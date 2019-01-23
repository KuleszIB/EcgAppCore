#include <iostream>
#include <fstream>
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <string>
#include <conio.h>

#include "sigpack.h"
#include "Dsp.h"
#include "SGSmooth.hpp"

#include "ecg_baseline_module.h"
#include "examination.h"

using namespace std;
using namespace sp;
using namespace Dsp;
using namespace arma;

//Jak filtrujesz czy coś, to wpisuj to do pól obiektu
void Filter_Params::set_filter_type(Filter_Type filter_type_set)
{
    filter_type = filter_type_set;
}

void Filter_Params::set_filter_params(double high=34, double low=2, unsigned int order=25, unsigned int length=97, double step=0.2)
{
    filter_values.high_cutoff_freq = high;
    filter_values.low_cutoff_freq = low;
    filter_values.filter_order = order;
    filter_values.filter_length = length;
    filter_values.step_size = step;
}

Filter_Type Filter_Params::get_filter_type()
{
    return filter_type;
}

Filter_Values Filter_Params::get_filter_values()
{
    return filter_values;
}

void Ecg_Baseline::calc_time_vec()
{
    time_vec = timevec(signal_raw.size(), sampling_frequency);
}

Ecg_Baseline::Ecg_Baseline()
{

}

Ecg_Baseline::Ecg_Baseline(arma::vec input, double fs)
{
    signal_raw = input;
    sampling_frequency = fs;
    calc_time_vec();
}



void Ecg_Baseline::filter_noise()
{
    double fc = 34 / (sampling_frequency/2);
    int M = 25;
    arma::vec coeffs = sp::fir1(M, fc);
    signal_filtered = conv(signal_raw, coeffs, "same");
}

void Ecg_Baseline::filter_bandpass()
{
    double fc1 = 34 / (sampling_frequency/2);
    double fc2 = 2 / (sampling_frequency/2);
    int M = 25;
    arma::vec coeffs = sp::fir1_bp(M, fc2, fc1);
    signal_filtered = conv(signal_raw, coeffs, "same");
}

void Ecg_Baseline::filter_moving_average(Filter_Values gui_parameters)
{
    filter_noise();
    Filter_Values filter_values = gui_parameters;

    double windowSize = filter_values.filter_length;
    arma::vec A(windowSize);
    A.ones();
    arma::vec b(windowSize);
    for (int i = 0; i<windowSize; i++)
    {
        b[i] = (1/windowSize) * A[i];
    }


    FIR_filt<double,double,double> coefficient;
    coefficient.set_coeffs(b);
    arma::vec signal_buff = coefficient.filter(signal_filtered);
    signal_filtered = signal_filtered-signal_buff;
}



std::vector<double> arma2std(arma::vec signal_vec)
{
    std::vector<double> signal_std;
    for (int i=0;i<signal_vec.size();i++)
    {
        signal_std.push_back(signal_vec[i]);
    }
    return signal_std;
}

double* vec2tab(arma::vec signal_vec)
{
    double *signal = new double[signal_vec.size()];
    for(int ii = 0; ii < signal_vec.size(); ii++)
        signal[ii] = signal_vec(ii);
    return signal;
}

arma::vec tab2vec(double *signal_vec)
{
    arma::vec signal(30000);
    double arraySize = signal.size();
    for(int ii = 0; ii < arraySize; ii++)
        {
        signal(ii) = signal_vec[ii];
        }
    return signal;
}

void Ecg_Baseline::filter_butterworth(Filter_Values gui_parameters)
{
    filter_noise();
    Filter_Values filter_values = gui_parameters;

    double w = filter_values.high_cutoff_freq;
    w = w/(sampling_frequency / 2);
    int numSamples = signal_filtered.size();
    Dsp::Filter* f = new Dsp::SmoothedFilterDesign
        <Dsp::Butterworth::Design::HighPass <1>, 1, Dsp::DirectFormII>(sampling_frequency);
    Dsp::Params params;
    params[0] = sampling_frequency; // sample rate
    params[1] = 1; // order
    params[2] = w; // center frequency
    f->setParams(params);
    double *signal_tab[1];
    signal_tab[0] = vec2tab(signal_filtered);
    f->process(numSamples, signal_tab);

    signal_filtered = -1*tab2vec(*signal_tab);
}

void Ecg_Baseline::filter_chebyshev(Filter_Values gui_parameters)
{

    filter_noise();
    Filter_Values filter_values = gui_parameters;
    int numSamples = signal_filtered.size();
    Dsp::Filter* f = new Dsp::FilterDesign
        <Dsp::ChebyshevII::Design::LowShelf <2>, 1>;
    Dsp::Params params;
    params[0] = sampling_frequency; // sample rate
    params[1] = 2; // order
    params[2] = filter_values.low_cutoff_freq/(sampling_frequency/2); // corner frequency
    params[3] = 6; // shelf gain
    params[4] = 10; // passband ripple
    f->setParams(params);
    double *signal_tab[1];
    signal_tab[0] = vec2tab(signal_filtered);
    f->process(numSamples, signal_tab);
    signal_filtered = tab2vec(*signal_tab);
}

void Ecg_Baseline::filter_savitzky_golay(Filter_Values gui_parameters)
{
    filter_noise();
    Filter_Values filter_values = gui_parameters;
    int w = filter_values.filter_length;
    int deg = filter_values.filter_order;
    int numSamples = signal_filtered.size();
    std::vector<double> sig_buff= arma2std(signal_filtered);
    signal_filtered = sg_smooth (sig_buff, w, deg);
    double fc = 5 / (sampling_frequency/2);
    int M = 24;
    arma::vec coeffs = sp::fir1_hp(M, fc);
    signal_filtered = conv(coeffs, signal_filtered);
}

void Ecg_Baseline::filter_lms(Filter_Values gui_parameters)
{
    arma::vec x = signal_raw;
    filter_bandpass();
    Filter_Values filter_values = gui_parameters;

    int N = x.size();
    int M = filter_values.filter_length;
    double mu = filter_values.step_size;
    sp::FIR_filt<double,double,double> G;
    sp::FIR_filt<double,double,double> Ghat;
    arma::vec y(N);  y.zeros();
    arma::vec e(N);  e.zeros();
    arma::mat Wlog(M,N);
    arma::vec w(M);  w.zeros();

    G.set_coeffs(w);
    Ghat.setup_lms(M, mu);
    arma::vec d= signal_filtered;
    for(int n=0;n<N;n++)
        {
            // Apply adaptiv filter
            y(n) = Ghat(x(n));

            // Calc error
            e(n) = d(n)-y(n);

            // Update filter
            Ghat.lms_adapt(e(n));

            // Save to log
            Wlog.col(n) = Ghat.get_coeffs();
        }

    signal_filtered = conv(Wlog.col(29999), signal_raw);
}




void Ecg_Baseline::filter_baseline(Filter_Params filter_params)
{
    switch(filter_params.get_filter_type())
        {
        case MOVING_AVERAGE:
            filter_moving_average(filter_params.get_filter_values());
            break;
        case BUTTERWORTH:
            filter_butterworth(filter_params.get_filter_values());
            break;
        case CHEBYSHEV:
            filter_chebyshev(filter_params.get_filter_values());
            break;
        case SAVITZKY_GOLAY:
            filter_savitzky_golay(filter_params.get_filter_values());
            break;
        case LMS:
            filter_lms(filter_params.get_filter_values());
            break;
        default:
            filter_moving_average(filter_params.get_filter_values());
            break;
        }
}

arma::vec Ecg_Baseline::get_time_vec(int it)
{
    arma::vec tmp(signal_raw.size());
    tmp.fill(signal_raw.size()*it/sampling_frequency);
    time_vec = time_vec + tmp;
    return time_vec;
}

arma::vec Ecg_Baseline::get_signal_raw()
{
    return signal_raw;
}

arma::vec Ecg_Baseline::get_signal_filtered()
{
    return signal_filtered;
}

arma::vec Ecg_Baseline::get_signal_baseline()
{
    return signal_baseline;
}

double Ecg_Baseline::get_sampling_freq()
{
    return sampling_frequency;
}


void Ecg_Baseline::write_to_file(int it)
{
    QString a = "../EcgApplicationCore/results/ecg_baseline/ecg_";
    a.append(QString::number(it));
    a.append(".txt");
    QFile file(a);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    for(int i = 0; i < signal_filtered.size(); i++)
        out << QString::number(signal_filtered[i]) << "\n";
}

void Ecg_Baseline::set_signal_filtered(arma::vec signal)
{
    signal_filtered = signal;
}

void Ecg_Baseline::set_signal_raw(arma::vec signal)
{
    signal_raw = signal;
}

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
//    time_vec = arma::linspace(0, signal_raw.size(), sampling_frequency);
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
    //filter_baseline (filter_type); gdzie to wywolujemy?
}



void Ecg_Baseline::filter_noise()
{
    double fc = 34 / (sampling_frequency/2);
    //int M = signal_raw.size();
    int M = 25;
    arma::vec coeffs = sp::fir1(M, fc);
    signal_filtered = conv(signal_raw, coeffs, "same");
//    qInfo() << "Filter noise signal_filtered.size()" << signal_filtered.size();
}

void Ecg_Baseline::filter_bandpass()
{
    qInfo() << "filter bandpass";
    double fc1 = 34 / (sampling_frequency/2);
    double fc2 = 2 / (sampling_frequency/2);
    int M = 25;
    arma::vec coeffs = sp::fir1_bp(M, fc2, fc1);
    signal_filtered = conv(signal_raw, coeffs, "same");
//    qInfo() << "Filter bandpass signal_filtered.size()" << signal_filtered.size();
}

void Ecg_Baseline::filter_moving_average(Filter_Values gui_parameters)
{
    filter_noise();
    Filter_Values filter_values = gui_parameters;
    //double windowSize = 97;
    qInfo()<<"to jest dlugosc filtra"<<filter_values.filter_length;
    arma::vec A(filter_values.filter_length);
    A.ones();
    arma::vec b(filter_values.filter_length);
    for (int i = 0; i<filter_values.filter_length; i++)
    {
        b[i] = (1/filter_values.filter_length) * A[i];
    }


    FIR_filt<double,double,double> coefficient;
    coefficient.set_coeffs(b);
    arma::vec signal_buff = coefficient.filter(signal_filtered);
    signal_filtered = signal_filtered-signal_buff;

    //za pomoca funkcji conv
    //arma::vec signal_buff= arma::conv(signal_filtered,b);
    //signal_filtered = signal_filtered(signal_buff.size())-signal_buff;
    //signal_filtered= arma::conv(signal_filtered,b);


//    qInfo() << "po filtracji moving average";
//    for (int i=1; i<signal_filtered.size(); i++)
//    {
//        qInfo() << signal_filtered[i];
//    }
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
    arma::vec signal(650000);
    //int arraySize = sizeof(signal_vec)/sizeof(double);
    //qInfo() << "arraySize";
    //qInfo() << arraySize;
    qInfo() << "signal size";
    qInfo() << signal.size();
    double arraySize = 650000;
    for(int ii = 0; ii < arraySize; ii++)
        {
        signal(ii) = signal_vec[ii];
        }
    qInfo() << "po petli ";
    return signal;
}

void Ecg_Baseline::filter_butterworth(Filter_Values gui_parameters)
{	
    filter_noise();
    Filter_Values filter_values = gui_parameters;

    double w = filter_values.high_cutoff_freq;
    w = w/(sampling_frequency/2);
    int numSamples = signal_filtered.size();
    Dsp::Filter* f = new Dsp::SmoothedFilterDesign
        <Dsp::Butterworth::Design::HighPass <1>, 1, Dsp::DirectFormII>(sampling_frequency);
    Dsp::Params params;
    params[0] = sampling_frequency; // sample rate
    params[1] = filter_values.filter_order; // order
    params[2] = w; // center frequency
    qInfo()<<"to jest cut off"<<filter_values.high_cutoff_freq;
    qInfo()<<"to jest filter order"<<filter_values.filter_order;
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
  /*
    // Create a Chebyshev type I Band Stop filter of order 3
    // with state for processing 2 channels of audio.
    Dsp::SimpleFilter <Dsp::ChebyshevII::BandStop <3>, 1> f;
    f.setup(2,    // order
        44100,// sample rate
        4000, // center frequency
        880,  // band width
        1);   // ripple dB
    f.process(numSamples, signal_buff);
  */
    Dsp::Filter* f = new Dsp::FilterDesign
        <Dsp::ChebyshevII::Design::LowShelf <2>, 1>;
    Dsp::Params params;
    params[0] = sampling_frequency; // sample rate
    params[1] = filter_values.filter_order; // order
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

    qInfo() << "LMS";
    int N = x.size();
    qInfo() << "dlugosc x: ";
    qInfo() << N;
    qInfo() << "dlugosc filtrowanego: ";
    qInfo() << signal_filtered.size();
    //int M = 15;
    int M = filter_values.filter_length;
    //double mu = 0.2;
    double mu = filter_values.step_size;
    sp::FIR_filt<double,double,double> G;
    sp::FIR_filt<double,double,double> Ghat;
    arma::vec y(N);  y.zeros();
    arma::vec e(N);  e.zeros();
    arma::mat Wlog(M,N);
    arma::vec w(M);  w.zeros();
    //arma::vec W(M, N);  W.zeros();

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
    qInfo() << "rozmiar Wlog";
    qInfo() << Wlog.size();
        signal_filtered = conv(Wlog.col(649999), signal_raw);

            for (int i=1; i<signal_filtered.size(); i++)
            {
                qInfo() << signal_filtered[i];
            }




    /*std::cout << "Estimated coeffs: " << Ghat.get_coeffs().t() << std::endl;
    gplot gp0;
    gp0.window("Plot", 10, 10, 500, 500);
        gp0.plot_add_mat(Wlog,"b");
        gp0.plot_show();*/

    /*for (int i = 1; i <= N; i++) {
        if (i <= M) {
            arma::vec k = arma::linspace(i, -1, 1);
            arma::vec A(M-k.size()); A.zeros();
            int x;
            arma::vec x1 = join_rows(signal_filtered,A);
        }
        else
    }*/

    /*long T, n = 0;
    double D, Y, E;
    double * W = new double[M];
    double * X = new double[M];

    for (T = 0; T < N; T++)
    {
        for (int m = T; m > T - M; m--) {
            if (m >= 0)
            {X[M + (m - T) - 1] = signal_filtered[m];	//X new input sample for LMS filter
                qInfo() << X[m];}
            else break;
        }
        D = signal_filtered[T];					//desired signal
        Y = 0;						//filter’output set to zero

        for (int i = 0; i < M; i++)
            Y = Y+(W[i]*X[i]);			//calculate filter output


        E = D - Y;					//calculate error signal

        for (int i = 0; i < M; i++)
            W[i] = W[i] + (mu * E * X[i]);		//update filter coefficients
        signal_filtered[T] = Y; //signal_filtered = Y[T]

    }*/

    /*qInfo() << "po filtracji LMS";
    for (int i=1; i<signal_filtered.size(); i++)
    {
        qInfo() << signal_filtered[i];
    }*/

}




void Ecg_Baseline::filter_baseline(Filter_Params filter_params)
{
 //ustalamy ktora funkcje filtracji odpalic  i z jakimi parametrami o ile sa
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

arma::vec Ecg_Baseline::get_time_vec(int it) //Nie wiem czy to nie musi być przed konstruktorem jeszcze
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

arma::vec read_from_file()
{
    string N;
    arma::vec data;
    ifstream plik;
    plik.open("C:/Users/Laura/Desktop/Laura/semestr 9/MOJE/DADM/projekt/Prototyp Matlab/100_V5.dat");
    if (!plik.good() == true){
        while (!plik.eof())
        {
            getline(plik, N);
            int i = 1;
            data[i] = atoi(N.c_str());
        }
        plik.close();
    }
    return data;
}

void Ecg_Baseline::write_to_file(int it)
{
//    ofstream plik;
//    int i = 0;
//    plik.open("C:/Users/Laura/Desktop/Laura/semestr 9/MOJE/DADM/projekt/Prototyp Matlab/100_V5_pozapisaniu.txt");
//    if (!plik.good() == true){
//        cin >> data[i++];
//    }
//    plik.close();
    QString a = "../EcgApplicationCore/results/ecg_baseline/ecg_";
    a.append(QString::number(it));
    a.append(".txt");
    QFile file(a);
//    qInfo() << a;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
//    qInfo() << "Przeszło";
    QTextStream out(&file);
    for(int i = 0; i < signal_filtered.size(); i++)
        out << QString::number(signal_filtered[i]) << "\n";
//    for(int i = 0; i < signal_raw.size(); i++)
//        out << QString::number(signal_raw[i]) << "\n";
}

void Ecg_Baseline::set_signal_filtered(arma::vec signal)
{
    signal_filtered = signal;
}

void Ecg_Baseline::set_signal_raw(arma::vec signal)
{
    signal_raw = signal;
}

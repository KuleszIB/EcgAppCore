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

using namespace std;
using namespace sp;
using namespace Dsp;
using namespace arma;

//Jak filtrujesz czy coś, to wpisuj to do pól obiektu

Filter_Type Filter_Params::get_filter_type()
{
    return filter_type;
}

void Ecg_Baseline::calc_time_vec()
{
    time_vec = arma::linspace(0, signal_raw.size(), sampling_frequency);
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
    double fc = 34 / (sampling_frequency / 2);
    int M = 25;
    arma::vec coeffs = sp::fir1(M, fc);
    signal_filtered = conv(coeffs, signal_raw, "same");
}

void Ecg_Baseline::filter_bandpass()
{
    double fc1 = 34 / (sampling_frequency / 2);
    double fc2 = 2 / (sampling_frequency / 2);
    int M = 25;
    arma::vec coeffs = fir1_bp(M, fc1, fc2);
    signal_filtered = conv(coeffs, signal_raw, "same");
}

void Ecg_Baseline::filter_moving_average()
{
    filter_noise();
    int windowSize = 97;
    arma::Col<double> A =  arma::ones(1, windowSize);
    arma::vec b(windowSize);
    for (int i = 0; i<windowSize; i++)
    {
        b[i] = 1/windowSize * A[i];
    }
    //int a = 1;
    FIR_filt<double,double,double> coefficient;
    coefficient.set_coeffs(b);
    signal_filtered = coefficient.filter(signal_filtered); //albo mat, i jak to zrobic zeby nie nadpisywac sygnalu? czy mam utworzyc nowa zmienna w header?
}

double **vec2tab(arma::vec signal_vec)
{
    double **signal_tab = new double*[signal_vec.size()];
    for(int ii = 0; ii < signal_vec.size(); ii++)
        **(signal_tab + ii) = signal_vec(ii);
    return signal_tab;
}

void Ecg_Baseline::filter_butterworth()
{	
    filter_noise();
    double w = 1.8;
    w = w / (sampling_frequency / 2);
    int numSamples = signal_filtered.size();
    Dsp::Filter* f = new Dsp::SmoothedFilterDesign
        <Dsp::Butterworth::Design::HighPass <1>, 1, Dsp::DirectFormII>(sampling_frequency);
    Dsp::Params params;
    params[0] = sampling_frequency; // sample rate
    params[1] = 1; // order
    params[2] = w; // center frequency
    f->setParams(params);
    double **signal_tab = vec2tab(signal_filtered);
    f->process(numSamples, signal_tab);

    /*Dsp::ButterHighPass<6, 2> butter;
    butter.Setup(w);
    butter.Process<0>(count, stereoBuffer);*/
}

void Ecg_Baseline::filter_chebyshev()
{

    filter_noise();
    int numSamples = signal_filtered.n_rows;

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
        <Dsp::ChebyshevII::Design::LowShelf <1>, 1>;
    Dsp::Params params;
    params[0] = sampling_frequency; // sample rate
    params[1] = 2; // order
    params[2] = 1/(sampling_frequency/2); // corner frequency
    params[3] = 6; // shelf gain
    params[4] = 10; // passband ripple
    f->setParams(params);
    double **signal_tab = vec2tab(signal_filtered);
    f->process(numSamples, signal_tab);

}

void Ecg_Baseline::filter_savitzky_golay()
{
    filter_noise();
    int w = 17;
    int deg = 3;
    int numSamples = signal_filtered.n_rows;
    vector<double> sig_buff ;
    for (int i=0;i<numSamples;i++)
    {
        sig_buff[i] = signal_filtered[i];
    }
    signal_filtered = sg_smooth (sig_buff, w, deg);
    /*
        double result;
        result = (1.0 / 5175.0) * (-253.0*syg_dolno[i - 12]
        - 138.0*syg_dolno[i - 11]
        - 33.0*syg_dolno[i - 10]
        + 62.0*syg_dolno[i - 9]
        + 147.0*syg_dolno[i - 8]
        + 222.0*syg_dolno[i - 7]
        + 287.0*syg_dolno[i - 6]
        + 343.0*syg_dolno[i - 5]
        + 387.0*syg_dolno[i - 4]
        + 422.0*syg_dolno[i - 3]
        + 447.0*syg_dolno[i - 2]
        + 462.0*syg_dolno[i - 1]

        + 467.0*syg_dolno[i]

        + 462.0*syg_dolno[i + 1]
        + 447.0*syg_dolno[i + 2]
        + 422.0*syg_dolno[i + 3]
        + 387.0*syg_dolno[i + 4]
        + 343.0*syg_dolno[i + 5]
        + 287.0*syg_dolno[i + 6]
        + 222.0*syg_dolno[i + 7]
        + 147.0*syg_dolno[i + 8]
        + 62.0*syg_dolno[i + 9]
        - 33.0*syg_dolno[i + 10]
        - 138.0*syg_dolno[i + 11]
        - 253.0*syg_dolno[i + 12]);

    return result;*/
}

void Ecg_Baseline::filter_lms()
{
    filter_bandpass();
    int N = signal_filtered.n_rows;
    int M = 15;
    double mu = 0.2;
    //mat y(N, 1);  y.zeros<mat>();
    //mat w(M, 1);  w.zeros<mat>();
    //mat e(N, 1);  e.zeros<mat>();
    //mat W(M, N);  W.zeros<mat>();

    //FIR_filt lms;
    //void lms.setup_lms(N, mu, M);

    /*for (int i = 1; i <= N; i++) {
        if (i <= M) {
            arma::vec k = linspace<arma::vec>(i, -1, 1);
            mat A(M-k.n_rows, 1); A.zeros<mat>();
            int x;
            mat x1 = join_rows(A);
            mat x1 = [x(k)];
        }
    }*/

    long T, n = 0;
    double D, Y, E;
    double * W = new double[M];
    double * X = new double[M];


    for (T = 0; T < N; T++)
    {
        for (int m = T; m > T - M; m--) {
            if (m >= 0)
                X[M + (m - T) - 1] = signal_filtered[m];	//X new input sample for
                                //LMS filter
            else break;
        }

        D = signal_filtered[T];					//desired signal
        Y = 0;						//filter’output set to zero

        for (int i = 0; i < M; i++)
            Y += (W[i] * X[i]);			//calculate filter output

        E = D - Y;					//calculate error signal

        for (int i = 0; i < M; i++)
            W[i] = W[i] + (mu * E * X[i]);		//update filter coefficients

        signal_filtered[T] = Y; //signal_filtered = Y[T]

    }

}




void Ecg_Baseline::filter_baseline(Filter_Params filter_params)
{
 //ustalamy ktora funkcje filtracji odpalic  i z jakimi parametrami o ile sa
    switch(filter_params.get_filter_type())
        {
        case MOVING_AVERAGE:
            filter_moving_average();
            break;
        case BUTTERWORTH:
            filter_butterworth();
            break;
        case CHEBYSHEV:
            filter_chebyshev();
            break;
        case SAVITZKY_GOLAY:
            filter_savitzky_golay();
            break;
        case LMS:
            filter_lms();
            break;
        default:
            filter_moving_average();
            break;
        }
}

arma::vec Ecg_Baseline::get_time_vec() //Nie wiem czy to nie musi być przed konstruktorem jeszcze
{
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

arma::vec readtxt()
{
    //bool s = true;
    //string N;
    arma::vec data;
//    ifstream plik;
//    plik.open("C:/Users/Laura/Desktop/Laura/semestr 9/MOJE/DADM/projekt/Prototyp Matlab/100_V5.dat");
//    if (!plik.good() == true){
//        while (!plik.eof())
//        {
//            //getline(plik, N);
//            //tu coś trzeba jeszcze
//        }
//        plik.close();
//    }
    return data;
}
/*
int main() {

    Filter_Type filter_type;
    string filter;
    cin >> filter;

    Filter_Params filter_params;

    int fs = 360;
    arma::vec input;
    input = readtxt();
    Ecg_Baseline test(input, fs);
    test.filter_baseline(filter_params);
    cout << "dziala" << endl;

}
*/

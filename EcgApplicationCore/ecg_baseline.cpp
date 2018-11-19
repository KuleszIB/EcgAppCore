#include "ecg_baseline.h"
#include "vector"
#include "liquid/liquid.h"
#include <armadillo>
#include "sigpack.h"
#include "Dsp.h"
#include "SGSmooth.hpp"
#include <iostream>
#include <fstream>
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <string>
#include <conio.h>



using namespace std;
using namespace arma;
using namespace sp;
using namespace Dsp;
//Jak filtrujesz czy coś, to wpisuj to do pól obiektu

Ecg_Baseline::Ecg_Baseline()
{

}

Ecg_Baseline::Ecg_Baseline(vector<double> input, double fs)
{
    signal_raw = input;
    sampling_frequency = fs;
    time_vec = calc_time_vec(input, fs);
}



vector<double> Ecg_Baseline::filter_noise(vector<double> syg_wejsciowy, double fs)
{
    double fc = 34 / (fs / 2);
	int M = 25;
    vector<double> coeffs = fir1(M, fc);
    vector<double> syg_dolno = conv(coeffs, syg_wejsciowy, "same");
	return syg_dolno;
}

vector<double> Ecg_Baseline::filter_noise_bp(vector<double> syg_wejsciowy, double fs)
{
    double fc1 = 34 / (fs / 2);
    double fc2 = 2 / (fs / 2);
	int M = 25;	
	vector<double> coefficient = fir1_bp(M, fc1, fc2);
	vector<double> syg_pasmo = conv(coefficient, syg_wejsciowy, "same");
	return syg_pasmo;
}

void Ecg_Baseline::filter_moving_average(vector<double> syg_wejsciowy, double fs)
{
	vector<double> syg_dolno = filter_noise(syg_wejsciowy, fs);
	int windowSize = 97;
    Col<double> A =  ones<Col<double>>(1, windowSize);
    vector<double> b(windowSize);
    for (int i = 0; i<windowSize; i++)
    {
        b[i] = 1/windowSize * A[i];
    }
	//int a = 1;
    FIR_filt coefficient;
	coefficient.set_coeffs(b);
	vector<double>syg_moving_average = coefficient.filter(syg_dolno); //albo mat
}

void Ecg_Baseline::filter_butterworth(vector<double> syg_wejsciowy, double fs)
{	
	vector<double> syg_dolno = filter_noise(syg_wejsciowy, fs);
	double w = 1,8;
	w = w / (fs / 2);
	int numSamples = syg_dolno.n_rows;
	Dsp::Filter* f = new Dsp::SmoothedFilterDesign
		<Dsp::Butterworth::Design::HighPass <1>, 2, Dsp::DirectFormII>(fs);
	Dsp::Params params;
	params[0] = fs; // sample rate
	params[1] = 1; // order
	params[2] = w; // center frequency
	f->setParams(params);
	f->process(numSamples, syg_dolno);

	/*Dsp::ButterHighPass<6, 2> butter;
	butter.Setup(w);
	butter.Process<0>(count, stereoBuffer);*/
}

void Ecg_Baseline::filter_chebyshev(vector<double> syg_wejsciowy, double fs)
{
	// Create a Chebyshev type I Band Stop filter of order 3
// with state for processing 2 channels of audio.
	/*Dsp::SimpleFilter <Dsp::ChebyshevII::BandStop <3>, 2> f;
	f.setup(2,    // order
		44100,// sample rate
		4000, // center frequency
		880,  // band width
		1);   // ripple dB
	f.process(numSamples, arrayOfChannels);*/
	vector<double> syg_dolno = filter_noise(syg_wejsciowy, fs);
	int numSamples = syg_dolno.n_rows;
	//vector<double> audioData = syg_dolno;
	Dsp::Filter* f = new Dsp::FilterDesign;
		<Dsp::ChebyshevII::Design::LowShelf <2>, 2>;
	Dsp::Params params;
	params[0] = fs; // sample rate
	params[1] = 2; // order
	params[2] = 1/(fs/2); // corner frequency
	params[3] = 6; // shelf gain
	params[4] = 10; // passband ripple
	f->setParams(params);
	f->process(numSamples, syg_dolno);
}

void Ecg_Baseline::filter_savitzky_golay(vector<double> syg_wejsciowy, double fs)
{
	vector<double> syg_dolno = filter_noise(syg_wejsciowy, fs);
	int w = 17;
	int deg = 3;
	
	vector<double> syg_sg = sg_smooth(syg_dolno, w, deg);
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

void Ecg_Baseline::filter_lms(vector<double> syg_wejsciowy, double fs)
{
	vector<double> syg_dolno = filter_noise(syg_wejsciowy, fs);
	vector<double> syg_desired = Ecg_Baseline::filter_noise_bp(syg_wejsciowy, fs);
	int N = syg_dolno.n_rows;
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
			vector<double> k = linspace<vector<double>>(i, -1, 1);
			mat A(M-k.n_rows, 1); A.zeros<mat>();
			int x;
			mat x1 = join_rows(A);
			mat x1 = [x(k)];
		}
	}*/

	long T, n = 0;
	double D, Y, E;
    double W[M];
    double X[M];


	for (T = 0; T < N; T++)
	{
		for (int m = T; m > T - M; m--) {
			if (m >= 0)
				X[M + (m - T) - 1] = syg_dolno[m];	//X new input sample for 
								//LMS filter
			else break;
		}

		D = syg_desired[T];					//desired signal
		Y = 0;						//filter’output set to zero

		for (int i = 0; i < M; i++)
			Y += (W[i] * X[i]);			//calculate filter output

		E = D - Y;					//calculate error signal

		for (int i = 0; i < M; i++)
			W[i] = W[i] + (mu * E * X[i]);		//update filter coefficients

		vector<double> syg_lms = Y[T];

	}


}




void Ecg_Baseline::filter_baseline(Filter_Params filter_params)
{

}

vector<double> Ecg_Baseline::get_time_vec() //Nie wiem czy to nie musi być przed konstruktorem jeszcze
{
    vector<double> time_vec;

    return time_vec;
}

vector<double> Ecg_Baseline::get_signal_raw()
{
    vector<double> signal_raw;

    return signal_raw;
}

vector<double> Ecg_Baseline::get_signal_filtered()
{
    vector<double> signal_filtered;

    return signal_filtered;
}

vector<double> Ecg_Baseline::get_signal_baseline()
{
    vector<double> baseline;

    return baseline;
}


double* open()
{
    //bool s = true;
    int N;
    ifstream plik;
    plik.open("C:/Users/Laura/Desktop/Laura/semestr 9/MOJE/DADM/projekt/Prototyp Matlab/100_V5.dat");
    if (!plik.good() == true){
        while (!plik.eof())
        {
            cin.get(plik, N);
            cout << N << endl;
        }
        plik.close();
    }
}

int main() {


    int fs = 360;
    vector<double> syg_dolno, syg_wejsciowy;
    syg_wejsciowy = open();
 	Ecg_Baseline test(syg_wejsciowy, fs);
	syg_dolno = test.filter_noise(syg_wejsciowy, fs);
	cout << "jestem" << endl;

}

#include "waves_module.h"
#include <iostream>
#include <math.h>
#include <cmath>
#define pi 3.14159265358979323846

using namespace std;

Waves::Waves()
{
    r_peaks_vec = R_Peaks::get_r_peaks();
    signal_filtered = R_Peaks::signal_raw;
    signal_raw = R_Peaks::signal_raw;
    sampling_frequency = R_Peaks::sampling_frequency;
}

Waves::Waves(arma::vec signal, arma::uvec r_peaks, double fs)
{
    signal_filtered = signal;
    r_peaks_vec = r_peaks;
    sampling_frequency = fs;
}

void Waves::find_qrs_onset_end()
{
    // sprawdzenie czy sygnal jest "odwrocony"
    bool odwrocony = false;
    if (signal_raw[int(r_peaks_vec[0])] < 0)
    {
        signal_filtered = -signal_filtered;
        odwrocony = true;
    }

    bool goLeft, decreasingL, firstMinReached;
    bool goRight, decreasingR;
    arma::uvec qrsOnset(r_peaks_vec.size()), qrsEnd(r_peaks_vec.size());

    for(int i=0; i<r_peaks_vec.size(); i++)
    {
        // Poszukiwanie QRS-onset
        // Idac w lewo, poszukiwane sa nastepujace po sobie minimum oraz maksimum
        goLeft = true;
        decreasingL = false;
        firstMinReached = false;
        int j = int(r_peaks_vec[i]);
        while (goLeft)
        {
            if (signal_filtered[j] > signal_filtered[j-1])
                decreasingL = true;
            if ((signal_filtered[j] < signal_filtered[j-1]) && decreasingL == true)
                firstMinReached = true;
            if ((firstMinReached == true) && (decreasingL == true) && (signal_filtered[j] > signal_filtered[j-1]))
            {
                qrsOnset[i] = j;
                goLeft = false;
            }
            j--;
        }

        // Poszukiwanie QRS-end
        // Idac w prawo, poszukiwane sa nastepujace po sobie minimum oraz maksimum
        goRight = true;
        decreasingR = false;
        firstMinReached = false;
        j = int(r_peaks_vec[i]);
        while (goRight)
        {
            if (signal_filtered[j] > signal_filtered[j+1])
                decreasingR = true;
            if ((signal_filtered[j] < signal_filtered[j+1]) && decreasingR == true)
                firstMinReached = true;
            if (firstMinReached == true && decreasingR == true && signal_filtered[j] > signal_filtered[j+1])
            {
                qrsEnd[i] = j;
                goRight = false;
            }
            j++;
        }
    }

    if (odwrocony)
        signal_filtered = -signal_filtered;

    waves_points.qrs_onset = qrsOnset;
    waves_points.qrs_end = qrsEnd;
}

void Waves::find_p_onset_end()
{
    // sprawdzenie czy sygnal jest "odwrocony"
    bool odwrocony = false;
    if (signal_raw[int(r_peaks_vec[0])] < 0)
    {
        signal_filtered = -signal_filtered;
        odwrocony = true;
    }

    // WSTEPNE PRZETWARZANIE
    // usuniecie zespolow QRS
    for (int i=0; i<waves_points.qrs_onset.size(); i++)
    {
        double meanValue = (signal_filtered[int(waves_points.qrs_onset[i])] + signal_filtered[int(waves_points.qrs_end[i])]) / 2;
        for (int j=int(waves_points.qrs_onset[i]); j<=waves_points.qrs_end[i]; j++)
            signal_filtered[j] = meanValue;
    }
    filter_lowpass(5,20);   // wygladzenie sygnalu
    differentiate();        // rozniczkowanie
    filter_lowpass(15,20);  // ponowna filtracja

    // WYSZUKIWANIE PONSETS I PENDS
    arma::uvec Ponset(r_peaks_vec.size()), Pend(r_peaks_vec.size());
    int noOfSamples = int(floor(0.25/(1/sampling_frequency)));

    for (int i=0; i<r_peaks_vec.size(); i++)
    {
        // SZUKANIE P END
        // Szukane jest minimum pochodnej, znajdujace sie na lewo od punktu QRS-onset
        int startPoint = int(waves_points.qrs_onset[i]) - noOfSamples;   // Punkt startowy
        if (startPoint < 0)
            startPoint = 0;
        int endPoint = int(waves_points.qrs_onset[i]);                   // Punkt koncowy
        int minPos = int(arma::index_min(signal_filtered.subvec(startPoint,endPoint)));
        minPos += startPoint;

        // Szukany jest punkt za znalezionym minimum, w ktorym wartosc
        // pochodnej jest wieksza od zadanej wartosci. Jest to p. P-end
        bool lookingForZero = true;
        int j = minPos;
        while (lookingForZero)
        {
            if (signal_filtered[j] >= -0.0003)
            {
                lookingForZero = false;
                // Sprawdzenie, czy p. P-end znajduje sie przez QRS-onset
                if (j >= waves_points.qrs_onset[i] || abs(int(waves_points.qrs_onset[i])-j)<10)
                    Pend[i] = waves_points.qrs_onset[i] - 10;
                else
                    Pend[i] = j;
            }
            j++;
        }

        // SZUKANIE P ONSET
        // Szukane jest maksimum pochodnej, znajdujace sie przed wczesniej znalezionym minimum
        endPoint = minPos;
        int maxPos = int(arma::index_max(signal_filtered.subvec(startPoint,endPoint)));
        maxPos += startPoint;
        // Szukany jest punkt przed znalezionym maksimum, w ktorym wartosc
        // pochodnej jest mniejsza od zadanej wartosci. Jest to p. P-onset
        lookingForZero = true;
        j = maxPos;
        while (lookingForZero)
        {
            if (signal_filtered[j] <= 0.0003)
            {
                lookingForZero = false;
                Ponset[i] = j;
            }
            j--;
        }
    }

    signal_filtered = signal_raw;

    waves_points.p_end = Pend;
    waves_points.p_onset = Ponset;
}

void Waves::find_t_end()
{
    // sprawdzenie czy sygnal jest "odwrocony"
    bool odwrocony = false;
    if (signal_raw[int(r_peaks_vec[0])] < 0)
    {
        signal_filtered = -signal_filtered;
        odwrocony = true;
    }

    // WSTEPNE PRZETWARZANIE
    // usuniecie zespolow QRS
    for (int i=0; i<waves_points.qrs_onset.size(); i++)
    {
        double meanValue = (signal_filtered[int(waves_points.qrs_onset[i])] + signal_filtered[int(waves_points.qrs_end[i])]) / 2;
        for (int j=int(waves_points.qrs_onset[i]); j<=waves_points.qrs_end[i]; j++)
            signal_filtered[j] = meanValue;
    }
    filter_lowpass(5,20);   // wygladzenie sygnalu
    differentiate();        // rozniczkowanie
    filter_lowpass(15,20);  // ponowna filtracja

    arma::uvec Tend(r_peaks_vec.size());
    for (int i=0; i<r_peaks_vec.size(); i++)
    {
        // Poszukiwanie maksimum pochodnej wystepujacego miedzy punktem
        // ORS-end a P-onset z nastepnego uderzenia
        int startPoint = int(waves_points.qrs_end[i]);
        int endPoint;
        if (i == waves_points.qrs_end.size()-1)
            endPoint = int(signal_filtered.size())-1;
        else
            endPoint = int(waves_points.p_onset[i+1]);
        int maxPos = int(arma::index_max(signal_filtered.subvec(startPoint,endPoint)));
        maxPos += startPoint;

        // Poszukiwanie minimum lokalnego wystepujacego bezposrednio po
        // wczesniej wyszukanym maksimum
        arma::uvec b = find_peaks(-signal_filtered.subvec(maxPos,endPoint));
        int minPos;
        if (b.size() != 0)
            minPos = int(b[0]) + maxPos;
        else
            continue;

        // Szukany jest punkt za znalezionym minimum, w ktorym wartosc
        // pochodnej jest wieksza od zadanej wartosci. Jest to p. T-end
        bool lookingForZero = true;
        int j = minPos;
        while (lookingForZero)
        {
            if (signal_filtered[j] >= -0.0005)
            {
                lookingForZero = false;
                if (i!= waves_points.qrs_end.size()-1)
                {
                    if (j >= waves_points.p_onset[i+1])
                        Tend[i] = waves_points.p_onset[i+1] - 10;
                    else
                        Tend[i] = j;
                }
                else
                    Tend[i] = j;
            }
            if (j<signal_filtered.size()-1)
                j++;
            else
            {
                Tend[i] = j;
                break;
            }
        }
    }

    signal_filtered = signal_raw;

    waves_points.t_end = Tend;
}

void Waves::filter_lowpass(double fc, int M)
{
    fc = fc / sampling_frequency / 2;
    int N = 2 * M + 1;

    // zdefiniowanie wspolczynnikow filtra h
    arma::vec h(N);
    for (int i=-M; i<0; i++)
        h[i+M] = 2*fc*pi*arma::sinc(i*2*fc*pi);

    h[M] = 2*fc;
    for (int i=1; i<=M; i++)
        h[i+M] = 2*fc*pi*arma::sinc(i*2*fc*pi);

    // zdefiniowanie okna
    arma::vec okno(N);
    for (int i=0; i<N; i++)
        okno[i] = 1-(2*(abs(double(i)-(double(N)-1)/2))/(double(N)-1));

    // przemnozenie wspolczynnikow filtra przez okno
    arma::vec hw(N);
    hw = h % okno;

    signal_filtered = arma::conv(signal_filtered,hw,"same");
}

void Waves::find_waves()
{
    find_qrs_onset_end();
    find_p_onset_end();
    find_t_end();
}

Waves_Points Waves::get_waves()
{
    find_waves();
    return waves_points;
}

#include "waves_module.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <QDebug>
#define pi 3.14159265358979323846

using namespace std;

Waves::Waves()
{
    r_peaks_vec = R_Peaks::get_r_peaks();
    signal_filtered = R_Peaks::signal_raw;
    signal_raw = R_Peaks::signal_raw;
    sampling_frequency = R_Peaks::sampling_frequency;
}

Waves::Waves(arma::vec signal, arma::vec r_peaks, double fs)
{
    signal_filtered = signal;
    signal_raw = signal;
    r_peaks_vec = r_peaks;
    sampling_frequency = fs;
}

void Waves::find_qrs_onset_end()
{
    // sprawdzenie czy sygnal jest "odwrocony"
    bool inverted = false;
    if ((signal_raw[int(r_peaks_vec[0])] + signal_raw[int(r_peaks_vec[1])]) / 2 < 0)
    {
        signal_filtered = -signal_filtered;
        inverted = true;
    }

    bool goLeft, decreasingL, firstMinReached;
    bool goRight, decreasingR;
    arma::vec qrsOnset(r_peaks_vec.size()), qrsEnd(r_peaks_vec.size());

    for(int i=0; i<r_peaks_vec.size(); i++)
    {
        // Poszukiwanie QRS-onset
        // Idac w lewo, poszukiwane sa nastepujace po sobie minimum oraz maksimum
        goLeft = true;
        decreasingL = false;
        firstMinReached = false;
        int j = int(r_peaks_vec[i]);
        while (goLeft && j>0)
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
            if ((decreasingL == true) && (j == 1))
                qrsOnset[i] = 0;
            j--;
        }

        // Poszukiwanie QRS-end
        // Idac w prawo, poszukiwane sa nastepujace po sobie minimum oraz maksimum
        goRight = true;
        decreasingR = false;
        firstMinReached = false;
        j = int(r_peaks_vec[i]);
        while (goRight && j<signal_filtered.size()-1)
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
            if (decreasingR == true && j == signal_filtered.size()-2)
                qrsEnd[i] = j+1;
            j++;
        }
    }

    if (inverted)
        signal_filtered = -signal_filtered;

    waves_points.qrs_onset = qrsOnset;
    waves_points.qrs_end = qrsEnd;
}

void Waves::find_p_onset_end()
{
    // sprawdzenie czy sygnal jest "odwrocony"
    if ((signal_raw[int(r_peaks_vec[0])] + signal_raw[int(r_peaks_vec[1])]) / 2 < 0)
        signal_filtered = -signal_filtered;

    // WSTEPNE PRZETWARZANIE
    // usuniecie zespolow QRS
    int min_len = std::min(waves_points.qrs_onset.size(),waves_points.qrs_end.size());
    for (int i=0; i<min_len; i++)
    {
//        if(i==118)
//            qInfo() << "int(waves_points.qrs_onset[i])" << int(waves_points.qrs_onset[i])
//                    << "int(waves_points.qrs_end[i])"   << int(waves_points.qrs_end[i]);
        double meanValue = (signal_filtered[int(waves_points.qrs_onset[i])] + signal_filtered[int(waves_points.qrs_end[i])]) / 2;
        for (int j=int(waves_points.qrs_onset[i]); j<=waves_points.qrs_end[i]; j++)
            signal_filtered[j] = meanValue;
    }
    filter_lowpass(5,20);   // wygladzenie sygnalu
    differentiate();        // rozniczkowanie
    filter_lowpass(15,20);  // ponowna filtracja

    // WYSZUKIWANIE PONSETS I PENDS
    arma::vec Ponset(r_peaks_vec.size()), Pend(r_peaks_vec.size());
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
                {
                    if (j>9 && waves_points.qrs_onset[i]>9)
                        Pend[i] = waves_points.qrs_onset[i] - 10;
                    else
                        Pend[i] = waves_points.qrs_onset[i];
                }
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
        while (lookingForZero && j>=0)
        {
            if (signal_filtered[j] <= 0.0003)
            {
                lookingForZero = false;
                if (j > Pend[i])
                    Ponset[i] = Pend[i];
                else
                    Ponset[i] = j;
            }
            if (j == 0)
            {
                Ponset[i] = j;
                lookingForZero = false;
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
    if ((signal_raw[int(r_peaks_vec[0])] + signal_raw[int(r_peaks_vec[1])]) / 2 < 0)
        signal_filtered = -signal_filtered;

    // WSTEPNE PRZETWARZANIE
    // usuniecie zespolow QRS
    int min_len = std::min(waves_points.qrs_onset.size(),waves_points.qrs_end.size());
    for (int i=0; i<min_len; i++)
    {
        double meanValue = (signal_filtered[int(waves_points.qrs_onset[i])] + signal_filtered[int(waves_points.qrs_end[i])]) / 2;
        for (int j=int(waves_points.qrs_onset[i]); j<=waves_points.qrs_end[i]; j++)
            signal_filtered[j] = meanValue;
    }
    filter_lowpass(5,20);   // wygladzenie sygnalu
    differentiate();        // rozniczkowanie
    filter_lowpass(15,20);  // ponowna filtracja

    arma::vec Tend(r_peaks_vec.size());
    int counter = 0;
    for (int i=0; i<r_peaks_vec.size(); i++)
    {
        // Poszukiwanie maksimum pochodnej wystepujacego miedzy punktem
        // ORS-end a P-onset z nastepnego uderzenia
        int startPoint;
        if (waves_points.qrs_end[i] == signal_filtered.size())
            startPoint = int(waves_points.qrs_end[i]);
        else
            startPoint = int(waves_points.qrs_end[i]) + 1;

        int endPoint;
        if (i == waves_points.qrs_end.size()-1)
            endPoint = int(signal_filtered.size()) - 1;
        else
            endPoint = int(waves_points.p_onset[i+1])-1;

        int maxPos;
        if (startPoint < endPoint)
        {
            maxPos = int(arma::index_max(signal_filtered.subvec(startPoint,endPoint)));
            maxPos += startPoint;
        }
        else
            continue;

        // Poszukiwanie minimum lokalnego wystepujacego bezposrednio po
        // wczesniej wyszukanym maksimum
        int minPos;
        if ((endPoint - maxPos) < 2)
            continue;
        else
        {
            arma::vec b = find_peaks(-signal_filtered.subvec(maxPos,endPoint));
            if (b.size() != 0)
                minPos = int(b[0]) + maxPos - 1;
            else
            {
                Tend[counter++] = endPoint;
                continue;
            }
        }

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
                        Tend[counter++] = waves_points.p_onset[i+1] - 10;
                    else
                        Tend[counter++] = j;
                }
                else
                    Tend[counter++] = j;
            }
            if (j<signal_filtered.size()-1)
                j++;
            else
            {
                Tend[counter++] = j;
                break;
            }
        }
    }

    signal_filtered = signal_raw;

    waves_points.t_end = Tend.subvec(0,counter-1);
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
    signal_filtered = signal_raw;
    find_qrs_onset_end();
    find_p_onset_end();
    find_t_end();
}

Waves_Points Waves::get_waves()
{
    return waves_points;
}

void Waves::remove_head(int which)
{
    switch(which)
    {
    case 0:
        waves_points.p_onset.shed_row(0);
        break;
    case 1:
        waves_points.p_end.shed_row(0);
        break;
    case 2:
        waves_points.qrs_onset.shed_row(0);
        break;
    case 3:
        waves_points.r_peaks.shed_row(0);
        break;
    case 4:
        waves_points.qrs_end.shed_row(0);
        break;
    case 5:
        waves_points.t_end.shed_row(0);
        break;
    default:
        break;
    }
}

void Waves::set_waves(Waves_Points waves)
{
    waves_points = waves;
}

void Waves::write_to_file(int it)
{
    QString a = "../EcgApplicationCore/results/waves/waves_";
    a.append(QString::number(it));
    a.append(".txt");
    QFile file(a);
    qInfo() << a;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    for(int i = 0; i < r_peaks_vec.size(); i++)
    {
        out << QString::number(waves_points.p_onset[i]) << ";" <<
               QString::number(waves_points.p_end[i]) << ";" <<
               QString::number(waves_points.qrs_onset[i]) << ";" <<
               QString::number(r_peaks_vec[i]) << ";" <<
               QString::number(waves_points.qrs_end[i]) << ";" <<
               QString::number(waves_points.t_end[i]) << "\n";
    }
    qInfo() << "Przeszło";
//    for(int i = 0; i < signal_raw.size(); i++)
//        out << QString::number(signal_raw[i]) << "\n";
}

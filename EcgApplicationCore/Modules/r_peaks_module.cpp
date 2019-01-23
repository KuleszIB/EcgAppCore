#include "r_peaks_module.h"
#include <iostream>
#include <math.h>
#include <cmath>
#define pi 3.14159265358979323846

using namespace std;

R_Peaks::R_Peaks()
{
    signal_raw = Ecg_Baseline::signal_filtered;             // Sygnal po filtracji
    signal_filtered = Ecg_Baseline::signal_filtered;        // Sygnal po filtracji
    sampling_frequency = Ecg_Baseline::sampling_frequency;  // Czestotliwosc probkowania
}

R_Peaks::R_Peaks(arma::vec signal, double fs)
{
    signal_raw = signal;        // Sygnal po filtracji
    signal_filtered = signal;   // Sygnal po filtracji
    sampling_frequency = fs;    // Czestotliwosc probkowania
    calc_time_vec();            // Obliczenie wektora czasu
}

void R_Peaks::pan_tompkins()
{
    /*****************************************************************************
    * Funkcja realizuje algorytm Pan-Topkins na sygnale signal_filtered.
    *****************************************************************************/

    // WSTEPNE PRZETWARZANIE SYGNALU

    signal_filtered = signal_raw;
    filter_highpass(5,30);      // Filtracja gornoprzepustowa
    differentiate();            // Rozniczkowanie
    square();                   // Potegowanie
    int W = floor(0.025*sampling_frequency);        // Ustalenie dlugosci okna calkowania
    if (W%2 == 0)
        W = ceil(0.025*sampling_frequency);
    integrate(2*W+1);           // Calkowanie

    // WSTEPNE WYSZUKIWANIE PIKOW
    // Warunek: wyszukaj maksima, ktorych wartosc jest wieksza niż Amax/15

    arma::vec peaks = find_peaks(signal_filtered);  // Wyszukanie pikow
    int N = int(peaks.size());

    arma::vec peakValue(N);     // Obliczenie wartosci sygnalu w miejscach znalezionych pikow
    for (int i=0; i<N; i++)
        peakValue[i] = signal_filtered(int(peaks[i]));

    // WYSZUKIWANIE ZALAMKOW R
    // Warunek: wsrod znaleznionych pikow wyszukaj maksima z zalozeniem, ze nie moga byc polozone blizej niz 200 ms

    double max_value = double(peakValue[0]);
    int max_number = int(peaks[0]);
    int nrOfSamples = int(floor(0.2 * sampling_frequency)); // Ilosc probek odpowiadajaca 200 ms

    arma::vec Rpeaks(N);    // Wektor zalamkow R
    int counter = 0;        // Licznik znalezionych zalamkow

    if (N > 1)              // Jezeli ilosc znalezionych pikow jest wieksza niz 1
    {
        for (int i=1; i<N; i++)
        {
            // Sprawdzenie czy obecna probka jest wieksza od tymczasowego
            // maksimum oraz czy odleglosc pomiedzy nimi jest mniejsza od 0.2s
            if((peakValue[i] > max_value) && ((peaks[i] - max_number) < nrOfSamples))
            {
                max_value = peakValue[i];
                max_number = int(peaks[i]);
            }
            // Jesli odleglosc od poprzedniego maksimum jest wieksza od 0.2s,
            // wartosc ostatniego maksimum jest zapisywana i rozpoczyna sie
            // wyszukiwanie nowego
            else if ((peaks[i] - max_number) >= nrOfSamples)
            {
                Rpeaks[counter++] = max_number;
                max_value = peakValue[i];
                max_number = int(peaks[i]);
            }
            // Jezeli jest to ostatni ze znalezionych pikow, zapisujemy ostatnie maksimum do wektora
            if ((i == (N-1)) && (Rpeaks[counter-1] != max_number))
            {
                Rpeaks[counter++] = max_number;
            }
        }
        // Wyciecie wektora o dlugosci rownej liczbie znalezionych zalamkow R
        r_peaks_vec = Rpeaks.subvec(0,counter-1);
    }
    else
    {
        r_peaks_vec = peaks;
    }
    // Przesuniecie znalezionych probek ze wzgledu na uzycie filtra FIR podczas calkowania
    r_peaks_vec -= W;
}

arma::vec R_Peaks::find_peaks(arma::vec signal)
{
    /*****************************************************************************
    * Funcja wyszukuje maksima w sygnale signal, ktorych wartosc jest wieksza niz prog.
    * Funkcja zwraca numery probek znalezionych maksimow.
    *****************************************************************************/

    int N = int(signal.size());             // Dlugosc sygnalu
    arma::vec peaks(N);                     // Wektor pikow
    double threshold = signal.max() / 15;   // Prog
    int counter = 0;                        // Licznik znalezionych pikow

    if (N > 2)  // Jezeli w sygnale wystepuja min. 3 probki
    {
        // Znajdz maksimum, ktorego wartosc jest wieksza niz prog
        for (int i=1; i<N-1; i++)
            if ((signal(i) > signal(i-1)) && (signal(i) > signal(i+1)) && (signal(i) > threshold))
                peaks[counter++] = i;

        // Wyciecie sygnalu, w zaleznosci od tego, czy maksimum zostalo znalezione
        if (counter > 0)
            peaks = peaks.subvec(0,counter-1);
        else
            peaks = N-1;
    }
    return peaks;
}

void R_Peaks::filter_highpass(double fc, int M)
{
    /*****************************************************************************
    * Funkcja realizuje filtracje gornoprzepustowa sygnalu signal_filtered
    * za pomoca filtra o czestotliwosci odciecia fc zaprojektowanego metoda okien
    * o dlugosci 2M+1 przy wykorzystaniu okna Bartletta.
    *****************************************************************************/

    fc = fc / sampling_frequency / 2;   // Znormalizowana czestotliwosc odciecia
    int N = 2 * M + 1;                  // Dlugosc filtra

    // Zdefiniowanie wspolczynnikow filtra h
    arma::vec h(N);
    for (int i=-M; i<0; i++)
        h[i+M] = -2*fc*pi*arma::sinc(i*2*fc*pi);

    h[M] = 1-2*fc;
    for (int i=1; i<=M; i++)
        h[i+M] = -2*fc*pi*arma::sinc(i*2*fc*pi);

    // Zdefiniowanie okna
    arma::vec okno(N);
    for (int i=0; i<N; i++)
        okno[i] = 1-(2*(abs(double(i)-(double(N)-1)/2))/(double(N)-1));

    // Przemnozenie wspolczynnikow filtra przez okno
    arma::vec hw(N);
    hw = h % okno;

    // Splot sygnalu i wspolczynnikow filtra
    signal_filtered = arma::conv(signal_filtered,hw,"same");
}

void R_Peaks::differentiate()
{
    /*****************************************************************************
     * Funkcja realizuje rozniczkowanie sygnalu signal_filtered.
    *****************************************************************************/

    int N = int(signal_filtered.size());
    arma::vec signal_diff(N);
    signal_diff[0] = 0;
    signal_diff[1] = 0;
    signal_diff[N-2] = 0;
    signal_diff[N-1] = 0;

    for (int i=2; i<N-2; i++)
        signal_diff[i] = (-signal_filtered(i-2) - 2*signal_filtered(i-1) + 2*signal_filtered(i+1) + signal_filtered(i+2)) / 8;
    signal_filtered = signal_diff;

}

void R_Peaks::square()
{
    /*****************************************************************************
     * Funkcja realizuje potegowanie sygnalu signal_filtered.
    *****************************************************************************/

    signal_filtered = signal_filtered % signal_filtered;
}

void R_Peaks::integrate(int W)
{
    /*****************************************************************************
     * Funkcja realizuje calkowanie sygnalu signal_filtered z ruchomym oknem
     * o dlugosci W.
    *****************************************************************************/

    int N = int(signal_filtered.size());
    arma::vec  signal_int = arma::zeros<arma::vec>(N);
    for (int i=W-1; i<N; i++)
    {
        for (int j=i-W+1; j<=i; j++)
        {
            signal_int[i] = signal_int[i] + signal_filtered[j];
        }
        signal_int[i] = signal_int[i] / W;
    }
    signal_filtered = signal_int;
}

void R_Peaks::find_r_peaks()
{
    /*****************************************************************************
     * Funkcja wywoluje algorytm Pan-Tompkins w celu znalezienia zalamkow R.
    *****************************************************************************/
    pan_tompkins();
}

arma::vec R_Peaks::get_r_peaks()
{
    /*****************************************************************************
     * Funkcja zwraca wektor numerow probek znalezionych zalamkow R.
    *****************************************************************************/
    return r_peaks_vec;
}

void R_Peaks::set_r_peaks(arma::vec new_r_peaks)
{
    /*****************************************************************************
     * Funkcja ustawia nowa wartosc wektora numerow probek zalamkow R.
     * Niezbedna podczas przeprobkowania.
    *****************************************************************************/
    r_peaks_vec = new_r_peaks;
}

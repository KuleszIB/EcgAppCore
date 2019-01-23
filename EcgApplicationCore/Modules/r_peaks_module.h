#ifndef R_PEAKS_H
#define R_PEAKS_H

#include "ecg_baseline_module.h"

class R_Peaks : public Ecg_Baseline
{
private:
    void pan_tompkins();                    // Funkcja realizujaca algorytm Pan-Tompkins
    void filter_highpass(double fc, int M); // Funkcja realizujaca filtracje gornoprzepustowa
    void square();                          // Funkcja realizujaca potegowanie sygnalu
    void integrate(int W);                  // Funkcja realizujaca calkowanie sygnalu

protected:
    void differentiate();                   // Funkcja realizujaca roznickzowanie sygnalu
    arma::vec find_peaks(arma::vec signal); // Funkcja szukajaca maksimow
    arma::vec r_peaks_vec;                  // Wektor znalezionych zalamkow R

public:
    R_Peaks();                                  // Konstruktor 1
    R_Peaks(arma::vec signal, double fs=360);   // Konstruktor 2
    void find_r_peaks();                        // Funkcja szukajaca zalamkow R
    arma::vec get_r_peaks();                    // Funkcja zwracajaca znalezione zalamki R
    void set_r_peaks(arma::vec new_r_peaks);    // Funkcja ustawiajaca nowa wartosc zalamkow R
};

#endif // R_PEAKS_H

#ifndef WAVES
#define WAVES

#include "r_peaks_module.h"

struct Waves_Points
{
    arma::vec r_peaks;      // Wektor zalamkow R
    arma::vec qrs_onset;    // Wektor punktow QRS-onset
    arma::vec qrs_end;      // Wektor punktow QRS-end
    arma::vec t_end;        // Wektor punktow T-end
    arma::vec p_onset;      // Wektor punktow P-onset
    arma::vec p_end;        // Wektor punktow P-end
};

class Waves : public R_Peaks
{
private:
    void find_qrs_onset_end();  // Funkcje szukajace punktow charakterstycznych
    void find_t_end();
    void find_p_onset_end();

protected:
    Waves_Points waves_points;  // Struktura przechowujaca znalezione punkty
    void filter_lowpass(double fc, int M);  // Filtracja dolnoprzepustowa

public:
    Waves();                                                // Konstruktor 1
    Waves(arma::vec signal, arma::vec r_peaks, double fs);  // Konstruktor 2
    void find_waves();          // Funkcja szukajaca punktow charakterystycznych
    Waves_Points get_waves();   // Funkcja zwracajaca nr punktow charakterystycznych
    void set_waves(Waves_Points waves);
    void remove_head(int which);
    void write_to_file(int it);
};

#endif // WAVES_H

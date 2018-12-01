#ifndef HRV2_H
#define HRV2_H

#include "r_peaks_module.h"

struct histogram_hrv2
{
    arma::vec values; // typ danych do sprawdzenia
    arma::vec bins; // do czego to ma sie odnosic?  do zmiany albo wyrzucenia
};

class Hrv2 : public R_Peaks
{
private:
    double cum_time_vec;
    histogram_hrv2 histogram;
    double tinn;
    double triangular_index; // -> do konsultacji z Kasi
    double poincare; // -> do konsultacji z Kasią
    double sd1;
    double sd2;

    void calc_cum_time_vec();
    void calc_histogram();
    void calc_tinn();
    void calc_triangular_index();
    void calc_poincare();
    void calc_SD1();
    void calc_SD2();

public:
    Hrv2();
    Hrv2(arma::vec r_peaks);

    void calc_params();
    histogram_hrv2 get_hist();
    double get_tinn();
    double get_triang_index();
    double get_poincare();

};

#endif // HRV2_H

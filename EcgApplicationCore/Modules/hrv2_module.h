#ifndef HRV2_H
#define HRV2_H

#include "r_peaks_module.h"

//W konstruktorze liczą się interwały RR
//Trzeba wywołać funkcję calc_params() --> wywola wtedy 3 funkcje
//Pod każdą z nich są poboczne
//Na koniec zwraca 4 gety

struct histogram_hrv2
{
    arma::ivec values;
    arma::vec bins;
    int max_value;
};

struct poincare_graph
{
    arma::vec intervals_ox;
    arma::vec intervals_oy;
    arma::vec straight_xy;
    arma::vec sd1_axis_ox;
    arma::vec sd1_axis_oy;
    arma::vec sd2_axis;
    double centroid;
    double sd1;
    double sd2;
};

class Hrv2 : public R_Peaks
{
private:
    arma::vec intervals_original;
    arma::vec intervals;
    double tinn;
    double triangular_index;
    histogram_hrv2 histogram;
    poincare_graph poincare;

    void calc_histogram();
    void remove_outliers();
    void calc_tinn();
    void calc_triangular_index();
    void calc_poincare();
    void calc_SD1();
    void calc_SD2();
    void calc_centroid();
    void calc_poincare_axises();

public:
    Hrv2();
    Hrv2(arma::vec r_peaks);
    void calc_params();
    double get_tinn();
    double get_triang_index();
    histogram_hrv2 get_hist();
    poincare_graph get_poincare();

};

#endif // HRV2_H

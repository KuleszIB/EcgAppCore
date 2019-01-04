#ifndef HRV2_H
#define HRV2_H

#include "r_peaks_module.h"

struct histogram_hrv2
{
    arma::ivec values; // typ danych do sprawdzenia
    arma::vec bins; // do czego to ma sie odnosic?  do zmiany albo wyrzucenia
    int max_value;
};

//Dodalam strukture, mysle ze tak bedzie latwiej dla Moniki do wizualizacji
//Jeszcze nie implementowalam, wiec nei wiem czy tak zostanie
struct poincare_graph
{
    arma::vec intervals_ox;
    arma::vec intervals_oy;
    arma::vec left_axis;
    arma::vec right_axis;
    arma::vec centroid;
    double sd1;
    double sd2;

};

class Hrv2 : public R_Peaks
{
private:
    //double cum_time_vec; // tego raczej nie potrzebuje
    histogram_hrv2 histogram;
    double tinn;
    double triangular_index;
    poincare_graph poincare; // tu nie wiem czy tak zostanie
//    double sd1;
//    double sd2;
    arma::vec intervals_original;
    arma::vec intervals;


    //void calc_cum_time_vec(); tego nie potrzeba
    void calc_histogram();
    void remove_outliers();
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
    poincare_graph get_poincare();

};

#endif // HRV2_H

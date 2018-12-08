#ifndef HRV1_H
#define HRV1_H

#include "ecg_baseline_module.h"
#include "r_peaks_module.h"

//Jeśli czegoś brakuje daj mi znać

struct Time_Params
{
    double rr_mean;
    double sdnn;
    double rmssd;
    double nn50;
    double pnn50;
};

struct Frequency_Params
{
    double tp;
    double ulf;
    double vlf;
    double lf;
    double hf;
    arma::vec freq_ulf;
    arma::vec freq_vlf;
    arma::vec freq_lf;
    arma::vec freq_hf;
};

class Hrv1 : public R_Peaks
{
private:
    arma::vec r_peaks_vec;              //RR intervals
    arma::vec uniform_r_peaks_vec;      //RR intervals after resampling
    arma::vec cum_time_vec;
    arma::vec uniform_time_vec;
    arma::vec frequency_vec;
    arma::vec periodogram;
    Time_Params time_params;
    Frequency_Params freq_params;

    void calc_cum_time_vec();
    void calc_freq_vec();
    void resample();
    void calc_time_params();
    void calc_freq_params();

public:
    Hrv1();
    Hrv1(arma::vec r_peaks); // tu się powinno liczyć od razu cum_time_vec

    void calc_periodogram();
    void calc_params();

    arma::vec get_periodogram();
    arma::vec get_freq_vec();
    Time_Params get_time_params();
    Frequency_Params get_freq_params();
};

#endif // HRV1_H


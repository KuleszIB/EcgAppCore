#ifndef R_PEAKS_H
#define R_PEAKS_H

#include "ecg_baseline_module.h"

class R_Peaks : public Ecg_Baseline
{
private:
    void pan_tompkins();
    void filter_highpass(double fc, int M);
    void square();
    void integrate(int W);


protected:
    void differentiate();
    arma::uvec find_peaks(arma::vec signal);
    arma::uvec r_peaks_vec; // output

public:
    R_Peaks();
    R_Peaks(arma::vec signal);
    void find_r_peaks();
    arma::uvec get_r_peaks();
};

#endif // R_PEAKS_H

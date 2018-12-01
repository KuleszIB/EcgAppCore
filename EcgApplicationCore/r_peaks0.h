#ifndef R_PEAKS_H
#define R_PEAKS_H

#include "ecg_baseline.h"

class R_Peaks : public Ecg_Baseline
{
private:
    void pan_tompkins();
    void filter_highpass(double fc, int M);
    void differentiate();
    void square();
    void integrate(int W);
    arma::vec find_peaks();

protected:
    arma::vec r_peaks_vec; // output

public:
    R_Peaks();
    R_Peaks(arma::vec signal);
    void find_r_peaks();
    arma::vec get_r_peaks();
};

#endif // R_PEAKS_H

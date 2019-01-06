#ifndef WAVES_H
#define WAVES_H

#include "r_peaks_module.h"

struct Waves_Points
{
    arma::uvec r_peaks;
    arma::uvec qrs_onset;
    arma::uvec qrs_end;
    arma::uvec t_end;
    arma::uvec p_onset;
    arma::uvec p_end;
};

class Waves : public R_Peaks
{
private:
    void find_qrs_onset_end();
    void find_t_end();
    void find_p_onset_end();

protected:
    Waves_Points waves_points;
    void filter_lowpass(double fc, int M);

public:
    Waves();
    Waves(arma::vec signal, arma::uvec r_peaks, double fs);
    void find_waves();
    Waves_Points get_waves();
};

#endif // WAVES_H

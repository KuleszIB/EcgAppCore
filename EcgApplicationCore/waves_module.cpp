#include "waves_module.h"

Waves::Waves()
{

}

Waves::Waves(arma::vec signal, arma::vec r_peaks, double fs)
{
    signal_filtered = signal;
    r_peaks_vec = r_peaks;
    sampling_frequency = fs;
}

void Waves::find_qrs_onset()
{
    // waves_points.qrs_onset = ...
}

void Waves::find_qrs_end()
{
    // waves_points.qrs_end = ...
}

void Waves::find_t_end()
{
    // waves_points.t_end = ...
}

void Waves::find_p_onset()
{
    // waves_points.p_onset = ...
}

void Waves::find_p_end()
{
    // waves_points.p_end = ...
}

void Waves::filter_lowpass()
{

}

void Waves::find_waves()
{
    find_qrs_onset();
    find_qrs_end();
    find_t_end();
    find_p_onset();
    find_p_end();
}

Waves_Points Waves::get_waves()
{
    return waves_points;
}

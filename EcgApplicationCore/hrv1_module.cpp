#include "hrv1_module.h"

//Najpierw luknij do headera jakie masz możliwości

Hrv1::Hrv1()
{

}

Hrv1::Hrv1(arma::vec r_peaks)
{
    //r_peaks_vec = r_peaks;
    calc_cum_time_vec();
}

void Hrv1::calc_cum_time_vec()
{

}

void Hrv1::calc_freq_vec()
{

}

void Hrv1::resample()
{

}

void Hrv1::calc_time_params()
{

}

void Hrv1::calc_freq_params()
{

}

void Hrv1::calc_periodogram()
{

}

void Hrv1::calc_params()
{

}

arma::vec Hrv1::get_periodogram()
{
    return periodogram;
}

arma::vec Hrv1::get_freq_vec()
{
    return frequency_vec;
}

Time_Params Hrv1::get_time_params()
{
    return time_params;
}

Frequency_Params Hrv1::get_freq_params()
{
    return freq_params;
}

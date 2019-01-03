#include "hrv2_module.h"

Hrv2::Hrv2()
{

}

Hrv2::Hrv2(arma::vec r_peaks)
{

}

void Hrv2::calc_cum_time_vec()
{

}

void Hrv2::calc_histogram()
{

}

void Hrv2::calc_tinn()
{

}

void Hrv2::calc_triangular_index()
{

}

void Hrv2::calc_poincare()
{

}

void Hrv2::calc_SD1()
{

}

void Hrv2::calc_SD2()
{

}

histogram_hrv2 Hrv2::get_hist()
{
    return histogram;
}

double Hrv2::get_tinn()
{
    return tinn;
}

double Hrv2::get_triang_index()
{
    return triangular_index;
}

double Hrv2::get_poincare()
{
    return poincare;
}

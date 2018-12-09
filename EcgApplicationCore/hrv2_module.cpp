#include "hrv2_module.h"
#include <cmath>

Hrv2::Hrv2()
{

}

Hrv2::Hrv2(arma::vec r_peaks)
{
    double fs = 360;
    r_peaks = {75,367,661,944,1230,1514,1806,2042,2401,2704,2996,3278,3555,3859,4167,4464,4763,5057,5345,5631,5914,6211,6524,6822,7104,7379,7668,7952,8243,8537,8836,9140,9429,9706,9991};
    //definicja intervals?
    intervals[1] = (r_peaks[2]-r_peaks[1])/fs;
    for(int i=1;i<=(r_peaks.size() - 1);i++)
    {
         intervals[i] = r_peaks[i] - r_peaks[i-1];             //RR intervals
         intervals[i] = intervals[i]/fs;                    //sampling frequency = 360; changing to the time [s]
    }
}

void Hrv2::calc_cum_time_vec()
{
//jesli to funkcja do tachogramu to ja go nie potrzebuje ;)
}

void Hrv2::remove_outliers()
{
    //wyliczenie średniej wartości odległosci RR
    double sum = 0;
    double average_distance = 0;
    arma::vec differences;

    for (int i=0; i<intervals.size(); i++)
    {
        sum = sum + intervals[i];
    }
    average_distance = sum/intervals.size();

    for(int i=0; i<intervals.size(); i++)
    {
        differences[i] = std::abs(intervals[i] - average_distance);
    }

    // if differences[i] > 100{remove}
    //usuwanie próbek odległych o 100 od średniej
    //w matlabie jest inaczej - do ewentualnej poprawy

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

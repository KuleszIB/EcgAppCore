#include "ecg_baseline.h"
#include "vector"
#include "liquid/liquid.h"
//Jak filtrujesz czy coś, to wpisuj to do pól obiektu

module1::Ecg_Baseline::Ecg_Baseline()
{

}

module1::Ecg_Baseline::Ecg_Baseline(std::vector<double> input, double fs)
{

}

void module1::Ecg_Baseline::filter_moving_average()
{

}

void module1::Ecg_Baseline::filter_butterworth()
{

}

void module1::Ecg_Baseline::filter_chebyshev()
{

}

void module1::Ecg_Baseline::filter_savitzky_golay()
{

}

void module1::Ecg_Baseline::filter_lms()
{

}

void module1::Ecg_Baseline::filter_noise()
{

}

void module1::Ecg_Baseline::filter_baseline(Filter_Params filter_params)
{

}

std::vector<double>module1::Ecg_Baseline::get_time_vec() //Nie wiem czy to nie musi być przed konstruktorem jeszcze
{
    std::vector<double> time_vec;

    return time_vec;
}

std::vector<double>module1::Ecg_Baseline::get_signal_raw()
{
    std::vector<double> signal_raw;

    return signal_raw;
}

std::vector<double>module1::Ecg_Baseline::get_signal_filtered()
{
    std::vector<double> signal_filtered;

    return signal_filtered;
}

std::vector<double>module1::Ecg_Baseline::get_signal_baseline()
{
    std::vector<double> baseline;

    return baseline;
}

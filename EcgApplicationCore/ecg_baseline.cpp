#include "ecg_baseline.h"

//Jak filtrujesz czy coś, to wpisuj to do pól obiektu

Ecg_Baseline::Ecg_Baseline()
{

}

Ecg_Baseline::Ecg_Baseline(std::vector<double> input, double fs)
{

}

void Ecg_Baseline::filter_moving_average()
{

}

void Ecg_Baseline::filter_butterworth()
{

}

void Ecg_Baseline::filter_chebyshev()
{

}

void Ecg_Baseline::filter_savitzky_golay()
{

}

void Ecg_Baseline::filter_lms()
{

}

void Ecg_Baseline::filter_noise()
{

}

void Ecg_Baseline::filter_baseline(Filter_Params filter_params)
{

}

void Ecg_Baseline::calc_time_vec() //Nie wiem czy to nie musi być przed konstruktorem jeszcze
{
    std::vector<double> time_vec;

    return time_vec;
}

void Ecg_Baseline::get_signal_raw()
{
    std::vector<double> signal_raw;

    return signal_raw;
}

void Ecg_Baseline::get_signal_filtered()
{
    std::vector<double> signal_filtered;

    return signal_filtered;
}

void Ecg_Baseline::get_signal_baseline()
{
    std::vector<double> baseline;

    return baseline;
}

#include "ecg_baseline.h"
#include "armadillo"
//Jak filtrujesz czy coś, to wpisuj to do pól obiektu

Filter_Type Filter_Params::get_filter_type()
{
    return filter_type;
}

Ecg_Baseline::Ecg_Baseline()
{

}

Ecg_Baseline::Ecg_Baseline(arma::vec input, double fs)
{
    signal_raw = input;
    sampling_frequency = fs;
}

void Ecg_Baseline::filter_bandpass()
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
    switch(filter_params.get_filter_type())
    {
    case MOVING_AVERAGE:
        filter_moving_average();
        break;
    case BUTTERWORTH:
        filter_butterworth();
        break;
    case CHEBYSHEV:
        filter_chebyshev();
        break;
    case SAVITZKY_GOLAY:
        filter_savitzky_golay();
        break;
    case LMS:
        filter_lms();
        break;
    default:
        filter_moving_average();
        break;
    }
}

arma::vec Ecg_Baseline::get_time_vec() //Nie wiem czy to nie musi być przed konstruktorem jeszcze
{
    return time_vec;
}

arma::vec Ecg_Baseline::get_signal_raw()
{
    return signal_raw;
}

arma::vec Ecg_Baseline::get_signal_filtered()
{
    return signal_filtered;
}

arma::vec Ecg_Baseline::get_signal_baseline()
{
    return signal_baseline;
}

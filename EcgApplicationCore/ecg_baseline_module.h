#ifndef ECG_BASELINE_H
#define ECG_BASELINE_H

#include "armadillo"

enum Filter_Type
{
    MOVING_AVERAGE = 0,
    BUTTERWORTH = 1,
    CHEBYSHEV = 2,
    SAVITZKY_GOLAY = 3,
    LMS = 4
};

class Filter_Params
{
private:
    Filter_Type filter_type;
    //musisz sama sobie dopisać, o ile potrzebujesz do tego osobnej klasy
public:
    void set_filter_type(Filter_Type filter_type_set);
    Filter_Type get_filter_type();
};

class Ecg_Baseline
{
private: //funkcje pomocnicze, wydaje mi się, że jak to jest rozdzielone, to po prostu ładniej wygląda ;p
    void filter_bandpass();
    void filter_moving_average();
    void filter_butterworth();
    void filter_chebyshev();
    void filter_savitzky_golay();
    void filter_lms();

protected:
    arma::vec signal_raw;
    arma::vec signal_filtered;
    arma::vec signal_baseline;
    double sampling_frequency;
    arma::vec time_vec;
    void calc_time_vec(); //powinno to być użyte w konstruktorze

public:
    Ecg_Baseline(); //chyba, że masz jakąś inną koncepcję
    Ecg_Baseline(arma::vec input, double fs);

    void filter_noise(); //czy potrzebne częstotliwości odcięcia? -> informacja również ważna dla GUI
    void filter_baseline(Filter_Params filter_params);
    arma::vec get_signal_raw();
    arma::vec get_signal_filtered();
    arma::vec get_signal_baseline();
    arma::vec get_time_vec();
};

#endif // ECG_BASELINE_H

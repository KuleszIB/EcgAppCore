#ifndef ECG_BASELINE_H
#define ECG_BASELINE_H

#include <vector>

enum Filter_Type
{
    moving_average = 0,
    butterworth = 1,
    chebyshev = 2,
    savitzky_golay = 3,
    lms = 4
};

class Filter_Params
{
    Filter_Type filter_type;
    //musisz sama sobie dopisać, o ile potrzebujesz do tego osobnej klasy
};

class Ecg_Baseline
{
private: //funkcje pomocnicze, wydaje mi się, że jak to jest rozdzielone, to po prostu ładniej wygląda ;p
    void calc_time_vec(); //powinno to być użyte w konstruktorze
    void filter_moving_average();
    void filter_butterworth();
    void filter_chebyshev();
    void filter_savitzky_golay();
    void filter_lms();

public:
    Ecg_Baseline(); //chyba, że masz jakąś inną koncepcję
    Ecg_Baseline(std::vector<double> input, double fs);
    std::vector<double> signal_raw;
    std::vector<double> signal_filtered;
    std::vector<double> signal_baseline;
    double sampling_frequency;
    std::vector<double> time_vec;

    void filter_noise(); //czy potrzebne częstotliwości odcięcia? -> informacja również ważna dla GUI
    void filter_baseline(Filter_Params filter_params);
    std::vector<double> get_signal_raw();
    std::vector<double> get_signal_filtered();
    std::vector<double> get_signal_baseline();
    std::vector<double> get_time_vec();
};

#endif // ECG_BASELINE_H

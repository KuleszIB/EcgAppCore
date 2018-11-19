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
    std::vector<double> calc_time_vec(std::vector<double> input, double fs){int N = input.arma::n_rows; std::vector<double> a = linspace<std::vector<double>>(0, N, 1 / fs); return a;}; //powinno to być użyte w konstruktorze
    void filter_moving_average(std::vector<double> syg_wejsciowy, double fs);
    void filter_butterworth(std::vector<double> syg_wejsciowy, double fs);
    void filter_chebyshev(std::vector<double> syg_wejsciowy, double fs);
    void filter_savitzky_golay(std::vector<double> syg_wejsciowy, double fs);
    void filter_lms(std::vector<double> syg_wejsciowy, double fs);

public:
    Ecg_Baseline(); //chyba, że masz jakąś inną koncepcję
    Ecg_Baseline(std::vector<double> input, double fs);
    std::vector<double> signal_raw;
    //std::vector<double> signal_filtered;
    //std::vector<double> signal_baseline;
    double sampling_frequency;
    std::vector<double> time_vec;

    std::vector<double> filter_noise(std::vector<double> syg_wejsciowy, double fs); //czy potrzebne częstotliwości odcięcia? -> informacja również ważna dla GUI
    std::vector<double> filter_noise_bp(std::vector<double> syg_wejsciowy, double fs);
    void filter_baseline(Filter_Params filter_params);
    std::vector<double> get_signal_raw();
    std::vector<double> get_signal_filtered();
    std::vector<double> get_signal_baseline();
    std::vector<double> get_time_vec();
};

#endif // ECG_BASELINE_H

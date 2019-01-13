#ifndef ECG_BASELINE_H
#define ECG_BASELINE_H

#include "armadillo"
#include <QFile>
#include <QString>

enum Filter_Type
{
    MOVING_AVERAGE = 0,
    BUTTERWORTH = 1,
    CHEBYSHEV = 2,
    SAVITZKY_GOLAY = 3,
    LMS = 4
};

struct Filter_Values
{
    double high_cutoff_freq;
    double low_cutoff_freq;
    unsigned int filter_order;
    unsigned int filter_length;
    double step_size;
};

class Filter_Params
{
private:
    Filter_Type filter_type;
    Filter_Values filter_values;
    //musisz sama sobie dopisać, o ile potrzebujesz do tego osobnej klasy
public:
    void set_filter_type(Filter_Type filter_type_set);
    void set_filter_params(double high, double low, unsigned int order, unsigned int length, double step);
    Filter_Type get_filter_type();
    Filter_Values get_filter_values();
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
    Filter_Params filter_params;
    void calc_time_vec(); //powinno to być użyte w konstruktorze

public:
    Ecg_Baseline(); //chyba, że masz jakąś inną koncepcję
    Ecg_Baseline(arma::vec input, double fs);

    void filter_noise(); //czy potrzebne częstotliwości odcięcia? -> informacja również ważna dla GUI
    void filter_baseline(Filter_Params filter_params);
    arma::vec get_signal_raw();
    arma::vec get_signal_filtered();
    arma::vec get_signal_baseline();
    arma::vec get_time_vec(int it);
    double get_sampling_freq();
    void set_signal_filtered(arma::vec signal);
    void set_signal_raw(arma::vec signal);
    virtual void write_to_file(int it); // do usunięcia później
};

#endif // ECG_BASELINE_H

#ifndef T_WAVE_ALT_H
#define T_WAVE_ALT_H

#include "t_peaks.h"
// usuń moje komentarze później
// dziedziczysz:
//  Ecg_Baseline:
//      arma::vec signal_raw;           -> któryś z tych
//      arma::vec signal_filtered;      -> któryś z tych
//      arma::vec signal_baseline;
//      double sampling_frequency;      -> tego używasz
//      arma::vec time_vec;             -> tego używasz
//      void calc_time_vec();           -> tego używasz chyba
//  R_Peaks:
//      void differentiate();
//      arma::vec find_peaks(arma::vec signal); -> w sumie to nie wiem po co, ale boję się tego już teraz zmieniać ;p
//      arma::vec r_peaks_vec;
//  Waves:
//      Waves_Points waves_points;      -> tego używasz
//      void filter_lowpass(double fc, int M);  -> tego używasz chyba
//  T_Peaks:
//      arma::vec t_peaks;              -> tego używasz
//      void find_t_peaks()             -> to jest do implementacji

class T_Wave_Alt : public T_Peaks
{
private:
    arma::vec odd_t;            // zastępcze nieparzyste
    arma::vec even_t;           // zastępcze parzyste
    arma::vec STp_min;
    arma::vec TpTe_min;
    double alt;
    void filter_t_wave_alt();   // filter_lowpass z Waves może być?
    void preprocessing_t_wave_alt(); // myślisz, że nie będzie problemem nadpisanie QRSends_T itd. w waves_points?
    void remove_wrong_t_detection();
    void sample_counter();

public:
    T_Wave_Alt();
    T_Wave_Alt(arma::vec signal, double fs, Waves_Points waves); // wywołaj calc_time_vec() i wpisz do time_vec
    void analyze();             // główna funkcja wywołująca wszystkie podfunkcje i wpisująca do pól obiektu
    arma::uvec get_t_peaks();
    double get_alt();
};

#endif // T_WAVE_ALT_H

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
    arma::vec odd_T;            // zastępcze nieparzyste
    arma::vec even_T;           // zastępcze parzyste
    int STp_min;                //ZMIANA !!! Kasia P. (vec na int)
    int TpTe_min;               //ZMIANA !!! Kasia P. (vec na int)
    double alt;
    arma::vec time_vec_alt;     //DODANE !!! Kasia P. (do wygenerowania wykresu załamków zastępczych)
    arma::vec even_array;       //DODANE !!! Kasia P. (do wygenerowania wykresu)
    arma::vec odd_array;        //DODANE !!! Kasia P. (do wygenerowania wykresu)
    arma::vec even_t_array;     //DODANE !!! Kasia P.(do wygenerowania wykresu)
    arma::vec odd_t_array;      //DODANE !!! Kasia P.(do wygenerowania wykresu)
    void filter_t_wave_alt();   // filter_lowpass z Waves może być? może
    void preprocessing_t_wave_alt(); // myślisz, że nie będzie problemem nadpisanie QRSends_T itd. w waves_points? nie
    void remove_wrong_t_detection();
    void sample_counter();
    void moving_average();      //DODANE !!! Kasia P. (główny algorytm)

public:
    T_Wave_Alt();
    T_Wave_Alt(arma::vec signal, double fs, Waves_Points waves); // wywołaj calc_time_vec() i wpisz do time_vec. ok
    void analyze();             // główna funkcja wywołująca wszystkie podfunkcje i wpisująca do pól obiektu
    arma::vec get_t_peaks();
    arma::vec get_odd_t();          //DODANE !!! Kasia P.
    arma::vec get_even_t();         //DODANE !!! Kasia P.
    arma::vec get_time_vec_alt();   //DODANE !!! Kasia P.
    arma::vec get_even_array();     //DODANE !!! Kasia P.
    arma::vec get_odd_array();      //DODANE !!! Kasia P.
    arma::vec get_even_t_array();   //DODANE !!! Kasia P.
    arma::vec get_odd_t_array();    //DODANE !!! Kasia P.
    double get_alt();
};

#endif // T_WAVE_ALT_H

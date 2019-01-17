#ifndef T_WAVE_ALT_H
#define T_WAVE_ALT_H

#include "t_peaks.h"

struct T_Wave_Alt_Struct
{
    arma::vec odd_T;
    arma::vec even_T;
    arma::vec time_vec_alt;
    arma::vec even_array;
    arma::vec odd_array;
    arma::vec even_t_array;
    arma::vec odd_t_array;
    double alt;
};

class T_Wave_Alt : public T_Peaks
{
private:
    arma::vec odd_T;            // zastępcze nieparzyste
    arma::vec even_T;           // zastępcze parzyste
    int STp_min;                //ZMIANA (vec na int)
    int TpTe_min;               //ZMIANA (vec na int)
    double alt;
    arma::vec time_vec_alt;     //DODANE (do wygenerowania wykresu załamków zastępczych)
    arma::vec even_array;       //DODANE (do wygenerowania wykresu)
    arma::vec odd_array;        //DODANE (do wygenerowania wykresu)
    arma::vec even_t_array;     //DODANE (do wygenerowania wykresu)
    arma::vec odd_t_array;      //DODANE (do wygenerowania wykresu)
    T_Wave_Alt_Struct t_wave_alt_struct; //DODANE (do ostatecznej funkcji get)
    void filter_t_wave_alt();   // filter_lowpass z Waves też może być
    void preprocessing_t_wave_alt();
    void remove_wrong_t_detection();
    void sample_counter();
    void moving_average();      //DODANE (główny algorytm)

public:
    T_Wave_Alt();
    T_Wave_Alt(arma::vec signal, double fs, Waves_Points waves);
    void analyze();                 // główna funkcja wywołująca wszystkie podfunkcje i wpisująca do pól obiektu
    arma::vec get_t_peaks();
    arma::vec get_odd_t();          //DODANE
    arma::vec get_even_t();         //DODANE
    arma::vec get_time_vec_alt();   //DODANE
    arma::vec get_even_array();     //DODANE
    arma::vec get_odd_array();      //DODANE
    arma::vec get_even_t_array();   //DODANE
    arma::vec get_odd_t_array();    //DODANE
    double get_alt();
    T_Wave_Alt_Struct get_t_wave_alt(); //DODANE

};

#endif // T_WAVE_ALT_H

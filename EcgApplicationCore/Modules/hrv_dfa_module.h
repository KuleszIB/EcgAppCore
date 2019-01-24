#ifndef HRV_DFA_H
#define HRV_DFA_H
#include "r_peaks_module.h"
#include "armadillo"

struct Out_DFA { // do wykresow potrzebne rzeczy
    double alpha1; // parametr alfa analizy krotkoczasowej
    double alpha2; // parametr alfa analizy dlugoczasowej
    arma::vec log_F; // wektor logarytmiczny F do wykresu: wartości na osi Y na wykresie (punkty)
    arma::vec log_delta; // wektor logarytmiczny delta do wykresu: wartości na osi  X na wykresie
    arma::vec vector_short_windows; // do wykresu: wartości Y dopasowanej prostej dla krotkich okien;
    arma::vec vector_long_windows; // do wykresu: wartosci Y dopasowanej prostej dla dlugich okien;
};

class HrvDfa : public R_Peaks
{
private:
    arma::vec least_squares(arma::vec tm, arma::vec ym, int delta_m);
    double calculate_F(arma::vec tk, arma::vec x, int delta_m);
    void make_tachogram();

    arma::vec cum_time_vec;
    arma::vec RR_intervals;
    arma::vec r_peaks;
    int middle;
    int first_delta;
    int last_delta;
public:
    Out_DFA calculate_DFA();
    void set_delta(int last_delta, int first_delta);
    HrvDfa();
    HrvDfa(arma::vec r_peaks);
    // jesli chcemy sami wpisac srodek analizy czasowej (middle), najmniejsze okienko (pierwsza_delta), najwieksze okienko (ostatnia_delta)
    HrvDfa(arma::vec r_peaks, int first_delta, int last_delta);
    Out_DFA get_out_DFA();

};

#endif // HRV_DFA_H

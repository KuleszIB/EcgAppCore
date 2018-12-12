#ifndef HRV_DFA_H
#define HRV_DFA_H
#include "r_peaks_module.h"
#include "armadillo"

struct Wyjsciowe_dane_DFA { // do wykresow potrzebne rzeczy
    double alpha1; // parametr alfa analizy krotkoczasowej
    double alpha2; // parametr alfa analizy dlugoczasowej
    arma::vec log_F; // wektor logarytmiczny F do wykresu: wartości na osi Y na wykresie (punkty)
    arma::vec log_delta; // wektor logarytmiczny delta do wykresu: wartości na osi  X na wykresie
    arma::vec prosta_krotkie_okna; // do wykresu: wartości Y dopasowanej prostej dla krotkich okien;
    arma::vec prosta_dlugie_okna; // do wykresu: wartosci Y dopasowanej prostej dla dlugich okien;
};

class HrvDfa : public R_Peaks
{
private:
    arma::vec najmniejsze_kwadraty(arma::vec tm, arma::vec ym, int delta_m);
    double oblicz_F(arma::vec tk, arma::vec x, int delta_m);
    void zrob_tachogram();
    Wyjsciowe_dane_DFA wyjsciowe_dane_DFA;
    Wyjsciowe_dane_DFA oblicz_dane_DFA();
    arma::vec cum_time_vec;
    arma::vec RR_intervals;
    arma::vec r_peaks;
    int middle;
    int pierwsza_delta;
    int ostatnia_delta;
public:
    HrvDfa();
    HrvDfa(arma::vec r_peaks);
    // jesli chcemy sami wpisac srodek analizy czasowej (middle), najmniejsze okienko (pierwsza_delta), najwieksze okienko (ostatnia_delta)
    HrvDfa(arma::vec r_peaks, int middle, int pierwsza_delta, int ostatnia_delta);
    Wyjsciowe_dane_DFA get_wyjsciowe_dane_DFA();

};

#endif // HRV_DFA_H

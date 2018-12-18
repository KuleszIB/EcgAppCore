#include "hrv_dfa_module.h"


HrvDfa::HrvDfa() //konstruktor domyslny
{

}
HrvDfa::HrvDfa(arma::vec r_peaks)
{
    r_peaks = HrvDfa::r_peaks;
    HrvDfa::middle = 12;
    HrvDfa::pierwsza_delta = 4;
    HrvDfa::ostatnia_delta = 64;
}
HrvDfa::HrvDfa(arma::vec r_peaks, int middle, int pierwsza_delta, int ostatnia_delta)
{
    HrvDfa::r_peaks = r_peaks;
    HrvDfa::middle = middle;
    HrvDfa::pierwsza_delta = pierwsza_delta;
    HrvDfa::ostatnia_delta = ostatnia_delta;
}

void HrvDfa::zrob_tachogram()
{
   r_peaks = {75,367,661,944,1230,1514,1806,2042,2401,2704,2996,3278,3555,3859,4167,4464,4763,5057,5345,5631,5914,6211,6524,6822,7104,7379,7668,7952,8243,8537,8836,9140,9429,9706,9991};
   for(int i = 0; i < (r_peaks.size() - 1); i++) {
        RR_intervals[i] = r_peaks[i + 1] - r_peaks[i];             //RR intervals
        RR_intervals[i] = RR_intervals[i] / 360;                    //sampling frequency = 360; changing to the time [s]
   }
   cum_time_vec = arma::cumsum(RR_intervals);                   //creating tachogram's timeline
   cum_time_vec = cum_time_vec/360;                            //changing to the time [s]; NOT SURE IF WORKS
//    for(int i=0;i<cum_time_vec.size();i++) {
//        cum_time_vec[i] = cum_time_vec[i]/360;//tachogram's timeline
   //}
}
Wyjsciowe_dane_DFA HrvDfa::oblicz_dane_DFA() {

    return wyjsciowe_dane_DFA; // tu bede implementowac algorytm
}
Wyjsciowe_dane_DFA HrvDfa::get_wyjsciowe_dane_DFA() {
    return wyjsciowe_dane_DFA;
}

arma::vec HrvDfa::najmniejsze_kwadraty(arma::vec tm, arma::vec ym, int delta_m) {
int M = delta_m;
double YM_sum2 = arma::sum(tm % ym); // odpowiednik .* w matlabie
double TM_sum = arma::sum(tm);
double TM_sumkw = arma::sum(tm % tm);
double YM_sum = arma::sum(ym);
arma::mat Macierz2;
Macierz2 << YM_sum  << arma::endr
         << YM_sum2 << arma::endr; // matko jakie to dziwne
// sprobuje to potem przepisac na normalna inwersje macierzy
// ale w matlabie nie dzialala, wiec wole na razie zostawic tak
double pierwszy_czynnik = 1/(M*TM_sumkw-TM_sum*TM_sum);
arma::mat drugi_czynnik_mnozenia;
drugi_czynnik_mnozenia << TM_sumkw << -TM_sum << arma::endr
                       << -TM_sum  << M       << arma::endr;
drugi_czynnik_mnozenia = drugi_czynnik_mnozenia.t();
arma::mat inv_Macierz1 = pierwszy_czynnik * drugi_czynnik_mnozenia;

return inv_Macierz1 * Macierz2;

}

double HrvDfa::oblicz_F(arma::vec tk, arma::vec x, int delta_m) {
    //calkowanie
    double x_mean = arma::mean(x);
    arma::vec y = arma::cumsum(x-x_mean);
    int K=arma::as_scalar(y.n_elem);
    arma::vec proste;

    // dopasowanie prostych, osobno dla kazdego okienka (dlatego i jest co
    // delta_m)
    // indeksowanie w armadillo od 0
    for (int i = 0; i == K - (K - (K%delta_m)-delta_m); i=i+delta_m) {// minus mod bo zostaje niepełne
        // okienko na końcu sygnału, mod
        // -delta_m bo dodajemy zaraz do indeksu delta_m żeby liczyć prostą dla
        // długości okna
        // wywolujemy funkcje wspolczynniki_HRV_DFA zeby policzyc a i b
        // metoda najmniejszych kwadratow
         arma::vec result = HrvDfa::najmniejsze_kwadraty(tk.rows(i,i+delta_m-1), y.rows(i,i+delta_m-1), delta_m);
         //wydłużamy wektor 'proste' o kolejne dofitowanie
         proste = arma::join_rows(proste, result(1,0) * tk.rows(i,(i+delta_m-1)) + result(0,0));
    }
    double sum=0;
    for (int i=0;i==K-K%delta_m-delta_m;i++) {
        sum = sum + (arma::as_scalar(y(i,0))-arma::as_scalar(proste(i,0)))*(arma::as_scalar(y(i,0))-arma::as_scalar(proste(i,0))); // sum to suma we wzorze na F, obliczam
        // ja osobno dla wiekszej przejrzystosci
    }
        // ostateczny wzor na fluktuacje
    double F = sqrt(sum/(K-K%delta_m-delta_m));
    return F;
}

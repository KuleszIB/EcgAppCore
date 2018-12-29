#include "hrv_dfa_module.h"


HrvDfa::HrvDfa() //konstruktor domyslny
{

}
HrvDfa::HrvDfa(arma::vec r_peaks)
{
    r_peaks = HrvDfa::r_peaks;
    HrvDfa::middle = 12;
    HrvDfa::first_delta = 4;
    HrvDfa::last_delta = 64;
}
HrvDfa::HrvDfa(arma::vec r_peaks, int middle, int first_delta, int last_delta)
{
    HrvDfa::r_peaks = r_peaks;
    HrvDfa::middle = middle;
    HrvDfa::first_delta = first_delta;
    HrvDfa::last_delta = last_delta;
}

void HrvDfa::make_tachogram()
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
Out_DFA HrvDfa::calculate_DFA() {

    return out_DFA; // tu bede implementowac algorytm
}
Out_DFA HrvDfa::get_out_DFA() {
    return out_DFA;
}

arma::vec HrvDfa::least_squares(arma::vec tm, arma::vec ym, int delta_m) {
int M = delta_m;
double YM_sum2 = arma::sum(tm % ym); // odpowiednik .* w matlabie
double TM_sum = arma::sum(tm);
double TM_sumpow = arma::sum(tm % tm);
double YM_sum = arma::sum(ym);
arma::mat Matrix2;
Matrix2 << YM_sum  << arma::endr
         << YM_sum2 << arma::endr; // matko jakie to dziwne
// sprobuje to potem przepisac na normalna inwersje macierzy
// ale w matlabie nie dzialala, wiec wole na razie zostawic tak
double first_factor = 1/(M*TM_sumpow-TM_sum*TM_sum);
arma::mat second_factor;
second_factor << TM_sumpow << -TM_sum << arma::endr
                       << -TM_sum  << M       << arma::endr;
second_factor = second_factor.t();
arma::mat inv_Matrix1 = first_factor* second_factor;

return inv_Matrix1 * Matrix2;

}

double HrvDfa::calculate_F(arma::vec tk, arma::vec x, int delta_m) {
    //calkowanie
    double x_mean = arma::mean(x);
    arma::vec y = arma::cumsum(x-x_mean);
    int K=arma::as_scalar(y.n_elem);
    arma::vec regression_vector;

    // dopasowanie prostych, osobno dla kazdego okienka (dlatego i jest co
    // delta_m)
    // indeksowanie w armadillo od 0
    for (int i = 0; i == K - (K - (K%delta_m)-delta_m); i=i+delta_m) {// minus mod bo zostaje niepełne
        // okienko na końcu sygnału, mod
        // -delta_m bo dodajemy zaraz do indeksu delta_m żeby liczyć prostą dla
        // długości okna
        // wywolujemy funkcje wspolczynniki_HRV_DFA zeby policzyc a i b
        // metoda najmniejszych kwadratow
         arma::vec result = HrvDfa::least_squares(tk.rows(i,i+delta_m-1), y.rows(i,i+delta_m-1), delta_m);
         //wydłużamy wektor 'proste' o kolejne dofitowanie
         regression_vector = arma::join_rows(regression_vector, result(1,0) * tk.rows(i,(i+delta_m-1)) + result(0,0));
    }
    double sum=0;
    for (int i=0;i==K-K%delta_m-delta_m;i++) {
        sum = sum + (arma::as_scalar(y(i,0))-arma::as_scalar(regression_vector(i,0)))*(arma::as_scalar(y(i,0))-arma::as_scalar(regression_vector(i,0))); // sum to suma we wzorze na F, obliczam
        // ja osobno dla wiekszej przejrzystosci
    }
        // ostateczny wzor na fluktuacje
    double F = sqrt(sum/(K-K%delta_m-delta_m));
    return F;
}

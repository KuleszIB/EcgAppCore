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
HrvDfa::HrvDfa(arma::vec r_peaks, int first_delta, int last_delta)
{
    HrvDfa::r_peaks = r_peaks;
    HrvDfa::first_delta = first_delta;
    HrvDfa::last_delta = last_delta;
    HrvDfa::middle = floor(last_delta/ 4); //tu konwersja, ale nie szkodzi bo jest floor
}

void HrvDfa::make_tachogram()
{

   for(int i = 0; i < (r_peaks.n_elem - 1); i++) {
        HrvDfa::RR_intervals[i] = r_peaks[i + 1] - r_peaks[i];             //RR intervals
        HrvDfa::RR_intervals[i] = HrvDfa::RR_intervals[i] / 360;                    //sampling frequency = 360; changing to the time [s]
   }
   HrvDfa::cum_time_vec = arma::cumsum(HrvDfa::RR_intervals);                   //creating tachogram's timeline
   HrvDfa::cum_time_vec = HrvDfa::cum_time_vec/360;                            //changing to the time [s]; NOT SURE IF WORKS

}
Out_DFA HrvDfa::calculate_DFA() {
    make_tachogram();
    arma::vec delta_vector;
    for (int i =0;i=(last_delta-first_delta);i++) {
        delta_vector[i] = first_delta + i; //tworzenie wektora delt
    }
    arma::vec F;
    for (int k = 0; k<delta_vector.n_elem; k++) {
        F[k] = calculate_F(cum_time_vec, RR_intervals, delta_vector(k));
    }
    arma::vec fit = polyfit(log10(delta_vector.rows(0,middle)), log10(F.rows(0,middle)),1);

    // polyfit zwraca
    // wspolczynniki a i b, takie ze dopasowana prosta to y = a * x + b
    arma:: vec fitdata=fit(0) * (log10(delta_vector.rows(0,middle-1)))+fit(1);
    double alpha = arma::as_scalar(fit(0));
    arma::vec fit2 = polyfit(log10(delta_vector.rows(middle,delta_vector.n_elem-1)), log10(F.rows(middle,delta_vector.n_elem -1)),1);
    arma::vec fitdata2=fit2(0)*(log10(delta_vector.rows(middle,delta_vector.n_elem-1)))+fit2(1);
    double alpha2 = arma::as_scalar(fit2(1));
    Out_DFA out_DFA;
    out_DFA.alpha1 = alpha;
    out_DFA.alpha2 = alpha2;
    out_DFA.log_F = log10(F);
    out_DFA.log_delta = log10(delta_vector);
    out_DFA.vector_short_windows = fitdata;
    out_DFA.vector_long_windows = fitdata2;
    return out_DFA;
}
Out_DFA HrvDfa::get_out_DFA() {
    return out_DFA;
}

arma::vec HrvDfa::least_squares(arma::vec tm, arma::vec ym, int delta_m) {
double M = delta_m;
double YM_sum2 = arma::sum(tm % ym); // odpowiednik .* w matlabie
double TM_sum = arma::sum(tm);
double TM_sumpow = arma::sum(arma::square(tm));
double YM_sum = arma::sum(ym);
arma::mat Matrix2 = {YM_sum,YM_sum2};
// sprobuje to potem przepisac na normalna inwersje macierzy
// ale w matlabie nie dzialala, wiec wole na razie zostawic tak
arma::mat Matrix3 = {{TM_sumpow, -TM_sum}, {-TM_sum, M}};
double Matrix4 = 1/(M*TM_sumpow-TM_sum*TM_sum);
arma::mat inv_Matrix1 = 1/Matrix4*Matrix3 ;
return inv_Matrix1 * Matrix2;
}

double HrvDfa::calculate_F(arma::vec tk, arma::vec x, int delta_m) {
    //calkowanie
    double x_mean = arma::mean(x);
    arma::vec y = arma::cumsum(x-x_mean);
    arma::uword K=y.n_elem; //co to w ogole za typ zmiennej
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
         //wydłużamy wektor 'regression_vector' o kolejne dofitowanie
         regression_vector = arma::join_rows(regression_vector, result(1) * tk.rows(i,(i+delta_m-1)) + result(0));
    }
    double sum=0;
    for (int i=0;i==K-K%delta_m-delta_m;i++) {
        sum = sum + ((arma::as_scalar(y(i))-arma::as_scalar(regression_vector(i)))*(arma::as_scalar(y(i))-arma::as_scalar(regression_vector(i)))); // sum to suma we wzorze na F, obliczam
        // ja osobno dla wiekszej przejrzystosci
    }
        // ostateczny wzor na fluktuacje
    double F = sqrt(sum/(K-K%delta_m-delta_m));
    return F;
}

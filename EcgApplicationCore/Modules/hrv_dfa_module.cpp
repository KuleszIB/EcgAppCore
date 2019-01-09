#include "hrv_dfa_module.h"


HrvDfa::HrvDfa() //konstruktor domyslny
{

}
// GDY NIE PODAJEMY DELT
// TO PRZYJMUJEMY 4 i 64, TAKIE JAK W LABORATORIUM
HrvDfa::HrvDfa(arma::vec r_peaks)
{
    r_peaks = HrvDfa::r_peaks;
    HrvDfa::middle = 12;
    HrvDfa::first_delta = 4;
    HrvDfa::last_delta = 64;
}

//KONSTRUKTOR W PRZYPADKU GDY PODAJEMY DELTY
HrvDfa::HrvDfa(arma::vec r_peaks, int first_delta, int last_delta)
{
    HrvDfa::r_peaks = r_peaks;
    HrvDfa::first_delta = first_delta;
    HrvDfa::last_delta = last_delta;
    HrvDfa::middle = floor(last_delta/ 4); //tu konwersja, ale nie szkodzi bo jest floor
}
//ROBIMY TACHOGRAM
void HrvDfa::make_tachogram()
{
    int size = int(r_peaks.size()) - 1;
     arma::vec RR_intervals_temp(size);
   for(int i = 0; i < (r_peaks.n_elem - 1); i++) {
       RR_intervals_temp[i] = r_peaks[i + 1] - r_peaks[i];             //roznice miedzy probkami
        RR_intervals_temp[i] = RR_intervals_temp[i] / 360;                    //dzielimy przez 360, czyli czestotliwosc progkowania
   }
   RR_intervals =  RR_intervals_temp;
   HrvDfa::cum_time_vec = arma::cumsum(HrvDfa::RR_intervals);                   // wektor czasu, armadillo ma funkcje cumsum

}
Out_DFA HrvDfa::calculate_DFA() {
    // najpierw robimy tachogram
    HrvDfa::make_tachogram();
    // tu robimy wektor delt: od first_delta, co jeden, do last_delta
    int size_delta = last_delta-first_delta+1; //rozmiar ktory sie przyda do deklaracji wektorow F, delta_vector...
    arma::vec delta_vector(size_delta);
    for (int i =0;i < last_delta-first_delta;i++) {
        delta_vector[i] = first_delta + i; //tworzenie wektora delt
    }
    // tu obliczamy F
    arma::vec F(size_delta);
    for (int k = 0; k<size_delta; k++) {
        F[k] = calculate_F(cum_time_vec, RR_intervals, delta_vector(k));
    }
    arma::vec fit = least_squares(log10(delta_vector.rows(0,middle-1)), log10(F.rows(0,middle-1)),middle);

    // polyfit zwraca
    // wspolczynniki a i b, takie ze dopasowana prosta to y = a * x + b
    arma:: vec fitdata=fit(1) * (log10(delta_vector.rows(0,middle-1)))+fit(0);
    double alpha = fit(1);
    arma::vec fit2 = least_squares(log10(delta_vector.rows(middle,delta_vector.n_elem-1)), log10(F.rows(middle,delta_vector.n_elem -1)),delta_vector.n_elem-middle-1);
    arma::vec fitdata2=fit2(1)*(log10(delta_vector.rows(middle,delta_vector.n_elem-1)))+fit2(0);
    double alpha2 = fit2(1);
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
    Out_DFA out_DFA = calculate_DFA();
    return out_DFA;
}

arma::vec HrvDfa::least_squares(arma::vec tm, arma::vec ym, int delta_m) {
double M = delta_m;
double YM_sum2 = arma::sum(tm % ym); // odpowiednik .* w matlabie
double TM_sum = arma::sum(tm);
double TM_sumpow = arma::sum(arma::square(tm));
double YM_sum = arma::sum(ym);
arma::mat Matrix2 = {{YM_sum},{YM_sum2}};
// sprobuje to potem przepisac na normalna inwersje macierzy
// ale w matlabie nie dzialala, wiec wole na razie zostawic tak
arma::mat Matrix3 = {{TM_sumpow, -TM_sum}, {-TM_sum, M}};
double Matrix4 = (M*TM_sumpow-TM_sum*TM_sum);
arma::mat inv_Matrix1 = 1/Matrix4*Matrix3 ;
//rezultat to wektor dwoch wartosci:
//ta o indeksie 0 to b, ta o indeksie 1 to a: ax+b,
return inv_Matrix1 * Matrix2;
}

double HrvDfa::calculate_F(arma::vec tk, arma::vec x, int delta_m) {
    //calkowanie
    double x_mean = arma::mean(x); //tick
    arma::vec y = arma::cumsum(x-x_mean);
    arma::uword K=y.n_elem; //co to w ogole za typ zmiennej
    arma::vec regression_vector(K - (K%delta_m)-delta_m);
    // dopasowanie prostych, osobno dla kazdego okienka (dlatego i jest co
    // delta_m)
    // indeksowanie w armadillo od 0
    for (int i = 0; i < (K - (K%delta_m)-delta_m); i=i+delta_m) {// minus mod bo zostaje niepełne
        // okienko na końcu sygnału, mod
        // -delta_m bo dodajemy zaraz do indeksu delta_m żeby liczyć prostą dla
        // długości okna
        // wywolujemy funkcje wspolczynniki_HRV_DFA zeby policzyc a i b
        // metoda najmniejszych kwadratow
         arma::vec result = HrvDfa::least_squares(tk.rows(i,i+delta_m-1), y.rows(i,i+delta_m-1), delta_m); ////to nie tu jest blad /// jednak tu

         //wydłużamy wektor 'regression_vector' o kolejne dofitowanie
         regression_vector.rows(i,(i+delta_m-1)) = result(1) * tk.rows(i,(i+delta_m-1)) + result(0);

    }
    double sum=0;
    for (int i=0;i<K-K%delta_m-delta_m;i++) {
        sum = sum + ((y(i)-regression_vector(i))*(y(i)-regression_vector(i))); // sum to suma we wzorze na F, obliczam
        // ja osobno dla wiekszej przejrzystosci
    }
        // ostateczny wzor na fluktuacje
    double F = sqrt(sum/(K-K%delta_m-delta_m));
    return F;
}

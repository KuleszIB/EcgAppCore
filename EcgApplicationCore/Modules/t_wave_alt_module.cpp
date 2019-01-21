#include "t_wave_alt_module.h"
#define pi 3.14159265358979323846
#include <vector>

T_Wave_Alt::T_Wave_Alt()
{

}

T_Wave_Alt::T_Wave_Alt(arma::vec signal, double fs, Waves_Points waves)
{
       signal_filtered = signal;
       sampling_frequency = fs;
       waves_points = waves;
       calc_time_vec();
}

void T_Wave_Alt::filter_t_wave_alt()
{
//Funkcja filter_t_wave_alt() wykonuje filtrację dolnoprzepustową sygnału
//z wykorzystaniem filtru FIR. Zastosowano okno Barletta.
//Możliwość ustawienia częstotliwości odcięcia (fc) oraz liczby próbek (M).

        double fc = 15;                     //częstotliwość odcięcia
        int M = 30;                         //liczba próbek
        fc = fc / sampling_frequency / 2;   //znormalizowana częstotliwość odcięcia
        int N = 2 * M + 1;                  //liczba współczynników filtra

        // odpowiedź impulsowa filtra dolnoprzepustowego
        arma::vec h(N);
        for (int i=-M; i<0; i++)
            h[i+M] = sin(i*2*fc*pi*pi)/(i*pi);

        h[M] = 2*fc;    //uwzględnienie szczególnego przypadku (N=0)
        for (int i=1; i<=M; i++)
            h[i+M] = sin(i*2*fc*pi*pi)/(i*pi);

        // zdefiniowanie okna Barletta
        arma::vec okno(N);
        for (int i=0; i<N; i++)
            okno[i] = 1-(2*(abs(double(i)-(double(N)-1)/2))/(double(N)-1));

        // wyznaczenie współczynników filtra
        arma::vec hw(N);
        hw = h % okno;

        // filtracja sygnału
        signal_filtered = arma::conv(signal_filtered,hw,"same");
        //std::cout << signal_filtered(0) << std::endl;
}

void T_Wave_Alt::preprocessing_t_wave_alt()
{
//Funkcja preprocessing_t_wave_alt() realizuje wstępne przetwarzanie
//punktów charakterystycznych (QRSend i Tend) wykrytych w sygnale EKG.
//Funkcja zapewnia, że pierwszym pkt. charakt. jest QRSend, a ostatnim Tend,
//że liczba QRSend i Tend jest taka sama oraz, że liczba pkt. charakt. jest parzysta.

    if(waves_points.t_end(0) < waves_points.qrs_end(0)) //gdy sygnał zaczyna się od Tend
    {
        arma::vec tmp(waves_points.t_end.size()-1);                 //wektor pomocniczy
        tmp = waves_points.t_end.tail(waves_points.t_end.size()-1); //usunięcie pierwszego Tend
        waves_points.t_end.set_size(tmp.size());                    //zmiana rozmiaru wektora t_end
        waves_points.t_end = tmp;                                   //zapisanie nowego wektora t_end
        /*for (int i=0; i<(int)waves_points.t_end.size(); i++){
            std::cout << waves_points.t_end(i) << std::endl;
        }*/
    }
    if(waves_points.qrs_end(waves_points.qrs_end.size()-1) > waves_points.t_end(waves_points.t_end.size()-1))
        //gdy sygnał kończy się na QRSend
    {
        arma::vec tmp(waves_points.qrs_end.size()-1);                   //wektor pomocniczy
        tmp = waves_points.qrs_end.head(waves_points.qrs_end.size()-1); //usunięcie ostatniego QRSend
        waves_points.qrs_end.set_size(tmp.size());                      //zmiana rozmiaru wektora qrs_end
        waves_points.qrs_end = tmp;                                     //zapisanie nowego wektora qrs_end
        /*for (int i=0; i<(int)waves_points.qrs_end.size(); i++){
            std::cout << waves_points.qrs_end(i) << std::endl;
        }*/
    }
    //sprawdzenie, czy liczba QRSend i Tend jest równa
    if(waves_points.t_end.size() != waves_points.qrs_end.size())
    {
        std::cout << "Różna liczba QRSend i Tend" << std::endl;
    }
    else
    {
        if(waves_points.t_end.size() % 2 != 0) //sprawdzenie czy liczba QRSend i Tend jest parzysta
        {
            //usunięcie ostatniego QRSend i Tend, gdy liczba ta jest nieparzysta
            arma::vec tmp(waves_points.qrs_end.size()-1);                   //wektor pomocniczy
            tmp = waves_points.qrs_end.head(waves_points.qrs_end.size()-1); //usunięcie ostatniego QRSend
            waves_points.qrs_end.set_size(tmp.size());                      //zmiana rozmiaru wektora qrs_end
            waves_points.qrs_end = tmp;                                     //zapisanie nowego wektora qrs_end
            arma::vec tmp1(waves_points.t_end.size()-1);                    //wektor pomocniczy
            tmp1 = waves_points.t_end.head(waves_points.t_end.size()-1);    //usunięcie ostatniego Tend
            waves_points.t_end.set_size(tmp1.size());                       //zmiana rozmiaru wektora t_end
            waves_points.t_end = tmp1;                                      //zapisanie nowego wektora t_end
        }
    }
    /*for (int i=0; i<(int)waves_points.qrs_end.size(); i++){
        std::cout << waves_points.qrs_end(i) << std::endl;
    }
    std::cout << std::endl;
    for (int i=0; i<(int)waves_points.t_end.size(); i++){
        std::cout << waves_points.t_end(i) << std::endl;
    }*/

}

void T_Wave_Alt::remove_wrong_t_detection()
{
//Funkcja delete_wrong_T_detection() usuwająca błędne detekcje załamków T.
//Usuwane są załamki, dla których punkty Tend i Tpeak znajdują się poza
//zakresem [mean - 2*std; mean + 2*std].
//Dla zachowania parzystej liczby załamków, załamki o numerach parzystych
//usuwane są wraz z załamkiem następnym, natomiast załamki o numerach
//nieparzystych usuwane są wraz z załamkiem poprzednim.

    //arma::uvec t_end_val = signal_filtered.elem(waves_points.t_end); //przechowuje wartości sygnału dla t_end
    //arma::uvec t_peak_val = signal_filtered.elem(t_peaks);           //przechowuje wartości sygnału dla t_peaks
    arma::vec t_end_val(waves_points.t_end.size());
    arma::vec t_peak_val(t_peaks.size());
    for(int i=0; i<(int)waves_points.t_end.size(); i++)
    {
        t_end_val(i) =signal_filtered(waves_points.t_end(i));
    }
    for(int i=0; i<(int)t_peaks.size(); i++)
    {
        t_peak_val(i) = signal_filtered(t_peaks(i));
    }

    double t_end_mean = mean(t_end_val);      //wyznaczenie średniej wartości Tend
    double t_end_std = stddev(t_end_val);     //wyznaczenie odch. stand. Tend
    double t_peak_mean = mean(t_peak_val);    //wyznaczenie średniej wartości Tpeak
    double t_peak_std = stddev(t_peak_val);   //wyznaczenie odch. stand. Tpeak
    //std::cout << t_end_mean << std::endl << t_end_std << std::endl;
    //std::cout << t_peak_mean << std::endl << t_peak_std << std::endl;

    int N_peak = t_peak_val.size(); //liczba załamków T w sygnale EKG
    std::vector<bool> flag; //bool flag[N_peak]; przechowuje inf. czy dany załamek T pozostanie w sygnale
    for(int i=0; i<N_peak; i++)     //inicjalizacja tablicy
    {
        flag.push_back(true);  //flag[i] = true;
    }

    //usunięcie błędnych detekcji (pętla przechodząca przez kolejne załamki T)
    for(int i=0; i<N_peak; i++)
    {
        //sprawdzenie, czy Tpeak oraz Tend mieści się w zadanym zakresie (mean +- 2*std)
        if(t_end_val(i) > t_end_mean+2*t_end_std || t_end_val(i) < t_end_mean-2*t_end_std ||
                t_peak_val(i) > t_peak_mean+2*t_peak_std || t_peak_val(i) < t_peak_mean-2*t_peak_std)
        {
            if(i%2 == 0) //załamek o numerze parzystym
            {
                //zaznaczenie załamków (i) oraz (i+1) do usunięcia
                flag[i] = false;
                flag[i+1] = false;
            }
            if(i%2 != 0) //załamek o numerze nieparzystym
            {
                //zaznaczenie załamków (i) oraz (i-1) do usunięcia
                flag[i] = false;
                flag[i-1] = false;
                i++;
            }
        }
    }
    //zliczenie poprawnych załamków
    int N_true_peak = 0;
    for(int i=0; i<N_peak; i++)
    {
        if(flag[i]) N_true_peak++;  //gdy flaga jest true
    }
    //std::cout << N_true_peak << std::endl;
    if(N_true_peak != N_peak){      //gdy wykryto błędne detekcje
        arma::vec sample_true_peak(N_true_peak);   //przechowuje numery poprawnie wykrytych załamków
        int j=0;
        for(int i=0; i<N_peak; i++)
        {
            if(flag[i])
            {
                sample_true_peak(j) = i;    //zapisanie numeru poprawnie wykrytego załamka
                j++;
            }
        }
        //tymczasowe wektory dla pkt. charakt. poprawnych załamków
        arma::vec qrs_end_tmp(N_true_peak);
        arma::vec t_end_tmp(N_true_peak);
        arma::vec t_peak_tmp(N_true_peak);
        for(int i=0; i<N_true_peak; i++)
        {
            //przypisanie numerów próbek dla pkt. charakt. poprawnych załamków
            qrs_end_tmp(i) = waves_points.qrs_end(sample_true_peak(i));
            t_end_tmp(i) = waves_points.t_end(sample_true_peak(i));
            t_peak_tmp(i) = t_peaks(sample_true_peak(i));
        }
        //zmiana wymiaru oryginalnych wektorów
        waves_points.qrs_end.set_size(N_true_peak);
        waves_points.t_end.set_size(N_true_peak);
        t_peaks.set_size(N_true_peak);
        //przypisanie numerów próbek dla pkt. charakt. poprawnych załamków do oryginalnych wektorów
        waves_points.qrs_end = qrs_end_tmp;
        waves_points.t_end = t_end_tmp;
        t_peaks = t_peak_tmp;
    }
    /*for (int i=0; i<(int)waves_points.qrs_end.size(); i++){
        std::cout << waves_points.qrs_end(i) << std::endl;
    }
    std::cout << std::endl;
    for (int i=0; i<(int)waves_points.t_end.size(); i++){
        std::cout << waves_points.t_end(i) << std::endl;
    }
    std::cout << std::endl;
    for (int i=0; i<(int)t_peaks.size(); i++){
        std::cout << t_peaks(i) << std::endl;
    }*/
}
void T_Wave_Alt::sample_counter()
{
//Funkcja sample_counter() wyznacza minimalną liczbę próbek pomiędzy QRSend
//i Tpeak oraz między Tpeak i Tend.

    int N_true_peak = t_peaks.size();
    //std::cout << N_true_peak << std::endl;
    arma::vec STp(N_true_peak);
    arma::vec TpTe(N_true_peak);
    for(int i=0; i<N_true_peak; i++)
    {
        //wyznaczenie liczby próbek między QRSends i Tpeaks
        STp(i) = t_peaks(i) - waves_points.qrs_end(i);
        //wyznaczenie liczby próbek między Tpeaks i Tends
        TpTe(i) = waves_points.t_end(i) - t_peaks(i);
    }
    //Wyznaczenie minimalnej liczby próbek pomiędzy QRSend i Tpeak
    STp_min = round( (double)STp.min() / 2.0 );
    //Wyznaczenie minimalnej liczby próbek pomiędzy Tpeak i Tend
    TpTe_min = (int)TpTe.min();
    //std::cout << STp_min << " " << TpTe_min << std::endl;
}

void T_Wave_Alt::moving_average()
{
//Funkcja moving_average() realizująca algorytm ruchomej średniej do
//wyznaczania alternansu załamka T

    sample_counter();
    //liczba próbek załamka zastępczego
    int N_Twave_sample = STp_min+TpTe_min+1;
    //liczba załamków T
    int N_true_peak = t_peaks.size();
    arma::mat tmp_odd_array(N_true_peak, N_Twave_sample);   //macierz załamków nieparzystych
    arma::mat tmp_even_array(N_true_peak, N_Twave_sample);  //macierz załamków parzystych
    arma::mat tmp_odd_t_array(N_true_peak, N_Twave_sample); //macierz chwil czasowych załamków nieparzystych
    arma::mat tmp_even_t_array(N_true_peak, N_Twave_sample);//macierz chwil czasowych załamków parzystych
    for(int i=0; i<round(N_true_peak/2); i++)
    {
        for(int j=0; j<N_Twave_sample; j++)
        {
            //Wyrównanie załamków T do punktów Tpeaks
            //Podział na załamki o numerach parzystych i nieparzystych
            tmp_odd_array(i, j) = signal_filtered(t_peaks(2*i)-STp_min+j);
            tmp_even_array(i, j) = signal_filtered(t_peaks(2*i+1)-STp_min+j);
            //Wybranie chwil czasowych odpowiadających załamkom parzystym i nieparzystym
            tmp_odd_t_array(i, j) = time_vec(t_peaks(2*i)-STp_min+j);
            tmp_even_t_array(i, j) = time_vec(t_peaks(2*i+1)-STp_min+j);
        }
    }
    odd_array = tmp_odd_array;
    even_array = tmp_even_array;
    odd_t_array = tmp_odd_t_array;
    even_t_array = tmp_even_t_array;

    arma::vec tmp_even_T(N_Twave_sample);   //pomocniczy wektor przechowujący próbki pierwszego parzystego załamka T
    arma::vec tmp_odd_T(N_Twave_sample);    //pomocniczy wektor przechowujący próbki pierwszego nieparzystego załamka T
    for(int i=0; i<N_Twave_sample; i++)
    {
        tmp_even_T(i) = even_array(0, i);
        tmp_odd_T(i) = odd_array(0,i);
    }
    even_T = tmp_even_T;
    odd_T = tmp_odd_T;

    //wektory przechowujące różnice między kolejnymi próbkami załamka zastępczego i kolejnego załamkami w sygnale
    arma::vec delta_even(N_Twave_sample);
    arma::vec delta_odd(N_Twave_sample);
    //Realizacja algorytmu ruchomej średniej.
    for(int i=1; i<round(N_true_peak/2); i++){
        for(int j=0; j<N_Twave_sample; j++){
            //Wyznaczenie różnicy między aktualnym załamkiem zastępczym a kolejnym
            //załamkiem T w sygnale (osobno dla nieparzystych i parzystych).
            //W literaturze zasugerowano dzielenie różnicy przez wartość "8", która
            //została dobrana doświadczalnie.
            delta_even(j) = (even_array(i, j) - even_T(j)) / 8.0;
            delta_odd(j) = (odd_array(i, j) - odd_T(j)) / 8.0;
            //Modyfikacja zastępczego załamka o wyznaczoną wartość delta (osobno
            //dla nieparzystych i parzystych).
            even_T(j) = even_T(j) + delta_even(j);
            odd_T(j) = odd_T(j) + delta_odd(j);
        }
    }
    //wektor pomocniczy przechowujący różnice między kolejnymi próbkami
    //parzystego i nieparzystego załamka zastępczego
    arma::vec delta(N_Twave_sample);
    for(int i=0; i<N_Twave_sample; i++){
        //std::cout << even_T(i) << std::endl;
        delta(i) = abs(even_T(i) - odd_T(i));
    }
    //Wyznaczenie wartości alternansu jako maksymalnej różnicy między kolejnymi próbkami
    //parzystego i nieparzystego załamka zastępczego
    alt = max(delta);
    //wyznaczenie wektora czasu do narysowania załamków zastępczych
    time_vec_alt = time_vec.head(N_Twave_sample);
    //std::cout << alt*1000 << std::endl;
}

void T_Wave_Alt::analyze()
{
    filter_t_wave_alt();
    //lub tak: filter_lowpass(15, 30);
    preprocessing_t_wave_alt();
    find_t_peaks();
    remove_wrong_t_detection();
    moving_average();
}

arma::vec T_Wave_Alt::get_t_peaks()
{
    return t_peaks;
}

double T_Wave_Alt::get_alt()
{
    return alt;
}
arma::vec T_Wave_Alt::get_odd_t()
{
    return odd_T;
}
arma::vec T_Wave_Alt::get_even_t()
{
    return even_T;
}
arma::vec T_Wave_Alt::get_time_vec_alt()
{
    return time_vec_alt;
}
arma::mat T_Wave_Alt::get_even_array()
{
    return even_array;
}
arma::mat T_Wave_Alt::get_odd_array()
{
    return odd_array;
}
arma::mat T_Wave_Alt::get_even_t_array()
{
    return even_t_array;
}
arma::mat T_Wave_Alt::get_odd_t_array()
{
    return odd_t_array;
}

T_Wave_Alt_Struct T_Wave_Alt::get_t_wave_alt()
{
    t_wave_alt_struct.odd_T = odd_T;                //zastępczy załamek nieparzysty
    t_wave_alt_struct.even_T = even_T;              //zastępczy załamek parzysty
    t_wave_alt_struct.time_vec_alt = time_vec_alt;  //wektor czasu dla załamków zastępczych
    t_wave_alt_struct.even_array = even_array;      //tablica próbek załamków parzystych
    t_wave_alt_struct.odd_array = odd_array;        //tablica próbek załamków nieparzystych
    t_wave_alt_struct.even_t_array = even_t_array;  //chwile czasowe próbek załamków parzystych
    t_wave_alt_struct.odd_t_array = odd_t_array;    //chwile czasowe próbek załamków nieparzystych
    t_wave_alt_struct.alt = alt;                    //wartość alternansu
    return t_wave_alt_struct;
}

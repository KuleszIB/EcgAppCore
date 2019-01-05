#include "t_wave_alt_module.h"
#define pi 3.14159265358979323846

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
        arma::uvec tmp(waves_points.t_end.size()-1);                //wektor pomocniczy
        tmp = waves_points.t_end.tail(waves_points.t_end.size()-1); //usunięcie pierwszego Tend
        waves_points.t_end.set_size(tmp.size());                    //zmiana rozmiaru wektora t_end
        waves_points.t_end = tmp;                                   //zapisanie nowego wektora t_end
        /*for (int i=0; i<(int)waves_points.t_end.size(); i++){
            std::cout << waves_points.t_end(i) << std::endl;
        }*/
    }
    if(waves_points.qrs_end(waves_points.qrs_end.size()-1) > waves_points.t_end(waves_points.t_end.size()-1)) //gdy sygnał kończy się na QRSend
    {
        std::cout << std::endl;
        arma::uvec tmp(waves_points.qrs_end.size()-1);                  //wektor pomocniczy
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
            arma::uvec tmp(waves_points.qrs_end.size()-1);                  //wektor pomocniczy
            tmp = waves_points.qrs_end.head(waves_points.qrs_end.size()-1); //usunięcie ostatniego QRSend
            waves_points.qrs_end.set_size(tmp.size());                      //zmiana rozmiaru wektora qrs_end
            waves_points.qrs_end = tmp;                                     //zapisanie nowego wektora qrs_end
            arma::uvec tmp1(waves_points.t_end.size()-1);                   //wektor pomocniczy
            tmp1 = waves_points.t_end.head(waves_points.t_end.size()-1);    //usunięcie ostatniego Tend
            waves_points.t_end.set_size(tmp1.size());                       //zmiana rozmiaru wektora t_end
            waves_points.t_end = tmp1;                                      //zapisanie nowego wektora t_end
        }
    }
    for (int i=0; i<(int)waves_points.qrs_end.size(); i++){
        //std::cout << waves_points.qrs_end(i) << std::endl;
    }
    std::cout << std::endl;
    for (int i=0; i<(int)waves_points.t_end.size(); i++){
        //std::cout << waves_points.t_end(i) << std::endl;
    }

}

void T_Wave_Alt::remove_wrong_t_detection()
{
//Funkcja delete_wrong_T_detection() usuwająca błędne detekcje załamków T.
//Usuwane są załamki, dla których punkty Tend i Tpeak znajdują się poza
//zakresem [mean - 2*std; mean + 2*std].
//Dla zachowania parzystej liczby załamków, załamki o numerach parzystych
//usuwane są wraz z załamkiem poprzedzającym, natomiast załamki o numerach
//nieparzystych usuwane są wraz z załamkiem następnym.

    arma::vec t_end_val = signal_filtered.elem(waves_points.t_end);
    arma::vec t_peak_val = signal_filtered.elem(t_peaks);

    double t_end_mean = mean(t_end_val);        //wyznaczenie średniej wartości Tend
    double t_end_std = stddev(t_end_val);       //wyznaczenie odch. stand. Tend
    double t_peak_mean = mean(t_peak_val);    //wyznaczenie średniej wartości Tpeak
    double t_peak_std = stddev(t_peak_val);   //wyznaczenie odch. stand. Tpeak
    //std::cout << t_end_mean << std::endl << t_end_std << std::endl;
    //std::cout << t_peaks_mean << std::endl << t_peaks_std << std::endl;

    int N_peak =t_peak_val.size();  //liczba załamków T w sygnale EKG
    bool flag[N_peak];
    for(int i=0; i<N_peak; i++)
    {
        flag[i] = true;
    }

    //usunięcie błędnych detekcji (pętla przechodząca przez kolejne załamki T)
    for(int i=0; i<N_peak; i++)
    {
        //sprawdzenie, czy Tpeak oraz Tend mieści się w zadanym zakresie (mean +- 2*std)
        if(t_end_val(i) > t_end_mean+2*t_end_std || t_end_val(i) < t_end_mean-2*t_end_std ||
                t_peak_val(i) > t_peak_mean+2*t_peak_std || t_peak_val(i) < t_peak_mean-2*t_peak_std)
        {
            //załamek o numerze parzystym
            if(i%2 == 0)
            {
                flag[i] = false;    //zaznaczenie załamka do usunięcia
                flag[i+1] = false;  //zaznaczenie załamka następnego do usunięcia
                //std::cout << "Parzysty: " << i << "Nieparzysty: " << i+1 << std::endl;
            }
            //załamek o numerze nieparzystym
            if(i%2 != 0)
            {
                flag[i] = false;    //zaznaczenie załamka do usunięcia
                flag[i-1] = false;  //zaznaczenie załamka npoprzedniego do usunięcia
                //std::cout << "Nieparzysty: " << i << "Parzysty: " << i-1 << std::endl;
                i++;
            }
        }
    }
    //zliczenie poprawnych załamków
    int N_true_peak = 0;
    for(int i=0; i<N_peak; i++)
    {
        if(flag[i]) N_true_peak++;
    }
    //std::cout << N_true_peak << std::endl;
    if(N_true_peak != N_peak){
        arma::uvec sample_true_peak(N_true_peak);
        int j=0;
        for(int i=0; i<N_peak; i++)
        {
            if(flag[i])
            {
                sample_true_peak(j) = i;
                j++;
            }
        }
        arma::uvec qrs_end_tmp(N_true_peak);
        arma::uvec t_end_tmp(N_true_peak);
        arma::uvec t_peak_tmp(N_true_peak);
        for(int i=0; i<N_true_peak; i++)
        {
            qrs_end_tmp(i) = waves_points.qrs_end(sample_true_peak(i));
            t_end_tmp(i) = waves_points.t_end(sample_true_peak(i));
            t_peak_tmp(i) = t_peaks(sample_true_peak(i));
        }
        waves_points.qrs_end.set_size(N_true_peak);
        waves_points.t_end.set_size(N_true_peak);
        t_peaks.set_size(N_true_peak);
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

}

void T_Wave_Alt::analyze()
{
    filter_t_wave_alt();
    preprocessing_t_wave_alt();
    find_t_peaks();
    remove_wrong_t_detection();
}

arma::uvec T_Wave_Alt::get_t_peaks()
{
    return t_peaks;
}

double T_Wave_Alt::get_alt()
{
    return alt;
}

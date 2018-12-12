#include "hrv1_module.h"

//Najpierw luknij do headera jakie masz możliwości

Hrv1::Hrv1()                //usunac?
{

}

Hrv1::Hrv1(arma::vec r_peaks)
{
    int size = int(r_peaks.size()) - 1;
    arma::vec r_peaks_vec_temp(size);                                     //temporary vector for RR intervals
    for(int i=0;i<size;i++) {
        r_peaks_vec_temp[i] = int(r_peaks[i+1] - (r_peaks[i]));           //RR intervals
        r_peaks_vec_temp[i] = r_peaks_vec_temp[i]/360;                    //sampling frequency = 360; changing to the time [s]
    }
    r_peaks_vec = r_peaks_vec_temp;                                       //RR interval's vector
    std::cout << r_peaks_vec << std::endl;             //USUNAC!!! DO TESTOW

    calc_cum_time_vec();                                                  //tachogram's timeline

}

void Hrv1::calc_cum_time_vec()
{
    int size = int(r_peaks_vec.size());
    arma::vec cum_time_vec_temp(size);                                    //temporary timeline vector
    cum_time_vec_temp[0] = 0;                                             //first value = 0
    arma::vec sum_cum_time_vec = arma::cumsum(r_peaks_vec);               //cumulating sum of elements
    for(int i=1;i<size;i++){
        cum_time_vec_temp[i] = sum_cum_time_vec[i-1];                     //creating tachogram's timeline
    }
    cum_time_vec = cum_time_vec_temp;                                     //tachogram's timeline vector
    std::cout << cum_time_vec <<std::endl;          //USUNAC!!! DO TESTOW
}

void Hrv1::calc_freq_vec()
{
    int length = int(uniform_r_peaks_vec.size());
    double fs = 1/(uniform_time_vec[1] - uniform_time_vec[0]);              //sampling frequency
    double delta = fs/2/length;
    frequency_vec = arma::regspace<arma::vec>(0,delta,fs/2);                //creating frequency vector
}

void Hrv1::resample()
{
    r_peaks_vec = r_peaks_vec - time_params.rr_mean;                        //removing constant signal component
    std::cout << r_peaks_vec << std::endl;                      //USUNAC!!!! do testow

    int length = int(cum_time_vec.size());
    uniform_time_vec = arma::linspace(0, cum_time_vec(length-1), length);    //generating linearly spaced vector
    std::cout << uniform_time_vec << std::endl;                 //USUNAC!!! do testow
    arma::interp1(cum_time_vec, r_peaks_vec, uniform_time_vec, uniform_r_peaks_vec, "nearest");     //interpolation
    std::cout << uniform_r_peaks_vec << std::endl;              //USUNAC!!!! do testow
}

void Hrv1::calc_time_params()
{
    time_params.rr_mean = arma::mean(r_peaks_vec);                           //mean [s]

    time_params.sdnn = arma::stddev(r_peaks_vec);                            //standard deviation [s]

    double temp_sum = 0;                                                     //root mean square of successive differences [s]
    double difference;
    for(int i=1;i<int(r_peaks_vec.size());i++) {
        difference = double(r_peaks_vec[i]) - double(r_peaks_vec[i-1]);
        temp_sum = temp_sum + std::pow(difference,2);
    }
    time_params.rmssd = std::sqrt(temp_sum/(int(r_peaks_vec.size()-1)));

    time_params.nn50 = 0;                                                     //NN50
    for(int j=0;j<int(r_peaks_vec.size()-1);j++) {
        if((std::abs(double(r_peaks_vec[j+1]) - double(r_peaks_vec[j])))>0.05) {
            time_params.nn50 = time_params.nn50 + 1;
        }
    }

    time_params.pnn50 = (time_params.nn50/(r_peaks_vec.size()-1)) * 100;       //pNN50 [%]
}

void Hrv1::calc_freq_params()
{
    for(int i=0;i<int(frequency_vec.size());i++) {                                   //defining range for every parameter
        if (frequency_vec[i]<=0,003) {
            int j = 0;
            freq_params.freq_ulf[j] = frequency_vec[i];
            j++;
        }
        else if (frequency_vec[i]<0,04) {
            int j = 0;
            freq_params.freq_vlf[j] = frequency_vec[i];
            j++;
        }
        else if (frequency_vec[i]<0,15) {
            int j = 0;
            freq_params.freq_lf[j] = frequency_vec[i];
            j++;
        }
        else if (frequency_vec[i]<0,4) {
            int j = 0;
            freq_params.freq_hf[j] = frequency_vec[i];
            j++;
        }
    }

    freq_params.tp = arma::sum(frequency_vec);                                  //frequency parameters
    freq_params.ulf = arma::sum(freq_params.freq_ulf);
    freq_params.vlf = arma::sum(freq_params.freq_vlf);
    freq_params.lf = arma::sum(freq_params.freq_lf);
    freq_params.hf = arma::sum(freq_params.freq_hf);


}

void Hrv1::calc_periodogram()
{
    int length = int(uniform_r_peaks_vec.size());
    std::complex<double> ii(0,1);                                       //creating complex number
    double pi = 3.141592653589793238;
    arma::vec periodogram_temp(length);                                 //temporary periodogram vector
    for(int i=0;i<length;i++) {
        std::complex<double> temp = 0;
        for(int k=0;k<length;k++) {                                     //creating periodogram
            temp = temp + uniform_r_peaks_vec(k)*std::exp(-2*(pi)*ii*frequency_vec(i)*uniform_time_vec(k));
        }
        double result = std::abs(temp);
        result = std::pow(result,2);
        periodogram_temp[i] = result/length;
    }
    periodogram = periodogram_temp;                                     //periodogram vector
}

void Hrv1::calc_params()
{

}

arma::vec Hrv1::get_periodogram()
{
    calc_periodogram();
    return periodogram;
}

arma::vec Hrv1::get_freq_vec()
{
    resample();
    calc_freq_vec();
    return frequency_vec;
}

Time_Params Hrv1::get_time_params()
{
    calc_time_params();
    return time_params;
}

Frequency_Params Hrv1::get_freq_params()
{
    calc_freq_params();
    return freq_params;
}




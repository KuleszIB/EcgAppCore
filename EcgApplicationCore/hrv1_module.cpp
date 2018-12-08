#include "hrv1_module.h"

//Najpierw luknij do headera jakie masz możliwości

Hrv1::Hrv1()
{

}

Hrv1::Hrv1(arma::vec r_peaks)
{
    r_peaks = {75,367,661,944,1230,1514,1806,2042,2401,2704,2996,3278,3555,3859,4167,4464,4763,5057,5345,5631,5914,6211,6524,6822,7104,7379,7668,7952,8243,8537,8836,9140,9429,9706,9991};
   for(int i=0;i<(r_peaks.size() - 1);i++) {
        r_peaks_vec[i] = r_peaks[i+1] - r_peaks[i];             //RR intervals
        r_peaks_vec[i] = r_peaks_vec[i]/360;                    //sampling frequency = 360; changing to the time [s]
   }
    calc_cum_time_vec();                                        //tachogram's timeline
}

void Hrv1::calc_cum_time_vec()
{
    cum_time_vec = arma::cumsum(r_peaks_vec);                   //creating tachogram's timeline
    cum_time_vec = cum_time_vec/360;                            //changing to the time [s]; NOT SURE IF WORKS
//    for(int i=0;i<cum_time_vec.size();i++) {
//        cum_time_vec[i] = cum_time_vec[i]/360;
//    }
}

void Hrv1::calc_freq_vec()
{
    int length = uniform_r_peaks_vec.size();
    double fs = 1/(uniform_time_vec[1] - uniform_time_vec[0]);
    double delta = fs/2/length;
    frequency_vec = arma::regspace<arma::vec>(0,delta,fs/2);
}

void Hrv1::resample()
{
    r_peaks_vec = r_peaks_vec - time_params.rr_mean;    //removing constant signal component; NOT SURE IF WORKS
    for(int i=0;i<r_peaks_vec.size();i++) {
        r_peaks_vec[i] = r_peaks_vec[i] - time_params.rr_mean;
    }

    int length = cum_time_vec.size();
    uniform_time_vec = arma::linspace(0, cum_time_vec(length-1), length);      //generating linearly spaced vector
    arma::interp1(cum_time_vec, r_peaks_vec, uniform_time_vec, uniform_r_peaks_vec, "nearest");     //resampling, spline
}

void Hrv1::calc_time_params()
{
    time_params.rr_mean = arma::mean(r_peaks_vec);              //mean [s]

    time_params.sdnn = arma::stddev(r_peaks_vec);               //standard deviation [s]

    int temp_sum = 0;                                           //Root mean square of successive differences [s]
    for(int i=1;i<r_peaks_vec.size();i++) {
        temp_sum = temp_sum + pow((r_peaks_vec[i] - r_peaks_vec[i-1]),2);   //squaring
    }
    time_params.rmssd= sqrt(temp_sum/(r_peaks_vec.size()-1));

    time_params.nn50 = 0;                                       //NN50
    for(int j=0;j<(r_peaks_vec.size()-1);j++) {
        if(abs(r_peaks_vec[j+1] - r_peaks_vec[j])>0,05) {
            time_params.nn50 = time_params.nn50+1;
        }
    }

    time_params.pnn50 = (time_params.nn50/(r_peaks_vec.size()-1)) * 100;        //pNN50 [%]

}

void Hrv1::calc_freq_params()
{
    for(int i=0;i<frequency_vec.size();i++) {
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

    freq_params.tp = arma::sum(frequency_vec);
    freq_params.ulf = arma::sum(freq_params.freq_ulf);
    freq_params.vlf = arma::sum(freq_params.freq_vlf);
    freq_params.lf = arma::sum(freq_params.freq_lf);
    freq_params.hf = arma::sum(freq_params.freq_hf);


}

void Hrv1::calc_periodogram()
{
    int length = uniform_r_peaks_vec.size();    //źleeeeeeeeeeeeeee
    std::complex<double> ii(0,1);
    double pi = 3.141592653589793238;
    for(int i=0;i<length;i++) {
        std::complex<double> temp = 0;
        for(int k=0;k<length;k++) {
            temp = temp + uniform_r_peaks_vec(k)*exp(-2*(pi)*ii*frequency_vec(i)*uniform_time_vec(k));
        }
        periodogram[i] = (1/length) * (std::pow((std::abs(temp)),2));
    }
}

void Hrv1::calc_params()
{

}

arma::vec Hrv1::get_periodogram()
{
    return periodogram;
}

arma::vec Hrv1::get_freq_vec()
{
    return frequency_vec;
}

Time_Params Hrv1::get_time_params()
{
    return time_params;
}

Frequency_Params Hrv1::get_freq_params()
{
    return freq_params;
}

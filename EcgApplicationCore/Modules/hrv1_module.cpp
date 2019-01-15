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
//    std::cout << "R peaks vec" << std::endl << r_peaks_vec << std::endl;             //USUNAC!!! DO TESTOW

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
//    std::cout << "Timeline vector" << std::endl << cum_time_vec <<std::endl;          //USUNAC!!! DO TESTOW
}

void Hrv1::calc_freq_vec()
{
    int length = int(uniform_r_peaks_vec.size());
    double fs = 1/(uniform_time_vec[1] - uniform_time_vec[0]);              //sampling frequency
    double delta = (fs/2)/length;                                           //space between next samples
    frequency_vec = arma::regspace<arma::vec>(0,delta,fs/2);                //creating frequency vector
}

void Hrv1::resample()
{  
    int length = int(cum_time_vec.size());
    uniform_time_vec = arma::linspace(0, cum_time_vec(length-1), length);    //generating linearly spaced vector
//    std::cout << "Uniform timeline vec" << std::endl << uniform_time_vec << std::endl;                 //USUNAC!!! do testow
    arma::interp1(cum_time_vec, r_peaks_vec, uniform_time_vec, uniform_r_peaks_vec, "nearest");     //interpolation
//    std::cout << "Uniform r peaks" << std::endl<< uniform_r_peaks_vec << std::endl;              //USUNAC!!!! do testow
    uniform_r_peaks_vec = uniform_r_peaks_vec - time_params.rr_mean;                        //removing constant signal component
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
    int ulf_end=0, vlf_end=0, lf_end=0, hf_end=0, vlf_start=0;

    for(int i=0;i<int(frequency_vec.size());i++) {                              //checking the range of parameters (how many samples
        if (frequency_vec[i]<=0.003 && ((cum_time_vec[cum_time_vec.size() - 1] * 360) > 120000)) {                                          //of frequency vec belong to each parameter)
                ulf_end++;
        }
        else if(frequency_vec[i]<=0.003) {
                vlf_start++;
        }
        else if (frequency_vec[i]<0.04) {
            vlf_end++;
        }
        else if (frequency_vec[i]<0.15) {
            lf_end++;
        }
        else if (frequency_vec[i]<0.4) {
            hf_end++;
        }

    }

    int vlf_range;
    if(ulf_end == 0) {
        vlf_range=vlf_end+vlf_start;
    }
    else {
        vlf_range=vlf_end+ulf_end;
    }
    int lf_range =vlf_range+lf_end;
    int hf_range=lf_range+hf_end;

    std::cout << "Amount of:ulf vlf lf hf " << ulf_end << " " << vlf_range << " " << lf_range << " " << hf_range << " " <<std::endl;
    //usunac
    arma::vec temp_freq_ulf(ulf_end);                                                //creating temporary vectors for parameters
    arma::vec temp_freq_vlf(vlf_end);
    arma::vec temp_freq_lf(lf_end);
    arma::vec temp_freq_hf(hf_end);

    arma::vec temp_ulf(ulf_end);
    arma::vec temp_vlf(vlf_end);
    arma::vec temp_lf(lf_end);
    arma::vec temp_hf(hf_end);

    int a=0, b=0, c=0, d=0;

    for(int i=0;i<int(frequency_vec.size());i++) {                                   //creating a vector for every parameter
        if (i<ulf_end) {                                                             //(both frequency & power)
            temp_freq_ulf[a] = frequency_vec[i];
            temp_ulf[a] = periodogram[i];
            a++;
        }
        else if (ulf_end<=i && frequency_vec(i)>0.003 && i<vlf_range) {
            temp_freq_vlf[b] = frequency_vec[i];
            temp_vlf[b] = periodogram[i];
            b++;
        }
        else if (vlf_range<=i && frequency_vec(i)>0.003 && i<lf_range) {
            temp_freq_lf[c] = frequency_vec[i];
            temp_lf[c] = periodogram[i];
            c++;
        }
        else if (lf_range<=i && frequency_vec(i)>0.003 && i<hf_range) {
            temp_freq_hf[d] = frequency_vec[i];
            temp_hf[d] = periodogram[i];
            d++;
        }
    }

    freq_params.freq_ulf = temp_freq_ulf;                                     //parameters' vectors
    freq_params.freq_vlf = temp_freq_vlf;
    freq_params.freq_lf = temp_freq_lf;
    freq_params.freq_hf = temp_freq_hf;

    freq_params.tp = arma::sum(periodogram);                                  //frequency parameters
    freq_params.ulf = arma::sum(temp_ulf);
    freq_params.vlf = arma::sum(temp_vlf);
    freq_params.lf = arma::sum(temp_lf);
    freq_params.hf = arma::sum(temp_hf);


}

void Hrv1::calc_periodogram()
{
    int length = int(uniform_r_peaks_vec.size());
    int length_perio = int(frequency_vec.size());
//    std::cout << "Size of 1st perio " << length_perio << std::endl;
    std::complex<double> ii(0,1);                                             //creating complex number
    double pi = 3.141592653589793238;                                         //pi number
    arma::vec periodogram_temp(length_perio);                                 //temporary periodogram vector
    for(int i=0;i<length_perio;i++) {
        std::complex<double> temp = 0;
        for(int k=0;k<length;k++) {                                           //creating periodogram
            temp = temp + (uniform_r_peaks_vec(k)*(std::exp(-2*(pi)*ii*frequency_vec(i)*uniform_time_vec(k))));
        }
//        std:: cout << "temp " << temp << std::endl;
        double result = std::abs(temp);
        result = std::pow(result,2);
        periodogram_temp[i] = result/length;
    }
    periodogram = periodogram_temp;                                          //periodogram vector
//    std::cout << "Size of perio " << periodogram.size() << std::endl;
}


void Hrv1::calc_params()
{
    calc_time_params();
    resample();
    calc_freq_vec();
    calc_periodogram();
    calc_freq_params();

}

arma::vec Hrv1::get_periodogram()
{
    return periodogram;
}

arma::vec Hrv1::get_freq_vec()
{
//    frequency_vec = arma::log(frequency_vec);
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




#include "hrv2_module.h"

Hrv2::Hrv2()
{
    //intervals=[]; lub wyrzucenie błędu "Nie podano indeksów R"
}

Hrv2::Hrv2(arma::vec r_peaks)
{
    double fs = 360;
        r_peaks = {75,367,661,944,1230,1514,1806,2042,2401,2704,2996,3278,3555,3859,4167,4464,4763,5057,5345,5631,5914,6211,6524,6822,7104,7379,7668,7952,8243,8537,8836,9140,9429,9706,9991};
        int size = int(r_peaks.size()) - 1;
        arma::vec r_peaks_vec_temp(size);                                     //temporary vector for RR intervals
        for(int i=0; i<size; i++) {
            r_peaks_vec_temp[i] = int(r_peaks[i+1] - (r_peaks[i]));           //RR intervals
            r_peaks_vec_temp[i] = r_peaks_vec_temp[i]/fs;                    //changing to the time [s]
        }
        intervals_original = r_peaks_vec_temp;

        remove_outliers();
}


void Hrv2::remove_outliers()
{
    //PART1
    //  Remove outliers under the threshold
    double threshold = 0.79;
    int size = 0;

    //  How many numbers are under above the threshold
    for (int i = 0; i < intervals_original.size(); i++){
        if(intervals_original[i] > threshold){
            size++;
        }
    }

    //  Leave only those above threshold, remove the rest
    int a = 0;
    arma::vec tmp_vec(size);
    for (int i = 0; i < intervals_original.size(); i++){
        if(intervals_original[i] > threshold){
            tmp_vec[a]=intervals_original[i];
            a++;
        }
    }


    //PART2
    //  Count vector of differences between intervals and average value of interval
    double sum = 0;
    double average_distance = 0;
    arma::vec differences(size);

    for (int i=0; i < tmp_vec.size(); i++){
        sum = sum + tmp_vec[i];
    }
    average_distance = sum/tmp_vec.size();
//    std::cout << "Average: " << std::endl << average_distance << std::endl;

    for(int i=0; i < tmp_vec.size(); i++){
        differences[i] = std::abs(tmp_vec[i] - average_distance);
    }

    double thres2 = 0.03;
    int vec_size = 0;
    for(int i = 0; i < differences.size(); i++){
        if (differences[i] < thres2){
            vec_size++;
        }
    }

    //  Last version of vector with normal values
    intervals = arma::zeros<arma::vec>(vec_size);

    int j = 0;
    for (int i = 0; i < differences.size(); i++){
        if (differences[i] < thres2){
            intervals[j] = tmp_vec[i];
            j++;
        }
    }

    calc_histogram();
}

void Hrv2::calc_histogram()
{
    double fs = 360;
    double minimum = intervals.min();
    double maximum = intervals.max();
    double bin_width = 1/fs;
    double nbins = ((maximum-minimum)*fs);       //liczba słupków
    int size_edges = int(nbins)+1;

    arma::vec edges(size_edges);
    edges = arma::regspace<arma::vec>(minimum, bin_width, maximum+bin_width);    // granice słupkow

    arma::vec sorted_intervals = arma::sort(intervals);       //posortowane inetrwaly RR (min --> max)
    arma::ivec values(size_edges);  //wartosci jako 'inty' - bo zliczenia zawsze calkowite

    //  Zliczanie ilości wystąpień w każdym przedziale
    int a = 0;
    for(int i = 0; i < edges.size()-1; i++){
        int count = 0;          //zerowanie countera w kazdej petli - ilosc zliczen w przedziale od 0
        bool stop = 0;          // wlaczenie petli while w kazdej iteracji petli for

        while(stop == 0 && a < sorted_intervals.size()){
            if(sorted_intervals[a] <= edges[i+1]){
                count++;
                a++;
            } else {
                stop = 1;   //zatrzymanie while jesli dotrzemy do liczby wiekszej niz gorny limit przedzialu
            }
        }
    values[i] = count;
    }

    int tmp_max_value = values.max();

    std::cout << values << std::endl;
    std::cout << tmp_max_value << std::endl;

    histogram.max_value = tmp_max_value;       //dla mnie! maks liczba zliczen w hist
    histogram.bins = edges;     //wartosci przedzialow
    histogram.values = values;  //ilosc zliczen w kazdym koszu

    calc_tinn();
    calc_triangular_index();
}

void Hrv2::calc_tinn()
{
    double minimum = intervals.min();
    double maximum = intervals.max();
    double tinn = (maximum-minimum)*1000;   //wartosc w [ms], bez 1000 w [s]
//    std::cout << tinn << std::endl;
}

void Hrv2::calc_triangular_index()
{
    double triangular_index = intervals.size() * histogram.max_value;
//    std::cout << triangular_index << std::endl;
}

void Hrv2::calc_poincare()
{

}

void Hrv2::calc_SD1()
{

}

void Hrv2::calc_SD2()
{

}

histogram_hrv2 Hrv2::get_hist()
{
    return histogram;
}

double Hrv2::get_tinn()
{
    return tinn;
}

double Hrv2::get_triang_index()
{
    return triangular_index;
}

poincare_graph Hrv2::get_poincare()
{
    return poincare;
}

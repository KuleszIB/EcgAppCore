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
        calc_histogram();
        calc_poincare();

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

    for(int i=0; i < tmp_vec.size(); i++){
        differences[i] = std::abs(tmp_vec[i] - average_distance);
    }

    //  Threshold will be assessed later - could be not so perfect ;)
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

    int tmp_max_value = int(values.max());

    histogram.max_value = tmp_max_value;       //dla mnie - maks liczba zliczen w hist; najwyzszy slupek
    histogram.bins = edges;     //wartosci przedzialow
    histogram.values = values;  //ilosc zliczen w kazdym koszu

    calc_tinn();
    calc_triangular_index();
}


void Hrv2::calc_tinn()
{
    double minimum = intervals.min();
    double maximum = intervals.max();
    tinn = (maximum-minimum)*1000;   //wartosc w [ms], bez 1000 w [s]
}


void Hrv2::calc_triangular_index()
{
    triangular_index = int(intervals.size()) * histogram.max_value;
}


void Hrv2::calc_poincare()
{
    //  Count vectors Ox and Oy for graph
    int size = int(intervals.size());
    arma::vec poincare_ox(size-1);
    arma::vec poincare_oy(size-1);

    poincare_ox[0] = intervals[0];
    for (int i = 1; i < size; i++){
        if(i != size-1){
            poincare_ox[i] = intervals[i];
        }
        poincare_oy[i-1] = intervals [i];
    }

    poincare.intervals_ox = poincare_ox;
    poincare.intervals_oy = poincare_oy;


    //  Count straight line XY --> Y = X
    double straight_min = poincare_ox.min();
    double straight_max = poincare_ox.max();
    int line_length = 40;
    arma::vec straight_line(line_length);
    straight_line = arma::linspace<arma::vec>(straight_min, straight_max, line_length);

    poincare.straight_xy = straight_line;
    calc_SD1();
    calc_SD2();
    calc_centroid();
    calc_centroid2();
    calc_poincare_axises();
}


void Hrv2::calc_SD1()
{
    int size = int(poincare.intervals_ox.size());
    arma::vec tmp_cumulative_vec(size);

    for (int i = 0; i < size; i++){
        tmp_cumulative_vec[i] = poincare.intervals_ox[i] - poincare.intervals_oy[i];
    }
    double sd1 = arma::stddev(tmp_cumulative_vec)/sqrt(2);
    poincare.sd1 = sd1;
}


void Hrv2::calc_SD2()
{
    int size = int(poincare.intervals_oy.size());
    arma::vec tmp_cumulative_vec(size);

    for (int i = 0; i < size; i++){
        tmp_cumulative_vec[i] = poincare.intervals_ox[i] + poincare.intervals_oy[i];
    }
    double sd2 = arma::stddev(tmp_cumulative_vec)/sqrt(2);
    poincare.sd2 = sd2;
}


void Hrv2::calc_centroid()
{
    //  Centroid as an average of points
    double tmp_sum = arma::sum(poincare.intervals_ox);
    double size = double(poincare.intervals_oy.size());
    double x_centre = tmp_sum/size;

//gdyby nie dzialalo to mozna y osobno wyliczyc, ale przy duzych wektorach powinno byc git
//    double tmp_sum2 = arma::sum(poincare.intervals_oy);
//    double y_centre = tmp_sum2/size;

    poincare.centroid = x_centre;
}

void Hrv2::calc_centroid2()
{
    //  Centroid as an average of points
    double tmp_sum = arma::sum(poincare.intervals_oy);
    double size = double(poincare.intervals_ox.size());
    double y_centre = tmp_sum/size;

//gdyby nie dzialalo to mozna y osobno wyliczyc, ale przy duzych wektorach powinno byc git
//    double tmp_sum2 = arma::sum(poincare.intervals_oy);
//    double y_centre = tmp_sum2/size;

    poincare.centroid2 = y_centre;
}

void Hrv2::calc_poincare_axises()
{
    double pi = 3.14159265359;
    double sd1 = poincare.sd1;
    double sd2 = poincare.sd2;
    double centre = poincare.centroid;
    double angle = pi/4;
    double scope_sd1 = pi/2;    //definicja położenia (nachylenia) prostej
    double scope_sd2 = pi;
    int line_length = 20;

    //Axis for SD2 --> SD2_y = SD2_x
    double SD2_endX = centre + sd2*cos(scope_sd2)*cos(angle) - sd1*sin(scope_sd2)*sin(angle);
    arma::vec sd2_x_axis(line_length);
    sd2_x_axis = arma::linspace<arma::vec>(SD2_endX, centre, line_length);

    //Axis for SD1 --> perpendicular line to line SD2
    double SD1_endX = centre + sd2*cos(scope_sd1)*cos(angle) - sd1*sin(scope_sd1)*sin(angle);
    double SD1_endY = centre + sd2*cos(scope_sd1)*sin(angle) + sd1*sin(scope_sd1)*cos(angle);

    arma::vec sd1_x(line_length);
    sd1_x = arma::linspace<arma::vec>(SD1_endX, centre, line_length);

    arma::vec sd1_y(line_length);
    sd1_y = arma::linspace<arma::vec>(SD1_endY, centre, line_length);

    poincare.sd1_axis_ox = sd1_x;
    poincare.sd1_axis_oy = sd1_y;
    poincare.sd2_axis = sd2_x_axis;     //x i y są takie same, bo prosta: x=y
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

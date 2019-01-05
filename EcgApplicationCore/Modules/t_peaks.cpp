#include "t_peaks.h"

T_Peaks::T_Peaks()
{

}

void T_Peaks::find_t_peaks()
{
//Funkcja find_t_peaks() pozwala na wyszukanie wierzchołków kolejnych załamków T w sygnale EKG
    arma::uvec tmp((int)waves_points.t_end.size());
    for(int i=0; i<(int)waves_points.t_end.size(); i++){
        //wyszukanie Tpeak jako max w zakresie między QRSend a Tend
        tmp(i) = waves_points.qrs_end(i) + signal_filtered.subvec(waves_points.qrs_end(i), waves_points.t_end(i)).index_max();
    }
    t_peaks = tmp;
    /*for (int i=0; i<(int)t_peaks.size(); i++){
        std::cout << t_peaks(i) << std::endl;
    }*/
}

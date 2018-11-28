#include "r_peaks0.h"

void R_Peaks::pan_tompkins()
{

}
void R_Peaks::filter_bandpass()
{

}
void R_Peaks::filter_lowpass()
{

}
void R_Peaks::filter_highpass()
{

}
void R_Peaks::differentiate()
{

}
void R_Peaks::square()
{

}
void R_Peaks::integrate()
{

}
void R_Peaks::hilbert_transform()
{

}

void R_Peaks::find_r_peaks(R_Detection_Method method)
{
    switch(method)
    {
    case PAN_TOMPKINS:
        pan_tompkins();
        break;

    case HILBERT_TRANSFORM:
        hilbert_transform();
        break;

    default:
        pan_tompkins();
        break;
    }
}

arma::vec R_Peaks::get_r_peaks()
{
   return r_peaks_vec;
}

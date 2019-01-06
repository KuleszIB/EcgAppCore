#ifndef T_PEAKS_H
#define T_PEAKS_H

#include "waves_module.h"

class T_Peaks : public Waves
{
protected:
    arma::uvec t_peaks;
    void find_t_peaks();
    T_Peaks();

};

#endif // T_PEAKS_H

#ifndef HRV_DFA_H
#define HRV_DFA_H
#include "r_peaks0.h"


class HrvDfa : public R_Peaks
{
public:
    HrvDfa();
    HrvDfa(arma::vec r_peaks);

};

#endif // HRV_DFA_H

#ifndef STSEGMENT_MODULE_H
#define STSEGMENT_MODULE_H

#include "waves_module.h"

struct St_Points
{
    arma::uvec t_peak;
    arma::uvec t_on;
    arma::uvec t_end;
    arma::uvec q_on;
    arma::uvec q_end;
    arma::vec sig;
    arma::ivec offset;
    arma::uvec slope;
    arma::mat diagnose;

};

class St_Segment : public Waves
{
private:
    void slopes();
    void offsets();
    void find_t_ons();
    void find_t_peaks();
    void classify();
protected:
St_Points St_Points;

public:
    St_Segment();
    St_Segment(arma::vec signal, double fs, Waves_Points waves);
    void analyze();
};

#endif // STSEGMENT_MODULE_H

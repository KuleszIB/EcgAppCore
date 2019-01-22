#ifndef ST_SEGMENT_MODULE_H
#define ST_SEGMENT_MODULE_H


#include "waves_module.h"

struct St_Points
{
public:
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
struct St_Gui_Values{
   public:
    double offset_Threshold_Min;
    double offset_Threshold_Max;
    double type_Detection_Threshold;
    double segment_Linearity_Min;
    double segment_Linearity_Max;
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


public:
    St_Points St_Points;
    St_Segment();
    St_Segment(arma::vec signal,Waves_Points waves);
    void analyze();
    void set_St_Params(double offsetmin, double offsetmax, double detectionthreshold, double linearitymin, double linearitymax);
    St_Gui_Values St_Gui_Values;
};


#endif // ST_SEGMENT_MODULE_H

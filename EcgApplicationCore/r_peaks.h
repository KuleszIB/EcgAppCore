#ifndef R_PEAKS_H
#define R_PEAKS_H

#include "armadillo"
#include "ecg_baseline.h"

enum R_Detection_Method
{
    // tutaj Kasia/ Fabian prosze o uzupelnienie sobie tego dla ulatwienia.
    PAN_TOMPKINS = 0,
    HILBERT_TRANSFORM = 1 // jeśli będziesz robić hilberta, jeśli nie, to enum jest niepotrzebny
};

class R_Peaks : public Ecg_Baseline
{
private:
    void pan_tompkins();
    void filter_lowpass(); // tutaj w argumentach pododawaj to co potrzebujesz
    void filter_highpass();
    void filter_bandpass();
    void differentiate();
    void square();
    void integrate();
    void hilbert_transform(); // czy trzeba jakieś funkcje pomocnicze do tego?

protected:
    arma::vec r_peaks_vec; // output

public:
    R_Peaks();
    R_Peaks(arma::vec signal);
    void find_r_peaks(R_Detection_Method method);
    arma::vec get_r_peaks();

    // moim zdaniem tych dwóch poniżej nie trzeba
    double sampling_frequency_r_peaks;  // tutaj to samo co nizej czy to ma byc to samo co w ecg baseline czy nie.
    arma::vec time_vec_r_peaks; // tutaj jest mozliwosc z korzystania z ecg_baseline time vector ale czy to Ci potrzebne? ( tak czy siak jest dziedziczone)
};

#endif // R_PEAKS_H

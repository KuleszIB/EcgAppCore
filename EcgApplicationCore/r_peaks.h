#ifndef R_PEAKS_H
#define R_PEAKS_H
#include "vector"
#include "ecg_baseline.h"

enum R_detection_method
{
    // tutaj Kasia/ Fabian prosze o uzupelnienie sobie tego dla ulatwienia.
};
class r_peaks : public Ecg_Baseline
{
private:
    std::vector<double> get_r_peaks();
    void pan_tompkins();
    void filter_bandpass();// tutaj w argumentach pododawaj to co potrzebujesz
    void filter_lowpass();
    void filter_highpass();
    void differentiate();
    void square();
    void integrate();
    void hilbert_transform();

public:
    r_peaks();
    double sampling_frequency_r_peaks;  // tutaj to samo co nizej czy to ma byc to samo co w ecg baseline czy nie.
    std::vector<double> time_vec_r_peaks; // tutaj jest mozliwosc z korzystania z ecg_baseline time vector ale czy to Ci potrzebne? ( tak czy siak jest dziedziczone)
    std::vector<double> r_peaks_vector;
};

#endif // R_PEAKS_H

//Qt libraries
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QApplication>

//External libraries
//#include "armadillo"
//#include "sigpack.h"
//#include "wfdb.h"
//#include "Dsp.h"
//#include "SGSmooth.hpp"
//#include "interpolation.h"

//GUI
#include "View/mainview.h"

//Our modules
#include "ecg_baseline_module.h"
#include "r_peaks_module.h"
#include "waves_module.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    arma::vec A(256, arma::fill::randu);
    arma::vec B(16, arma::fill::randu);
    arma::vec C = conv(A, B);

    // Rpeaks test
    R_Peaks *obj = new R_Peaks();
    arma::vec R_peaks_numbers = obj->get_r_peaks();
    std::cout << "R peaks:" << std::endl << R_peaks_numbers << std::endl;

    // Waves test
    Waves *obj2 = new Waves();
    Waves_Points Waves_numbers = obj2->get_waves();
    std::cout << "QRS onsets:" << std::endl << Waves_numbers.qrs_onset << std::endl;
    std::cout << "QRS ends:" << std::endl << Waves_numbers.qrs_end << std::endl;
    std::cout << "P onsets:" << std::endl << Waves_numbers.p_onset << std::endl;
    std::cout << "P ends:" << std::endl << Waves_numbers.p_end << std::endl;
    std::cout << "T ends:" << std::endl << Waves_numbers.t_end << std::endl;

    MainView w;
    w.show();
    return a.exec();
}


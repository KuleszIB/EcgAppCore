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
#include "ecg_baseline.h"
#include "r_peaks0.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    arma::vec A(256, arma::fill::randu);
    arma::vec B(16, arma::fill::randu);
    arma::vec C = conv(A, B);
    R_Peaks *obj = new R_Peaks();
    arma::vec R_peaks_numbers = obj->get_r_peaks();
    std::cout << R_peaks_numbers << std::endl;

    MainView w;
    w.show();
    return a.exec();
}


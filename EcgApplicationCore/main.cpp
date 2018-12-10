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
//#include "ecg_baseline_module.cpp"
#include "r_peaks0.h"
#include "examination.h"


using namespace arma;

arma::vec readtxt()
{
    arma::vec data;
    return data;
}


int main(int argc, char *argv[])
{
    /*arma::vec output = testuje_baseline(argc,argv);
    QApplication a(argc, argv);
    arma::vec A(256, arma::fill::randu);
    arma::vec B(16, arma::fill::randu);
    arma::vec C = conv(A, B);
    R_Peaks *obj = new R_Peaks();
    MainView w;
    w.show();

    return a.exec();*/
    examination proba;
    proba.get_data(argc, argv);
    arma::Col<float> input = proba.channel_one;
    Filter_Type filter_type = BUTTERWORTH;
    Filter_Params filter_params;
    filter_params.set_filter_type(filter_type);
    int fs = 360;
    //arma::vec input = read_from_file();
    //arma::vec a = conv_col_vec(input);
    Ecg_Baseline ecg_baseline_filter(input, fs);
    ecg_baseline_filter.filter_baseline(filter_params);
    arma::vec output = ecg_baseline_filter.get_signal_filtered();
    //write_to_file(output);
    qInfo() << "dziala" ;

    return 0;
}


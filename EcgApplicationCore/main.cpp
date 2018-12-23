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
#include "examination.h"


using namespace arma;

arma::vec readtxt()
{
    arma::vec data;
    return data;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;
    w.show();
    examination proba;
    proba.get_data(argc, argv);
    arma::vec input = proba.channel_one;
    Filter_Type filter_type = CHEBYSHEV;
    Filter_Params filter_params;
    filter_params.set_filter_type(filter_type);
    qInfo() << filter_params.get_filter_type();
    int fs = 360;
    //arma::vec input = read_from_file();
    Ecg_Baseline ecg_baseline_filter(input, fs);
    qInfo() << "dziala" ;
    ecg_baseline_filter.filter_baseline(filter_params);
    arma::vec output = ecg_baseline_filter.get_signal_filtered();
    /*qInfo() << "output";
    for (int i=1; i<output.size(); i++)
    {
      qInfo() << output[i];
    }*/


    return a.exec();
}


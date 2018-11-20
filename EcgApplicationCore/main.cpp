#include "themewidget.h"
#include "ecg_baseline.h"
#include "r_peaks.h"

#include "armadillo"
#include "sigpack.h"
#include "wfdb.h"
#include "Dsp.h"
#include "SGSmooth.hpp"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

using namespace arma;
using namespace sp;

int main(int argc, char *argv[])
{
    //To tylko jest do sprawdzenia, czy dobrze się obiekty tworzą i nie ma błędu
    Ecg_Baseline ecg_baseline;
    FIR_filt<double,double,double> filt;
    vec time_vec = timevec(100,360);

    QApplication a(argc, argv);
    QMainWindow window;
    ThemeWidget *widget = new ThemeWidget();
    window.setCentralWidget(widget);
    window.resize(900, 600);
    window.show();
    return a.exec();
}


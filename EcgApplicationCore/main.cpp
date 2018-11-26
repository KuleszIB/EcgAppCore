#include "View/mainview.h"
#include "ecg_baseline.h"
#include "r_peaks.h"

#include "armadillo"
#include "sigpack.h"
#include "wfdb.h"
#include "Dsp.h"
#include "SGSmooth.hpp"
#include "interpolation.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

using namespace arma;
using namespace sp;
#include <QApplication>


int main(int argc, char *argv[])
{
    //To tylko jest do sprawdzenia, czy dobrze się obiekty tworzą i nie ma błędu
    Ecg_Baseline ecg_baseline;
    FIR_filt<double,double,double> filt;
    vec time_vec = timevec(100,360);

    QApplication a(argc, argv);
    MainView w;
    //module1::Ecg_Baseline *baseline = new module1::Ecg_Baseline(); // tutaj cos z deklaracja namespace mozliwe ze usuniemy to module1 ale to do sprawdzenia
    //w.setCentralWidget(widget);
    //w.resize(900, 600);
    w.show();
    return a.exec();
}


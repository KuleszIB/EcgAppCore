//Qt libraries
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QApplication>

//GUI
#include "View/mainview.h"

//Our modules
#include "Modules/examination.h"
#include "Modules/ecg_baseline_module.h"
#include "Modules/r_peaks_module.h"
#include "Modules/waves_module.h"
#include "Modules/hrv1_module.h"
#include "Modules/hrv2_module.h"


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);

    //Test HRV2
    arma::vec r_peaks = {75,367,661,944,1230,1514,1806,2042,2401,2704,2996,3278,3555,3859,4167,4464,4763,5057,5345,5631,5914,6211,6524,6822,7104,7379,7668,7952,8243,8537,8836,9140,9429,9706,9991};
    Hrv2 *obj = new Hrv2(r_peaks);


    /*MainView w;
    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.show();

    return a.exec();*/
}


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
#include "Modules/stsegment_module.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainView w(&a);
//    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    St_Segment Test;
    Test.analyze();
//    return a.exec();
}


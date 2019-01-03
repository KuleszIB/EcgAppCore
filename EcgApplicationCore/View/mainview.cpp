#include "mainview.h"
#include "ui_mainview.h"
#include "View/heart_class_gui.h"
#include "View/t_alt_class_gui.h"
#include "View/hrv1_gui.h"
#include "View/hrv2_gui.h"
#include "View/st_segment_gui.h"
#include "View/hrv_dfa_gui.h"
#include "View/ecgbaseline_gui.h"
#include "View/r_peaks_gui.h"
#include "Modules/r_peaks_module.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    auto heart_class_gui = new Heart_class_gui(this);
    ui ->loHeartClass->addWidget(heart_class_gui);
    auto t_alt_class_gui = new T_alt_class_gui(this);
    ui ->loTAltClass->addWidget(t_alt_class_gui);
    auto hrv_2_gui = new HRV2_gui(this);
    ui ->lo_HRV2->addWidget(hrv_2_gui);
    auto hrv_1_gui = new HRV1_gui(this);
    ui ->lo_HRV1->addWidget(hrv_1_gui);
    auto stSegment_gui = new St_segment_gui(this);
    ui ->loSTSegment->addWidget(stSegment_gui);
    auto hrv_dfa_gui = new HRV_dfa_gui(this);
    ui ->loHRVdfa->addWidget(hrv_dfa_gui);
    auto ecgBaseline_gui = new ECGbaseline_gui(this);
    ui ->loECGBaseline->addWidget(ecgBaseline_gui);
    auto rPeaks_gui = new R_peaks_gui(this);
    ui ->loRpeaks->addWidget(rPeaks_gui);
    QObject::connect(this,SIGNAL(signal_loaded(examination)),ecgBaseline_gui,SLOT(load_signal(examination)));
  //  loadSettings();

}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_actionExit_triggered()
{
    QApplication::quit();
}
//Jeżeli chce się ustawić rozmiar okna taki jaki się chce!

//{void MainView::saveSettings()
//{
//    QSettings settings(QDir::currentPath() + "/ecg.ini", QSettings::IniFormat);

//    settings.beginGroup("MainView");

//    // Save position and size of window
//    settings.setValue("size", size());
//    settings.setValue("pos", pos());
//  // settings.setValue("MainView/fullScreen", main->isFullScreen());

//    settings.endGroup();
//}

//void MainView::loadSettings()
//{
//    // Coordinates of screen center for default window positioning
//    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
//    QPoint center = desktopRect.center();
//    center.setX(center.x() - width() * 0.5);
//    center.setY(center.y() - height() * 0.5);

//    QSettings settings(QDir::currentPath() + "/ecg.ini", QSettings::IniFormat);

//    settings.beginGroup("MainWindow");

//    // Set position and size of window
//    resize(settings.value("size", QSize(1081, 693)).toSize());
//    move(settings.value("pos", center).toPoint());

//    settings.endGroup();
//}



 void MainView::on_actionOpen_triggered()
 {
     examination file;
     file.get_data();
     qInfo() << "Wczytywanie zakończone!";
     qInfo() <<  "MainView - wczytano: " << file.channel_one[1];
     emit signal_loaded(file);
 }

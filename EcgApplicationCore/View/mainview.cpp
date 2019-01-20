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
#include "Modules/ecg_io.h"
#include <QString>

MainView::MainView(QApplication *app, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    auto ecgBaseline_gui = new ECGbaseline_gui(this);
    ui ->loECGBaseline->addWidget(ecgBaseline_gui);
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
    auto rPeaks_gui = new R_peaks_gui(this);
    ui ->loRpeaks->addWidget(rPeaks_gui);
  //  loadSettings();
    m_app = app; // ewentualnie do usunięcia
    // TU MA BYĆ INFO_LOADED Z CZYMŚ POŁĄCZONE
    connect(this,SIGNAL(signal_loaded(examination*)),ecgBaseline_gui,SLOT(load_signal(examination*)));
    connect(ecgBaseline_gui,SIGNAL(ecg_signal_filtered(Ecg_Baseline*)),rPeaks_gui,SLOT(filtered_signal_loaded(Ecg_Baseline*)));
    connect(rPeaks_gui,SIGNAL(r_peaks_waves_found(R_Peaks*,Waves*)),hrv_1_gui, SLOT(load_R_Peaks_vector(R_Peaks*,Waves*)));
    connect(rPeaks_gui,SIGNAL(r_peaks_waves_found(R_Peaks*,Waves*)),hrv_2_gui, SLOT(load_R_Peaks_vector2(R_Peaks*,Waves*)));
    connect(rPeaks_gui,SIGNAL(r_peaks_waves_found(R_Peaks*,Waves*)),hrv_dfa_gui, SLOT(load_R_Peaks_vector3(R_Peaks*,Waves*)));
    connect(ecgBaseline_gui,SIGNAL(ecg_signal_filtered(Ecg_Baseline*)),stSegment_gui,SLOT(filtered_signal_loaded_Stsegment(Ecg_Baseline*)));
    connect(ecgBaseline_gui,SIGNAL(ecg_signal_filtered(Ecg_Baseline*)),heart_class_gui,SLOT(filtered_signal_loaded_Heart(Ecg_Baseline*)));
    connect(ecgBaseline_gui,SIGNAL(ecg_signal_filtered(Ecg_Baseline*)),t_alt_class_gui,SLOT(filtered_signal_loaded_Taltclass(Ecg_Baseline*)));




    // Tutaj jest do multithread
    ecg_io = new Ecg_IO();
    connect(ecg_io,SIGNAL(data_loaded(examination*)),ecgBaseline_gui,SLOT(load_signal(examination*)));
    connect(ecg_io,SIGNAL(finished()),ecg_io,SLOT(deleteLater()));
    connect(ecg_io->get_file(),SIGNAL(info_loaded(examination_info*)),ecgBaseline_gui, SLOT(load_info(examination_info*)));
    connect(ecg_io->get_file(),SIGNAL(part_loaded(arma::vec*)),ecgBaseline_gui,SLOT(load_part(arma::vec*)));
    connect(ecgBaseline_gui,SIGNAL(still_loading()),ecgBaseline_gui,SLOT(continue_processing()));
    connect(rPeaks_gui,SIGNAL(still_loading()),rPeaks_gui,SLOT(continue_processing()));
    connect(hrv_1_gui,SIGNAL(still_loading()),hrv_1_gui,SLOT(continue_processing()));

}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_actionExit_triggered()
{
    // możliwe, że nie usuwamy czegoś deletem
    m_app->quit(); // dupa, to nie działa :'(
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
//     QTime time;
     QString name = file.get_filename();
     ecg_io->set_filename(name);
//     time.start();
     ecg_io->start();
//     file.get_data();
//     qInfo() << "Upłynęło " << time.elapsed()/1000.0 << "s";
//     emit signal_loaded(input.get_file());
     ui->statusBar->showMessage("Data loading");
     QTime time;
     time.start();
//     file.get_data();
     qInfo() << "Upłynęło " << time.elapsed()/1000.0 << "s";
//     emit signal_loaded(&file);

     //-------- tutaj do poprawy, na razie nieistotne
     //Konwersja int wieku do Qstringa
//     QString xstr=QString::number(file.age);
//     ui->lE_age->setText(xstr);


     //Do poprawy wyswietlanie plci
     //QString str=QString::unicode(file.sex);
     //ui->lE_gender->setText(str);
     ui->tabWidget->setEnabled(true);
     ui->statusBar->showMessage("Data loaded");
     ecg_io->start();
 }

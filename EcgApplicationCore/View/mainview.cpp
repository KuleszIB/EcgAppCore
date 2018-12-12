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

}

MainView::~MainView()
{
    delete ui;
}


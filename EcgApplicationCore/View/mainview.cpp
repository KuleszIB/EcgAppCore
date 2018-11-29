#include "mainview.h"
#include "ui_mainview.h"
#include "View/heart_class.h"
#include "View/t_alt_class.h"
#include "View/hrv1.h"
#include "View/hrv2.h"
#include "View/st_segment.h"
#include "View/hrv_dfa.h"
#include "View/ecgbaseline.h"
#include "View/r_peaks.h"
#include "r_peaks0.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    auto heart_class = new Heart_class(this);
    ui ->loHeartClass->addWidget(heart_class);
    auto t_alt_class = new T_alt_class(this);
    ui ->loTAltClass->addWidget(t_alt_class);
    auto hrv_2 = new HRV2(this);
    ui ->lo_HRV2->addWidget(hrv_2);
    auto hrv_1 = new HRV1(this);
    ui ->lo_HRV1->addWidget(hrv_1);
    auto stSegment = new St_segment(this);
    ui ->loSTSegment->addWidget(stSegment);
    auto hrv_dfa = new HRV_dfa(this);
    ui ->loHRVdfa->addWidget(hrv_dfa);
    auto ecgBaseline = new ECGbaseline(this);
    ui ->loECGBaseline->addWidget(ecgBaseline);
    auto rPeaks = new R_peaks(this);
    ui ->loRpeaks->addWidget(rPeaks);

}

MainView::~MainView()
{
    delete ui;
}

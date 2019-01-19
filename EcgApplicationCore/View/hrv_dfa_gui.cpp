#include "hrv_dfa_gui.h"
#include "ui_hrv_dfa_gui.h"

HRV_dfa_gui::HRV_dfa_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV_dfa_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    hrvdfaPlot2 = new hrvdfaplot(this);
    layout->addWidget(hrvdfaPlot2);
    ui->Plot->setLayout(layout);
    m_r_peaks.reserve(20);
    m_hrv_dfa.reserve(20);
    current_it = 0;
}

HRV_dfa_gui::~HRV_dfa_gui()
{
    delete ui;
}

void HRV_dfa_gui::AddGraph(){

//m_hrv_dfa[0]->calculate_DFA();
Out_DFA Out=m_hrv_dfa[0]->get_out_DFA();
//double alpha1=Out.alpha1;
//double alpha2=Out.alpha2;
arma::vec logF=Out.log_F;
arma::vec logdelta=Out.log_delta;
arma::vec vectorshortwindows=Out.vector_short_windows;
arma::vec vectorlongwindows=Out.vector_long_windows;
//int K=7200;
QVector<double> log_f(logF.size()), log_d(logdelta.size()), v_s(vectorshortwindows.size()), v_l(vectorlongwindows.size());
log_f= examination::convert_vec_qvector(logF);
log_d= examination::convert_vec_qvector(logdelta);
v_s= examination::convert_vec_qvector(vectorshortwindows);
v_l= examination::convert_vec_qvector(vectorlongwindows);

hrvdfaPlot2->setDataHRVDFA(log_f, log_d, v_s, v_l);
}


void HRV_dfa_gui::load_R_Peaks_vector3(R_Peaks *r_peaks_signal, Waves *waves)
{
    m_r_peaks.push_back(r_peaks_signal);
    HrvDfa *hrv_dfa_r_peaks = new HrvDfa(m_r_peaks[current_it++]->get_r_peaks());
    m_hrv_dfa.push_back(hrv_dfa_r_peaks);
}

void HRV_dfa_gui::on_pushButton_clicked()
{
    AddGraph();
}



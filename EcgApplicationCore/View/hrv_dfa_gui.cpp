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
    package_it = 0;
}

HRV_dfa_gui::~HRV_dfa_gui()
{
    delete ui;
}

void HRV_dfa_gui::AddGraph(){

//m_hrv_dfa[0]->calculate_DFA();
    int deltaMaxValue = ui->deltaMax->value();
        int deltaMinValue = ui->deltaMin->value();
m_hrv_dfa[0]->set_delta(deltaMaxValue,deltaMinValue);
Out_DFA Out=m_hrv_dfa[current_it-2]->get_out_DFA();
//double alpha1=Out.alpha1;
//double alpha2=Out.alpha2;
QTableWidgetItem *theItem = new QTableWidgetItem();
    theItem->setData(Qt::EditRole, Out.alpha1);
    ui->tableWidget->setItem(1, 0, theItem);
    QTableWidgetItem *theItem1 = new QTableWidgetItem();
    theItem1->setData(Qt::EditRole, Out.alpha2);
    ui->tableWidget->setItem(1, 1, theItem1);
    qInfo()<<Out.alpha2;

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

hrvdfaPlot2->setDataHRVDFA(log_d,log_f,  v_l,v_s);
}


void HRV_dfa_gui::load_R_Peaks_vector3(R_Peaks *r_peaks_signal, Waves *waves)
{
    //m_r_peaks.push_back(r_peaks_signal);
    //HrvDfa *hrv_dfa_r_peaks = new HrvDfa(m_r_peaks[current_it++]->get_r_peaks());
    //m_hrv_dfa.push_back(hrv_dfa_r_peaks);

    //
    R_Peaks *n_r_peaks = new R_Peaks;
    arma::vec n_signal = r_peaks_signal->get_r_peaks();
//    qInfo() << "n_signal(0)" << n_signal(0);
    n_r_peaks->set_r_peaks(n_signal);
    if(package_it>0)
    {
        arma::vec o_signal = m_r_peaks[package_it-1]->get_r_peaks();
        n_signal.insert_rows(0,o_signal);
        n_r_peaks->set_r_peaks(n_signal);
    }
    m_r_peaks.push_back(n_r_peaks);
//    if(package_it == 21)
//    {
//        arma::vec r = m_r_peaks[21]->get_r_peaks();
//        for(int i = 0; i < r.size() ;i++)
//            qInfo() << r[i];
//    }
    HrvDfa *hrv_dfa_r_peaks = new HrvDfa(n_signal);
    m_hrv_dfa.push_back(hrv_dfa_r_peaks);
    package_it++;
    if(current_it > 0)
        emit still_loading();
}

void HRV_dfa_gui::on_pushButton_clicked()
{
    emit still_loading();
    ui->pushButton->setDisabled(true);
}

void HRV_dfa_gui::continue_processing()
{
    if(++current_it < m_r_peaks.size())
        emit still_loading();
    else
    {
        m_hrv_dfa[current_it-2]->calculate_DFA();
        AddGraph();
    }
}


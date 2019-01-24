#include "st_segment_gui.h"
#include "ui_st_segment_gui.h"

St_segment_gui::St_segment_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::St_segment_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    qrsPlot2 = new qrsplot(this);
    layout->addWidget(qrsPlot2);
    ui->ecgPlot->setLayout(layout);
    connect(ui->button, SIGNAL(clicked()),this, SLOT(addRandomGraph()));

}
St_segment_gui::~St_segment_gui()
{
    delete ui;
}

void St_segment_gui::filtered_signal_loaded_Stsegment(Ecg_Baseline *signal)
{
    //tutaj odbierasz signalfiltered
    Ecg_Baseline *ecg_signal_filtered = new Ecg_Baseline(signal->get_signal_filtered(),signal->get_sampling_freq());
    m_ecg_baseline.push_back(signal);
    //R_Peaks *r_peaks = new R_Peaks(signal->get_signal_raw());
    //m_r_peaks.push_back(r_peaks);

    //Waves *m_waves2 = new Waves(signal->get_signal_filtered(),m_r_peaks[0]->get_r_peaks(), signal->get_sampling_freq());
    //m_waves.push_back(m_waves2);

}

void St_segment_gui::load_waves_vector(R_Peaks *signal1,Waves *signal2)
{
    //tutaj odbierasz wavesy
    m_r_peaks.push_back(signal1);
    m_waves.push_back(signal2);
    St_Segment *st_segment1 = new St_Segment(m_waves[0]->get_signal_filtered(),m_waves[0]->get_waves());
    st.push_back(st_segment1);
}
void St_segment_gui::addRandomGraph() //Przykładowy wykres
{


    st[0]->analyze();
    arma:: vec signal = m_ecg_baseline[0]->get_signal_filtered();
    arma:: vec time = m_ecg_baseline[0]->get_time_vec(0);
    double freq=m_r_peaks[0]->get_sampling_freq();
  arma::uvec t_peak=st[0]->St_Points.t_peak;
  arma::uvec t_on=st[0]->St_Points.t_on;
  arma::uvec t_end=st[0]->St_Points.t_end;
  arma::uvec q_on=st[0]->St_Points.q_on;
  arma::uvec q_end=st[0]->St_Points.q_end;
  arma::vec sig=st[0]->St_Points.sig;

  int M=1200;
     //QVector<double> tpeak(t_peak.size()), ton(t_on.size()), tend(t_end.size()), qon(q_on.size()), qend(q_end.size()), Sig(sig.size()); // initialize with entries 0..100
     QVector<double> tpeak(M), ton(M), tend(M), qon(M), qend(M), Sig(M); // initialize with entries 0..100
  tpeak=examination::convert_uvec_qvector(t_peak);
  ton=examination::convert_uvec_qvector(t_on);
  tend=examination::convert_uvec_qvector(t_end);
  qon=examination::convert_uvec_qvector(q_on);
  qend=examination::convert_uvec_qvector(q_end);
  Sig=examination::convert_vec_qvector(sig);
int M1=7200;
  QVector<double> xx(Sig.size()), yy(Sig.size()); // initialize with entries 0..100
  xx=examination::convert_vec_qvector(time);
  yy=examination::convert_vec_qvector(signal);
 qInfo()<<"TO JEST ROZMIAR EJJJJJJJJJJ"<<yy.size()<<"A toooo jest SIG"<<Sig.size();

  qrsPlot2->setData4(xx,yy,tpeak, qon,qend,ton,tend, freq);


  }

void St_segment_gui::on_button_clicked()
{
    addRandomGraph();
    //podpiecie parametrow do gui
    St_Segment *st_segment = new St_Segment(m_ecg_baseline[0]->get_signal_filtered(),m_waves[0]->get_waves());
    double tresholdOFFMin = ui->Treshold_Offset_Min->value(); //geting parameters from GUI
    double tresholdOFFMax = ui->Treshold_Offset_Max->value();
    double tresholdLINMin = ui->Treshold_Linearity_Min->value();
    double tresholdLINMax = ui->Treshold_Linearity_Max->value();
    double tresholdDETType = ui->Treshold_Detection_Type->value();
    st_segment->set_St_Params(tresholdOFFMin, tresholdOFFMax, tresholdDETType, tresholdLINMin, tresholdLINMax);
    st_segment->analyze();
    ui->button->setDisabled(true);
    QString first_ischema_gui = QString::number(st_segment->St_Points.diagnose(0,0));
    ui->lineEdit_ischemia1->setText(first_ischema_gui);
    QString second_ischema_gui = QString::number(st_segment->St_Points.diagnose(0,1));
    ui->lineEdit_ischemia2->setText(second_ischema_gui);
    QString third_ischema_gui = QString::number(st_segment->St_Points.diagnose(0,2));
    ui->lineEdit_ischemia3->setText(third_ischema_gui);
    QString fourth_ischema_gui = QString::number(st_segment->St_Points.diagnose(0,3));
    ui->lineEdit_ischemia4->setText(fourth_ischema_gui);
    QString severe_gui = QString::number(st_segment->St_Points.diagnose(0,4));
    ui->lineEdit_severe->setText(severe_gui);
    QString acute_gui = QString::number(st_segment->St_Points.diagnose(0,5));
    ui->lineEdit_acute->setText(acute_gui);
    QString no_gui = QString::number(st_segment->St_Points.diagnose(0,6));
    ui->lineEdit_nopathologies->setText(no_gui);


}


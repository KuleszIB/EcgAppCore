#include "st_segment_gui.h"
#include "ui_st_segment_gui.h"

St_segment_gui::St_segment_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::St_segment_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    ecgPlot2 = new ecgplot(this);
    layout->addWidget(ecgPlot2);
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
//    Ecg_Baseline *ecg_signal_filtered = new Ecg_Baseline(signal->get_signal_filtered(),signal->get_sampling_freq());
    m_ecg_baseline.push_back(signal);
    //R_Peaks *r_peaks = new R_Peaks(signal->get_signal_raw());
    //m_r_peaks.push_back(r_peaks);

    //Waves *m_waves2 = new Waves(signal->get_signal_filtered(),m_r_peaks[0]->get_r_peaks(), signal->get_sampling_freq());
    //m_waves.push_back(m_waves2);

}

void St_segment_gui::load_waves_vector(R_Peaks *signal1,Waves *signal2)
{
    //tutaj odbierasz wavesy
    m_waves.push_back(signal2);
    //T_Wave_Alt *t_wave_alt = new T_Wave_Alt(m_ecg_baseline[0]->get_signal_filtered(),m_ecg_baseline[0]->get_sampling_freq(),m_waves[0]->get_waves());
    //chyba tak to mialo byc? tutaj masz pelny obiekt t_waves.
    //t_waves.push_back(t_wave_alt);
}
void St_segment_gui::addRandomGraph() //Przykładowy wykres
{
//    arma:: vec time = m_ecg_baseline[0]->get_time_vec(0);
//    arma:: vec signal = m_ecg_baseline[0]->get_signal_filtered();
//    int N=7200;
//    QVector<double> x(N), y(N); // initialize with entries 0..100
//    x=examination::convert_vec_qvector(time);
//    y=examination::convert_vec_qvector(signal);
//    st[0]->analyze();
//    St_Points m_st_points;
//    arma::uvec t_peak=m_st_points.t_peak;
//    arma::uvec t_on=m_st_points.t_on;
//    arma::uvec t_end=m_st_points.t_end;
//    arma::uvec q_on=m_st_points.q_on;
//    arma::uvec q_end=m_st_points.q_end;
//    arma::vec sig=m_st_points.sig;
//    arma::ivec offset=m_st_points.offset;
//    arma::uvec slope=m_st_points.slope;
//    arma::mat diagnose=m_st_points.diagnose;
//    int M=7200;
//       QVector<double> a(M), b(M), c(M), d(M), e(M), f(M); // initialize with entries 0..100
//    a=examination::convert_uvec_qvector(t_peak);
//    b=examination::convert_uvec_qvector(t_on);
//    c=examination::convert_uvec_qvector(t_end);
//    d=examination::convert_uvec_qvector(q_on);
//    e=examination::convert_uvec_qvector(q_end);
//    f=examination::convert_vec_qvector(sig);
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    ecgPlot2->setData(x,y);

  }

void St_segment_gui::on_button_clicked()
{
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


    addRandomGraph();
}

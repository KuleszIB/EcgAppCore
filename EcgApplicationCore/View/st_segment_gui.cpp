#include "st_segment_gui.h"
#include "ui_st_segment_gui.h"
#include "Modules/st_segment_module.h"

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
    //connect(ui->button, SIGNAL(clicked()),this, SLOT(addRandomGraph()));

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
    //chyba tak to mialo byc? tutaj masz pelny obiekt t_waves.
    //t_waves.push_back(t_wave_alt);
}
void St_segment_gui::addRandomGraph() //Przykładowy wykres
{
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = cos(x[i]); // let's plot a quadratic function
    }
    ecgPlot2->setData(x,y);
  }

void St_segment_gui::on_button_clicked()
{
    St_Segment *st_segment = new St_Segment(m_ecg_baseline[0]->get_signal_filtered(),m_waves[0]->get_waves());
    double tresholdOFFMin = ui->Treshold_Offset_Min->value(); //geting parameters from GUI
    double tresholdOFFMax = ui->Treshold_Offset_Max->value();
    double tresholdLINMin = ui->Treshold_Linearity_Min->value();
    double tresholdLINMax = ui->Treshold_Linearity_Max->value();
    double tresholdDETType = ui->Treshold_Detection_Type->value();
    st_segment->set_St_Params(tresholdOFFMin, tresholdOFFMax, tresholdDETType, tresholdLINMin, tresholdLINMax);
   st_segment->analyze();
    ui->button->setDisabled(true);
   //Filip tutaj wywolanie funkcji

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

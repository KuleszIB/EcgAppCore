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
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = cos(x[i]); // let's plot a quadratic function
    }
    ecgPlot2->setData(x,y);
  }

void St_segment_gui::on_pushButton_clicked()
{
    //Filip tutaj wywolanie funkcji
}

#include "t_alt_class_gui.h"
#include "ui_t_alt_class_gui.h"

T_alt_class_gui::T_alt_class_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::T_alt_class_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    ecgPlot2 = new ecgplot(this);
    layout->addWidget(ecgPlot2);
    ui->ecgPlot->setLayout(layout);
    //do usuniecia na dole funkcja do on push button
 //   connect(ui->button, SIGNAL(clicked()),this, SLOT(addGraph()));
    m_ecg_baseline.reserve(10);
    m_waves.reserve(10);
    t_waves.reserve(10);
    current_it = 0;

}

T_alt_class_gui::~T_alt_class_gui()
{
    delete ui;
}



//void T_alt_class_gui::filtered_signal_loaded_Taltclass(Ecg_Baseline *signal)
//{
//    Ecg_Baseline *ecg_signal_filtered = new Ecg_Baseline(signal->get_signal_filtered(),signal->get_sampling_freq());
  //  m_ecg_baseline.push_back(signal);
//    R_Peaks *r_peaks = new R_Peaks(signal->get_signal_raw());
//    m_r_peaks.push_back(r_peaks);

    //Waves *m_waves2 = new Waves(signal->get_signal_filtered(),m_r_peaks[0]->get_r_peaks(), signal->get_sampling_freq());
    //m_waves.push_back(m_waves2);

//}
void T_alt_class_gui::load_waves_vector(R_Peaks *signal1,Waves *signal2)
{
    m_waves.push_back(signal2);
    m_r_peaks.push_back(signal1);
    T_Wave_Alt *t_wave_alt = new T_Wave_Alt(m_waves[0]->get_signal_filtered(),m_r_peaks[0]->get_sampling_freq(),m_waves[0]->get_waves());
    //chyba tak to mialo byc? tutaj masz pelny obiekt t_waves.
    t_waves.push_back(t_wave_alt);

}

void T_alt_class_gui::AddGraph() //Przykładowy wykres
{

//    int N = 20000;
//        QVector<double> x(N), y(N); // initialize with entries 0..100

//        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
//        arma::vec time = m_ecg_baseline[0]->get_time_vec(0);
//        arma::vec time_cropped = time(arma::span(0,N-1));
//        x = examination::convert_vec_qvector(time_cropped);
//        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
//       // qrsPlot2->setData2(x,y);

    t_waves[0]->analyze();
    T_Wave_Alt_Struct TWS=t_waves[0]->get_t_wave_alt();
    arma::vec timevec=TWS.time_vec_alt;
    arma::vec odd=TWS.odd_T; //nieparzysty
    arma::vec even=TWS.even_T;
 int N=7200;
    QVector<double> Time(N), Odd(N), Even(N); // initialize with entries 0..100

    Time=examination::convert_vec_qvector(timevec);
    Odd=examination::convert_vec_qvector(odd);
    Even=examination::convert_vec_qvector(even);

    ecgPlot2->setData2(Time,Even, Odd);
   // ecgPlot2->setData(Time,Odd);
  }

//void T_alt_class_gui::on_button_clicked()
//{

//}

void T_alt_class_gui::on_button2_clicked()
{
    AddGraph();
}

#include "t_alt_class_gui.h"
#include "ui_t_alt_class_gui.h"

T_alt_class_gui::T_alt_class_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::T_alt_class_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    qrsPlot2 = new qrsplot(this);
    layout->addWidget(qrsPlot2);
    ui->ecgPlot->setLayout(layout);
    //do usuniecia na dole funkcja do on push button
    connect(ui->button, SIGNAL(clicked()),this, SLOT(addRandomGraph()));
    m_ecg_baseline.reserve(10);
    m_waves.reserve(10);
    t_waves.reserve(10);

}

T_alt_class_gui::~T_alt_class_gui()
{
    delete ui;
}



void T_alt_class_gui::filtered_signal_loaded_Taltclass(Ecg_Baseline *signal)
{
//    Ecg_Baseline *ecg_signal_filtered = new Ecg_Baseline(signal->get_signal_filtered(),signal->get_sampling_freq());
    m_ecg_baseline.push_back(signal);
//    R_Peaks *r_peaks = new R_Peaks(signal->get_signal_raw());
//    m_r_peaks.push_back(r_peaks);

    //Waves *m_waves2 = new Waves(signal->get_signal_filtered(),m_r_peaks[0]->get_r_peaks(), signal->get_sampling_freq());
    //m_waves.push_back(m_waves2);

}
void T_alt_class_gui::load_waves_vector(R_Peaks *signal1,Waves *signal2)
{
    m_waves.push_back(signal2);
    T_Wave_Alt *t_wave_alt = new T_Wave_Alt(m_ecg_baseline[0]->get_signal_filtered(),m_ecg_baseline[0]->get_sampling_freq(),m_waves[0]->get_waves());
    //chyba tak to mialo byc? tutaj masz pelny obiekt t_waves.
    t_waves.push_back(t_wave_alt);
    //double alt = t_wave_alt->get_alt(); //wyświetlanie alternansu
   // QString alternans = QString("%1").arg(alt);
    //ui->line_ALT1->setText(alternans);
}


void T_alt_class_gui::addRandomGraph() //Przykładowy wykres
{
//    QVector<double> x(1001), y(1001); // initialize with entries 0..100
//    for (int i=0; i<1001; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = cos(x[i]); // let's plot a quadratic function
//    }
//    qrsPlot2->setData2(x,y);
    int N = 20000;
        QVector<double> x(N), y(N); // initialize with entries 0..100

        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
        arma::vec time = m_ecg_baseline[0]->get_time_vec(0);
        arma::vec time_cropped = time(arma::span(0,N-1));
        x = examination::convert_vec_qvector(time_cropped);
        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        qrsPlot2->setData2(x,y);



//    m_t_wave_alt[0]->analyze();
//    arma::uvec tpeaks=m_t_wave_alt[0]->get_t_peaks();
//    double talt=m_t_wave_alt[0]->get_alt();

  }

void T_alt_class_gui::on_button_clicked()
{
    ui->button->setDisabled(true);
    //Monika tutaj wywolanie funkcji
}

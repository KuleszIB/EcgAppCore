#include "heart_class_gui.h"
#include "ui_heart_class_gui.h"

Heart_class_gui::Heart_class_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Heart_class_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    ecgPlot2 = new ecgplot(this);
    layout->addWidget(ecgPlot2);
    ui->Plot->setLayout(layout);
    m_ecg_baseline.reserve(20);

}


Heart_class_gui::~Heart_class_gui()
{
    delete ui;
}


void Heart_class_gui::filtered_signal_loaded_Heart(Ecg_Baseline *signal)
{
//    Ecg_Baseline *ecg_signal_filtered = new Ecg_Baseline(signal->get_signal_filtered(),signal->get_sampling_freq());
    m_ecg_baseline.push_back(signal);
    R_Peaks *r_peaks = new R_Peaks(signal->get_signal_raw());
    m_r_peaks.push_back(r_peaks);


}
void Heart_class_gui::addGraph()
{
    int N = 20000;
        QVector<double> x(N), y(N); // initialize with entries 0..100

        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
        arma::vec time = m_ecg_baseline[0]->get_time_vec(0);

        arma::vec time_cropped = time(arma::span(0,N-1));
        x = examination::convert_vec_qvector(time_cropped);
        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        ecgPlot2->setData(x,y);
}


void Heart_class_gui::on_Button_Run_clicked()
{
    addGraph();
}


#include "r_peaks_gui.h"
#include "ui_r_peaks_gui.h"

R_peaks_gui::R_peaks_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::R_peaks_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    qrsPlot2=new qrsplot(this);
    layout->addWidget(qrsPlot2);
    ui->qrsPlot->setLayout(layout);
    m_ecg_baseline.reserve(10);
    m_r_peaks.reserve(10);
}



void R_peaks_gui::addRandomGraph() //Przykładowy wykres
{
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    qrsPlot2->setData();
 }
R_peaks_gui::~R_peaks_gui()
{
    delete ui;
}




void R_peaks_gui::peakDetection()
{

}

void R_peaks_gui::filtered_signal_loaded(Ecg_Baseline *signal)
{
//    Ecg_Baseline *ecg_signal_filtered = new Ecg_Baseline(signal->get_signal_filtered(),signal->get_sampling_freq());
    m_ecg_baseline.push_back(signal);
    R_Peaks *r_peaks = new R_Peaks(signal->get_signal_raw());
    m_r_peaks.push_back(r_peaks);
}

void R_peaks_gui::display()
    {
    int N = 7200;
        QVector<double> x(N), y(N); // initialize with entries 0..100
        arma::vec time = m_ecg_baseline[0]->get_time_vec();
        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
        arma::vec time_cropped = time(arma::span(0,N-1));
        x = examination::convert_vec_qvector(time_cropped);
        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        qrsPlot2->setData2(x,y);
      }


void R_peaks_gui::filter2()
    {
    int N = 7200;
    int K = 500;
        QVector<double> x(N), y(N), r(K); // initialize with entries 0..100
        arma::vec time = m_ecg_baseline[0]->get_time_vec();
        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
        arma::vec time_cropped = time(arma::span(0,N-1));
        x = examination::convert_vec_qvector(time_cropped);
        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        arma::vec r_peaks = m_r_peaks[0]->get_r_peaks();
        r = examination::convert_vec_qvector(r_peaks);
       // qrsPlot2->setData2(r,y);
      }


void R_peaks_gui::filter3()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = exp(x[i]); // let's plot a quadratic function
        }
        qrsPlot2->setData2(x,y);
      }



void R_peaks_gui::filter4()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = (x[i]); // let's plot a quadratic function
        }
        qrsPlot2->setData2(x,y);
     }



void R_peaks_gui::on_pushButton_clicked()
{

//    if(ui->checkBoxQRSonset->isChecked())
//    {
//        return filter2();
//    }
//    if(ui->checkBoxR->isChecked())
//    {
//        return filter3();
//    }
//    if(ui->checkBoxQRSend->isChecked())
//    {
//        return filter4();
//    }
    //m_r_peaks[0]->find_r_peaks();
    display();
    arma::vec r_test = m_r_peaks[0]->get_r_peaks();
    qInfo() << "Znaleziono " << r_test.size() << " zespołów QRS.";
 //   if(ui->checkBoxR->isChecked())
 //    {
  //         return filter2();
  //   }


}

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



void R_peaks_gui::filter1()
    {
    int N = 7200;
        QVector<double> x(N), y(N); // initialize with entries 0..100
//        for (int i=0; i<1001; ++i)
//        {
//          x[i] = i/50.0 - 1; // x goes from -1 to 1
//          y[i] = sin(x[i]); // let's plot a quadratic function
//        }
        arma::vec time = m_ecg_baseline[0]->get_time_vec();
        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
        arma::vec time_cropped = time(arma::span(0,N-1));
        x = examination::convert_vec_qvector(time_cropped);
        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        qrsPlot2->setData2(x,y);
      }


void R_peaks_gui::filter2()
    {
//        QVector<double> x(1001), y(1001); // initialize with entries 0..100
//        for (int i=0; i<1001; ++i)
//        {
//          x[i] = i/50.0 - 1; // x goes from -1 to 1
//          y[i] = cos(x[i]); // let's plot a quadratic function
//        }
//        qrsPlot2->setData2(x,y);


    m_waves_points=m_waves.get_waves();
    arma:: uvec rpeaks=m_waves_points.r_peaks;
    arma:: uvec qrsonset=m_waves_points.qrs_onset;
    arma:: uvec qrsend=m_waves_points.qrs_end;
    arma:: uvec tend=m_waves_points.t_end;
    arma:: uvec ponset=m_waves_points.p_onset;
    arma:: uvec pend=m_waves_points.p_end;
    int N = rpeaks.size();
        QVector<double> Rpeaks(N), QRSonset(N), QRSend(N), Tend(N), Ponset(N), Pend(N);
    Rpeaks = examination::convert_uvec_qvector(rpeaks);
    QRSonset = examination::convert_uvec_qvector(qrsonset);
    QRSend = examination::convert_uvec_qvector(qrsend);
    Tend = examination::convert_uvec_qvector(tend);
    Ponset = examination::convert_uvec_qvector(ponset);
    Pend = examination::convert_uvec_qvector(pend);



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
//    if(ui->checkBoxR->isChecked())
//    {
//        return filter1();
//    }
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
    filter1();
    arma::vec r_test = m_r_peaks[0]->get_r_peaks();
    emit r_peaks_get(m_r_peaks[0]);
    qInfo() << "Znaleziono " << r_test.size() << " zespołów QRS.";
}

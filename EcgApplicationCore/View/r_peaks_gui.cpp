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
    m_waves.reserve(10);
}



void R_peaks_gui::addRandomGraph() //Przykładowy wykres
{
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = (x[i]); // let's plot a quadratic function
    }
    qrsPlot2->setData2(x,y);
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

    Waves *m_waves2 = new Waves(signal->get_signal_filtered(),m_r_peaks[0]->get_r_peaks(), signal->get_sampling_freq());
    m_waves.push_back(m_waves2);

}

void R_peaks_gui::filter1()
    {
    int N = 7200;
        QVector<double> x(N), y(N); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = sin(x[i]); // let's plot a quadratic function
        }
        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
        arma::vec time = m_ecg_baseline[0]->get_time_vec();
        arma::vec time_cropped = time(arma::span(0,N-1));
        x = examination::convert_vec_qvector(time_cropped);
        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        qrsPlot2->setData2(x,y);


//        Waves *m_waves2 = new Waves(m_ecg_baseline[0]->get_signal_filtered(),m_r_peaks[0]->get_r_peaks(), m_ecg_baseline[0]->get_sampling_freq());
//        m_waves.push_back(m_waves2);

//        Waves *m_waves2 = new Waves(signal_filtered, m_r_peaks[0]->get_r_peaks(), m_ecg_baseline[0]->get_sampling_freq());
//        m_waves.push_back(m_waves2);
//        int K=7200;
//        new_waves= m_waves[0]->get_waves();
//        arma::uvec new_qrs_onset = new_waves.qrs_onset;
//        arma::uvec new_qrs_end = new_waves.qrs_end;
//        arma::uvec new_p_onset = new_waves.p_onset;
//        arma::uvec new_p_end = new_waves.p_end;

        //funkcja


//        QVector<double> ponest(K), pend(K), qrsonset(K), qrsend(K);
//        ponest=examination::convert_uvec_qvector(new_p_onset);
//        pend=examination::convert_uvec_qvector(new_p_end);
//        qrsonset=examination::convert_uvec_qvector(new_qrs_onset);
//        qrsend=examination::convert_uvec_qvector(new_qrs_end);



       // qrsPlot2->setData3(x,  y, ponest, pend,qrsonset,qrsend);
      }


void R_peaks_gui::funkcja1(){
//    arma::vec y = m_ecg_baseline[0]->get_signal_filtered();
//    arma::vec x = m_ecg_baseline[0]->get_time_vec();
                //   new_waves= m_waves[0]->get_waves();
//    new_waves= m_waves[0]->get_waves();
//    double freq=m_ecg_baseline[0]->get_sampling_freq();
//    arma::uvec new_qrs_onset= new_waves.qrs_onset;//freq;
//    arma::uvec new_qrs_end= new_waves.qrs_end;//freq;
//    arma::uvec new_p_onset= new_waves.p_onset;//freq;
//    arma::uvec new_p_end= new_waves.p_end;//freq;
//    arma::uvec y_ponest(new_p_onset);
//    arma::uvec y_pend(new_p_end);
//    arma::uvec y_qrsend(new_qrs_end);
//    arma::uvec y_qrsonset(new_qrs_onset);
    //SPOSÓB 1
//    for(int i = 0; i<(new_waves.qrs_onset).size()-1;i++)
//    {
//        y_qrsonset(i) = y(uint(new_waves.qrs_onset(i)));
//        qInfo()<<i;
//    }
//    for(int i = 0; i<(new_waves.qrs_end).size()-1;i++)
//    {
//        y_qrsend(i) = y(uint(new_waves.qrs_end(i)));
//        qInfo()<<i;
//    }
//    for(int i = 0; i<(new_waves.p_onset).size()-1;i++)
//        y_ponest(i) = y(uint(new_waves.p_onset(i)));
//    for(int i = 0; i<(new_waves.p_end).size()-1;i++)
//        y_pend(i) = y(uint(new_waves.p_end(i)));

    //SPOSÓB 2
//    for(int i=0;i<(new_waves.qrs_onset).size();i++){
//        if((new_waves.qrs_onset)(i)==x(i)){
//            y_qrsonset(i)=y(i);
//        }
//    }
//    for(int i=0;i<(new_waves.qrs_end).size();i++){
//        if((new_waves.qrs_end)(i)==x(i)){
//            y_qrsend(i)=y(i);
//        }
//    }
//    for(int i=0;i<(new_waves.p_onset).size();i++){
//        if((new_waves.p_onset)(i)==x(i)){
//             y_ponest(i)=y(i);
//        }
//    }

//    for(int i=0;i<(new_waves.p_end).size();i++){
//        if((new_waves.p_end)(i)==x(i)){
//          y_pend(i)=y(i);
//        }
//    }

//        int K=5000;
//    QVector<double> xx(K), yy(K),yponest(K), ypend(K), yqrsonset(K), yqrsend(K);
//    yponest=examination::convert_uvec_qvector(y_ponest);
//    ypend=examination::convert_uvec_qvector(y_pend);
//    yqrsonset=examination::convert_uvec_qvector(y_qrsonset);
//    yqrsend=examination::convert_uvec_qvector(y_qrsend);

//int N=7200;
//    arma::vec time_cropped = x(arma::span(0,N-1));
//    xx = examination::convert_vec_qvector(time_cropped);
//    yy = examination::convert_vec_qvector(y(arma::span(0,N-1)));
 //   qrsPlot2->setData2(x,y);



    //funkcja

//    arma::uvec xnew_qrs_onset = new_waves.qrs_onset;
//    arma::uvec xnew_qrs_end = new_waves.qrs_end;
//    arma::uvec xnew_p_onset = new_waves.p_onset;
//    arma::uvec xnew_p_end = new_waves.p_end;

//    QVector<double> xponest(K), xpend(K), xqrsonset(K), xqrsend(K);
//    xponest=examination::convert_uvec_qvector(xnew_p_onset);
//    xpend=examination::convert_uvec_qvector(xnew_p_end);
//    xqrsonset=examination::convert_uvec_qvector(xnew_qrs_onset);
//    xqrsend=examination::convert_uvec_qvector(xnew_qrs_end);



//    qrsPlot2->setData3(xx,  yy, xponest, yponest, xpend,ypend, xqrsonset,yqrsonset, xqrsend, yqrsend, freq);


}

void R_peaks_gui::filter2()
    {

    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = exp(x[i]); // let's plot a quadratic function
    }
    qrsPlot2->setData2(x,y);
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

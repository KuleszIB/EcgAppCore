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
    m_ecg_baseline.reserve(20);
    m_r_peaks.reserve(20);
    m_waves.reserve(20);
    current_it = 0;
    ui->pushButton->setDisabled(true);
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
    R_Peaks *r_peaks = new R_Peaks(signal->get_signal_filtered(),signal->get_sampling_freq());
    m_r_peaks.push_back(r_peaks);
    ui->pushButton->setDisabled(false);
    if(current_it > 0)
        emit still_loading();
//    qInfo() << "R_peaks size" << m_r_peaks.size();
}
static int suma = 0;
void R_peaks_gui::filter1()
    {
//    int N = 7200;
//        QVector<double> x(N), y(N); // initialize with entries 0..100
//        for (int i=0; i<1001; ++i)
//        {
//          x[i] = i/50.0 - 1; // x goes from -1 to 1
//          y[i] = sin(x[i]); // let's plot a quadratic function
//        }
//        arma::vec time = m_ecg_baseline[0]->get_time_vec(0);
//        arma::vec signal_filtered = m_ecg_baseline[0]->get_signal_filtered();
//        arma::vec time_cropped = time(arma::span(0,N-1));
//        x = examination::convert_vec_qvector(time_cropped);
//        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
//        qInfo() << "Current it" << current_it;
        m_r_peaks[current_it]->find_r_peaks();
        renumber_r_peaks();
        qInfo() << "R_Peak[" << suma << "] =" << (m_r_peaks[current_it]->get_r_peaks())(0);
        suma += (m_r_peaks[current_it]->get_r_peaks()).size();

        if(++current_it < m_r_peaks.size()-1)
            emit still_loading();

//        qrsPlot2->setData2(x,y);
      }


void R_peaks_gui::filter2()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = cos(x[i]); // let's plot a quadratic function
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
    if (current_it > 0)
        emit still_loading();
}

void R_peaks_gui::renumber_r_peaks()
{
    arma::vec new_r_peaks = m_r_peaks[current_it]->get_r_peaks();
    arma::vec tmp(new_r_peaks.size());
    int N = (m_r_peaks[current_it]->get_signal_filtered()).size();
    tmp.fill(N*current_it);
    m_r_peaks[current_it]->set_r_peaks(new_r_peaks + tmp);
}

void R_peaks_gui::renumber_waves()
{
    Waves_Points new_waves = m_waves[current_it]->get_waves();
    arma::vec new_p_onset = new_waves.p_onset;
    arma::vec new_p_end = new_waves.p_end;
    arma::vec new_qrs_onset = new_waves.qrs_onset;
    arma::vec new_r_peaks = new_waves.r_peaks;
    arma::vec new_qrs_end = new_waves.qrs_end;
    arma::vec new_t_end = new_waves.t_end;

    arma::vec tmp_p_onset(new_p_onset.size());
    arma::vec tmp_p_end(new_p_end.size());
    arma::vec tmp_qrs_onset(new_qrs_onset.size());
    arma::vec tmp_r_peaks(new_r_peaks.size());
    arma::vec tmp_qrs_end(new_qrs_end.size());
    arma::vec tmp_t_end(new_t_end.size());

    tmp_p_onset.fill((m_r_peaks[current_it]->get_signal_filtered()).size()*current_it);
    tmp_p_end.fill((m_r_peaks[current_it]->get_signal_filtered()).size()*current_it);
    tmp_qrs_onset.fill((m_r_peaks[current_it]->get_signal_filtered()).size()*current_it);
    tmp_r_peaks.fill((m_r_peaks[current_it]->get_signal_filtered()).size()*current_it);
    tmp_qrs_end.fill((m_r_peaks[current_it]->get_signal_filtered()).size()*current_it);
    tmp_t_end.fill((m_r_peaks[current_it]->get_signal_filtered()).size()*current_it);

    new_p_onset = new_p_onset + tmp_p_onset;
    new_p_end = new_p_end + tmp_p_end;
    new_qrs_onset = new_qrs_onset + tmp_qrs_onset;
    new_r_peaks = new_r_peaks + tmp_r_peaks;
    new_qrs_end = new_qrs_end + tmp_qrs_end;
    new_t_end = new_t_end + tmp_t_end;

    new_waves.p_onset = new_p_onset;
    new_waves.p_end = new_p_end;
    new_waves.qrs_onset = new_qrs_onset;
    new_waves.r_peaks = new_r_peaks;
    new_waves.qrs_end = new_qrs_end;
    new_waves.t_end = new_t_end;

    m_waves[current_it]->set_waves(new_waves);
}

void R_peaks_gui::continue_processing()
{
    filter1();
}

void R_peaks_gui::run_waves()
{
    Waves *waves = new Waves(m_r_peaks[current_it]->get_signal_filtered(),m_r_peaks[current_it]->get_r_peaks(),m_r_peaks[current_it]->get_sampling_freq());
    m_waves.push_back(waves);
    if(current_it != 0)
        find_waves();
    else
        find_waves();
}

void R_peaks_gui::find_waves()
{
    Waves *waves;

    arma::vec new_r_peaks((m_r_peaks[current_it]->get_r_peaks()).size()+1);

    new_r_peaks(0) = (m_r_peaks[current_it-1]->get_r_peaks())((m_r_peaks[current_it-1]->get_r_peaks()).size()-1);
    new_r_peaks(arma::span(1,new_r_peaks.size()-1)) = m_r_peaks[current_it]->get_r_peaks();

    arma::vec new_signal0 = (m_r_peaks[current_it-1]->get_signal_filtered())(arma::span(new_r_peaks(0),(m_r_peaks[current_it-1]->get_signal_filtered()).size()-1));
    arma::vec new_signal1((m_r_peaks[current_it]->get_signal_filtered()).size()+new_signal0.size());
    new_signal1(arma::span(0,new_signal0.size()-1)) = new_signal0;
    new_signal1(arma::span(new_signal0.size(),new_signal1.size()-1)) = m_r_peaks[current_it]->get_signal_filtered();

    waves = new Waves(new_signal1,new_r_peaks,m_r_peaks[current_it]->get_sampling_freq());
    waves->find_waves();
    Waves_Points qrs0 = m_waves[current_it-1]->get_waves();
    renumber_waves();
    Waves_Points qrs1 = waves->get_waves();

//    if(qrs0.p_onset.tail(1) == qrs1.p_onset.head(1))
//        m_waves[current_it]->remove_head(0);
//    if(qrs0.p_end.tail(1) == qrs1.p_end.head(1))
//        m_waves[current_it]->remove_head(1);
//    if(qrs0.qrs_onset.tail(1) == qrs1.qrs_onset.head(1))
//        m_waves[current_it]->remove_head(2);
//    if(qrs0.r_peaks.tail(1) == qrs1.r_peaks.head(1))
//        m_waves[current_it]->remove_head(3);
//    if(qrs0.qrs_end.tail(1) == qrs1.qrs_end.head(1))
//        m_waves[current_it]->remove_head(4);
//    if(qrs0.t_end.tail(1) == qrs1.t_end.head(1))
//        m_waves[current_it]->remove_head(5);

}

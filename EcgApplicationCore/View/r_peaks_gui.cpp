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
//    ui->pushButton->setDisabled(true);
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
    m_ecg_baseline.push_back(signal);
    R_Peaks *r_peaks = new R_Peaks(signal->get_signal_filtered(),signal->get_sampling_freq());
    m_r_peaks.push_back(r_peaks);
    ui->pushButton->setDisabled(false);
    if(current_it > 0)
        emit still_loading();
}

void R_peaks_gui::on_pushButton_clicked()
{
    emit still_loading();
}

void R_peaks_gui::filter1()
{

}

void R_peaks_gui::renumber_r_peaks(int direction)
{
    arma::vec new_r_peaks = m_r_peaks[current_it+direction]->get_r_peaks();
    arma::vec tmp(new_r_peaks.size());
    int N = (m_r_peaks[current_it+direction]->get_signal_filtered()).size();
    tmp.fill(N*(current_it+direction));
    m_r_peaks[current_it+direction]->set_r_peaks(new_r_peaks + tmp);
}

void R_peaks_gui::renumber_waves() // w zależności od numeru iteracji
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

    tmp_p_onset.fill((m_r_peaks[current_it-1]->get_signal_filtered()).size()*current_it);
    tmp_p_end.fill((m_r_peaks[current_it-1]->get_signal_filtered()).size()*current_it);
    tmp_qrs_onset.fill((m_r_peaks[current_it-1]->get_signal_filtered()).size()*current_it);
    tmp_r_peaks.fill((m_r_peaks[current_it-1]->get_signal_filtered()).size()*current_it);
    tmp_qrs_end.fill((m_r_peaks[current_it-1]->get_signal_filtered()).size()*current_it);
    tmp_t_end.fill((m_r_peaks[current_it-1]->get_signal_filtered()).size()*current_it);

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

void R_peaks_gui::renumber_waves(int old_signal_size) // cofnięcie o ilość próbek we wklejonym fragmencie
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

    tmp_p_onset.fill(old_signal_size);
    tmp_p_end.fill(old_signal_size);
    tmp_qrs_onset.fill(old_signal_size);
    tmp_r_peaks.fill(old_signal_size);
    tmp_qrs_end.fill(old_signal_size);
    tmp_t_end.fill(old_signal_size);

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
    m_r_peaks[current_it]->find_r_peaks();
    run_waves();
    if(++current_it < m_r_peaks.size())
        emit still_loading();
}

void R_peaks_gui::run_waves()
{
    Waves *waves = new Waves(m_ecg_baseline[current_it]->get_signal_filtered(),m_r_peaks[current_it]->get_r_peaks(),m_r_peaks[current_it]->get_sampling_freq());
    m_waves.push_back(waves);
    find_waves();
}

void R_peaks_gui::find_waves()
{
// ------------
// Dobry pomysł Kasi Samojeden!
// ------------
    int M, N;
    arma::vec new_r_peaks = m_r_peaks[current_it]->get_r_peaks();
    arma::vec new_r_peaks_copy;
    arma::vec old_r_peaks;
    arma::vec last_r_vec(1); // na szypko
    double last_r;

    arma::vec old_signal;
    arma::vec current_signal = m_ecg_baseline[current_it]->get_signal_filtered();

    // usunięcie ostatniego r peaka
    new_r_peaks.shed_row(new_r_peaks.size()-1);
    new_r_peaks_copy = new_r_peaks;
    if(current_it > 0)
    {
        // wycięcie ze starego sygnału fragmentu od przedostaniego r peaka
        old_r_peaks = m_waves[current_it-1]->get_r_peaks();
        old_signal = m_ecg_baseline[current_it-1]->get_signal_filtered();
        M = old_r_peaks(old_r_peaks.size()-1)+int(m_waves[current_it]->get_sampling_freq()/10.0); // R peak + 10 ms
        N = old_signal.size()-1;
        old_signal = old_signal(arma::span(M,N));

        // wklejenie poprzedniego fragmentu sygnału od przedostatniego r peaka
        current_signal.insert_rows(0,old_signal);        

        // przenumerowanie r peaków ze względu na wklejenie dodatkowych próbek
        arma::vec r_peaks_add_samples(new_r_peaks.size());
        r_peaks_add_samples.fill(old_signal.size());
        new_r_peaks = new_r_peaks + r_peaks_add_samples;

        // przeliczenie r peaka z poprzedniego fragmentu
        last_r = (m_r_peaks[current_it-1]->get_r_peaks())((m_r_peaks[current_it-1]->get_r_peaks()).size()-1);
        last_r = last_r - (m_r_peaks[current_it-1]->get_signal_filtered()).size()*current_it + old_signal.size();
        last_r_vec(0) = last_r;
        new_r_peaks.insert_rows(0,last_r_vec);

        // wstawienie przenumerowanych, doklejonych r peaków
        m_waves[current_it]->set_r_peaks(new_r_peaks);

        // wstawienie sygnału z zakładką
        m_waves[current_it]->set_signal_filtered(current_signal);
        m_waves[current_it]->set_signal_raw(current_signal);

        // szukanie wavesów
        m_waves[current_it]->find_waves();

        // powrócenie sygnału do stanu początkowego
        current_signal.shed_rows(0,old_signal.size()-1);
        m_waves[current_it]->set_signal_filtered(current_signal);

        // przenumerowanie wavesów związane z wklejeniem sygnału
        renumber_waves(-int(old_signal.size()));

        // powrócenie r peaków do stanu początkowego
        m_waves[current_it]->set_r_peaks(new_r_peaks_copy);

        // przenumerowanie starych r peaków, bo w następnej iteracji już ich nie używamy
        renumber_r_peaks();
        renumber_waves();
    }
    else
    {
        m_waves[current_it]->set_r_peaks(new_r_peaks);
        m_waves[current_it]->find_waves();
    }

    renumber_r_peaks(0); // przenumerowanie związane z numerem fragmentu
    m_waves[current_it]->write_to_file(current_it);

    if(current_it>0)
        renumber_r_peaks();
    emit r_peaks_waves_found(m_r_peaks[current_it],m_waves[current_it]);
}

void R_peaks_gui::signal_loaded()
{

}

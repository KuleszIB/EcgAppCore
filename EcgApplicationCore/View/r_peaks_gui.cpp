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
    finished = false;
//    ui->pushButton->setDisabled(true);
}




R_peaks_gui::~R_peaks_gui()
{
    delete ui;
}

void R_peaks_gui::peakDetection()
{

}

// tutaj odbieramy sygnal i wczytujemy go do wektora. Patrz na r_peaks_gui.h
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
    int N;
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec(0);
    N = signal_filtered.size();
        QVector<double> x(N), y(N); // initialize with entries 0..100



        arma::vec time_cropped = time(arma::span(0,N-1));
        x = examination::convert_vec_qvector(time_cropped);
        y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        qrsPlot2->setData2(x,y);

    Waves_Points new_waves=m_waves[current_it]->get_waves();

    if(current_it>0)
        waves2plot(&new_waves);

        double freq=m_ecg_baseline[0]->get_sampling_freq();

        arma::vec xnew_qrs_onset = new_waves.qrs_onset;
        arma::vec xnew_qrs_end = new_waves.qrs_end;
        arma::vec xnew_p_onset = new_waves.p_onset;
        arma::vec xnew_p_end = new_waves.p_end;
        arma::vec xnew_t_end = new_waves.t_end;
        arma::vec xnew_r_peak = rpeaks2plot();

        QVector<double> xponest, xpend, xqrsonset, xrpeak, xqrsend, xtend;
        //xponest=examination::convert_vec_qvector(xnew_p_onset);
        //xpend=examination::convert_vec_qvector(xnew_p_end);
        //xqrsonset=examination::convert_vec_qvector(xnew_qrs_onset);
        //xrpeak=examination::convert_vec_qvector(xnew_r_peak);
        //xqrsend=examination::convert_vec_qvector(xnew_qrs_end);
       // xtend=examination::convert_vec_qvector(xnew_t_end);

        if (ui->checkBoxR->checkState()){
            xrpeak=examination::convert_vec_qvector(xnew_r_peak);
            }
        if (ui->checkBoxQRSonset->checkState()){
             xqrsonset=examination::convert_vec_qvector(xnew_qrs_onset);
            }
        if (ui->checkBoxQRSend->checkState()){
             xqrsend=examination::convert_vec_qvector(xnew_qrs_end);
            }
        if (ui->checkBoxPonset->checkState()){
             xponest=examination::convert_vec_qvector(xnew_p_onset);
            }
        if (ui->checkBoxPend->checkState()){
            xpend=examination::convert_vec_qvector(xnew_p_end);
           }
        qrsPlot2->setData3(x,  y, xponest, xpend, xqrsonset, xrpeak, xqrsend, xtend, freq);


      }


void R_peaks_gui::renumber_r_peaks(int direction)
{
    arma::vec new_r_peaks = m_r_peaks[current_it+direction]->get_r_peaks();
    arma::vec tmp(new_r_peaks.size());
    int N = (m_r_peaks[current_it+direction]->get_signal_filtered()).size();
    tmp.fill(N*(current_it+direction));
    m_r_peaks[current_it+direction]->set_r_peaks(new_r_peaks + tmp);
}

void R_peaks_gui::last_r_peaks()
{
    arma::vec new_r_peaks = m_r_peaks[current_it-1]->get_r_peaks();
    arma::vec tmp(new_r_peaks.size());
    int N = (m_r_peaks[current_it-2]->get_signal_filtered()).size();
    tmp.fill(N*(current_it-1));
    m_r_peaks[current_it-1]->set_r_peaks(new_r_peaks + tmp);
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
    filter1();
}

void R_peaks_gui::find_waves()
{
// ------------
// Dobry pomysł Kasi Samojeden!
// I jeszcze lepsze wykonanie Fabiana Bogusza!
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

        //przeklejenie ujemnych wartości do poprzedniego fragmentu
        distribute_waves();


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
void R_peaks_gui::distribute_waves()
{
    Waves_Points n_waves = m_waves[current_it]->get_waves();
    Waves_Points o_waves = m_waves[current_it-1]->get_waves();
    int N = (m_waves[current_it-1]->get_signal_filtered()).size();
    bool finished = false;

    arma::vec n_p_onset = n_waves.p_onset;
    arma::vec n_p_end = n_waves.p_end;
    arma::vec n_qrs_onset = n_waves.qrs_onset;
    arma::vec n_qrs_end = n_waves.qrs_end;
    arma::vec n_t_end = n_waves.t_end;

    arma::vec o_p_onset = o_waves.p_onset;
    arma::vec o_p_end = o_waves.p_end;
    arma::vec o_qrs_onset = o_waves.qrs_onset;
    arma::vec o_qrs_end = o_waves.qrs_end;
    arma::vec o_t_end = o_waves.t_end;

    arma::vec p_onset(1);
    arma::vec p_end(1);
    arma::vec qrs_onset(1);
    arma::vec qrs_end(1);
    arma::vec t_end(1);

    while(finished == false)
    {
        finished = true;
        if(n_p_onset(0) < 0)
        {
            p_onset = N + n_p_onset(0);
            o_p_onset.insert_rows(o_p_onset.size()-1,p_onset);
            n_p_onset.shed_row(0);
            finished = false;
        }
        if(n_p_end(0) < 0)
        {
            p_end = N + n_p_end(0);
            o_p_end.insert_rows(o_p_end.size()-1,p_end);
            n_p_end.shed_row(0);
            finished = false;
        }
        if(n_qrs_onset(0) < 0)
        {
            qrs_onset = N + n_qrs_onset(0);
            o_qrs_onset.insert_rows(o_qrs_onset.size()-1,qrs_onset);
            n_qrs_onset.shed_row(0);
            finished = false;
        }
        if(n_qrs_end(0) < 0)
        {
            qrs_end = N + n_qrs_end(0);
            o_qrs_end.insert_rows(o_qrs_end.size()-1,qrs_end);
            n_qrs_end.shed_row(0);
            finished = false;
        }
        if(n_t_end(0) < 0)
        {
            t_end = N + n_t_end(0);
            o_t_end.insert_rows(o_t_end.size()-1,t_end);
            n_t_end.shed_row(0);
            finished = false;
        }
    }

    o_waves.p_onset = o_p_onset;
    o_waves.p_end = o_p_end;
    o_waves.qrs_onset = o_qrs_onset;
    o_waves.qrs_end = o_qrs_end;
    o_waves.t_end = o_t_end;

    n_waves.p_onset = n_p_onset;
    n_waves.p_end = n_p_end;
    n_waves.qrs_onset = n_qrs_onset;
    n_waves.qrs_end = n_qrs_end;
    n_waves.t_end = n_t_end;

    m_waves[current_it-1]->set_waves(o_waves);
    m_waves[current_it]->set_waves(n_waves);
}

void R_peaks_gui::waves2plot(Waves_Points* n_waves)
{
    int N = (m_waves[current_it-1]->get_signal_filtered()).size();

    arma::vec p_onset = n_waves->p_onset;
    arma::vec p_end = n_waves->p_end;
    arma::vec qrs_onset = n_waves->qrs_onset;
    arma::vec qrs_end = n_waves->qrs_end;
    arma::vec t_end = n_waves->t_end;

    arma::vec tmp_p_onset(p_onset.size());
    arma::vec tmp_p_end(p_end.size());
    arma::vec tmp_qrs_onset(qrs_onset.size());
    arma::vec tmp_qrs_end(qrs_end.size());
    arma::vec tmp_t_end(t_end.size());

    tmp_p_onset.fill(-N*current_it);
    tmp_p_end.fill(-N*current_it);
    tmp_qrs_onset.fill(-N*current_it);
    tmp_qrs_end.fill(-N*current_it);
    tmp_t_end.fill(-N*current_it);

    n_waves->p_onset = p_onset + tmp_p_onset;
    n_waves->p_end = p_end + tmp_p_end;
    n_waves->qrs_onset = qrs_onset + tmp_qrs_onset;
    n_waves->qrs_end = qrs_end + tmp_qrs_end;
    n_waves->t_end = t_end + tmp_t_end;
}

void R_peaks_gui::signal_loaded()
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

//    arma::vec r_test = m_r_peaks[0]->get_r_peaks();
//    emit r_peaks_get(m_r_peaks[0]);
//    qInfo() << "Znaleziono " << r_test.size() << " zespołów QRS.";
    finished = true;
    last_r_peaks();
}

arma::vec R_peaks_gui::rpeaks2plot()
{
    arma::vec o_r_peaks = m_r_peaks[current_it]->get_r_peaks();
    int N = (m_r_peaks[current_it]->get_signal_filtered()).size();
    arma::vec tmp_r_peaks(o_r_peaks.size());
    tmp_r_peaks.fill(-current_it*N);
    return o_r_peaks + tmp_r_peaks;
}

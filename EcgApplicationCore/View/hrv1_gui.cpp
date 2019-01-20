
#include "hrv1_gui.h"
#include "ui_hrv1_gui.h"

HRV1_gui::HRV1_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV1_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    hrv1Plot2 = new hrv1plot(this);
    layout->addWidget(hrv1Plot2);
    ui->hrv1Plot->setLayout(layout);
    connect(ui->button, SIGNAL(clicked()),this, SLOT(addRandomGraph()));
    hrv_r_peaks.reserve(10);
    current_it = 0;
}

HRV1_gui::~HRV1_gui()
{
    delete ui;
}
void HRV1_gui::addRandomGraph() //Przykładowy wykres
{
   // hrv_r_peaks[0]->calc_periodogram();
   // hrv_r_peaks[0]->calc_freq_vec();
   // hrv_r_peaks[current_it]->calc_params();

    //    if(current_it > 1)
    //    {
    //        arma::vec o_signal = m_r_peaks[current_it-1]->get_r_peaks();
    //        o_signal.shed_rows(0,o_signal.size()-1);

    //        arma::vec n_signal = hrv_r_peaks[current_it]->get_r_peaks();
    //        n_signal.insert_rows(0,o_signal);


    //        //Hrv1 *hrv1 = new Hrv1(n_signal);
    //        //hrv1->calc_params();
    //        hrv_r_peaks[current_it]->set_r_peaks(n_signal);

    //    }





    //
    hrv_r_peaks[current_it]->calc_params();
    int W = 20000;
    qInfo() << "W size " << W;
    QVector<double> periodogram(W), freq(W); // initialize with entries 0..100
    arma::vec period =hrv_r_peaks[current_it]->get_periodogram();
    periodogram = examination::convert_vec_qvector(period);

    arma::vec ti = hrv_r_peaks[current_it]->get_freq_vec();
    freq = examination::convert_vec_qvector(ti);

    timeParams = hrv_r_peaks[current_it]->get_time_params();
    freq_params = hrv_r_peaks[current_it]->get_freq_params();


 //       double hff = freq_params.hf;
 //       double ulff = freq_params.ulf;
 //       double vlff = freq_params.vlf;
 //       double lff = freq_params.lf;

    arma:: vec hff = freq_params.freq_hf;
    arma:: vec ulff = freq_params.freq_ulf;
    arma:: vec vlff = freq_params.freq_vlf;
    arma:: vec lff = freq_params.freq_lf;
    QVector<double> hf(W), ulf(W), vlf(W), lf(W);
    hf= examination::convert_vec_qvector(hff);
    ulf= examination::convert_vec_qvector(ulff);
    vlf= examination::convert_vec_qvector(vlff);
    lf= examination::convert_vec_qvector(lff);
    hrv1Plot2->setDataHRV(freq, periodogram,ulf,vlf, lf,hf);
    QString hf_str = QString("%1").arg(freq_params.hf); //showing frequency parameters
        QString ulf_str = QString("%1").arg(freq_params.ulf);
        QString vlf_str = QString("%1").arg(freq_params.vlf);
        QString lf_str = QString("%1").arg(freq_params.lf);
        QString tp_str = QString("%1").arg(freq_params.tp);
        ui->lineEditHF->setText(hf_str);
        ui->lineEditULF->setText(ulf_str);
        ui->lineEditVLF->setText(vlf_str);
        ui->lineEditLF->setText(lf_str);
        ui->lineEditTP->setText(tp_str);

        QString mean_str = QString("%1").arg(timeParams.rr_mean); //showing time parameters
        QString sdnn_str = QString("%1").arg(timeParams.sdnn);
        QString rmsdd_str = QString("%1").arg(timeParams.rmssd);
        QString pnn50_str = QString("%1").arg(timeParams.pnn50);
        QString nn50_str = QString("%1").arg(timeParams.nn50);
        ui->lineEditMean->setText(mean_str);
        ui->lineEditSDNN->setText(sdnn_str);
        ui->lineEditRMSSD->setText(rmsdd_str);
        ui->lineEditPNN50->setText(pnn50_str);
        ui->lineEditNN50->setText(nn50_str);

   // qInfo()<<hf.size();
}

void HRV1_gui::load_R_Peaks_vector(R_Peaks *r_peaks_signal, Waves *waves)
{
    m_r_peaks.push_back(r_peaks_signal);
    Hrv1 *hrv1_r_peaks;
    if(current_it > 0)
    {
        arma::vec o_peaks = m_r_peaks[current_it-1]->get_r_peaks();
        arma::vec n_peaks = r_peaks_signal->get_r_peaks();
        n_peaks.insert_rows(0,o_peaks);
        hrv1_r_peaks = new Hrv1(n_peaks);
    }
    else
        hrv1_r_peaks = new Hrv1(m_r_peaks[current_it]->get_r_peaks());
    hrv_r_peaks.push_back(hrv1_r_peaks);
    qInfo() << "hrv_r_peaks.size()" << hrv_r_peaks.size();
    if(current_it > 0)
        emit still_loading();

}
void HRV1_gui::on_pushButton_clicked()
{
    addRandomGraph();
    emit still_loading();
    //tutaj chyba calculate periodogram

}

void HRV1_gui::continue_processing()
{
    hrv_r_peaks[current_it]->calc_periodogram();
    addRandomGraph();
    if(++current_it < hrv_r_peaks.size())
        emit still_loading();
}

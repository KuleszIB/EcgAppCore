
#include "hrv1_gui.h"
#include "ui_hrv1_gui.h"

HRV1_gui::HRV1_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV1_gui)
{
    ui->setupUi(this);
    ui->labelHF->setStyleSheet("QLabel {color : rgb(0,150,0); }");
    ui->labelLF->setStyleSheet("QLabel {color : blue; }");
    ui->labelVLF->setStyleSheet("QLabel {color : red; }");
    ui->labelULF->setStyleSheet("QLabel {color : rgb(185,94,0); }");
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
    hrv_r_peaks[current_it]->calc_params();


    arma::vec period =hrv_r_peaks[current_it]->get_periodogram();
    qInfo()<<"sprawdzam rozmiar:"<<hrv_r_peaks[current_it]->get_periodogram().size();

    arma::vec ti = hrv_r_peaks[0]->get_freq_vec();
//int N=200;
    QVector<double>periodogram(period.size()), freq(ti.size()); //periodogram(N), freq(N);
    periodogram = examination::convert_vec_qvector(period);
    freq = examination::convert_vec_qvector(ti);
    timeParams = hrv_r_peaks[0]->get_time_params();
    freq_params = hrv_r_peaks[0]->get_freq_params();


 //       double hff = freq_params.hf;
 //       double ulff = freq_params.ulf;
 //       double vlff = freq_params.vlf;
 //       double lff = freq_params.lf;

    arma:: vec hff = freq_params.freq_hf;
    arma:: vec ulff = freq_params.freq_ulf;
    arma:: vec vlff = freq_params.freq_vlf;
    arma:: vec lff = freq_params.freq_lf;
 int K=200;
    QVector<double> hf(hff.size()), ulf(ulff.size()), vlf(vlff.size()), lf(lff.size()); //hf(K), ulf(K), vlf(K), lf(K);
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
            ui->button->setDisabled(true);

   // qInfo()<<hf.size();
}

void HRV1_gui::load_R_Peaks_vector(R_Peaks *r_peaks_signal, Waves *waves)
{
    m_r_peaks.push_back(r_peaks_signal);
    Hrv1 *hrv1_r_peaks = new Hrv1(r_peaks_signal->get_r_peaks());
    hrv_r_peaks.push_back(hrv1_r_peaks);
    qInfo()<<"Przyszła paczka "<<hrv_r_peaks.size();



}
void HRV1_gui::on_pushButton_clicked()
{

    addRandomGraph();
    //tutaj chyba calculate periodogram

}


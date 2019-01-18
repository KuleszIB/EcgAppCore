
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

}

HRV1_gui::~HRV1_gui()
{
    delete ui;
}
void HRV1_gui::addRandomGraph() //Przykładowy wykres
{
   // hrv_r_peaks[0]->calc_periodogram();
   // hrv_r_peaks[0]->calc_freq_vec();
    hrv_r_peaks[0]->calc_params();
    int N = 7200;
    QVector<double> periodogram(N), freq(N); // initialize with entries 0..100
    arma::vec period =hrv_r_peaks[0]->get_periodogram();
    periodogram = examination::convert_vec_qvector(period);

    arma::vec ti = hrv_r_peaks[0]->get_freq_vec();
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
    int K=7200;
    QVector<double> hf(K), ulf(K), vlf(K), lf(K);
    hf= examination::convert_vec_qvector(hff);
    ulf= examination::convert_vec_qvector(ulff);
    vlf= examination::convert_vec_qvector(vlff);
    lf= examination::convert_vec_qvector(lff);
    hrv1Plot2->setDataHRV(freq, periodogram,ulf,vlf, lf,hf);
   // qInfo()<<hf.size();
}

void HRV1_gui::load_R_Peaks_vector(R_Peaks *r_peaks_signal)
{
    m_r_peaks.push_back(r_peaks_signal);
    Hrv1 *hrv1_r_peaks = new Hrv1(m_r_peaks[0]->get_r_peaks());
    hrv_r_peaks.push_back(hrv1_r_peaks);


}
void HRV1_gui::on_pushButton_clicked()
{
    addRandomGraph();

    //tutaj chyba calculate periodogram

    //KN:fabian sprawdz czy to jest dobrze bo ja nie kumaty z tych rzeczy albo osoba od hrv1 co tu ma byc .

}

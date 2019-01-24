#include "hrv2_gui.h"
#include "ui_hrv2_gui.h"

HRV2_gui::HRV2_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV2_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    hrv2poincarePlot2 = new hrv2poincareplot(this);
    layout->addWidget(hrv2poincarePlot2);
    ui->hrv2poincarePlot->setLayout(layout);

    QVBoxLayout *layout2;
    layout2 = new QVBoxLayout;
    hrv2histPlot2 = new hrv2histplot(this);
    layout2->addWidget(hrv2histPlot2);
    ui->hrv2histPlot->setLayout(layout2);
    m_hrv2.reserve(20);
    m_r_peaks.reserve(20);
    current_it = 0;
    package_it = 0;

}

HRV2_gui::~HRV2_gui()
{
    delete ui;
}

void HRV2_gui::addGraph()
{
   // m_hrv2[0]->calc_poincare();
   // int N = 7200;
    //QVector<double> poincarex(N), poincarey(N); // initialize with entries 0..100
    poincare_graph PoincareGraph=m_hrv2[current_it-2]->get_poincare();
    double sd1 =PoincareGraph.sd1;
    double sd2 =PoincareGraph.sd2;
    double centroidx=PoincareGraph.centroid;
    double centroidy=PoincareGraph.centroid;

    arma::vec intervals_ox=PoincareGraph.intervals_ox;
    arma::vec intervals_oy=PoincareGraph.intervals_oy;
    arma::vec straight_xyxy=PoincareGraph.straight_xy;
    arma::vec sd1_axis_oxx=PoincareGraph.sd1_axis_ox;
    arma::vec sd1_axis_oyy=PoincareGraph.sd1_axis_oy;
    arma::vec sd2_axis_=PoincareGraph.sd2_axis;
    arma::vec xellipse=PoincareGraph.ellipse_ox;
    arma::vec yellipse=PoincareGraph.ellipse_oy;
    //int K=7200;
    QVector<double> int_ox(intervals_ox.size()), int_oy(intervals_oy.size()), sd1_axis_ox(sd1_axis_oxx.size()), sd1_axis_oy(sd1_axis_oyy.size()), sd2_axis(sd2_axis_.size()),ellipse_ox(xellipse.size()), ellipse_oy(yellipse.size());
    int_ox= examination::convert_vec_qvector(intervals_ox);
    int_oy= examination::convert_vec_qvector(intervals_oy);
    sd1_axis_ox= examination::convert_vec_qvector(sd1_axis_oxx);
    sd1_axis_oy= examination::convert_vec_qvector(sd1_axis_oyy);
    sd2_axis=examination::convert_vec_qvector(sd2_axis_);
    ellipse_ox= examination::convert_vec_qvector(xellipse);
    ellipse_oy=examination::convert_vec_qvector(yellipse);
//
    hrv2poincarePlot2->setDataHRVPOINCARE(int_ox,int_oy, sd1_axis_ox, sd1_axis_oy,sd2_axis, sd2_axis,ellipse_ox, ellipse_oy, centroidx, centroidy);

    double tinn_gui = m_hrv2[0]->get_tinn();
    QString tinn_qui_qs = QString::number(tinn_gui);
    ui->lineEditSD1->setText(tinn_qui_qs);

    double triangle_index_gui = m_hrv2[0]->get_triang_index();
    QString triangle_index_gui_qs = QString::number(triangle_index_gui);
    ui->lineEditSD2->setText(triangle_index_gui_qs);
}


void HRV2_gui::addHistogram(){
    histogram_hrv2 Hist=m_hrv2[current_it-2]->get_hist();
    arma::ivec values=Hist.values;
    arma::vec bins=Hist.bins;
    int maxx=Hist.max_value;
    QVector<double> Values, Bins;
    Values=examination::convert_ivec_qvector(values);
    Bins=examination::convert_vec_qvector(bins);
    hrv2histPlot2->setValues2(Bins,Values);
}
void HRV2_gui::load_R_Peaks_vector2(R_Peaks *r_peaks_signal, Waves *waves)
{
    R_Peaks *n_r_peaks = new R_Peaks;
    arma::vec n_signal = r_peaks_signal->get_r_peaks();
//    qInfo() << "n_signal(0)" << n_signal(0);
    n_r_peaks->set_r_peaks(n_signal);
    if(package_it>0)
    {
        arma::vec o_signal = m_r_peaks[package_it-1]->get_r_peaks();
        n_signal.insert_rows(0,o_signal);
        n_r_peaks->set_r_peaks(n_signal);
    }
    m_r_peaks.push_back(n_r_peaks);
//    if(package_it == 21)
//    {
//        arma::vec r = m_r_peaks[21]->get_r_peaks();
//        for(int i = 0; i < r.size() ;i++)
//            qInfo() << r[i];
//    }
    Hrv2 *hrv2_r_peaks = new Hrv2(n_signal);
    m_hrv2.push_back(hrv2_r_peaks);
    package_it++;
    if(current_it > 0)
        emit still_loading();


    //
//    m_r_peaks.push_back(r_peaks_signal);
//    Hrv2 *hrv2_r_peaks = new Hrv2(m_r_peaks[current_it++]->get_r_peaks());
//    m_hrv2.push_back(hrv2_r_peaks);
}

void HRV2_gui::on_pushButton_RUN_clicked()
{
     emit still_loading();
ui->pushButton_RUN->setDisabled(true);

}

void HRV2_gui::continue_processing()
{
    if(++current_it < m_r_peaks.size())
        emit still_loading();
    else
    {
        m_hrv2[current_it-2]->calc_params();
        addHistogram();
        addGraph();
    }
}

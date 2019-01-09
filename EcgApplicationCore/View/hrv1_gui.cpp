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
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
        x[i] = i/50.0 - 1; // x goes from -1 to 1
        y[i] = cos(2*x[i]); // let's plot a quadratic function
   }
    hrv1Plot2->setData2(x,y);
  }

void HRV1_gui::load_R_Peaks_vector(Ecg_Baseline *r_peaks_signal)
{
    Hrv1 *hrv1_r_peaks = new Hrv1(r_peaks_signal->get_signal_raw());
    hrv_r_peaks.push_back(hrv1_r_peaks);
}
void HRV1_gui::on_pushButton_clicked()
{
    addRandomGraph();
    //tutaj chyba calculate periodogram
    hrv_r_peaks[0]->calc_periodogram();
    //fabian sprawdz czy to jest dobrze bo ja nie kumaty z tych rzeczy albo osoba od hrv1 co tu ma byc .

}

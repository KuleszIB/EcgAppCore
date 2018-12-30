#include "ecgbaseline_gui.h"
#include "ui_ecgbaseline_gui.h"

ECGbaseline_gui::ECGbaseline_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ECGbaseline_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    ecgPlot2 = new ecgplot(this);
    layout->addWidget(ecgPlot2);
    ui->ecgPlot->setLayout(layout);


}

ECGbaseline_gui::~ECGbaseline_gui()
{
    delete ui;
}

void ECGbaseline_gui::addRandomGraph() //Przykładowy wykres
{
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    ecgPlot2->setData(x,y);
  }
void ECGbaseline_gui::on_comboBox_filter_currentTextChanged(const QString &arg1)
{
    QString filter = ui->comboBox_filter->currentText();
    if(filter=="lowpass_filter"){
      ui->spinBox_lowFreq->setDisabled(true);
      ui->spinBox_highFreq->setDisabled(false);
      ui->spinBox_filOrder->setDisabled(true);
      ui->spinBox_filLength->setDisabled(true);
      ui->spinBox_stepSize->setDisabled(true);

    } else if (filter=="bandpass_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(false);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);


    } else if (filter=="Butterworth_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(false);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);

    } else if (filter=="Chebyshev_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(false);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it3");
    } else if (filter=="Savitzky’_Golay_filter") {
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(false);
        ui->spinBox_filLength->setDisabled(false);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it4");
    } else if (filter=="Keiser_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(false);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);

    } else if (filter=="LSM_algoritm") {
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(false);
        ui->spinBox_stepSize->setDisabled(true);

    }else if (filter=="Moving_average"){
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(false);
        ui->spinBox_stepSize->setDisabled(false);

    }
}

void ECGbaseline_gui::filter1()
{
    qInfo() << "Teraz ma być MOVING AVERAGE";
    Filter_Params filter_params;
    filter_params.set_filter_type(MOVING_AVERAGE);
    m_ecg_baseline->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline->get_signal_filtered();
    qInfo() << "Teoretycznie przefiltrowało - signal_filtered[1] = " << signal_filtered[1];
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline->get_time_vec();
    arma::vec time_cropped = time(arma::span(0,N-1));
    x = examination::convert_vec_qvector(time_cropped);
    y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
//    for (int i=0; i<1001; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = sin(x[i]); // let's plot a quadratic function
//    }
//    ecgPlot2->setData(x,y);
//    for (int i=0; i<1001; ++i)
//    {
//      x[i] = time_cropped[i]; // x goes from -1 to 1
//      y[i] = signal_filtered[i]; // let's plot a quadratic function
//    }
    ecgPlot2->setData(x,y);
}


void ECGbaseline_gui::filter2()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = cos(x[i]); // let's plot a quadratic function
        }
        ecgPlot2->setData(x,y);


      }


void ECGbaseline_gui::filter3()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = cos(2*x[i]); // let's plot a quadratic function
        }
        ecgPlot2->setData(x,y);
      }



void ECGbaseline_gui::filter4()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = cos(x[i])+sin(x[i]); // let's plot a quadratic function
        }
        ecgPlot2->setData(x,y);
     }

void ECGbaseline_gui::on_pushButton_clicked()
{
    if(ui->comboBox_filter->currentIndex() == 0)
    {
        return filter1();
    }
    if(ui->comboBox_filter->currentIndex() == 1)
    {
        return filter2();
    }
    if(ui->comboBox_filter->currentIndex() == 2)
    {
        return filter3();
    }
    if(ui->comboBox_filter->currentIndex() == 3)
    {
        return filter4();
    }


}

void ECGbaseline_gui::load_signal(examination *file)
{
    m_file = file;
    qInfo() << "Przesłano do ECGbaseline_gui: " << m_file->channel_one[1];
    double fs = m_file->frequency;
    Ecg_Baseline *ecg_baseline = new Ecg_Baseline(m_file->channel_one,fs);
    m_ecg_baseline = ecg_baseline;
}

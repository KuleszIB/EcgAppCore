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
    addRandomGraph();

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
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = sin(x[i]); // let's plot a quadratic function
        }
        ecgPlot2->setData(x,y);
      }

}

void ECGbaseline_gui::filter2()
{
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = cos(x[i]); // let's plot a quadratic function
        }
        ecgPlot2->setData(x,y);
      }

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
}

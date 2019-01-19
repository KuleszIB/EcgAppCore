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
    ui->spinBox_highFreq->setSuffix(" kHz");
    ui->spinBox_lowFreq->setSuffix(" kHz");
    layout->addWidget(ecgPlot2);
    ui->ecgPlot->setLayout(layout);
    m_ecg_baseline.reserve(10);
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
    if(filter=="Raw_signal"){ //dodanie sygnału podstawowego
      ui->spinBox_lowFreq->setDisabled(true);
      ui->spinBox_highFreq->setDisabled(true);
      ui->spinBox_filOrder->setDisabled(true);
      ui->spinBox_filLength->setDisabled(true);
      ui->doubleSpinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("Raw");
    }else if (filter=="Moving_average"){
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(false);
        ui->doubleSpinBox_stepSize->setDisabled(false);
        ui->plainTextEdit->setPlainText("Moving average");
    }
 //   else if (filter=="lowpass_filter"){
 //     ui->spinBox_lowFreq->setDisabled(true);
 //     ui->spinBox_highFreq->setDisabled(false);
 //     ui->spinBox_filOrder->setDisabled(true);
 //     ui->spinBox_filLength->setDisabled(true);
 //     ui->spinBox_stepSize->setDisabled(true);

 //   } else if (filter=="bandpass_filter") {
 //       ui->spinBox_lowFreq->setDisabled(false);
 //       ui->spinBox_highFreq->setDisabled(false);
 //       ui->spinBox_filOrder->setDisabled(true);
 //       ui->spinBox_filLength->setDisabled(true);
 //       ui->spinBox_stepSize->setDisabled(true);


 //   }
    else if (filter=="Butterworth_filter") {
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(false);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->doubleSpinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("Butterworth");

    } else if (filter=="Chebyshev_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->doubleSpinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("Chebyshev");
    } else if (filter=="Savitzky’_Golay_filter") {
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(false);
        ui->spinBox_filLength->setDisabled(false);
        ui->doubleSpinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("Savitzky’_Golay");
    } //else if (filter=="Keiser_filter") {
      //  ui->spinBox_lowFreq->setDisabled(false);
      //  ui->spinBox_highFreq->setDisabled(false);
      //  ui->spinBox_filOrder->setDisabled(true);
      //  ui->spinBox_filLength->setDisabled(true);
      //  ui->spinBox_stepSize->setDisabled(true);

    //}
    else if (filter=="LSM_algorithm") {
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(false);
        ui->doubleSpinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("LSM");
    }
}
void ECGbaseline_gui::nofilter()
{
//    Filter_Params filter_params;
//    filter_params.set_filter_type(BUTTERWORTH);
//    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_raw = m_ecg_baseline[current_it]->get_signal_raw();
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec();
    arma::vec time_cropped = time(arma::span(0,N-1));
    x = examination::convert_vec_qvector(time_cropped);
    y = examination::convert_vec_qvector(signal_raw(arma::span(0,N-1)));
    ecgPlot2->setData(x,y);
}
void ECGbaseline_gui::filter1()
    {
    Filter_Params filter_params;
    filter_params.set_filter_type(MOVING_AVERAGE);
    //Sprawdzenie czy uzytkownik ustawil parametry filtra
    unsigned int length_m;
    double step_m;
    unsigned int length_gui = ui->spinBox_filLength->value();
    if(length_gui != 0)
         {
           length_m=length_gui;
          }else{ length_m=97;}
    double step_gui = ui->doubleSpinBox_stepSize->value();
    if(step_gui != 0)
         {
           step_m=step_gui;
          }else{ step_m=0.2;}
    //Przypisanie parametrow do filtra
    filter_params.set_filter_params(34, 2, 25, length_m, step_m);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    emit ecg_signal_filtered(m_ecg_baseline[current_it]);
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec();
    arma::vec time_cropped = time(arma::span(0,N-1));
    x = examination::convert_vec_qvector(time_cropped);
    y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
//        QVector<double> x(1001), y(1001); // initialize with entries 0..100
//        for (int i=0; i<1001; ++i)
//        {
//          x[i] = i/50.0 - 1; // x goes from -1 to 1
//          y[i] = cos(x[i])+sin(x[i]); // let's plot a quadratic function
//        }
        ecgPlot2->setData(x,y);

     }

void ECGbaseline_gui::filter2()
{
    Filter_Params filter_params;
    filter_params.set_filter_type(BUTTERWORTH);
    double highFreq_b;
    //unsigned int order_b;
    double centerFreq = ui->spinBox_highFreq->value();
    if(centerFreq != 0)
         {
           highFreq_b=centerFreq;
          }else{ highFreq_b=34;}
    //unsigned int order_gui = ui->spinBox_filOrder->value();
    //if(order_gui != 0)
    //     {
    //       order_b=order_gui;
    //      }else{ order_b=1;}
    filter_params.set_filter_params(highFreq_b, 34, 1, 1, 0.2);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec();
    arma::vec time_cropped = time(arma::span(0,N-1));
    x = examination::convert_vec_qvector(time_cropped);
    y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
    ecgPlot2->setData(x,y);
}


void ECGbaseline_gui::filter3()
    {
    Filter_Params filter_params;
    filter_params.set_filter_type(CHEBYSHEV);
    double lowFreq_c;
    //unsigned int order_c;
    double cornerFreq = ui->spinBox_lowFreq->value();
    if(cornerFreq != 0)
         {
           lowFreq_c=cornerFreq;
          }else{ lowFreq_c=2;}
    //unsigned int order_gui_c = ui->spinBox_filOrder->value();
    //if(order_gui_c != 0)
    //     {
    //       order_c=order_gui_c;
    //      }else{ order_c=2;}
    filter_params.set_filter_params(2, lowFreq_c, 2, 1, 0.2);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec();
    arma::vec time_cropped = time(arma::span(0,N-1));
    x = examination::convert_vec_qvector(time_cropped);
    y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        ecgPlot2->setData(x,y);


      }


void ECGbaseline_gui::filter4()
    {
    Filter_Params filter_params;
    filter_params.set_filter_type(SAVITZKY_GOLAY);
    ui->spinBox_filOrder->setMaximum(99);
    unsigned int order_s;
    unsigned int length_s;
    unsigned int order_gui_s = ui->spinBox_filOrder->value();
    if(order_gui_s!= 0)
         {
           order_s=order_gui_s;
          }else{ order_s=3;}
    unsigned int length_gui_s = ui->spinBox_filLength->value();
    if(length_gui_s != 0)
         {
           length_s=length_gui_s;
          }else{ length_s=7;}
    filter_params.set_filter_params(34, 2, order_s, length_s, 0.2);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec();
    arma::vec time_cropped = time(arma::span(0,N-1));
    x = examination::convert_vec_qvector(time_cropped);
    y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        ecgPlot2->setData(x,y);
      }




void ECGbaseline_gui::filter5()
    {
    Filter_Params filter_params;
    filter_params.set_filter_type(LMS);
    unsigned int length_l;
    unsigned int length_gui_l = ui->spinBox_filLength->value();
    if(length_gui_l!= 0)
         {
           length_l=length_gui_l;
          }else{ length_l=97;}
    filter_params.set_filter_params(34, 2, 25, length_l, 0.2);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec();
    arma::vec time_cropped = time(arma::span(0,N-1));
    x = examination::convert_vec_qvector(time_cropped);
    y = examination::convert_vec_qvector(signal_filtered(arma::span(0,N-1)));
        ecgPlot2->setData(x,y);
    }

void ECGbaseline_gui::on_pushButton_clicked()
{
    if(ui->comboBox_filter->currentIndex() == 0)
    {
        nofilter(); //raw signal
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 1)
    {
        filter1(); //Moving Average
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 2)
    {
        filter2(); //Butterworth
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 3)
    {
        filter3(); //Chebyshev
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 4)
    {
        filter4(); //Savitzky_Golay
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 5)
    {
        filter5(); //LMS
        // emituj sygnał do R_Peaks
    }


}

void ECGbaseline_gui::load_signal(examination *file)
{
    m_file = file;
    Ecg_Baseline *ecg_baseline = new Ecg_Baseline(m_file->channel_one,m_file->frequency);
    m_ecg_baseline.push_back(ecg_baseline);
    current_it = 0;
    ui->plainTextEdit->setPlainText("Sygnał załadowano");
}

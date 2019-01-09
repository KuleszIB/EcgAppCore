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
    m_signal.reserve(20);
    m_ecg_baseline.reserve(20);
    current_it = 0;
    loading_finished = false;
    ui->pushButton->setDisabled(true);
}

ECGbaseline_gui::~ECGbaseline_gui()
{
    delete ui;
}

void ECGbaseline_gui::set_info(examination_info file_info)
{
    m_file_info = file_info;
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
    Filter_Params filter_params;
    filter_params.set_filter_type(BUTTERWORTH);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it]->get_time_vec();
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
    Filter_Params filter_params;
    filter_params.set_filter_type(CHEBYSHEV);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
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
//          y[i] = cos(x[i]); // let's plot a quadratic function
//        }
        ecgPlot2->setData(x,y);


      }


void ECGbaseline_gui::filter3()
    {
    Filter_Params filter_params;
    filter_params.set_filter_type(SAVITZKY_GOLAY);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
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
//          y[i] = cos(2*x[i]); // let's plot a quadratic function
//        }
        ecgPlot2->setData(x,y);
      }



void ECGbaseline_gui::filter4()
    {
    Filter_Params filter_params;
    filter_params.set_filter_type(MOVING_AVERAGE);
    m_ecg_baseline[current_it]->filter_baseline(filter_params);
    arma::vec signal_filtered = m_ecg_baseline[current_it]->get_signal_filtered();
    emit ecg_signal_filtered(m_ecg_baseline[current_it]); 
    int N = 7200;
    QVector<double> x(N), y(N); // initialize with entries 0..100
    arma::vec time = m_ecg_baseline[current_it++]->get_time_vec();
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

void ECGbaseline_gui::on_pushButton_clicked()
{
//    current_it++;
    if(ui->comboBox_filter->currentIndex() == 3)
    {
        filter1();
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 4)
    {
        filter2();
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 5)
    {
        filter3();
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 8)
    {
        filter4();
        // emituj sygnał do R_Peaks
    }


}

void ECGbaseline_gui::load_signal(examination *file)
{
    m_file = file;
//    Ecg_Baseline *ecg_baseline = new Ecg_Baseline(m_file->get_channel_one(),m_file->get_freq());
//    m_ecg_baseline.push_back(ecg_baseline);
//    current_it = 0;
    ui->plainTextEdit->setPlainText("Sygnał załadowano");
//    loading_finished = true;
}

void ECGbaseline_gui::load_part(arma::vec *part)
{
    m_signal.push_back(part);
    Ecg_Baseline *ecg_baseline = new Ecg_Baseline(*(m_signal.last()),m_file_info.frequency);
    m_ecg_baseline.push_back(ecg_baseline);
    if (m_signal.length() == 1)
    {
        ui->plainTextEdit->setPlainText("Wczytano fragment");
        ui->pushButton->setDisabled(false);
    }
    else if (current_it > 0)
    {
        emit still_loading();
    }
}

void ECGbaseline_gui::load_info(examination_info *info)
{
    m_file_info = *info;
}

void ECGbaseline_gui::continue_processing()
{
    if(ui->comboBox_filter->currentIndex() == 3)
    {
        filter1();
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 4)
    {
        filter2();
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 5)
    {
        filter3();
        // emituj sygnał do R_Peaks
    }
    if(ui->comboBox_filter->currentIndex() == 8)
    {
        filter4();
        // emituj sygnał do R_Peaks
    }
}

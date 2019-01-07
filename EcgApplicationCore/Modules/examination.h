#ifndef EXAMINATION_H
#define EXAMINATION_H
#include <QWidget>
#include <QFile>
#include <QDir>
#include <QString>
#include <iostream>
#include <QFileDialog>
#include <QtGlobal>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include "armadillo"
#include "file_explorer.h"
//#include <examination.h>

class examination : public QObject
{
    Q_OBJECT
    int age=-1; //TRZEBA JAKOS ZAINICJALIZOWAĆ!!
    char *sex;
    int frequency, baseline, gain;
    QString channel1, channel2, medication, filename;
    int N = 650000;
    arma::vec channel_one=arma::zeros<arma::vec>(N);
    arma::vec channel_two=arma::zeros<arma::vec>(N);
    //std::vector <float> channel_one, channel_two;
    arma::vec sample=arma::zeros<arma::vec>(N);

    QString get_filename();

    //void get_data(int argc, char **argv);
       void get_data();

       // definicja f statycznej musi być tutaj
    static QVector<double> convert_vec_qvector(arma::vec signal)
    {
        typedef std::vector<double> stdvec;
         //typedef QVector<float> qvec;
         stdvec signal_temp = arma::conv_to<stdvec>::from(signal);
         QVector<double> signal_qvec = QVector<double>::fromStdVector(signal_temp);


         return signal_qvec;
    }
signals:
    void part_loaded(examination*);


}; // zamyka strukturę

#endif // EXAMINATION_H

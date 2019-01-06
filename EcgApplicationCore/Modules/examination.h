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
#include "file_explorer.cpp"
//#include <examination.h>




struct examination
{
    int age=-1; //TRZEBA JAKOS ZAINICJALIZOWAĆ!!
    char *sex;
    int frequency, baseline, gain;
    QString channel1, channel2, medication;
    int N = 650000;
    arma::vec channel_one=arma::zeros<arma::vec>(N);
    arma::vec channel_two=arma::zeros<arma::vec>(N);
    //std::vector <float> channel_one, channel_two;
    arma::vec sample=arma::zeros<arma::vec>(N);


    //void get_data(int argc, char **argv);
       void get_data();

       // definicja f statycznej musi być tutaj
    static QVector<float> convert_vec_qvector(arma::vec signal)
    {
        typedef std::vector<float> stdvec;
         //typedef QVector<float> qvec;
         stdvec signal_temp = arma::conv_to<stdvec>::from(signal);
         QVector<float> signal_qvec = QVector<float>::fromStdVector(signal_temp);


         return signal_qvec;
    }



}; // zamyka strukturę

#endif // EXAMINATION_H

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

struct examination_info
{
    QString sex;
    int age, frequency;
};

class examination : public QObject
{
    Q_OBJECT

private:
    int age; //TRZEBA JAKOS ZAINICJALIZOWAĆ!!
//    char *sex;
    int frequency, baseline, gain;
    QString channel1, channel2, medication, filename, sex;
    int N;
    arma::vec channel_one;
    arma::vec channel_two;
    arma::vec sample;

    // definicja f statycznej musi być tutaj -> wydaje mi się, że nie musi
public:
    examination();
    static QVector<double> convert_vec_qvector(arma::vec signal);
    void set_filename(QString name);
    QString get_filename();
    void get_data();
    arma::vec get_channel_one();
    double get_freq();

    static QVector<double> convert_uvec_qvector(arma::uvec signal);
    static QVector<double> convert_ivec_qvector(arma::ivec signal);

signals:
    void part_loaded(arma::vec*);
    void info_loaded(examination_info *info);

}; // zamyka strukturę

#endif // EXAMINATION_H

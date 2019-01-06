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
#include "examination.h"


//void examination::get_data(int argc, char **argv)
void examination::get_data()

{


    QString filename;
  //QApplication app(argc, argv);
  //QWidget *window = new QWidget;
 //QHBoxLayout *layout = new QHBoxLayout;
  QFileDialogTester test;
  filename = test.openFile();
  QStringList name_parts = filename.split(QRegExp("[\\.]"));
  QString info_filename = name_parts[0]+"_info.txt";
  qInfo() << "Wczytany plik naglowkowy" <<  info_filename;
  // elo, wybraliśmy plik, teraz liczymy na to że info do niego ma prawilną nazwę czyli num_info.txt
  QFile file_info(info_filename);
  if (!file_info.open(QIODevice::ReadOnly)){

        //QMessageBox::information(0, "info", file_info.errorString());
      QString not_found = "Info file not found, using dummy values";
      QMessageBox::information(0, "info", not_found);
      //qInfo() << "fileOpen failed";
        age = -1;
        *sex = 'N';
        //sex = "N";
        //qInfo() << "sex" << *sex<< endl;
        frequency = -1;
        baseline = -1;
        gain = -1;
        medication = "NA";
        channel1 = "unknown";
        channel2 = "unknown";
        qInfo() << gain;

  }else{ //bylo bez
      QTextStream info(&file_info);


      // to czego będziemy szukać
      QString freq = "Sampling Frequency";
      QString channel = "Description";
      QString base = "Baseline";
      QString decor = "=====";
      QStringList list;

      // holdery do przechowywania linijek
      QString info_line;

      while(info.readLineInto(&info_line))
      {

          //tu bierzemy częstotliwosc
          if (info_line.contains(freq, Qt::CaseInsensitive))
          {
                list = info_line.split(QRegExp("\\W+"));
              frequency = list[2].toInt();
          } //a tu nazwy kanałów
          else if (info_line.contains(channel))
          {
           list = info_line.split(": ");
              if( channel1.isEmpty()){
                  channel1 = list[1];
              }else if (channel2.isEmpty()){
                  channel2 = list[1]; }
          }
           else if (info_line.contains(base))
          { // na wypadek gdyby sygnał był cyfrowy
               list = info_line.split(": ");
               baseline = list[1].toInt();
          }
          else if (info_line.contains(decor) && age==-1){ // czyli ze wiek nie ustawiony jeszcze
              info_line = info.readLine();
              list = info_line.split(QRegExp("\\W+"), QString::SkipEmptyParts);
              age = list[0].toInt();

              // czary mary z typami
              sex = const_cast<char*>( list[1].toStdString().c_str());
              if (*sex == 'F') // female - kobieta, male - mezczyzna zostaje :)
                  *sex = 'K';

              // teraz sprawdzamy, czy nasz badany sie leczy
              info_line = info.readLine();
              if (info_line!=decor)
              {
                  medication = info_line;
              }else{ //czyli dostalismy koncowe ==== czyli nie bierze lekow
                  info_line = "-";
              }

          }
      }

  }

  // wczytujemy w koncu sygnal
  QFile file(filename);
  if (!file.open(QIODevice::ReadOnly))
  {
      qInfo() << "filropen signal fail";
      QMessageBox::information(0, "file", file.errorString());
  }

  QTextStream in(&file);
  //QTextBrowser *browser = new QTextBrowser;
  QString line;
unsigned int counter = 0;
    while(in.readLineInto(&line))
  {

        if (counter>=channel_one.size())
        { //alokacja pamięci na większą ilość próbek;
            channel_one.resize(channel_one.size()+N);
            channel_two.resize(channel_two.size()+N);
            sample.resize(sample.size()+N);

       }
       //line=in.readLine();
       float ch1, ch2, s;
       //QTextStream ss(line);
       //s = line.section(' ', 1, 1);
       //QStringList list = line.split(" \t ", QString::SkipEmptyParts);
QStringList list = line.split(QRegExp("([\\s])"), QString::SkipEmptyParts);
//
       //to sa liczby a nie to co pomiedzy nimi: QStringList list = line.split(QRegExp("([^\s]\d*)"));
if (list.size() == 2)   {
    ch1 = list[0].toFloat();
    ch2 = list[1].toFloat();
    channel_one(counter)=ch1;
    channel_two(counter)=ch2;
   // qInfo() << channel_one.at(counter);

}else if (list.size()==3) {
    //qInfo() << "trzy";
    s = list[0].toFloat();
    ch1 = list[1].toFloat();
    ch2 = list[2].toFloat();
    sample(counter) = s;
    channel_one(counter)=ch1;
    //channel_one.at(counter)=ch1;
    channel_two(counter)=ch2;

   // qInfo() << channel_one.at(counter);
}


   ++counter;
  }
    //sprawdzenie jakiejś wartości ze środka, czy sygnał cyfrowy czy analogowy
    // albo sprawdzać, czy coś po przecinku (ale to może trafić na zero
    if (channel_one[10]>50 || channel_two[10]> 50)
    {
        int baseline = 1024; // odczytane z adnotacji (sprawdzić czy się nie zmienia)
        int gain = 200; // tak samo

        //odejmuje baseline od każdego elementu i dzieli przez gain
        for (auto& element: channel_one )
        {
            element -= baseline;
            element /= gain;
        }
        for (auto& element : channel_two)
        {
            element-=baseline;
            element /=gain;
        }
    }
//channel_one.print("channel one");


}



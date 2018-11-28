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

class QFileDialogTester : public QWidget
{
public:
  QString openFile()
  {
      // szukaczka otworzy się w tym katalogu
      QString dir = "C:/Users/Documens";
      // fun fact: jak w ścieżce damy folder który nie istnieje, to go wyświetli jako szukana nazwe pliku
      // moze mozna w ten sposob podac ustawic sugerowany plik
    QString filename =  QFileDialog::getOpenFileName(this,tr("Open Document"),
          dir, tr("Text files (*.txt)"));

    if( !filename.isNull() )
    {
      qInfo() << "selected file path : " << filename.toUtf8();



    }
  return filename;
  }

};



struct examination
{
    int age=-1; //TRZEBA JAKOS ZAINICJALIZOWAĆ!!
    char *sex;
    int frequency, baseline, gain;
    QString channel1, channel2, medication;
    std::vector <float> channel_one, channel_two;
    std::vector <float> sample; // nie bedzie chyba potrzebny

    int test_fun(){
        qInfo() << "test_fun";
        frequency = 151900;
        qInfo() << frequency;
        return 1;
    }

    void get_data(int argc, char **argv)
    {


        QString filename;
      QApplication app(argc, argv);
      //QWidget *window = new QWidget;
     //QHBoxLayout *layout = new QHBoxLayout;
      QFileDialogTester test;
      filename = test.openFile();
      QStringList name_parts = filename.split(QRegExp("[\\.]"));
      QString info_filename = name_parts[0]+"_hea.txt";
      qInfo() << "Wczytany plik naglowkowy" <<  info_filename;
      // elo, wybraliśmy plik, teraz liczymy na to że info do niego ma prawilną nazwę czyli num_hea.txt
      QFile file_info(info_filename);
      if (!file_info.open(QIODevice::ReadOnly)){
          // może jak nie znajdzie to pominąć i wyświetlać bez
          // dodac inicjalizowanie jakichs domyślnych wartości
          // i zeby nie zabijało programu jak nie ma pliku z informacjami
            QMessageBox::information(0, "info", file_info.errorString());
      }
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
          //qInfo() << debug;
          //qInfo() << info_line;

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

      // do wyswietlania w konsoli, co ładnego odczytaliśmy
      // cout wyswietla zle w Qt
      //qInfo() << "WIek" << age;
      //qInfo() << "plec" << sex;
      //qInfo() << "Czestotliwosc: "<< frequency;
      //qInfo() << channel1;
      //qInfo() << channel2;
      //qInfo() << baseline;

      // wczytujemy w koncu sygnal
      QFile file(filename);
      if (!file.open(QIODevice::ReadOnly))
          QMessageBox::information(0, "info", file.errorString());
      QTextStream in(&file);
      //QTextBrowser *browser = new QTextBrowser;
      QString line;

        while(in.readLineInto(&line))
      {

           //line=in.readLine();
           float ch1, ch2, s;
           //QTextStream ss(line);
           //s = line.section(' ', 1, 1);
           //QStringList list = line.split(" \t ", QString::SkipEmptyParts);
    QStringList list = line.split(QRegExp("([\\s])"), QString::SkipEmptyParts);
    //
           //to sa liczby a nie to co pomiedzy nimi: QStringList list = line.split(QRegExp("([^\s]\d*)"));

            s = list[0].toFloat();
            ch1 = list[1].toFloat();
            ch2 = list[2].toFloat();

        // no wiec uzywanie couta daje jakieś dzikie wyniki w Qt
          // std::cout << "\t" << s << "\t" << endl;

            sample.push_back(s);
            channel_one.push_back(ch1);
            channel_two.push_back(ch2);
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



    } // zamyka funkcję


}; // zamyka strukturę

#endif // EXAMINATION_H

#include "themewidget.h"
#include "ecg_baseline.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
int main(int argc, char *argv[])
{
    //module1::Ecg_Baseline ecg_baseline;
    QApplication a(argc, argv);
    QMainWindow window;
    ThemeWidget *widget = new ThemeWidget();
    //module1::Ecg_Baseline *baseline = new module1::Ecg_Baseline(); // tutaj cos z deklaracja namespace mozliwe ze usuniemy to module1 ale to do sprawdzenia
    window.setCentralWidget(widget);
    window.resize(900, 600);
    window.show();
    return a.exec();
}


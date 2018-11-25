#include "View/mainview.h"
#include "ecg_baseline.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //module1::Ecg_Baseline ecg_baseline;
    QApplication a(argc, argv);
    MainView w;
    //module1::Ecg_Baseline *baseline = new module1::Ecg_Baseline(); // tutaj cos z deklaracja namespace mozliwe ze usuniemy to module1 ale to do sprawdzenia
    //w.setCentralWidget(widget);
    //w.resize(900, 600);
    w.show();
    return a.exec();
}


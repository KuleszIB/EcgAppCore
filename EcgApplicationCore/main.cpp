#include "themewidget.h"
#include "ecg_baseline.h"
#include <armadillo>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "r_peaks.h"

using namespace arma;

int main(int argc, char *argv[])
{
    Ecg_Baseline ecg_baseline;
    mat A(2,3);
    std::cout << A.n_rows << std::endl;
    QApplication a(argc, argv);
    QMainWindow window;
    ThemeWidget *widget = new ThemeWidget();
    window.setCentralWidget(widget);
    window.resize(900, 600);
    window.show();
    return a.exec();
}


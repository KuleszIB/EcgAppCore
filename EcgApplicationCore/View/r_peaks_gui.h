#ifndef R_PEAKS_H
#define R_PEAKS_H

#include <QWidget>
//#include "r_peaks_module.h"
#include "View/qrsplot.h"
#include <QVBoxLayout>

namespace Ui {
class R_peaks_gui;
}

class R_peaks_gui : public QWidget
{
    Q_OBJECT

public:
    explicit R_peaks_gui(QWidget *parent = 0);
    ~R_peaks_gui();

private slots:
    void peakDetection();
    void prog2();
    void prog1();
    void addRandomGraph();

//    void on_checkBoxR_toggled(bool checked);

    void on_detectPeaksButton_clicked();

    void on_checkBoxR_toggled(bool checked);

private:
    Ui::R_peaks_gui *ui;
    qrsplot *qrsPlot2;
};

#endif // R_PEAKS_H

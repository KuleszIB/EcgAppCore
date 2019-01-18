#ifndef R_PEAKS_GUI_H
#define R_PEAKS_GUI_H

#include <QWidget>
#include "View/qrsplot.h"
#include <QVBoxLayout>
#include "Modules/r_peaks_module.h"
#include "Modules/waves_module.h"
#include "Modules/examination.h"
#include "armadillo"

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
    void addRandomGraph();
    void on_pushButton_clicked();

public slots:
    void filtered_signal_loaded(Ecg_Baseline *signal);
signals:
    void r_peaks_get(R_Peaks* peaks);

private:
    Ui::R_peaks_gui *ui;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Waves*> m_waves;
    Waves_Points new_waves;
    void funkcja1();

    qrsplot *qrsPlot2;
    void filter1();
    void filter2();
    void filter3();
    void filter4();
};

#endif // R_PEAKS_H

#ifndef R_PEAKS_GUI_H
#define R_PEAKS_GUI_H

#include <QWidget>
#include "View/qrsplot.h"
#include <QVBoxLayout>
#include "Modules/r_peaks_module.h"
#include "Modules/waves_module.h"
#include "Modules/examination.h"

namespace Ui {
class R_peaks_gui;
}

class R_peaks_gui : public QWidget
{
    Q_OBJECT

public:
    explicit R_peaks_gui(QWidget *parent = 0);
    ~R_peaks_gui();
    void renumber_r_peaks();
    void renumber_waves();

private slots:
    void peakDetection();
    void addRandomGraph();
    void on_pushButton_clicked();

public slots:
    void filtered_signal_loaded(Ecg_Baseline *signal);
    void continue_processing();
    void run_waves();

signals:
    void still_loading();
    void r_peaks_found();

private:
    int current_it;
    Ui::R_peaks_gui *ui;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Waves*> m_waves;
    qrsplot *qrsPlot2;
    void filter1();
    void filter2();
    void filter3();
    void filter4();
    void find_waves();

};

#endif // R_PEAKS_H

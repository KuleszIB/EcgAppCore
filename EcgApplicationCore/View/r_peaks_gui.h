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
    void renumber_r_peaks(int direction = -1);
    void renumber_waves(); 
    void renumber_waves(int old_signal_size);

private slots:
    void peakDetection();
    void addRandomGraph();
    void on_pushButton_clicked();

public slots:
    void filtered_signal_loaded(Ecg_Baseline *signal);
    void continue_processing();
    void signal_loaded();

signals:
    void still_loading();
    void r_peaks_waves_found(R_Peaks*,Waves*);
    void r_peaks_get(R_Peaks* peaks);

private:
    int current_it;
    Ui::R_peaks_gui *ui;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Waves*> m_waves;
<<<<<<< HEAD
=======
    Waves_Points new_waves;
    void funkcja1();

>>>>>>> origin/Monique_visualization
    qrsplot *qrsPlot2;
    void filter1();
    void filter2();
    void filter3();
    void filter4();
    void find_waves();
    void run_waves();

};

#endif // R_PEAKS_H

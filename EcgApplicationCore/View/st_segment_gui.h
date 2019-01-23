#ifndef ST_SEGMENT_H
#define ST_SEGMENT_H

#include <QWidget>
#include "ecgplot.h"
#include <QVBoxLayout>
#include "Modules/ecg_baseline_module.h"
#include "Modules/waves_module.h"
#include "Modules/examination.h"
#include "Modules/st_segment_module.h"
namespace Ui {
class St_segment_gui;
}

class St_segment_gui : public QWidget
{
    Q_OBJECT

public:
    explicit St_segment_gui(QWidget *parent = 0);
    ~St_segment_gui();
private slots:
    void addRandomGraph();
    void filtered_signal_loaded_Stsegment(Ecg_Baseline*);
    void load_waves_vector(R_Peaks *signal1,Waves *signal2);

    void on_button_clicked();

private:
    Ui::St_segment_gui *ui;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Waves*> m_waves;
    QVector<St_Segment*> st;
    Waves_Points new_waves;
    ecgplot *ecgPlot2;
//    St_Points m_st_points;
};

#endif // ST_SEGMENT_H

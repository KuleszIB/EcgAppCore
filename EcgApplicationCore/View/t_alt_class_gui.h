#ifndef T_ALT_CLASS_H
#define T_ALT_CLASS_H

#include <QWidget>
#include "qrsplot.h"
#include <QVBoxLayout>
#include "Modules/ecg_baseline_module.h"
#include "Modules/waves_module.h"
namespace Ui {
class T_alt_class_gui;
}

class T_alt_class_gui : public QWidget
{
    Q_OBJECT

public:
    explicit T_alt_class_gui(QWidget *parent = 0);
    ~T_alt_class_gui();


private slots:
    void addRandomGraph();
    void filtered_signal_loaded_Taltclass(Ecg_Baseline *signal);

private:
    Ui::T_alt_class_gui *ui;
    qrsplot *qrsPlot2;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Waves*> m_waves;
    Waves_Points new_waves;
};

#endif // T_ALT_CLASS_H

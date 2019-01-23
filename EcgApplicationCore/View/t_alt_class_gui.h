#ifndef T_ALT_CLASS_H
#define T_ALT_CLASS_H

#include <QWidget>
#include "ecgplot.h"
#include <QVBoxLayout>
#include "Modules/ecg_baseline_module.h"
#include "Modules/waves_module.h"
#include "Modules/t_wave_alt_module.h"
#include "Modules/examination.h"
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

 //   void filtered_signal_loaded_Taltclass(Ecg_Baseline *signal);
    void load_waves_vector(R_Peaks *signal1,Waves *signal2);
 //   void on_button_clicked();

    void on_button2_clicked();

private:
    Ui::T_alt_class_gui *ui;
    ecgplot *ecgPlot2;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Waves*> m_waves;
    QVector<T_Wave_Alt*>t_waves;
    unsigned int current_it;
//    QVector<T_Wave_Alt*> m_t_wave_alt;
//   Waves_Points new_waves;
   // void addGraph();
    void AddGraph();
};

#endif // T_ALT_CLASS_H

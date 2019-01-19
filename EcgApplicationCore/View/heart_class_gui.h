#ifndef HEART_CLASS_H
#define HEART_CLASS_H

#include <QWidget>
#include "ecgplot.h"
#include <QVBoxLayout>
#include "Modules/ecg_baseline_module.h"
#include "Modules/waves_module.h"
#include "Modules/examination.h"


namespace Ui {
class Heart_class_gui;
}

class Heart_class_gui : public QWidget
{
    Q_OBJECT

public:
    explicit Heart_class_gui(QWidget *parent = 0);
    ~Heart_class_gui();

private slots:
    void on_Button_Run_clicked();
public slots:
    void filtered_signal_loaded_Heart(Ecg_Baseline*);


private:
    Ui::Heart_class_gui *ui;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    QVector<R_Peaks*> m_r_peaks;
    void addGraph();
    ecgplot *ecgPlot2;
};

#endif // HEART_CLASS_H

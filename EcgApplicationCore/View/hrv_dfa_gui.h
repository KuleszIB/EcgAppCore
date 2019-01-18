#ifndef HRV_DFA_H
#define HRV_DFA_H

#include <QWidget>
#include "hrvdfaplot.h"
#include <Modules/hrv_dfa_module.h>
#include <Modules/r_peaks_module.h>
#include <Modules/examination.h>

namespace Ui {
class HRV_dfa_gui;
}

class HRV_dfa_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV_dfa_gui(QWidget *parent = 0);
    ~HRV_dfa_gui();

public slots:
    void load_R_Peaks_vector3(R_Peaks *r_peaks_signal);

private slots:
    void on_pushButton_clicked();


private:
    Ui::HRV_dfa_gui *ui;
    hrvdfaplot *hrvdfaPlot2;
    QVector<R_Peaks*> m_r_peaks;
    QVector<HrvDfa*> m_hrv_dfa;
    void AddGraph();
};

#endif // HRV_DFA_H

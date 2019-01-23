#ifndef HRV_DFA_GUI_H
#define HRV_DFA_GUI_H

#include <QWidget>
#include "hrvdfaplot.h"
#include <Modules/hrv_dfa_module.h>
#include <Modules/r_peaks_module.h>
#include <Modules/examination.h>
#include "Modules/waves_module.h"

namespace Ui {
class HRV_dfa_gui;
}

class HRV_dfa_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV_dfa_gui(QWidget *parent = 0);
    ~HRV_dfa_gui();
    void AddGraph();
    hrvdfaplot *hrvdfaPlot2;

public slots:
    void load_R_Peaks_vector3(R_Peaks*,Waves*);

private slots:
    void on_pushButton_clicked();

private:
    Ui::HRV_dfa_gui *ui;
    QVector<R_Peaks*> m_r_peaks;
    QVector<HrvDfa*> m_hrv_dfa;
    unsigned int current_it;

};

#endif // HRV_DFA_GUI_H

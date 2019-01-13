#ifndef HRV_DFA_H
#define HRV_DFA_H

#include <QWidget>
#include <QVBoxLayout>
#include "Modules/ecg_baseline_module.h"
#include "Modules/r_peaks_module.h"
#include "Modules/hrv_dfa_module.h"

namespace Ui {
class HRV_dfa_gui;
}

class HRV_dfa_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV_dfa_gui(QWidget *parent = 0);
    ~HRV_dfa_gui();

private:
    Ui::HRV_dfa_gui *ui;
//    QVector<R_Peaks*> m_r_peaks;
    //QVector<HRV_dfa*> hrv_r_peaks;
};

#endif // HRV_DFA_H

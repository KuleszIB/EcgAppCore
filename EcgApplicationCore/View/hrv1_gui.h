#ifndef HRV1_H
#define HRV1_H

#include <QWidget>
#include "hrv1plot.h"
#include <QVBoxLayout>
#include "Modules/r_peaks_module.h"
#include "Modules/ecg_baseline_module.h"
#include "Modules/hrv1_module.h"
#include "Modules/examination.h"
namespace Ui {
class HRV1_gui;
}

class HRV1_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV1_gui(QWidget *parent = 0);
    ~HRV1_gui();

private slots:
    void addRandomGraph();
    void on_button_clicked();

public slots:

    void load_R_Peaks_vector(R_Peaks *r_peaks_signal); // chyba musi byc tak bo w outpucie z r peaksow jest arma vec ale ecgbaseline tez
private:
    Ui::HRV1_gui *ui;
    hrv1plot *hrv1Plot2;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Hrv1*> hrv_r_peaks;
    Time_Params timeParams;
    Frequency_Params freq_params;
};

#endif // HRV1_H

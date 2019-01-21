#ifndef HRV1_GUI_H
#define HRV1_GUI_H

#include <QWidget>
#include "hrv1plot.h"
#include <QVBoxLayout>
#include "Modules/r_peaks_module.h"
#include "Modules/ecg_baseline_module.h"
#include "Modules/hrv1_module.h"
#include "Modules/examination.h"
#include "Modules/waves_module.h"


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
    void on_pushButton_clicked();

public slots:
    void load_R_Peaks_vector(R_Peaks*,Waves*);

signals:
    void still_loading();
private:
    Ui::HRV1_gui *ui;
    hrv1plot *hrv1Plot2;
    QVector<R_Peaks*> m_r_peaks;
    QVector<Hrv1*> hrv_r_peaks;
    Time_Params timeParams;
    Frequency_Params freq_params;
    unsigned int current_it;
};

#endif // HRV1_GUI_H

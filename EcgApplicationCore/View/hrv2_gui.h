#ifndef HRV2_H
#define HRV2_H

#include <QWidget>
#include "hrv2poincareplot.h"
#include "hrv2histplot.h"
#include "Modules/hrv2_module.h"
#include "Modules/r_peaks_module.h"
#include "Modules/examination.h"

namespace Ui {
class HRV2_gui;
}

class HRV2_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV2_gui(QWidget *parent = 0);
    ~HRV2_gui();

public slots:
    void load_R_Peaks_vector2(R_Peaks *r_peaks_signal);

private slots:
    void on_pushButton_RUN_clicked();

private:
    Ui::HRV2_gui *ui;
    hrv2poincareplot *hrv2poincarePlot2;
    hrv2histplot *hrv2histPlot2;
    QVector<Hrv2*> m_hrv2;
    QVector<R_Peaks*> m_r_peaks;
    void addGraph();
    void addHistogram();
};

#endif // HRV2_H

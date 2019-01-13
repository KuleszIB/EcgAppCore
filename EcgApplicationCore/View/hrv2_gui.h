#ifndef HRV2_H
#define HRV2_H

#include <QWidget>
#include "Modules/r_peaks_module.h"
#include "Modules/hrv2_module.h"
#include "hrv2poincareplot.h"
#include "hrv2histplot.h"


namespace Ui {
class HRV2_gui;
}

class HRV2_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV2_gui(QWidget *parent = 0);
    ~HRV2_gui();

private slots:
    void on_pushButton_RUN_clicked();

private:
    Ui::HRV2_gui *ui;
    QVector<R_Peaks> m_r_peaks;
   // QVector<Hrv2> hrv2;
    hrv2poincareplot *hrv2poincarePlot2;
    hrv2histplot *hrv2histPlot2;


};

#endif // HRV2_H

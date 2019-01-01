#ifndef ECGBASELINE_H
#define ECGBASELINE_H

#include <QWidget>
#include "ecgplot.h"
#include "Modules/ecg_baseline_module.h"
#include <QVBoxLayout>
#include "Modules/examination.h"
namespace Ui {
class ECGbaseline_gui;
}

class ECGbaseline_gui : public QWidget
{
    Q_OBJECT

public:
    explicit ECGbaseline_gui(QWidget *parent = 0);
    ~ECGbaseline_gui();

private slots:
    void addRandomGraph();
    void on_comboBox_filter_currentTextChanged(const QString &arg1);
    void on_pushButton_clicked();
public slots:
    void load_signal(examination *file);

private:
    examination *m_file;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    unsigned int current_it;
    Ui::ECGbaseline_gui *ui;
    ecgplot *ecgPlot2;
    void filter1();
    void filter2();
    void filter3();
    void filter4();


};

#endif // ECGBASELINE_H

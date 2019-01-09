#ifndef ECG_BASELINE_GUI_H
#define ECG_BASELINE_GUI_H

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
    void set_info(examination_info file_info);
    ~ECGbaseline_gui();

private slots:
    void addRandomGraph();
    void on_comboBox_filter_currentTextChanged(const QString &arg1);
    void on_pushButton_clicked();
public slots:
    void load_signal(examination *file);
    void load_part(arma::vec *part);
    void load_info(examination_info *info);
    void continue_processing();
signals:
    void ecg_signal_filtered(Ecg_Baseline *signal);
    void still_loading();
private:
    examination *m_file;
    examination_info m_file_info;
    QVector<arma::vec*> m_signal;
    QVector<Ecg_Baseline*> m_ecg_baseline;
    unsigned int current_it;
    bool loading_finished;
    Ui::ECGbaseline_gui *ui;
    ecgplot *ecgPlot2;
    void filter1();
    void filter2();
    void filter3();
    void filter4();


};

#endif // ECGBASELINE_H

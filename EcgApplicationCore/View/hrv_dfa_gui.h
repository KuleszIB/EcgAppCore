#ifndef HRV_DFA_H
#define HRV_DFA_H

#include <QWidget>
#include "ecgplot.h"
#include "Modules/hrv_dfa_module.h"
#include <QVBoxLayout>
#include "Modules/examination.h"

namespace Ui {
class HRV_dfa_gui;
}

class HRV_dfa_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV_dfa_gui(QWidget *parent = 0);
    ~HRV_dfa_gui();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HRV_dfa_gui *ui;

};

#endif // HRV_DFA_H

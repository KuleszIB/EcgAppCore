#ifndef HRV_DFA_H
#define HRV_DFA_H

#include <QWidget>

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
};

#endif // HRV_DFA_H

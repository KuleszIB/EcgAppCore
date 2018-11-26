#ifndef HRV_DFA_H
#define HRV_DFA_H

#include <QWidget>

namespace Ui {
class HRV_dfa;
}

class HRV_dfa : public QWidget
{
    Q_OBJECT

public:
    explicit HRV_dfa(QWidget *parent = 0);
    ~HRV_dfa();

private:
    Ui::HRV_dfa *ui;
};

#endif // HRV_DFA_H

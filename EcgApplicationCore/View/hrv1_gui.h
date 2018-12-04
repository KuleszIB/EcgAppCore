#ifndef HRV1_H
#define HRV1_H

#include <QWidget>

namespace Ui {
class HRV1_gui;
}

class HRV1_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV1_gui(QWidget *parent = 0);
    ~HRV1_gui();

private:
    Ui::HRV1_gui *ui;
};

#endif // HRV1_H

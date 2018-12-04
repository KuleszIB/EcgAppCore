#ifndef HRV2_H
#define HRV2_H

#include <QWidget>

namespace Ui {
class HRV2_gui;
}

class HRV2_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV2_gui(QWidget *parent = 0);
    ~HRV2_gui();

private:
    Ui::HRV2_gui *ui;
};

#endif // HRV2_H

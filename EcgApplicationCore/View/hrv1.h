#ifndef HRV1_H
#define HRV1_H

#include <QWidget>

namespace Ui {
class HRV1;
}

class HRV1 : public QWidget
{
    Q_OBJECT

public:
    explicit HRV1(QWidget *parent = 0);
    ~HRV1();

private:
    Ui::HRV1 *ui;
};

#endif // HRV1_H

#ifndef HRV2_H
#define HRV2_H

#include <QWidget>

namespace Ui {
class HRV2;
}

class HRV2 : public QWidget
{
    Q_OBJECT

public:
    explicit HRV2(QWidget *parent = 0);
    ~HRV2();

private:
    Ui::HRV2 *ui;
};

#endif // HRV2_H

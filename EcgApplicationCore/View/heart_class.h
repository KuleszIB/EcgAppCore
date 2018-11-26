#ifndef HEART_CLASS_H
#define HEART_CLASS_H

#include <QWidget>

namespace Ui {
class Heart_class;
}

class Heart_class : public QWidget
{
    Q_OBJECT

public:
    explicit Heart_class(QWidget *parent = 0);
    ~Heart_class();

private:
    Ui::Heart_class *ui;
};

#endif // HEART_CLASS_H

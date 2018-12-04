#ifndef HEART_CLASS_H
#define HEART_CLASS_H

#include <QWidget>

namespace Ui {
class Heart_class_gui;
}

class Heart_class_gui : public QWidget
{
    Q_OBJECT

public:
    explicit Heart_class_gui(QWidget *parent = 0);
    ~Heart_class_gui();

private:
    Ui::Heart_class_gui *ui;
};

#endif // HEART_CLASS_H

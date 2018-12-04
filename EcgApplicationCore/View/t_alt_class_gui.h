#ifndef T_ALT_CLASS_H
#define T_ALT_CLASS_H

#include <QWidget>

namespace Ui {
class T_alt_class_gui;
}

class T_alt_class_gui : public QWidget
{
    Q_OBJECT

public:
    explicit T_alt_class_gui(QWidget *parent = 0);
    ~T_alt_class_gui();

private:
    Ui::T_alt_class_gui *ui;
};

#endif // T_ALT_CLASS_H

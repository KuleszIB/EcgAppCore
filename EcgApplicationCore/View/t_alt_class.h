#ifndef T_ALT_CLASS_H
#define T_ALT_CLASS_H

#include <QWidget>

namespace Ui {
class T_alt_class;
}

class T_alt_class : public QWidget
{
    Q_OBJECT

public:
    explicit T_alt_class(QWidget *parent = 0);
    ~T_alt_class();

private:
    Ui::T_alt_class *ui;
};

#endif // T_ALT_CLASS_H

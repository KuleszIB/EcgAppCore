#ifndef ST_SEGMENT_H
#define ST_SEGMENT_H

#include <QWidget>

namespace Ui {
class St_segment;
}

class St_segment : public QWidget
{
    Q_OBJECT

public:
    explicit St_segment(QWidget *parent = 0);
    ~St_segment();

private:
    Ui::St_segment *ui;
};

#endif // ST_SEGMENT_H

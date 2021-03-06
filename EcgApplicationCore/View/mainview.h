#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
//#include "../Modules/examination.h"
#include "../Modules/ecg_io.h"
//#include <QSettings>
//#include <QRect>
//#include <QDesktopWidget>
namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QApplication *app, QWidget *parent = 0);
    ~MainView();
    void saveSettings();
    void loadSettings();

private slots:
    void on_actionExit_triggered();
    void on_actionOpen_triggered();

signals:
    void signal_loaded(examination *file);

private:
    Ui::MainView *ui;
    QApplication *m_app;
    Ecg_IO *ecg_io;

};

#endif // MAINVIEW_H

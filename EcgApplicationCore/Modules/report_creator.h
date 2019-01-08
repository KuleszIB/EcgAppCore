#ifndef REPORT_CREATOR2_H
#define REPORT_CREATOR2_H
#include <QPrinter>
#include "view/ecgplot.h"
#include "custom_renderer.h"

class ReportCreator
{
private:
    int i = 10;
    QString  test_name = "C:/Users/Dominika/Pulpit/test_report.pdf";
    QPrinter printer;
    QPainter doc;
    // moze generować jeden printer jako pole klasy

public:
    ReportCreator(); // konstruktor;

    // trzeba chyba template zrobić...
    //void create(ecgplot plot, QPrinter &printer); //jakaś lista widget plotów?
    // TODO template class nadpisujaca QwtRenderer::renderTo
    CustomRenderer create_renderer(ecgplot plot); // na razie tylko ecgplot
    //template <typename T, typename R> R create_renderer(T plot);

    void create_printer();
    void paint_beginning();
    void paint_ending();


};




#endif // REPORT_CREATOR2_H

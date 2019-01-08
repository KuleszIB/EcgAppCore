#include "report_creator.h"
//#include <QPainter>
ReportCreator::ReportCreator()
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(test_name);
    printer.setPageMargins(25, 25, 25, 25, QPrinter::Millimeter);

}

// albo jakaś lista rendererów do paint raport, albo druga funkcja



void ReportCreator::paint_beginning()
{

    doc.begin(&printer);
    doc.drawText(10,5, "Raport z przeprowadzonej analizy");
    doc.drawText(10,10, "test");


    // albo QVariant(3).toString();
    //doc.drawText(10,25, QString::number(exam.age));

    //doc.end();
    //return doc;
}

void ReportCreator::paint_ending()
{
    doc.drawText(150, 0, "Koniec raportu");
    // moze jakas data
    doc.end();
}

void ReportCreator::create_printer()
{
    QString  test_name = "test_report.pdf";
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(test_name);
    printer.setPageMargins(25, 25, 25, 25, QPrinter::Millimeter);

}

CustomRenderer ReportCreator::create_renderer(ecgplot plot)
{
    CustomRenderer;
    renderer.renderTo(plot, printer);
    return renderer;
}

/*
template <typename T, typename R> R ReportCreator::create_renderer(T plot) //jakaś lista widget plotów? // replotted, co z tym ze nowe klasy?
{
    // ale teraz trzeba jakoś, żeby renrerer też był template...
    T renderer;
    //CustomRenderer renderer;
    //QwtPlotRenderer renderer;
    renderer.renderTo(plot, printer);
    //renderer.renderDocument(plot, "test.svg");
    //renderer.exportTo(plot, "costam.pdf"); // ale chyba nie bardzo jak chcemy wiecej
    return renderer;
}
*/

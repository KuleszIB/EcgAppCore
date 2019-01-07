#include "file_explorer.h"

QString QFileDialogTester::openFile()
 {
        // szukaczka otworzy się w tym katalogu
        QString dir = "../../";
        //QString dir = "D:/sem2mag/dadm/signals/mitdb";
        // fun fact: jak w ścieżce damy folder który nie istnieje, to go wyświetli jako szukana nazwe pliku
        // moze mozna w ten sposob podac ustawic sugerowany plik
      QString filename =  QFileDialog::getOpenFileName(this,tr("Open Document"),
            dir, tr("Text files (*.txt)"));

      if( !filename.isNull() )
      {
//        qInfo() << "selected file path : " << filename.toUtf8();
      }
    return filename;
    }

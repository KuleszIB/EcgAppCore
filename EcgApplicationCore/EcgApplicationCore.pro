#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T14:38:52
#
#-------------------------------------------------

QT += charts
requires(qtConfig(combobox))

HEADERS += \
    themewidget.h \
    ecg_baseline.h \
    r_peaks.h

SOURCES += \
    main.cpp \
    themewidget.cpp \
    ecg_baseline.cpp \
    r_peaks.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/chartthemes
INSTALLS += target

FORMS += \
    themewidget.ui

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../liquid-dsp/lib/' -lliqui
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../liquid-dsp/lib/' -lliquid

INCLUDEPATH += $$PWD/'../liquid-dsp/include' \
               $$PWD/'../3rdparty/armadillo-9.200.4/include' \
               $$PWD/'../3rdparty/sigpack-1.2.4/sigpack' \
               $$PWD/'../3rdparty/wfdb-10.6.0/lib' \
               $$PWD/'../3rdparty/DSPFilters-master/shared/DSPFilters/include'

DEPENDPATH += $$PWD/'../liquid-dsp/include' \
              $$PWD/'../3rdparty/armadillo-9.200.4/include' \
              $$PWD/'../3rdparty/sigpack-1.2.4/sigpack' \
              $$PWD/'../3rdparty/wfdb-10.6.0/lib' \
              $$PWD/'../3rdparty/DSPFilters-master/shared/DSPFilters/include'

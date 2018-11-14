#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T14:38:52
#
#-------------------------------------------------

QT += charts
requires(qtConfig(combobox))

HEADERS += \
    themewidget.h \
    ecg_baseline.h

SOURCES += \
    main.cpp \
    themewidget.cpp \
    ecg_baseline.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/chartthemes
INSTALLS += target

FORMS += \
    themewidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../Program Files (x86)/liquid-dsp/lib/' -lliqui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../Program Files (x86)/liquid-dsp/lib/' -lliquid

INCLUDEPATH += $$PWD/'../../../Projekty/EcgAppCoreDADM/liquid-dsp/include'
DEPENDPATH += $$PWD/'../../../Projekty/EcgAppCoreDADM/liquid-dsp/include'

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

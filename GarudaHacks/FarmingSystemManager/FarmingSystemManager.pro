QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ReqClasses.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    FarmingSystemManager_id_ID.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/README.txt \
    icons/qt_attribution.json \
    icons/weather-few-clouds.png \
    icons/weather-fog.png \
    icons/weather-haze.png \
    icons/weather-icy.png \
    icons/weather-overcast.png \
    icons/weather-showers.png \
    icons/weather-sleet.png \
    icons/weather-snow.png \
    icons/weather-storm.png \
    icons/weather-sunny-very-few-clouds.png \
    icons/weather-sunny.png \
    icons/weather-thundershower.png \
    icons/sproutlogo.png


RESOURCES += \
    images.qrc

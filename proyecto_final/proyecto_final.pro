QT       += core gui multimedia
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    botones.cpp \
    enemigo.cpp \
    imagenes.cpp \
    main.cpp \
    interfaz.cpp \
    personaje.cpp \
    plataforma.cpp \
    proyectil.cpp

HEADERS += \
    botones.h \
    enemigo.h \
    imagenes.h \
    interfaz.h \
    personaje.h \
    plataforma.h \
    proyectil.h

FORMS += \
    interfaz.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

DISTFILES += \
    audio/sce.mp3

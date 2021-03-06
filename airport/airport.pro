QT       += core gui sql quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    function.cpp \
    general.cpp \
    main.cpp \
    mainwindow.cpp \
    mysqlit.cpp \
    sign.cpp \
    user.cpp

HEADERS += \
    admin.h \
    function.h \
    general.h \
    mainwindow.h \
    mysqlit.h \
    sign.h \
    user.h

FORMS += \
    admin.ui \
    mainwindow.ui \
    sign.ui \
    user.ui

TRANSLATIONS += \
    airport_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

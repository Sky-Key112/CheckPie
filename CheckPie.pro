QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./QXlsx/         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./QXlsx/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./QXlsx/source/  # current QXlsx source path is ./source/
include(./QXlsx/QXlsx.pri)

win32:CONFIG(release, debug|release): LIBS += -L'C:/Program Files (x86)/DataFrame/lib/' -lDataFrame
else:win32:CONFIG(debug, debug|release): LIBS += -L'C:/Program Files (x86)/DataFrame/lib/' -lDataFramed

INCLUDEPATH += 'C:/Program Files (x86)/DataFrame/include'
DEPENDPATH += 'C:/Program Files (x86)/DataFrame/include'

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += 'C:/Program Files (x86)/DataFrame/lib/libDataFrame.a'
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += 'C:/Program Files (x86)/DataFrame/lib/libDataFramed.a'
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += 'C:/Program Files (x86)/DataFrame/lib/DataFrame.lib'
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += 'C:/Program Files (x86)/DataFrame/lib/DataFramed.lib'

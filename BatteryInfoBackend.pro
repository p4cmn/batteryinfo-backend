QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

LIBS += -lPowrprof -lsetupapi
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  source/batteryinfocontroller.cpp \
  source/batteryinfomodel.cpp \
  source/batteryinfoservice.cpp \
  source/main.cpp \
  source/powermanagementcontroller.cpp \
  source/powermanagementservice.cpp \
  source/tcpserver.cpp

HEADERS += \
  source/batteryhealth.h \
  source/batteryinfocontroller.h \
  source/batteryinfomodel.h \
  source/batteryinfoservice.h \
  source/batterytype.h \
  source/powermanagementcontroller.h \
  source/powermanagementservice.h \
  source/powermode.h \
  source/powersupplytype.h \
  source/tcpserver.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

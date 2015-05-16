TEMPLATE = app

QT += qml quick network

SOURCES += main.cpp \
    controller/backendengineinterface.cpp \
    networking/discoveryserver.cpp \
    networking/devices.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    common/sailfish-postbox-desktop-defines.h \
    controller/backendengineinterface.h \
    networking/discoveryserver.h \
    networking/devices.h

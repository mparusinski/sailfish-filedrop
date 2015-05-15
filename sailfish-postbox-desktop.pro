TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    controller/backendengineinterface.cpp \
    networking/networkdiscoverythread.cpp \
    networking/devices.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    common/sailfish-postbox-desktop-defines.h \
    controller/backendengineinterface.h \
    networking/networkdiscoverythread.h \
    networking/devices.h

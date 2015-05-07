#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/backendengineinterface.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlContext * rootCtx = engine.rootContext();
    rootCtx->setContextProperty("backendEngineInterface", controller::getBackendEngineInterface());

    return app.exec();
}

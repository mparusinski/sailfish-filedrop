#ifndef BACKENDENGINEINTERFACE_H
#define BACKENDENGINEINTERFACE_H

#include <QObject>

class BackendEngineInterface : public QObject
{
    Q_OBJECT
public:
    static BackendEngineInterface* getInstance();

signals:

public slots:

private:
    Q_DISABLE_COPY(BackendEngineInterface)
    explicit BackendEngineInterface(QObject *parent = 0);

    static BackendEngineInterface* instance;
};

#endif // BACKENDENGINEINTERFACE_H

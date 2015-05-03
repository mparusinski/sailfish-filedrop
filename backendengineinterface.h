#ifndef BACKENDENGINEINTERFACE_H
#define BACKENDENGINEINTERFACE_H

#include <QObject>

class BackendEngineInterface : public QObject
{
    Q_OBJECT
public:
    explicit BackendEngineInterface(QObject *parent = 0);

signals:

public slots:
};

#endif // BACKENDENGINEINTERFACE_H

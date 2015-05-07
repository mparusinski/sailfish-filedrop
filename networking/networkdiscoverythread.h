#ifndef NETWORKDISCOVERYTHREAD_H
#define NETWORKDISCOVERYTHREAD_H

#include <QThread>

class NetworkDiscoveryThread : public QThread
{
    Q_OBJECT
public:
	static NetworkDiscoveryThread* getInstance();

    void run();

signals:

public slots:

private:
	Q_DISABLE_COPY(NetworkDiscoveryThread)
	explicit NetworkDiscoveryThread(QThread *parent = 0);

	static NetworkDiscoveryThread* instance;
};

NetworkDiscoveryThread* getNetworkDiscoveryThread();

#endif // NETWORKDISCOVERYTHREAD_H

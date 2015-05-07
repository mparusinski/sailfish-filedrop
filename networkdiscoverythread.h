#ifndef NETWORKDISCOVERYTHREAD_H
#define NETWORKDISCOVERYTHREAD_H

#include <QThread>

namespace networking {

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

} // namespace networking

#endif // NETWORKDISCOVERYTHREAD_H

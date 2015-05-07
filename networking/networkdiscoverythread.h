#ifndef NETWORKDISCOVERYTHREAD_H
#define NETWORKDISCOVERYTHREAD_H

#include <QThread>

namespace networking {

	/*!
	 * \brief NetworkDiscoveryThread is the thread responsible for discovery 
	 *        sailfish devices on the local network. [SINGLETON]
	 *
	 * NetworkDiscoveryThread is a thread that polls the local network for
	 * sailfish devices. It also keeps checking if the devices are available.
	 * The thread also takes care of informing the UI when connecting is lost
	 * or when a connection is made.
	 *
	 * NetworkingDiscoveryThread is a singleton class and should be invoked
	 * using getNetworkDiscoveryThread()
	 */
	class NetworkDiscoveryThread : public QThread
	{
	    Q_OBJECT
	public:
		/*!
		 * \brief getInstance is a function that returns the unique instance of 
		 *        the class.
		 * \warning To get the singleton instance please use 
		 *          getNetworkDiscoveryThread
		 */
		static NetworkDiscoveryThread* getInstance();

	    void run();

	signals:

	public slots:

	private:
		Q_DISABLE_COPY(NetworkDiscoveryThread)
		explicit NetworkDiscoveryThread(QThread *parent = 0);

		static NetworkDiscoveryThread* instance;
	};

	/*!
	 * \brief returns the unique instance of NetworkDiscoverThread
	 */
	NetworkDiscoveryThread* getNetworkDiscoveryThread();							

}

#endif // NETWORKDISCOVERYTHREAD_H

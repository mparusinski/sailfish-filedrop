#include "networkdiscoverythread.h"

namespace networking {

	NetworkDiscoveryThread* NetworkDiscoveryThread::instance = NULL;

	NetworkDiscoveryThread::NetworkDiscoveryThread(QThread *parent) : QThread(parent)
	{

	}

	NetworkDiscoveryThread* NetworkDiscoveryThread::getInstance()
	{
		if (instance == NULL) {
			instance = new NetworkDiscoveryThread;
		}
		return instance;
	}

	void NetworkDiscoveryThread::run()
	{
		// TODO: Implement this function
	}

	NetworkDiscoveryThread* getNetworkDiscoveryThread()
	{
		return NetworkDiscoveryThread::getInstance();
	}

} // namespace networking

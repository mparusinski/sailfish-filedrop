#include "backendengineinterface.h"

BackendEngineInterface* BackendEngineInterface::instance = NULL;

BackendEngineInterface::BackendEngineInterface(QObject *parent) : QObject(parent)
{

}

BackendEngineInterface * BackendEngineInterface::getInstance()
{
    // TODO: Handle case where multiple threads access this code
    if (instance == NULL) {
        // TODO: Handle case where constructor fails
        instance = new BackendEngineInterface;
    }
    return instance;
}

BackendEngineInterface* getBackendEngineInterface()
{
	return BackendEngineInterface::getInstance();
}

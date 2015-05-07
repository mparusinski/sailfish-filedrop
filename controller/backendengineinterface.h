#ifndef BACKENDENGINEINTERFACE_H
#define BACKENDENGINEINTERFACE_H

#include <QObject>

namespace controller {

	/*!
	 * \brief BackendEngineInterface is a class responsible for interfacing 
	 *        the UI with the backend. [SINGLETON]
	 *
	 * BackendEngineInterface is a C++ object that is added to the QML root 
	 * context. This way QML UI objects can communicate back with the backend.
	 *
	 * BackendEngineInterface is a singleton class and should be invoked using
	 * getBackendEngineInterface()
	 */
	class BackendEngineInterface : public QObject
	{
	    Q_OBJECT
	public:
		/*!
		 * \brief getInstance is a function that returns the unique instance of 
		 *        the class.
		 * \warning To get the singleton instance please use 
		 *          getBackendEngineInterface
		 */
	    static BackendEngineInterface* getInstance();

	signals:

	public slots:

	private:
	    Q_DISABLE_COPY(BackendEngineInterface)
	    explicit BackendEngineInterface(QObject *parent = 0);

	    static BackendEngineInterface* instance;
	};

	/*!
	 * \brief returns the unique instance of BackendEngineInterface
	 */
	BackendEngineInterface* getBackendEngineInterface();

} // namespace controller

#endif // BACKENDENGINEINTERFACE_H

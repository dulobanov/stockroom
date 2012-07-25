#include <QtSingleApplication>
#include "mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
	QtSingleApplication app( argc, argv );
	if( app.isRuning()) return 0;

    MainWindowImpl win;
	QObject::connect(&win, SIGNAL( quit() ), &app, SLOT( quit() ) );
	app.setActivationWindow(&win);

	win.show();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}

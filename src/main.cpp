#include <QApplication>
#include "mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
    QApplication app( argc, argv );

    MainWindowImpl win;
	QObject::connect(&win, SIGNAL( quit() ), &app, SLOT( quit() ) );
	win.init();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}

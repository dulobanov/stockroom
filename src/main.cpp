#include <QApplication>
#include "mainwindowimpl.h"
#include "settings.h"
#include "login.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );

    MainWindowImpl win;

    settings *sett = new settings(QString("lobanovs"), QString("stokroom"), &win);
	QObject::connect(sett, SIGNAL( quit() ), &app, SLOT( quit() ) );
	if( sett->init() ) exit(0);
	else win.show();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}

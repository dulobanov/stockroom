#include <QApplication>
#include "mainwindowimpl.h"
#include "settings.h"
#include "login.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );

    settings *sett = new settings;
	
    MainWindowImpl win;
    win.show();
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}

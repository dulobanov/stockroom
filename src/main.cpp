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
    //if(sett->settings_login()) exit(1);
	

    //win.show();
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}

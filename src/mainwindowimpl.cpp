#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
	: QMainWindow(parent, f)
{
	//	ui init
	setupUi(this);


	// start settings
	sett = settings(QString("lobanovs"), QString("stokroom"), this);
	connect(&sett, SIGNAL( quit() ), this, SIGNAL( quit() ) );
	if( sett.init() ) exit(0);


}
//

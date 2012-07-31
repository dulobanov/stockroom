#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
	: QMainWindow(parent, f)
{
	//	ui init
	setupUi(this);
	sett = 0;
	kern = 0;
}







int MainWindowImpl::reinit_vars()
{
	hide();
	return 0;
}






int MainWindowImpl::init()
{
	//	start settings
	sett = new settings(QString("lobanovs"), QString("stokroom"), this);
	connect(sett, SIGNAL( quit() ), this, SIGNAL( quit() ) );
	if( sett->init() )
	{
		qDebug("settings init returns non zero");
		exit(0);
	}
	show();
	return 0;
}












//

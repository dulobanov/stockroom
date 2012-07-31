#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
	: QMainWindow(parent, f)
{
	//	ui init
	setupUi(this);

}







int MainWindowImpl::reinit_vars()
{
	hide();
	if( sett != 0 ) delete sett;
	if( kern != 0 ) delete kern;
}






int MainWindowImpl::init()
{
	//	start settings
	sett = new settings(QString("lobanovs"), QString("stokroom"), this);
	connect(sett, SIGNAL( quit() ), this, SIGNAL( quit() ) );
	if( sett->init() ) exit(0);
	return 0;
}












//

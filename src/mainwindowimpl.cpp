#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
	: QMainWindow(parent, f)
{
	//	ui init
	setupUi(this);
	sett = 0;
	kern = 0;
	init();
	

	test new_test(this);

}




MainWindowImpl::~MainWindowImpl()
{
	reinit_vars();
}





int MainWindowImpl::reinit_vars()
{
	hide();
	if( sett != 0 )
	{
		delete sett;
		sett = 0;
	}
	if( kern != 0 )
	{
		delete kern;
		kern = 0;
	}
	return 0;
}






int MainWindowImpl::init()
{
	//	start settings
	sett = new settings(QString("lobanovs"), QString("stokroom"), this);
	connect(sett, SIGNAL( quit() ), this, SIGNAL( quit() ) );
	if( sett->init() )
	{
		qDebug("Settings init returns non zero");
		logout();
	}

	//	init kern
	QDir u_path;
	if ( sett->get_upath(u_path) )
	{
		QMessageBox::critical(this, QString("Init"), QString("Can't recive user folder."));
		logout();
	}
	kern = new kernel(this);
	if( kern->lock( u_path ) )
	{
		logout();
	}


	show();
	return 0;
}




























//				slots
void MainWindowImpl::logout()
{
	//	delete vars
	reinit_vars();
	init();
}










//

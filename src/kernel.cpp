#include "kernel.h"
//
kernel::kernel( QWidget *prnt )
	: QObject()
{
	parent = prnt;
}



kernel:~kernel()
{

}







int kernel::lock(QDir user_dir)
{
		// is ir present
	QFileInfo ud_info(user_dir);
	if( !ud_info.isDir() )
	{
		QMessageBox::critical(parent, QString("StokRoom"), QString("Wrong user directory.\nProgrm will be closed.") );
		exit(0);
	}

		// is dir locked
	lock_file = QFile( QString(user_dir.path()+"/.lock") );
	if( QFileInfo::exists( lock_file ) )
	{
		int ret = QMessageBox::question(parent, QString("StokRoom"), QString("User directory alredy locked.\nPerhebs same application alredy runing.\nIf you continue it can destruct your data.\nContinue anyway?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
		if( ret == QMessageBox::No ) exit(0);
	}

		// try to open file with write permissions
	if( !lock_file.open(QIODevice::WriteOnly | QIODevice::Text) )
	{
		QMessageBox::critical(parent, QString("StokRoom"), QString("Can't lock user directory.\nProgrm will be closed.") );
		exit(0);
	}

		// write to file date & time
	QDateTime timestamp( QDateTime::currentDateTime() );
	QTextStream out(&lock_file);
	out << timestamp.toString() << "\n";


}



















//





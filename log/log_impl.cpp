#include "log_impl.h"

log_impl::log_impl(QObject *prnt) :
    QFile(prnt)
{
}




log_impl::~log_impl()
{
	save();
}






quint8 log_impl::init(QString dir)
{
	QFileInfo directory( dir );
	if( !directory.isDir() ) return 1;
	if( !directory.isWritable() ) return 2;

	QDateTime date_time( QDateTime::currentDateTime () );
	QString file_name = dir + QString("/") + date_time.toString( QString("yyyy_MM") ) + QString(".log");

	setFileName( file_name );

	if( !open( QIODevice::Append | QIODevice::Text ) ) return 3;
	if( !seek( size() ) ) return 4;
	return 0;
}










quint8 log_impl::save()
{
	if( !isOpen() ) return 0;
	flush();
	close();
	return 0;
}

















//__________________________________________ [ SLOTS ] _____________________________________________


void log_impl::log(QString sender, QString message)
{

	if( !isOpen() ) return;
	QDateTime date_time( QDateTime::currentDateTime () );
	QByteArray data;
	QString tmp;

	data.append( date_time.toString( QString("[ yyyy.MM.dd ddd hh:mm:ss ]: ") ) );
	data.append("\t");
	//	prepeare sender: remove \n & \r
	tmp = sender;
	tmp.replace("\n", " ");
	tmp.replace("\r", " ");
	data.append( tmp );
	data.append("\t\t");
	//	prepeare message
	tmp = message;
	tmp.replace("\n", " ");
	tmp.replace("\r", " ");
	data.append( tmp );
	data.append("\n");
	//	write
	write( data );

	return;
}













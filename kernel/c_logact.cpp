#include "c_logact.h"

c_logact::c_logact(QWidget *prnt) :
    QWidget(prnt)
{
	parent = prnt;
	files = new QVector<files_struct *>;
}



c_logact::~c_logact()
{

}














quint8 c_logact::init( QString usr_dir, QString vrnt, QString slct, QList<QString> old_files )
{
	if( usr_dir == "" )
	{
		emit log( QString( Q_FUNC_INFO ), QString("user directory is empty") );
		return 1;
	}

	//	path init
	QString *fpath = new QString;
	*fpath = usr_dir + "/" + vrnt + "__" + slct;
	//	check is path exists
	QDir wrk_dir( *fpath );
	if( !wrk_dir.exists() )
	{
		if( !wrk_dir.mkpath( *fpath ) )
		{
		emit log( QString( Q_FUNC_INFO ), QString("work irectory don't exists, and it's imposible to create it") );
		return 2;
		}
	}

	//	runtime filename initicialization
	runtime_file = 0;
	QString runtime_ffn = *fpath + "/" + get_runtime_fn();


	QFileInfoList wrk_files = wrk_dir.entryInfoList( QDir::Files | QDir::Readable | QDir::Writable | QDir::NoSymLinks );
	//	load

	QString fn, hash;
	files_struct *f_tmp;

	for(quint16 i = 0; i < wrk_files.size(); ++i)
	{
		//	check is our file
		fn = ( wrk_files.at(i) ).absoluteFilePath();
		if( old_files.indexOf( fn ) == -1 )
		{
			emit log( QString( Q_FUNC_INFO ), QString("file %1 dosn't registered before, will be deleted").arg( fn ) );
			if( !QFile::remove( fn ) ) emit log( QString( Q_FUNC_INFO ), QString("can't delete file %1").arg( fn ) );
			continue;
		}

		//	file is our -> load it
		f_tmp = new files_struct;
		*f_tmp->file_name = fn ;
		f_tmp->descriptor = new ma_log(this, fn);
		if( f_tmp->descriptor->get_hash( &hash ) )
		{
			emit log( QString( Q_FUNC_INFO ), QString("file loading error %1 (can't get hash)").arg( fn ) );
			delete f_tmp;
			continue;
		}
		*f_tmp->hash = hash ;
		*f_tmp->changed = 0;

		//	all loaded add to vector
		files->append( f_tmp );

		//	check is this file our runtime file
		if( fn == runtime_ffn ) runtime_file = f_tmp;
	}

	//	check is runtime file exists
	if( runtime_file == 0 )
	{	//	runtime file dosn't exists need to create
		f_tmp = new files_struct;
		*f_tmp->file_name = runtime_ffn ;
		f_tmp->descriptor = new ma_log(this, runtime_ffn);
		if( f_tmp->descriptor->get_hash( &hash ) )
		{
			emit log( QString( Q_FUNC_INFO ), QString("file loading error %1 (can't get hash of runtime file)").arg( fn ) );
			delete f_tmp;
			return 3;
		}
		*f_tmp->hash = hash ;
		*f_tmp->changed = 0;

		//	all loaded add to vector
		files->append( f_tmp );
		runtime_file = f_tmp;
	}


	return 0;
}
















QString c_logact::get_runtime_fn()
{
	QDateTime date_time( QDateTime::currentDateTime () );
	return date_time.toString( QString("yyyy_MM") ) + QString(".stkm");
}






















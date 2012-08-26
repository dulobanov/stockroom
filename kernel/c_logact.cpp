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














quint8 c_logact::init( QString dir, QMap<QString, QString> old_files )
{
    if( dir == "" )
    {
        emit log( QString( Q_FUNC_INFO ), QString("user directory is empty") );
        return 1;
    }

    //	path init
    QString *fpath = new QString( dir );
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
    QList<QString> good_files = old_files.keys();
    quint32 err_count = 0;

    for(quint16 i = 0; i < wrk_files.size(); ++i)
    {
        //	check is our file
        fn = ( wrk_files.at(i) ).absoluteFilePath();
        if( good_files.indexOf( fn ) == -1 )
        {
            emit log( QString( Q_FUNC_INFO ), QString("file %1 dosn't registered before, it will be deleted").arg( fn ) );
            if( !QFile::remove( fn ) ) emit log( QString( Q_FUNC_INFO ), QString("can't delete file %1").arg( fn ) );
            err_count++;
            continue;
        }

//	initialization o the structure
        //	file is our -> load it
        f_tmp = new files_struct;
        *f_tmp->file_name = fn ;
        f_tmp->descriptor = new ma_log(this, fn);
        if( f_tmp->descriptor->get_hash( &hash ) )
        {
            emit log( QString( Q_FUNC_INFO ), QString("file loading error (can't get hash), filename %1").arg( fn ) );
            delete f_tmp;
            err_count++;
            continue;
        }

        //	check hash
        if( old_files.value( fn ) != hash )
        {
            emit log( QString( Q_FUNC_INFO ), QString("file loading error, hash is wrong, skip file %1").arg( fn ) );
            delete f_tmp;
            err_count++;
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
            err_count++;
            return ++err_count;
        }
        *f_tmp->hash = hash ;
        *f_tmp->changed = 0;

        //	all loaded add to vector
        files->append( f_tmp );
        runtime_file = f_tmp;
    }


    return err_count;
}
















QString c_logact::get_runtime_fn()
{
    QDateTime date_time( QDateTime::currentDateTime () );
    return date_time.toString( QString("yyyy_MM") ) + QString(".stkm");
}












quint8 c_logact::close( QMap<QString, QString> *files_hashes )
{
    if( files_hashes == 0) return 1;

    files_hashes->clear();

    files_struct *f;
    QString ffn, f_hash;
    quint32 err_count = 0;

    for(quint32 i = 0; i < (quint64) files->size(); ++i)
    {
        f = files->at(i);
        ffn = *f->file_name;
        if( f->descriptor->get_hash( &f_hash ) )
        {
            emit log( QString( Q_FUNC_INFO ), QString("can't get hash file skipped, filename %1").arg( ffn ) );
            err_count++;
            continue;
        }
        *f->hash = f_hash;
        *f->changed = 0;
        files_hashes->insert( ffn, f_hash );
    }
    return err_count;
}














quint8 c_logact::add_record(quint64 date, QString direction, quint64 boxes, quint64 items, QString description )
{
    if( runtime_file == 0 )
    {
        emit log( QString( Q_FUNC_INFO ), QString("can't add recor becoase of runtime_file not setted") );
        return 1;
    }

    return runtime_file->descriptor->add_record( date, direction, boxes, items, description );
}

















quint8 c_logact::remove_record( quint64 timestamp, action_record* record )
{
    if( runtime_file == 0 )
    {
        emit log( QString( Q_FUNC_INFO ), QString("can't add recor becoase of runtime_file not setted") );
        return 1;
    }

    return runtime_file->descriptor->remove_record( timestamp, record );
}

















QStringList c_logact::get_file_names()
{
    QStringList fns;

    QStringList fn;

    for(quint64 i = 0; i < (quint64) files->size(); ++i)
    {
        fn = files->at(i)->file_name->split(".") ;
        if( fn.size() != 2 )
        {
            emit log( QString( Q_FUNC_INFO ), QString("Can't split filename: #%1#, more than 2 parts").arg( *files->at(i)->file_name ) );
            continue;
        }

        fns.append( fn.at(0) );
    }

    return fns;
}












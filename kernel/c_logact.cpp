#include "c_logact.h"

c_logact::c_logact(QObject *prnt) :
    QObject(prnt)
{
    parent = prnt;
    files = new QVector<files_struct *>;

    this->id = new QString("");
    this->varity = new QString("");
    this->selection = new QString("");
}



c_logact::~c_logact()
{

}












quint8 c_logact::setVaritySelection(QString varity, QString selection)
{
    if(varity.isEmpty())
    {
        emit log(QString(Q_FUNC_INFO), QString("Varity is empty: #%1#").arg(varity));
        return 1;
    }

    if(selection.isEmpty())
    {
        emit log(QString(Q_FUNC_INFO), QString("Selection is empty: #%1#").arg(selection));
        return 2;
    }

    *this->varity = varity;
    *this->selection = selection;

    return 0;
}













quint8 c_logact::setID(QString id)
{
    if(id.isEmpty())
    {
        emit log(QString(Q_FUNC_INFO), QString("ID is empty: #%1#").arg(id));
        return 1;
    }

    *this->id = id;

    return 0;
}
















quint8 c_logact::init( QString dir, QMap<QString, QString> old_files )
{
    if( dir == "" )
    {
        emit log( QString( Q_FUNC_INFO ), QString("user directory is empty") );
        return 1;
    }

    //	path init
    work_folder = new QString( dir );
    //	check is path exists
    QDir wrk_dir( *work_folder );
    if( !wrk_dir.exists() )
    {
        if( !wrk_dir.mkpath( *work_folder ) )
        {
        emit log( QString( Q_FUNC_INFO ), QString("work irectory don't exists, and it's imposible to create it") );
        return 2;
        }
    }

    //	runtime filename initicialization
    runtime_file = 0;
    QString runtime_ffn = *work_folder + QDir::separator() + get_runtime_fn();


    QFileInfoList wrk_files = wrk_dir.entryInfoList( QDir::Files | QDir::Readable | QDir::Writable | QDir::NoSymLinks | QDir::NoDotAndDotDot );
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

        //	initialization of the structure
        //	file is our -> load it
        f_tmp = new files_struct;
        //f_tmp->varity = this->varity;
        //f_tmp->selection = this->selection;
        f_tmp->file_name = new QString(fn);
        f_tmp->descriptor = new ma_log(this, fn);
        f_tmp->descriptor->setID(*this->id);
        f_tmp->descriptor->setVaritySelection(*this->varity, *this->selection);
        if( f_tmp->descriptor->get_hash( &hash ) )
        {
            emit log( QString( Q_FUNC_INFO ), QString("file loading error (can't get hash), filename %1").arg( fn ) );
            delete f_tmp;
            err_count++;
            continue;
        }

        //add year month
        f_tmp->month_year = new QString(( wrk_files.at(i) ).baseName());

        //	check hash
        if( old_files.value( fn ) != hash )
        {
            emit log( QString( Q_FUNC_INFO ), QString("file loading error, hash is wrong, skip file %1").arg( fn ) );
            delete f_tmp;
            err_count++;
            continue;
        }


        f_tmp->hash = new QString(hash);
        f_tmp->changed = false;

        //	all loaded add to vector
        files->append( f_tmp );

        //	check is this file our runtime file
        if( fn == runtime_ffn ) runtime_file = f_tmp;
    }

    //	check is runtime file exists
    if( runtime_file == 0 )
    {	//	runtime file dosn't exists need to create
        //create file
        QFile rf(runtime_ffn);
        if(!rf.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            emit log( QString( Q_FUNC_INFO ), QString("can't create file: %1").arg( runtime_ffn ) );
            return ++err_count;
        }
        rf.close();
        //init
        f_tmp = new files_struct;
        f_tmp->id = this->id;
        f_tmp->varity = this->varity;
        f_tmp->selection = this->selection;
        f_tmp->file_name = new QString(runtime_ffn);
        f_tmp->descriptor = new ma_log(this, runtime_ffn);
        f_tmp->descriptor->setID(*this->id);
        f_tmp->descriptor->setVaritySelection(*this->varity, *this->selection);
        if( f_tmp->descriptor->get_hash( &hash ) )
        {
            emit log( QString( Q_FUNC_INFO ), QString("file loading error %1 (can't get hash of runtime file)").arg( fn ) );
            delete f_tmp;
            return ++err_count;
        }
        f_tmp->hash = &hash ;
        f_tmp->changed = false;
        f_tmp->month_year = new QString(QDateTime::currentDateTime().toString("yyyy_MM"));

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
        f->hash = new QString(f_hash);
        f->changed = false;
        files_hashes->insert( ffn, f_hash );
    }
    return err_count;
}











files_struct* c_logact::findStructureByDate(quint64 dateTimestamp)
{
    if(dateTimestamp == 0)
    {
        emit log( QString( Q_FUNC_INFO ), QString("Date is empty, find is impossible") );
        return 0;
    }

    QString date = (QDateTime::fromMSecsSinceEpoch(dateTimestamp)).toString("yyyy_MM");

    for(quint64 i = 0; i < (quint64) files->size(); ++i)
    {
        if( (files->at(i))->month_year == date ) return files->at(i);
    }


    emit log( QString( Q_FUNC_INFO ), QString("Structure not founded for timestamp: %1, date: %2").arg(dateTimestamp).arg(date) );
    return 0;

}










quint8 c_logact::addRecord(quint64 date, QString direction, quint64 boxes, quint64 items, QString description )
{
    files_struct *fs;
    if( (fs = this->findStructureByDate(date)) == 0 ) return 1;

    return fs->descriptor->addRecord( date, direction, boxes, items, description );
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

    for(quint64 i = 0; i < (quint64) files->size(); ++i)
    {
        fns.append( *files->at(i)->month_year );
    }

    return fns;
}










QVector<action_record> c_logact::get_activity(QString year_month)
{

    QVector<action_record> result;

    for(quint64 i = 0; i < (quint64) files->size(); ++i)
    {
        if( (year_month == tr("All")) || (year_month == files->at(i)->month_year) )
        {
            result += files->at(i)->descriptor->get_activity();
        }
    }

    return result;
}















files_struct* c_logact::initializeMonthInstance(quint64 timestamp)
{

    if(!this->findStructureByDate(timestamp))
    {
        emit log( QString( Q_FUNC_INFO ), QString("So file alredy exists") );
        return 0;
    }

    QString hash;
    QString ffn = *work_folder + QDir::separator() + QString(QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN));

    files_struct *f_tmp = new files_struct;
    f_tmp->id = this->id;
    f_tmp->varity = this->varity;
    f_tmp->selection = this->selection;
    f_tmp->file_name = new QString(ffn);
    f_tmp->descriptor = new ma_log(this, ffn);
    f_tmp->descriptor->setID(*this->id);
    f_tmp->descriptor->setVaritySelection(*this->varity, *this->selection);
    if( f_tmp->descriptor->get_hash( &hash ) )
    {
        emit log( QString( Q_FUNC_INFO ), QString("file loading error %1 (can't get hash of runtime file)").arg( ffn ) );
        delete f_tmp;
        return 0;
    }
    f_tmp->hash = &hash ;
    f_tmp->changed = false;
    f_tmp->month_year = new QString(QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN));

    //	all loaded add to vector
    files->append( f_tmp );
    return f_tmp;
}








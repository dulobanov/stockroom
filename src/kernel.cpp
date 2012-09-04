#include "kernel.h"
//
kernel::kernel(QWidget *prnt) : QObject()
{
    parent = prnt;
    work_dir = new QString;
    selVariant = new QString();
    selSelection = new QString();
    selMonth = new QString();
}



kernel::~kernel()
{
    //	disable lock file
    unlock();
}







int kernel::lock(QDir user_dir)
{

        // is dir locked
    lock_file = new QFile( QString(user_dir.path()) + QString("/.lock") );
    if( QFile::exists( lock_file->fileName() ) )
    {
        int ret = QMessageBox::question(parent, QString("StokRoom"), QString("User directory alredy locked.\nPerhebs same application alredy runing.\nIf you continue it can destruct your data.\nContinue anyway?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if( ret == QMessageBox::No ) exit(0);
    }

        // try to open file with write permissions
    if( !lock_file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QMessageBox::critical(parent, QString("StokRoom"), QString("Can't lock user directory.\nProgrm will be closed.") );
        exit(0);
    }

        // write to file date & time
    QDateTime timestamp( QDateTime::currentDateTime() );
    QTextStream out(lock_file);
    out << timestamp.toString( QString("ddd dd MMMM yyyy  hh:mm:ss") ) << "\n";
    lock_file->flush();

    //	save dir to user_dir
    *work_dir = user_dir.absolutePath();
    summary = new c_summary(parent, new QDir(user_dir));
    connect(summary, SIGNAL(log(QString,QString)), this, SIGNAL(log(QString,QString)));
    summary->load();

    return 0;
}



int kernel::unlock()
{
    //	close file
    if( lock_file->isOpen() )
    {
        lock_file->flush();
        lock_file->close();
    }

    //	remove file
    if( lock_file->exists() )
        if( !QFile::remove( lock_file->fileName() ) )
            QMessageBox::information(parent, QString("Quit"), QString("Something wrong: program can't remove lock file.\nPlease do it mannualy.\nRemove .lock file from your data directory"));

    return 0;
}








quint8 kernel::addItemRecord(QString varity, QString selection, quint64 box_count, quint64 item_count, QString description, bool set_as_default)
{
    quint8 ret = summary->addItemRecord(varity, selection, box_count, item_count, description, set_as_default);
    if(ret > 0) return ret;
    this->sendUpdates();
    return 0;
}












quint8 kernel::addActionToItem(QString itemId, QString direction, quint64 dateTime, quint64 boxes, quint64 items, QString description)
{

    if(direction == "l")
    {
        if(summary->load_item(itemId, dateTime, boxes, items, description)) return 1;
    }
    else
    {
        if(direction == "u")
        {
            if(summary->unload_item(itemId, dateTime, boxes, items, description)) return 2;
        }
        else
        {
            emit log(QString(Q_FUNC_INFO), QString("Unknown direction #%1#").arg(direction));
            return 3;
        }
    }

    this->sendUpdates();
    return 0;
}








quint8 kernel::setActivitySelection(QString variant, QString selection, QString month)
{
    *selVariant = variant;
    *selSelection = selection;
    *selMonth = month;
    this->sendUpdates();
    return 0;
}









QStringList kernel::getSelectionsFor(QString varity)
{
    return summary->getSelectionsFor(varity);
}






QStringList kernel::getVaritys()
{
    return summary->getVaritys();
}








void kernel::sendUpdates()
{
    emit updateSummaryTable(summary->get_records());
    emit updateActivityTable(summary->get_activity(*selVariant, *selSelection, *selMonth));
}














//





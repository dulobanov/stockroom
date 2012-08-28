#include "kernel.h"
//
kernel::kernel() : QObject()
{
    work_dir = new QString;
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















//





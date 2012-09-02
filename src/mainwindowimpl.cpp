#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    //	ui init

    setupUi(this);
    //initGUI();
    sett = 0;
    kern = 0;
    log = 0;
    init();

//	for test running
//	test new_test(this);
    initGUI();
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
        exit(1);
    }

    //	initialization of log class
    log = new log_impl(this);
    QString log_path;
    if( sett->get_log_path( &log_path ) )
    {
        qDebug("MainWindowImpl::init can't get log path");
        exit(1);
    }
    if(log->init( log_path )) exit(1);
    connect(sett, SIGNAL( log(QString, QString) ), log, SLOT( log(QString, QString) ) );
    connect(this, SIGNAL( log_message(QString, QString) ), log, SLOT( log(QString, QString) ) );


    //	init kernel
    QDir u_path;
    if ( sett->get_upath(u_path) )
    {
        QMessageBox::critical(this, QString("Init"), QString("Can't recive user folder."));
        exit(1);
    }
    kern = new kernel(this);
    connect(kern, SIGNAL( log(QString, QString) ), log, SLOT( log(QString, QString) ) );
    if( kern->lock( u_path ) )
    {
        exit(1);
    }

    show();
    return 0;
}
















quint8 MainWindowImpl::initGUI()
{
    //show();
    return 0;
}

















//				slots
void MainWindowImpl::logout()
{
    //	delete vars
    reinit_vars();
    init();
}











void MainWindowImpl::addItem()
{
    add_item addIt(this);
    connect(&addIt, SIGNAL(log(QString,QString)), log, SLOT(log(QString,QString)));
    addIt.exec();
    qDebug("to1 kern");
    QString varity, selection, description;
    quint64 box, item;
    bool save;
    qDebug("to2 kern");
    if(addIt.getValues(&varity, &selection, &box, &item, &save, &description)) return;
    qDebug("to kern");
    kern->addItem(varity, selection, box, item, description, save);
}






void MainWindowImpl::loadItem()
{

}






void MainWindowImpl::unloadItem()
{

}





//

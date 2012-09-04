#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QDebug>


#include "ui_mainwindow.h"
#include "settings.h"
#include "kernel.h"
#include "test/test.h"
#include "log/log_impl.h"
#include "mainwin/tables/summarytable.h"
#include "dialogs/add_item/add_item.h"
#include "dialogs/load_item/load_item.h"

//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
    MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
    ~MainWindowImpl();
    int init();
    quint8 initGUI();





private:

    //	VARS
    settings *sett;
    kernel *kern;
    log_impl *log;


    //	FUNCTIONS
    int reinit_vars();









signals:
    void quit();
    void log_message(QString sender, QString message);











public slots:
    void logout();
    void addItem();
    void loadItem();
    void unloadItem();







};
#endif





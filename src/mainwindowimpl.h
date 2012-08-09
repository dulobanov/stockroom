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

//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~MainWindowImpl();
	int init();





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







};
#endif





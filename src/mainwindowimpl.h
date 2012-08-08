#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QDebug>
#include "ui_mainwindow.h"
#include "settings.h"
#include "kernel.h"
#include "test/test.h"
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



	//	FUNCTIONS
	int reinit_vars();









signals:
	void quit();











public slots:
	void logout();







};
#endif





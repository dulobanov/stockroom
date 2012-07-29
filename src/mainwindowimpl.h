#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "settings.h"
#include "kernel.h"
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	int init();





private:

	//	VARS
    //settings sett;
	kernel kern;



	//	FUNCTIONS









signals:
	void quit();











private slots:
};
#endif





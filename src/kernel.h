#ifndef KERNEL_H
#define KERNEL_H
//
#include <QWidget>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QDateTime>
#include <QTextStream>
//
class kernel : public QWidget
{
Q_OBJECT
public:
	kernel( QWidget *prnt = 0 );
	~kernel();

	int lock(QDir user_dir);
    int unlock();





private:

	//	VARS
	QWidget *parent;
    QFile *lock_file;





	//	FUNCTIONS






signals:
    void logout();




};
#endif

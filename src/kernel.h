#ifndef KERNEL_H
#define KERNEL_H
//
#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QDateTime>
#include <QTextStream>
//
class kernel : public QObject
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

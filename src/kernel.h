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
    kernel();
    ~kernel();

    int lock(QDir user_dir);
    int unlock();





private:

    //	VARS
    QWidget *parent;
    QFile *lock_file;
    QString *work_dir;





    //	FUNCTIONS






signals:
    void logout();
    void log(QString sender, QString message);




};
#endif

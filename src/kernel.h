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
#include "kernel/c_summary.h"

//
class kernel : public QObject
{
Q_OBJECT
public:
    kernel(QWidget *prnt = 0);
    ~kernel();

    int lock(QDir user_dir);
    int unlock();
    quint8 addItem( QString varity = "", QString selection = "", quint64 box_count = 0, quint64 item_count = 0, QString description = "", bool set_as_default = false);





private:

    //	VARS
    QWidget *parent;
    QFile *lock_file;
    QString *work_dir;
    c_summary *summary;





    //	FUNCTIONS






signals:
    void logout();
    void log(QString sender, QString message);




};
#endif

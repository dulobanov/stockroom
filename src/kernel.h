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
#include <QStringList>
#include <QDateTimeEdit>
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
    quint8 addItemRecord( QString varity = "", QString selection = "", quint64 box_count = 0, quint64 item_count = 0, QString description = "", bool set_as_default = false);
    quint8 addActionToItem(QString itemId = "", QString direction = "", quint64 dateTime = 0, quint64 boxes = 0, quint64 items = 0, QString description = "");
    QStringList getSelectionsFor(QString varity = "");
    QStringList getVaritys();
    summary_record* getRecordByID(QString id = "");
    quint8 setActivitySelection(QString variant = "", QString selection = "", QString month = "");
    quint8 setReportSelection(QString variant = "", QString selection = "", QString month = "");
    quint8 getRoundsFor(QString variant = "", QString selection = "", QString month = "", QStringList *var = 0, QStringList *sel = 0, QStringList *mth = 0);




private:

    //	VARS
    QWidget *parent;
    QFile *lock_file;
    QString *work_dir;
    c_summary *summary;

    QString *selVariant, *selSelection, *selMonth;
    QString *repVariant, *repSelection, *repMonth;




    //	FUNCTIONS
    void sendUpdates();





signals:
    void logout();
    void log(QString sender, QString message);
    void updateSummaryTable(QVector<summary_record*>* updates);
    void updateActivityTable(QVector<action_record> updates);
    void updateReportTable(QVector<action_record> updates);





};
#endif

#ifndef C_SUMMARY_H
#define C_SUMMARY_H

#include <QFile>
#include <QDateTime>
#include <QMap>
#include <QVector>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QCryptographicHash>

#include "c_logact.h"

#define C_SUMMARY_DELIMETER_1 ":"
#define C_SUMMARY_DELIMETER_2 "!"
#define C_SUMMARY_DELIMETER_3 "="

struct summary_record
{
    QString id;
    QString variant;
    quint64 selection;
    quint64 box_count;
    quint64 item_count;
    QString created;
    QString closed;
    quint64 saved_box_count;
    quint64 saved_item_count;
    QMap<QString, QString> log_activities;
    QString hash;
    QString description;
    c_logact *d;
    bool changed;
};



class c_summary : public QFile
{
    Q_OBJECT
public:
    explicit c_summary(QWidget *prnt = 0, QDir *u_d = 0);
    ~c_summary();
    quint8 save();
    quint8 load_item(QString variant = "", quint16 selection = 0, quint64 date = 0, QString direction = "", quint64 boxes = 0, quint64 items = 0, QString description = "");
    quint8 unload_item(QString variant = "", quint16 selection = 0, quint64 timestamp = 0);
    QVector<summary_record *> get_records();
    QVector<action_record> get_activity( QString variant = "", QString selection = "all", QString year_month = "" );
    quint8 get_rounds( QString variant = "", QString selection = "", QString month = "", QVector<QString> *var = 0, QVector<QString> *sel = 0, QVector<QString> *mth = 0 );
    quint8 add_record( QString varity = "", QString selection = "", quint64 box_count = 0, quint64 item_count = 0, QString description = "", bool set_as_default = false);
    quint8 load();


private:

    //	vars
    QWidget *parent;
//    QVector<c_logact *> *items; // object for records
    QVector<summary_record *> *records;
    QDir *data_dir;
    QFile *summary;
    bool is_saved;
    summary_record* find(QString variant, quint16 selection);




    //	functions

    QString get_hash(summary_record rec);
    quint8 save_summary();




signals:
    void logout();
    void log( QString sender, QString message );

public slots:

};

#endif // C_SUMMARY_H

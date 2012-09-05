#ifndef C_LOGACT_H
#define C_LOGACT_H

#include <QWidget>
#include <QVector>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFile>
#include <QDir>
#include <QDateTime>

#include "kernel/ma_log.h"

#define CURRENT_FILE_NAME_PATTERN "yyyy_MM"

struct files_struct
{
    ma_log *descriptor;
    QString *file_name;
    QString *month_year;
    QString *hash;
    bool *changed;
    QString *varity;
    QString *selection;
};







class c_logact : public QObject
{
    Q_OBJECT
public:
    explicit c_logact(QObject *prnt = 0);
    ~c_logact();

    quint8 init( QString dir = "", QMap<QString, QString> old_files = QMap<QString, QString>() );
    quint8 addRecord(quint64 date = 0, QString direction = "", quint64 boxes = 0, quint64 items = 0, QString description = "" );
    quint8 remove_record(quint64 timestamp = -1, action_record* record = 0);
    quint8 close( QMap<QString, QString> *files_hashes = 0 );
    QStringList get_file_names();
    QVector<action_record> get_activity(QString year_month = "");
    files_struct* findStructureByDate(quint64 date = 0);
    quint8 setVaritySelection(QString varity = "", QString selection = "");





private:
    //	VARS
    QObject *parent;
    QString *varity;
    QString *selection;
    QString *user_dir;
    QString *work_folder;
    QVector<files_struct *> *files;
    files_struct *runtime_file;
    qint64 *boxes_count, *items_count;



    //	FUNCTIONS
    QString get_runtime_fn();





signals:
    void log(QString sender, QString message);




public slots:

};

#endif // C_LOGACT_H

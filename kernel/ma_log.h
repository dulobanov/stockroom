#ifndef MA_LOG_H
#define MA_LOG_H

#include <QFile>
#include <QWidget>
#include <QVector>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QByteArray>
#include <QCryptographicHash>


#define MA_LOG_DELIMETER ":"

struct action_record
{
    quint64 timestamp;
    quint64 date_time;
    QString direction;
    quint64 boxes;
    quint64 items;
    QString description;
    QString *id;
    QString *varity;
    QString *selection;
};

class ma_log : public QFile
{
    Q_OBJECT
public:
    explicit ma_log(QObject *prnt = 0, QString ffn = "");
    ~ma_log();

    quint8 init();
    quint8 addRecord(quint64 date = 0, QString direction = "", quint64 boxes = 0, quint64 items = 0, QString description = "" );
    quint8 remove_record(quint64 timestamp = -1, action_record* a_rec = 0);
    quint8 save();
    quint8 find_record(quint64 timestamp = 0, quint64 *index = 0);
    quint8 get_hash( QString *hash);
    quint8 get_motion( qint64 *boxes = 0, qint64 *items = 0 );
    QVector<action_record> get_activity();
    quint8 setVaritySelection(QString varity = "", QString selection = "");
    quint8 setID(QString id = "");



private:
        //	VARS
    bool *added_record;
    bool *modified;
    bool *data_loaded;
    QVector <quint64> *unwriten_records; //	inserted timestamp in miliseconds
    QString *id;
    QString *varity;
    QString *selection;

    //	file
    QVector <action_record *> *file_records;
    qint64 *ma_boxes_activity, *ma_items_activity;



        //	FUNCTIONS
    quint8 get_line( quint64 index = 0, QString *line = 0 );
    quint8 get_index_by_timestamp( quint64 timestamp = 0, quint64* index = 0 );





signals:
    void log_message(QString sender, QString message);




public slots:

};

#endif // MA_LOG_H

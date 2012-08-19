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
#include <QCryptographicHash>

#include "c_logact.h"

#define C_SUMMARY_DELIMETER_1 ":"
#define C_SUMMARY_DELIMETER_2 "!"
#define C_SUMMARY_DELIMETER_3 "="

struct summary_record
{
	QString id;
	QString variant;
	quint16 selection;
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



private:

	//	vars
	QWidget *parent;
	QVector<c_logact *> *items; // object for records
	QVector<summary_record *> *records;
	QDir *data_dir;
	QFile *summary;
	bool is_saved;




	//	functions
	uint load();
	QString get_hash(summary_record rec);
	quint8 save_summary();




signals:
	void logout();
	void log( QString sender, QString message );

public slots:

};

#endif // C_SUMMARY_H

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

#include "c_logact.h"

struct summary_record
{
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
};



class c_summary : public QFile
{
    Q_OBJECT
public:
    explicit c_summary(QWidget *prnt = 0, QDir *u_d = 0);
	~c_summary();
	quint8 close_files();



private:

	//	vars
	QWidget *parent;
	QVector<c_logact *> *items; // object for records
	QVector<summary_record *> *records;
	QDir *data_dir;
	QFile *summary;




	//	functions
	uint load();
	bool is_saved;




signals:
	void logout();

public slots:

};

#endif // C_SUMMARY_H

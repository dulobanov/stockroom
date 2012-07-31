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


struct summary_record
{
	QString variant;
	uint selection;
	quint64 box_count;
	quint64 item_count;
	uint created;
	uint closed;
	quint64 saved_box_count;
	quint64 saved_item_count;
	QMap<QString, QString> log_activities;
	QString hash;
};



class c_summary : public QFile
{
    Q_OBJECT
public:
    explicit c_summary(QObject *parent = 0, QDir *u_d = 0);




private:

	//	vars
    //QMap<QString, *c_logact> items; // object for records
	QMap<QString, summary_record> records; // at summary file
	QDir data_dir;
	QFile summary;




	//	functions
	uint load();
	bool is_saved;




signals:

public slots:

};

#endif // C_SUMMARY_H

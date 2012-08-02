#ifndef MA_LOG_H
#define MA_LOG_H

#include <QFile>
#include <QWidget>
#include <QVector>
#include <QTextStream>
#include <QString>
#include <QStringList>

class ma_log : public QFile
{
    Q_OBJECT
public:
	explicit ma_log(QWidget *prnt = 0, QString path = "", QString fn = "");
	~ma_log();

	quint8 init();



private:
	bool *changed;

	//	file
	QVector <quint64> *f_time, *f_boxes, *f_items;
	QVector <QString> *f_direction, *f_description;
	quint64 *ma_boxes_activity, *ma_items_activity;

signals:

public slots:

};

#endif // MA_LOG_H

#include "ma_log.h"

ma_log::ma_log(QWidget *prnt, QString path, QString fn) : QFile(prnt)
{
	setFileName(path + QString("/") + fn);
	*changed = new bool(0);
	f_time = new QVector<quint64>;
	f_direction = new QVector<QString>;
	f_boxes = new QVector<quint64>;
	f_items = new QVector<quint64>;
	f_description = new QVector<QString>;
	ma_boxes_activity = new quint64(0);
	ma_items_activity = new quint64(0);
}





quint8 ma_log::init()
{
	if( !exists() ) return 1;

	if( !open( QIODevice::ReadWrite ) ) return 2;

	QString line;
	QStringList elements;
	QTextStream in(this);
	quint64 rec_num = 0;
	bool ok;
	quint64 tmp_time, tmp_boxes, tmp_items;
	QString tmp_direction;
	while( !in.atEnd() )
	{
		line = in.readLine();
		//	split line
		elements = line.split( QString(":") );

		if (elements.size() < 4)
		{
			qDebug("ma_log::init line skipped due to elements count");
			continue;
		}

		//	adding elements
		tmp_time = elements[0].toULongLong(&ok);
		if(!ok)	{	qDebug("ma_log::init line skipped due to time conversion"); continue;}
		tmp_direction = elements[1];
		if( ( tmp_direction != "l" ) && ( tmp_direction != "u" ) )	{	qDebug("ma_log::init line skipped due to wrong direction"); continue;}
		tmp_boxes = elements[2].toULongLong(&ok);
		if(!ok)	{	qDebug("ma_log::init line skipped due to boxes conversion"); continue;}
		tmp_items = elements[3].toULongLong(&ok);
		if(!ok)	{	qDebug("ma_log::init line skipped due to items conversion"); continue;}
		//	conversion complete push in vectors
		f_time->insert( rec_num, tmp_time);
		f_direction->insert( rec_num, tmp_direction);
		f_boxes->insert( rec_num, tmp_boxes );
		f_items->insert(rec_num, tmp_items );
		f_description->insert( rec_num, elements[4] );
		if( tmp_direction == "l" )
		{
			*ma_boxes_activity += tmp_boxes;
			*ma_items_activity += tmp_items;
		}
		else
		{
			*ma_boxes_activity -= tmp_boxes;
			*ma_items_activity -= tmp_items;
		}

		rec_num++;
	}


	return 1;
}













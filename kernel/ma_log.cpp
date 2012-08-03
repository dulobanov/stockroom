#include "ma_log.h"

ma_log::ma_log(QWidget *prnt, QString path, QString fn) : QFile(prnt)
{
	setFileName(path + QString("/") + fn);
	added_record = new bool(0);
	modified = new bool(0);
	unwriten_records = new QVector<quint64>;
	file_records = new QVector<action_record *>;
	ma_boxes_activity = new quint64(0);
	ma_items_activity = new quint64(0);
}





quint8 ma_log::init()
{
	if( !open( QIODevice::ReadWrite | QIODevice::Text ) ) return 2;

	QString line;
	QStringList elements;
	QTextStream in(this);
	bool ok;
	action_record *record;
	while( !in.atEnd() )
	{
		record = new action_record;
		line = in.readLine().trimmed();
		if( line.size() == 0 ) continue;
		//	split line
		elements = line.split( QString(MA_LOG_DELIMETER) );

		if (elements.size() < 5)
		{
			qDebug("ma_log::init line skipped due to elements count");
			continue;
		}

		//	adding elements
	//	timestamp
		record->timestamp = elements[0].toULongLong(&ok);
		if(!ok)	{	qDebug("ma_log::init line skipped due to time conversion"); delete record; continue;}
	//	date & time (stamp)
		record->date_time = elements[1].toULongLong(&ok);
		if(!ok)	{	qDebug("ma_log::init line skipped due to time conversion"); delete record; continue;}
	//	direction
		if( ( elements[2] != "l" ) && ( elements[2] != "u" ) )	{	qDebug("ma_log::init line skipped due to wrong direction"); delete record; continue;}
		record->direction = elements[2];
	//	box count
		record->boxes = elements[3].toULongLong(&ok);
		if(!ok)	{	qDebug("ma_log::init line skipped due to boxes conversion"); delete record; continue;}
	//	item count
		record->items = elements[4].toULongLong(&ok);
		if(!ok)	{	qDebug("ma_log::init line skipped due to items conversion"); delete record; continue;}
	//	description
		record->description = elements[5];

		if( record->direction == "l" )
		{
			*ma_boxes_activity += record->boxes;
			*ma_items_activity += record->items;
		}
		else
		{
			*ma_boxes_activity -= record->boxes;
			*ma_items_activity -= record->items;
		}

		file_records->append( record );

	}

	close();
	return 0;
}







quint8 ma_log::add_record( quint64 date, QString direction, quint64 boxes, quint64 items, QString description )
{
	if( ( direction != "l" ) && ( direction != "u" ) ) return 1;
	if ( date == 0 ) return 1;

	quint64 timestamp = QDateTime::currentMSecsSinceEpoch();

	if( direction == "l" )
	{
		*ma_boxes_activity += boxes;
		*ma_items_activity += items;
	}
	else
	{
		*ma_boxes_activity -= boxes;
		*ma_items_activity -= items;
	}

	//	create item
	action_record *record = new action_record;

	//	fill
	record->timestamp = timestamp;
	record->date_time = date;
	record->direction = direction;
	record->boxes = boxes;
	record->items = items;
	record->description = description;


	//	insert item
	file_records->append( record );

	*added_record = 1;
	unwriten_records->append( timestamp );

	return 0;
}












quint8 ma_log::save()
{
	if ( *modified )
	{
		QByteArray ch_arr;
		QString line;
		if( !open( QIODevice::WriteOnly | QIODevice::Truncate ) ) return 1;
		for( quint64 i = 0; i < (quint64) file_records->size(); ++i )
		{
			if( get_line( i, &line ) ) return 1;
			ch_arr = line.toUtf8();
			write( ch_arr );
		}
	}
	return 0;
}


quint8 ma_log::get_line( quint64 index, QString *line )
{
	if ( index >= (quint64) file_records->size() ) return 1;

	line->clear();

	action_record *record = file_records->at(index);

	//	concotenate data
	line->append( QString::number( record->timestamp ) );
	line->append(MA_LOG_DELIMETER);
	line->append( QString::number( record->date_time ) );
	line->append(MA_LOG_DELIMETER);
	line->append( record->direction );
	line->append(MA_LOG_DELIMETER);
	line->append( QString::number( record->boxes ) );
	line->append(MA_LOG_DELIMETER);
	line->append( QString::number( record->items ) );
	line->append(MA_LOG_DELIMETER);
	line->append( record->description );

	return 0;
}





















quint8 ma_log::find_record(quint64 timestamp, quint64 *index)
{
	if( timestamp == 0 ) return 1;

	for( quint64 i = 0; i < (quint64) file_records->size(); ++i )
	{
		if( (file_records->at(i))->timestamp == timestamp )
		{
			*index = i;
			return 0;
		}
	}
	return 2;
}












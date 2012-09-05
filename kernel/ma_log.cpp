#include "ma_log.h"

ma_log::ma_log(QObject *prnt, QString ffn) : QFile(prnt)
{
    setFileName( ffn );
    added_record = new bool(0);
    modified = new bool(0);
    data_loaded = new bool(0);
    unwriten_records = new QVector<quint64>;
    file_records = new QVector< action_record *>;
    ma_boxes_activity = new qint64(0);
    ma_items_activity = new qint64(0);

    this->varity = new QString("");
    this->selection = new QString("");
}








ma_log::~ma_log()
{
    save();
}











quint8 ma_log::setVaritySelection(QString varity, QString selection)
{
    if(varity.isEmpty())
    {
        emit log_message(QString(Q_FUNC_INFO), QString("Varity is empty: #%1#").arg(varity));
        return 1;
    }

    if(selection.isEmpty())
    {
        emit log_message(QString(Q_FUNC_INFO), QString("Selection is empty: #%1#").arg(selection));
        return 2;
    }

    *this->varity = varity;
    *this->selection = selection;

    return 0;
}











quint8 ma_log::init()
{
    if( *data_loaded == 1) return 0;
    if( !open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("can't open file: ") + fileName() );
        return 2;
    }

    QString line;
    QStringList elements;
    QTextStream in(this);
    bool ok;
    action_record *record;
    while( !in.atEnd() )
    {
        record = new action_record;
        record->varity = this->varity;
        record->selection = this->selection;
        line = in.readLine().trimmed();
        if( line.size() == 0 ) continue;
        //	split line
        elements = line.split( QString(MA_LOG_DELIMETER) );

        if (elements.size() < 5)
        {
            emit log_message( QString( Q_FUNC_INFO ), QString("line skipped due to elements count: ") + line );
            continue;
        }

        //	adding elements
    //	timestamp
        record->timestamp = elements[0].toULongLong(&ok);
        if(!ok)	{	emit log_message( QString( Q_FUNC_INFO ), QString("line skipped due to time conversion: ") + line ); delete record; continue;}
    //	date & time (stamp)
        record->date_time = elements[1].toULongLong(&ok);
        if(!ok)	{	emit log_message( QString( Q_FUNC_INFO ), QString("line skipped due to time conversion: ") + line ); delete record; continue;}
    //	direction
        if( ( elements[2] != "l" ) && ( elements[2] != "u" ) )	{	emit log_message( QString( Q_FUNC_INFO ), QString("line skipped due to wrong direction: ") + line ); delete record; continue;}
        record->direction = elements[2];
    //	box count
        record->boxes = elements[3].toULongLong(&ok);
        if(!ok)	{	emit log_message( QString( Q_FUNC_INFO ), QString("line skipped due to boxes conversion: ") + line ); delete record; continue;}
    //	item count
        record->items = elements[4].toULongLong(&ok);
        if(!ok)	{	emit log_message( QString( Q_FUNC_INFO ), QString("line skipped due to items conversion: ") + line ); delete record; continue;}
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

    *data_loaded = 1;
    close();
    return 0;
}







quint8 ma_log::addRecord( quint64 date, QString direction, quint64 boxes, quint64 items, QString description )
{
    if( init() )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("Fail on init file log activity: ") + fileName() );
        return 1;
    }

    if( ( direction != "l" ) && ( direction != "u" ) ) return 1;
    if ( date == 0 ) return 1;

    quint64 tmp;
    quint64 timestamp = QDateTime::currentMSecsSinceEpoch();
    while( !get_index_by_timestamp( timestamp, &tmp ) )
    {
        usleep(1000);
        timestamp = QDateTime::currentMSecsSinceEpoch();
    }

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
    record->varity = this->varity;
    record->selection = this->selection;
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













quint8 ma_log::remove_record( quint64 timestamp, action_record* a_rec )
{
    if( init() )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("Fail on init file log activity: ") + fileName() );
        return 1;
    }

    QString line;
    action_record record;
    for( quint64 i = 0; i < (quint64) file_records->size(); ++i )
    {
        if( timestamp == (file_records->at(i))->timestamp )
        {
            record = *(file_records->at(i));
            if( record.direction == "l")
            {
                *ma_boxes_activity -= record.boxes;
                *ma_items_activity -= record.items;
            }
            else
            {
                *ma_boxes_activity += record.boxes;
                *ma_items_activity += record.items;
            }
            get_line(i, &line);
            emit log_message( QString( Q_FUNC_INFO ), QString("delited record: ") + line );
            a_rec = file_records->at( i );
            file_records->remove( i );
            *modified = 1;
            return 0;
        }
    }

    return 10;
}












quint8 ma_log::save()
{
    if ( *modified )
    {
        QByteArray ch_arr;
        QString line;
        if( !open( QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text ) )
        {
            emit log_message( QString( Q_FUNC_INFO ), QString("can't open file for overwrite") );
            close();
            return 1;
        }
        for( quint64 i = 0; i < (quint64) file_records->size(); ++i )
        {
            if( get_line( i, &line ) )
            {
                emit log_message( QString( Q_FUNC_INFO ), QString("can't get line from record with timestamp: ")+QString::number( (file_records->at(i))->timestamp ) );
                close();
                return 2;
            }
            ch_arr = line.toUtf8();
            ch_arr.append( "\n" );
            write( ch_arr );
        }
        *modified = 0;
        *added_record = 0;
        close();
        return 0;
    }

    if( *added_record )
    {
        QByteArray ch_arr;
        QString line;
        //	open
        if( !open( QIODevice::Append | QIODevice::Text ) )
        {
            emit log_message( QString( Q_FUNC_INFO ), QString("can't open ile or append") );
            return 3;
        }
        //	go to end o file
        if( !seek( size() ) )
        {
            emit log_message( QString( Q_FUNC_INFO ), QString("can't go to end of ile for append records") );
            close();
            return 4;
        }

        QVector<quint64> recorded;
        quint64 timestamp;
        qint64 index;
        for( quint64 i = 0; i < (quint64) file_records->size(); ++i )
        {
            timestamp = (file_records->at(i))->timestamp;
            index = unwriten_records->indexOf( timestamp );
            if( index == -1 ) continue;
            if( recorded.indexOf( timestamp ) != -1 )
            {
                emit log_message( QString( Q_FUNC_INFO ), QString("there ara more than one message with same timestamp skip") );
                unwriten_records->remove( index );
                continue;
            }
            unwriten_records->remove(index);

            if( get_line( i, &line ) )
            {
                emit log_message( QString( Q_FUNC_INFO ), QString("can't get line from record with timestamp: ")+QString::number( (file_records->at(i))->timestamp ) );
                continue;
            }

            ch_arr = line.toUtf8();
            ch_arr.append( "\n" );
            write( ch_arr );
            recorded.append( timestamp );
        }

        if( unwriten_records->size() != 0 )
        {
            emit log_message( QString( Q_FUNC_INFO ), QString("ERROR: not all records are writen.") );
            close();
            return 5;
        }

        *modified = 0;
        *added_record = 0;
        close();
        return 0;
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














quint8 ma_log::get_index_by_timestamp( quint64 timestamp, quint64* index )
{
    for( quint64 i = 0; i < (quint64) file_records->size(); ++i)
    {
        if( (file_records->at(i))->timestamp == timestamp )
        {
            *index = i;
            return 0;
        }
    }
    return 1;
}













quint8 ma_log::find_record(quint64 timestamp, quint64 *index)
{
    if( init() )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("Fail on init file log activity: ") + fileName() );
        return 1;
    }

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

















quint8 ma_log::get_hash( QString *hash)
{
    if( init() )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("Fail on init file log activity: ") + fileName() );
        return 1;
    }

    hash->clear();
    if( save() ) return 3;

    if( !exists() )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("file not exists, filename: ") + fileName() );
        return 1;
    }

    if( !open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("can't open file: ") + fileName() );
        return 2;
    }

    QByteArray file_data = readAll();
    close();
    QByteArray md5 = QCryptographicHash::hash( file_data, QCryptographicHash::Md5 );
    file_data.append( md5 );

    *hash = ( QCryptographicHash::hash( file_data, QCryptographicHash::Sha1 ) ).toHex();
    return 0;
}





















quint8 ma_log::get_motion( qint64 *boxes, qint64 *items )
{
    if( init() )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("Fail on init file log activity: ") + fileName() );
        return 1;
    }

    if( *data_loaded == 0 )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("data not loaded, no motion yet") );
        return 1;
    }

    *boxes = *ma_boxes_activity;
    *items = *ma_items_activity;

    return 0;
}












QVector<action_record> ma_log::get_activity()
{
    QVector<action_record> ret;
    if( init() )
    {
        emit log_message( QString( Q_FUNC_INFO ), QString("Fail on init file log activity: ") + fileName() );
        return ret;
    }

    for(quint64 i = 0; i < (quint64) file_records->size(); ++i)
    {
        ret.append( *file_records->at(i) );
    }

    return ret;
}











#include "c_summary.h"

c_summary::c_summary(QWidget *prnt, QDir *u_d) :
    QFile(prnt)
{
    data_dir = u_d;
    records = new QVector<summary_record *>;
    parent = prnt;
}


c_summary::~c_summary()
{
    save();
}









quint8 c_summary::save()
{
    //	step by step close
    for(quint32 i = 0; i < (quint32) records->size(); ++i)
    {
        (records->at(i))->d->close( &(records->at(i))->log_activities );
    }
    save_summary();
    return 0;
}











QString c_summary::get_hash(summary_record rec)
{
    QByteArray tmp;
    tmp.append(rec.id);
    tmp.append(rec.variant);
    tmp.append(rec.selection);
    tmp.append(rec.item_count);
    tmp.append(rec.box_count);

    QByteArray h1 = QCryptographicHash::hash(tmp, QCryptographicHash::Sha1);

    h1.append(rec.box_count);
    h1.append(rec.item_count);
    h1.append(rec.created);
    h1.append(rec.closed);
    h1.append(rec.saved_box_count);
    h1.append(rec.saved_item_count);
    h1.append(rec.description);

return QString( QCryptographicHash::hash(h1, QCryptographicHash::Sha1) );
}











quint8 c_summary::save_summary()
{
    QByteArray line;
    QList<QString> keys;
    QString hash, tmp;
    if( !summary->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate) )
    {
        QMessageBox::critical(0, QString("Save"), QString("Can't open summary file."));
        return 1;
    }

    for(quint32 i = 0; i < (quint32) records->size(); ++i)
    {
        line.clear();
        hash.clear();
        line.append((records->at(i))->id);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->variant);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->selection);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->box_count);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->item_count);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->created);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->closed);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->saved_box_count);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->saved_item_count);
        line.append(C_SUMMARY_DELIMETER_1);

        keys = (records->at(i))->log_activities.keys();
        for(quint32 j = 0; j < (quint32) keys.size(); ++j)
        {
            tmp.clear();
            tmp.append(keys[j]);
            tmp.append(C_SUMMARY_DELIMETER_3);
            tmp.append((records->at(i))->log_activities.value( keys[j] ) );
            if( hash.size() > 0 ) hash.append( C_SUMMARY_DELIMETER_2 );
            hash.append( tmp );
        }

        line.append(hash);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append( get_hash( *(records->at(i)) ) );
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->description);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append("\n");
        write( line );
    }
    close();
    return 0;
}











uint c_summary::load()
{
    // dir is exists checked before
    // open ile summary
    summary->setFileName(data_dir->path()+QString("/summary.stok"));
    if( !summary->exists() )
    {
        return 0;
    }

    //	open file;
    if( !summary->open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QMessageBox::critical(0, QString("Load"), QString("Can't open summary file."));
        return 1;
    }

    //	read file
    QString line;
    QStringList l_elements, tmp;
    QTextStream load(summary);
    quint8 unloaded = 0;
    quint8 i, item_id, map_split_err;
    summary_record *new_record;
    c_logact *new_log_activity;
    item_id = 0;
    while( !load.atEnd() )
    {
            //	load string & split it
        line = load.readLine().trimmed();
        if( line.size() == 0 ) continue;
        l_elements = line.split(QString( C_SUMMARY_DELIMETER_1 ));
        if( l_elements.size() != 12 )
        {
            emit log( QString( Q_FUNC_INFO ), QString("wrong count of elements in line at file #%1#, line #%2#").arg(summary->fileName()).arg(line) );
            unloaded++;
            continue;
        }

        //	init new record
        bool ok;
        new_record = new summary_record;
        new_record->id = l_elements[0];
        new_record->variant = l_elements[1];
        new_record->selection = l_elements[2].toUShort(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting selection: #%1#").arg( l_elements[2] ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->box_count = l_elements[3].toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting box_count: #%1#").arg( l_elements[3] ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->item_count = l_elements[4].toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting item_count: #%1#").arg( l_elements[4] ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->created = l_elements[5];
        new_record->closed = l_elements[6];
        new_record->saved_box_count = l_elements[7].toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting saved_box_count #%1#").arg( l_elements[7] ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->saved_item_count = l_elements[8].toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting saved_item_count #%1#").arg( l_elements[8] ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->hash = l_elements[10];
        new_record->description = l_elements[11];
        //	load QMap
        map_split_err = 0;
        l_elements = l_elements[9].split( QString( C_SUMMARY_DELIMETER_2 ) );
        for(i = 0; i < l_elements.size(); ++i)
        {
            tmp = l_elements[i].split( QString( C_SUMMARY_DELIMETER_3 ) );
            if( tmp.size() != 2 )
            {
                emit log( QString( Q_FUNC_INFO ), QString("not 2 elements at file part ( skipped ): #%1#").arg( l_elements[i] ) );
                map_split_err++;
                continue;
            }
            new_record->log_activities.insert(tmp[0], tmp[1]);
        }
        //	if during loading of map error occurs => skip record
        if( map_split_err )
        {
            unloaded++;
            continue;
        }

        //	init record object
        new_log_activity = new c_logact(parent);//, new_record->variant, QString(new_record->selection));
        if( new_log_activity->init( data_dir->absolutePath()+ "/" + new_record->id, new_record->log_activities) )
        {
            delete new_record;
            delete new_log_activity;
            unloaded++;
            continue;
        }

        //	all ok
        new_record->d = new_log_activity;
        records->insert(item_id, new_record);
        item_id++;
    }
    summary->close();
    return unloaded;
}

















//____________________________ [ Work with Items ] __________________________________




summary_record* c_summary::find(QString variant, quint16 selection)
{

    if( variant == "" || selection == 0 ) return 0;

    for(quint64 i = 0; i < (quint64) records->size(); ++i)
    {
        if( (records->at(i))->variant == variant && (records->at(i))->selection == selection ) return records->at(i);
    }

    return 0;
}





quint8 c_summary::load_item(QString variant, quint16 selection, quint64 date, QString direction, quint64 boxes, quint64 items, QString description)
{

    summary_record* record;
    if( (record = find(variant, selection)) == 0 )
    {
        emit log(  QString( Q_FUNC_INFO ), QString("Element with variant %1 and selection %2 not founded").arg(variant).arg(selection) );
        return 1;
    }

    quint8 ret = record->d->add_record(date, direction, boxes, items, description);

    if( ret != 0 ) return ret;

    if(direction == "l")
    {
        record->box_count += boxes;
        record->item_count += items;
    }
    else
    {
        record->box_count -= boxes;
        record->item_count -= items;
    }


    return 0;
}







quint8 c_summary::unload_item(QString variant, quint16 selection, quint64 timestamp)
{
    summary_record* record;
    if( (record = find(variant, selection)) == 0 )
    {
        emit log(  QString( Q_FUNC_INFO ), QString("Element with variant %1 and selection %2 not founded").arg(variant).arg(selection) );
        return 1;
    }

    action_record a_record;
    int ret = record->d->remove_record(timestamp, &a_record);
    if( ret != 0 ) return ret;

    if(a_record.direction == "l")
    {
        record->box_count -= a_record.boxes;
        record->item_count -= a_record.items;
    }
    else
    {
        record->box_count += a_record.boxes;
        record->item_count += a_record.items;
    }

    return 0;
}





QVector<summary_record*> c_summary::get_records()
{
    return *records;
}






quint8 c_summary::get_rounds(QString variant, QString selection, QString month, QVector<QString> *var, QVector<QString> *sel, QVector<QString> *mth)
{
    var->clear();
    if( variant == "all" )
    {
        for(quint64 i = 0; i < (quint64) records->size(); ++i) var->append( records->at(i)->variant );
    }
    else
    {
        for(quint64 i = 0; i < (quint64) records->size(); ++i)
        {
            if( records->at(i)->variant == variant ) var->append( records->at(i)->variant );
        }
    }

    if( var->size() == 0 )
    {
        emit log(  QString( Q_FUNC_INFO ), QString("Not fonded elements witn next parameter(Variant): Variant: %1; Selection: %2; Month: %3").arg(variant).arg(selection).arg(month) );
        return 1;
    }


    bool ok = false;
    quint64 sel_num = selection.toULongLong(&ok);
    if(!ok)
    {
        emit log(  QString( Q_FUNC_INFO ), QString("Can't convert selection to number, selection: #%1#").arg(selection) );
        return 1;
    }

    sel->clear();
    mth->clear();
    QStringList monthes;

    for(quint64 i = 0; i < (quint64) records->size(); ++i)
    {
        if( (selection == "all") || (sel_num == records->at(i)->selection) )
        {
            sel->append( QString::number(records->at(i)->selection) );
            monthes += records->at(i)->d->get_file_names();
        }
    }

    if( sel->size() == 0 )
    {
        emit log(  QString( Q_FUNC_INFO ), QString("Not fonded elements witn next parameter(Selection): Variant: %1; Selection: %2; Month: %3").arg(variant).arg(selection).arg(month) );
        return 1;
    }


    //delete all repeated monthes
    monthes.removeDuplicates();
    for(quint64 i = 0; i < (quint64) monthes.size(); ++i)
    {
        mth->append( monthes.at(i) );
    }

    return 0;
}












QVector<action_record> c_summary::get_activity(QString variant, quint64 selection, QString year_month)
{

}












//__________________________ [ End Work with Items ] __________________________________







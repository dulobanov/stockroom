#include "c_summary.h"

c_summary::c_summary(QWidget *prnt, QDir *u_d) :
    QFile(prnt)
{
    this->data_dir = u_d;
    this->records = new QVector<summary_record *>;
    this->parent = prnt;
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

return QCryptographicHash::hash(h1, QCryptographicHash::Sha1).toHex();
}











quint8 c_summary::save_summary()
{
    QByteArray line;
    QList<QString> keys;
    QString hash, tmp;
    if( !this->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate) )
    {
        QMessageBox::critical(0, QString("Save"), QString("Can't open this file."));
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
        line.append(QString::number(records->at(i)->selection));
        line.append(C_SUMMARY_DELIMETER_1);
        line.append(QString::number(records->at(i)->box_count));
        line.append(C_SUMMARY_DELIMETER_1);
        line.append(QString::number(records->at(i)->item_count));
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->created);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append((records->at(i))->closed);
        line.append(C_SUMMARY_DELIMETER_1);
        line.append(QString::number(records->at(i)->saved_box_count));
        line.append(C_SUMMARY_DELIMETER_1);
        line.append(QString::number(records->at(i)->saved_item_count));
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
        line.append("\n");
        write( line );
    }
    close();
    return 0;
}











quint8 c_summary::load()
{
    // dir is exists checked before
    // open ile this
    this->setFileName(data_dir->path() + QString("/summary.stok"));
    if( !this->exists() )
    {
        return 0;
    }

    //	open file;
    if( !this->open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        emit(QString(Q_FUNC_INFO), QString("Can't open this file: %1").arg(fileName()));
        return 1;
    }

    //	read file
    QString line;
    QStringList l_elements, tmp;
    QTextStream load(this);
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
            emit log( QString( Q_FUNC_INFO ), QString("wrong count of elements in line at file #%1#, line #%2#").arg(this->fileName()).arg(line) );
            unloaded++;
            continue;
        }

        //	init new record
        bool ok;
        new_record = new summary_record;
        new_record->id = l_elements.at(0);
        new_record->variant = l_elements.at(1);
        new_record->selection = l_elements.at(2).toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting selection: #%1#").arg( l_elements.at(2) ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->box_count = l_elements.at(3).toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting box_count: #%1#").arg( l_elements.at(3) ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->item_count = l_elements.at(4).toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting item_count: #%1#").arg( l_elements.at(4) ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->created = l_elements.at(5);
        new_record->closed = l_elements.at(6);
        new_record->saved_box_count = l_elements.at(7).toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting saved_box_count #%1#").arg( l_elements.at(7) ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->saved_item_count = l_elements.at(8).toULongLong(&ok);
        if(!ok)
        {
            emit log( QString( Q_FUNC_INFO ), QString("error during converting saved_item_count #%1#").arg( l_elements.at(8) ) );
            unloaded++;
            delete new_record;
            continue;
        }

        new_record->hash = l_elements.at(10);
        new_record->description = l_elements.at(11);


        //	load QMap
        map_split_err = 0;
        if(!(l_elements.at(9)).isEmpty())
        {
            l_elements = l_elements.at(9).split( QString( C_SUMMARY_DELIMETER_2 ) );
            for(i = 0; i < l_elements.size(); ++i)
            {
                tmp = l_elements.at(i).split( QString( C_SUMMARY_DELIMETER_3 ) );
                if( tmp.size() != 2 )
                {
                    emit log( QString( Q_FUNC_INFO ), QString("not 2 elements at file part ( skipped ): #%1#").arg( l_elements.at(i) ) );
                    map_split_err++;
                    continue;
                }
                new_record->log_activities.insert(tmp.at(0), tmp.at(1));
            }
            //	if during loading of map error occurs => skip record
            if( map_split_err )
            {
                unloaded++;
                continue;
            }
        }


        //	init record object
        new_log_activity = new c_logact(parent);
        new_log_activity->setID(new_record->id);
        new_log_activity->setVaritySelection(new_record->variant, QString::number(new_record->selection));
        connect(new_log_activity, SIGNAL(log(QString,QString)), this, SIGNAL(log(QString,QString)));
        if( new_log_activity->init( this->data_dir->path() + QDir::separator() + new_record->id, new_record->log_activities) )
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
    this->close();
    return unloaded;
}

















//____________________________ [ Work with Items ] __________________________________



quint8 c_summary::addItemRecord(QString varity, QString selection, quint64 box_count, quint64 item_count, QString description, bool set_as_default)
{
    summary_record *record = new summary_record;
    bool ok;

    record->id = QString::number(QDateTime::currentMSecsSinceEpoch());

    record->variant = varity;

    quint64 sel = selection.toLongLong(&ok);
    if(!ok)
    {
        emit log( QString( Q_FUNC_INFO ), QString("error during converting selection #%1# to number").arg( selection ) );
        return 1;
    }

    record->selection = sel;
    record->box_count = 0;
    record->item_count = 0;
    record->created = record->id;
    record->closed = QString("0");


    record->description = description;
    record->d = new c_logact(parent);
    record->d->setID(record->id);
    record->d->setVaritySelection(varity, selection);
    connect(record->d, SIGNAL(log(QString,QString)), this, SIGNAL(log(QString,QString)));
    record->d->init( this->data_dir->path() + QDir::separator() + record->id, QMap<QString, QString>());
    record->changed = true;

    records->append(record);

    this->load_item(record->id, record->created.toULongLong(&ok), box_count, item_count, QString("Load in initialization"));

    if(set_as_default)
    {
        record->saved_box_count = record->box_count;
        record->saved_item_count = record->item_count;
    }
    else
    {
        record->saved_box_count = 0;
        record->saved_item_count = 0;
    }

    return 0;
}











summary_record* c_summary::findItemRecord(QString id)
{

    if( id == "" )
    {
        emit log(QString(Q_FUNC_INFO), QString("Item ID is Empty"));
        return 0;
    }

    for(quint64 i = 0; i < (quint64) records->size(); ++i)
    {
        if( (records->at(i))->id == id )
        {
            return records->at(i);
        }
    }

    emit log(QString(Q_FUNC_INFO), QString("Item with ID #%1# not founded.").arg(id));
    return 0;
}





quint8 c_summary::load_item(QString id, quint64 date, quint64 boxes, quint64 items, QString description)
{
    summary_record *record;
    record = findItemRecord(id);
    if(record == 0) return 1;

    if( record->d->addRecord(date, "l", boxes, items, description) ) return 2;

    record->box_count += boxes;
    record->item_count += items;

    return 0;
}








quint8 c_summary::unload_item(QString id, quint64 date, quint64 boxes, quint64 items, QString description)
{
    summary_record* record;
    record = findItemRecord(id);
    if(record == 0) return 1;

    if( record->d->addRecord(date, "u", boxes, items, description) ) return 2;

    record->box_count -= boxes;
    record->item_count -= items;

    return 0;
}





QVector<summary_record*>* c_summary::get_records()
{
    return records;
}






quint8 c_summary::getRoundsFor(QString variant, QString selection, QString month, QStringList *var, QStringList *sel, QStringList *mth)
{
    var->clear();
    var->append(tr("All"));
    sel->clear();
    sel->append(tr("All"));
    mth->clear();
    mth->append(tr("All"));

    //select varity
    for(quint64 i = 0; i < (quint64) records->size(); ++i)
    {
        if( (selection != tr("All")) && (QString::number(records->at(i)->selection) != selection) ) continue;
        if( (month != tr("All")) && (records->at(i)->d->get_file_names().indexOf(month) == -1) ) continue;
        var->append( records->at(i)->variant );
    }


    //select selection
    for(quint64 i = 0; i < (quint64) records->size(); ++i)
    {
        if( (variant != tr("All")) && (variant != records->at(i)->variant) ) continue;
        if( (month != tr("All")) && (records->at(i)->d->get_file_names().indexOf(month) == -1) ) continue;
        sel->append( QString::number(records->at(i)->selection) );
    }


    //select month&Year
    for(quint64 i = 0; i < (quint64) records->size(); ++i)
    {
        if( (variant != tr("All")) && (variant != records->at(i)->variant) ) continue;
        if( (selection != tr("All")) && (QString::number(records->at(i)->selection) != selection) ) continue;
        *mth += records->at(i)->d->get_file_names();
    }
    // add current month
    mth->append( QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN) );

    var->removeDuplicates();
    sel->removeDuplicates();
    mth->removeDuplicates();

    return 0;
}












QVector<action_record> c_summary::get_activity(QString variant, QString selection, QString year_month)
{
    QVector<action_record> result;
    summary_record rec;

    for(quint64 i = 0; i < (quint64) records->size(); ++ i)
    {
        rec = *records->at(i);

        if( variant != tr("All") )
        {
            if( variant != rec.variant ) continue;
        }

        if( selection != tr("All"))
        {
            if( selection != QString::number(rec.selection) ) continue;
        }

        result += rec.d->get_activity(year_month);
    }

    return result;
}














QStringList c_summary::getSelectionsFor(QString varity)
{
    QStringList selections;

    for(quint64 i = 0; i < (quint64) records->size(); ++ i)
    {
        if(records->at(i)->variant == varity) selections.append(QString::number(records->at(i)->selection));
    }

    selections.removeDuplicates();
    return selections;
}






QStringList c_summary::getVaritys()
{
    QStringList varitys;

    for(quint64 i = 0; i < (quint64) records->size(); ++ i)
    {
        varitys.append(records->at(i)->variant);
    }

    varitys.removeDuplicates();
    return varitys;
}






//__________________________ [ End Work with Items ] __________________________________







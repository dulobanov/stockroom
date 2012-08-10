#include "c_summary.h"

c_summary::c_summary(QWidget *prnt, QDir *u_d) :
    QFile(prnt)
{
	data_dir = u_d;
	items = new QVector<c_logact *>;
	records = new QVector<summary_record *>;
	parent = prnt;
}


c_summary::~c_summary()
{
	close_files();
}









quint8 c_summary::close_files()
{
	//	step by step close
    for(quint32 i = 0; i < (quint64) items->size(); ++i)
	{
		;
	}
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


















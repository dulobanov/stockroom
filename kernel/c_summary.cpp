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
	quint8 i, item_id;
	summary_record *new_record;
	c_logact *new_log_activity;
	item_id = 0;
	while( !load.atEnd() )
	{
			//	load string & split it
		line = load.readLine().trimmed();
		if( line.size() == 0 ) continue;
		l_elements = line.split(QString("#"));
		if( l_elements.size() != 11 )
		{
			qDebug("c_summary::load wrong count of elements in line at summary.stok");
			unloaded++;
			continue;
		}

		//	init new record
		bool ok;
		new_record = new summary_record;
		new_record->variant = l_elements[0];
		new_record->selection = l_elements[1].toUShort(&ok);
		if(!ok) { unloaded++; delete new_record; continue; }
		new_record->box_count = l_elements[2].toULongLong(&ok);
		if(!ok) { unloaded++; delete new_record; continue; }
		new_record->item_count = l_elements[3].toULongLong(&ok);
		if(!ok) { unloaded++; delete new_record; continue; }
		new_record->created = l_elements[4];
		new_record->closed = l_elements[5];
		new_record->saved_box_count = l_elements[6].toULongLong(&ok);
		if(!ok) { unloaded++; delete new_record; continue; }
		new_record->saved_item_count = l_elements[7].toULongLong(&ok);
		if(!ok) { unloaded++; delete new_record; continue; }
		new_record->hash = l_elements[9];
		new_record->description = l_elements[10];
		//	load QMap
		l_elements = l_elements[8].split( QString("!") );
		for(i = 0; i < l_elements.size(); ++i)
		{
			tmp = l_elements[i].split( QString("=") );
			if( tmp.size() != 2 ) {	qDebug("c_summary::load not two element at map => continue"); continue; }
			new_record->log_activities[tmp[0]] = tmp[1];
		}

		//	init record object
		new_log_activity = new c_logact(parent, new_record->variant, QString(new_record->selection));

		//	all ok
		records->insert(item_id, new_record);
		items->insert(item_id, new_log_activity);
		item_id++;
	}



	if(unloaded > 0)
	{
		QMessageBox::warning( parent, QString("StokRoom"), QString("unloaded ") + QString(unloaded) + QString(" element(s) due to errors") );
	}

	return 0;
}


















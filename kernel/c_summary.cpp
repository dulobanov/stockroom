#include "c_summary.h"

c_summary::c_summary(QObject *parent, QDir *u_d) :
    QFile(parent)
{
	data_dir = *u_d;
}














uint c_summary::load()
{
	// dir is exists checked before
	// open ile summary
    summary.setFileName(data_dir.path()+QString("/summary.stok"));
	if( !summary.exists() )
	{
		return 0;
	}

	//	open file;
	if( !summary.open(QIODevice::ReadOnly | QIODevice::Text) )
	{
        QMessageBox::critical(0, QString("Load"), QString("Can't open summary file."));
		return 1;
	}

	//	read file
	QString line;
	QStringList l_elements;
	QTextStream load(&summary);
	while( !load.atEnd() )
	{
			//	load string & split it
		line = load.readLine();
        l_elements = line.split(QString("#"));
        if( l_elements.size() != 10 )
		{
            ;
		}
	}

	return 0;
}


















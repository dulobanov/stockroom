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
	summary = QFile(data_dir.path()+"/summary.stok");
	if( !summary.exists() )
	{
		return 0;
	}

	//	open file;
	if( !summary.open(QIODevice::ReadOnly | QIODevice::Text) )
	{
		QMesageBox::critical(0, QString("Load"), QString("Can't open summary file."));
		return 1;
	}

	//	read file
	QTextStream load(&summary);
	while( !load.atEnd() )
	{

	}

	return 0;
}


















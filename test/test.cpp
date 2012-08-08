#include "test.h"

test::test(QWidget *parent) :
    QWidget(parent)
{


	log = new log_impl(this);
	qDebug() << "log init result is: " << log->init( QString("/home/user/test/log") );



	ma_log malog(this, QString("/home/user/test"), QString("1.test"));
	connect( &malog, SIGNAL(log(QString, QString)), log, SLOT(log(QString, QString)));

	qDebug() << "init res:" << malog.init();
	for(quint64 i = 0; i < 5; ++i)
	{
		qDebug() << "add val " << i;
		malog.add_record(QDateTime::currentMSecsSinceEpoch(), QString("l"), 10, 1000, QString::number(i) );
	}
//	qDebug() << "remove result:" << malog.remove_record(1344368224046);
	qDebug() << "save res:" << malog.save();

}

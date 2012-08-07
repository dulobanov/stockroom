#include "test.h"

test::test(QWidget *parent) :
    QWidget(parent)
{
	ma_log malog(this, QString("/home/user/test"), QString("1.test"));
	qDebug() << "init res:" << malog.init();
	for(quint64 i = 0; i < 500; ++i)
	{
		qDebug() << "add val " << i;
		malog.add_record(QDateTime::currentMSecsSinceEpoch(), QString("l"), 10, 1000, QString::number(i) );
	}
	qDebug() << "remove result:" << malog.remove_record(1344368224046);
	qDebug() << "save res:" << malog.save();

}

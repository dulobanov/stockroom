#include "test.h"

test::test(QWidget *parent) :
    QWidget(parent)
{
	ma_log malog(this, QString("/home/user/test"), QString("1.test"));
	for(quint64 i = 0; i < 50; ++i)
		malog.add_record(QDateTime::currentMSecsSinceEpoch(), QString("l"), 10, 1000, QString::number(i) );

}

#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include "kernel/ma_log.h"
#include "log/log_impl.h"

class test : public QWidget
{
    Q_OBJECT
public:
    explicit test(QWidget *parent = 0);



private:
	log_impl *log;



signals:

public slots:

};

#endif // TEST_H

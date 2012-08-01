#ifndef C_LOGACT_H
#define C_LOGACT_H

#include <QObject>

class c_logact : public QObject
{
    Q_OBJECT
public:
    explicit c_logact(QWidget *prnt = 0, QString vart = "", QString selec = "");





private:
	//	VARS
	QWidget *parent;
	QString variant;
	QString selection;




	//	FUNCTIONS






signals:

public slots:

};

#endif // C_LOGACT_H

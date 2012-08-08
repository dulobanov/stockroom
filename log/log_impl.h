#ifndef LOG_IMPL_H
#define LOG_IMPL_H

#include <QFile>
#include <QObject>
#include <QFileInfo>
#include <QDateTime>
#include <QString>
#include <QByteArray>

class log_impl : public QFile
{
    Q_OBJECT
public:
	explicit log_impl(QObject *prnt = 0);
	~log_impl();

	quint8 init(QString dir);
	quint8 save();

signals:

public slots:
	void log(QString sender, QString message);

};

#endif // LOG_IMPL_H

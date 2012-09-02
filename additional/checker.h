#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QRegExp>

class Checker : public QObject
{
    Q_OBJECT
public:
    explicit Checker(QObject *parent = 0);
    quint8 checkForUsualString(QString str);
    quint8 checkForUsualString(QString str, QString *out);



private:
    QString *alowed_common;


signals:
    void log(QString sender, QString message);

public slots:

};

#endif // CHECKER_H

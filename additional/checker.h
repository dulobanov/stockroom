#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QRegExp>

class Checker : public QObject
{
    Q_OBJECT
public:
    explicit Checker(QObject *parent = 0);

    quint8 checkForUsualString(QString str = "", QString *out = 0);

    quint8 checkForDescription(QString str = "", QString *out = 0);

    quint8 check(QString str = "", QString regEx = "", QString *out = 0);



private:
    QString *alowed_common;


signals:
    void log(QString sender, QString message);

public slots:


};

#endif // CHECKER_H

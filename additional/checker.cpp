#include "checker.h"

Checker::Checker(QObject *parent) :
    QObject(parent)
{
}






quint8 Checker::checkForUsualString(QString inStr, QString *out)
{
    out->clear();
    QString str;
    if(str.size() > 200)
    {
        emit log(QString( Q_FUNC_INFO ), QString("String size larger than 200 symbols"));
        str = inStr.left(200);
    }
    else str = inStr;

    return this->check(inStr, QString("^[\\w\\d\\s_]+$"), out);
}



















quint8 Checker::checkForDescription(QString inStr, QString *out)
{
    out->clear();
    QString str;
    if(str.size() > 200)
    {
        emit log(QString( Q_FUNC_INFO ), QString("String size larger than 200 symbols"));
        str = inStr.left(200);
    }
    else str = inStr;

    return this->check(inStr, QString("^[\\w\\d\\s\\.,_]+$"), out);
}













quint8 Checker::check(QString str, QString regEx, QString *out)
{
    out->clear();
    QRegExp exp(regEx);
    QString badSymbols = "";
    for(quint8 i = 0; i < str.size(); ++i)
    {
        if(exp.exactMatch(str.at(i))) out->append(str.at(i));
        else badSymbols.append(str.at(i));
    }

    if(badSymbols.size() != 0)
    {
        emit log(QString( Q_FUNC_INFO ), QString("String contains invalid symbols: %1").arg(badSymbols));
        return 2;
    }

    return 0;
}







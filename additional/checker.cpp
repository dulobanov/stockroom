#include "checker.h"

Checker::Checker(QObject *parent) :
    QObject(parent)
{
}


quint8 Checker::checkForUsualString(QString str, QString *out)
{
    qDebug("checker st");
    out->clear();
    if(str.size() > 100)
    {
        emit log(QString( Q_FUNC_INFO ), QString("String size larger than 100 symbols"));
        return 1;
    }
qDebug("checker 1");
    QRegExp exp("^[a-zA-Z0-9\\s]+$");
    QString badSymbols = "";
    for(quint8 i = 0; i < str.size(); ++i)
    {
        if(exp.exactMatch(str.at(i))) out->append(str.at(i));
        else badSymbols.append(str.at(i));
    }
qDebug("checker 2");
    if(badSymbols.size() != 0)
    {
        emit log(QString( Q_FUNC_INFO ), QString("String contains invalid symbols: %1").arg(badSymbols));
        return 2;
    }

    return 0;
}



quint8 Checker::checkForUsualString(QString str)
{
    QString out;
    return this->checkForUsualString(str, &out);
}

#ifndef REPORTTABLE_H
#define REPORTTABLE_H

#include <QTableWidget>
#include <QWidget>
#include <QMap>
#include <QMapIterator>

#include "src/kernel.h"





struct reportStruct
{
    QString id;
    QString varity;
    QString selection;
    QString direction;
    quint64 boxCount;
    quint64 itemCount;
};







class ReportTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit ReportTable(QWidget *parent = 0);





private:
    //VARS






    //FUNCTIONS
    quint8 initTable();
    quint8 addRow(reportStruct row = reportStruct());




    
signals:
    void log(QString sender, QString message);
    
public slots:
    void updateReportTable(QVector<action_record> updates);
    
};

#endif // REPORTTABLE_H

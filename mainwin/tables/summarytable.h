#ifndef SUMMARYTABLE_H
#define SUMMARYTABLE_H

#include <QTableWidget>
#include <QTableWidgetItem>

#include "src/kernel.h"

class SummaryTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit SummaryTable(QWidget *parent = 0);
    quint8 getActiveRowID(QString *id);
    //quint8 setKernel(kernel* kern = 0);


private:
    //  VARS
    kernel *kern;


    //  FUNCTIONS
    quint8 initTable();



signals:


public slots:
    void updateSummaryTable(QVector<summary_record*> *updates);

};

#endif // SUMMARYTABLE_H

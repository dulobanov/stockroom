#ifndef ACTIVITYTABLE_H
#define ACTIVITYTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>

#include "src/kernel.h"

class ActivityTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit ActivityTable(QWidget *parent = 0);
    


private:
    quint8 initTable();




signals:
    void log(QString sender, QString message);
    
public slots:
    void updateActivityTable(QVector<action_record> updates);
    
};

#endif // ACTIVITYTABLE_H

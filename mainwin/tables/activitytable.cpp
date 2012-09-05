#include "activitytable.h"

ActivityTable::ActivityTable(QWidget *parent) :
    QTableWidget(parent)
{
    initTable();
}











quint8 ActivityTable::initTable()
{
    setColumnCount(8);
    setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Varity")));
    setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Selection")));
    setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Date & Time")));
    setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Direction")));
    setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Boxes")));
    setHorizontalHeaderItem(6, new QTableWidgetItem(tr("Items")));
    setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Description")));
    setShowGrid(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setColumnHidden(0, true);
    return 0;
}













void ActivityTable::updateActivityTable(QVector<action_record> updates)
{
    this->clear();
    this->initTable();
    this->setSortingEnabled(false);

    //  set count of rows
    this->setRowCount(updates.size());

    //  insert items
    action_record record;
    QDateTime dateTime;
    for(quint64 i = 0; i < (quint64) updates.size(); ++i)
    {
        record = updates.at(i);
        this->setItem(i, 0, new QTableWidgetItem(QString::number(record.timestamp)));
        this->setItem(i, 1, new QTableWidgetItem(*record.varity));
        this->setItem(i, 2, new QTableWidgetItem(*record.selection));
        dateTime = QDateTime::fromMSecsSinceEpoch(record.date_time);
        this->setItem(i, 3, new QTableWidgetItem(dateTime.toString(QString("dd MMM yyyy hh:mm"))));

        if(record.direction == "l")
        {
            this->setItem(i, 4, new QTableWidgetItem(tr("Load")));
        }
        else
        {
            if(record.direction == "u")
            {
                this->setItem(i, 4, new QTableWidgetItem(tr("Unload")));
            }
            else
            {
                emit log(QString(Q_FUNC_INFO), QString("Unknown direction: #%1#").arg(record.direction));
                QMessageBox::critical(this, QString("Error"), QString("Unknown direction: %1").arg(record.direction));
                continue;
            }
        }

        this->setItem(i, 5, new QTableWidgetItem(QString::number(record.boxes)));
        this->setItem(i, 6, new QTableWidgetItem(QString::number(record.items)));
        this->setItem(i, 7, new QTableWidgetItem(record.description));
    }

    this->setSortingEnabled(true);
}




















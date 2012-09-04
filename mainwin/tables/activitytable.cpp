#include "activitytable.h"

ActivityTable::ActivityTable(QWidget *parent) :
    QTableWidget(parent)
{
    initGUI();
}











quint8 ActivityTable::initGUI()
{
    setColumnCount(7);
    setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Date")));
    setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Time")));
    setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Direction")));
    setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Boxes")));
    setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Items")));
    setHorizontalHeaderItem(6, new QTableWidgetItem(tr("Description")));
    setShowGrid(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setColumnHidden(0, true);
    return 0;
}













void ActivityTable::updateActivityTable(QVector<action_record> updates)
{
    this->clear();
    this->setSortingEnabled(false);

    //  set count of rows
    this->setRowCount(updates.size());

    //  insert items
    action_record record;
    QDateTime dateTime;
    for(quint64 i = 0; i < (quint64) updates.size(); ++i)
    {
        record = updates.at(i);
        this->setItem(i, 0, new QTableWidgetItem(record.timestamp));
        dateTime = QDateTime::fromMSecsSinceEpoch(record.date_time);
        this->setItem(i, 1, new QTableWidgetItem(dateTime.toString(QString("dd MMM YYYY"))));
        this->setItem(i, 2, new QTableWidgetItem(dateTime.toString(QString("hh:mm:ss"))));

        if(record.direction == "l")
        {
            this->setItem(i, 3, new QTableWidgetItem(tr("Load")));
        }
        else
        {
            if(record.direction == "u")
            {
                this->setItem(i, 3, new QTableWidgetItem(tr("Unload")));
            }
            else
            {
                emit log(QString(Q_FUNC_INFO), QString("Unknown direction: #%1#").arg(record.direction));
                QMessageBox::critical(this, QString("Error"), QString("Unknown direction: %1").arg(record.direction));
                continue;
            }
        }

        this->setItem(i, 4, new QTableWidgetItem(record.boxes));
        this->setItem(i, 5, new QTableWidgetItem(record.items));
        this->setItem(i, 7, new QTableWidgetItem(record.description));
    }

    this->setSortingEnabled(true);
}




















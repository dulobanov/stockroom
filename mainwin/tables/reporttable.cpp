#include "reporttable.h"

ReportTable::ReportTable(QWidget *parent) :
    QTableWidget(parent)
{


}














quint8 ReportTable::initTable()
{
    setColumnCount(6);
    setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID")));
    setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Varity")));
    setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Selection")));
    setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Direction")));
    setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Boxes")));
    setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Items")));
    setColumnHidden(0, true);
    setShowGrid(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    return 0;
}



















void ReportTable::updateReportTable(QVector<action_record> updates)
{
    this->clear();
    this->initTable();
    this->setSortingEnabled(false);


    //prepeare data
    QMap<QString, reportStruct*> data;

    QString id;
    action_record record;
    reportStruct *rS;
    for(qint64 i = 0; i < updates.size(); ++i)
    {
        record = updates.at(i);
        id = QString("%1/%2").arg(*record.id).arg(record.direction);
        if(data.contains(id))
        {
            rS = data.value(id);
            rS->boxCount += record.boxes;
            rS->itemCount += record.items;
        }
        else
        {//init structure
            rS = new reportStruct;
            rS->id = *record.id;
            rS->varity = *record.varity;
            rS->selection = *record.selection;

            if(record.direction == "l") rS->direction = tr("Load");
            else rS->direction = tr("Unload");

            rS->boxCount = record.boxes;
            rS->itemCount = record.items;

            data.insert(id, rS);
        }
    }

    //  set count of rows
    this->setRowCount(data.size());

    //  insert items
    QMapIterator<QString, reportStruct*> iterator(data);
    quint64 row = 0;
    while(iterator.hasNext())
    {
        iterator.next();
        this->addRow(row, *(iterator.value()));
        ++row;
    }

    this->setSortingEnabled(true);
}









quint8 ReportTable::addRow(quint64 rowID, reportStruct row)
{
    this->setItem(rowID, 0, new QTableWidgetItem(row.id));
    this->setItem(rowID, 1, new QTableWidgetItem(row.varity));
    this->setItem(rowID, 2, new QTableWidgetItem(row.selection));
    this->setItem(rowID, 3, new QTableWidgetItem(row.direction));
    this->setItem(rowID, 4, new QTableWidgetItem(QString::number(row.boxCount)));
    this->setItem(rowID, 5, new QTableWidgetItem(QString::number(row.itemCount)));
    return 0;
}









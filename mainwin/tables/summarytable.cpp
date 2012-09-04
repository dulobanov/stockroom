#include "summarytable.h"

SummaryTable::SummaryTable(QWidget *parent) :
    QTableWidget(parent)
{
    initTable();
}













quint8 SummaryTable::initTable()
{
    setColumnCount(8);
    setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Varity")));
    setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Selection")));
    setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Box count")));
    setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Item Count")));
    setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Saved box count")));
    setHorizontalHeaderItem(6, new QTableWidgetItem(tr("Saved item count")));
    setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Description")));
    setShowGrid(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setColumnHidden(0, true);

    return 0;
}















void SummaryTable::updateSummaryTable(QVector<summary_record *> *updates)
{
    this->clear();
    this->initTable();
    this->setSortingEnabled(false);

    //  set count of rows
    this->setRowCount(updates->size());

    //  insert items
    summary_record record;
    for(quint64 i = 0; i < (quint64) updates->size(); ++i)
    {
        record = *updates->at(i);
        this->setItem(i, 0, new QTableWidgetItem(record.id));
        this->setItem(i, 1, new QTableWidgetItem(record.variant));
        this->setItem(i, 2, new QTableWidgetItem(QString::number(record.selection)));
        this->setItem(i, 3, new QTableWidgetItem(QString::number(record.box_count)));
        this->setItem(i, 4, new QTableWidgetItem(QString::number(record.item_count)));
        this->setItem(i, 5, new QTableWidgetItem(QString::number(record.saved_box_count)));
        this->setItem(i, 6, new QTableWidgetItem(QString::number(record.saved_item_count)));
        this->setItem(i, 7, new QTableWidgetItem(record.description));
    }

    this->setSortingEnabled(true);
}











quint8 SummaryTable::getActiveRowID(QString *id)
{
    //if(this->rowCount() < 1) return 1;
    qint64 row = (qint64) this->currentRow();
    if(row < 0) return 1;
    *id = this->item(row, 0)->text();
    return 0;
}








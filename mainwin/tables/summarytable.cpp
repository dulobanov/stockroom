#include "summarytable.h"

SummaryTable::SummaryTable(QWidget *parent) :
    QTableWidget(parent)
{
    initGUI();
}













quint8 SummaryTable::initGUI()
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
    insertRow( rowCount() );
    insertRow( rowCount() );

    return 0;
}








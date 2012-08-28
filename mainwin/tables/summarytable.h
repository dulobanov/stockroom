#ifndef SUMMARYTABLE_H
#define SUMMARYTABLE_H

#include <QTableWidget>
#include <QTableWidgetItem>

class SummaryTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit SummaryTable(QWidget *parent = 0);


private:
    quint8 initGUI();



signals:

public slots:

};

#endif // SUMMARYTABLE_H

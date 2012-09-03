#include "load_item.h"
#include "ui_load_item.h"

load_item::load_item(QWidget *parent, kernel *kern) :
    QDialog(parent),
    ui(new Ui::load_item)
{
    ui->setupUi(this);
    this->kern = kern;
    this->setValues(ui->varity, kern->getVaritys());
}

load_item::~load_item()
{
    delete ui;
}















quint8 load_item::setValues(QComboBox *list, const QStringList values)
{
    if(list == 0)
    {
        emit log( QString( Q_FUNC_INFO ), QString("ComboBox is not initialized"));
        return 1;
    }

    if(values.empty())
    {
        emit log( QString( Q_FUNC_INFO ), QString("Values list is empty"));
        return 2;
    }

    list->clear();
    list->addItems(values);
    return 0;
}










//			slots


void load_item::varity_selected(QString varity)
{
    this->setValues(ui->selection, kern->getSelectionsFor(varity));
	return;
}












void load_item::changes()
{
    bool ok;
    quint64 boxes = (ui->box_count->text()).toULongLong(&ok);
    if(!ok) return;

    quint64 selection = (ui->selection->currentText()).toULongLong(&ok);
    if(!ok)
    {
        emit log( QString( Q_FUNC_INFO ), QString("Can't convert selection to number, selection %1").arg(ui->selection->currentText()));
        return;
    }

    ui->items_count->setText(QString::number(boxes*selection));

	return;
}











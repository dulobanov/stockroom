#include "load_item.h"
#include "ui_load_item.h"

load_item::load_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::load_item)
{
    ui->setupUi(this);
}

load_item::~load_item()
{
    delete ui;
}


















//			slots


void load_item::varity_selected(QString varity)
{
	return;
}







void load_item::selection_selected(QString selection)
{
	return;
}








void load_item::changes()
{
	return;
}











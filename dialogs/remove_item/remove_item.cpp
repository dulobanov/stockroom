#include "remove_item.h"
#include "ui_remove_item.h"

remove_item::remove_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remove_item)
{
    ui->setupUi(this);
}

remove_item::~remove_item()
{
    delete ui;
}

























//			slots


void remove_item::varity_selected(QString varity)
{
	return;
}







void remove_item::selection_selected(QString selection)
{
	return;
}











void remove_item::accept()
{
	return;
}









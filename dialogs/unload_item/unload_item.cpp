#include "unload_item.h"
#include "ui_unload_item.h"

unload_item::unload_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::load_item)
{
    ui->setupUi(this);
}

unload_item::~unload_item()
{
    delete ui;
}


















//			slots


void unload_item::varity_selected(QString varity)
{
	return;
}







void unload_item::selection_selected(QString selection)
{
	return;
}








void unload_item::changes()
{
	return;
}











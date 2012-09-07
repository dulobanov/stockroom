#include "add_item.h"
#include "ui_add_item.h"

add_item::add_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_item)
{
    ui->setupUi(this);
    initGUI();
}

add_item::~add_item()
{
    delete ui;
}








quint8 add_item::initGUI()
{
    //  look for ok button
    QList <QAbstractButton *> buttons = ui->buttonBox->buttons();
    QAbstractButton * button;
    // perebiraem knopki: ischem ok
    int count = buttons.count();
    for(int i = 0; i < count; ++i )
    {
        button = buttons[i];
        if(ui->buttonBox->buttonRole(button) == QDialogButtonBox::AcceptRole)
        {
            this->okButton = button;
            break;
        }
    }
    this->okButton->setDisabled(1);

    return 0;
}










quint8 add_item::getValues(QString *varity, QString *selection, quint64 *boxCount, quint64 *itemCount, bool *saved, QString *description)
{
    Checker ch(this);
    connect(&ch, SIGNAL(log(QString,QString)), this, SIGNAL(log(QString,QString)));

    QString tmp;

    tmp = ui->varity->text();
    if(tmp.size() < 1)
    {
        emit log(QString( Q_FUNC_INFO ), QString("Varity field is empty, varity: #%1#").arg(ui->varity->text()));
        return 1;
    }
    if(ch.checkForUsualString(tmp))
    {
        emit log(QString( Q_FUNC_INFO ), QString("Varity field is wrong, varity: #%1#").arg(ui->varity->text()));
        return 1;
    }
    *varity = ui->varity->text();

    tmp = ui->selection->text();
    bool ok;
    tmp.toULongLong(&ok);
    if(!ok)
    {
        emit log(QString( Q_FUNC_INFO ), QString("Converting selection to number fails, selection: %1").arg(tmp));
        return 2;
    }
    *selection = ui->selection->text();


    tmp = ui->box_amount->text();
    *boxCount = tmp.toULongLong(&ok);
    if(!ok)
    {
        emit log(QString( Q_FUNC_INFO ), QString("Converting box count to number fails, box count: %1").arg(tmp));
        return 3;
    }


    tmp = ui->item_amount->text();
    *itemCount = tmp.toULongLong(&ok);
    if(!ok)
    {
        emit log(QString( Q_FUNC_INFO ), QString("Converting item count to number fails, item count: %1").arg(tmp));
        return 4;
    }


    if(ui->setDefault->isChecked()) *saved = true;
    else *saved = false;

    if(ui->description->text().size() > 0) ch.checkForUsualString(ui->description->text(), description);
    else *description = QString("");

    return 0;
}



















//			slots

void add_item::changes()
{
    this->okButton->setDisabled(1);
    quint64 selection, boxes, items;
    bool ok;

    selection = ui->selection->text().toULongLong(&ok);
    if(!ok) return;

    boxes = ui->box_amount->text().toULongLong(&ok);
    if(!ok) return;

    ui->item_amount->setText(QString::number(selection*boxes));

    this->checkOkButton();

    return;
}







void add_item::checkOkButton()
{
    this->okButton->setDisabled(1);
    Checker ch;
    bool ok;
    //check item varity
    if(ch.checkForUsualString(ui->varity->text())) return;

    //check selection
    ui->selection->text().toULongLong(&ok);
    if(!ok) return;

    //check boxes
    ui->box_amount->text().toULongLong(&ok);
    if(!ok) return;

    //check items
    ui->item_amount->text().toULongLong(&ok);
    if(!ok) return;

    this->okButton->setDisabled(0);
    return;
}









/*

void add_item::accept()
{

    return;
}*/







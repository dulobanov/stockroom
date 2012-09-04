#include "load_item.h"
#include "ui_load_item.h"

load_item::load_item(QWidget *parent, kernel *kern, QString varity, quint64 selection):
    QDialog(parent),
    ui(new Ui::load_item)
{
    ui->setupUi(this);
    ui->varity->setText(varity);
    ui->selection->setText(QString::number(selection));
    selection = quint64(selection);
    this->kern = kern;
}


load_item::~load_item()
{
    delete ui;
}







quint8 load_item::initGUI()
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
            okButton = button;
            break;
        }
    }
    button->setDisabled(1);
    return 0;
}








quint8 load_item::getValues(quint64 *dateTime, quint64 *boxes, quint64 *items, QString *description)
{
    bool ok;
    *dateTime = ui->date_time->dateTime().currentMSecsSinceEpoch();

    *boxes = ui->box_count->text().toULongLong(&ok);
    if(!ok)
    {
        emit log(QString(Q_FUNC_INFO), QString("Can't convert box count to number, box count #%1#").arg(ui->box_count->text()));
        return 1;
    }

    *items = ui->items_count->text().toULongLong(&ok);
    if(!ok)
    {
        emit log(QString(Q_FUNC_INFO), QString("Can't convert item count to number, item count #%1#").arg(ui->items_count->text()));
        return 2;
    }

    Checker ch;
    ch.checkForDescription(ui->description->text(), description);

    return 0;
}













//			slots

void load_item::changesBoxes(QString boxCount)
{
    bool ok;
    quint64 boxes = boxCount.toULongLong(&ok);
    if(!ok) return;

    ui->items_count->setText(QString::number(boxes*(*selection)));

    this->checkOkButton();
	return;
}












void load_item::checkOkButton()
{
    okButton->setDisabled(1);

    bool ok;

    ui->box_count->text().toULongLong(&ok);
    if(!ok) return;

    ui->items_count->text().toULongLong(&ok);
    if(!ok) return;

    okButton->setDisabled(0);
}







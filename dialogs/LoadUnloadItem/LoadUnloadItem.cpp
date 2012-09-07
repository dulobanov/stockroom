#include "LoadUnloadItem.h"
#include "ui_LoadUnloadItem.h"

LoadUnloadItem::LoadUnloadItem(QWidget *parent, kernel *kern, QString varity, quint64 selection):
    QDialog(parent),
    ui(new Ui::load_item)
{
    ui->setupUi(this);
    initGUI();

    ui->varity->setText(varity);
    ui->selection->setText(QString::number(selection));
    this->selection = new quint64(selection);
    this->kern = kern;
    ui->box_count->setFocus();

}


LoadUnloadItem::~LoadUnloadItem()
{
    delete ui;
}







quint8 LoadUnloadItem::initGUI()
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

    //init date
    ui->date_time->setDateTime(QDateTime::currentDateTime());


    return 0;
}








quint8 LoadUnloadItem::getValues(quint64 *dateTime, quint64 *boxes, quint64 *items, QString *description)
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









quint8 LoadUnloadItem::setTitle(QString title)
{
    this->setWindowTitle(title);
    return 0;
}











//			slots

void LoadUnloadItem::boxesChenged(QString boxCount)
{
    bool ok;
    this->okButton->setDisabled(1);
    quint64 boxes = boxCount.toULongLong(&ok);
    if(!ok) return;

    ui->items_count->setText(QString::number(boxes*(*this->selection)));

    this->checkOkButton();
    return;
}












void LoadUnloadItem::checkOkButton()
{
    this->okButton->setDisabled(1);

    bool ok;
    quint64 tmp;

    tmp = ui->box_count->text().toULongLong(&ok);
    if(!ok) return;

    tmp = ui->items_count->text().toULongLong(&ok);
    if(!ok) return;
    if(tmp < 1) return;

    this->okButton->setDisabled(0);
}







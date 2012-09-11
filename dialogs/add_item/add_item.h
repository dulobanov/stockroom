#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QDialog>
#include <QAbstractButton>
#include <additional/checker.h>
//#include <kernel.h>

namespace Ui {
class add_item;
}

class add_item : public QDialog
{
    Q_OBJECT

public:
    explicit add_item(QWidget *parent = 0);
    ~add_item();
    quint8 getValues(QString *varity = 0, QString *selection = 0, quint64 *boxCount = 0, quint64 *itemCount = 0, bool *saved = 0, QString *description = 0);

private:
    Ui::add_item *ui;
    QAbstractButton *okButton;

    //  functions
    quint8 initGUI();



public slots:
    void changes();
    void checkOkButton();


signals:
    void log(QString sender, QString message);





};

#endif // ADD_ITEM_H

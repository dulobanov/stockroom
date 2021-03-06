#ifndef LOAD_ITEM_H
#define LOAD_ITEM_H

#include <QDialog>
#include <QComboBox>
#include <QAbstractButton>
#include <QStringList>
#include "src/kernel.h"
#include "additional/checker.h"

namespace Ui {
class load_item;
}

class LoadUnloadItem : public QDialog
{
    Q_OBJECT

public:
    explicit LoadUnloadItem(QWidget *parent = 0, kernel *kern = 0, QString varity = "", quint64 selection = 0);
    ~LoadUnloadItem();

    quint8 getValues(quint64 *dateTime = 0, quint64 *boxes = 0, quint64 *items = 0, QString *description = 0);
    quint8 setTitle(QString title);
    quint8 setMaxBoxItemCount(quint64 boxCount = 0, quint64 itemCount = 0);

private:
    //  VARS
    Ui::load_item *ui;
    kernel *kern;
    quint64 *selection, *maxBoxCount, *maxItemCount;
    QAbstractButton *okButton;

    //  FUNCTIONS
    quint8 initGUI();





public slots:
    void boxesChenged(QString boxCount);
    void checkOkButton();


signals:
    void log(QString sender, QString message);




};


#endif // LOAD_ITEM_H

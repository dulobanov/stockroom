#ifndef LOAD_ITEM_H
#define LOAD_ITEM_H

#include <QDialog>
#include <QComboBox>
#include <QStringList>
#include "src/kernel.h"

namespace Ui {
class load_item;
}

class load_item : public QDialog
{
    Q_OBJECT
    
public:
    explicit load_item(QWidget *parent = 0, kernel *kern = 0);
    ~load_item();
    
private:
    //  VARS
    Ui::load_item *ui;
    kernel *kern;

    //  FUNCTIONS
    quint8 setValues(QComboBox *list = 0, const QStringList values = QStringList());




public slots:
    void varity_selected(QString varity);
	void changes();


signals:
    void log(QString sender, QString message);




};


#endif // LOAD_ITEM_H

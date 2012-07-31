#ifndef REMOVE_ITEM_H
#define REMOVE_ITEM_H

#include <QDialog>

namespace Ui {
class remove_item;
}

class remove_item : public QDialog
{
    Q_OBJECT
    
public:
    explicit remove_item(QWidget *parent = 0);
    ~remove_item();
    
private:
    Ui::remove_item *ui;





public slots:
	void varity_selected(QString varity);
	void selection_selected(QString selection);
	void accept();





};

#endif // REMOVE_ITEM_H

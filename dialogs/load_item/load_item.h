#ifndef LOAD_ITEM_H
#define LOAD_ITEM_H

#include <QDialog>

namespace Ui {
class load_item;
}

class load_item : public QDialog
{
    Q_OBJECT
    
public:
    explicit load_item(QWidget *parent = 0);
    ~load_item();
    
private:
    Ui::load_item *ui;






slots:
    void varity_selected(QString varity);
    void selection_selected(QString selection);
	void changes();







};


#endif // LOAD_ITEM_H

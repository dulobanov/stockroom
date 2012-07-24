#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QDialog>

namespace Ui {
class add_item;
}

class add_item : public QDialog
{
    Q_OBJECT
    
public:
    explicit add_item(QWidget *parent = 0);
    ~add_item();
    
private:
    Ui::add_item *ui;



slots:
	void changes();
	void accept();








};

#endif // ADD_ITEM_H

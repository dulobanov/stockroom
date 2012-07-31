#ifndef UNLOAD_ITEM_H
#define UNLOAD_ITEM_H

#include <QDialog>

namespace Ui {
class unload_item;
}

class unload_item : public QDialog
{
    Q_OBJECT
    
public:
    explicit unload_item(QWidget *parent = 0);
    ~unload_item();
    
private:
    Ui::unload_item *ui;






public slots:
    void varity_selected(QString varity);
    void selection_selected(QString selection);
	void changes();







};


#endif // UNLOAD_ITEM_H

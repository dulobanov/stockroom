#include "c_logact.h"

c_logact::c_logact(QWidget *prnt, QString vart, QString selec) :
    QWidget(prnt)
{
	parent = prnt;
	variant = vart;
	selection = selec;
}

#include "login.h"
//
login::login( QWidget *parent  )
	: QDialog(parent)
{
	start_ui();
	// show - last
	show();
}










QString login::get_hash(QString user, QString password)
{
	QByteArray str_1 = QCryptographicHash::hash( QByteArray(user.toAscii()), QCryptographicHash::Md5);
	QByteArray str_2 = QCryptographicHash::hash( QByteArray(password.toAscii()) + str_1, QCryptographicHash::Sha1);
	return ( QString( QCryptographicHash::hash( str_1 + QByteArray(user.toAscii()) +str_2 + QByteArray(password.toAscii()), QCryptographicHash::Md5 ) ) );
}








bool login::start_login(QString &user, QString &hash)
{
	user = "user";
	hash = "hash";
	return false;
}








void login::start_ui()
{
	ui.setupUi(this);
    // lock button Ok
	QList <QAbstractButton *> login_buttons = ui.buttonBox->buttons();
	QAbstractButton * button;
	// perebiraem knopki: ischem ok
	int count = login_buttons.count();
	for(int i = 0; i < count; ++i )
	{
		button = login_buttons[i];
		if(ui.buttonBox->buttonRole(button) == QDialogButtonBox::AcceptRole)
		{
			ui_ok = button;
			break;
		}
	}
	button->setDisabled(1);



	//		connections
	//	switch tab
	connect(ui.tabWidget, SIGNAL( currentChanged(int) ), this, SLOT( tab_switched(int) ));


}







bool login::set_pre_user(QString user)
{
	// check is valid username
	this->user = &user;
	return true;
}













//	SLOTS


void login::accept()
{
	return;
}








void login::reject()
{
	int ret = QMessageBox::question(this, QString(tr("Authorization")), QString(tr("You discard autorization, application will be closed.\nQuit?")), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if( ret == QMessageBox::Yes ) emit login_fail();
	return;
}





void login::tab_switched(int tab)
{
	//	get tab name
	QString tab_title = ui.tabWidget->tabText(tab);
	//	chose action
	QString pattern("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_");
	switch(tab_title)
	{	//	check form filling due to tab chose
		case tr("&Login"):
			
			break;

		case tr("&Registration"):
			break;

		default:
			QMessageBox::warning(this, QString("Tab Error"), QString("No such tab #" + tab_title + "#"));

	}

	QMessageBox::warning(this, QString("Tab debug"), tab_title);
}













//



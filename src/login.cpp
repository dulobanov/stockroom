#include "login.h"
//
login::login( QWidget *parent  )
	: QDialog(parent)
{
//	init vars
	pattern = QString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_");

//	start
	start_ui();
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
	return 0;
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

	// load & save lineedit palletes
	line_edit_norm = line_edit_wrong = ui.login_user->palette();
	line_edit_wrong.setColor( QPalette::Base, QColor(255, 230, 230) );

	//		connections
	//	switch tab
//	connect(ui.tabWidget, SIGNAL( currentChanged() ), this, SLOT( changes() ));






	show();
}







bool login::set_pre_user(QString user)
{
	// check is valid username
	this->user = &user;
	return 0;
}









bool login::is_legal_line(QString string, int min_len)
{
	int line_length = string.size();
	if(line_length < min_len) return 1;
	for(int i = 0; i < line_length; i++)
	{
		if( !pattern.contains( QString(string[i]) ) ) return 1;
	}
	return 0;
}








//	SLOTS


void login::accept()
{
// send information to settings
	return;
}








void login::reject()
{
	int ret = QMessageBox::question(this, QString(tr("Authorization")), QString(tr("You discard autorization, application will be closed.\nQuit?")), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if( ret == QMessageBox::Yes ) emit login_fail();
	return;
}





void login::changes()
{
	//	get tab name
	QString tab_title = ui.tabWidget->tabText( ui.tabWidget->currentIndex() );
	// return all lines to ok
	// lock button
	ui.login_user->setPalette( line_edit_norm );
	ui.login_password->setPalette( line_edit_norm );
	ui.reg_user->setPalette( line_edit_norm );
	ui.reg_pass_1->setPalette( line_edit_norm );
	ui.reg_pass_2->setPalette( line_edit_norm );
	ui_ok->setDisabled(1);
	//	chose action
	
	if(tab_title == tr("&Registration") )
	{
		QString user = ui.reg_user->text();
		QString pass1 = ui.reg_pass_1->text();
		QString pass2 = ui.reg_pass_2->text();
		// if one of the fild == "" -> return
		if( (user == "") || (pass1 == "") || (pass2 == "") )
		{
			return;
		}
		// check is pass1 == pass2
		if(pass1 != pass2)
		{
			ui.reg_pass_2->setPalette( line_edit_wrong );
			return;
		}
		//check user name field
		if( is_legal_line(user, 3) )
		{
			ui.reg_user->setPalette( line_edit_wrong );
			return;
		}
		// passwords is equal check one
		if( is_legal_line( pass1, 5 ) )
		{
			ui.reg_pass_1->setPalette( line_edit_wrong );
			ui.reg_pass_2->setPalette( line_edit_wrong );
			return;
		}
		//	all ok unlock Ok button
		ui_ok->setDisabled(0);
	}
	else if(tab_title == tr("&Login") )
	{
		int user_len = ( ui.login_user->text() ).size();
		int pass_len = ( ui.login_password->text() ).size();
		if( (user_len > 0) && (pass_len > 0)) ui_ok->setDisabled(0);
	}
	else
	{
		QMessageBox::warning(this, QString("Tab Error"), QString("No such tab #" + tab_title + "#"));
	}
}





















//



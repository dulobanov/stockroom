#include "login.h"
//
login::login( QWidget *parent, QString user  )
	: QDialog(parent)
{
//	init vars
	pattern = QString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_");
	set_ui();
	set_uname(user);
}














void login::set_ui()
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
	
	//	set pre username
	set_uname(pre_user);
	return;
}








void login::get_user_pass(QString &user, QString &password)
{
	user = QString( ui.login_user->text() );
	password = QString( ui.login_password->text() );
	return;
}











void login::set_uname(QString user)
{
	if( is_legal_line(user, 3) ) return;
	ui.login_user->setText(user);
	ui.login_password->setFocus();
	return;
}









int login::is_legal_line(QString string, int min_len)
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







void login::changes()
{
	// return all lines to ok
	// lock button
	ui.login_user->setPalette( line_edit_norm );
	ui.login_password->setPalette( line_edit_norm );
	ui_ok->setDisabled(1);
	
	//	if user name or password empty don't mark
	if( ( (ui.login_user->text()).size() < 1 ) || ( (ui.login_password->text()).size() < 1 ) ) return;

	if( is_legal_line( ui.login_user->text(), 3) )
	{
		ui.login_user->setPalette( line_edit_wrong );
		return;
	}

	if( is_legal_line( ui.login_password->text(), 5) )
	{
		ui.login_password->setPalette( line_edit_wrong );
		return;
	}
	ui_ok->setDisabled(0);
	return;
}












//



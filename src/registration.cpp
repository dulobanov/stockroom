#include "registration.h"
//
registration::registration( QWidget *parent )
	: QDialog(parent)
{
//	init vars
	pattern = QString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_");
	set_ui();
}














void registration::set_ui()
{
	ui.setupUi(this);
    // lock button Ok
	QList <QAbstractButton *> buttons = ui.buttonBox->buttons();
	QAbstractButton * button;
	// perebiraem knopki: ischem ok
	int count = buttons.count();
	for(int i = 0; i < count; ++i )
	{
		button = buttons[i];
		if(ui.buttonBox->buttonRole(button) == QDialogButtonBox::AcceptRole)
		{
			ui_ok = button;
			break;
		}
	}
	button->setDisabled(1);

	// load & save lineedit palletes
	line_edit_norm = line_edit_wrong = ui.user->palette();
	line_edit_wrong.setColor( QPalette::Base, QColor(255, 230, 230) );
	ui.user->setFocus();

	return;
}








int registration::get_user_pass(QString &user, QString &password, QDir &dir)
{
	//check username
	if ( is_legal_line( ui.user->text(), 3) ) return 1;

	//check password
	if( ui.pass_1->text() != ui.pass_2->text() ) return 2;
	if( is_legal_line( ui.pass_1->text(), 5 ) ) return 3;
	//	check permissions to dir
	QFileInfo idir( ui.dir->text() );
	if( !idir.isDir() ) return 4;
	if( !idir.isReadable() ) return 5;
	if( !idir.isWritable() ) return 6;
	user = QString( ui.user->text() );
	password = QString( ui.pass_1->text() );
	dir = QDir( ui.dir->text() );

	return 0;
}












int registration::is_legal_line(QString string, int min_len)
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







void registration::changes()
{
	// return all lines to ok
	// lock button
	ui.user->setPalette( line_edit_norm );
	ui.pass_1->setPalette( line_edit_norm );
	ui.pass_2->setPalette( line_edit_norm );
	ui.dir->setPalette( line_edit_norm );
	ui_ok->setDisabled(1);

	//	if user name or password empty don't mark
	if( ( (ui.user->text()).size() < 1 ) || ( (ui.pass_1->text()).size() < 1 ) || ( (ui.pass_2->text()).size() < 1 ) || ( (ui.dir->text()).size() < 1 ) ) return;

	int err = 0;

	if( is_legal_line( ui.user->text(), 3) )
	{
		ui.user->setPalette( line_edit_wrong );
		err++;
	}

	if( is_legal_line( ui.pass_1->text(), 5) )
	{
		ui.pass_1->setPalette( line_edit_wrong );
		err++;
	}

	if( is_legal_line( ui.pass_2->text(), 5) )
	{
		ui.pass_2->setPalette( line_edit_wrong );
		err++;
	}
	
	if( ui.pass_2->text() != ui.pass_1->text() )
	{
		ui.pass_2->setPalette( line_edit_wrong );
		ui.pass_1->setPalette( line_edit_wrong );
		err++;
	}

	//	check permissions to dir
	QFileInfo dir( ui.dir->text() );
	if( !dir.isDir() )
	{
		ui.dir->setPalette( line_edit_wrong );
		err++;
	}
	if( !dir.isReadable() )
	{
		ui.dir->setPalette( line_edit_wrong );
		err++;
	}
	if( !dir.isWritable() )
	{
		ui.dir->setPalette( line_edit_wrong );
		err++;
	}
	


	if (err) return;
	else ui_ok->setDisabled(0);

	return;
}












void registration::choose_dir()
{
	QString directory = QFileDialog::getExistingDirectory(this, tr("Select directory for data storing"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	ui.dir->setText( directory );
	return;
}






//



#include "settings.h"

//
settings::settings( QString organization, const QString application, QWidget *parent )
    : QSettings( QSettings::IniFormat, QSettings::UserScope, organization, application, parent )
{
	// init vars
	main_win_parent = parent;
	is_logged = 0;
	is_debug = 1;
}






int settings::init()
{
 	//	check have we users
	int ret;
	registration reg(main_win_parent);
	QString user, pass;
	QDir data_dir;
	while( value("user_count", 0).toInt() < 1 )
	{	//	no users create them
		ret = reg.exec();
		if(ret == QDialog::Accepted)
		{
			if( reg.get_user_pass(user, pass, data_dir) )
			{	// error
				continue;
			}
			//	add user
			beginGroup("users/"+user);
			setValue("password", get_hash(user, pass));
			setValue("dir", data_dir.path());
			endGroup();
			setValue("user_count", value("user_count", 0).toInt() + 1);
		}
		else
		{
			//	not acceptet -> exit
			ret = QMessageBox::question(main_win_parent, QString("Registration"), QString("You discard registration, application will be closed.\nQuit?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
			if( ret == QMessageBox::Yes ) exit(0);
		}
	}

	QString prev_user = value("previous_user", "").toString();
	beginGroup("users");
	QStringList users = childGroups();
	login ulogin(main_win_parent, prev_user);
	QString hash, tmp_dir;
	while( !is_logged )
	{	//	login while not logged
		ret = ulogin.exec();
		if( ret == QDialog::Accepted )
		{
			ulogin.get_user_pass(user, pass);
			hash = get_hash(user, pass);
			if( value(user+"/password", "").toString() != hash)
			{	//	login failed
				QMessageBox::information(main_win_parent, QString("Login"), QString("Involid username or password.\nTry again."));
				continue;
			}


			//	login success
			//	check avalible of data dir
			tmp_dir = value(user+"/dir", "").toString();
			if( check_data_dir( tmp_dir ) )
			{
				QMessageBox::information(main_win_parent, QString("Login"), QString("Involid data dir in your account.\nTry again."));
				continue;
			}

			data_dir = tmp_dir;
			is_logged = 1;
			username = user;
			endGroup();
			setValue("previous_user", user);
		}
		else
		{

			//	not accepted -> exit
			ret = QMessageBox::question(main_win_parent, QString("Login"), QString("You discard login, application will be closed.\nQuit?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
			if( ret == QMessageBox::Yes ) exit(0);
		}
	}
	return 0;
}












int settings::check_data_dir(QString dir_name)
{
	//	check permissions to dir
	QFileInfo dir( dir_name );
	if( !dir.isDir() ) return 1;
	if( !dir.isReadable() ) return 2;
	if( !dir.isWritable() ) return 3;

	return 0;

}














int settings::start_login()
{
	login login_in(main_win_parent);
	bool invite = 1;
	while( invite )
	{
		int ret = login_in.exec();
		//check pressed button
		switch(ret)
		{
			case QDialog::Accepted :
				{
					QString user, password;
					login_in.get_user_pass( user, password );
					// check is valid user password
					// user involid ret 1
					return 1;
				}
			case QDialog::Rejected :
				{
					int q = QMessageBox::question(main_win_parent, QString("Login"), QString("You discard login, application will be closed.\nQuit?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
					if(q == QMessageBox::Yes)
					{
						QMessageBox::information(main_win_parent, QString("log"), QString(ret));
						return 1;
					}
				}
				continue;
			default :
				return 1;
		}
	}
	return 1;
}







int settings::start_reg()
{
	registration reg(main_win_parent);
	reg.exec();
	return 1;
}
















int settings::get_users_count()
{
	return 0;
}









QString settings::get_hash(QString user, QString password)
{
	QByteArray str_1 = QCryptographicHash::hash( QByteArray(user.toAscii()), QCryptographicHash::Md5);
	QByteArray str_2 = QCryptographicHash::hash( QByteArray(password.toAscii()) + str_1, QCryptographicHash::Sha1);
	return ( QString( QCryptographicHash::hash( str_1 + QByteArray(user.toAscii()) +str_2 + QByteArray(password.toAscii()), QCryptographicHash::Md5 ) ) );
}








//



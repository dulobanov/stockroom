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

//__________________________ [ LOGIN ] _______________________________
	//	get users count
	int u_count = get_users_count();
	if( u_count < 1 )
	{	//	registration
		while( !is_logged )
		{
			if( registration() ) exit(0);
		}
	}
	else
	{	//	login
		while( !is_logged )
		{
			if( login() ) exit(0);
		}
//________________________ [ LOGIN END ] _______________________________
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
	if( dir_name.size() < 1 ) return 4;

	return 0;

}














int settings:get_upath(QDir &user_path)
{
	if(!is_logged)
	{
		QMessageBox::critical(main_win_parent, QString("Inormation"), QString("You are not logged yet."));
		return 1;
	}

	user_path = user_dir;
	return 0;
}

















int settings::get_users_count()
{
	//	select all groups at users group
	beginGroup("users");
	QStringList users = childGroups();
	endGroup();
	QStringList u_dirs;
	QString tmp_str;
	int pos = 0;
	//	select all data dirs
	for(int i = 0; i < users.size(); i++)
	{
		tmp_str = value("users/"+users[i]+"/dir", "").toString();
			//	check is dir defined
		if( tmp_str.size() == 0 )
		{	// delete user (wrong)
			remove( QString("users/"+users[i]) );
			users.removeAt(i);
			continue;
		}
			//	check is dir belong to other user
		if( (pos = u_dirs.indexOf( tmp_str )) != -1)
		{	//	user with same user dir exists del them
			remove( QString("users/"+users[i]) );
			users.removeAt(i);
			remove( QString("users/"+users[pos]) );
			users.removeAt(pos);
			continue;

		}
		u_dirs[i] = tmp_str;
	}
	return u_dirs.size();
}









QString settings::get_hash(QString user, QString password)
{
	QByteArray str_1 = QCryptographicHash::hash( QByteArray(user.toAscii()), QCryptographicHash::Md5);
	QByteArray str_2 = QCryptographicHash::hash( QByteArray(password.toAscii()) + str_1, QCryptographicHash::Sha1);
	return ( QString( QCryptographicHash::hash( str_1 + QByteArray(user.toAscii()) +str_2 + QByteArray(password.toAscii()), QCryptographicHash::Md5 ) ) );
}





















int settings::registration()
{
	int ret;
	registration reg(main_win_parent);
	QString user, pass;
	QDir data_dir;
	//	no users create them
	ret = reg.exec();
	if(ret == QDialog::Accepted)
	{
		if( reg.get_user_pass(user, pass, data_dir) )
		{	// error
			return 0;
		}
		//	check have same user or data dir
		if( users.indexOf(user) != -1 )
		{	//	we have same username
			QMessageBox::information(main_win_parent, QString("Registration"), QString("User with same username alredy exists.\nTry again."));
			return 0;
		}
		if( u_dirs.indexOf(data_dir.path()) != -1 )
		{	//	we have same data dir
			QMessageBox::information(main_win_parent, QString("Registration"), QString("User with same data directory alredy exists.\nTry again."));
			return 0;
		}
		//	add user
		beginGroup("users/"+user);
		setValue("password", get_hash(user, pass));
		setValue("dir", data_dir.path());
		endGroup();
		is_logged = 1;
		username = user;
		user_dir = data_dir;
		setValue("previous_user", user);
		return 0;
	}
	else
	{
		//	not acceptet -> exit
		ret = QMessageBox::question(main_win_parent, QString("Registration"), QString("You discard registration, application will be closed.\nQuit?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
		if( ret == QMessageBox::Yes ) return 1;
	}
	return 10;
}
























int settings::login()
{
	if( is_logged ) return 0;
	QString prev_user = value("previous_user", "").toString();
	beginGroup("users");
	users = childGroups();
	endGroup();
	login ulogin(main_win_parent, prev_user);
	QString hash, tmp_dir;
	//	login while not logged
	ret = ulogin.exec();
	if( ret == QDialog::Accepted )
	{
		ulogin.get_user_pass(user, pass);
		hash = get_hash(user, pass);
		if( value("users/"+user+"/password", "").toString() != hash)
		{	//	login failed
			QMessageBox::information(main_win_parent, QString("Login"), QString("Involid username or password.\nTry again."));
			return 0;
		}


		//	login success
		//	check avalible of data dir
		tmp_dir = value("users/"+user+"/dir", "").toString();
		if( check_data_dir( tmp_dir ) )
		{
			remove("users/"+user);
			QMessageBox::information(main_win_parent, QString("Login"), QString("Involid data dir in your account.\nTry again."));
			return 0;
		}

		data_dir = tmp_dir;
		is_logged = 1;
		username = user;
		setValue("previous_user", user);
	}
	else
	{
		//	not accepted -> exit
		ret = QMessageBox::question(main_win_parent, QString("Login"), QString("You discard login, application will be closed.\nQuit?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
		if( ret == QMessageBox::Yes ) return 1;
	}

	return 10;
}










//



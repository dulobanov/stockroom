#include "settings.h"

//
settings::settings( QString organization, const QString application, QWidget *parent )
    : QSettings( QSettings::IniFormat, QSettings::UserScope, organization, application, parent )
{
	// init vars
	main_win_parent = parent;
	reinit_vars();
}







int settings::reinit_vars()
{
	is_logged = 0;
	is_debug = 0;
	username.clear();
	user_dir.setPath( QString("") );
	if( users_info != 0 )
	{
		delete users_info;
		users_info = 0;
	}
	return 0;
}








int settings::init()
{

//__________________________ [ LOGIN ] _______________________________
	//	get users count
	int u_count = load_users();
	if( u_count < 1 )
	{	//	registration
		while( !is_logged )
		{
			if( sregistration() ) exit(0);
		}
	}
	else
	{	//	login
		while( !is_logged )
		{
			if( slogin() ) exit(0);
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














int settings::get_upath(QDir &user_path)
{
	if(!is_logged)
	{
		QMessageBox::critical(main_win_parent, QString("Inormation"), QString("You are not logged yet."));
		return 1;
	}

	user_path = user_dir;
	return 0;
}














int settings::load_users()
{
	if( users_info != 0 ) delete users_info;
	QList<user_info> *tmp = new QList<user_info>;
	//	select all groups at users group
	beginGroup("users");
	QStringList users = childGroups();
	endGroup();
	QStringList u_dirs;
	QString tmp_dir;
	user_info tmp_user;
	int pos = 0;
	//	select all data dirs
	for(int i = 0; i < users.size(); i++)
	{
		tmp_dir = value("users/"+users[i]+"/dir", "").toString();
			//	check is dir defined
		if( tmp_dir.size() == 0 )
		{	// delete user (wrong)
			remove( QString("users/"+users[i]) );
			users.removeAt(i);
			continue;
		}
			//	check is dir belong to other user
		if( (pos = u_dirs.indexOf( tmp_dir )) != -1)
		{	//	user with same user dir exists del them
			remove( QString("users/"+users[i]) );
			users.removeAt(i);
			remove( QString("users/"+users[pos]) );
			users.removeAt(pos);
			continue;
		}
		u_dirs[i] = tmp_dir;
			//	add to list
		tmp_user.user = users[i];
		tmp_user.dir = QDir( tmp_dir );
		tmp_user.hash = value("users/"+users[i]+"/hash", "").toString();
			//	add
		tmp->push_back(tmp_user);
	}
	users_info = tmp;
	return tmp->size();

}


int settings::get_user_by_name( QString name )
{
	for(int i = 0; i < users_info->size(); i++)
	{
		if( ((*users_info)[i]).user == name ) return i;
	}
	return -1;
}




int settings::get_user_by_path( QString path )
{
	for(int i = 0; i < users_info->size(); i++)
	{
		if( (((*users_info)[i]).dir).path() == path ) return i;
	}
	return -1;
}

















QString settings::get_hash(QString user, QString password)
{
	QByteArray str_1 = QCryptographicHash::hash( QByteArray(user.toAscii()), QCryptographicHash::Md5);
	QByteArray str_2 = QCryptographicHash::hash( QByteArray(password.toAscii()) + str_1, QCryptographicHash::Sha1);
	return ( QString( QCryptographicHash::hash( str_1 + QByteArray(user.toAscii()) +str_2 + QByteArray(password.toAscii()), QCryptographicHash::Md5 ) ) );
}





















int settings::sregistration()
{
	int ret;
	registration reg(main_win_parent);
	QString user, pass;
	QDir data_dir;
	ret = reg.exec();
	while ( !is_logged )
	{
		if(ret == QDialog::Accepted)
		{
			if( reg.get_user_pass(user, pass, data_dir) )
			{	// error
				continue;
			}
			//	check have same user or data dir
			if( get_user_by_name(user) != -1 )
			{	//	we have same username
				QMessageBox::information(main_win_parent, QString("Registration"), QString("User with same username alredy exists.\nTry again."));
				continue;
			}
			if( get_user_by_path(data_dir.path()) != -1 )
			{	//	we have same data dir
				QMessageBox::information(main_win_parent, QString("Registration"), QString("User with same data directory alredy exists.\nTry again."));
				continue;
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
	}
	return 10;
}
























int settings::slogin()
{
	if( is_logged ) return 0;
	QString prev_user = value("previous_user", "").toString();
	login ulogin(main_win_parent, prev_user);
	QString hash, tmp_dir, user, pass;
	int u_num;
	user_info try_user;
	//	login while not logged
	int ret = ulogin.exec();
	while ( !is_logged )
	{
		if( ret == QDialog::Accepted )
		{
			ulogin.get_user_pass(user, pass);
			hash = get_hash(user, pass);
			u_num = get_user_by_name( user );
			if( u_num == -1 )
			{	//	no such user
				QMessageBox::information(main_win_parent, QString("Login"), QString("Involid username or password.\nTry again."));
				continue;
			}

			try_user = (*users_info)[u_num];

			if( value("users/"+user+"/password", "").toString() != try_user.hash)
			{	//	login failed
				QMessageBox::information(main_win_parent, QString("Login"), QString("Involid username or password.\nTry again.."));
				continue;
			}

			//	login success
			//	check avalible of data dir
			tmp_dir = value("users/"+user+"/dir", "").toString();
			if( check_data_dir( tmp_dir ) )
			{
				remove("users/"+user);
				load_users();
				QMessageBox::information(main_win_parent, QString("Login"), QString("Involid data dir in your account.\nTry again."));
				continue;
			}

			user_dir.setPath( tmp_dir );
			is_logged = 1;
			username = user;
			setValue("previous_user", user);
			return 0;
		}
		else
		{
			//	not accepted -> exit
			ret = QMessageBox::question(main_win_parent, QString("Login"), QString("You discard login, application will be closed.\nQuit?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
			if( ret == QMessageBox::Yes ) return 1;
		}
	}

	return 10;
}










//



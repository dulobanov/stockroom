#ifndef SETTINGS_H
#define SETTINGS_H
//
#include <QSettings>
#include <QCryptographicHash>
#include <QStringList>
#include <QString>
#include <QDir>
#include "login.h"
#include "registration.h"
//




struct user_info
{
	QString user;
	QDir dir;
	QString hash;
};





class settings : public QSettings
{
Q_OBJECT
public:
	settings( QString organization, const QString application, QWidget *parent= 0 );
	int init();

	//	get functions
	int get_upath(QDir &user_path);





private:
	bool is_logged;
	QString username;
	QDir user_dir;
	QList <user_info> *users_info;
	bool is_debug;
	QWidget *main_win_parent;

		//	functions
	QString get_hash(QString user, QString pass);
	int check_data_dir(QString dir_name);
	int slogin();
	int sregistration();
	int load_users();
	int get_user_by_name( QString name );
	int get_user_by_path( QString path );
	int reinit_vars();



//	SLOT SIGNALS



public slots:



signals:
	void quit();




};
#endif

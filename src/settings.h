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
class settings : public QSettings
{
Q_OBJECT
public:
	settings( QString organization, const QString application, QWidget *parent= 0 );
	int init();
	int get_users_count();

	//	get functions
	int get_upath(QDir &user_path);





private:
	bool is_logged;
	QString username;
	QDir user_dir;
	bool is_debug;
	QWidget *main_win_parent;

		//	functions
	QString get_hash(QString user, QString pass);
	int check_data_dir(QString dir_name);
	int login();
	int registration();



//	SLOT SIGNALS



public slots:



signals:
	void quit();




};
#endif

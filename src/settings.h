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
	int start_login();
	int start_reg();







private:
	bool is_logged;
	QString username;
	QDir data_dir;
	bool is_debug;
	QWidget *main_win_parent;

		//	functions
	QString get_hash(QString user, QString pass);
	int check_data_dir(QString dir_name);



//	SLOT SIGNALS



public slots:



signals:
	void quit();




};
#endif

#ifndef SETTINGS_H
#define SETTINGS_H
//
#include <QSettings>
#include <QStringList>
#include <QString>
#include "login.h"
//
class settings : public QSettings
{
Q_OBJECT
public:
    settings( QString organization, const QString application, QObject * parent );
    bool settings_login();
	bool is_have_users();







private:
	bool is_logged;
    bool is_debug;
    //login *login_in;


//	SLOT SIGNALS



public slots:



signals:
	void login_reject();




};
#endif

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
	settings();
    bool settings_login();







private:
	bool is_logged;
    //login *login_in;







};
#endif

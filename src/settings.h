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







private:
	bool is_logged;
    bool is_debug;
    //login *login_in;







};
#endif

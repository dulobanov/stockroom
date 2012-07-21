#include "settings.h"

//
settings::settings( QString organization, const QString application, QObject * parent )
    : QSettings( organization, application, parent )
{
	// init vars
	is_logged = 0;
    is_debug = 1;
    QWidget wid;
    login *login_in = new login;
	connect(login_in, SIGNAL( login_fail() ), this, SIGNAL( login_reject() ));


}






bool settings::settings_login()
{
	QStringList child_groups = childGroups();
	int id = child_groups.indexOf("users");
// no users yet we must to create
    if(id == -1)
	{ // create new user dialog

	}
	return 1;
}











int settings::get_users_count()
{
	return 0;
}











//



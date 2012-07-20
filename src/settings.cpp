#include "settings.h"

//
settings::settings( QString organization, const QString application, QObject * parent = 0 )
    : QSettings(organization, application, &parent)
{
	// init vars
	is_logged = 0;
    is_debug = 1;
    login *login_in = new login(this);

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









//



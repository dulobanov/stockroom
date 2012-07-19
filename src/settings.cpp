#include "settings.h"
//
settings::settings(  )
	: QSettings()
{
	// init vars
	is_logged = 0;
}






bool settings::login()
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



#ifndef SETTINGS_H
#define SETTINGS_H
//
#include <QSettings>
#include <QStringList>
#include <QString>
//
class settings : public QSettings
{
Q_OBJECT
public:
	settings();
	bool login();







private:
	bool is_logged;








};
#endif

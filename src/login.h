#ifndef LOGIN_H
#define LOGIN_H
//
#include <QDialog>
#include <QCryptographicHash>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QByteArray>
#include "ui_login.h"
//
class login : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	login(QWidget *parent = 0);





private:
		// vars
	QString *user;
	QString *password;


		// functions
	QString get_hash(QString user, QString password);
    bool start_login(QString &user, QString &hash);
	bool set_pre_user(QString user);



};
#endif

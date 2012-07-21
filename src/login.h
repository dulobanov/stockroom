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
#include <QList>
#include <QAbstractButton>
#include <QSettings>
#include "ui_login.h"
#include <QMessageBox>
//
class login : public QDialog//, public Ui::login
{
Q_OBJECT
public:
    login(QWidget *parent = 0);





private:
		// vars
	QString *user;
	QString *password;


        // ui elements
	Ui::login ui;
	QAbstractButton *ui_ok;

		// functions
	QString get_hash(QString user, QString password);
    bool start_login(QString &user, QString &hash);
	bool set_pre_user(QString user);
	// init QDialog
	void start_ui();





//	SIGNALS SLOTS

public slots:
	void accept();
	void reject();
	void tab_switched(int tab);


signals:
	void login_success();
	void login_fail();






};
#endif

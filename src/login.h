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
#include <QPalette>
#include <QColor>
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
	QString pattern;

        // ui elements
	Ui::login ui;
	QAbstractButton *ui_ok;
	QPalette line_edit_norm, line_edit_wrong;

		// functions
	QString get_hash(QString user, QString password);
	bool start_login(QString &user, QString &hash);
	bool set_pre_user(QString user);
	bool is_legal_line(QString string, int min_len = 0);
	// init QDialog
	void start_ui();





//	SIGNALS SLOTS

public slots:
	void accept();
	void reject();
	void changes();


signals:
	void login_success();
	void login_fail();






};
#endif

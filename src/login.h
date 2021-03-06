#ifndef LOGIN_H
#define LOGIN_H
//
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QAbstractButton>
#include <QMessageBox>
#include <QPalette>
#include <QColor>
#include "ui_login.h"
//
class login : public QDialog
{
Q_OBJECT
public:
	login(QWidget *parent = 0, QString user = "");
	void get_user_pass(QString &user, QString &password);
	void set_uname(QString user = "");




private:
		// vars
	QString pre_user;
	QString pattern;

        // ui elements
	Ui::login ui;
	QAbstractButton *ui_ok;
	QPalette line_edit_norm, line_edit_wrong;

		// functions
	int is_legal_line(QString string = "", int min_len = 0);
	// init QDialog
	void set_ui();





//	SIGNALS SLOTS

public slots:
	void changes();


signals:
	void login_success(QString, QString);






};
#endif

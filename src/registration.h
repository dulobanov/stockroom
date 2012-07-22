#ifndef REG_H
#define REG_H
//
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QPalette>
#include <QColor>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include "ui_registration.h"
//
class registration: public QDialog
{
Q_OBJECT
public:
	registration(QWidget *parent = 0 );
	int get_user_pass(QString &user, QString &password, QDir &dir);




private:
		// vars
	QString pattern;

        // ui elements
	Ui::registration ui;
	QAbstractButton *ui_ok;
	QPalette line_edit_norm, line_edit_wrong;

		// functions
	int is_legal_line(QString string = "", int min_len = 0);
	// init QDialog
	void set_ui();





//	SIGNALS SLOTS

public slots:
	void changes();
	void choose_dir();


signals:






};
#endif

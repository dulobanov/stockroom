#ifndef C_LOGACT_H
#define C_LOGACT_H

#include <QWidget>
#include <QVector>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFile>
#include <QDir>
#include <QDateTime>

#include "kernel/ma_log.h"

struct files_struct
{
	ma_log *descriptor;
	QString *file_name;
	QString *hash;
	bool *changed;
};







class c_logact : public QWidget
{
    Q_OBJECT
public:
	explicit c_logact(QWidget *prnt = 0);
	~c_logact();

	quint8 init( QString usr_dir = "", QString vrnt = "", QString slct = "", QList<QString> old_files = QList<QString>() );





private:
	//	VARS
	QWidget *parent;
	QString *variant;
	QString *selection;
	QString *user_dir;
	QString *work_folder;
	QVector<files_struct *> *files;
	files_struct *runtime_file;



	//	FUNCTIONS
	QString get_runtime_fn();





signals:
	void log(QString sender, QString message);




public slots:

};

#endif // C_LOGACT_H

#include "login.h"
//
login::login( QWidget *parent  ) 
	: QDialog(parent)
{
	// TODO
}










QString login::get_hash(QString user, QString password)
{
    QByteArray str_1 = QCryptographicHash::hash( QByteArray(user.toAscii()), QCryptographicHash::Md5);
    QByteArray str_2 = QCryptographicHash::hash( QByteArray(password.toAscii()) + str_1, QCryptographicHash::Sha1);
    return ( QString( QCryptographicHash::hash( str_1 + QByteArray(user.toAscii()) +str_2 + QByteArray(password.toAscii()), QCryptographicHash::Md5 ) ) );
}








bool login::start_login(QString &user, QString &hash)
{

}









bool login::set_pre_user(QString user)
{

}







//



/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Sat Jul 21 11:50:16 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_login;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *login_user;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *login_password;
    QWidget *tab_reg;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *reg_pass_1;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *reg_pass_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *reg_user;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->setWindowModality(Qt::ApplicationModal);
        login->resize(370, 220);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setMinimumSize(QSize(370, 220));
        login->setMaximumSize(QSize(370, 220));
        QFont font;
        font.setPointSize(16);
        login->setFont(font);
        login->setModal(true);
        tabWidget = new QTabWidget(login);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 351, 161));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        tabWidget->setFont(font1);
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab_login = new QWidget();
        tab_login->setObjectName(QString::fromUtf8("tab_login"));
        horizontalLayoutWidget = new QWidget(tab_login);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 321, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        QFont font2;
        font2.setPointSize(15);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        login_user = new QLineEdit(horizontalLayoutWidget);
        login_user->setObjectName(QString::fromUtf8("login_user"));
        login_user->setFont(font);

        horizontalLayout->addWidget(login_user);

        horizontalLayoutWidget_2 = new QWidget(tab_login);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 70, 321, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        login_password = new QLineEdit(horizontalLayoutWidget_2);
        login_password->setObjectName(QString::fromUtf8("login_password"));
        login_password->setFont(font);
        login_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(login_password);

        tabWidget->addTab(tab_login, QString());
        tab_reg = new QWidget();
        tab_reg->setObjectName(QString::fromUtf8("tab_reg"));
        horizontalLayoutWidget_3 = new QWidget(tab_reg);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 50, 321, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setFont(font2);

        horizontalLayout_3->addWidget(label_3);

        reg_pass_1 = new QLineEdit(horizontalLayoutWidget_3);
        reg_pass_1->setObjectName(QString::fromUtf8("reg_pass_1"));
        reg_pass_1->setFont(font);
        reg_pass_1->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(reg_pass_1);

        horizontalLayoutWidget_4 = new QWidget(tab_reg);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 90, 321, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setFont(font2);

        horizontalLayout_4->addWidget(label_4);

        reg_pass_2 = new QLineEdit(horizontalLayoutWidget_4);
        reg_pass_2->setObjectName(QString::fromUtf8("reg_pass_2"));
        reg_pass_2->setFont(font);
        reg_pass_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(reg_pass_2);

        horizontalLayoutWidget_5 = new QWidget(tab_reg);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 10, 321, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setFont(font2);

        horizontalLayout_5->addWidget(label_5);

        reg_user = new QLineEdit(horizontalLayoutWidget_5);
        reg_user->setObjectName(QString::fromUtf8("reg_user"));
        reg_user->setFont(font);

        horizontalLayout_5->addWidget(reg_user);

        tabWidget->addTab(tab_reg, QString());
        buttonBox = new QDialogButtonBox(login);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 180, 321, 31));
        QFont font3;
        font3.setPointSize(14);
        buttonBox->setFont(font3);
        buttonBox->setInputMethodHints(Qt::ImhNone);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(login_user);
        label_2->setBuddy(login_password);
        label_3->setBuddy(reg_pass_1);
        label_4->setBuddy(reg_pass_2);
        label_5->setBuddy(reg_user);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(login_user, login_password);
        QWidget::setTabOrder(login_password, buttonBox);
        QWidget::setTabOrder(buttonBox, reg_user);
        QWidget::setTabOrder(reg_user, reg_pass_1);
        QWidget::setTabOrder(reg_pass_1, reg_pass_2);
        QWidget::setTabOrder(reg_pass_2, tabWidget);

        retranslateUi(login);
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), login, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_login->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("login", "&User", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        login_user->setToolTip(QApplication::translate("login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">acceptable name must constist of underline symbol,  latin alfabet symbols (a-zA-z), numbers (0-9)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("login", "&Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        login_password->setToolTip(QApplication::translate("login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">acceptable password must constist of underline symbol,  latin alfabet symbols (a-zA-z), numbers (0-9)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_login), QApplication::translate("login", "&Login", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("login", "&Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        reg_pass_1->setToolTip(QApplication::translate("login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">acceptable password must constist of underline symbol,  latin alfabet symbols (a-zA-z), numbers (0-9)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("login", "P&assword", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        reg_pass_2->setToolTip(QApplication::translate("login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">acceptable password must constist of underline symbol,  latin alfabet symbols (a-zA-z), numbers (0-9)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("login", "&User", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        reg_user->setToolTip(QApplication::translate("login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">acceptable name must constist of underline symbol,  latin alfabet symbols (a-zA-z), numbers (0-9)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_reg), QApplication::translate("login", "&Registration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

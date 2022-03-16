#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("login");
    connect(ui->btnLogin,&QPushButton::clicked,this,&LoginDialog::slotsLoginClicked);
    connect(ui->btnCancel,&QPushButton::clicked,this,&LoginDialog::slotsCancelClicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::slotsLoginClicked()
{
    QString strUsername =ui->editUserName->text();
    QString strPassword =ui->editPassword->text();
    emit signalsUserInfo(strUsername,strPassword);
     close();
}

void LoginDialog::slotsCancelClicked()
{
    close();
}

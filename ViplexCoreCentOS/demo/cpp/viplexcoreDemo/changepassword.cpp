#include "changepassword.h"
#include "QMessageBox"
#pragma execution_character_set("utf-8")

Changepassword::Changepassword(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()),this,SLOT(slotClickedSure()));
}

void Changepassword::setCallback(std::function<void(const std::string oldpassword, const std::string newpassword)> callback)
{
    m_callback = callback;
}

void Changepassword::slotClickedSure()
{
    QString strOldPassword = ui.lineEdit->displayText();
    QString strNewPassword = ui.lineEdit_2->displayText();
    QMessageBox::about(NULL, "提示", "修改密码 测试");
    m_callback(strOldPassword.toStdString(), strNewPassword.toStdString());
}

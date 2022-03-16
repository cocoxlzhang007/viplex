#pragma once

#include <QtWidgets/QWidget>
#include "ui_changepassword.h"


class Changepassword : public QWidget
{
    Q_OBJECT

public:
    Changepassword(QWidget *parent = Q_NULLPTR);
    void setCallback(std::function<void(const std::string oldpassword, const std::string newpassword)>);
private:
    Ui::ChangepasswordClass ui;
    std::function<void(const std::string oldpassword, const std::string newpassword)> m_callback;
private slots:
    void slotClickedSure();
};

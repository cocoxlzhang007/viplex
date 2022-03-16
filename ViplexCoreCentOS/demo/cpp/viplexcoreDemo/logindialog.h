#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
private slots:
    void slotsLoginClicked();
    void slotsCancelClicked();
    private:
    Ui::LoginDialog *ui;
signals:
    void signalsUserInfo(QString,QString);
};

#endif // LOGINDIALOG_H

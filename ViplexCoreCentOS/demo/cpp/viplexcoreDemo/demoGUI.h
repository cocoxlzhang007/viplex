#pragma once
#include <QtWidgets/QWidget>
#include <QTableView>
#include "ui_demoGUI.h"
#include "QStandardItemModel"
#include "qevent.h"
#include "demoChildGUI.h"
#include "changepassword.h"
#include "viplexcommon/jsonserializer/jsonserializer.h"

class DemoGUI : public QWidget
{
    Q_OBJECT

public:
    DemoGUI(QWidget *parent = Q_NULLPTR);
    ~DemoGUI();

public:
    QDialog *dialog;
    QDialog *rangeDialog;
    QPushButton *ip_button_start;
    QPushButton *ip_button_quit;
    QPushButton *ip_range_button_start;
    QPushButton *ip_range_button_quit;
    QLabel *ip_Label;
    QLabel *ip_Label_Begin;
    QLabel *ip_Label_Last;
    QLineEdit *ip_lineedit;
    QLineEdit *ip_lineedit_Begin;
    QLineEdit *ip_lineedit_Last;

private:
    Ui::DemoGUIClass ui;
    DemoChildGUI demoChildGUI;
    Changepassword changepassword;
    //ViplexCallback m_resultCallBack;
    void setTableContent(const std::string &data);

    vector<ns::SearchResponseData> vectorSearchData;
    int i = 0;
    int row = 0;
    void testAPI(const std::string &APIname,const std::string &data);
    void AppointIpInit();
    void SpecifyRangeIpInit();

    std::string ip_begin_str_dot_back;//记录起始ip.后面的字符
    std::string ip_last_str_dot_back;//记录终止ip.后面的字符
    std::string ip_begin_str_dot_front;//记录起始ip.前面的字符
    std::string	ip_last_str_dot_front;//记录终止ip.前面的字符
    size_t ip_begin_position;
    size_t ip_last_position;
    std::string ip_itos;//记录起始ip.后面的字符串，获取所有的.后面的字符串
    std::string serchIp;//记录要被要搜索的拼接ip
    size_t ip_stoi_begin;//记录起始ip.后面字符转数字
    size_t ip_stoi_last;//记录终止ip.后面字符转数字
protected:
    virtual void contextMenuEvent(QContextMenuEvent  *event) override;
signals:
    void signalsendSN(QString);
    void signalsendResponseData(int,QString);
    void signalDissconnect(int, QString);
    void signalSerch(int, QString);
    void signalLogin( int, QString);
private slots:
    //void slotsGetItem(QTableWidgetItem *item);
    void slotsGetIndex(int,int);

    void slotsConnect();
    void slotsConnectSys();
    void slotsConnectPublicnet();
    void slotsQuit();
    void slotsRename();
    void slotsRepassword();
    void slotsForgetPassword();
    void slotsDownload();
    void slotClickedSearch();
    void slotDissconnect(int, QString);
    void slotSerch(int, QString);
    void slotLogin(int, QString);
    void on_pushButton_2_clicked();
    void on_slotsIp_button_start_clicked();
    void on_specifyRangeIpButton_clicked();
    void on_slotsRange_Ip_button_start_clicked();
};

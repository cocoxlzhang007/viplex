#include "demoGUI.h"
#include <QStandardItemModel>
#include "QObject"
#include "QAbstractItemView"
#include <QMenu>
#include"QDebug"
#include <thread>
#include "QDialog"
#include"QMessageBox"
#include<QHeaderView>
#include "exportviplexcoreasync.h"
#include "viplexcoreasync.h"
#include "viplexcommon/jsonserializer/jsonserializer.h"
#include "viplexcommon/fromstring.h"
#include "logindialog.h"
#include "exportviplexcore.h"
#include "exportviplexcoreasync.h"
#include "viplexcoreasync.h"
#pragma execution_character_set("utf-8")

using namespace std;

DemoGUI::DemoGUI(QWidget *parent)
    : QWidget(parent)
{
    AppointIpInit();
    SpecifyRangeIpInit();
    ui.setupUi(this);
    ui.tableWidget->setColumnCount(4);

    //设置行数
    ui.tableWidget->setRowCount(100);
    QStringList sListHeader;
    sListHeader << "终端名称" << "状态" << "终端IP" << "显示屏大小";
    ui.tableWidget->setHorizontalHeaderLabels(sListHeader);
    //不可编辑，每次选中一行数据
    ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //列间距平均分割
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    connect(this, SIGNAL(signalsendSN(QString)), &demoChildGUI, SLOT(soltsGetSN(QString)));
    connect(this, SIGNAL(signalsendResponseData(int, QString)), &demoChildGUI, SLOT(soltGetResponseData(int, QString)));
    connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slotsGetIndex(int, int)));
    connect(this, &DemoGUI::signalDissconnect, this, &DemoGUI::slotDissconnect, Qt::QueuedConnection);
    connect(this, &DemoGUI::signalSerch, this, &DemoGUI::slotSerch, Qt::QueuedConnection);
    connect(this, &DemoGUI::signalLogin, this, &DemoGUI::slotLogin, Qt::QueuedConnection);

    //ViplexCore::getInstance().init("C:/Users/Public/viplexcore", enNova);

    string strDir = "C:/Users/Public/viplexcore";
    string credentials = "{\"company\":\"NovaStar\",\"phone\":\"029-68216000\",\"email\":\"hr@novastar.tech\"}";
    ViplexCoreAsync::nvInit(strDir.c_str(), credentials.c_str());
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotClickedSearch()));
    connect(ip_button_start, SIGNAL(clicked()), this, SLOT(on_slotsIp_button_start_clicked()));
    connect(ip_range_button_start, SIGNAL(clicked()), this, SLOT(on_slotsRange_Ip_button_start_clicked()));
    connect(ip_button_quit, SIGNAL(clicked()), dialog, SLOT(close()));
    connect(ip_range_button_quit, SIGNAL(clicked()), rangeDialog, SLOT(close()));


    //string initdata = "{\"publicModule\":true,\"encrypt\":false,\"certificatePath\":\"E:/vplayergit/vplayer301/viplexcore_pubtmp/viplexcore/build/RelWithDebInfo/bin/cert\",\"port\":16603,\"httpserverUrl\":\"http://192.168.1.101:8080\",\"httpserverLocalPath\":\"E:/httpserverpath\"}";
    //ViplexCoreAsync::nvInitPublicNetAsync(initdata.c_str(), [=](const uint16_t code, const char *data) {
    //    emit signalSerch((uint16_t)code, QString::fromStdString(data));
    //    }, [=](const uint16_t code, const char* data) {
    //        qDebug() << "guzh disconnect:" << QString::fromStdString(data);
    //        emit signalDissconnect(code, QString::fromStdString(data));
    //    });

    slotClickedSearch();
}

DemoGUI::~DemoGUI()
{
    ViplexCoreAsync::nvStopPublicNetAsync([=](const uint16_t code, const char *data) {
        qDebug() << "nvStopPublicNetAsync";
    });
}

void DemoGUI::setTableContent(const std::string &data)
{
    ns::SearchResponseData searchResponseData;
    from_string(data, searchResponseData);

    vectorSearchData.push_back(searchResponseData);
    //添加数据
    ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(searchResponseData.aliasName)));
    QString strIslogined;
    if (searchResponseData.logined)
    {
        strIslogined = "已被上位机登录";
    }
    else
    {
        strIslogined = "未登录";
    }
    ui.tableWidget->setItem(i, 1, new QTableWidgetItem(strIslogined));
    ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(searchResponseData.ip)));
    QString strSize = QString::number(searchResponseData.width) + "*" + QString::number(searchResponseData.height);
    ui.tableWidget->setItem(i, 3, new QTableWidgetItem(strSize));
    i++;
}


void DemoGUI::contextMenuEvent(QContextMenuEvent *event)
{
    QPoint point = event->pos(); //得到窗口坐标
    row = ui.tableWidget->indexAt(point).row();

    //右键菜单选项
    QMenu *menu = new QMenu(ui.tableWidget);
    QAction *aconnect = new QAction("连接", ui.tableWidget);
    QAction *aconnectsys = new QAction("连接system", ui.tableWidget);
    QAction *aconnectpublic = new QAction("连接公网", ui.tableWidget);
    QAction *aQuit = new QAction("退出", ui.tableWidget);
    QAction *aRename = new QAction("重命名", ui.tableWidget);
    QAction *aRepassword = new QAction("修改密码", ui.tableWidget);
    QAction *aforgetPassword = new QAction("忘记密码", ui.tableWidget);
    QAction *adwonload = new QAction("下载运行日志", ui.tableWidget);
    menu->addAction(aconnect);
    menu->addAction(aconnectsys);
    menu->addAction(aconnectpublic);
    menu->addAction(aQuit);
    menu->addAction(aRename);
    menu->addAction(aRepassword);
    menu->addAction(aforgetPassword);
    menu->addAction(adwonload);

    //菜单栏信号槽连接
    connect(aconnect, SIGNAL(triggered(bool)), this, SLOT(slotsConnect()));
    connect(aconnectsys, SIGNAL(triggered(bool)), this, SLOT(slotsConnectSys()));
    connect(aconnectpublic, SIGNAL(triggered(bool)), this, SLOT(slotsConnectPublicnet()));
    connect(aQuit, SIGNAL(triggered(bool)), this, SLOT(slotsQuit()));
    connect(aRename, SIGNAL(triggered(bool)), this, SLOT(slotsRename()));
    connect(aRepassword, SIGNAL(triggered(bool)), this, SLOT(slotsRepassword()));
    connect(aforgetPassword, SIGNAL(triggered(bool)), this, SLOT(slotsForgetPassword()));
    connect(adwonload, SIGNAL(triggered(bool)), this, SLOT(slotsDownload()));


    menu->move(cursor().pos());
    menu->show();
}


void DemoGUI::slotsGetIndex(int row, int column)
{
    demoChildGUI.show();
    std::string strSn = vectorSearchData.at(row).sn;
    emit signalsendSN(QString::fromStdString(strSn));
    demoChildGUI.setCallback([=](const std::string &APIname, const std::string &requestData) {
        testAPI(APIname, requestData);
    });
}
void DemoGUI::testAPI(const std::string &APIname, const std::string &para)
{
    const char * data = para.c_str();
    if ("getIcareConfigInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetIcareConfigInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setIcareConfigInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetIcareConfigInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getBindPlayer()" == APIname)
    {
        ViplexCoreAsync::nvGetBindPlayerAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setBindPlayer()" == APIname)
    {
        ViplexCoreAsync::nvSetBindPlayerAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getCloudPlayerList()" == APIname)
    {
        ViplexCoreAsync::nvGetCloudPlayerListAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getPlayerIdentifer()" == APIname)
    {
        ViplexCoreAsync::nvGetPlayerIdentiferAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getNodeServerList()" == APIname)
    {
        ViplexCoreAsync::nvGetNodeServerListAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("addNodeServerList()" == APIname)
    {
        ViplexCoreAsync::nvAddNodeServerListAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deleteNodeServerList()" == APIname)
    {
        ViplexCoreAsync::nvDeleteNodeServerListAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("changeNodeServerList()" == APIname)
    {
        ViplexCoreAsync::nvChangeNodeServerListAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getVolume()" == APIname)
    {
        ViplexCoreAsync::nvGetVolumeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setVolume()" == APIname)
    {
        ViplexCoreAsync::nvSetVolumeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getCurrentTimeAndZone()" == APIname)
    {
        ViplexCoreAsync::nvGetCurrentTimeAndZoneAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("calibrateTime()" == APIname)
    {
        ViplexCoreAsync::nvCalibrateTimeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getColorTemperature()" == APIname)
    {
        ViplexCoreAsync::nvGetColorTemperatureAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setColorTemperature()" == APIname)
    {
        ViplexCoreAsync::nvSetColorTemperatureAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getNetTimingListInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetNetTimingListInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("addNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvAddNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deleteNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvDeleteNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvUpdateNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setBrightnessAdjustMode()" == APIname) {
        ViplexCoreAsync::nvSetBrightnessAdjustModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getBrightnessAdjustMode()" == APIname) {
        ViplexCoreAsync::nvGetBrightnessAdjustModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenBrightness()" == APIname) {
        ViplexCoreAsync::nvSetScreenBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenBrightness()" == APIname) {
        ViplexCoreAsync::nvGetScreenBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getBrightnessPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetBrightnessPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setBrightnessPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetBrightnessPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerAdjustMode()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerAdjustMode()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerState()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerStateAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerState()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerStateAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getEnvironmentBrightness()" == APIname)
    {
        ViplexCoreAsync::nvGetEnvironmentBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenUnitTemp()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenUnitTempAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getNetTimingListInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetNetTimingListInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("addNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvAddNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deleteNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvDeleteNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvUpdateNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setBrightnessAdjustMode()" == APIname) {
        ViplexCoreAsync::nvSetBrightnessAdjustModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getBrightnessAdjustMode()" == APIname) {
        ViplexCoreAsync::nvGetBrightnessAdjustModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenBrightness()" == APIname) {
        ViplexCoreAsync::nvSetScreenBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenBrightness()" == APIname) {
        ViplexCoreAsync::nvGetScreenBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getBrightnessPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetBrightnessPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setBrightnessPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetBrightnessPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerAdjustMode()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerAdjustMode()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerState()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerStateAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerState()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerStateAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerManual0x99()" == APIname)
    {
        ViplexCoreAsync::nvsetScreenPowerManual0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerPolicy0x99()" == APIname)
    {
        ViplexCoreAsync::nvsetScreenPowerPolicy0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("GetScreenPowerPolicyFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerPolicyFor0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerManual0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerManual0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getEnvironmentBrightness()" == APIname)
    {
        ViplexCoreAsync::nvGetEnvironmentBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenUnitTemp()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenUnitTempAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }


    if ("getAvailableStorageData()" == APIname)
    {
        ViplexCoreAsync::nvGetAvailableStorageDataAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getCPUUsage()" == APIname)
    {
        ViplexCoreAsync::nvGetCPUUsageAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getCPUTemp()" == APIname)
    {
        ViplexCoreAsync::nvGetCPUTempAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getAvailableMemory()" == APIname)
    {
        ViplexCoreAsync::nvGetAvailableMemoryAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenAttribute()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenAttributeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenAttribute()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenAttributeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getconfiguration()" == APIname)
    {
        ViplexCoreAsync::nvGetconfigurationAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getFirmwareInfos()" == APIname)
    {
        ViplexCoreAsync::nvGetFirmwareInfosAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getInstalledPackageVersions()" == APIname)
    {
        ViplexCoreAsync::nvGetInstalledPackageVersionsAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getProductInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetProductInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("GetSpliceInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetSpliceInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("SetSpliceInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetSpliceInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("GetReBootTask()" == APIname)
    {
        ViplexCoreAsync::nvGetReBootTaskAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("SetReBootTask()" == APIname)
    {
        ViplexCoreAsync::nvSetReBootTaskAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getUri()" == APIname)
    {
        //todo
    }

    else if ("SetRecvCardFile()" == APIname)
    {
        ViplexCoreAsync::nvSetRecvCardFileAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    //else if ("SetRecvCardFileSetScreen()" == APIname)
    //{
    //ViplexCore::getScreenSetting()->SetRecvCardFileSetScreen(data,fileName, [=](const int errorCode, const std::string &result) {
    //    emit signalsendResponseData(errorCode, QString::fromStdString(result));
    //});
    //}
    else if ("getTimeZone()" == APIname)
    {
        ViplexCoreAsync::nvGetTimeZoneAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }


    else if ("getProgramInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetProgramInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deletePlayList()" == APIname)
    {
        ViplexCoreAsync::nvDeletePlayListAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("startPlay()" == APIname)
    {
        ViplexCoreAsync::nvStartPlayAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("startPlay1()" == APIname)
    {
        ViplexCoreAsync::nvStartPlayAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("pausePlay()" == APIname)
    {
        ViplexCoreAsync::nvPausePlayAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("resumePlay()" == APIname)
    {
        ViplexCoreAsync::nvResumePlayAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("stopPlay()" == APIname)
    {
        ViplexCoreAsync::nvStopPlayAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("playListTransferError()" == APIname)
    {
        //TODO
    }

    else if ("downLoadFiles()" == APIname)
    {
        ViplexCoreAsync::nvDownLoadFilesAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("queryFileByType()" == APIname)
    {
        ViplexCoreAsync::nvQueryFileByTypeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setSyncPlay()" == APIname)
    {
        ViplexCoreAsync::nvSetSyncPlayAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getSyncPlay()" == APIname)
    {
        ViplexCoreAsync::nvGetSyncPlayAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("reboot()" == APIname)
    {
        ViplexCoreAsync::nvRebootAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("setReBootWipeUserData()" == APIname)
    {
        ViplexCoreAsync::nvSetReBootWipeUserDataAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("clearAllMedias()" == APIname)
    {
        ViplexCoreAsync::nvClearAllMediasAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getOTGUSBMode()" == APIname)
    {
        ViplexCoreAsync::nvGetOTGUSBModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("setOTGUSBMode()" == APIname)
    {
        ViplexCoreAsync::nvSetOTGUSBModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("setCurrentResolutio()" == APIname)
    {
        ViplexCoreAsync::nvSetCurrentResolutioAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getCurrentResolution()" == APIname)
    {
        ViplexCoreAsync::nvGetCurrentResolutionAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getSupportedResolution()" == APIname)
    {
        ViplexCoreAsync::nvGetSupportedResolutionAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setCustomResolution()" == APIname)
    {
        ViplexCoreAsync::nvSetCustomResolutionAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getHdmiOutputStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetHdmiOutputStatusAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setHdmiOutputStatus()" == APIname)
    {
        ViplexCoreAsync::nvSetHdmiOutputStatusAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getAPNetwork()" == APIname)
    {
        ViplexCoreAsync::nvGetAPNetworkAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("setAPNetwork()" == APIname)
    {
        ViplexCoreAsync::nvSetAPNetworkAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getVideoControlInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetVideoControlInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("setVideoControlInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetVideoControlInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("startGetAvailableMemoryData()" == APIname)
    {
        ViplexCoreAsync::nvStartGetAvailableMemoryDataAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("finishData()" == APIname)
    {
        ViplexCoreAsync::nvFinishDataAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getWifiList()" == APIname)
    {
        ViplexCoreAsync::nvGetWifiListAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("connectWifiNetwork()" == APIname)
    {
        ViplexCoreAsync::nvConnectWifiNetworkAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getWifiCurrentStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetWifiCurrentStatusAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("disconnectWifiNetwork()" == APIname)
    {
        ViplexCoreAsync::nvDisconnectWifiNetworkAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getWifiEnabled()" == APIname)
    {
        ViplexCoreAsync::nvGetWifiEnabledAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("setWifiEnabled()" == APIname)
    {
        ViplexCoreAsync::nvSetWifiEnabledAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("sendForgetWifiCommand()" == APIname)
    {
        ViplexCoreAsync::nvSendForgetWifiCommandAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getMobileNetwork()" == APIname)
    {
        ViplexCoreAsync::nvGetMobileNetworkAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setMobileNetwork()" == APIname)
    {
        ViplexCoreAsync::nvSetMobileNetworkAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("isMobileModuleExisted()" == APIname)
    {
        ViplexCoreAsync::nvIsMobileModuleExistedAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getEthernetInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetEthernetInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setEthernetInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetEthernetInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("AMGetInstalledPackageInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetInstalledPackageInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("GetRunningPackageInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetRunningPackageInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("ForceStopApp()" == APIname)
    {
        ViplexCoreAsync::nvForceStopAppAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("UninstallPackage()" == APIname)
    {
        ViplexCoreAsync::nvUninstallPackageAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    if ("runApp()" == APIname)
    {

        //todo
    }
    else if ("queryUpdateFileByType()" == APIname)
    {
        ViplexCoreAsync::nvQueryUpdateFileByTypeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("readFileContentFromZipFile()" == APIname)
    {
        ViplexCoreAsync::nvReadFileContentFromZipFileAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateApp()" == APIname)
    {
        ViplexCoreAsync::nvUpdateAppAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateOS()" == APIname)
    {
        ViplexCoreAsync::nvUpdateOSAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("stopCurrentUpdateTask()" == APIname)
    {
        ViplexCoreAsync::nvStopCurrentUpdateTaskAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateAppVerify()" == APIname)
    {
        ViplexCoreAsync::nvUpdateVerifyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateOSVerify()" == APIname)
    {
        ViplexCoreAsync::nvUpdateVerifyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("createProgram()" == APIname)
    {
        ViplexCoreAsync::nvCreateProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("makeProgram()" == APIname)
    {
        ViplexCoreAsync::nvMakeProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("addPage()" == APIname)
    {
        //TODO
        /*ViplexCore::getEditProgram()->addPage(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });*/
    }
    else if ("setPageParam()(图片、视频、GIF简化)" == APIname || "setPageParam()(数字时钟简化)" == APIname || "setPageParam()(文本简化)" == APIname || "setPageParam()(图片)" == APIname || "setPageParam()(RSS)" == APIname || "setPageParam()(炫彩字)" == APIname || "setPageParam()(环境监测)" == APIname || "setPageParam()(计时器)" == APIname || "setPageParam()(RSS简化)" == APIname || "setPageParam()(炫彩字简化)" == APIname || "setPageParam()(环境监测简化)" == APIname || "setPageParam()(计时器简化)" == APIname || "setPageParam()(网页)" == APIname || "setPageParam()(流媒体)" == APIname)
    {
        ViplexCoreAsync::nvSetPageProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getPageParam()" == APIname)
    {
        ViplexCoreAsync::nvGetProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deletePage()" == APIname)
    {
        //TODO
        //ViplexCore::getEditProgram()->deletePage(data, [=](const int errorCode, const std::string &result) {
        //	emit signalsendResponseData(errorCode, QString::fromStdString(result));
        //});
    }
    else if ("addWidget()" == APIname)
    {
        //TODO
        //ViplexCore::getEditProgram()->addWidget(data, [=](const int errorCode, const std::string &result) {
        //	emit signalsendResponseData(errorCode, QString::fromStdString(result));
        //});
    }
    else if ("setWidgetParam()" == APIname)
    {
        //TODO
        //ViplexCore::getEditProgram()->setWidgetParam(data, [=](const int errorCode, const std::string &result) {
        //	emit signalsendResponseData(errorCode, QString::fromStdString(result));
        //});
    }
    else if ("getWidgetParam()" == APIname)
    {
        //TODO
        /*	ViplexCore::getEditProgram()->getWidgetParam(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });*/
    }
    else if ("deleteWidget()" == APIname)
    {
        //TODO
        //ViplexCore::getEditProgram()->deleteWidgetAsync(data, [=](const int errorCode, const std::string &result) {
        //	emit signalsendResponseData(errorCode, QString::fromStdString(result));
        //});
    }
    else if ("addTpl()" == APIname)
    {
        ViplexCoreAsync::nvAddTplAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setSystemTplInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetSystemTplInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("editTpl()" == APIname)
    {
        ViplexCoreAsync::nvEditTplAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deleteTpl()" == APIname)
    {
        ViplexCoreAsync::nvDeleteTplAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getProgram()" == APIname)
    {
        ViplexCoreAsync::nvGetProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deleteProgram()" == APIname)
    {
        ViplexCoreAsync::nvDeleteProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("startTransferProgram()" == APIname)
    {
        ViplexCoreAsync::nvStartTransferProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("startTransferProgram1()" == APIname)
    {
        ViplexCoreAsync::nvStartTransferProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("stopProgramTransfer()" == APIname)
    {
        ViplexCoreAsync::nvStopProgramTransferAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setPageParams()" == APIname)
    {
        ViplexCoreAsync::nvSetPageProgramsAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setAudioMedioProgram()" == APIname)
    {
        ViplexCoreAsync::nvSetAudioMedioProgramAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setTerminalInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetTerminalInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("delTerminalInfo()" == APIname)
    {
        ViplexCoreAsync::nvDelTerminalInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setUserInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetUserInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getUserInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetUserInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("dataBaseMigration()" == APIname)
    {
        ViplexCoreAsync::nvDataBaseMigrationAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("getCustomerTpl()" == APIname)
    {
        ViplexCoreAsync::nvGetCustomerTplAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("uploadFeedbackInfo()" == APIname)
    {
        ViplexCoreAsync::nvUploadFeedbackInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    if ("StartUploadApk()" == APIname)
    {
        ViplexCoreAsync::nvStartUploadApkCoreAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("setTimingPowerSwitchStatus()" == APIname)
    {
        ViplexCoreAsync::nvSetTimingPowerSwitchStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getTimingPowerSwitchStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetTimingPowerSwitchStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getRealtimePowerSwitchStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetRealtimePowerSwitchStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setManualPowerSwitchStatus()" == APIname)
    {
        ViplexCoreAsync::nvSetManualPowerSwitchStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("logOut()" == APIname)
    {
        ViplexCoreAsync::nvLogOutAsync([=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    else if ("getManualPowerSwitchStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetManualPowerSwitchStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getAPNInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetAPNInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setAPNInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetAPNInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setFlightMode()" == APIname)
    {
        ViplexCoreAsync::nvSetFlightModeAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getFlightMode()" == APIname)
    {
        ViplexCoreAsync::nvGetFlightModeAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("get4GNetworkStatus()" == APIname)
    {
        ViplexCoreAsync::nvGet4GNetworkStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getAPNetworkOpenStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetAPNetworkOpenStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setAPNetworkOpenStatus()" == APIname)
    {
        ViplexCoreAsync::nvSetAPNetworkOpenStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setWifiApStationSwitch()" == APIname)
    {
        ViplexCoreAsync::nvSetWifiApStationSwitchAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getModuleInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetModuleInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("addCollector()" == APIname)
    {
        ViplexCoreAsync::nvAddCollectorAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("deleteCollector()" == APIname)
    {
        ViplexCoreAsync::nvDeleteCollectorAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getSendCardMonitorInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetSendCardMonitorInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getReceiverCountAndInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetReceiverCountAndInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getMonitorInfoByReceiverIndex()" == APIname)
    {
        ViplexCoreAsync::nvGetMonitorInfoByReceiverIndexAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("downloadScreenShot()" == APIname)
    {
        ViplexCoreAsync::nvDownLoadScreenshotAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("downloadScreenShotNet()" == APIname)
    {
        ViplexCoreAsync::nvDownLoadScreenshotNetAsync(data, [=](const int errorcode, const std::string& result)
            {
                emit signalsendResponseData(errorcode, QString::fromStdString(result));
            });
    }
    else if ("getNetTimingListInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetNetTimingListInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("addNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvAddNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deleteNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvDeleteNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateNetTimingInfo()" == APIname)
    {
        ViplexCoreAsync::nvUpdateNetTimingInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setBrightnessAdjustMode()" == APIname) {
        ViplexCoreAsync::nvSetBrightnessAdjustModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getBrightnessAdjustMode()" == APIname) {
        ViplexCoreAsync::nvGetBrightnessAdjustModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenBrightness()" == APIname) {
        ViplexCoreAsync::nvSetScreenBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenBrightness()" == APIname) {
        ViplexCoreAsync::nvGetScreenBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getBrightnessPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetBrightnessPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setBrightnessPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetBrightnessPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerAdjustMode()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerAdjustMode()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerModeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerState()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerStateAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerState()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerStateAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenPowerPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerManual0x99()" == APIname)
    {
        ViplexCoreAsync::nvsetScreenPowerManual0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("setScreenPowerPolicy0x99()" == APIname)
    {
        ViplexCoreAsync::nvsetScreenPowerPolicy0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("GetScreenPowerPolicyFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerPolicyFor0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerManual0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerManual0x99Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenPowerPolicyAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getEnvironmentBrightness()" == APIname)
    {
        ViplexCoreAsync::nvGetEnvironmentBrightnessAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getScreenUnitTemp()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenUnitTempAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    else if ("setRotation()" == APIname)
    {
        ViplexCoreAsync::nvSetRotationAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getRotation()" == APIname)
    {
        ViplexCoreAsync::nvGetRotationAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getDisplayInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetDisplayInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setTimeAndZone()" == APIname)
    {
        ViplexCoreAsync::nvSetTimeAndZoneAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setScreenShot()" == APIname)
    {
        ViplexCoreAsync::nvSetScreenShotAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setRotation()" == APIname)
    {
        ViplexCoreAsync::nvSetRotationAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    else if ("setVPNConnectInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetVPNConnectInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getVPNConnectInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetVPNConnectInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("VPNManagerFor0x99()" == APIname)
    {
        /*ViplexCore::getVPNConnection()->VPNManagerFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });*/
    }
    else if ("setVPNConnectInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetVPNConnectInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getVPNConnectInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetVPNConnectInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("VPNManagerFor0x99()" == APIname)
    {
        //todo
        /*ViplexCore::getVPNConnection()->VPNManagerFor0x99(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });*/
    }

    if ("getIsUseDayLightTime()" == APIname)
    {
        ViplexCoreAsync::nvGetIsUseDayLightTimeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getPlaylogPath()" == APIname)
    {
        ViplexCoreAsync::nvGetPlaylogPathAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getThirdPackageinfos()" == APIname)
    {

        //TODO
    }

    else if ("getTerminalService()" == APIname)
    {
        //TODO

    }
    else if ("startService()" == APIname)
    {
        //TODO

    }
    else if ("stopService()" == APIname)
    {
        //TODO

    }
    else if ("getPlayFontUploadPath()" == APIname)
    {
        //TODO

    }
    else if ("getTerminalFont()" == APIname)
    {
        ViplexCoreAsync::nvGetTerminalFontAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("deleteFont()" == APIname)
    {
        ViplexCoreAsync::nvDeleteFontAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("updateFont()" == APIname)
    {
        ViplexCoreAsync::nvUpdateFontAsync(data, [=](const int errorCode, const std::string &result)
        {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }

    if ("setTimingVolume()" == APIname)
    {
        ViplexCoreAsync::nvSetTimingVolumeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getTimingVolume()" == APIname)
    {
        ViplexCoreAsync::nvGetTimingVolumeAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("getRunningLogPath()" == APIname)
    {
        //TODO
    }
    if ("getFileMD5()" == APIname)
    {
        ViplexCoreAsync::nvGetFileMD5Async(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    else if ("isFileExisted()" == APIname)
    {
        //todo
    }
    else if ("deleteFile()" == APIname)
    {
        //todo
    }
    else if ("getLoraInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetLoraInfoAsync(data, [=](const int errorCode, const std::string &result) {
            emit signalsendResponseData(errorCode, QString::fromStdString(result));
        });
    }
    if ("getPickerReceiver()" == APIname)
    {
        ViplexCoreAsync::nvGetPickerReceiverAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    if ("setVideoEDID()" == APIname)
    {
        ViplexCoreAsync::nvSetVideoEDIDAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getVideoEDID()" == APIname)
    {
        ViplexCoreAsync::nvGetVideoEDIDAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getVideoSourceManualFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetVideoSourceManualFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getVideoSourcePolicyFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetVideoSourcePolicyFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setVideoSourceManualFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvSetVideoSourceManualFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setVideoSourcePolicyFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvSetVideoSourcePolicyFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getUSBAuthentic()" == APIname)
    {
        //todo
    }

    else if ("setUSBAuthentic()" == APIname)
    {
        //todo
    }
    if ("getVolumeFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetVolumeFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setVolumeFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvSetVolumeFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    else if ("setTimingVolumeFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvSetTimingVolumeFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getTimingVolumeFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvGetTimingVolumeFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }



    if ("setAudioPlayRealTime()" == APIname)
    {
        //TODO

    }
    else if ("setAudioPlayPolicy()" == APIname)
    {
        //TODO
    }
    else if ("getAudioPlayPolicy()" == APIname)
    {
        //TODO

    }

    if ("setSupportSensorInfo()" == APIname)
    {
        ViplexCoreAsync::nvSetSupportSensorInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getSupportSensorInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetSupportSensorInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getInfraRedConfig()" == APIname)
    {
        //TODO

    }
    else if ("setInfraRedConfig()" == APIname)
    {
        //TODO
    }
    else if ("setManualSolidPower()" == APIname)
    {
        //TODO
    }
    else if ("getSolidPowerStatus()" == APIname)
    {
        //TODO
    }


    if ("setPowerInfoManual()" == APIname)
    {
        ViplexCoreAsync::nvSetPowerInfoManualAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setPowerInfoPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetPowerInfoPolicyAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getPowerInfoPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetPowerInfoPolicyAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getPowerInfoStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetPowerInfoStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setPowerMode()" == APIname)
    {
        ViplexCoreAsync::nvSetPowerModeAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getPowerMode()" == APIname)
    {
        ViplexCoreAsync::nvGetPowerModeAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setTimingSolidPower()" == APIname)
    {
        //TODO
    }
    else if ("getTimingSolidPower()" == APIname)
    {
        //TODO
    }
    else if ("setSolidPowerStatus()" == APIname)
    {
        //TODO
    }
    else if ("isExistSolidPower()" == APIname)
    {
        //TODO
    }
    if ("setManualBrightnessFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvsetManualBrightnessFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getManualBrightnessFor0x99()" == APIname)
    {
        //TODO
        ViplexCoreAsync::nvgetManualBrightnessFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setPolicyBrightnessFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvsetPolicyBrightnessFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getPolicyBrightnessFor0x99()" == APIname)
    {
        ViplexCoreAsync::nvgetPolicyBrightnessFor0x99Async(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setImmediatelyReboot()" == APIname)
    {
        //todo
    }
    else if ("setTimingReboot()" == APIname)
    {
        //todo
    }
    else if ("getTimingReboot()" == APIname)
    {
        //todo
    }

    else if ("clearAllMediasFor0x99()" == APIname)
    {
        //todo
    }
    else if ("setSyncPlayFor0x99()" == APIname)
    {
        //todo
    }
    else if ("getPolicySourceOutMode()" == APIname)
    {
        //todo
    }
    else if ("setPolicySourceOutMode()" == APIname)
    {
        //todo
    }

    else if ("getNetworkCheck()" == APIname)
    {
        //todo
    }
    else if ("batchSetScreenAttribute()" == APIname)
    {
        //todo
    }
    else if ("batchLogin()" == APIname)
    {
        //todo
    }
    else if ("batchSetRecvCardFile()" == APIname)
    {
        //todo
    }
    else if ("setScreenAttributeSDK()" == APIname)
    {
        //todo
    }
    else if ("setRelayPowerManual()" == APIname)
    {
        ViplexCoreAsync::nvSetRelayPowerManualAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setRelayPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvSetRelayPowerPolicyAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getRelayPowerPolicy()" == APIname)
    {
        ViplexCoreAsync::nvGetRelayPowerPolicyAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getRelayPowerStatus()" == APIname)
    {
        ViplexCoreAsync::nvGetRelayPowerStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setRelayPowerStatus()" == APIname)
    {
        ViplexCoreAsync::nvSetRelayPowerStatusAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("setNetworkCheck()" == APIname)
    {
        //TODO
    }

    if ("downloadTerminalLog()" == APIname)
    {
        ViplexCoreAsync::nvDownloadTerminalLogAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("uploadTerminalLog()" == APIname)
    {
        ViplexCoreAsync::nvUploadTerminalLogAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("cancelFunction()" == APIname)
    {
        ViplexCoreAsync::nvCancelFunctionAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("checkNetwork()" == APIname)
    {
        ViplexCoreAsync::nvCheckNetworkAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("downloadTerminalAllLog()" == APIname)
    {
        ViplexCoreAsync::nvDownloadTerminalAllLogAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("downloadTerminalLogNet()" == APIname)
    {
        ViplexCoreAsync::nvDownloadTerminalLogNetAsync(data, [=](const int errorcode, const std::string& result)
            {
                emit signalsendResponseData(errorcode, QString::fromStdString(result));
            });
    }
    if ("downloadTerminalPlayLog()" == APIname)
    {
        ViplexCoreAsync::nvDownloadTerminalPlayLogAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("downloadTerminalPlayLogNet()" == APIname)
    {
        ViplexCoreAsync::nvDownloadTerminalPlayLogNetAsync(data, [=](const int errorcode, const std::string& result)
            {
                emit signalsendResponseData(errorcode, QString::fromStdString(result));
            });
    }
    if ("getSendCardMonitorInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetSendCardMonitorInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("getSendCardMonitorInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetReceiverCountAndInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    if ("getScreenDeviceInfo()" == APIname)
    {
        ViplexCoreAsync::nvGetScreenDeviceInfoAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    if ("loginVnnox()" == APIname)
    {
        ViplexCoreAsync::nvLoginVnnox(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("getVerifyCode()" == APIname)
    {
        ViplexCoreAsync::nvGetVerifyCode(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("registerVnnox()" == APIname)
    {
        ViplexCoreAsync::nvRegisterVnnox(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    if ("ping()" == APIname)
    {
        ViplexCoreAsync::nvPingAsync([=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("rsaEncode()" == APIname)
    {
        ViplexCoreAsync::nvRsaEncodeAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("rsaDecode()" == APIname)
    {
        ViplexCoreAsync::nvRsaDecodeAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    if ("StartUploadApk()" == APIname)
    {
        ViplexCoreAsync::nvStartUploadApkCoreAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }

    if ("setPublicNetConfigParam()" == APIname)
    {
        ViplexCoreAsync::nvSetPublicNetConfigParamAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("initPublicNet()" == APIname)
    {
        ViplexCoreAsync::nvInitPublicNetAsync(data, [=](const int errorcode, const std::string& result)
            {
                emit signalsendResponseData(errorcode, QString::fromStdString(result));
            }, [=](const int errorcode, const std::string& result)
            {
                emit signalsendResponseData(errorcode, QString::fromStdString(result));
            });
    }
    if ("stopPublicNet()" == APIname)
    {
        ViplexCoreAsync::nvStopPublicNetAsync([=](const int errorcode, const std::string& result)
            {
                emit signalsendResponseData(errorcode, QString::fromStdString(result));
            });
    }
    else  if ("getPublicNetParam()" == APIname)
    {
        ViplexCoreAsync::nvGetPublicNetParamAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else  if ("disconnectPublicNet()" == APIname)
    {
        ViplexCoreAsync::nvDisconnectPublicNetAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    else if ("getOnlineDevicesAsync()" == APIname)
    {
        ViplexCoreAsync::nvGetOnlineDevicesAsync([=](const int errorcode, const std::string& result)
            {
                emit signalsendResponseData(errorcode, QString::fromStdString(result));
            });
    }
    if ("getEnvironmentBrightnessParameter()" == APIname)
    {
        ViplexCoreAsync::nvGetEnvironmentBrightnessParameterAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    if ("setEnvironmentBrightnessParameter()" == APIname)
    {
        ViplexCoreAsync::nvSetEnvironmentBrightnessParameterAsync(data, [=](const int errorcode, const std::string &result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }


    if ("transferProgram()" == APIname)
    {
        ViplexCoreAsync::nvTransferProgramAsync(data, [=](const int errorcode, const std::string& result)
        {
            emit signalsendResponseData(errorcode, QString::fromStdString(result));
        });
    }
    





    //支持的模块测试
    //std::string sn = vectorSearchData.at(row - 2).sn;
    //std::string param;
    //ns::to_string(sn, param);
    //ViplexCoreAsync::nvGetconfiguration(param, [=](const int errorCode, const std::string &result) {
    //    emit signalsendResponseData(QString::fromStdString(result));
    //qDebug() << "********************" << errorCode << QString::fromStdString(result);
    //});
    //});

    ////已安装的软件版本信息测试
    //ns::PackageInfoWithSN piws;
    //piws.sn = sn;
    //piws.packageInfo.packageName.push_back("nova.priv.terminal.syssetting");
    //piws.packageInfo.packageName.push_back("nova.priv.terminal.easypluto");
    //std::string packageinfo;
    //ns::to_string(piws, packageinfo);
    //login->getInstalledPackageVersions(packageinfo, [=](const int errorCode, const std::string &result) {

    //qDebug() << "********************" << errorCode << QString::fromStdString(result);
    //});

    ////获取固件版本信息测试
    //ns::PackageInfoWithSN piws;
    //std::string param;
    //ns::to_string(sn, param);
    //login->getFirmwareInfos(param, [=](const int errorCode, const std::string &result) {

    //qDebug() << "********************" << errorCode << QString::fromStdString(result);
    //});

    ////获取设备信息测试
    //std::string param;
    //ns::to_string(sn, param);
    //ViplexCoreAsync::nvGetProductInfo(param, [=](const int errorCode, const std::string &result) {

    //qDebug() << "********************" << errorCode << QString::fromStdString(result);
    //});

}

void DemoGUI::slotsConnect()
{
    LoginDialog *pLogin = new LoginDialog();
    connect(pLogin, &LoginDialog::signalsUserInfo, this, [=](QString strUsername, QString strPassword) {
        ns::LoginData lo;
        lo.sn = vectorSearchData.at(row - 2).sn;
        lo.loginType = 0;
        lo.rememberPwd = 0;
        lo.username = strUsername.toStdString();
        lo.password = strPassword.toStdString();
        std::string loginstr;
        ns::to_string(lo, loginstr);

        ViplexCoreAsync::nvLoginAsync(loginstr.c_str(), [=](const int errorCode, const char *result)
        {
            emit signalLogin(errorCode, QString::fromStdString(result));
        });

    }, Qt::QueuedConnection);
    pLogin->exec();
}

void DemoGUI::slotsConnectSys()
{
    LoginDialog *pLoginsys = new LoginDialog();
    connect(pLoginsys, &LoginDialog::signalsUserInfo, this, [=](QString strUsername, QString strPassword) {
        ns::LoginData lo;
        lo.sn = vectorSearchData.at(row - 2).sn;
        lo.loginType = 1;
        lo.rememberPwd = 0;
        lo.username = strUsername.toStdString();
        lo.password = strPassword.toStdString();
        std::string loginstr;
        ns::to_string(lo, loginstr);

        ViplexCoreAsync::nvLoginAsync(loginstr.c_str(), [=](const int errorCode, const char *result)
        {
            emit signalLogin(errorCode, QString::fromStdString(result));
        });

    }, Qt::QueuedConnection);
    pLoginsys->exec();
}

void DemoGUI::slotsConnectPublicnet()
{
    LoginDialog *pLoginsys = new LoginDialog();
    connect(pLoginsys, &LoginDialog::signalsUserInfo, this, [=](QString strUsername, QString strPassword) {
        ns::LoginData lo;
        lo.sn = vectorSearchData.at(row - 2).sn;
        lo.loginType = 5;
        lo.rememberPwd = 0;
        lo.username = strUsername.toStdString();
        lo.password = strPassword.toStdString();
        std::string loginstr;
        ns::to_string(lo, loginstr);

        ViplexCoreAsync::nvLoginAsync(loginstr.c_str(), [=](const int errorCode, const char *result)
        {
            emit signalLogin(errorCode, QString::fromStdString(result));
        });

    }, Qt::QueuedConnection);
    pLoginsys->exec();
}

void DemoGUI::slotsQuit()
{
    std::string strSn = vectorSearchData.at(row - 2).sn;
    ns::DissConnectData data;
    data.loginType = 1;
    data.sn = strSn;
    std::string param;
    ns::to_string(data, param);
    ViplexCoreAsync::nvLogoutAsync(param.c_str(), [this](const int errorCode, const char *result)
    {
        emit signalDissconnect(errorCode, QString::fromStdString(result));
    });
}

void DemoGUI::slotsRename()
{

}

void DemoGUI::slotsRepassword()
{
    changepassword.show();
    changepassword.setCallback([=](const std::string oldpassword, const std::string newpassword)
    {
        ns::ChangePasswordWithSN sncp;
        sncp.sn = vectorSearchData.at(row - 2).sn;
        sncp.cp.password = oldpassword;
        sncp.cp.newPassword = newpassword;
        sncp.cp.username = "admin";
        std::string password;
        ns::to_string(sncp, password);
        ViplexCoreAsync::nvChangePassWordAsync(password.c_str(), [=](const int errorCode, const char *result) {

            //qDebug() << "********************" << errorCode << QString::fromStdString(result);
        });
    }
    );
}

void DemoGUI::slotsForgetPassword()
{

}

void DemoGUI::slotsDownload()
{

}

void DemoGUI::slotClickedSearch()
{
    i = 0;
    vectorSearchData.clear();


    ViplexCoreAsync::nvSearchTerminalAsync([=](const uint16_t code, const char *data) {;
    emit signalSerch((uint16_t)code, QString::fromStdString(data));
    });
}

void DemoGUI::slotDissconnect(int errorcode, QString result)
{
    if (errorcode == 0)
    {
        QMessageBox::about(NULL, "提示", QString("%1已退出").arg(result));
    }
    else
    {
        QMessageBox::about(NULL, "提示", result);
    }
}

void DemoGUI::slotSerch(int code, QString data)
{
    //qDebug() << "---------------" << data;
    if (ViplexError::OK == code)
    {
        setTableContent(data.toStdString());
    }
    else
    {
        QMessageBox::about(NULL, "警告", data);
    }
}

void DemoGUI::slotLogin(int code, QString data)
{
    if (0 == code)
    {
        ns::LoginReplyData loginReplyData;
        from_string(data.toStdString(), loginReplyData);

        if (loginReplyData.logined)
        {
            ui.tableWidget->setItem(row - 2, 1, new QTableWidgetItem("登录成功!!!"));
            return;
        }
        else
        {
            QMessageBox::about(NULL, "提示", QString("请求成功，但登录失败"));
            return;
        }
    }
    else
    {
        QMessageBox::about(NULL, "提示", QString("登录失败 %1 %1").arg(code).append(data));
    }
}

void DemoGUI::on_pushButton_2_clicked()
{
    dialog->show();//显示指定ip按钮界面
}
void DemoGUI::on_slotsIp_button_start_clicked()
{
    i = 0;//初始化行数，让其重新在第一行打印
    ui.tableWidget->clearContents();//清除表格上的内容
    dialog->close();//关闭指定ip按钮及指定范围ip按钮打开的界面
    QString AppointIP = ip_lineedit->text();//获取指定ip文本框内容ViplexCoreAsync::nvG
    if (AppointIP.isEmpty())
    {
        QMessageBox::information(NULL, "提示", "没有输入ip,请输入ip:");
        return;
    }
    ViplexCoreAsync::nvSearchAppointIpAsync(AppointIP.toStdString().data(), [=](const uint16_t code, const std::string &result) {
        ns::SearchResponseData SearchResponseData;
        ns::from_string(result, SearchResponseData);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        emit signalSerch((uint16_t)code, QString::fromStdString(result));
    });
}
void DemoGUI::AppointIpInit()
{
    dialog = new QDialog();//创建一个界面
    dialog->resize(250, 70);//设置界面大小
    dialog->setModal(false);//设置界面模式
    ip_button_start = new QPushButton(dialog);//在界面中添加一个确定按钮
    ip_button_quit = new QPushButton(dialog);//在界面中添加一个取消按钮
    ip_Label = new QLabel(dialog);//在界面中创建一个标签用于显示指定IP这几个字
    ip_lineedit = new QLineEdit(dialog);//创建一个文本框
    ip_lineedit->resize(130, 20);//设置文本框大小
    ip_lineedit->move(90, 8);//设置文本框位置
    ip_Label->resize(150, 30);//设置标签大小
    ip_Label->setText(tr("请输入指定IP:"));//设置标签内容
    ip_Label->move(10, 3);//设置标签位置
    ip_button_start->setText(tr("确定"));//添加按钮中的文字
    ip_button_quit->setText(tr("取消"));//添加另一个按钮中的文字
    ip_button_start->move(35, 35);//设置确认按钮的位置
    ip_button_quit->move(140, 35);//设置取消按钮的位置
}

void DemoGUI::on_specifyRangeIpButton_clicked()
{
    rangeDialog->show();//显示指定范围ip界面
}
void DemoGUI::SpecifyRangeIpInit()
{
    rangeDialog = new QDialog();//创建指定范围ip界面
    rangeDialog->resize(250, 100);//设置指定范围ip界面大小
    rangeDialog->setModal(false);//设置指定范围ip界面为非模态界面
    ip_range_button_start = new QPushButton(rangeDialog);//创建按钮
    ip_range_button_quit = new QPushButton(rangeDialog);//创建另一个按钮
    ip_Label_Begin = new QLabel(rangeDialog);//创建起始ip标签
    ip_Label_Last = new QLabel(rangeDialog);//创建终止ip标签
    ip_lineedit_Begin = new QLineEdit(rangeDialog);//创建起始ip文本框
    ip_lineedit_Last = new QLineEdit(rangeDialog);//创建终止ip文本框
    ip_lineedit_Begin->resize(130, 20);//设置起始ip文本框大小
    ip_lineedit_Begin->move(90, 8);//设置起始ip文本框位置
    ip_lineedit_Last->resize(130, 20);//设置终止ip文本框大小
    ip_lineedit_Last->move(90, 38);//设置终止ip文本框位置
    ip_Label_Begin->resize(150, 30);//设置起始ip标签大小
    ip_Label_Begin->setText(tr("请输入起始IP:"));//设置起始ip标签内容
    ip_Label_Begin->move(10, 3);//设置起始ip标签位置
    ip_Label_Last->resize(150, 30);//设置终止ip标签大小
    ip_Label_Last->setText(tr("请输入终止IP:"));//设置终止ip标签内容
    ip_Label_Last->move(10, 33);//设置终止ip标签位置
    ip_range_button_start->setText(tr("确定"));//设置确定按钮的内容
    ip_range_button_quit->setText(tr("取消"));//设置取消按钮的内容
    ip_range_button_start->move(35, 65);//设置确定按钮的位置
    ip_range_button_quit->move(140, 65);//设置取消按钮的位置
}
void DemoGUI::on_slotsRange_Ip_button_start_clicked()
{
    i = 0;//打印的行数初始化为0
    ui.tableWidget->clearContents();//清屏
    rangeDialog->close();//关闭指定范围ip界面
    ip_lineedit_Begin->text();//读取起始ip文本框中的内容
    ip_lineedit_Last->text();//读取终止ip文本框中的内容
    if (ip_lineedit_Begin->text().isEmpty())
    {
        QMessageBox::information(NULL, "提示", "没有输入起始ip,请输入起始ip:");
        return;
    }
    if (ip_lineedit_Last->text().isEmpty())
    {
        QMessageBox::information(NULL, "提示", "没有输入终止ip,请输入终止ip:");
        return;
    }
    ns::SerchAppointIpRequest serchAppointIpBeginRequest;
    ns::SerchAppointIpRequest serchAppointIpLastRequest;
    ns::from_string(ip_lineedit_Begin->text().toStdString(), serchAppointIpBeginRequest);
    ns::from_string(ip_lineedit_Last->text().toStdString(), serchAppointIpLastRequest);
    ns::SerchRangeIpRequest serchRangeIpRequest;//{"ipStart":"172.18.175.1"}
    serchRangeIpRequest.ipStart = serchAppointIpBeginRequest.ip;
    serchRangeIpRequest.ipEnd = serchAppointIpLastRequest.ip;

    ip_begin_position = serchRangeIpRequest.ipStart.find_last_of('.');//找到字符串中最后一个.的位置，并返回对应位置
    ip_begin_str_dot_back = serchRangeIpRequest.ipStart.substr(ip_begin_position + 1);//截取.后面的字符
    ip_begin_str_dot_front = serchRangeIpRequest.ipStart.substr(0, ip_begin_position);//截取.前面的字符

    ip_last_position = serchRangeIpRequest.ipEnd.find_last_of('.');
    ip_last_str_dot_back = serchRangeIpRequest.ipEnd.substr(ip_last_position + 1);
    ip_last_str_dot_front = serchRangeIpRequest.ipEnd.substr(0, ip_last_position);
    if (ip_begin_str_dot_front != ip_last_str_dot_front)//判断两次输入的ip是否在同一网段
    {
        QMessageBox::information(NULL, "提示", "两次输入的IP不在同一网段，请重新输入:");
        return;
    }
    ip_stoi_begin = atoi(ip_begin_str_dot_back.c_str());//字符串转为int型的数字
    ip_stoi_last = atoi(ip_last_str_dot_back.c_str());
    if (ip_stoi_begin > ip_stoi_last)//判断起始ip是否小于终止ip
    {
        QMessageBox::information(NULL, "提示", "起始IP大于终止IP,请重新输入:");
        return;
    }

    if (serchRangeIpRequest.ipStart == serchRangeIpRequest.ipEnd)//判断起始ip与终止ip是否相等，相等做单独处理操作
    {
        ViplexCoreAsync::nvSearchAppointIpAsync(ip_lineedit_Last->text().toStdString().data(), [=](const uint16_t code, const char *result) {
            ns::SearchResponseData SearchResponseData;
            ns::from_string(result, SearchResponseData);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            emit signalSerch((uint16_t)code, QString::fromStdString(result));
        });
        return;
    }
    std::string ipdata;
    ns::to_string(serchRangeIpRequest, ipdata);//(const uint16_t, const char *)
    /*ExportViplexCallback resultCallBack;
    using ViplexCallback = std::function<void(const uint16_t, const char *)>;
    VIPLEX_EXPORT typedef void(__stdcall *ExportViplexCallback)(const uint16_t, const char *);
    typedef int(*A) (char, char);*/
    //nvSearchRangeIpAsync(ipdata.data(),[=](const uint16_t code, const std::string &result) {
    //	ns::SearchResponseData SearchResponseData;
    //	ns::from_string(result, SearchResponseData);
    //	std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //	emit signalSerch((uint16_t)0, QString::fromStdString(result));
    //});

    ViplexCoreAsync::nvSearchRangeIpAsync(ipdata.data(), [=](const uint16_t code, const std::string &result) {
        ns::SearchResponseData SearchResponseData;
        ns::from_string(result, SearchResponseData);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        emit signalSerch((uint16_t)code, QString::fromStdString(result));
    });
}

#pragma once

#include <QtWidgets/QWidget>
#include "ui_demoChildGUI.h"

class DemoChildGUI : public QWidget
{
    Q_OBJECT

public:
    DemoChildGUI(QWidget *parent = Q_NULLPTR);


    void setCallback(std::function<void(const std::string &APIname, const std::string &requestData) > );
private:
    Ui::DemoChildGUIClass ui;

    std::function<void(const std::string &APIname,const std::string &requestData)> m_callback;

    void initAPIModule();
    void initAPI();
    void initTestCase();
    //void initRemotemanagerAPI();
    //void initQuicksettingAPI();
    //void initVerifytimeAPI();
    //void initAdvancedfeaturesAPI();
    //   void initScreenBrightnessAPI();
    //   void initScreenPowerAPI();
    //void initHardwareInfoAPI();
    //void intiLoginAPI();
    //   void initUpdateHelperAPI();
    //void initScreenSetting();
    //void initAdvancedFeatures();
    //void initVideoSourceController();
    //void initScreenShot();
    //void initStatusCollector();
    //   void initNetworksettingAPI();
    //void initAppManage();
    //void initPlayManager();
    //void initEditProgram();
    //   void initUserInfo();
    //void initDBMigration();
    //   void initFeedBack();


    void initDiagnosisAPI();
    void initPowerManagerAPI();
    void initVolumeControllerAPI();
    void initVPNConnectionAPI();
    void initAppManagerAPI();
    void initPlayLoggerAPI();
    void initPlayFontAPI();
    void initCreatFunctionTestAPI();
    void initLEDSplicerAPI();
    void initRunningLoggerAPI();
    void initSelfInspectionAPI();
    void initIPAudioAPI();
    void initFixedPointDeliveryAPI();
    void initEmergencyIntercutAPI();
    void initSensorAPI();
    void initExternalDeliveryAPI();
    void initRadioFrequencyAPI();
    void initPowerControllerAPI();
    void initVideoSourceControllerAPI();
    void initUserManagerAPI();
    void initLoginAPI();
    void initLightControllerAPI();
    void initTemperatureControllerAPI();
    void initSwitchControllerAPI();
    void initFileManagerAPI();
    void initListManagerAPI();
    void initAdvancedFeaturesAPI();
    void initAcquisitionReceiverAPI();
    void initUSBVPlayAPI();
    void initUpgradeManagerAPI();
    void initNetworkConfiguratorAPI();
    void initScreenConfigurationAPI();
    void initICareConfiguratorAPI();
    void initCloudConfiguratorAPI();
    void initMonitorConfiguratorAPI();
    void initScreenManagerAPI();
    void initProgramEditorAPI();
    void initVerfityTimeAPI();
    void initNodeServerListAPI();
    void initFeedbackAPI();
    void initDatabaseMigrationAPI();
    void initViplexCoreAssistAPI();
    void initBindingManagerAPI();
    void initTimeZoneListAPI();
    void initBatchSetAPI();
    void initLogUpload();
    void initPublibNetConfigAPI();
    void initGetOnlineDevicesAPI();

private slots:
    /**
    * @brief 获取接口返回信息
    * @return void
    */
    void soltsGetInfo();

    void soltsGetSN(QString);
    void soltGetResponseData(int,QString);

    void slotsChangeAPI(int);

    void slotsSetRequestData(QString);
};

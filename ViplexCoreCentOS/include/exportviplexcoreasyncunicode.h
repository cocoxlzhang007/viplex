#pragma once
#include "exportdefine.h"
extern "C"
{
    VIPLEX_EXPORT void nvSetPlatformW(const char *platform);

    VIPLEX_EXPORT int nvInitW(const char *sdkRootDir, const char *credentials);

#pragma region Diagnosis 诊断模块 
#pragma endregion 诊断模块 待开发

#pragma region publicnet 公网模块 

    VIPLEX_EXPORT void nvInitPublicNetAsyncW(const char* data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvStopPublicNetAsyncW(ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetPublicNetConfigParamAsyncW(const char* data, ExportViplexCallbackUnicode callback);

	VIPLEX_EXPORT void nvDisconnectPublicNetAsyncW(const char* data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetPublicNetParamAsyncW(const char* data, ExportViplexCallbackUnicode callback);
#pragma endregion 公网模块

#pragma region PowerManager 多功能卡电源管理 

    VIPLEX_EXPORT void nvSetTimingPowerSwitchStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetTimingPowerSwitchStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetRealtimePowerSwitchStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetManualPowerSwitchStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetManualPowerSwitchStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion 多功能卡电源管理

#pragma region VolumeController 音量调节
    
    VIPLEX_EXPORT void nvGetVolumeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetVolumeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetTimingVolumeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetTimingVolumeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetVolumeFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetVolumeFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetTimingVolumeFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetTimingVolumeFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion VolumeController 音量调节

#pragma region VPNConnection VPN连接管理
    
    VIPLEX_EXPORT void nvGetVPNConnectInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetVPNConnectInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion VPN连接管理 待开发

#pragma region AppManager
   
    VIPLEX_EXPORT void nvGetInstalledPackageInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvGetRunningPackageInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvForceStopAppAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvUninstallPackageAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvStartUploadApkCoreAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion AppManager APP管理

#pragma region PlayLogger 播放日志
   
    VIPLEX_EXPORT void nvGetPlaylogPathAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion 播放日志 待开发

#pragma region PlayFont 字体
   
    VIPLEX_EXPORT void nvGetTerminalFontAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvDeleteFontAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvUpdateFontAsyncW(const char *data, ExportViplexCallbackUnicode callback);
#pragma endregion 字体 待开发

#pragma region 生产功能测试
#pragma endregion 生产功能测试 待开发

#pragma region LEDSplicer 多屏拼接
    
    VIPLEX_EXPORT void nvGetSpliceInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvSetSpliceInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion 多屏拼接 

#pragma region RunningLogger
#pragma endregion RunningLogger 日志管理 待开发

#pragma region SelfInspection
#pragma endregion SelfInspection 一键自检 待开发

#pragma region IPAudio
#pragma endregion IPAudio IP音频 待开发

#pragma region FixedPointDelivery
#pragma endregion FixedPointDelivery 定点投放 待开发

#pragma region EmergencyIntercut
#pragma endregion EmergencyIntercut 紧急插播 待开发

#pragma region Sensor
    
    VIPLEX_EXPORT void nvGetSupportSensorInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvSetSupportSensorInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion Sensor 传感器子板 待开发

#pragma region ExternalDelivery
#pragma endregion ExternalDelivery 外投调节 待开发

#pragma region RadioFrequency
    
    VIPLEX_EXPORT void nvGetLoraInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion RadioFrequency 射频管理  待补充

#pragma region PowerController
    
    VIPLEX_EXPORT void nvSetPowerInfoManualAsyncW(const char *data, ExportViplexCallbackUnicode callback);
  
    VIPLEX_EXPORT void nvSetPowerInfoPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvGetPowerInfoPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvGetPowerInfoStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvSetPowerModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetPowerModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
  
    VIPLEX_EXPORT void nvSetRelayPowerManualAsyncW(const char *data, ExportViplexCallbackUnicode callback);
  
    VIPLEX_EXPORT void nvSetRelayPowerPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvGetRelayPowerPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvGetRelayPowerStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetRelayPowerStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion PowerController 终端电源控制 待开发

#pragma region VideoSourceController
   
    VIPLEX_EXPORT void nvGetVideoControlInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvSetVideoControlInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetVideoEDIDAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetVideoEDIDAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetVideoSourceManualFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetVideoSourceManualFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetVideoSourcePolicyFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetVideoSourcePolicyFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);


#pragma endregion VideoSourceController 视频源控制

#pragma region userInfo

    
    VIPLEX_EXPORT void nvSetUserInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetUserInfoAsyncW(const char *data, ExportViplexCallbackUnicode callBack);

#pragma endregion userInfo 显示屏用户信息

#pragma region Login
    
    VIPLEX_EXPORT void nvSearchTerminalAsyncW(ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSearchAppointIpAsyncW(const char * appointIp, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSearchRangeIpAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvFindAllTerminalsAsyncW(ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvLoginAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvChangePassWordAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvDelTerminalInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetScreenInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    
    VIPLEX_EXPORT void nvGetTerminalInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetTerminalInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetSystemInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvLogoutAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetFirmwareInfosAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetInstalledPackageVersionsAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetProductInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetconfigurationAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion Login 搜索连接登录

#pragma region ScreenBrightness
    
    VIPLEX_EXPORT void nvSetBrightnessAdjustModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetBrightnessAdjustModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetScreenBrightnessAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetScreenBrightnessAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetBrightnessPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetBrightnessPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetEnvironmentBrightnessAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvsetManualBrightnessFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvsetPolicyBrightnessFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvgetPolicyBrightnessFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion LightController 显示屏亮度和环境亮度

#pragma region TemperatureController
    
    VIPLEX_EXPORT void nvGetColorTemperatureAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetColorTemperatureAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma region SwitchController
    
    VIPLEX_EXPORT void nvSetScreenPowerModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetScreenPowerModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetScreenPowerStateAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetScreenPowerStateAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetScreenPowerPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetScreenPowerPolicyAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvsetScreenPowerManual0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvsetScreenPowerPolicy0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetScreenPowerManual0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetScreenPowerPolicyFor0x99AsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion SwitchController 开关屏管理


#pragma region FileManager
#pragma endregion FileManager 系统文件管理 待开发

#pragma region ListManager
    
    VIPLEX_EXPORT void nvGetProgramInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvDeletePlayListAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvStartPlayAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvPausePlayAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvResumePlayAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvStopPlayAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion ListManager 清单管理 

#pragma region AdvancedFeatures
    
    VIPLEX_EXPORT void nvSetSyncPlayAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetSyncPlayAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetReBootWipeUserDataAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvClearAllMediasAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetOTGUSBModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetOTGUSBModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetCurrentResolutioAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetCurrentResolutionAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetSupportedResolutionAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetReBootTaskAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetReBootTaskAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetHdmiOutputStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetHdmiOutputStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetCustomResolutionAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion AdvancedFeatures 高级特性 

#pragma region AcquisitionReceiver
    
    VIPLEX_EXPORT void nvGetPickerReceiverAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvAddCollectorAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvDeleteCollectorAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion AcquisitionReceiver 采集器接收器

#pragma region USBVPlay
#pragma endregion USBVPlay U盘相关协议 待开发

#pragma region UpgradeManager
    
    void nvQueryUpdateFileByTypeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    void nvGetOnlineUpgradeFileAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    void nvDownloadUpgradeFileAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    void nvStopDownloadUpgradeFileAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    void nvReadFileContentFromZipFileAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    void nvUpdateAppAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    void nvUpdateOSAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    void nvStopCurrentUpdateTaskAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvUpdateVerifyAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion UpgradeManager 升级 待修改类名（张鹏程）

#pragma region 网络配置
    
    VIPLEX_EXPORT void nvGetWifiListAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvConnectWifiNetworkAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetWifiCurrentStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvDisconnectWifiNetworkAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetWifiEnabledAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetWifiEnabledAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSendForgetWifiCommandAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetMobileNetworkAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetMobileNetworkAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvIsMobileModuleExistedAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetEthernetInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetEthernetInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetAPNetworkAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetAPNetworkAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetAPNInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetAPNInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetFlightModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetFlightModeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGet4GNetworkStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetAPNetworkOpenStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetAPNetworkOpenStatusAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetWifiApStationSwitchAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetModuleInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion 网络配置 NetworkConfigurator

#pragma region ScreenConfiguration

    VIPLEX_EXPORT void nvGetScreenAttributeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetScreenAttributeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetRecvCardFileAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion ScreenConfiguration 配屏 

#pragma region ICareConfigurator
    
    VIPLEX_EXPORT void nvGetIcareConfigInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetIcareConfigInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion ICareConfigurator icare配置

#pragma region CloudConfigurator

    VIPLEX_EXPORT void nvSetBindPlayerAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetCloudPlayerListAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetBindPlayerAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion CloudConfigurator 终端cloud配置

#pragma region MonitorConfigurator
    
    VIPLEX_EXPORT void nvGetAvailableStorageDataAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetCPUUsageAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetCPUTempAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetAvailableMemoryAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetSendCardMonitorInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetReceiverCountAndInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetMonitorInfoByReceiverIndexAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion MonitorConfigurator 监控 

#pragma region ScreenManager
    
    VIPLEX_EXPORT void nvGetCurrentTimeAndZoneAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvCalibrateTimeAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetNetTimingInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetNetTimingInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetNetTimingListInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvAddNetTimingInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvDeleteNetTimingInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvUpdateNetTimingInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvAddNetTimingInfoListAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvGetIsUseDayLightTimeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma region ScreenShot 
   
    VIPLEX_EXPORT void nvDownLoadScreenshotAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion ScreenShot 截屏

#pragma endregion ScreenManager 屏体其他项
    
    VIPLEX_EXPORT void nvSetRotationAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvGetRotationAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvGetDisplayInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetTimeAndZoneAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    
    VIPLEX_EXPORT void nvSetScreenShotAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma region 其他
    
    VIPLEX_EXPORT void nvGetScreenUnitTempAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvDataBaseMigrationAsyncW(const char *data, ExportViplexCallbackUnicode callback);
   
    VIPLEX_EXPORT void nvDownLoadFilesAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvQueryFileByTypeAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma region EditProgram

    VIPLEX_EXPORT void nvCreateProgramAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetPageProgramAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetPageProgramsAsyncW(const char *data, ExportViplexCallbackUnicode callback);
    

    VIPLEX_EXPORT void nvMakeProgramAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetSystemTplInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvAddTplAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvEditTplAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvDeleteTplAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetProgramAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvDeleteProgramAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvStartTransferProgramAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvStopProgramTransferAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetCustomerTplAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetFileMD5AsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvSetAudioMedioProgramAsyncW(const char *data, ExportViplexCallback  callback);

#pragma endregion EditProgram 节目

#pragma region NodeServerList 节点服务器列表

    VIPLEX_EXPORT void nvGetNodeServerListAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvAddNodeServerListAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvDeleteNodeServerListAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvChangeNodeServerListAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvAddNodeServerInfoListAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion NodeServerList 


#pragma region feedback

    VIPLEX_EXPORT void nvUploadFeedbackInfoAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvUploadFeedBackFileStateAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion feedback 用户反馈

#pragma region StatusCollector

    VIPLEX_EXPORT void nvStartGetAvailableMemoryDataAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvFinishDataAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion StatusCollector

#pragma region BindingManager

    VIPLEX_EXPORT void nvIsCommonCloudAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetPlayerIdentiferAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvIsExistPlayerNameAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetTokenAsyncW(const char *data, ExportViplexCallbackUnicode callback);
#pragma endregion 
    VIPLEX_EXPORT void nvGetTimeZoneAsyncW(const char *data, ExportViplexCallbackUnicode callback);

#pragma endregion 其他  待补充

    VIPLEX_EXPORT void nvDownloadTerminalLogAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvUploadTerminalLogAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvCheckNetworkAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvCancelFunctionAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvDownloadTerminalAllLogAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvDownloadTerminalPlayLogAsyncW(const char *data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvRebootAsyncW(const char* data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvStartUploadApkAsyncW(const char* data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvGetWifiCurrentStatusAsyncW(const char* data, ExportViplexCallbackUnicode callback);
    VIPLEX_EXPORT void nvNewSetBindPlayerAsyncW(const char* data, ExportViplexCallbackUnicode callback);

    VIPLEX_EXPORT void nvRsaEncodeAsyncW(const char* data, ExportViplexCallbackUnicode callback);
    VIPLEX_EXPORT void nvRsaDecodeAsyncW(const char* data, ExportViplexCallbackUnicode callback);
}




#pragma once
#include "exportdefine.h"
#include "viplexcommon/jsonserializer/jsonserializer.h"
#include "viplexcommon/interface/iviplexrequester.h"


class VIPLEX_EXPORT ViplexCoreAsync
{
public:
    static void nvSetDevLang(const char *devLang);
    static void exportFuncAPIAsync(std::function<void(const char *, ViplexCallback)>, const char *data, ViplexCallback callback, const char *funcName);
    static int initInternal(const char *sdkRootDir, const char *credentials, const EnumType type);
    static void nvSetPlatform(const char *platform);
    static int nvInit(const char *sdkRootDir, const char *credentials);
	static void nvPingAsync(ViplexCallback callback);

    //public net config
    static void nvInitPublicNetAsync(const char* data, ViplexCallback connectCallback, ViplexCallback disconnectCallback);
    static void nvStopPublicNetAsync(ViplexCallback callback);
    static void nvSetPublicNetConfigParamAsync(const char *data, ViplexCallback callback);
    static void nvDisconnectPublicNetAsync(const char *data, ViplexCallback callback);
    static void nvGetPublicNetParamAsync(const char *data, ViplexCallback callback);
    static void nvGetOnlineDevicesAsync(ViplexCallback callback);



    //PowerManager 多功能卡电源管理 
    static void nvSetTimingPowerSwitchStatusAsync(const char *data, ViplexCallback callback);
    static void nvGetTimingPowerSwitchStatusAsync(const char *data, ViplexCallback callback);
	static void nvGetRealtimePowerSwitchStatusAsync(const char *data, ViplexCallback callback);
    static void nvSetManualPowerSwitchStatusAsync(const char *data, ViplexCallback callback);
    static void nvGetManualPowerSwitchStatusAsync(const char *data, ViplexCallback callback);
    
    //音量调节
    static void nvGetVolumeAsync(const char *data, ViplexCallback callback);
    static void nvSetVolumeAsync(const char *data, ViplexCallback callback);
    static void nvSetTimingVolumeAsync(const char *data, ViplexCallback callback);
	static void nvGetTimingVolumeAsync(const char *data, ViplexCallback callback);
    static void nvGetVolumeFor0x99Async(const char *data, ViplexCallback callback);
    static void nvSetVolumeFor0x99Async(const char *data, ViplexCallback callback);
    static void nvSetTimingVolumeFor0x99Async(const char *data, ViplexCallback callback);
    static void nvGetTimingVolumeFor0x99Async(const char *data, ViplexCallback callback);

    //VPN连接管理
    static void nvGetVPNConnectInfoAsync(const char *data, ViplexCallback callback);
    static void nvSetVPNConnectInfoAsync(const char *data, ViplexCallback callback);

    //AppManager
    static void nvGetInstalledPackageInfoAsync(const char *data, ViplexCallback callback);
    static void nvGetRunningPackageInfoAsync(const char *data, ViplexCallback callback);
    static void nvForceStopAppAsync(const char *data, ViplexCallback callback);
    static void nvUninstallPackageAsync(const char *data, ViplexCallback callback);
    static void nvStartUploadApkCoreAsync(const char *data, ViplexCallback callback);

    //播放日志
    static void nvGetPlaylogPathAsync(const char *data, ViplexCallback callback);

    //字体
    static void nvGetTerminalFontAsync(const char *data, ViplexCallback callback);
    static void nvDeleteFontAsync(const char *data, ViplexCallback callback);
    static void nvUpdateFontAsync(const char *data, ViplexCallback callback);

    //多屏拼接
	static void nvGetSpliceInfoAsync(const char *data, ViplexCallback callback);
	static void nvSetSpliceInfoAsync(const char *data, ViplexCallback callback);

    //Sensor
	static void nvGetSupportSensorInfoAsync(const char *data, ViplexCallback callback);
	static void nvSetSupportSensorInfoAsync(const char *data, ViplexCallback callback);

    //RadioFrequency
	static void nvGetLoraInfoAsync(const char *data, ViplexCallback callback);

    //PowerController
    static void nvSetPowerInfoManualAsync(const char *data, ViplexCallback callback);
    static void nvSetPowerInfoPolicyAsync(const char *data, ViplexCallback callback);
    static void nvGetPowerInfoPolicyAsync(const char *data, ViplexCallback callback);
    static void nvGetPowerInfoStatusAsync(const char *data, ViplexCallback callback);
    static void nvSetPowerModeAsync(const char *data, ViplexCallback callback);
    static void nvGetPowerModeAsync(const char *data, ViplexCallback callback);
    static void nvSetRelayPowerManualAsync(const char *data, ViplexCallback callback);
    static void nvSetRelayPowerPolicyAsync(const char *data, ViplexCallback callback);
    static void nvGetRelayPowerPolicyAsync(const char *data, ViplexCallback callback);
    static void nvGetRelayPowerStatusAsync(const char *data, ViplexCallback callback);
    static void nvSetRelayPowerStatusAsync(const char *data, ViplexCallback callback);

    //VideoSourceController
    static void nvGetVideoControlInfoAsync(const char *data, ViplexCallback callback);
	static void nvSetVideoControlInfoAsync(const char *data, ViplexCallback callback);
	static void nvSetVideoEDIDAsync(const char *data, ViplexCallback callback);
	static void nvGetVideoEDIDAsync(const char *data, ViplexCallback callback);
	static void nvGetVideoSourceManualFor0x99Async(const char *data, ViplexCallback callback);
	static void nvSetVideoSourceManualFor0x99Async(const char *data, ViplexCallback callback);
	static void nvGetVideoSourcePolicyFor0x99Async(const char *data, ViplexCallback callback);
	static void nvSetVideoSourcePolicyFor0x99Async(const char *data, ViplexCallback callback);

    //userInfo
	static void nvSetUserInfoAsync(const char *data, ViplexCallback callback);
	static void nvGetUserInfoAsync(const char *data, ViplexCallback callback);

    //Login
    static void nvSearchTerminalAsync(ViplexCallback resultCallBack);
	static void nvSearchAppointIpAsync(const char * appointIp, ViplexCallback resultCallBack);
	static void nvSearchRangeIpAsync(const char *rangeIp, ViplexCallback resultCallBack);
    static void nvFindAllTerminalsAsync(ViplexCallback resultCallBack);
	static void nvLoginAsync(const char *data, ViplexCallback resultCallBack);
	static void nvChangePassWordAsync(const char *data, ViplexCallback resultCallBack);
	static void nvDelTerminalInfoAsync(const char *data, ViplexCallback resultCallBack);
	static void nvSetScreenInfoAsync(const char *data, ViplexCallback resultCallBack);
	static void nvGetTerminalInfoAsync(const char *data, ViplexCallback resultCallBack);
	static void nvSetTerminalInfoAsync(const char *data, ViplexCallback resultCallBack);
	static void nvSetSystemInfoAsync(const char *data, ViplexCallback resultCallBack);
	static void nvLogoutAsync(const char *data, ViplexCallback resultCallBack);
	static void nvGetFirmwareInfosAsync(const char *data, ViplexCallback resultCallBack);
	static void nvGetInstalledPackageVersionsAsync(const char *data, ViplexCallback resultCallBack);
	static void nvGetProductInfoAsync(const char *data, ViplexCallback resultCallBack);
	static void nvGetconfigurationAsync(const char *data, ViplexCallback resultCallBack);

    //ScreenBrightness	
	static void nvSetBrightnessAdjustModeAsync(const char *data, ViplexCallback callback);
	static void nvGetBrightnessAdjustModeAsync(const char *data, ViplexCallback callback);
	static void nvSetScreenBrightnessAsync(const char *data, ViplexCallback callback);
	static void nvGetScreenBrightnessAsync(const char *data, ViplexCallback callback);
	static void nvGetBrightnessPolicyAsync(const char *data, ViplexCallback callback);
	static void nvSetBrightnessPolicyAsync(const char *data, ViplexCallback callback);
	static void nvGetEnvironmentBrightnessAsync(const char *data, ViplexCallback callback);
	static void nvsetManualBrightnessFor0x99Async(const char *data, ViplexCallback callback);
	static void nvsetPolicyBrightnessFor0x99Async(const char *data, ViplexCallback callback);
	static void nvgetPolicyBrightnessFor0x99Async(const char *data, ViplexCallback callback);
    static void nvgetManualBrightnessFor0x99Async(const char *data,ViplexCallback callback);
    static void nvGetEnvironmentBrightnessParameterAsync(const char *data, ViplexCallback callback);
    static void nvSetEnvironmentBrightnessParameterAsync(const char *data, ViplexCallback callback);


    //TemperatureController
    static void nvGetColorTemperatureAsync(const char *data, ViplexCallback callback);
	static void nvSetColorTemperatureAsync(const char *data, ViplexCallback callback);

    //SwitchController
	static void nvSetScreenPowerModeAsync(const char *data, ViplexCallback callback);
	static void nvGetScreenPowerModeAsync(const char *data, ViplexCallback callback);
	static void nvSetScreenPowerStateAsync(const char *data, ViplexCallback callback);
	static void nvGetScreenPowerStateAsync(const char *data, ViplexCallback callback);
	static void nvGetScreenPowerPolicyAsync(const char *data, ViplexCallback callback);
	static void nvSetScreenPowerPolicyAsync(const char *data, ViplexCallback callback);
	static void nvsetScreenPowerManual0x99Async(const char *data, ViplexCallback callback);
	static void nvsetScreenPowerPolicy0x99Async(const char *data, ViplexCallback callback);
	static void nvGetScreenPowerManual0x99Async(const char *data, ViplexCallback callback);
	static void nvGetScreenPowerPolicyFor0x99Async(const char *data, ViplexCallback callback);

    //ListManager
	static void nvGetProgramInfoAsync(const char *data, ViplexCallback callback);
	static void nvDeletePlayListAsync(const char *data, ViplexCallback callback);
	static void nvStartPlayAsync(const char *data, ViplexCallback callback);
	static void nvPausePlayAsync(const char *data, ViplexCallback callback);
	static void nvResumePlayAsync(const char *data, ViplexCallback callback);
	static void nvStopPlayAsync(const char *data, ViplexCallback callback);

    //AdvancedFeatures
	static void nvSetSyncPlayAsync(const char *data, ViplexCallback callback);
	static void nvGetSyncPlayAsync(const char *data, ViplexCallback callback);
    static void nvRebootAsync(const char *data, ViplexCallback callback);
	static void nvSetReBootWipeUserDataAsync(const char *data, ViplexCallback callback);
	static void nvClearAllMediasAsync(const char *data, ViplexCallback callback);
	static void nvGetOTGUSBModeAsync(const char *data, ViplexCallback callback);
	static void nvSetOTGUSBModeAsync(const char *data, ViplexCallback callback);
	static void nvSetCurrentResolutioAsync(const char *data, ViplexCallback callback);
	static void nvGetCurrentResolutionAsync(const char *data, ViplexCallback callback);
	static void nvGetSupportedResolutionAsync(const char *data, ViplexCallback callback);

	static void nvGetReBootTaskAsync(const char *data, ViplexCallback callback);
	static void nvSetReBootTaskAsync(const char *data, ViplexCallback callback);
	static void nvGetHdmiOutputStatusAsync(const char *data, ViplexCallback callback);
	static void nvSetHdmiOutputStatusAsync(const char *data, ViplexCallback callback);
	static void nvSetCustomResolutionAsync(const char *data, ViplexCallback callback);

    //AcquisitionReceiver
	static void nvGetPickerReceiverAsync(const char *data, ViplexCallback callback);
	static void nvAddCollectorAsync(const char *data, ViplexCallback callback);
	static void nvDeleteCollectorAsync(const char *data, ViplexCallback callback);

    //UpgradeManager
	static void nvQueryUpdateFileByTypeAsync(const char *data, ViplexCallback callback);
	static void nvGetOnlineUpgradeFileAsync(const char *data, ViplexCallback callback);
	static void nvDownloadUpgradeFileAsync(const char *data, ViplexCallback callback);
	static void nvStopDownloadUpgradeFileAsync(const char *data, ViplexCallback callback);
    static void nvReadFileContentFromZipFileAsync(const char *data, ViplexCallback callback);
	static void nvUpdateAppAsync(const char *data, ViplexCallback callback);
	static void nvUpdateOSAsync(const char *data, ViplexCallback callback);
    static void nvStartUploadApkAsync(const char *data, ViplexCallback callback);
	static void nvStopCurrentUpdateTaskAsync(const char *data, ViplexCallback callback);
	static void nvUpdateVerifyAsync(const char *data, ViplexCallback callback);

    //网络配置
    static void nvGetWifiListAsync(const char *data, ViplexCallback callback);
    static void nvConnectWifiNetworkAsync(const char *data, ViplexCallback callback);
    static void nvGetWifiCurrentStatusAsync(const char *data, ViplexCallback callback);
    static void nvDisconnectWifiNetworkAsync(const char *data, ViplexCallback callback);
    static void nvGetWifiEnabledAsync(const char *data, ViplexCallback callback);
    static void nvSetWifiEnabledAsync(const char *data, ViplexCallback callback);
    static void nvSendForgetWifiCommandAsync(const char *data, ViplexCallback callback);
    static void nvGetMobileNetworkAsync(const char *data, ViplexCallback callback);
    static void nvSetMobileNetworkAsync(const char *data, ViplexCallback callback);
    static void nvIsMobileModuleExistedAsync(const char *data, ViplexCallback callback);
    static void nvGetEthernetInfoAsync(const char *data, ViplexCallback callback);
    static void nvSetEthernetInfoAsync(const char *data, ViplexCallback callback);
    static void nvGetAPNetworkAsync(const char *data, ViplexCallback callback);
    static void nvSetAPNetworkAsync(const char *data, ViplexCallback callback);
    static void nvGetAPNInfoAsync(const char *data, ViplexCallback callback);
    static void nvSetAPNInfoAsync(const char *data, ViplexCallback callback);
    static void nvSetFlightModeAsync(const char *data, ViplexCallback callback);
    static void nvGetFlightModeAsync(const char *data, ViplexCallback callback);
    static void nvGet4GNetworkStatusAsync(const char *data, ViplexCallback callback);
	static void nvGetAPNetworkOpenStatusAsync(const char *data, ViplexCallback callback);
	static void nvSetAPNetworkOpenStatusAsync(const char *data, ViplexCallback callback);
	static void nvSetWifiApStationSwitchAsync(const char *data, ViplexCallback callback);
	static void nvGetModuleInfoAsync(const char *data, ViplexCallback callback);

    //ScreenConfiguration
    static void nvGetScreenAttributeAsync(const char *data, ViplexCallback callback);
    static void nvSetScreenAttributeAsync(const char *data, ViplexCallback callback);
    static void nvSetRecvCardFileAsync(const char *data, ViplexCallback callback);

    //ICareConfigurator
    static void nvGetIcareConfigInfoAsync(const char *data, ViplexCallback callback);
    static void nvSetIcareConfigInfoAsync(const char *data, ViplexCallback callback);

    //CloudConfigurator
    static void nvSetBindPlayerAsync(const char *data, ViplexCallback callback);
    static void nvGetCloudPlayerListAsync(const char *data, ViplexCallback callback);
    static void nvGetBindPlayerAsync(const char *data, ViplexCallback callback);

    //MonitorConfigurator
    static void nvGetAvailableStorageDataAsync(const char *data, ViplexCallback callback);
    static void nvGetCPUUsageAsync(const char *data, ViplexCallback callback);
	static void nvGetCPUTempAsync(const char *data, ViplexCallback callback);
	static void nvGetAvailableMemoryAsync(const char *data, ViplexCallback callback);
	static void nvGetSendCardMonitorInfoAsync(const char *data, ViplexCallback callback);
	static void nvGetReceiverCountAndInfoAsync(const char *data, ViplexCallback callback);
	static void nvGetMonitorInfoByReceiverIndexAsync(const char *data, ViplexCallback callback);

    //ScreenManager
	static void nvGetCurrentTimeAndZoneAsync(const char *data, ViplexCallback callback);
	static void nvCalibrateTimeAsync(const char *data, ViplexCallback callback);
	static void nvGetNetTimingInfoAsync(const char *data, ViplexCallback callback);
	static void nvSetNetTimingInfoAsync(const char *data, ViplexCallback callback);
    static void nvGetNetTimingListInfoAsync(const char *data, ViplexCallback callback);
    static void nvAddNetTimingInfoAsync(const char *data, ViplexCallback callback);
    static void nvDeleteNetTimingInfoAsync(const char *data, ViplexCallback callback);
    static void nvUpdateNetTimingInfoAsync(const char *data, ViplexCallback callback);
    static void nvAddNetTimingInfoListAsync(const char *data, ViplexCallback callback);
	static void nvGetIsUseDayLightTimeAsync(const char *data, ViplexCallback callback);

    //ScreenShot 
    static void nvDownLoadScreenshotAsync(const char *data, ViplexCallback callback);
    static void nvDownLoadScreenshotNetAsync(const char* data, ViplexCallback callback);

	static void nvSetRotationAsync(const char *data, ViplexCallback callback);
	static void nvGetRotationAsync(const char *data, ViplexCallback callback);
	static void nvGetDisplayInfoAsync(const char *data, ViplexCallback callback);
	static void nvSetTimeAndZoneAsync(const char *data, ViplexCallback callback);
	static void nvSetScreenShotAsync(const char *data, ViplexCallback callback);

    static void nvGetScreenUnitTempAsync(const char *data, ViplexCallback callback);
	static void nvDataBaseMigrationAsync(const char *data, ViplexCallback callback);
    static void nvDownLoadFilesAsync(const char *data, ViplexCallback callback);
    static void nvQueryFileByTypeAsync(const char *data, ViplexCallback callback);

    //EditProgram
    static void nvCreateProgramAsync(const char *data, ViplexCallback callback);
    static void nvSetPageProgramAsync(const char *data, ViplexCallback callback);
    static void nvSetPageProgramsAsync(const char *data, ViplexCallback callback);
    static void nvMakeProgramAsync(const char *data, ViplexCallback callback);
    static void nvSetSystemTplInfoAsync(const char *data, ViplexCallback callback);
    static void nvAddTplAsync(const char *data, ViplexCallback callback);
    static void nvEditTplAsync(const char *data, ViplexCallback callback);
    static void nvDeleteTplAsync(const char *data, ViplexCallback callback);
    static void nvGetProgramAsync(const char *data, ViplexCallback callback);
    static void nvDeleteProgramAsync(const char *data, ViplexCallback callback);
    static void nvStartTransferProgramAsync(const char *data, ViplexCallback callback);
    static void nvStopProgramTransferAsync(const char *data, ViplexCallback callback);
	static void nvGetCustomerTplAsync(const char *data, ViplexCallback callback);
	static void nvGetFileMD5Async(const char *data, ViplexCallback callback);
    static void nvSetAudioMedioProgramAsync(const char *data,ViplexCallback callback);
    static void nvTransferProgramAsync(const char* data, ViplexCallback callback);
    

    //节点服务器列表
    static void nvGetNodeServerListAsync(const char *data, ViplexCallback callback);
    static void nvAddNodeServerListAsync(const char *data, ViplexCallback callback);
    static void nvDeleteNodeServerListAsync(const char *data, ViplexCallback callback);
    static void nvChangeNodeServerListAsync(const char *data, ViplexCallback callback);
    static void nvAddNodeServerInfoListAsync(const char *data, ViplexCallback callback);

    //feedback
    static void nvUploadFeedbackInfoAsync(const char *data, ViplexCallback callback);
    static void nvUploadFeedBackFileStateAsync(const char *data, ViplexCallback callback);

    //StatusCollector
    static void nvStartGetAvailableMemoryDataAsync(const char *data, ViplexCallback callback);
    static void nvFinishDataAsync(const char *data, ViplexCallback callback);

    //BindingManager
	static void nvIsCommonCloudAsync(const char *data, ViplexCallback callback);
	static void nvGetPlayerIdentiferAsync(const char *data, ViplexCallback callback);
	static void nvIsExistPlayerNameAsync(const char *data, ViplexCallback callback);
    static void nvNewSetBindPlayerAsync(const char *data, ViplexCallback callback);
    static void nvGetTokenAsync(const char *data, ViplexCallback callback);
    static void nvGetTimeZoneAsync(const char *data, ViplexCallback callback);

	static void nvDownloadTerminalLogAsync(const char *data, ViplexCallback callback);
	static void nvUploadTerminalLogAsync(const char *data, ViplexCallback callback);
	static void nvCheckNetworkAsync(const char *data, ViplexCallback callback);
	static void nvCancelFunctionAsync(const char *data, ViplexCallback callback);
    static void nvDownloadTerminalAllLogAsync(const char *data,ViplexCallback callback);
    static void nvDownloadTerminalPlayLogAsync(const char *data,ViplexCallback callback);
    static void nvDownloadTerminalPlayLogNetAsync(const char* data, ViplexCallback callback);
    static void nvDownloadTerminalLogNetAsync(const char* data, ViplexCallback callback);

	static void nvGetScreenDeviceInfoAsync(const char *data, ViplexCallback callback);
	//Handy上云
	static void nvLogOutAsync(ViplexCallback callback);

	static void nvLoginVnnox(const char *data, ViplexCallback callback);
	static void nvGetVerifyCode(const char *data, ViplexCallback callback);
	static void nvRegisterVnnox(const char *data, ViplexCallback callback);



	static void nvRsaEncodeAsync(const char *data, ViplexCallback callback);
	static void nvRsaDecodeAsync(const char *data, ViplexCallback callback);
	
	

private:
    static void doSomething(ViplexCallback callback, ns::APIContent &apiContent, const uint16_t code, const char * data);

    static std::string getSNFromData(const std::string &data);
    static std::string m_credentials;
    static std::string m_terminalInfo;
    static std::string m_sdkRootDir;
    static std::string m_diskSN;
    static std::string m_devLang;
};

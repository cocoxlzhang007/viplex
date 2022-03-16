#include "demoChildGUI.h"
#include "qnamespace.h"
#include "qdebug.h"
#include "QStyledItemDelegate"
#include "QNetworkInterface"
#pragma execution_character_set("utf-8")
QString snVPlayerW9A5HAJW = "{\"sn\":\"W9A5HAJW\"}";
QString snBZSA07194A0049999716 = "{\"sn\":\"BZSA07194A0049999716\"}";
QString snBZVA28407N3X20008006 = "{\"sn\":\"BZVA28407N3X20008006\"}";
QString getIcareConfigInfoData = "{\"sn\":\"BZSA07194A0049999716\",\"requestInfo\":{\"language\":\"en\"}}";
QString setIcareConfigInfoData = "{\"sn\":\"BZSA07194A0049999716\",\"requestInfo\":{\"state\":true,\"url\":\"monitor-cn.vnnox.com\",\"username\":\"tangsf\"}}";
QString getBindPlayerData = "{\"sn\":\"BZSA07194A0049999716\"}";
QString setBindPlayerData = "{\"sn\":\"BZSA07194A0049999716\",\"playerInfo\":{\"baseUrl\":\"https://api-cn.vnnox.com\",\"data\":{\"playerList\":[{\"identifier\":\"8c8de85c3c8610cc32e3e91bc9cf3fa2##Taurus-49999716\",\"isUsed\":true,\"name\":\"Taurus-49999716\",\"playerIdentifier\":\"BZSA07194A0049999716\"}],\"token\":\"8c8d58dbb519b7ba08c1e8f86001d7198c0d6161\"},\"isNewVnnox\":true,\"password\":\"123456\",\"username\":\"tangsf\"}}";
QString getNodeServerListData = "{\"lang\":\"en\"}";
QString addNodeServerListData = "{\"label\":\"dangjintao\",\"node\":\"123.123.123\"}";
QString changeNodeServerlistData = "{\"oldServer\":{\"label\":\"dangjintao\",\"node\":\"123.123.123\"},\"newServer\" :{\"label\":\"zhangsan11111\",\"node\":\"1340.111.111\"}}";
QString deleteNodeServerListData = "{\"node\":\"134.111.111\",\"label\":\"zhangsan11111\"}";
QString getCloudPlayerListData = "{\"host\":\"beta-rest.vnnox.com\", \"data\":{\"username\":\"qht1003077897\",\"password\":\"qht1003077897\",\"playerType\":2}}";
QString setNetTimingInfoData = "{\"sn\":\"BZWA17422J1X20000093\",\"TimingInfo\" : {\"enable\":true,\"ntp\" : {\"enable\":true,\"server\" : \"http://ntpsss.net\"},\"lora\" : {\"address\": 1,\"channel\" : 23,\"enable\" : false, \"mode\" : \"MASTER\",\"groupId\" : \"novad101\"},\"gps\":{\"enable\":false},\"compatibility\" : {\"supportLoraInfo\":true}}}";
QString setsetScreenAttribute = "{\"sn\":\"BZSA07194A0049999716\",\"screenAttribute\":{\"screenAttributes\":[{\"id\":0,\"orders\":[0],\"portNumber\":1,\"scanInfos\":[{\"connectIndex\":0,\"height\":400,\"portIndex\":0,\"width\":400,\"x\":0,\"xInPort\":0,\"y\":0,\"yInPort\":0}],\"screenSource\":1,\"xCount\":1,\"xOffset\":0,\"yCount\":1,\"yOffset\":0}]}}";
QString getIsUseDayLightTimeStr = "{\"sn\":\"BZVA28407N3X20008006\",\"isUseDayLightTimeData\":{\"timeZone\":\"Asia/Shanghai\",\"gmt\" : \"GMT+08:00\"}}";

QString getNetTimingInfoData = "{\"sn\":\"BZSA07194A0049999716\"}";
QString addNetTimingInfoData = "{\"label\" : \"zhangsan\",\"node\" : \"123.123.123\"}";
QString updateNetTimingInfoData = "{\"oldServer\":{\"label\":\"zhangsan\",\"node\" : \"123.123.123\"},\"newServer\" :{\"label\":\"111\",\"node\" : \"111.111.111\"}}";
QString deleteNetTimingInfoData = "{\"label\" : \"zhangsan\",\"node\" : \"123.123.123\"}";
QString getNetTimingListInfoData = "{\"lang\":\"en\"}";
QString setVolumeData = "{\"sn\":\"BZWA17422J1X20000093\",\"volumeInfo\" :{\"ratio\":60.0}}";
QString getVolumeData = "{\"sn\":\"BZWA17422J1X20000093\"}";
QString calibrateTimeData = "{ \"sn\":\"BZWA17422J1X20000093\",\"currentTime\":\"2020-03-12 02:37:10\",\"timeZoneInfo\" : {\"utcTimeMillis\":1234455433,\"timeZone\":\"Asia/Shanghai\",\"gmt\":\"GMT+08:00\",\"isTimeOffsetEnable\" : true,\"beginTime\" : \"5-23\",\"endTime\" : \"12-23\",\"timeOffsetValue\" : 6000}}";
QString getCurrentTimeAndZoneData = "{\"sn\":\"BZWA17422J1X20000093\"}";
QString setColorTemperatureData = "{\"sn\":\"BZWA17422J1X20000093\",\"colorTemperatureInfo\" :{\"colorTemperature\":12}}";
QString getColorTemperatureData = "{\"sn\":\"BZWA17422J1X20000093\"}";
QString setBrightnessAdjustModeData = "{\"sn\":\"BZWA17422J1X20000093\",\"brightnessAdjustModeInfo\":{\"mode\":\"MANUALLY\"}}";
QString sn = "{\"sn\":\"BZSA07194A0049999716\"}";
QString setScreenBrightnessData = "{\"sn\":\"BZWA17422J1X20000093\",\"screenBrightnessInfo\":{\"ratio\":0.5}}";
QString getBrightnessPolicyData = "{\"sn\":\"BZWA17422J1X20000093\",\"brightnessPolicyInfo\":{\"isSupportCompleteCron\":false}}";
QString setBrightnessPolicyData = "{\"sn\":\"\",\"taskInfo\":{\"type\":\"BRIGHTNESS\",\"source\":{\"type\":0,\"platform\":2},\"enable\":true,\"conditions\":[{\"type\":2,\"cron\":[\"0 15 10 ? ** *\"],\"args\":[12000,20,80,40,10],\"startTime\":\"2017-09-01 00:00:00\",\"endTime\":\"4016-06-06 23:59:59\",\"enable\":true},{\"type\":1,\"cron\":[\"0 15 10 ? **\"],\"startTime\":\"2017-09-01 00:00:00\",\"endTime\":\"4016-06-06 23:59:59\",\"args\":[30],\"enable\":true}],\"segmentConfig\":{\"args\":[12000,20,80,40,10],\"segments\":[{\"environmentBrightness\":12000,\"screenBrightness\":80},{\"environmentBrightness\":10000,\"screenBrightness\":60}],\"opticalFailureInfo\":{\"enable\":true,\"screenBrightness\":30}},\"timeStamp\":\"2018-07-19 11:27:15\"}}";
QString setManualBrightnessFor0x99Data = "{\"sn\":\"BZSA07194A0049999716\",\"data\":{\"ratio\":0.5}}";
QString getManualBrightnessFor0x99Data = "{\"sn\":\"BZSA07194A0049999716\"}";
QString setPolicyBrightnessFor0x99Data = "{\"sn\":\"BZSA07194A0049999716\",\"taskInfo\":{\"enable\":true,\"conditions\":[{\"type\":2,\"cron\":[\"0 15 10 ? * *\"],\"args\":[12000,20,80,40,10],\"segments\":[{\"environmentBrightness\":12000,\"screenBrightness\":80},{\"environmentBrightness\":10000,\"screenBrightness\":60}],\"opticalFailureInfo\":{\"enable\":true,\"screenBrightness\":30},\"startTime\":\"2017-09-01 00:00:00\",\"endTime\":\"4016-06-06 23:59:59\",\"enable\":true},{\"type\":1,\"cron\":[\"0 15 10 ? * *\"],\"args\":[30],\"enable\":true,\"startTime\":\"2017-09-01 00:00:00\",\"endTime\":\"4016-06-06 23:59:59\"}],\"segmentConfig\":{\"args\":[12000,20,80,40,10],\"segments\":[{\"environmentBrightness\":12000,\"screenBrightness\":80},{\"environmentBrightness\":10000,\"screenBrightness\":60}],\"opticalFailureInfo\":{\"enable\":true,\"screenBrightness\":30}},\"timeStamp\":\"2018-07-19 11:27:15\"}}";
QString setScreenPowerAdjustModeData = "{\"sn\":\"W9A5HAJW\",\"taskInfo\":{\"mode\":\"MANUALLY\"}}";
QString setScreenPowerData = "{\"sn\":\"W9A5HAJW\",\"taskInfo\":{\"state\":\"open\"}}";
QString setScreenPowerPolicyData = "{\"sn\":\"W9A5HAJW\",\"taskInfo\":{\"type\":\"SCREENPOWER\",\"source\":{\"type\":0,\"platform\":2},\"enable\":true,\"conditions\":[{\"cron\":[\"0 15 10 ? * *\",\"0 0 12 * * ?\"],\"action\":\"OPEN\",\"enable\":true},{\"cron\":[\"0 15 10 ? * *\",\"0 0 12 * * ?\"],\"action\":\"CLOSE\",\"enable\":true}]}}";
QString getPolicyBrightnessFor0x99Data = "{\"sn\":\"BZSA07313J0350000997\",\"data\":null}";
QString setScreenPowerManual0x99Data = "{\"sn\":\"W9A5HAJW\",\"taskInfo\":{\"state\":\"OPEN\"}}";
QString setScreenPowerPolicy0x99Data = "{\"sn\":\"W9A5HAJW\",\"taskInfo\":{\"enable\":true,\"conditions\":[{\"cron\":[\"0 15 10 ? * *\",\"0 0 12 * * ?\"],\"action\":\"OPEN\",\"enable\":true},{\"cron\":[\"0 40 17 ? * *\",\"0 0 11 * * ?\"],\"action\":\"CLOSE\",\"enable\":true}]}}";
QString getScreenPowerManual0x99Data = "{\"sn\":\"W9A5HAJW\",\"data\":null}";
QString GetScreenPowerPolicyFor0x99Data = "{\"sn\":\"W9A5HAJW\",\"data\":null}";

QString setSyncPlayInfo = "{\"sn\":\"W9A5HAJW\",\"enable\":true}";
QString reBootWipeUserData = "{\"sn\":\"BZWA17422J1X20000093\",\"setInfo\":{\"reason\":\"terminal connect failed\"}}";
QString getotgusbmoderesultinfo = "\"value\":1.0";
QString setOTGUSBModeData = "{\"sn\":\"BZWA17422J1X20000093\",\"modeInfo\":{\"value\":1.0}}";
QString getCurrentResolutionData = "{\"sn\":\"BZWA17422J1X20000093\",\"requestInfo\":{\"displayMode\":1}}";
QString getCurrentResolutionResult = "{\"value\":\"1280x720p-60\"}";
QString setCurrentResolutionData = "{\"sn\":\"BZWA17422J1X20000093\",\"resolutionInfo\":{\"displayMode\":1,\"resolutionValue\":\"1280x720p-60\"}}";
QString getSupportedResolutionResult = "{\"result\":[{\"value\":\"2048x256p-60\"},{\"value\":\"4096x512p-60\"},{\"value\":\"1920x1080p-60\"},{\"value\":\"720x480p-60\"},{\"value\":\"1280x720p-60\"}]}";
QString getFirewareInfoData = "{\"sn\":\"\",\"\",\"\"}";
QString getInstalledPackageInfoData = "{\"sn\":\"BZWA17422J1X20000093\",\"packageInfo\":{\"packageName\":[\"nova.priv.terminal.syssetting\", \"nova.priv.terminal.easypluto\"]}}";
QString getProductInfoResult = "{\"productInfo\":{\"productName\":\"T3\",\"modelId\" : 10043},\"configInfo\" : {\"videoSwitch\": false,\"displayDevice\" : \"LED\",\"portConfig\" : [{\"portNO\": 1,\"isMainPort\" : true,\"belongMainPort\" : 0},{\"portNO\": 2,\"isMainPort\" : true,\"belongMainPort\" : 0}]}}";
QString getAPNetworkResult = "{\"aliasName\":\"AP\",\"suffix\":\"0016\",\"password\":\"12345678\",\"channelId\":10}";
QString setAPNetworkInfo = "{\"sn\":\"BZWA17422J1X20000093\",\"aliasName\":\"AP\",\"suffix\":\"0016\",\"password\":\"12345678\",\"channelId\":10}";
QString setVideoControlInfoStr = "{\"sn\":\"BZWA17422J1X20000093\",\"videdSourceInfo\":{\"type\":\"VIDEO_SOURCE_SWITCH\",\"source\":{\"type\":1,\"platform\":2},\"videoMode\":1,\"videoSource\":0,\"isScale\":false,\"offsetX\":0,\"offsetY\":0,\"conditions\":[{\"cron\":\"0 0 12 ? * *\",\"source\":0,\"enable\":true},{\"cron\":\"0 0 12 ? * *\",\"source\":1,\"enable\":true}]}}";
QString downloadScreenShotStr = "{\"sn\":\"BZWA17422J1X20000093\",\"width\":100,\"height\":100,\"downLoadDirectoryPath\":\"d:\",\"pictureName\":\"a.png\",\"pictureType\":1}";
QString downloadScreenShotNetStr = "{\"sn\":\"BZWA17422J1X20000093\",\"width\":100,\"height\":100,\"url\":\"http://10.10.10.114:18081/file/\",\"pictureType\":1}";
QString strsetRotation = "{\"sn\":\"BZSA07194A0049999716\",\"taskInfo\":{\"rotationValue\":1}}";
QString strgetRotation = "{\"sn\":\"BZSA07194A0049999716\"}";
QString strgetDisplayInfo = "{\"sn\":\"BZSA07194A0049999716\"}";
QString strsetTimeAndZone = "{\"sn\":\"BZSA07194A0049999716\",\"taskInfo\":{\"utcTimeMillis\":1234455433,\"timeZone\":\"Asia/Shanghai\",\"gmt\":\"GMT+08:00\",\"isTimeOffsetEnable\":true,\"beginTime\":\"5-23\",\"endTime\":\"12-23\",\"timeOffsetValue\":6000}}";
QString strsetScreenShot = "{\"sn\":\"BZSA07194A0049999716\",\"taskInfo\":{\"uploadOssInfo\":{\"accessid\":\"eMYWoIbIam9NsYRC\",\"host\":\"https://novacloud-test.oss-cn-hangzhou.aliyuncs.com\",\"policy\":\"eyJleHBpcmF0aW9uIjoiMjAxOS0xMS0yMVQwOTo0OTowMFoiLCJjb5nZSIsMCwxMDQ4NTc2=\",\"signature\":\"xt/XaiwvkNe3q2KlIRGN63iQSoI=\",\"expire\":\"1574300940\",\"callback\":\"eyJjYWxsYmFja1VybCI6Imh0dHA6XC9cL3Rlc3QtcmVzdC52bm5veC5m9ybV\",\"dir\":\"CheckPlatform/\"},\"sessionID\":\"h0dHA6XC9cL3Rlc3QtcmVzdC52bm5veC5m9.jpg\"}}";


QString startGetAvailableMemoryData = "{\"sn\":\"BZWA17422J1X20000093\",\"period\":1000}";
QString finishData = "{\"sn\":\"BZWA17422J1X20000093\",\"type\":\"CPU_USAGE\"}";
QString connectWifiNetworkData = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"ssid\":\"AirStation\",\"password\":\"12345678\"}}";
QString disconnectWifiNetworkData = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"ssid\":\"AirStation\"}}";
QString setWifiEnabledData = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"state\":1}}";
QString sendForgetWifiCommandData = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"ssid\":\"airStation\"}}";
QString getMobileNetworkData = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"ssid\":\"airStation\"}}";
QString setMobileNetworkData = "{\"sn\":\"BZWA17422J1X20000093\",\"mobileData\":{\"basicConfigs\":{\"mobileData\":true,\"dataRoaming\":true,\"enable4G\":true},\"advanced\":{\"networkType\":\"AUTO\",\"APN\":{\"providerName\":\"中国移动\"}}}}";
QString setEthernetInfoData = "{\"sn\":\"123465\",\"taskInfo\":{\"ethernets\":[{\"dhcp\":true,\"dns\":[\"172.16.0.201\",\"172.16.0.202\"],\"gateWay\":\"172.16.10.1\",\"ip\":\"172.16.10.106\",\"mask\":\"255.255.255.0\",\"name\":\"eth0\",\"scopeId\":-1}]}}";
QString forceStopAppStr = "{ \"sn\":\"BZWA17422J1X20000093\",\"requestInfo\" : {\"packageName\":\"nova.priv.terminal.screenService\"}}";
QString UninstallPackageStr = "{ \"sn\":\"BZWA17422J1X20000093\",\"packageName\":\"nova.priv.terminal.screenService\"}";
QString runAPPStr = "{\"sn\":\"BZSA79353N1310006847\",\"requestInfo\":{\"packageName\":\"nova.priv.terminal.daemonservice\"}}";
QString queryUpdateFile = "{\"paths\":[\"C:/Users/Public/viplexcore/fileundertest/test1\"],\"types\" : [\"*.nuzip\"],\"pageIndex\" : 0,\"pageSize\" : 100,}";
QString readJsonFormZipFile = "{\"zipFilePaths\":[\"D:/test/updatezip/VPlayer Update3.8.0.0201_x64.nuzip\"],\"dFileNames\" : [\"package_description.json\"]}";
QString startUpdateApp = "{\"sn\":\"W9A5HAJW\",\"filePath\":\"D:/test/update/VPlayer Update3.8.0.0201_x64.nuzip\"}";
QString startUpdateOS = "{\"sn\":\"BZSA07194A0049999716\",\"filePath\":\"C:/Users/Public/viplexcore/fileundertest/test1/UPDATE_OS_T3T4T6T8_TAURUSV010901CN0101.nuzip\"}";
QString updateVerify = "{\"sn\":\"W9A5HAJW\",\"verifyInfo\":{\"commonSupportedProducts\":[\"VPlayer\"],\"version\":\"3.8.0.0201\",\"totalSize\":183173120,\"description\":\"fgfgg\",\"packetType\":\"NUZIP\",\"excutionType\":\"UPDATE\",\"createdDate\":\"2018-07-10T16:42:49Z+08:00\",\"packages\":[{\"type\":\"EXE\",\"version\":\"3.8.0.0201\",\"name\":\"VPlayer Update3.8.0.0201_x64.exe\",\"identifier\":\"114ff74b5d8654e12a691531fa5fa139\",\"size\":183173120,\"startupAfterInstalled\":true, \"supportedProducts\" : []}]}}";
QString stopUpdate = "{\"sn\":\"W9A5HAJW\"}";
QString addPageStr = "{\"programID\":1,\"tplID\":1}";
QString setPageParamStr = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"pageNew\",\"widgetContainers\":[{\"audioGroup\":\"\",\"backgroundColor\":\"#00000000\",\"backgroundDrawable\":\"\",\"contents\":{\"widgetGroups\":[],\"widgets\":[{\"id\":1,\"mid\":2,\"name\":\"\",\"type\":\"PICTURE\",\"duration\":10000,\"repeatCount\":1,\"layout\":{\"x\":\"0\",\"y\":\"0\",\"width\":\"0.5\",\"height\":\"0.5\"},\"displayRatio\":\"ORIGINAL\",\"inAnimation\":{\"type\":1,\"duration\":1000},\"outAnimation\":{\"type\":0,\"duration\":0},\"dataSource\":\"26a0debe893d5c837270c60dde463913.png\",\"originalDataSource\":\"D:/nova/dog.png\",\"backgroundMusic\":\"/local/media/1.mp3\",\"backgroundColor\":\"#00ff0000\",\"backgroundDrawable\":\"/local/media/dog.png\",\"zOrder\":100,\"constraints\":[{\"startTime\":\"2016-11-14T12:15:15Z+8:00\",\"cron\":[],\"endTime\":\"2017-02-10T12:15:15Z+8:00\"}],\"fold\":{\"enable\":true,\"count\":2,\"orientation\":\"HORIZONTAL\",\"layoutItems\":[{\"y\":0,\"height\":200,\"x\":0,\"width\":200},{\"y\":200,\"height\":200,\"x\":0,\"width\":200}]},\"metadata\":\"\"}]},\"enable\":true,\"id\":1,\"itemsSource\":\"\",\"layout\":{\"height\":\"0.2863\",\"width\":\"0.3573\",\"x\":\"0.5\",\"y\":\"0\"},\"name\":\"widgetContainers1\",\"pickCount\":0,\"pickPolicy\":\"ORDER\",\"zOrder\":0}]}}";
QString setPageParamStrRSS = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"pageNew\",\"widgetContainers\":[{\"zOrder\":1,\"layout\":{\"x\":\"0\",\"y\":\"0\",\"width\":\"1\",\"height\":\"1\"},\"border\":{\"foregroundColor\":\"#FF008000\",\"width\":1,\"name\":\"border\",\"borderThickness\":\"0px,0px,0px,0px\",\"cornerRadius\":\"2%\",\"backgroundColor\":\"#FF000000\",\"style\":0,\"styleForExpress\":0,\"effects\":{\"speed\":3,\"animation\":\"CLOCK_WISE\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"contents\":{\"widgets\":[{\"layout\":{\"x\":\"0%\",\"y\":\"0%\",\"width\":\"100%\",\"height\":\"100%\"},\"inAnimation\":{\"type\":0,\"duration\":1000},\"outAnimation\":{\"type\":0,\"duration\":1000},\"border\":{\"foregroundColor\":\"#FF008000\",\"width\":1,\"name\":\"border\",\"borderThickness\":\"0px,0px,0px,0px\",\"cornerRadius\":\"2%\",\"backgroundColor\":\"#FF000000\",\"style\":0,\"styleForExpress\":0,\"effects\":{\"speed\":3,\"animation\":\"CLOCK_WISE\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"constraints\":[{\"startTime\":\"1970-01-01T00:00:00Z+8:00\",\"endTime\":\"4012-01-01T23:59:59Z+8:00\",\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"]}],\"metadata\":{\"updatePeriod\":60000,\"titleEnable\":true,\"pubTimeEnable\":true,\"bodyEnable\":true,\"bodyImageEnable\":false,\"displayStyle\":{\"type\":\"PAGE_SWITCH\",\"singleLine\":true,\"pageSwitchAttributes\":{\"inAnimation\":{\"type\":17,\"duration\":1000},\"remainDuration\":5000},\"scrollAttributes\":{\"effects\":{\"speed\":5,\"animation\":\"MARQUEE_UP\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"offset\":{\"x\":0,\"y\":0}},\"textAttributes\":{\"title\":{\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#FF0000\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":18,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0},\"pubTime\":{\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#FFFF00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":16,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0},\"body\":{\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#00FF00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":18,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0}},\"TitleFontFamily\":\"Arial\",\"PubTimeFontFamily\":\"Arial\",\"ContentFontFamily\":\"Arial\"},\"displayRatio\":\"FULL\",\"filesize\":1024,\"zOrder\":1,\"dataSource\":\"http://tech.qq.com/web/it/telerss.xml\",\"backgroundColor\":\"#00000000\",\"backgroundDrawable\":\"\",\"backgroundMusic\":\"\",\"name\":\"RSS\",\"enable\":true,\"type\":\"SIMPLE_RSS\",\"duration\":10000,\"repeatCount\":1,\"id\":100000,\"uuid\":\"099a5635-8250-4392-9ede-964087db8bc6\"}],\"widgetGroups\":[],\"widgetContainer\":[],\"enable\":false,\"zOrder\":0,\"id\":0,\"uuid\":\"5a0e9597-737a-428f-acd8-a0846b480d97\"},\"PCType\":0,\"name\":\"页面1\",\"enable\":true,\"pickPolicy\":\"ORDER\",\"id\":200000,\"uuid\":\"3ee6e06b-5a05-4cd7-84b8-c8668b4f6d53\"}]}}";
QString setPageParamStrColorFul = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"pageNew\",\"widgetContainers\":[{\"zOrder\":1,\"layout\":{\"x\":\"0\",\"y\":\"0\",\"width\":\"1\",\"height\":\"1\"},\"border\":{\"foregroundColor\":\"#FF008000\",\"width\":1,\"name\":\"border\",\"borderThickness\":\"0px,0px,0px,0px\",\"cornerRadius\":\"2%\",\"backgroundColor\":\"#FF000000\",\"style\":0,\"styleForExpress\":0,\"effects\":{\"speed\":3,\"animation\":\"CLOCK_WISE\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"contents\":{\"widgets\":[{\"layout\":{\"x\":\"0%\",\"y\":\"0%\",\"width\":\"100%\",\"height\":\"100%\"},\"inAnimation\":{\"type\":0,\"duration\":1000},\"outAnimation\":{\"type\":0,\"duration\":1000},\"border\":{\"foregroundColor\":\"#FF008000\",\"width\":1,\"name\":\"border\",\"borderThickness\":\"0px,0px,0px,0px\",\"cornerRadius\":\"2%\",\"backgroundColor\":\"#FF000000\",\"style\":0,\"styleForExpress\":0,\"effects\":{\"speed\":3,\"animation\":\"CLOCK_WISE\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"constraints\":[{\"startTime\":\"1970-01-01T00:00:00Z+8:00\",\"endTime\":\"4012-01-01T23:59:59Z+8:00\",\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"]}],\"metadata\":{\"content\":{\"content\":\"请输入文字!\",\"scrollAttributes\":{\"effects\":{\"speed\":5,\"animation\":\"MARQUEE_LEFT\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"textAttributes\":{\"effects\":{\"type\":\"GRADIENT_HORIZONTAL\",\"colors\":[\"#FF0000\",\"#FF00B050\",\"#FFC00000\",\"#FF007BD4\",\"#FFFFFF00\",\"#FF00FF\"],\"texture\":\"\",\"TempTexturePath\":\"\"},\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#FF0000\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":50,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":2,\"shadowDy\":2,\"shadowColor\":\"#6128bf\",\"strokeEnable\":false,\"strokeWidth\":2,\"strokeColor\":\"#6128bf\",\"letterSpacing\":1}},\"FontFamily\":\"Arial\",\"FontStyle\":\"Normal\",\"FontWeight\":\"Normal\"},\"displayRatio\":\"FULL\",\"filesize\":1024,\"zOrder\":1,\"backgroundColor\":\"#FF1F8787\",\"backgroundDrawable\":\"\",\"backgroundMusic\":\"\",\"name\":\"炫彩字\",\"enable\":true,\"type\":\"COLORFUL_TEXT\",\"duration\":10000,\"repeatCount\":1,\"id\":100000,\"uuid\":\"3dc02eef-b736-4817-b107-ea4c696e61f1\"}],\"widgetGroups\":[],\"widgetContainer\":[],\"enable\":false,\"zOrder\":0,\"id\":0,\"uuid\":\"71052088-28d3-48cf-9f03-08e16e189fe8\"},\"PCType\":0,\"name\":\"页面1\",\"enable\":true,\"pickPolicy\":\"ORDER\",\"id\":200000,\"uuid\":\"9e2a4114-6bec-4cb0-8d3e-93652ff0bb50\"}]}}";
QString setPageParamStRt = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"pageNew\",\"widgetContainers\":[{\"zOrder\":1,\"layout\":{\"x\":\"0\",\"y\":\"0\",\"width\":\"1\",\"height\":\"1\"},\"border\":{\"foregroundColor\":\"#FF008000\",\"width\":1,\"name\":\"border\",\"borderThickness\":\"0px,0px,0px,0px\",\"cornerRadius\":\"2%\",\"backgroundColor\":\"#FF000000\",\"style\":0,\"styleForExpress\":0,\"effects\":{\"speed\":3,\"animation\":\"CLOCK_WISE\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"contents\":{\"widgets\":[{\"layout\":{\"x\":\"0%\",\"y\":\"0%\",\"width\":\"100%\",\"height\":\"100%\"},\"inAnimation\":{\"type\":0,\"duration\":1000},\"outAnimation\":{\"type\":0,\"duration\":1000},\"border\":{\"foregroundColor\":\"#FF008000\",\"width\":1,\"name\":\"border\",\"borderThickness\":\"0px,0px,0px,0px\",\"cornerRadius\":\"2%\",\"backgroundColor\":\"#FF000000\",\"style\":0,\"styleForExpress\":0,\"effects\":{\"speed\":3,\"animation\":\"CLOCK_WISE\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"constraints\":[{\"startTime\":\"1970-01-01T00:00:00Z+8:00\",\"endTime\":\"4012-01-01T23:59:59Z+8:00\",\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"]}],\"metadata\":{\"_height\":500,\"updatePeriod\":60000,\"temperatureUnit\":\"Celsius\",\"regular\":\"噪音:$n\\n温度:$t\\n气湿:$AH\\n气压:$AP\\n风速:$WS\\n风向:$WD\\nPM2.5:$PM2.5\\nPM10:$PM10\\nCO2:$CO2\\n\",\"solidText\":{\"text\":\"\",\"textAttributes\":{\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":12,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0}},\"textAttributes\":{\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"楷体\"],\"style\":\"NORMAL\",\"size\":32,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0},\"valueTextAttributes\":{\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":16,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0},\"unitTextAttributes\":{\"backgroundColor\":\"#00FFFFFF\",\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":32,\"isUnderline\":false},\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0},\"temperatureCompensation\":0,\"displayStyle\":{\"type\":\"PAGE_SWITCH\",\"singleLine\":true,\"pageSwitchAttributes\":{\"inAnimation\":{\"type\":1,\"duration\":1000},\"remainDuration\":3000},\"scrollAttributes\":{\"effects\":{\"speed\":3,\"animation\":\"MARQUEE_UP\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"offset\":{\"x\":0,\"y\":0}},\"layoutStyles\":[{\"type\":1,\"horizontalAlignment\":\"RIGHT\",\"proportion\":50},{\"type\":0,\"horizontalAlignment\":\"CENTER\",\"proportion\":1},{\"type\":4,\"horizontalAlignment\":\"CENTER\",\"proportion\":49}],\"regularContents\":[{\"key\":\"$t\",\"type\":0,\"unit\":\"℃\",\"compensation\":0.0},{\"key\":\"$n\",\"type\":0,\"unit\":\"dB\",\"compensation\":0.0},{\"key\":\"$WS\",\"type\":0,\"unit\":\"km/h\",\"compensation\":0.0},{\"key\":\"$WD\",\"type\":0,\"unit\":\"\",\"compensation\":0.0,\"Templates\":[\"北风\",\"东北风\",\"东风\",\"东南风\",\"南风\",\"西南风\",\"西风\",\"西北风\"]},{\"key\":\"$AT\",\"type\":0,\"unit\":\"℃\",\"compensation\":0.0},{\"key\":\"$AP\",\"type\":0,\"unit\":\"kPa\",\"compensation\":0.0},{\"key\":\"$AH\",\"type\":0,\"unit\":\"%RH\",\"compensation\":0.0},{\"key\":\"$PM2.5\",\"type\":0,\"unit\":\"μg/m³\",\"compensation\":0.0},{\"key\":\"$PM10\",\"type\":0,\"unit\":\"μg/m³\",\"compensation\":0.0},{\"key\":\"$CO2\",\"type\":0,\"unit\":\"ppm\",\"compensation\":0.0}],\"RTVisibleList\":[2,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0],\"ValueFontFamily\":\"Arial\",\"UnitFontFamily\":\"Arial\",\"FixedTextFontFamily\":\"Arial\",\"FontFamily\":\"楷体\",\"TemperatureLable\":\"温度:\",\"NoiseLable\":\"噪音:\",\"WindSpeedLable\":\"风速:\",\"WindDirectionLable\":\"风向:\",\"AirTemperatureLable\":\"气温:\",\"AirPressureLable\":\"气压:\",\"AirHumiLable\":\"气湿:\",\"PM25Lable\":\"PM2.5:\",\"PM10Lable\":\"PM10:\",\"CO2Lable\":\"CO2:\"},\"displayRatio\":\"FULL\",\"filesize\":1024,\"zOrder\":1,\"backgroundColor\":\"#FF1F8787\",\"backgroundDrawable\":\"\",\"backgroundMusic\":\"\",\"name\":\"环境监测\",\"enable\":true,\"type\":\"RT_MEDIA\",\"duration\":10000,\"repeatCount\":1,\"id\":100000,\"uuid\":\"3dc02eef-b736-4817-b107-ea4c696e61f1\"}],\"widgetGroups\":[],\"widgetContainer\":[],\"enable\":false,\"zOrder\":0,\"id\":0,\"uuid\":\"71052088-28d3-48cf-9f03-08e16e189fe8\"},\"PCType\":0,\"name\":\"页面1\",\"enable\":true,\"pickPolicy\":\"ORDER\",\"id\":200000,\"uuid\":\"9e2a4114-6bec-4cb0-8d3e-93652ff0bb50\"}]}}";
QString setPageParamStrTimer = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"pageNew\",\"widgetContainers\":[{\"zOrder\":1,\"contents\":{\"widgets\":[{\"constraints\":[{\"startTime\":\"1970-01-01T00:00:00Z+8:00\",\"endTime\":\"4012-01-01T23:59:59Z+8:00\",\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"]}],\"metadata\":{\"FontFamily\":\"Arial\",\"solidText\":{\"textAttributes\":{\"font\":{\"size\":48,\"isUnderline\":false,\"family\":[\"Arial\"],\"style\":\"NORMAL\"},\"textColor\":\"#FF0000\",\"backgroundColor\":\"#00FFFFFF\",\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0},\"text\":\"\"},\"textAttributes\":{\"font\":{\"size\":48,\"isUnderline\":false,\"family\":[\"Arial\"],\"style\":\"NORMAL\"},\"textColor\":\"#FF0000\",\"backgroundColor\":\"#00FFFFFF\",\"shadowEnable\":false,\"ShadowRadius\":0,\"ShadowDx\":0,\"shadowDy\":0,\"shadowColor\":\"#00ff00\",\"strokeEnable\":false,\"strokeWidth\":0,\"letterSpacing\":0},\"regularNew\":\"$d&#160;$Ud&#160;$H&#160;$UH&#160;$m&#160;$Um&#160;$s&#160;$Us\",\"units\":[{\"zero\":\"天\",\"name\":\"$Ud\",\"singular\":\"天\",\"plural\":\"天\"},{\"zero\":\"时\",\"name\":\"$UH\",\"singular\":\"时\",\"plural\":\"时\"},{\"zero\":\"分\",\"name\":\"$Um\",\"singular\":\"分\",\"plural\":\"分\"},{\"zero\":\"秒\",\"name\":\"$Us\",\"singular\":\"秒\",\"plural\":\"秒\"}],\"regular\":\"$d&#160;天&#160;$H&#160;时&#160;$m&#160;分&#160;$s&#160;秒\",\"targetDateTime\":1602864000000,\"countType\":\"COUNT_DOWN\"},\"filesize\":1024,\"zOrder\":1,\"dataSource\":\"\",\"name\":\"计时器\",\"enable\":true,\"type\":\"COUNT_TIMER\",\"duration\":10000,\"repeatCount\":1,\"id\":100000}],\"zOrder\":0,\"id\":0},\"PCType\":0,\"name\":\"页面1\",\"enable\":true,\"pickPolicy\":\"ORDER\",\"id\":200000}]}}";
QString setPageParamStrRSSSimple = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目01\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":10000,\"metadata\":{\"titleEnable\":true,\"pubTimeEnable\":true,\"bodyEnable\":true,\"bodyImageEnable\":false,\"displayStyle\":{\"type\":\"PAGE_SWITCH\",\"pageSwitchAttributes\":{\"inAnimation\":{\"type\":17,\"duration\":1000},\"remainDuration\":5000},\"scrollAttributes\":{\"effects\":{\"speed\":5,\"animation\":\"MARQUEE_UP\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}}},\"textAttributes\":{\"title\":{\"textColor\":\"#FF0000\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":18,\"isUnderline\":false}},\"pubTime\":{\"textColor\":\"#FFFF00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":16,\"isUnderline\":false}},\"body\":{\"textColor\":\"#00FF00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":18,\"isUnderline\":false}}}},\"dataSource\":\"http://tech.qq.com/web/it/telerss.xml\",\"type\":\"SIMPLE_RSS\",\"name\":\"RSS\",\"originalDataSource\":\"\",\"isSupportSpecialEffects\":true}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
QString setPageParamStrColorFulSimple = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目01\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":10000,\"metadata\":{\"content\":{\"content\":\"请输入文字!\",\"scrollAttributes\":{\"effects\":{\"speed\":5,\"animation\":\"MARQUEE_LEFT\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"textAttributes\":{\"effects\":{\"type\":\"GRADIENT_HORIZONTAL\",\"colors\":[\"#FF0000\",\"#FF00B050\",\"#FFC00000\",\"#FF007BD4\",\"#FFFFFF00\",\"#FF00FF\"],\"texture\":\"\"},\"textColor\":\"#FF0000\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":50,\"isUnderline\":false}}}},\"dataSource\":\"\",\"type\":\"COLORFUL_TEXT\",\"name\":\"炫彩字\",\"originalDataSource\":\"\",\"isSupportSpecialEffects\":true}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
QString setPageParamStRtSimple = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目01\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":10000,\"metadata\":{\"updatePeriod\":10000,\"temperatureUnit\":\"Celsius\",\"regular\":\"噪音:$n\\n温度:$t\\n气湿:$AH\\n气压:$AP\\n风速:$WS\\n风向:$WD\\nPM2.5:$PM2.5\\nPM10:$PM10\\nCO2:$CO2\\n\",\"solidText\":{\"text\":\"\",\"textAttributes\":{\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":12,\"isUnderline\":false}}},\"textAttributes\":{\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"楷体\"],\"style\":\"NORMAL\",\"size\":32,\"isUnderline\":false}},\"valueTextAttributes\":{\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":16,\"isUnderline\":false}},\"unitTextAttributes\":{\"textColor\":\"#FFF56E00\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":32,\"isUnderline\":false}},\"displayStyle\":{\"type\":\"PAGE_SWITCH\",\"pageSwitchAttributes\":{\"inAnimation\":{\"type\":1,\"duration\":1000},\"remainDuration\":3000},\"scrollAttributes\":{\"effects\":{\"speed\":3,\"animation\":\"MARQUEE_UP\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}}},\"layoutStyles\":[{\"type\":1,\"horizontalAlignment\":\"RIGHT\",\"proportion\":50},{\"type\":0,\"horizontalAlignment\":\"CENTER\",\"proportion\":1},{\"type\":4,\"horizontalAlignment\":\"CENTER\",\"proportion\":49}],\"regularContents\":[{\"key\":\"$t\",\"type\":0,\"unit\":\"℃\"},{\"key\":\"$n\",\"type\":0,\"unit\":\"dB\"},{\"key\":\"$WS\",\"type\":0,\"unit\":\"km/h\"},{\"key\":\"$WD\",\"type\":0,\"unit\":\"\",\"Templates\":[\"北风\",\"东北风\",\"东风\",\"东南风\",\"南风\",\"西南风\",\"西风\",\"西北风\"]},{\"key\":\"$AT\",\"type\":0,\"unit\":\"℃\"},{\"key\":\"$AP\",\"type\":0,\"unit\":\"kPa\"},{\"key\":\"$AH\",\"type\":0,\"unit\":\"%RH\"},{\"key\":\"$PM2.5\",\"type\":0,\"unit\":\"μg/m³\"},{\"key\":\"$PM10\",\"type\":0,\"unit\":\"μg/m³\"},{\"key\":\"$CO2\",\"type\":0,\"unit\":\"ppm\"}]},\"dataSource\":\"\",\"type\":\"RT_MEDIA\",\"name\":\"环境监测\",\"originalDataSource\":\"\",\"isSupportSpecialEffects\":true}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
QString setPageParamStrTimerSimple = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目01\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":10000,\"metadata\":{\"solidText\":{\"textAttributes\":{\"font\":{\"size\":48,\"isUnderline\":false,\"family\":[\"Arial\"],\"style\":\"NORMAL\"},\"textColor\":\"#FF0000\"},\"text\":\"\"},\"textAttributes\":{\"font\":{\"size\":48,\"isUnderline\":false,\"family\":[\"Arial\"],\"style\":\"NORMAL\"},\"textColor\":\"#FF0000\"},\"regularNew\":\"$d&#160;$Ud&#160;$H&#160;$UH&#160;$m&#160;$Um&#160;$s&#160;$Us\",\"units\":[{\"zero\":\"天\",\"name\":\"$Ud\",\"singular\":\"天\",\"plural\":\"天\"},{\"zero\":\"时\",\"name\":\"$UH\",\"singular\":\"时\",\"plural\":\"时\"},{\"zero\":\"分\",\"name\":\"$Um\",\"singular\":\"分\",\"plural\":\"分\"},{\"zero\":\"秒\",\"name\":\"$Us\",\"singular\":\"秒\",\"plural\":\"秒\"}],\"regular\":\"$d&#160;天&#160;$H&#160;时&#160;$m&#160;分&#160;$s&#160;秒\",\"targetDateTime\":1602864000000,\"countType\":\"COUNT_DOWN\"},\"dataSource\":\"\",\"type\":\"COUNT_TIMER\",\"name\":\"计时器\",\"originalDataSource\":\"\",\"isSupportSpecialEffects\":true}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
QString setPageParamStrHtml = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"pageNew\",\"widgetContainers\":[{\"zOrder\":1,\"contents\":{\"widgets\":[{\"constraints\":[{\"startTime\":\"1970-01-01T00:00:00Z+8:00\",\"endTime\":\"4012-01-01T23:59:59Z+8:00\",\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"]}],\"filesize\":1024,\"zOrder\":1,\"dataSource\":\"https://www.baidu.com/\",\"name\":\"网页\",\"enable\":true,\"type\":\"HTML\",\"duration\":10000,\"repeatCount\":1,\"id\":100000}],\"zOrder\":0,\"id\":0},\"PCType\":0,\"name\":\"页面1\",\"enable\":true,\"pickPolicy\":\"ORDER\",\"id\":200000}]}}";
QString setPageParamStrStream = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"pageNew\",\"widgetContainers\":[{\"zOrder\":1,\"contents\":{\"widgets\":[{\"constraints\":[{\"startTime\":\"1970-01-01T00:00:00Z+8:00\",\"endTime\":\"4012-01-01T23:59:59Z+8:00\",\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"]}],\"metadata\":{\"subType\":\"STREAM\",\"modelData\":{\"src\":\"http://ivi.bupt.edu.cn/hls/cctv1hd.m3u8\",\"volume\":100,\"stream_media_type\":\"m3u8\",\"stream_media_protocol_type\":\"hls\"}},\"filesize\":1024,\"zOrder\":1,\"dataSource\":\"\",\"name\":\"流媒体\",\"enable\":true,\"type\":\"STREAM_MEDIA\",\"duration\":10000,\"repeatCount\":1,\"id\":100000}],\"zOrder\":0,\"id\":0},\"PCType\":0,\"name\":\"页面1\",\"enable\":true,\"pickPolicy\":\"ORDER\",\"id\":200000}]}}";
QString getPageParamStr = "{\"programID\":1,\"pageID\":1}";
QString deletePageStr = "{\"programID\":1,\"pageID\":1}";
QString addWidgetStr = "{\"programID\":3,\"pageID\":1,\"widgetContainerID\":1,\"taskInfo\":[{\"widgetMediaType\":\"PICTURE\",\"widget\":{\"mid\":2,\"name\":\"\",\"type\":\"PICTURE\",\"duration\":10000,\"repeatCount\":1,\"layout\":{\"x\":\"34.6%\",\"y\":\"24.0%\",\"width\":\"100%\",\"height\":\"100%\"},\"displayRatio\":\"ORIGINAL\",\"inAnimation\":{\"type\":1,\"duration\":1000},\"outAnimation\":{\"type\":0,\"duration\":0},\"dataSource\":\"26a0debe893d5c837270c60dde463913.png\",\"originalDataSource\":\"D:/nova/dog.png\",\"backgroundMusic\":\"/local/media/1.mp3\",\"backgroundColor\":\"#00ff0000\",\"backgroundDrawable\":\"/local/media/dog.png\",\"zOrder\":100,\"constraints\":[{\"startTime\":\"2016-11-14T12:15:15Z+8:00\",\"cron\":[],\"endTime\":\"2017-02-10T12:15:15Z+8:00\"}],\"fold\":{\"enable\":true,\"count\":2,\"orientation\":\"HORIZONTAL\",\"layoutItems\":[{\"y\":0,\"height\":200,\"x\":0,\"width\":200},{\"y\":200,\"height\":200,\"x\":0,\"width\":200}]},\"metadata\":\"\"}}]}";
QString setWidgetParamStr = "{\"programID\":1,\"pageID\":1,\"widgetContainerID\":1,\"widgetID\":1,\"widget\":{\"id\":1,\"mid\":2,\"name\":\"newdog\",\"type\":\"PICTURE\",\"duration\":10000,\"repeatCount\":1,\"layout\":{\"x\":\"34.6%\",\"y\":\"24.0%\",\"width\":\"100%\",\"height\":\"100%\"},\"displayRatio\":\"ORIGINAL\",\"inAnimation\":{\"type\":1,\"duration\":1000},\"outAnimation\":{\"type\":0,\"duration\":0},\"dataSource\":\"26a0debe893d5c837270c60dde463913.png\",\"originalDataSource\":\"D:/nova/dog.png\",\"backgroundMusic\":\"/local/media/1.mp3\",\"backgroundColor\":\"#00ff0000\",\"backgroundDrawable\":\"/local/media/dog.png\",\"zOrder\":100,\"constraints\":[{\"startTime\":\"2016-11-14T12:15:15Z+8:00\",\"cron\":[],\"endTime\":\"2017-02-10T12:15:15Z+8:00\"}],\"fold\":{\"enable\":true,\"count\":2,\"orientation\":\"HORIZONTAL\",\"layoutItems\":[{\"y\":0,\"height\":200,\"x\":0,\"width\":200},{\"y\":200,\"height\":200,\"x\":0,\"width\":200}]},\"metadata\":\"\"}}";
QString getWidgetParamStr = "{\"programID\":1,\"pageID\":1,\"widgetContainerID\":1,\"widgetID\":1}";
QString deleteWidgetStr = "{\"programID\":1,\"pageID\":1,\"widgetContainerID\":1,\"widgetID\":1}";

QString createProgram = "{\"name\":\"jiemu1\",\"width\":400,\"height\":400,\"tplID\":4,\"winInfo\":{\"height\":100,\"width\":100,\"left\":100,\"top\":100,\"zindex\":0,\"index\":1}}";
QString makeProgram = "{\"programID\":1,\"outPutPath\":\"C:/Users/Public/viplexcore/db\"}";
QString systemTpl = "{\"data\":[{\"width\":0.5,\"height\":0.5,\"left\":0.5,\"top\":0.5,\"zindex\":0},{\"width\":0.5,\"height\":0.5,\"left\":0.5,\"top\":0.5,\"zindex\":0},{\"width\":0.5,\"height\":0.5,\"left\":0.5,\"top\":0.5,\"zindex\":0}]}";
QString addTpl = "{\"data\":[{\"width\":0.4,\"height\":0.4,\"left\":0.4,\"top\":0.4,\"zindex\":1}]}";
QString editTpl = "{\"tplID\":6,\"data\":[{\"width\":0.6,\"height\":0.6,\"left\":0.6,\"top\":0.6,\"zindex\":6}]}";
QString deleteTpl = "{\"tplID\":6}"; 
QString getProgram = "";
QString deleteProgram = "{\"programID\":[1]}";

QString startTransferProgram = "{\"sn\":\"W9A5HAJW\",\"iconPath\":\"D:/test/program/9d30c74beba509cc6e6102b002f1fd9d/4e76df08-25ea-473a-8935-d9d2b0acdb4a.png\",\"iconName\":\"4e76df08-25ea-473a-8935-d9d2b0acdb4a.png\",\"sendProgramFilePaths\":{\"programPath\":\"D:/test/program/9d30c74beba509cc6e6102b002f1fd9d/\",\"mediasPath\":{}},\"programName\":\"local_net_planl\",\"deviceIdentifier\":\"\",\"startPlayAfterTransferred\":true,\"insertPlay\":true}";
QString startTransferProgram1 = "{\"sn\":\"W9A5HAJW\",\"iconPath\":\"D:/test/program/91c59f75db8fd2c43fbebb8c2c9cc426/be9cbc43-4555-470f-88e9-c6a361789ac9.png\",\"iconName\":\"be9cbc43-4555-470f-88e9-c6a361789ac9.png\",\"sendProgramFilePaths\":{\"programPath\":\"D:/test/program/91c59f75db8fd2c43fbebb8c2c9cc426/\",\"mediasPath\":{}},\"programName\":\"local_net_planl\",\"deviceIdentifier\":\"\",\"startPlayAfterTransferred\":true,\"insertPlay\":true}";
//QString startTransferProgram = "{\"sn\":\"W9A5HAJW\",\"sendProgramFilePath\":\"D:/testResource/video\",\"programName\":\"program2\",\"deviceIdentifier\":\"\",\"startPlayAfterTransferred\":true,\"insertPlay\":true}";
QString stopProgramTransfer = "";
QString strSetPageParams = "{\"programID\":1,\"sceneItems\":[{\"id\":1,\"page\":{\"id\":1,\"name\":\"节目06\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z 8:00\",\"startTime\":\"1970-01-01T00:00:00Z 8:00\"}],\"duration\":5000,\"metadata\":{\"date\":{\"textAttributes\":{\"font\":{\"size\":16},\"textColor\":\"#ffffff00\"},\"weekTemplates\":[\"星期日\",\"星期一\",\"星期二\",\"星期三\",\"星期四\",\"星期五\",\"星期六\"]},\"hourHand\":{\"color\":\"#ffffff00\"},\"minuteHand\":{\"color\":\"#ff00ff00\"},\"secondHand\":{\"color\":\"#ffff0000\"},\"text\":{\"text\":\"\",\"textAttributes\":{\"font\":{\"size\":12},\"textColor\":\"#ffff0000\"}}},\"name\":\"模拟时钟\",\"type\":\"ANALOG_CLOCK\"}]}}]},\"rules\":\"TIMES\",\"repeatCount\":1},{\"id\":2,\"page\":{\"name\":\"节目01\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z 8:00\",\"startTime\":\"1970-01-01T00:00:00Z 8:00\"}],\"duration\":10000,\"metadata\":{\"content\":{\"content\":\"请输入文字!\",\"scrollAttributes\":{\"effects\":{\"speed\":5,\"animation\":\"MARQUEE_LEFT\",\"isHeadTail\":false,\"headTailSpacing\":\"10\",\"speedByPixelEnable\":false}},\"textAttributes\":{\"effects\":{\"type\":\"GRADIENT_HORIZONTAL\",\"colors\":[\"#FF0000\",\"#FF00B050\",\"#FFC00000\",\"#FF007BD4\",\"#FFFFFF00\",\"#FF00FF\"],\"texture\":\"\"},\"textColor\":\"#FF0000\",\"font\":{\"family\":[\"Arial\"],\"style\":\"NORMAL\",\"size\":50,\"isUnderline\":false}}}},\"dataSource\":\"\",\"type\":\"COLORFUL_TEXT\",\"name\":\"炫彩字\",\"originalDataSource\":\"\",\"isSupportSpecialEffects\":true}]},\"id\":1,\"name\":\"widgetContainers1\"}]},\"rules\":\"TIMES\",\"repeatCount\":1}]}";
QString setTerminalInfo = "{\"sn\":\"BZSA07194A0049999716\",\"type\":\"setIgnoreTime\",\"value\":\"2019-12-12 13:24:24\"}";
QString delTerminalInfo = "{\"sn\":\"BZSA07194A0049999716\",\"type\":\"deleteTerminal\"}";
QString setUserInfoStr = "{\"sn\":\"123456\",\"userInfo\":{\"aliasName\":\"Taurus-49999716\",\"registerAddress\":{\"country\":\"中国\",\"province\":\"陕西省\",\"city\":\"西安市\",\"county\":\"雁塔区\",\"address\":\"科技二路，西安软件园\"}}}";
QString strDataBaseMigration = "{\"data\":[{\"ID\":\"100\",\"PLAYSOLUTION\":\"test100\",\"PLAYSOLUTIONRELATION\":\"test100\",\"SCHEDULECONSTRAINT\":\"test100\",\"PLAYLIST\":\"test100\",\"PLAN\":\"test100\",\"width\":\"400\",\"height\":\"400\"},{\"ID\":\"101\",\"PLAYSOLUTION\":\"test101\",\"PLAYSOLUTIONRELATION\":\"test101\",\"SCHEDULECONSTRAINT\":\"test101\",\"PLAYLIST\":\"test101\",\"PLAN\":\"test101\",\"width\":\"500\",\"height\":\"500\"}]}";
QString strUploadFeedbackInfo = "{\"sn\":\"123456\",\"contact\":\"minyf@novastar.tech\",\"description\":\"1736\",\"attacheds\":[]}";
QString strGetPlayerIdentifer = "";
QString strSetTimingPowerSwitchStatus = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"type\":\"FUNCTIONPOWER\",\"source\":{\"type\":1,\"platform\":2},\"data\":[{\"commands\":[{\"conditions\":[{\"cron\":[\"0 15 10 ? * *\",\"0 0 12 * * ?\"],\"action\":0,\"type\":\"屏体电源\",\"startTime\":\"2018-06-06\",\"endTime\":\"2018-06-07\",\"enable\":false,\"powerIndex\":0,\"flag\":\"abc\"},{\"cron\":[\"0 15 10 ? * *\",\"0 0 12 * * ?\"],\"action\":1,\"type\":\"屏体电源\",\"startTime\":\"2018-06-06\",\"endTime\":\"2018-06-07\",\"enable\":false,\"powerIndex\":1,\"flag\":\"abc\"}]}],\"enable\":false,\"portIndex\":0,\"connectIndex\":1}]}}";

QString strSetManualPowerSwitchStatus = "{\"sn\":\"XXXXXXXXXX\",\"data\":{\"type\":\"FUNCTIONPOWER\",\"source\":{\"type\":1,\"platform\":2},\"data\":[{\"conditions\":[{\"action\":1,\"type\":\"屏体电源\",\"powerIndex\":0},{\"action\":1,\"type\":\"风扇电源\",\"powerIndex\":1}],\"portIndex\":0,\"connectIndex\":1}]}}";
QString strGetManualPowerSwitchStatus = "{\"sn\":\"BZSA07194A0049999716\"}";
QString strLogOut = "";

QString strSetFightMode = "{\"sn\":\"BZSA07313J0350001034\",\"enable\":true}";
QString strSetAPNInfo = "{\"sn\":\"BZSA17313J0820001562\",\"APNs\":[{\"carrier\":\"Orange FR-MMS\",\"mcc\":\"208\",\"mnc\":\"01\",\"apn\":\"orange.acte\",\"user\":\"orange\",\"password\":\"orange\",\"server\":\"*\",\"port\":\"80\",\"mmsc\":\"http://mms.orange.fr\",\"mmsproxy\":\"192.168.010.200\",\"mmsport\":\"8080\",\"type\":\"mms\",\"isUserDefined\":false,\"isUsed\":true},{\"carrier\":\"中国移动彩信 (China Mobile)\",\"mcc\":\"460\",\"mnc\":\"00\",\"apn\":\"cmwap\",\"server\":\"*\",\"proxy\":\"10.0.0.172\",\"mmsc\":\"http://mmsc.monternet.com\",\"mmsproxy\":\"10.0.0.172\",\"mmsport\":\"80\",\"type\":\"mms\",\"protocol\":\"IPV4V6\",\"isUserDefined\":false,\"isUsed\":true}]}";
QString strAddCollector = "{\"sn\":\"BZSA17313J0820001562\",\"info\":{\"pickers\":[{\"type\":\"CPU_USAGE\",\"pickType\":\"PERIOD\",\"period\":1000,\"receivers\":[{\"outputDestination\":\"TCP_NET_WORK\",\"persistent\":false}]}]}}";
QString strDeleteCollector = "{\"sn\":123,\"info\":{\"type\":[\"CPU_USAGE\"]}}";

QString strSetAPNetworkOpenStatus = "{\"sn\":\"BZSA17313J0820001562\",\"enable\":false true}";
QString strSetWifiApStationSwitch = "{\"sn\":\"BZSA07201A0010000183\",\"taskInfo\":{\"state\":1,\"ssid\":\"novastar\",\"password\":\"nova123456\"}}";
QString strgetModuleInfo = "{\"sn\":\"BZSA07201A0010000183\"}";


QString strSetVPNConnectInfo = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"guid\":\"123456\",\"taskAction\":\"VPN_CLOSE\",\"source\":{\"type\":1,\"platform\":2},\"vpnInfo\":{\"name\":\"123456\",\"address\":\"vpn.vnnox.com\",\"protocolType\":1,\"username\":\"vnnox\",\"password\":\"123456\",\"sharedSecretKey\":\"novastar.tech\",\"redialNumber\":3,\"redialInterval\":180,\"sessionTimeout\":7200,\"isReconnect\":false}}}";



QString strStartService = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"serviceName\":\"nova.priv.terminal.player.PlayService\"}}";
QString strGetMonitorInfoByReceiverIndex = "{\"sn\":\"BZWA17422J1X20000093\",\"info\":{\"receiveCardRegionInfo\": [{\"portIndex\":0,\"connectedIndex\":0},{	\"portIndex\":0,\"connectedIndex\" : 1}]}}";
QString strDeleteFont = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"fonts\":[{\"name\":\"Arail\"}]}}";


QString strGetTimingVolume = "{\"sn\":\"BZSA79353N1310006847\"}";
QString strSetTimingVolume = "{\"sn\":\"BZSA79353N1310006847\",\"data\":{\"type\":\"VOLUME\",\"source\":{\"type\":0,\"platform\":2},\"enable\":true,\"conditions\":[{\"cron\":[\"0 15 10 ? * *\"],\"value\":50.0,\"enable\":true,\"startTime\":\"2020-09-01 00:00:00\",\"endTime\":\"4016-06-06 24:00:00\"},{\"cron\":[\"0 15 10 ? * *\"],\"value\":0,\"enable\":true,\"startTime\":\"2020-09-01 00:00:00\",\"endTime\":\"4016-06-06 24:00:00\"}]}}";
QString strGetLogPath = "{\"sn\":\"BZSA79353N1310006847\"}";
QString strUpdateFont = "{\"sn\":\"BZWA17422J1X20000093\",\"localFontPath\":\"C:\\\\Windows\\\\Fonts\",\"taskInfo\":{\"fonts\":[{\"name\":\"Agency FB\",\"style\":[\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\"],\"file\":[\"AGENCYB.TTF\",\"AGENCYB.TTF\",\"AGENCYB.TTF\",\"AGENCYB.TTF\",\"AGENCYB.TTF\"]},{\"name\":\"Algerian\",\"style\":[\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\"],\"file\":[\"ALGER.TTF\",\"ALGER.TTF\",\"ALGER.TTF\",\"ALGER.TTF\",\"ALGER.TTF\"]},{\"name\":\"Arial\",\"style\":[\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\"],\"file\":[\"arial.ttf\",\"arial.ttf\",\"arial.ttf\",\"arial.ttf\",\"arial.ttf\"]},{\"name\":\"Arial Black\",\"style\":[\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\",\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\",\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\",\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\"],\"file\":[\"ariblk.ttf\",\"ariblk.ttf\",\"ariblk.ttf\",\"ariblk.ttf\",\"ariblk.ttf\",\"arialbd.ttf\",\"arialbd.ttf\",\"arialbd.ttf\",\"arialbd.ttf\",\"arialbd.ttf\",\"arialbi.ttf\",\"arialbi.ttf\",\"arialbi.ttf\",\"arialbi.ttf\",\"arialbi.ttf\",\"ariali.ttf\",\"ariali.ttf\",\"ariali.ttf\",\"ariali.ttf\",\"ariali.ttf\"]},{\"name\":\"Arial Narrow\",\"style\":[\"Bold\",\"Italic\",\"Normal\",\"Underline\",\"Strikeout\"],\"file\":[\"ARIALN.TTF\",\"ARIALN.TTF\",\"ARIALN.TTF\",\"ARIALN.TTF\",\"ARIALN.TTF\"]}]}}";

QString strSetVideoEDID = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"width\":1920,\"height\":1080}}";

QString strFileManager = "{\"sn\":\"BZWA17422J1X20000093\",\"url\":\"C:/Users/Public/viplexcore/log/ViplexCore.log\"}";

QString strStartPlay = "{\"sn\":\"W9A5HAJW\",\"identifier\":\"d41d8cd98f00b204e9800998ecf8427e1602575438\"}";
QString strStartPlay1 = "{\"sn\":\"W9A5HAJW\",\"identifier\":\"eebc81c89026a10ef16c88355fc62f15\"}";
QString strTerminalStr = "{\"sn\":\"BZSA07194A0049999716\",\"info\":{\"value\":1}";
QString strCustomResolution = "{\"sn\":\"BZSA07194A0049999716\",\"info\":{\"displayMode\":1,\"width\":1920,\"height\":1079}}";

QString strUSBAuthentic = "{\"sn\":\"\",\"taskInfo\":{\"enable\":\"\"}}";

QString getInfraRedConfigStr = "{\"sn\":\"BZVA28407N3X20008006\"}";
QString setInfraRedConfigStr = "{\"sn\":\"BZVA28407N3X20008006\",\"data\":{\"enable\":true,\"trigger\":1,\"condition\":1,\"behaviors\":[{\"type\":\"SCREENPOWER\",\"action\":0},{\"type\":\"VOLUME\",\"action\":0}]}}";

QString strSetPowerInfoPolicy = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":[{\"conditions\":[{\"action\":0,\"cron\":[\"00 33 14 * * ? *\"],\"enable\":true,\"endTime\":\"4016-06-06\",\"flag\":\"a2fa3a07-e0da-94b107ff\",\"powerIndex\":0,\"startTime\":\"2020-08-28\",\"type\":\"屏体电源\"},{\"action\":1,\"cron\":[\"30 33 14 * * ? *\"],\"enable\":true,\"endTime\":\"4016-06-06\",\"flag\":\"a2fa3a07-e0da-94b107ff\",\"powerIndex\":0,\"startTime\":\"2020-08-28\",\"type\":\"屏体电源\"}],\"enable\":true,\"portIndex\":0,\"connectIndex\":0}]}";
QString strSetPowerInfoManual = "{\"sn\":\"123456\",\"taskInfo\":[{\"conditions\":[{\"action\":1,\"type\":\"屏体电源\",\"powerIndex\":0},{\"action\":0,\"type\":\"风扇电源\",\"powerIndex\":1}],\"portIndex\":0,\"connectIndex\":1}]}";
QString strSetManualPower = "{\"sn\":4,\"data\":[{\"type\":\"屏体电源\",\"powerIndex\":-2,\"status\":1}]}";
QString strSetTimingSolidPower = "{\"sn\":\"123456789\",\"data\":[{\"cron\":[\"0 15 10 ? * *\",\"0 15 10 ? * *\"],\"powerIndex\":0,\"type\":\"屏体电源\",\"status\":1,\"startTime\":\"2020-9-6 00:00:00\",\"endTime\":\"2020-9-7 00:00:00\",\"enable\":true}]}";
QString strSetSolidPower = "{\"sn\":\"123456789\",\"data\":{\"relayStatus\":[{\"type\":\"屏体电源\",\"powerIndex\":1}]}}";

QString strSetPowerMode = "{\"sn\":\"123456\",\"taskInfo\":{\"mode\":\"1\"}}";

QString strSetAudioPlayRealTime = "{\"sn\":\"123456\",\"taskInfo\":{\"operate\":\"START\",\"volume\":60.0,\"mediaList\":[{\"id\":1,\"mid\":1,\"name\":\"xxxxxx.mp3\",\"type\":\"AUDIO\",\"md5\":\"asdddaasdasdwwws1251\",\"size\":8568845123,\"content\":\"http://oss.com//XXX.mp3\"}],\"policy\":{\"endType\":\"DURATION\",\"endValue\":\"8456213654\"}}}";
QString strSetAudioPlayPolicy = "{\"sn\":\"123465\",\"taskInfo\":{\"callback\":\"http://www.xxx.com\",\"conditions\":[{\"operate\":\"START\",\"priority\":1,\"mediaList\":[{\"id\":1,\"mid\":1,\"name\":\"xxxxxx.mp3\",\"type\":\"AUDIO\",\"md5\":\"asdasd5465asd1a6dw\",\"size\":8688452,\"content\":\"http://oss.com/XXX.mp3\"}],\"policy\":{\"endType\":\"TIMES\",\"endValue\":\"5\"},\"cron\":[\"29 30 7 11 5 ? 2020\"],\"enable\":true,\"volume\":60}]}}";
QString strSetSupportSensorInfo = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"isUpgradeSensorProgram\":true,\"sensorInfos\":[{\"functionId\":10,\"vendor\":1,\"sensorId\":85,\"baudRate\":115200,\"vendorAliasName\":\"NovaStar\",\"previewValue\":\"-1000.0\",\"previewUnit\":100,\"connected\":true},{\"functionId\":6,\"vendor\":1,\"sensorId\":86,\"baudRate\":115200,\"vendorAliasName\":\"NovaStar\",\"previewValue\":\"-1000.0\",\"previewUnit\":60,\"connected\":true}]}}";
QString strGetSupportSensorInfo = "{\"sn\":\"BZWA17422J1X20000093\",\"taskInfo\":{\"isUpgradeSensorProgram\":true,\"sensorInfos\":\"123\"}}";
QString strVPNfor0x99 = "{\"sn\":\"BZWA17422J1X20000093\",\"action\":6,\"data\":{\"guid\":\"123456\",\"taskAction\":\"VPN_CONNECT\",\"source\":{\"type\":1,\"platform\":2},\"vpnInfo\":{\"name\":\"123456\",\"address\":\"vpn.vnnox.com\",\"protocolType\":1,\"username\":\"vnnox\",\"password\":\"123456\",\"sharedSecretKey\":\"novastar.tech\",\"redialNumber\":3,\"redialInterval\":180,\"sessionTimeout\":7200,\"isReconnect\":false}}}";

QString strsetVideoSourceManualFor0x99 = "{\"sn\":\"BZVA28407N3X20008006\",\"data\":{\"videoSource\":0}}";
QString strsetVideoSourcePolicyFor0x99 = "{\"sn\":\"BZVA28407N3X20008006\",\"data\":{\"enable\":true,\"conditions\":[{\"cron\":\"0 0 12 ? * *\",\"source\":0,\"enable\":true},{\"cron\":\"0 0 12 ? * *\",\"source\":1,\"enable\":true }]}}";

QString strSetTimingReboot = "{\"sn\": \"806FB673\",\"taskInfo\": {\"type\": \"REBOOT\",\"source\": {\"type\": 0,\"platform\": 1},\"executionType\": \"IMMEDIATELY\",\"reason\": \"Just to test\",\"conditions\": [{\"cron\": [\"0 05 15 25 2 ? 2021\"],\"enable\": true}]}}";
QString strClearAllMediasFor0x99 = "{\"sn\":\"BZSA79353N1310006847\",\"data\":{\"scope\":1}}";
QString strSetSyncPlayFor0x99 = "{\"sn\":\"BZSA79353N1310006847\",\"data\":{\"enable\":false}}";

QString strSetPolicySourceOutMode = "{\"sn\":\"BZSA79353N1310006847\",\"currentSourceOutMode\":\"1\"}";

QString batchLoginPassword = "123456";
QString batchSetScreenAttribute = "{\"sn\":\"\",\"screenAttribute\":{\"screenAttributes\":[{\"id\":0,\"orders\":[0],\"portNumber\":1,\"scanInfos\":[{\"connectIndex\":0,\"height\":400,\"portIndex\":0,\"width\":400,\"x\":0,\"xInPort\":0,\"y\":0,\"yInPort\":0}],\"screenSource\":0,\"xCount\":1,\"xOffset\":0,\"yCount\":1,\"yOffset\":0}]}}";
QString batchSetRecvCardFile = "{\"sn\":\"\",\"filePath\":\"D:/6432.rcfgx\",\"fileName\":\"6432.rcfgx\"}";

QString strSetRelayPowerManual = "{\"sn\":\"123456\",\"taskInfo\":[{\"type\":\"本板电源\",\"powerIndex\":1,\"status\":1}]}";
QString strSetRelayPowerPolicy = "{\"sn\":\"123456\",\"taskInfo\":[{\"cron\":[\"0 15 10 ? * *\",\"0 15 10 ? * *\"],\"powerIndex\":0,\"type\":\"本板电源\",\"status\":1,\"startTime\":\"2018-06-06\",\"endTime\":\"2018-06-07\",\"enable\":true},{\"cron\":[\"0 15 10 ? * *\",\"0 15 10 ? * *\"],\"powerIndex\":1,\"status\":0,\"type\":\"本板电源\",\"startTime\":\"2018-06-06\",\"endTime\":\"2018-06-07\",\"enable\":true}]}";
QString strSetRelayPowerStatus = "{\"sn\":\"123456\",\"taskInfo\":{\"relayStatus\":[{\"type\":\"本板电源\",\"powerIndex\":1,\"status\":1}]}}";
QString setScreenAttributeSDK = "{\"sn\":\"123456789\",\"width\":64,\"height\":32,\"xCount\":2,\"yCount\":2,\"portNumber\":1,\"orders\":[0]}";
QString setNetworkCheck = "{\"sn\":\"BZSA79353N1310006847\",\"data\":[{\"type\":1,\"enable\":true,\"address\":\"www.baidu.com\"}]}";

QString downloadTerminalLog = "{\"sn\":\"BZSA79353N1310006847\",\"fileName\":\"test_upload\",\"filePath\":\"E:/test\"}";
QString strDownloadTerminalAllLog = "{\"sn\":\"BZSA79353N1310006847\",\"fileName\":\"test_upload\",\"filePath\":\"E:/test\"}";
QString uploadTerminalLog = "{\"sn\":\"BZSA79353N1310006847\",\"fileName\":\"test_upload.zip\",\"filePath\":\"E:/test/test_upload.zip\"}";
QString cancelFunction = "{\"sn\":\"BZSA79353N1310006847\",\"type\":\"downLoadTerminalLog/upLoadTeminalLog\"}";
QString strEasyPicture = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目01\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":5000,\"dataSource\":\"f239518bb2aa5a52806b751cc3100a04.jpg\",\"type\":\"PICTURE\",\"name\":\"liuwen1.jpg\",\"originalDataSource\":\"D:/liuwen1.jpg\"}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
QString strEasyDigitalClock = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"id\":1,\"name\":\"节目05\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":5000,\"metadata\":{\"gmt\":\"UTC-08:00\",\"suffixTemplates\":[\"上午\",\"下午\"],\"weekTemplates\":[\"星期日\",\"星期一\",\"星期二\",\"星期三\",\"星期四\",\"星期五\",\"星期六\"],\"regular\":\"$MM/$dd/$yyyy\\n$E\\n$HH:$mm:$ss\",\"solidText\":{\"text\":\"\",\"textAttributes\":null},\"textAttributes\":{\"backgroundColor\":\"#00ff00\",\"font\":{\"isUnderline\":false,\"size\":20,\"style\":\"NORMAL\"},\"letterSpacing\":0,\"textColor\":\"#ffff0000\"},\"zone\":\"America/Anchorage\"},\"name\":\"数字时钟\",\"type\":\"DIGITAL_CLOCK\"}]}}]}}";
QString strEasyText = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目01\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":5000,\"metadata\":{\"content\":{\"autoPaging\":true,\"backgroundMusic\":{\"duration\":0,\"isTextSync\":false},\"displayStyle\":{\"scrollAttributes\":{\"effects\":{\"animation\":\"MARQUEE_LEFT\",\"speed\":3}},\"type\":\"SCROLL\"},\"paragraphs\":[{\"backgroundColor\":\"#00000000\",\"horizontalAlignment\":\"CENTER\",\"letterSpacing\":0,\"lineSpacing\":0,\"lines\":[{\"segs\":[{\"content\":\"测试测试测\"}]}],\"verticalAlignment\":\"CENTER\"}],\"textAttributes\":[{\"backgroundColor\":\"#ff000000\",\"attributes\":{\"font\":{\"family\":[\"Arial\"],\"isUnderline\":false,\"size\":20,\"style\":\"NORMAL\"},\"letterSpacing\":0,\"textColor\":\"#ffff0000\"}}]}},\"name\":\"文本\",\"type\":\"ARCH_TEXT\"}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
QString strLoginVnnox = "{\"type\":\"userName\",\"username\":\"qht1003077897\",\"node\":\"cn.vnnox.com\",\"password\":\"qht.19931001\",\"verifyCode\":\"\",\"countryCode\":\"\"}";
                                //"{\"programID\":1,\"taskInfo\":[{\"audioFileName\":\"audioList1.json\",\"data\":{\"audioList\":[{\"enable\":true,\"originalDataSource\":\"F:/test/test111.mp3\"},{\"enable\":true,\"originalDataSource\":\"F:/test/test222.mp3\"}],\"playPolicy\":\"ORDER\"}},{\"audioFileName\":\"audioList2.json\",\"data\":{\"audioList\":[{\"enable\":true,\"originalDataSource\":\"F:/test/test333.mp3\"}],\"playPolicy\":\"ORDER\"}}]}";
//QString strSetAudioMedioProgram = "{\"programID\":1,\"taskInfo\":{\"playPolicy\":\"ORDER\",\"audioList\":[{\"id\":1,\"mid\":2,\"name\":\"music1.mp3\",\"dataSource\":\"1b530defddb77e902dce1ee41cb55738.mp3\",\"originalDataSource\":\"/home/Media/1b530defddb77e902dce1ee41cb55738.mp3\",\"duration\":15868,\"enable\":true},{\"id\":2,\"mid\":2,\"name\":\"music2.mp3\",\"dataSource\":\"46d9566e0d76e30d7ae8cc1b556a84d7.mp3\",\"originalDataSource\":\"C:\\\\Media\\\\46d9566e0d76e30d7ae8cc1b556a84d7.mp3\",\"duration\":44568,\"enable\":true}]}}";
QString strSetAudioMedioProgram = "{\"programID\":1,\"taskInfo\":[{\"audioFileName\":\"audioList1.json\",\"data\":{\"audioList\":[{\"enable\":true,\"originalDataSource\":\"F:/test/test111.mp3\"},{\"enable\":true,\"originalDataSource\":\"F:/test/test222.mp3\"}],\"playPolicy\":\"ORDER\"}},{\"audioFileName\":\"audioList2.json\",\"data\":{\"audioList\":[{\"enable\":true,\"originalDataSource\":\"F:/test/test333.mp3\"}],\"playPolicy\":\"ORDER\"}}]}";
QString setPublicnetConfig = "{\"sn\":\"123456\",\"data\":{\"host\":\"192.168.1.1\",\"port\":80,\"timeout\":10000,\"isEncrypt\":true}}";
DemoChildGUI::DemoChildGUI(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    //窗口置顶
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(soltsGetInfo()));
    connect(ui.comboBox_APIModule, SIGNAL(currentIndexChanged(int)), this, SLOT(slotsChangeAPI(int)));
    connect(ui.comboBox_APIName, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotsSetRequestData(QString)));
    //下拉框高度
    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();
    ui.comboBox_APIModule->setItemDelegate(itemDelegate);
    ui.comboBox_APIName->setItemDelegate(itemDelegate);
    ui.comboBox_APIModule->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 25px;}");
    ui.comboBox_APIName->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 25px;}");

    initAPIModule();
    initAPI();

}

void DemoChildGUI::initTestCase()
{
    //getIcareConfigInfoData;
    //setIcareConfigInfoData;
    //getBindPlayerData;
    //setBindPlayerData;
    //getNodeServerListData;
}

void DemoChildGUI::setCallback(std::function<void(const std::string &APIname, const std::string &requestData)> callback)
{
    m_callback = callback;
}

void DemoChildGUI::initAPIModule()
{
    QStringList strList;
    strList << "ALL(所有接口)"
            << "诊断模块(Diagnosis)"
            << "多功能卡电源管理（PowerManager）"
            << "音量调节（VolumeController）"
            << "VPN连接管理（VPNConnection）"
            << "APP管理（AppManager）"
            << "播放日志（PlayLogger）"
            << "字体（PlayFont）"
            << "生产功能测试"
            << "多屏拼接（LEDSplicer）"
            << "日志管理（RunningLogger）"
            << "一键自检（SelfInspection）"
            << "IP音频（IPAudio）"
            << "定点投放（FixedPointDelivery）"
            << "紧急插播（EmergencyIntercut）"
            << "传感器子板（Sensor）"
            << "外投调节（ExternalDelivery）"
            << "射频管理（RadioFrequency）"
            << "终端电源控制（PowerController）"
            << "视频源控制（VideoSourceController）"
            << "显示屏用户信息（UserManager）"
            << "搜索连接登录（Login）"
            << "显示屏亮度&环境亮度（LightController）"
            << "温度&色温（TemperatureController）"
            << "开关屏管理（SwitchController）"
            << "系统文件管理（FileManager）"
            << "清单管理（ListManager）"
            << "高级特性（AdvancedFeatures）"
            << "采集器接收器（AcquisitionReceiver）"
            << "U盘相关协议（USBVPlay）"
            << "升级（UpgradeManager）"
            << "网络配置（NetworkConfigurator）"
            << "配屏（ScreenConfiguration）"
            << "icare配置（ICareConfigurator）"
            << "终端cloud配置（CloudConfigurator）"
            << "监控（MonitorConfigurator）"
            << "屏体其他项（ScreenManager）"
            << "其他/节目编辑（ProgramEditor）"
            << "其他/对时服务器列表(VerfityTime)"
            << "其他/节点服务器列表（NodeServerList）"
            << "其他/用户反馈(Feedback）"
            << "其他/数据迁移(DatabaseMigration)"
            << "其他/ViplexCore帮助（ViplexCoreAssist）"
            << "其他/绑定优化（BindingManager）"
            << "其他/获取时区列表（TimeZoneList）"
            << "批量小工具"
            <<"终端日志上传"
            << "公网配置";

    ui.comboBox_APIModule->addItems(strList);
}

void DemoChildGUI::initAPI()
{
    initDiagnosisAPI();
    initPowerManagerAPI();
    initVolumeControllerAPI();
    initVPNConnectionAPI();
    initAppManagerAPI();
    initPlayLoggerAPI();
    initPlayFontAPI();
    initCreatFunctionTestAPI();
    initLEDSplicerAPI();
    initRunningLoggerAPI();
    initSelfInspectionAPI();
    initIPAudioAPI();
    initFixedPointDeliveryAPI();
    initEmergencyIntercutAPI();
    initSensorAPI();
    initExternalDeliveryAPI();
    initRadioFrequencyAPI();
    initPowerControllerAPI();
    initVideoSourceControllerAPI();
    initUserManagerAPI();
    initLoginAPI();
    initLightControllerAPI();
    initTemperatureControllerAPI();
    initSwitchControllerAPI();
    initFileManagerAPI();
    initListManagerAPI();
    initAdvancedFeaturesAPI();
    initAcquisitionReceiverAPI();
    initUSBVPlayAPI();
    initNetworkConfiguratorAPI();
    initScreenConfigurationAPI();
    initICareConfiguratorAPI();
    initCloudConfiguratorAPI();
    initMonitorConfiguratorAPI();
    initScreenManagerAPI();
    initUpgradeManagerAPI();
    initProgramEditorAPI();
    initVerfityTimeAPI();
    initNodeServerListAPI();
    initFeedbackAPI();
    initDatabaseMigrationAPI();
    initViplexCoreAssistAPI();
    initBindingManagerAPI();
    initTimeZoneListAPI();
    initBatchSetAPI();
    initLogUpload();
    initPublibNetConfigAPI();
    initGetOnlineDevicesAPI();
}

void DemoChildGUI::initDiagnosisAPI()
{
    QStringList strList;
    strList << "待开发";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initPowerManagerAPI()
{
    QStringList strList;
    strList << "setTimingPowerSwitchStatus()"<<"getTimingPowerSwitchStatus()"<<"getRealtimePowerSwitchStatus()";
    strList << "getManualPowerSwitchStatus()" << "setManualPowerSwitchStatus()" << "logOut()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initVolumeControllerAPI()
{
    QStringList strList;
    strList << "getVolume()" << "setVolume()"<<"setTimingVolume()"<<"getTimingVolume()"<<"getVolumeFor0x99()"<<"setVolumeFor0x99()"<<"setTimingVolumeFor0x99()"<<"getTimingVolumeFor0x99()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initVPNConnectionAPI()
{
    QStringList strList;
    strList << "setVPNConnectInfo()"<<"getVPNConnectInfo()"<<"VPNManagerFor0x99()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initAppManagerAPI()
{
    QStringList strList;
    strList << "AMGetInstalledPackageInfo()"
            << "GetRunningPackageInfo()"
            << "ForceStopApp()"
            << "UninstallPackage()"
            << "StartUploadApk()"

            << "runApp()"
            << "getThirdPackageinfos()"
            << "getTerminalService()"
            << "startService()"
            << "stopService()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initPlayLoggerAPI()
{
    QStringList strList;
    strList << "getPlaylogPath()"<<"ping()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initPlayFontAPI()
{
    QStringList strList;
    strList << "getPlayFontUploadPath()"<<"getTerminalFont()"<<"deleteFont()"<<"updateFont()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initCreatFunctionTestAPI()
{
    QStringList strList;
    strList << "待开发";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initLEDSplicerAPI()
{	
    QStringList strList;
    strList << "GetSpliceInfo()" << "SetSpliceInfo()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initRunningLoggerAPI()
{
    QStringList strList;
    strList << "getLogPath()"<<"getRunningLogPath()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initSelfInspectionAPI()
{
    QStringList strList;
    strList << "待开发";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initIPAudioAPI()
{
    QStringList strList;
    strList << "setAudioPlayRealTime()"<<"setAudioPlayPolicy()"<<"getAudioPlayPolicy()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initFixedPointDeliveryAPI()
{
    QStringList strList;
    strList << "待开发";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initEmergencyIntercutAPI()
{
    QStringList strList;
    strList << "待开发";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initSensorAPI()
{
    QStringList strList;
    strList << "getSupportSensorInfo()" << "setSupportSensorInfo()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initExternalDeliveryAPI()
{
    QStringList strList;
    strList << "setInfraRedConfig()"<<"getInfraRedConfig()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initRadioFrequencyAPI()
{
    QStringList strList;
    strList << "getLoraInfo()" << "setManalLightSync()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initPowerControllerAPI()
{
    QStringList strList;
    strList << "setManualSolidPower()"<<"getSolidPowerStatus()"<<"setPowerInfoManual()"<<"setPowerInfoPolicy()"<<"getPowerInfoPolicy()"<<"getPowerInfoStatus()"<<"setPowerMode()"<<"getPowerMode()" << "setTimingSolidPower()" << "getTimingSolidPower()"<<"setSolidPowerStatus()"<<"isExistSolidPower()"<<"setRelayPowerManual()"
            <<"setRelayPowerPolicy()"<<"getRelayPowerPolicy()"<<"getRelayPowerStatus()"<<"setRelayPowerStatus()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initVideoSourceControllerAPI()
{
    QStringList strList;
    strList << "getVideoControlInfo()" << "setVideoControlInfo()"<<"setVideoEDID()"<<"getVideoEDID()" << "getVideoSourceManualFor0x99()" << "getVideoSourcePolicyFor0x99()" << "setVideoSourceManualFor0x99()" << "setVideoSourcePolicyFor0x99()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initUserManagerAPI()
{

    QStringList strList;
    strList << "setUserInfo()" << "getUserInfo()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initLoginAPI()
{
    QStringList strList;
    strList << "getconfiguration()" << "getFirmwareInfos()" << "getInstalledPackageVersions()" << "getProductInfo()" << "setTerminalInfo()" << "delTerminalInfo()"<<"loginVnnox()"<<"getVerifyCode()"<<"registerVnnox()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initLightControllerAPI()
{
    QStringList strList;
    strList << "setBrightnessAdjustMode()" << "getBrightnessAdjustMode()" << "setScreenBrightness()" << "getScreenBrightness()" << "setBrightnessPolicy()" << "getBrightnessPolicy()"<< "getEnvironmentBrightness()" << "setManualBrightnessFor0x99()" << "getManualBrightnessFor0x99()" << "setPolicyBrightnessFor0x99()"<< "getPolicyBrightnessFor0x99()"<< "getEnvironmentBrightnessParameter()"<< "setEnvironmentBrightnessParameter()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initTemperatureControllerAPI()
{
    QStringList strList;
    strList << "getColorTemperature()" << "setColorTemperature()" << "getScreenUnitTemp()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initSwitchControllerAPI()
{
    QStringList strList;
    strList << "setScreenPowerAdjustMode()" << "getScreenPowerAdjustMode()"<<"setScreenPowerState()" << "getScreenPowerState()" << "setScreenPowerPolicy()" << "getScreenPowerPolicy()" << "setScreenPowerManual0x99()" << "setScreenPowerPolicy0x99()" << "getScreenPowerManual0x99()" << "GetScreenPowerPolicyFor0x99()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initFileManagerAPI()
{
    QStringList strList;
    strList << "getFileMD5()"<<"isFileExisted()"<<"deleteFile()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initListManagerAPI()
{
    QStringList strList;
    strList << "getProgramInfo()" << "deletePlayList()" << "startPlay()" << "startPlay1()" << "pausePlay()" << "resumePlay()"<<"stopPlay()"<<"playListTransferError()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initAdvancedFeaturesAPI()
{
    QStringList strList;
    strList << "setSyncPlay()" << "getSyncPlay()"
            << "setReBootWipeUserData()" << "clearAllMedias()" << "getOTGUSBMode()"
            << "setOTGUSBMode()" << "setCurrentResolutio()"
            << "getCurrentResolution()" << "getSupportedResolution()"<<"GetReBootTask()" << "SetReBootTask()"
            << "getHdmiOutputStatus()" << "setHdmiOutputStatus()"<< "setCustomResolution()"
            <<"setImmediatelyReboot()"<<"clearAllMediasFor0x99()"<<"setSyncPlayFor0x99()"
           <<"getPolicySourceOutMode()"<<"setPolicySourceOutMode()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initAcquisitionReceiverAPI()
{
    QStringList strList;
    strList << "getPickerReceiver()" << "addCollector()" << "deleteCollector()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initUSBVPlayAPI()
{
    QStringList strList;
    strList << "getUSBAuthentic()"<<"setUSBAuthentic()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initUpgradeManagerAPI()
{
    QStringList strList;
    strList << "updateApp()" << "updateOS()" << "updateAppVerify()"<<"stopCurrentUpdateTask()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initProgramEditorAPI()
{
    QStringList strList;
    strList << "createProgram()" << "makeProgram()" << "addPage()" << "setPageParam()(图片)" << "setPageParam()(图片、视频、GIF简化)" << "setPageParam()(数字时钟简化)" << "setPageParam()(文本简化)"
            << "setPageParam()(RSS)" << "setPageParam()(RSS简化)" << "setPageParam()(炫彩字)" << "setPageParam()(炫彩字简化)" <<"setPageParam()(环境监测)" << "setPageParam()(环境监测简化)" <<"setPageParam()(计时器)" << "setPageParam()(计时器简化)" <<"setPageParam()(网页)"<<"setPageParam()(流媒体)"
            << "getPageParam()" << "deletePage()" << "addWidget()"
            << "setWidgetParam()" << "getWidgetParam()" << "deleteWidget()"
            << "addTpl()" << "editTpl()" << "deleteTpl()" << "setSystemTplInfo()" << "getCustomerTpl()" << "getProgram()" << "deleteProgram()"
            << "startTransferProgram()" << "startTransferProgram1()" << "stopProgramTransfer()"<<"setPageParams()"
            << "setAudioMedioProgram()"
            <<"transferProgram()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initVerfityTimeAPI()
{
    QStringList strList;
    strList << "getNetTimingListInfo()" << "addNetTimingInfo()" << "deleteNetTimingInfo()" << "updateNetTimingInfo()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initNodeServerListAPI()
{
    QStringList remotemanagerList;
    remotemanagerList  << "getCloudPlayerList()" << "getNodeServerList()" << "addNodeServerList()" << "deleteNodeServerList()" << "changeNodeServerList()";
    ui.comboBox_APIName->addItems(remotemanagerList);
}

void DemoChildGUI::initFeedbackAPI()
{
    QStringList strList;
    strList << "uploadFeedbackInfo()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initDatabaseMigrationAPI()
{
    QStringList strList;
    strList << "dataBaseMigration()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initViplexCoreAssistAPI()
{
    QStringList strList;
    strList  << "downLoadFiles()" << "queryFileByType()"<<"getScreenDeviceInfo()"<<"rsaEncode()"<<"rsaDecode()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initBindingManagerAPI()
{
    QStringList strList;
    strList << "待开发initBindingManagerAPI";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initTimeZoneListAPI()
{
    QStringList strList;
    strList << "待开发initTimeZoneListAPI";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initBatchSetAPI()
{
    QStringList strList;
    strList << "batchLogin()"<<"batchSetRecvCardFile()"<<"batchSetScreenAttribute()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initLogUpload()
{
    QStringList strList;
    strList << "downloadTerminalLog()" << "uploadTerminalLog()" << "cancelFunction()" << "checkNetwork()" << "downloadTerminalAllLog()" << "downloadTerminalPlayLog()" << "downloadTerminalPlayLogNet()" << "downloadTerminalLogNet()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initPublibNetConfigAPI()
{
    QStringList strList;
    strList << "initPublicNet()" << "stopPublicNet()" << "setPublicNetConfigParam()" << "disconnectPublicNet()" << "getPublicNetParam()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initNetworkConfiguratorAPI()
{
    QStringList strList;
    strList << "getWifiList()" << "connectWifiNetwork()" << "getWifiCurrentStatus()"
            << "disconnectWifiNetwork()" << "getWifiEnabled()" << "setWifiEnabled()"
            << "sendForgetWifiCommand()" << "getMobileNetwork()" << "setMobileNetwork()"
            << "isMobileModuleExisted()" << "getEthernetInfo()" << "setEthernetInfo()"
            << "getAPNetwork()" << "setAPNetwork()" << "getAPNInfo()" << "setAPNInfo()" << "setFlightMode()" << "getFlightMode()" << "get4GNetworkStatus()"
            << "getAPNetworkOpenStatus()" << "setAPNetworkOpenStatus()"
            << "getNetworkCheck()" << "setWifiApStationSwitch()" << "getModuleInfo()"<<"setNetworkCheck()";

    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initScreenConfigurationAPI()
{
    QStringList strList;
    strList << "SetRecvCardFile()" << "getScreenAttribute()" << "setScreenAttribute()"<< "setScreenAttributeSDK()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initICareConfiguratorAPI()
{	
    QStringList strList;
    strList << "getIcareConfigInfo()" << "setIcareConfigInfo()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initCloudConfiguratorAPI()
{	
    QStringList strList;
    strList << "getBindPlayer()" << "setBindPlayer()" << "getCloudPlayerList()"<<"getPlayerIdentifer()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initMonitorConfiguratorAPI()
{
    QStringList strList;
    strList << "getAvailableStorageData()" << "getCPUUsage()"<< "getCPUTemp()"<< "getAvailableMemory()"<<"getSendCardMonitorInfo()"<<"getReceiverCountAndInfo()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initScreenManagerAPI()
{
    QStringList strList;
    strList << "getCurrentTimeAndZone()" << "calibrateTime()" << "getNetTimingInfo()"
            << "setNetTimingInfo()" << "getNetTimingListInfo()" << "addNetTimingInfo()"
            << "deleteNetTimingInfo()" << "updateNetTimingInfo()" << "downloadScreenShot()" << "downloadScreenShotNet()"
            << "getIsUseDayLightTime()"<< "getSendCardMonitorInfo()" << "getReceiverCountAndInfo()"
            << "getMonitorInfoByReceiverIndex()" << "setRotation()" << "getRotation()" << "getDisplayInfo()" << "setTimeAndZone()";
    ui.comboBox_APIName->addItems(strList);
}

void DemoChildGUI::initGetOnlineDevicesAPI()
{
    QStringList strList;
    strList << "getOnlineDevicesAsync()";
    ui.comboBox_APIName->addItems(strList);
}


void DemoChildGUI::soltsGetInfo()
{
    QString strAPIname = ui.comboBox_APIName->currentText();
    QString strJson = ui.textEdit_2->toPlainText();
    m_callback(strAPIname.toStdString(), strJson.toStdString());
}

void DemoChildGUI::soltsGetSN(QString sn)
{
    ui.lineEdit->setText(sn);
}

void DemoChildGUI::soltGetResponseData(int errorcode, QString result)
{
    ui.textEdit->clear();
    ui.textEdit->setText(QString::number(errorcode));
    ui.textEdit->append(result);
}

void DemoChildGUI::slotsChangeAPI(int index)
{
    switch (index)
    {
    case 0:
        ui.comboBox_APIName->clear();
        initAPI();
        break;
    case 1:
        ui.comboBox_APIName->clear();
        initDiagnosisAPI();
        break;
    case 2:
        ui.comboBox_APIName->clear();
        initPowerManagerAPI();
        break;
    case 3:
        ui.comboBox_APIName->clear();
        initVolumeControllerAPI();
        break;
    case 4:
        ui.comboBox_APIName->clear();
        initVPNConnectionAPI();
        break;
    case 5:
        ui.comboBox_APIName->clear();
        initAppManagerAPI();
        break;
    case 6:
        ui.comboBox_APIName->clear();
        initPlayLoggerAPI();
        break;
    case 7:
        ui.comboBox_APIName->clear();
        initPlayFontAPI();
        break;
    case 8:
        ui.comboBox_APIName->clear();
        initCreatFunctionTestAPI();
        break;
    case 9:
        ui.comboBox_APIName->clear();
        initLEDSplicerAPI();
        break;
    case 10:
        ui.comboBox_APIName->clear();
        initRunningLoggerAPI();
        break;
    case 11:
        ui.comboBox_APIName->clear();
        initSelfInspectionAPI();
        break;
    case 12:
        ui.comboBox_APIName->clear();
        initIPAudioAPI();
        break;
    case 13:
        ui.comboBox_APIName->clear();
        initFixedPointDeliveryAPI();
        break;
    case 14:
        ui.comboBox_APIName->clear();
        initEmergencyIntercutAPI();
        break;
    case 15:
        ui.comboBox_APIName->clear();
        initSensorAPI();
        break;
    case 16:
        ui.comboBox_APIName->clear();
        initExternalDeliveryAPI();
        break;
    case 17:
        ui.comboBox_APIName->clear();
        initRadioFrequencyAPI();
        break;
    case 18:
        ui.comboBox_APIName->clear();
        initPowerControllerAPI();
        break;
    case 19:
        ui.comboBox_APIName->clear();
        initVideoSourceControllerAPI();
        break;
    case 20:
        ui.comboBox_APIName->clear();
        initUserManagerAPI();
        break;
    case 21:
        ui.comboBox_APIName->clear();
        initLoginAPI();
        break;
    case 22:
        ui.comboBox_APIName->clear();
        initLightControllerAPI();
        break;
    case 23:
        ui.comboBox_APIName->clear();
        initTemperatureControllerAPI();
        break;
    case 24:
        ui.comboBox_APIName->clear();
        initSwitchControllerAPI();
        break;
    case 25:
        ui.comboBox_APIName->clear();
        initFileManagerAPI();
        break;
    case 26:
        ui.comboBox_APIName->clear();
        initListManagerAPI();
        break;
    case 27:
        ui.comboBox_APIName->clear();
        initAdvancedFeaturesAPI();
        break;
    case 28:
        ui.comboBox_APIName->clear();
        initAcquisitionReceiverAPI();
        break;
    case 29:
        ui.comboBox_APIName->clear();
        initUSBVPlayAPI();
        break;
    case 30:
        ui.comboBox_APIName->clear();
        initUpgradeManagerAPI();
        break;
    case 31:
        ui.comboBox_APIName->clear();
        initNetworkConfiguratorAPI();
        break;
    case 32:
        ui.comboBox_APIName->clear();
        initScreenConfigurationAPI();
        break;
    case 33:
        ui.comboBox_APIName->clear();
        initICareConfiguratorAPI();
        break;
    case 34:
        ui.comboBox_APIName->clear();
        initCloudConfiguratorAPI();
        break;
    case 35:
        ui.comboBox_APIName->clear();
        initMonitorConfiguratorAPI();
        break;
    case 36:
        ui.comboBox_APIName->clear();
        initScreenManagerAPI();
        break;
    case 37:
        ui.comboBox_APIName->clear();
        initProgramEditorAPI();
        break;
    case 38:
        ui.comboBox_APIName->clear();
        initVerfityTimeAPI();
        break;
    case 39:
        ui.comboBox_APIName->clear();
        initNodeServerListAPI();
        break;
    case 40:
        ui.comboBox_APIName->clear();
        initFeedbackAPI();
        break;
    case 41:
        ui.comboBox_APIName->clear();
        initDatabaseMigrationAPI();
        break;
    case 42:
        ui.comboBox_APIName->clear();
        initViplexCoreAssistAPI();
        break;
    case 43:
        ui.comboBox_APIName->clear();
        initBindingManagerAPI();
        break;
    case 44:
        ui.comboBox_APIName->clear();
        initTimeZoneListAPI();
        break;
    case 45:
        ui.comboBox_APIName->clear();
        initBatchSetAPI();
        break;
    case 46:
        ui.comboBox_APIName->clear();
        initLogUpload();
        break;
    case 47:
        ui.comboBox_APIName->clear();
        initPublibNetConfigAPI();
        break;
    case 48:
        ui.comboBox_APIName->clear();
        initGetOnlineDevicesAPI();
        break;
    default:
        break;
    }
}

void DemoChildGUI::slotsSetRequestData(QString str)
{
    ui.textEdit->clear();
    if ("getIcareConfigInfo()" == str)
    {
        ui.textEdit_2->setText(getIcareConfigInfoData);
    }
    else if ("setIcareConfigInfo()" == str)
    {
        ui.textEdit_2->setText(setIcareConfigInfoData);
    }
    else if ("getBindPlayer()" == str)
    {
        ui.textEdit_2->setText(getBindPlayerData);
    }
    else if ("setBindPlayer()" == str)
    {
        ui.textEdit_2->setText(setBindPlayerData);
    }
    else if ("getCloudPlayerList()" == str)
    {
        ui.textEdit_2->setText(getCloudPlayerListData);
    }
    else if ("getNodeServerList()" == str)
    {
        ui.textEdit_2->setText(getNodeServerListData);
    }
    else if ("addNodeServerList()" == str)
    {
        ui.textEdit_2->setText(addNodeServerListData);
    }
    else if ("changeNodeServerList()" == str)
    {
        ui.textEdit_2->setText(changeNodeServerlistData);
    }
    else if ("deleteNodeServerList()" == str)
    {
        ui.textEdit_2->setText(deleteNodeServerListData);
    }
    else if ("setNetTimingInfo()" == str)
    {
        ui.textEdit_2->setText(setNetTimingInfoData);
    }

    else if ("getNetTimingInfo()" == str)
    {
        ui.textEdit_2->setText(getNetTimingInfoData);
    }
    else if ("getIsUseDayLightTime()" == str)
    {
        ui.textEdit_2->setText(getIsUseDayLightTimeStr);
    }
    else if ("addNetTimingInfo()" == str)
    {
        ui.textEdit_2->setText(addNetTimingInfoData);
    }
    else if ("updateNetTimingInfo()" == str)
    {
        ui.textEdit_2->setText(updateNetTimingInfoData);
    }
    else if ("deleteNetTimingInfo()" == str)
    {
        ui.textEdit_2->setText(deleteNetTimingInfoData);
    }
    else if ("getNetTimingListInfo()" == str)
    {
        ui.textEdit_2->setText(getNetTimingListInfoData);
    }
    else if ("setVolume()" == str)
    {
        ui.textEdit_2->setText(setVolumeData);
    }
    else if ("getVolume()" == str)
    {
        ui.textEdit_2->setText(getVolumeData);
    }
    else if ("calibrateTime()" == str)
    {
        ui.textEdit_2->setText(calibrateTimeData);
    }
    else if ("getCurrentTimeAndZone()" == str)
    {
        ui.textEdit_2->setText(getCurrentTimeAndZoneData);
    }
    else if ("setColorTemperature()" == str)
    {
        ui.textEdit_2->setText(setColorTemperatureData);
    }
    else if ("getColorTemperature()" == str)
    {
        ui.textEdit_2->setText(getColorTemperatureData);
    }
    else if ("setBrightnessAdjustMode()" == str)
    {
        ui.textEdit_2->setText(setBrightnessAdjustModeData);
    }
    else if ("getBrightnessAdjustMode()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setScreenBrightness()" == str)
    {
        ui.textEdit_2->setText(setScreenBrightnessData);
    }
    else if ("getScreenBrightness()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getBrightnessPolicy()" == str)
    {
        ui.textEdit_2->setText(getBrightnessPolicyData);
    }
    else if ("setBrightnessPolicy()" == str)
    {
        ui.textEdit_2->setText(setBrightnessPolicyData);
    }
    else if ("setManualBrightnessFor0x99()" == str)
    {
        ui.textEdit_2->setText(setManualBrightnessFor0x99Data);
    }
    else if ("getManualBrightnessFor0x99()" == str)
    {
        ui.textEdit_2->setText(getManualBrightnessFor0x99Data);
    }
    else if ("setPolicyBrightnessFor0x99()" == str)
    {
        ui.textEdit_2->setText(setPolicyBrightnessFor0x99Data);
    }
    else if ("getPolicyBrightnessFor0x99()" == str)
    {
        ui.textEdit_2->setText(getPolicyBrightnessFor0x99Data);
    }
    else if ("setScreenPowerAdjustMode()" == str)
    {
        ui.textEdit_2->setText(setScreenPowerAdjustModeData);
    }
    else if ("getScreenPowerAdjustMode()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setScreenPowerState()" == str)
    {
        ui.textEdit_2->setText(setScreenPowerData);
    }
    else if ("getScreenPowerState()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setScreenPowerPolicy()" == str)
    {
        ui.textEdit_2->setText(setScreenPowerPolicyData);
    }
    else if ("getScreenPowerPolicy()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setScreenPowerManual0x99()" == str)
    {
        ui.textEdit_2->setText(setScreenPowerManual0x99Data);
    }
    else if ("setScreenPowerPolicy0x99()" == str)
    {
        ui.textEdit_2->setText(setScreenPowerPolicy0x99Data);
    }
    else if ("getScreenPowerManual0x99()" == str)
    {
        ui.textEdit_2->setText(getScreenPowerManual0x99Data);
    }
    else if ("GetScreenPowerPolicyFor0x99()" == str)
    {
        ui.textEdit_2->setText(GetScreenPowerPolicyFor0x99Data);
    }

    else if ("getEnvironmentBrightness()" == str)
    {
        ui.textEdit_2->setText(snBZSA07194A0049999716);
    }
    else if ("getScreenUnitTemp()" == str)
    {
        ui.textEdit_2->setText(snBZSA07194A0049999716);
    }
    
    if ("getAvailableStorageData()" == str)
    {
        ui.textEdit_2->setText(snBZVA28407N3X20008006);
    }
    else if ("getCPUUsage()" == str)
    {
        ui.textEdit_2->setText(snBZVA28407N3X20008006);
    }
    else if ("getCPUTemp()" == str)
    {
        ui.textEdit_2->setText(snBZVA28407N3X20008006);
    }
    else if ("getAvailableMemory()" == str)
    {
        ui.textEdit_2->setText(snBZVA28407N3X20008006);
    }
    else if ("getScreenAttribute()" == str)
    {
        ui.textEdit_2->setText(snBZSA07194A0049999716);
    }
    else if ("setScreenAttribute()" == str)
    {
        ui.textEdit_2->setText(setsetScreenAttribute);
    }
    else if ("getconfiguration()" == str)
    {
        ui.textEdit_2->setText("getconfiguration data");
    }
    else if ("getFirmwareInfos()" == str)
    {
        ui.textEdit_2->setText(snVPlayerW9A5HAJW);
    }
    else if ("getInstalledPackageVersions()" == str)
    {
        ui.textEdit_2->setText("getInstalledPackageVersions data");
    }
    else if ("getProductInfo()" == str)
    {
        ui.textEdit_2->setText("getProductInfo data");
    }
    else if ("setSyncPlay()" == str)
    {
        ui.textEdit_2->setText(setSyncPlayInfo);
    }
    else if ("getSyncPlay()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("reboot()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setReBootWipeUserData()" == str)
    {
        ui.textEdit_2->setText(reBootWipeUserData);
    }
    else if ("clearAllMedias()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getOTGUSBMode()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setOTGUSBMode()" == str)
    {
        ui.textEdit_2->setText(setOTGUSBModeData);
    }
    else if ("setCurrentResolutio()" == str)
    {
        ui.textEdit_2->setText(setCurrentResolutionData);
    }
    else if ("getCurrentResolution()" == str)
    {
        ui.textEdit_2->setText(getCurrentResolutionData);
    }
    else if ("getSupportedResolution()" == str)
    {
        ui.textEdit_2->setText(getCurrentResolutionData);
    }
    else if ("getInstalledPackageInfo()" == str)
    {
        ui.textEdit_2->setText(getInstalledPackageInfoData);
    }
    else if ("高级功能getProductInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getAPNetwork()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setAPNetwork()" == str)
    {
        ui.textEdit_2->setText(setAPNetworkInfo);
    }
    else if ("getVideoControlInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setVideoControlInfo()" == str)
    {
        ui.textEdit_2->setText(setVideoControlInfoStr);
    }
    else if ("downloadScreenShot()" == str)
    {
        ui.textEdit_2->setText(downloadScreenShotStr);
    }
    else if ("downloadScreenShotNet()" == str)
    {
    ui.textEdit_2->setText(downloadScreenShotNetStr);
    }
    else if ("startGetAvailableMemoryData()" == str)
    {
        ui.textEdit_2->setText(startGetAvailableMemoryData);
    }
    else if ("finishData()" == str)
    {
        ui.textEdit_2->setText(finishData);
    }
    else if ("getWifiList()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("connectWifiNetwork()" == str)
    {
        ui.textEdit_2->setText(connectWifiNetworkData);
    }
    else if ("getWifiCurrentStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("disconnectWifiNetwork()" == str)
    {
        ui.textEdit_2->setText(disconnectWifiNetworkData);
    }
    else if ("getWifiEnabled()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setWifiEnabled()" == str)
    {
        ui.textEdit_2->setText(setWifiEnabledData);
    }
    else if ("sendForgetWifiCommand()" == str)
    {
        ui.textEdit_2->setText(sendForgetWifiCommandData);
    }
    else if ("getMobileNetwork()" == str)
    {
        ui.textEdit_2->setText(getMobileNetworkData);
    }
    else if ("setMobileNetwork()" == str)
    {
        ui.textEdit_2->setText(setMobileNetworkData);
    }
    else if ("isMobileModuleExisted()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getEthernetInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setEthernetInfo()" == str)
    {
        ui.textEdit_2->setText(setEthernetInfoData);
    }
    else if ("AMGetInstalledPackageInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("GetRunningPackageInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("ForceStopApp()" == str)
    {
        ui.textEdit_2->setText(forceStopAppStr);
    }
    else if ("UninstallPackage()" == str)
    {
        ui.textEdit_2->setText(UninstallPackageStr);
    }
    else if ("StartUploadApk()" == str)
    {
        ui.textEdit_2->setText(finishData);
    }
    else if ("runApp()" == str)
    {
        ui.textEdit_2->setText(runAPPStr);
    }
    else if ("queryUpdateFileByType()" == str)
    {
        ui.textEdit_2->setText(queryUpdateFile);
    }
    else if ("readFileContentFromZipFile()" == str)
    {
        ui.textEdit_2->setText(readJsonFormZipFile);
    }
    else if ("updateApp()" == str)
    {
        ui.textEdit_2->setText(startUpdateApp);
    }
    else if ("updateOS()" == str)
    {
        ui.textEdit_2->setText(startUpdateOS);
    }
    else if ("stopCurrentUpdateTask()" == str)
    {
        ui.textEdit_2->setText(snBZSA07194A0049999716);
    }
    else if ("updateAppVerify()" == str)
    {
        ui.textEdit_2->setText(updateVerify);
    }
    else if ("updateOSVerify()" == str)
    {
        ui.textEdit_2->setText(startUpdateOS);
    }
    else if ("addPage()" == str)
    {
        ui.textEdit_2->setText(addPageStr);
    }
    else if ("setPageParam()(图片)" == str)
    {
        ui.textEdit_2->setText(setPageParamStr);
    }
    else if ("setPageParam()(RSS)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrRSS);
    }
    else if ("setPageParam()(炫彩字)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrColorFul);
    }
    else if ("setPageParam()(环境监测)" == str)
    {
        ui.textEdit_2->setText(setPageParamStRt);
    }
    else if ("setPageParam()(计时器)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrTimer);
    }
    else if ("setPageParam()(RSS简化)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrRSSSimple);
    }
    else if ("setPageParam()(炫彩字简化)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrColorFulSimple);
    }
    else if ("setPageParam()(环境监测简化)" == str)
    {
        ui.textEdit_2->setText(setPageParamStRtSimple);
    }
    else if ("setPageParam()(计时器简化)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrTimerSimple);
    }
    else if ("setPageParam()(网页)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrHtml);
    }
    else if ("setPageParam()(流媒体)" == str)
    {
        ui.textEdit_2->setText(setPageParamStrStream);
    }
    else if ("getPageParam()" == str)
    {
        ui.textEdit_2->setText(getPageParamStr);
    }
    else if ("deletePage()" == str)
    {
        ui.textEdit_2->setText(deletePageStr);
    }
    else if ("addWidget()" == str)
    {
        ui.textEdit_2->setText(addWidgetStr);
    }
    else if ("setWidgetParam()" == str)
    {
        ui.textEdit_2->setText(setWidgetParamStr);
    }
    else if ("getWidgetParam()" == str)
    {
        ui.textEdit_2->setText(getWidgetParamStr);
    }
    else if ("deleteWidget()" == str)
    {
        ui.textEdit_2->setText(deleteWidgetStr);
    }
    else if ("createProgram()" == str)
    {
        ui.textEdit_2->setText(createProgram);
    }
    else if ("makeProgram()" == str)
    {
        ui.textEdit_2->setText(makeProgram);
    }
    else if ("addTpl()" == str)
    {
        ui.textEdit_2->setText(addTpl);
    }
    else if ("editTpl()" == str)
    {
        ui.textEdit_2->setText(editTpl);
    }
    else if ("deleteTpl()" == str)
    {
        ui.textEdit_2->setText(deleteTpl);
    }
    else if ("setSystemTplInfo()" == str)
    {
        ui.textEdit_2->setText(systemTpl);
    }
    else if ("getProgram()" == str)
    {
        ui.textEdit_2->setText(getProgram);
    }
    else if ("deleteProgram()" == str)
    {
        ui.textEdit_2->setText(deleteProgram);
    }
    else if ("startTransferProgram()" == str)
    {
        ui.textEdit_2->setText(startTransferProgram);
    }
    else if ("startTransferProgram1()" == str)
    {
        ui.textEdit_2->setText(startTransferProgram1);
    }
    else if ("stopProgramTransfer()" == str)
    {
        ui.textEdit_2->setText(stopProgramTransfer);
    }
    else if ("setPageParams()" == str)
    {
        ui.textEdit_2->setText(strSetPageParams);
    }
    else if ("setTerminalInfo()" == str)
    {
        ui.textEdit_2->setText(setTerminalInfo);
    }
    else if ("delTerminalInfo()" == str)
    {
        ui.textEdit_2->setText(delTerminalInfo);
    }
    else if ("setUserInfo()" == str)
    {
        ui.textEdit_2->setText(setUserInfoStr);
    }
    else if ("getUserInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("dataBaseMigration()" == str)
    {
        ui.textEdit_2->setText(strDataBaseMigration);
    }
    else if ("uploadFeedbackInfo()" == str)
    {
        ui.textEdit_2->setText(strUploadFeedbackInfo);
    }
    else if ("getPlayerIdentifer()" == str)
    {
        ui.textEdit_2->setText(strGetPlayerIdentifer);
    }
    if ("setManualPowerSwitchStatus()" == str)
    {
        ui.textEdit_2->setText(strSetManualPowerSwitchStatus);
    }
    if ("getManualPowerSwitchStatus()" == str)
    {
        ui.textEdit_2->setText(strGetManualPowerSwitchStatus);
    }
	if ("logOut()" == str)
	{
		ui.textEdit_2->setText(strLogOut);
	}
    if ("setTimingPowerSwitchStatus()" == str)
    {
        ui.textEdit_2->setText(strSetTimingPowerSwitchStatus);
    }
    else if ("getTimingPowerSwitchStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getRealtimePowerSwitchStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getAPNInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setAPNInfo()" == str)
    {
        ui.textEdit_2->setText(strSetAPNInfo);
    }
    else if ("setFlightMode()" == str)
    {
        ui.textEdit_2->setText(strSetFightMode);
    }
    else if ("getFlightMode()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("get4GNetworkStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getAPNetworkOpenStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setAPNetworkOpenStatus()" == str)
    {
        ui.textEdit_2->setText(strSetAPNetworkOpenStatus);
    }
    else if ("setWifiApStationSwitch()" == str)
    {
        ui.textEdit_2->setText(strSetWifiApStationSwitch);
    }
    else if ("getModuleInfo()" == str)
    {
        ui.textEdit_2->setText(strgetModuleInfo);
    }

    if ("addCollector()" == str)
    {
        ui.textEdit_2->setText(strAddCollector);
    }
    else if ("deleteCollector()" == str)
    {
        ui.textEdit_2->setText(strDeleteCollector);
    }
    else if ("getSendCardMonitorInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getReceiverCountAndInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getMonitorInfoByReceiverIndex()" == str)
    {
        ui.textEdit_2->setText(strGetMonitorInfoByReceiverIndex);
    }
    else if ("setRotation()" == str)
    {
        ui.textEdit_2->setText(strsetRotation);
    }
    else if ("getRotation()" == str)
    {
        ui.textEdit_2->setText(strgetRotation);
    }
    else if ("getDisplayInfo()" == str)
    {
        ui.textEdit_2->setText(strgetDisplayInfo);
    }
    else if ("setTimeAndZone()" == str)
    {
        ui.textEdit_2->setText(strsetTimeAndZone);
    }
    else if ("setScreenShot()" == str)
    {
        ui.textEdit_2->setText(strsetScreenShot);
    }
    else if ("setVPNConnectInfo()" == str)
    {
        ui.textEdit_2->setText(strSetVPNConnectInfo);
    }
    else if ("getVPNConnectInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getPlaylogPath()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
	else if ("ping" == str) 
	{
		ui.textEdit_2->setText("");
	}
    else if ("getThirdPackageinfos()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    if ("getTerminalService()"== str)
    {
        ui.textEdit_2->setText(sn);
    }
    if ("startService()" == str)
    {
        ui.textEdit_2->setText(strStartService);
    }
    if ("stopService()" == str)
    {
        ui.textEdit_2->setText(strStartService);
    }
    if ("getPlayFontUploadPath()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getTerminalFont()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("deleteFont()" == str)
    {
        ui.textEdit_2->setText(strDeleteFont);
    }
    else if ("updateFont()" == str)
    {
        ui.textEdit_2->setText(strUpdateFont);
    }
    if ("setTimingVolume()" == str)
    {
        ui.textEdit_2->setText(strSetTimingVolume);
    }
    if ("getTimingVolume()" == str)
    {
        ui.textEdit_2->setText(strGetTimingVolume);
    }
    if ("getLogPath()" == str)
    {
        ui.textEdit_2->setText(strGetLogPath);
    }
    if ("getRunningLogPath()" == str)
    {
        ui.textEdit_2->setText(strGetLogPath);
    }
    if ("getPickerReceiver()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    if ("setVideoEDID()" == str)
    {
        ui.textEdit_2->setText(strSetVideoEDID);
    }
    else if ("getVideoEDID()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getVideoSourceManualFor0x99()" == str)
    {
        ui.textEdit_2->setText(snBZVA28407N3X20008006);
    }
    else if ("getVideoSourcePolicyFor0x99()" == str)
    {
        ui.textEdit_2->setText(snBZVA28407N3X20008006);
    }
    else if ("setVideoSourceManualFor0x99()" == str)
    {
        ui.textEdit_2->setText(strsetVideoSourceManualFor0x99);
    }
    else if ("setVideoSourcePolicyFor0x99()" == str)
    {
        ui.textEdit_2->setText(strsetVideoSourcePolicyFor0x99);
    }

    if ("getFileMD5()" == str)
    {
        ui.textEdit_2->setText(strFileManager);
    }
    if ("isFileExisted()" == str)
    {
        ui.textEdit_2->setText(strFileManager);
    }
    if ("deleteFile()" == str)
    {
        ui.textEdit_2->setText(strFileManager);
    }
    if ("getProgramInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("deletePlayList()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("startPlay()" == str)
    {
        ui.textEdit_2->setText(strStartPlay);
    }
    else if ("startPlay1()" == str)
    {
        ui.textEdit_2->setText(strStartPlay1);
    }
    else if ("pausePlay()" == str)
    {
        ui.textEdit_2->setText(strStartPlay);
    }
    else if ("resumePlay()" == str)
    {
        ui.textEdit_2->setText(strStartPlay);
    }
    else if ("stopPlay()" == str)
    {
        ui.textEdit_2->setText(strStartPlay);
    }
    else if ("playListTransferError()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getUSBAuthentic()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setUSBAuthentic()" == str)
    {
        ui.textEdit_2->setText(strUSBAuthentic);
    }

    if ("getLoraInfo()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    if ("setManalLightSync()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getHdmiOutputStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setHdmiOutputStatus()" == str)
    {
        ui.textEdit_2->setText(strTerminalStr);
    }
    else if ("setCustomResolution()" == str)
    {
        ui.textEdit_2->setText(strCustomResolution);
    }
    if ("setAudioPlayRealTime()" == str)
    {
        ui.textEdit_2->setText(strSetAudioPlayRealTime);
    }
    else if ("setAudioPlayPolicy()" == str)
    {
        ui.textEdit_2->setText(strSetAudioPlayPolicy);
    }
    else if ("getAudioPlayPolicy()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    if ("setSupportSensorInfo()" == str)
    {
        ui.textEdit_2->setText(strSetSupportSensorInfo);
    }
    else if ("getSupportSensorInfo()" == str)
    {
        ui.textEdit_2->setText(strGetSupportSensorInfo);
    }
    else if ("VPNManagerFor0x99()" == str)
    {
        ui.textEdit_2->setText(strVPNfor0x99);
    }
    else if ("setManualSolidPower()" == str)
    {
        ui.textEdit_2->setText(strSetManualPower);
    }
    else if ("getSolidPowerStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }

    if ("setPowerInfoPolicy()" == str)
    {
        ui.textEdit_2->setText(strSetPowerInfoPolicy);
    }
    else if ("setPowerInfoManual()" == str)
    {
        ui.textEdit_2->setText(strSetPowerInfoManual);
    }
    else if ("getPowerInfoPolicy()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getPowerInfoStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setPowerMode()" == str)
    {
        ui.textEdit_2->setText(strSetPowerMode);
    }
    else if ("getPowerMode()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setTimingSolidPower()" == str)
    {
        ui.textEdit_2->setText(strSetTimingSolidPower);
    }
    else if ("getTimingSolidPower()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setSolidPowerStatus()" == str)
    {
        ui.textEdit_2->setText(strSetSolidPower);
    }
    else if ("isExistSolidPower()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setImmediatelyReboot()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("SetReBootTask()" == str)
    {
        ui.textEdit_2->setText(strSetTimingReboot);
    }
    else if ("GetReBootTask()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("clearAllMediasFor0x99()" == str)
    {
        ui.textEdit_2->setText(strClearAllMediasFor0x99);
    }
    else if ("setSyncPlayFor0x99()" == str)
    {
        ui.textEdit_2->setText(strSetSyncPlayFor0x99);
    }

    else if ("getPolicySourceOutMode()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setPolicySourceOutMode()" == str)
    {
        ui.textEdit_2->setText(strSetPolicySourceOutMode);
    }
    else if ("getNetworkCheck()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("batchSetScreenAttribute()" == str)
    {
        ui.textEdit_2->setText(setScreenAttributeSDK);
    }
    else if ("batchLogin()" == str)
    {
        ui.textEdit_2->setText(batchLoginPassword);
    }
    else if ("setRelayPowerManual()" == str)
    {
        ui.textEdit_2->setText(strSetRelayPowerManual);
    }
    else if ("setRelayPowerPolicy()" == str)
    {
        ui.textEdit_2->setText(strSetRelayPowerPolicy);
    }
    else if ("getRelayPowerPolicy()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getRelayPowerStatus()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setRelayPowerStatus()" == str)
    {
        ui.textEdit_2->setText(strSetRelayPowerStatus);
    }
    else if ("batchSetRecvCardFile()" == str)
    {
        ui.textEdit_2->setText(batchSetRecvCardFile);
    }
    else if ("setScreenAttributeSDK()" == str)
    {
        ui.textEdit_2->setText(setScreenAttributeSDK);
    }
    else if ("setNetworkCheck()" == str)
    {
        ui.textEdit_2->setText(setNetworkCheck);
    }
    if ("downloadTerminalLog()" == str)
    {
        ui.textEdit_2->setText(downloadTerminalLog);
    }
    if ("uploadTerminalLog()" == str)
    {
        ui.textEdit_2->setText(uploadTerminalLog);
    }
    if ("cancelFunction()" == str)
    {
        ui.textEdit_2->setText(cancelFunction);
    }
    if ("checkNetwork()" == str)
    {
        ui.textEdit_2->setText("");
    }
    if ("downloadTerminalAllLog()" == str)
    {
        ui.textEdit_2->setText(strDownloadTerminalAllLog);
    }
    else if ("downloadTerminalLogNet()" == str)
    {
        ui.textEdit_2->setText("");
    }
    if ("downloadTerminalPlayLog" == str)
    {
        ui.textEdit_2->setText(strDownloadTerminalAllLog);
    }
    if ("downloadTerminalPlayLogNet" == str)
    {
        ui.textEdit_2->setText(strDownloadTerminalAllLog);
    }
    else if("setPageParam()(图片、视频、GIF简化)"==str)
    {
        ui.textEdit_2->setText(strEasyPicture);
    }
    else if ("setPageParam()(数字时钟简化)" == str)
    {
        ui.textEdit_2->setText(strEasyDigitalClock);
    }
    else if ("setPageParam()(文本简化)" == str)
    {
        ui.textEdit_2->setText(strEasyText);
    }

	if ("getSendCardMonitorInfo()" == str)
	{
		ui.textEdit_2->setText(sn);
	}
	else if("getReceiverCountAndInfo()" == str)
	{
		ui.textEdit_2->setText(sn);
	}
	else if ("getScreenDeviceInfo()" == str)
	{
		ui.textEdit_2->setText(sn);
	}
	else if ("loginVnnox()" == str)
	{
		ui.textEdit_2->setText(strLoginVnnox);
	}
	else if ("getVerifyCode()" == str)
	{
		ui.textEdit_2->setText("");
	}
	else if ("registerVnnox()" == str)
	{
		ui.textEdit_2->setText("");
	}
	else if ("ping()" == str)
	{
		ui.textEdit_2->setText("");
	}
	else if ("ping()" == str)
	{
		ui.textEdit_2->setText("");
	}
	else if ("rsaEncode()" == str)
	{
		ui.textEdit_2->setText("");
	}
	else if ("rsaDecode()" == str)
	{
		ui.textEdit_2->setText("");
	}
	
    if ("setAudioMedioProgram()" == str)
    {
        ui.textEdit_2->setText(strSetAudioMedioProgram);
    }
    else if ("initPublicNet()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("stopPublicNet()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("setPublicNetConfigParam()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("disconnectPublicNet()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    else if ("getPublicNetParam()" == str)
    {
        ui.textEdit_2->setText(sn);
    }


    if ("getEnvironmentBrightnessParameter()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    if ("setEnvironmentBrightnessParameter()" == str)
    {
        ui.textEdit_2->setText(sn);
    }
    if ("getOnlineDevicesAsync()" == str)
    {
        ui.textEdit_2->setText(sn);
    }

    if ("transferProgram()" == str)
    {
        ui.textEdit_2->setText(sn);
    }

    
	
}
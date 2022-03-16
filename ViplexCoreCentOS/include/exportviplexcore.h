#pragma once
#include "exportdefine.h"
#include "viplexcommon/jsonserializer/jsonserializer.h"
#include "viplexcommon/interface/iviplexrequester.h"
extern "C"
{
   //VIPLEX_EXPORT void exportFuncAPI(std::function<void(const char *, ViplexCallback)>,const char *data, ViplexCallback callBack,const uint64_t timeout);

   VIPLEX_EXPORT void exportFuncFeedBackAPI(std::function<void(const char *, ViplexCallback)> func, const char *data, ViplexCallback callBack, const uint64_t timeout);

   VIPLEX_EXPORT void exportCollectorCallBack(std::function<void(const char *, ViplexCallback)>, const char *data, ViplexCallback callBack, const uint64_t timeout = 16000);


   /*
    *  @brief  临时接口，只有 ios 调用，IOS需要在进入后台干掉socket和重新创建socket，android或者其他平台不做处理
    *  @param  platform  识别是 IOS 还是 android 平台
    */
   VIPLEX_EXPORT void setPlatform(const char *platform);
   /**
* showdoc
* @catalog 接口示例/初始化
* @title SDK初始化
* @description SDK初始化接口,调用SDK接口前必须调用此接口完成SDK初始化
* @url int Init(const char *sdkRootDir, const char *credentials);
* @json_param {"company":"NovaStar","phone":"029-68216000","email":"hr@novastar.tech"}
* @param sdkRootDir 必选 string 存放SDK日志、数据库的路径
* @param credentials 必选 object 公司认证信息，SDK存在缺陷或重大更新时，便于通知客户升级
* @param company 必选 string 公司名称
* @param phone 必选 string 公司电话
* @param email 必选 string 公司Email
* @return ""
* @return_param code int 错误码：<br>`0`初始化成功<br>`65286`日志初始化失败<br>`65287`数据库初始化失败
* @remark
* @number 99
*/
   VIPLEX_EXPORT int init(const char *sdkRootDir, const char *credentials);
   VIPLEX_EXPORT int initViplexCore(const char *sdkRootDir, const char *credentials);
   VIPLEX_EXPORT void ping(ExportViplexCallback callBack);

#pragma region Diagnosis 诊断模块 
#pragma endregion 诊断模块 待开发


#pragma region PowerManager 多功能卡电源管理 
   VIPLEX_EXPORT void setTimingPowerSwitchStatus(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void getTimingPowerSwitchStatus(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void getRealtimePowerSwitchStatus(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/多功能卡电源管理/手动开关电源
    * @title 设置手动电源开关状态
    * @description 设置手动电源开关状态的接口
    * @method
    * @url void nvSetManualPowerSwitchStatus(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"123456","data":{"type":"FUNCTIONPOWER","source":{"type":1,"platform":1},"data":[{"conditions":[{"action":1,"type":"屏体电源","powerIndex":0},{"action":1,"type":"风扇电源","powerIndex":1}],"portIndex":0,"connectIndex":1}]}}
    * @param sn 必选 string 产品唯一序列号
    * @param data 必选 ObjectArray 按照条件执行的多功能卡任务集合
    * @param conditions 必选 ObjectArray 按照条件执行的任务集合,支持多任务
    * @param action 必选 int 具体电源控制。0：开、1：关
    * @param powerIndex 必选 int 开关的类型，以字符串的形式表征
    * @param type 必选 string 多功能卡电源的下标,(目前支持0-7)
    * @param connectIndex 必选 int 多功能卡网口连接的设备编号
    * @param portIndex 必选 int 多功能卡的网口地址
    * @param source 必选 Object 表示任务的发布来源。如：VNNOX、CS、LCT等
    * @param platform 必选 int 表示任务发布来源,1：手机,2：CS,3：平板,4：VNNOX,5：Care、6：LCT
    * @param type 必选 int 表示发布任务的平台,1：nova自己的平台0：第三方平台
    * @param type 必选 string FUNCTIONPOWER(固定值)
    * @return {"code":0,"data":"12d4sa654d564ddauioaj4163"}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 成功返回md5码,失败返回错误码对应的说明
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setManualPowerSwitchStatus(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/多功能卡电源管理/手动开关电源
    * @title 获取手动电源开关状态
    * @description 获取手动电源开关状态的接口
    * @method
    * @url void nvGetManualPowerSwitchStatus(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"123456"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"code":0,"data":{"data":[{"conditions":[{"action":1,"powerIndex":0,"type":"屏体电源"},{"action":1,"powerIndex":1,"type":"风扇电源"}],"connectIndex":1,"portIndex":0}],"source":{"platform":1,"type":1},"type":"FUNCTIONPOWER"}}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 成功返回md5码,失败返回错误码对应的说明
    * @return_param data ObjectArray 按照条件执行的多功能卡任务集合
    * @return_param conditions ObjectArray 按照条件执行的任务集合,支持多任务
    * @return_param action int 具体电源控制。0：开、1：关
    * @return_param powerIndex int 开关的类型，以字符串的形式表征
    * @return_param type string 多功能卡电源的下标,(目前支持0-7)
    * @return_param connectIndex int 多功能卡网口连接的设备编号
    * @return_param portIndex int 多功能卡的网口地址
    * @return_param source Object 表示任务的发布来源。如：VNNOX、CS、LCT等
    * @return_param platform int 表示任务发布来源,1：手机,2：CS,3：平板,4：VNNOX,5：Care、6：LCT
    * @return_param type int 表示发布任务的平台,1：nova自己的平台0：第三方平台
    * @return_param type string FUNCTIONPOWER(固定值)
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getManualPowerSwitchStatus(const char *data, ExportViplexCallback callBack);
#pragma endregion 多功能卡电源管理 待开发

#pragma region VolumeController 音量调节
   /**
    * @brief 获取当前音量
    * @param const char * data 格式如：
    {
        "sn":"BZSA07194A0049999716"
    }
    * @param ExportViplexCallback callback，成功返回如下格式：
    {
    "ratio":75
    }
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void getVolume(const char *data, ExportViplexCallback callback);
   /**
   * @brief 音量调节
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "volumeInfo":{
           "ratio":60
       }
   }
   * @param ExportViplexCallback callback，返回空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setVolume(const char *data, ExportViplexCallback callback);
#pragma endregion VolumeController 音量调节

#pragma region VPNConnection VPN连接管理
   /**
    * showdoc
    * @catalog 接口示例/VPN连接管理/VPN连接管理
    * @title 获取VPN连接信息
    * @description 获取VPN连接信息的接口
    * @method
    * @url void nvGetVPNConnectInfo(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"123456"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"connectInfo":{"connectStatus":2,"failReasonCode":0},"guid":"decf313f-1014-44ad-a059-28ed58fce170","networkInfo":{"ipAddress":"10.0.0.2"},"source":{"platform":2,"type":1},"taskAction":"VPN_CONNECT","timestamp":"2020-07-13 T02:27:47 Z+00:00","vpnInfo":{"address":"vpn.vnnox.com","isReconnect":false,"name":"456","password":"bOwVRSe8l4WnE6hCkItCEgLHFZpNndYx","protocolType":1,"redialInterval":180,"redialNumber":3,"sessionTimeout":7200,"sharedSecretKey":"novastar.tech","username":"vnnox"},"orderId":-1}
    * @return_param connectInfo object 连接上报信息
    * @return_param connectStatus int 连接接状态：1、链接中2、链接成功3、断开
    * @return_param failReasonCode int 失败原因code，0：正常，ERR_INTERRUPTED：超时后主动中断，ERR_ALREADY_EXISTED：命令重复，其他错误码见错误码说明
    * @return_param guid string 最后一条命令的唯一标识
    * @return_param timestamp string 时间戳
    * @return_param taskAction string 操作：VPN_CLOSE，VPN_CONNECT
    * @return_param networkInfo object 网络信息
    * @return_param ipAddress string Ip地址
    * @return_param source object 上报资源信息
    * @return_param type int 类型信息：1：nova，2：第三方平台
    * @return_param platform int 1：vnnox，2：cs软件
    * @return_param vpnInfo object vpn信息
    * @return_param address string vpn地址
    * @return_param isReconnect boolean 是否断线重连
    * @return_param name string vpn名称
    * @return_param password string 密码
    * @return_param protocolType string vpn协议类型
    * @return_param redialInterval int 重拨间隔
    * @return_param redialNumber int 重播次数
    * @return_param sessionTimeout int 会话时长
    * @return_param sharedSecretKey string 共享秘钥
    * @return_param username string 用户名
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void nvGetVPNConnectInfo(const char *data, ExportViplexCallback callback);
   /**
   * showdoc
   * @catalog 接口示例/VPN连接管理/VPN连接管理
   * @title 设置VPN连接信息
   * @description 设置VPN连接信息的接口
   * @method
   * @url void nvSetVPNConnectInfo(const char *data, ExportViplexCallback callback)
   * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"guid":"123456","taskAction":"VPN_CLOSE","source":{"type":1,"platform":2},"vpnInfo":{"name":"123456","address":"vpn.vnnox.com","protocolType":1,"username":"vnnox","password":"123456","sharedSecretKey":"novastar.tech","redialNumber":3,"redialInterval":180,"sessionTimeout":7200,"isReconnect":false}}}
   * @param sn 必选 string 产品唯一序列号
   * @param taskInfo 必选 object 设置VPN的详细信息
   * @param guid 必选 string 命令的唯一标识
   * @param taskAction 必选 string 操作：VPN_CLOSE，VPN_CONNECT
   * @param source 非必选 object 上报资源信息
   * @param type 非必选 int 类型信息：1：nova，0：第三方平台
   * @param platform 非必选 int 平台类型：1：移动终端发来的（如手机），2：表示传统电脑，3：表示平板，4：表示web端发来的
   * @param vpnInfo 必选 object vpn信息
   * @param name 必选 string vpn名称
   * @param address 必选 string vpn地址
   * @param protocolType 必选 string vpn协议类型
   * @param username 必选 string 用户名
   * @param password 必选 string 密码
   * @param sharedSecretKey 必选 string 共享秘钥
   * @param redialNumber 必选 int 重拨次数
   * @param redialInterval 必选 int 重播间隔
   * @param sessionTimeout 必选 int 会话时长
   * @param isReconnect 必选 boolean 是否断线重连
   * @return ""
   * @return_param code int 错误码：`0`获取成功
   * @return_param data string 成功返回md5码,失败返回错误码对应的说明
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void nvSetVPNConnectInfo(const char *data, ExportViplexCallback callback);
#pragma endregion VPN连接管理 待开发

#pragma region AppManager
   /**
  * @brief获取已安装的APP信息
  * @param const char * data
    * {
    *    "sn":"",
    * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void getInstalledPackageInfo(const char *data, ExportViplexCallback callBack);

   /**
  * @brief获取正在运行的APP版本信息
  * @param const char * data
   *{
   *    "sn":"",
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void getRunningPackageInfo(const char *data, ExportViplexCallback callBack);

   /**
  * @brief停止运行APP
  * @param const char * data
   * {
    *    "sn":"",
    *    "requestInfo":{
    *        "packageName":""
    *    }
    * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void forceStopApp(const char *data, ExportViplexCallback callBack);

   /**
  * @brief卸载安卓程序
  * @param const char * data
   * {
   *    "sn":"",
   *    "packageName":""
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void uninstallPackage(const char *data, ExportViplexCallback callBack);

   /**
  * @brief安装安卓程序
  * @param const char * data
   * {
   *    "sn":"",
   *    "apkFile":"",
   *    "packageName":"",
   *    "startAfterInstall":true,
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void startUploadApk(const char *data, ExportViplexCallback callBack);

   /**
  * @brief安装安卓程序(全部参数)
  * @param const char * data
  字段内容同远程升级接口，在此不再赘述
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void startUploadApkCore(const char *data, ExportViplexCallback callBack);
#pragma endregion AppManager APP管理

#pragma region PlayLogger 播放日志
   /**
    * showdoc
    * @catalog 接口示例/播放日志/播放日志路径获取
    * @title 播放日志路径获取
    * @description 播放日志路径获取的接口
    * @method
    * @url void nvGetPlaylogPath(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"123456"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"logList":["2020-07-13.json"],"url":"/sdcard/nova/viplex_terminal/play_log"}
    * @return_param url string 播放日志目录路径
    * @return_param logList stringArray 播放日志文件名集合
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getPlaylogPath(const char *data, ExportViplexCallback callback);
#pragma endregion 播放日志 待开发

#pragma region PlayFont 字体
   /**
    * showdoc
    * @catalog 接口示例/字体
    * @title 获取终端支持的字体
    * @description 获取终端支持的字体的接口
    * @method
    * @url void nvGetTerminalFont(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"123456"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"supportFonts":[{"name":"Arial","src":"system"},{"name":"Calibri","src":"system"},{"name":"Wingdings2","src":"system"},{"name":"SimSun","src":"system"},{"name":"KaiTi","src":"system"},{"name":"Microsoft YaHei","src":"system"},{"name":"Agency FB","src":"custom"}]}
    * @return_param code int 错误码：`0`获取成功
    * @return_param supportFonts ArrayObject 终端支持的字体
    * @return_param name String 字体名称
    * @return_param src String 字体来源，目前包括system、custom，以后也可支持来自某用户
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getTerminalFont(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/字体
    * @title 删除字体
    * @description 删除字体的接口
    * @method
    * @url void nvDeleteFont(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"fonts":[{"name":"Arail"}]}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 字体信息
    * @param fonts 必选 object 要删除的字体列表
    * @param name 必选 string 字体名称
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void deleteFont(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/字体
    * @title 更新字体
    * @description 更新字体的接口
    * @method
    * @url void nvUpdateFont(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093","localFontPath":"C:\\Windows\\Fonts","taskInfo":{"fonts":[{"name":"Agency FB","style":["Bold","Italic","Normal","Underline","Strikeout"],"file":["AGENCYB.TTF","AGENCYB.TTF","AGENCYB.TTF","AGENCYB.TTF","AGENCYB.TTF"]}]}}
    * @param sn 必选 string 产品唯一序列号
    * @param localFontPath 必选 string 字体存放目录
    * @param taskInfo 必选 Object 字体信息
    * @param fonts 必选 objectArray 要添加的字体列表
    * @param name 必选 string 字体名称
    * @param style 必选 stringArray 字体属性
    * @param file 必选 stringArray 字体文件名
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void updateFont(const char *data, ExportViplexCallback callBack);

#pragma endregion 字体 待开发

#pragma region 生产功能测试
#pragma endregion 生产功能测试 待开发

#pragma region LEDSplicer 多屏拼接
   /**
 * @brief 获取拼接参数
 * @param const char * data
 {
     "sn":""
 }
 * @param ExportViplexCallback callBack
 {
     "height":0,
     "isScale":false,
     "offsetX":0,
     "offsetY":0,
     "order":0,
     "orderNum":0,
     "videoSource":0,
     "width":0
 }
 * @returnVIPLEX_EXPORT void
 */
   VIPLEX_EXPORT void GetSpliceInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 设置拼接参数
   {
       "sn":"",
       "SpliceInfo":
               {
               "height":400,
               "isScale":false,
               "offsetX":0,
               "offsetY":0,
               "order":0,
               "orderNum":0,
               "videoSource":0,
               "width":400
               }
   }

   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void SetSpliceInfo(const char *data, ExportViplexCallback callBack);

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
   /**
    * showdoc
    * @catalog 接口示例/传感器子板
    * @title 获取终端支持的传感器信息
    * @description 获取终端支持的传感器信息的接口
    * @method
    * @url void nvGetSupportSensorInfo(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"sensorInfos":[{"baudRate":115200,"connected":false,"functionId":10,"previewUnit":100,"previewValue":"-1000.0","sensorId":85,"vendor":1,"vendorAliasName":"NovaStar"},{"baudRate":115200,"connected":false,"functionId":6,"previewUnit":60,"previewValue":"-1000.0","sensorId":86,"vendor":1,"vendorAliasName":"NovaStar"}]}
    * @return_param code int 错误码：`0`获取成功
    * @return_param sensorInfos objectArray 传感器信息
    * @return_param functionId int 功能ID,每个ID值表征什么业务见后表
    * @return_param vendor int 厂商
    * @return_param sensorId int 传感器ID,详情见下表
    * @return_param baudRate int 传感器波特率
    * @return_param connected boolean 是否连接
    * @return_param vendorAliasName String 厂商别名字,NovaStar,Nenghui,JXCT
    * @return_param previewValue String 检测到的传感器的值,默认无效值:-1000.0
    * @return_param previewUnit int 检测时传入的数值单位,0:默认单位,1:用户自定义其他单位
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getSupportSensorInfo(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/传感器子板
    * @title 配置传感器的连接选项
    * @description 配置传感器的连接选项的接口
    * @method
    * @url void nvSetSupportSensorInfo(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"isUpgradeSensorProgram":true,"sensorInfos":[{"functionId":10,"vendor":1,"sensorId":85,"baudRate":115200,"vendorAliasName":"NovaStar","previewValue":"-1000.0","previewUnit":100,"connected":true},{"functionId":6,"vendor":1,"sensorId":86,"baudRate":115200,"vendorAliasName":"NovaStar","previewValue":"-1000.0","previewUnit":60,"connected":true}]}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 设置信息
    * @param isUpgradeSensorProgram 非必选 bool true,上位机支持传感器预览数据回读,false不支持
    * @param sensorInfos 必选 ObjectArray 传感器信息
    * @param functionId 必选 int 功能ID，每个ID值表征什么业务见后表
    * @param vendor 必选 int 厂商
    * @param sensorId 必选 int 传感器ID
    * @param baudRate 必选 int 传感器波特率
    * @param connected 必选 boolean 是否连接
    * @param vendorAliasName 必选 string 厂商英文名字,NovaStar,Nenghui,JXCT
    * @param previewValue 必选 string 检测到的传感器的值,默认无效值:"-1000.0"
    * @param previewUnit 必选 int 检测时传入的数值单位：0：默认单位，1：用户自定义其他单位
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setSupportSensorInfo(const char *data, ExportViplexCallback callBack);
#pragma endregion Sensor 传感器子板 待开发

#pragma region ExternalDelivery
#pragma endregion ExternalDelivery 外投调节 待开发

#pragma region RadioFrequency
   /**
   * @brief 射频管理-获取Lora信息
   * @param const string & data
   {
	   "sn":""
   }
   * @param ViplexCallback callBack
   * @return void
   */
   void getLoraInfo(const char *data, ExportViplexCallback callBack);
#pragma endregion RadioFrequency 射频管理

#pragma region PowerController
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置手动多功能卡电源控制任务
    * @description 设置手动多功能卡电源控制任务的接口
    * @method
    * @url void setPowerInfoManual(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":[{"conditions":[{"action":1,"type":"屏体电源","powerIndex":0},{"action":0,"type":"风扇电源","powerIndex":1}],"portIndex":0,"connectIndex":1}]}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 设置信息
    * @param conditions 必选 ObjectArray 按照条件执行的任务集合，支持多任务
    * @param action 必选 int 具体电源控制。0：开、1：关
    * @param type 必选 string 开关的类型，以字符串的形式表征。
    * @param powerIndex 必选 int 多功能卡网口连接的设备编号
    * @param portIndex 必选 int 多功能卡的网口地址
    * @param connectIndex 必选 int 接收卡所在网口下的连接位置
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setPowerInfoManual(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置手动多功能卡电源控制任务
    * @description 设置手动多功能卡电源控制任务的接口
    * @method
    * @url void setPowerInfoPolicy(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":[{"conditions":[{"action":0,"cron":["00 33 14 * * ? *"],"enable":true,"endTime":"4016-06-06","flag":"a2fa3a07-e0da-94b107ff","powerIndex":0,"startTime":"2020-08-28","type":"屏体电源"},{"action":1,"cron":["30 33 14 * * ? *"],"enable":true,"endTime":"4016-06-06","flag":"a2fa3a07-e0da-94b107ff","powerIndex":0,"startTime":"2020-08-28","type":"屏体电源"}],"enable":true,"portIndex":0,"connectIndex":0}]}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 设置信息
    * @param conditions 必选 ObjectArray 按照条件执行的任务集合，支持多任务
    * @param action 必选 int 具体电源控制。0：开、1：关
    * @param cron 必选 StringArray 每个控制方案使用cron表达式数组表示，当有多个cron表达式时，cron表达式之间使用或的关系
    * @param action 必选 int 具体电源控制。0：开、1：关
    * @param type 必选 string 开关的类型，以字符串的形式表征
    * @param startTime 必选 string 有效时间的开始日期
    * @param endTime 必选 string 效时间的结束日期
    * @param enable 必选 boolean 按条件执行的使能开关。如果为true，那么此条cron表达式生效，如果为false，则不生效。
    * @param powerIndex 必选 int 多功能卡电源的下标.(目前支持0-7)
    * @param flag 必选 string 此字段属于VNNOX、手机、CS专用字段
    * @param enable 必选 bool 按条件执行的使能开关。如果为true，则执行conditions中的定时任务，如果为false，则不执行。
    * @param portIndex 必选 int 多功能卡的网口地址
    * @param connectIndex 必选 int 接收卡所在网口下的连接位置
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setPowerInfoPolicy(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取定时多功能电源控制任务
    * @description 获取定时多功能电源控制任务的接口
    * @method
    * @url void nvGetPowerInfoPolicy(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"data":[{"conditions":[{"action":0,"cron":["30 11 15 * * ? *"],"enable":true,"endTime":"4016-06-06","flag":"a2fa3a07-e0da-94b107ff","powerIndex":0,"startTime":"2020-08-28","status":-1,"type":"屏体电源"},{"action":1,"cron":["00 12 15 * * ? *"],"enable":true,"endTime":"4016-06-06","flag":"a2fa3a07-e0da-94b107ff","powerIndex":0,"startTime":"2020-08-28","status":-1,"type":"屏体电源"}],"connectIndex":0,"enable":true,"portIndex":0}],"orderId":-1,"source":{"platform":1,"type":1}}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data objectArray 按照条件执行的多功能卡任务集合
    * @return_param conditions objectArray 按照条件执行的任务集合，支持多任务
    * @return_param action int 具体电源控制,0：开、1：关
    * @return_param cron stringArray 每个控制方案使用cron表达式数组表示，当有多个cron表达式时，cron表达式之间使用或的关系
    * @return_param enable bool 按条件执行的使能开关。如果为true，那么此条cron表达式生效，如果为false，则不生效。
    * @return_param endTime string 有效时间的结束日期
    * @return_param flag string 此字段属于VNNOX、手机、CS专用字段
    * @return_param powerIndex int 多功能卡电源的下标.(目前支持0-7)
    * @return_param startTime string 有效时间的开始日期
    * @return_param status int 默认值为-1
    * @return_param type string 开关的类型，以字符串的形式表征
    * @return_param connectIndex int 接收卡所在网口下的连接位置
    * @return_param enable bool 按条件执行的使能开关。如果为true，则执行conditions中的定时任务，如果为false，则不执行。
    * @return_param portIndex int 多功能卡的网口地址
    * @return_param orderId int 默认为-1
    * @return_param source object 表示任务的发布来源。如：VNNOX、CS、LCT等
    * @return_param type int 表示发布任务的平台。1：nova自己的平台，0：第三方平台
    * @return_param platform int 表示任务发布来源。1：手机、2：CS、3：平板、4：VNNOX、5：Care、6：LCT
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getPowerInfoPolicy(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取多功能卡电源状态
    * @description  获取多功能卡电源状态的接口
    * @method
    * @url void getPowerInfoStatus(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"current_status_info":[{"connectIndex":0,"portIndex":0,"updatePowerIndexStates":[{"powerIndex":0,"status":1,"type":"屏体电源"},{"powerIndex":1,"status":1,"type":"屏体电源"},{"powerIndex":2,"status":1,"type":""},{"powerIndex":3,"status":1,"type":""},{"powerIndex":4,"status":1,"type":""},{"powerIndex":5,"status":1,"type":""},{"powerIndex":6,"status":1,"type":""},{"powerIndex":7,"status":1,"type":""}]}],"source":{"platform":0,"type":1}}
    * @return_param code int 错误码：`0`获取成功
    * @return_param current_status_info ObjectArray 多功能卡的各路电源状态
    * @return_param connectIndex int 多功能卡网口连接的设备编号
    * @return_param portIndex int 多功能卡接的网口地址
    * @return_param updatePowerIndexStates ObjectArray 每张多功能卡中各路电源的状态
    * @return_param powerIndex int 每一路电源所代表的下标，当前只支持0-7
    * @return_param type string 开关的类型，以字符串的形式表征
    * @return_param status int 0：开、1：关
    * @return_param source object 表示任务的发布来源。如：VNNOX、CS、LCT等
    * @return_param type int 表示发布任务的平台。1：nova自己的平台，0：第三方平台
    * @return_param platform int 表示任务发布来源。1：手机、2：CS、3：平板、4：VNNOX、5：Care、6：LCT
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getPowerInfoStatus(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制模式
    * @title 设置终端电源模式
    * @description 设置终端电源模式的接口
    * @method
    * @url void setPowerMode(const char *data, ViplexCallback callBack);
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"mode":1}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 设置信息
    * @param mode 必选 int 电源的模式。1：定时，0：手动
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setPowerMode(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制模式
    * @title 获取终端电源模式
    * @description 获取终端电源模式的接口
    * @method
    * @url void getPowerMode(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"mode":1,"source":{"platform":1,"type":1}}
    * @return_param code int 错误码：`0`获取成功
    * @return_param mode int 电源的模式。1：定时，0：手动
    * @return_param source object 表示任务的发布来源。如：VNNOX、CS、LCT等
    * @return_param type int 表示发布任务的平台。1：nova自己的平台，0：第三方平台
    * @return_param platform int 表示任务发布来源。1：手机、2：CS、3：平板、4：VNNOX、5：Care、6：LCT
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getPowerMode(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置本板电源手动控制任务
    * @description 设置本板电源手动控制任务的接口
    * @method
    * @url void setRelayPowerManual(const char *data, ViplexCallback callBack);
    * @json_param {"sn":"123456","taskInfo":[{"type":"本板电源","powerIndex":1,"status":1}]}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 ObjectArray 设置信息
    * @param type 必选 string 本板电源
    * @param powerIndex 必选 int 继电器编号
    * @param status 必选 int 开关：1表示开，0表示关
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setRelayPowerManual(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置本板电源定时控制任务
    * @description 设置本板电源定时控制任务的接口
    * @method
    * @url void setRelayPowerPolicy(const char *data, ViplexCallback callBack);
    * @json_param {"sn":"BZVA28407N3X20008006","taskInfo":[{"cron":["00 41 11 * * ? *"],"powerIndex":0,"type":"本板电源","status":1,"startTime":"2020-09-06","endTime":"2020-09-30","enable":true},{"cron":["30 41 11 * * ? *"],"powerIndex":1,"status":0,"type":"本板电源","startTime":"2020-09-06","endTime":"2020-09-30","enable":true}]}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 ObjectArray 设置信息
    * @param cron 必选 stringArray 每个控制方案使用cron表达式数组表示，当有多个cron表达式时，cron表达式之间使用或的关系
    * @param type 必选 string 本板电源
    * @param powerIndex 必选 int 继电器编号
    * @param status 必选 int 开关：1表示开，0表示关
    * @param startTime 必选 string 有效时间的开始日期
    * @param endTime 必选 string 有效时间的结束日期
    * @param enable 必选 bool 按条件执行的使能开关。如果为true，那么此条cron表达式生效，如果为false，则不生效
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setRelayPowerPolicy(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取本板电源定时控制任务
    * @description 获取本板电源定时控制任务的接口
    * @method
    * @url void getRelayPowerPolicy(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"relayPolicyTask":[{"cron":["00 41 11 * * ? *"],"enable":true,"endTime":"2020-09-30","powerIndex":0,"startTime":"2020-09-06","status":1,"type":"本板电源"},{"cron":["30 41 11 * * ? *"],"enable":true,"endTime":"2020-09-30","powerIndex":1,"startTime":"2020-09-06","status":0,"type":"本板电源"}],"source":{"platform":1,"type":1}}
    * @return_param code int 错误码：`0`获取成功
    * @return_param relayPolicyTask objectArray 本板电源定时控制信息
    * @return_param cron stringArray 每个控制方案使用cron表达式数组表示，当有多个cron表达式时，cron表达式之间使用或的关系
    * @return_param enable bool 按条件执行的使能开关。如果为true，那么此条cron表达式生效，如果为false，则不生效
    * @return_param endTime string 有效时间的结束日期
    * @return_param powerIndex int 继电器编号
    * @return_param startTime string 有效时间的开始日期
    * @return_param status int 开关：1表示开，0表示关
    * @return_param type string 本板电源
    * @return_param type int 表示发布任务的平台。1：nova自己的平台，0：第三方平台
    * @return_param platform int 表示任务发布来源。1：手机、2：CS、3：平板、4：VNNOX、5：Care、6：LCT
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getRelayPowerPolicy(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取本板电源状态
    * @description 获获取本板电源状态的接口
    * @method
    * @url void getRelayPowerStatus(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"relayStatus":[{"powerIndex":0,"status":1,"type":"本板电源"}],"source":{"platform":0,"type":1}}
    * @return_param code int 错误码：`0`获取成功
    * @return_param relayStatus objectArray 本板电源状态信息
    * @return_param type string 本板电源
    * @return_param powerIndex int 继电器编号
    * @return_param status int 开关：1表示开，0表示关
    * @return_param type int 表示发布任务的平台。1：nova自己的平台，0：第三方平台
    * @return_param platform int 表示任务发布来源。1：手机、2：CS、3：平板、4：VNNOX、5：Care、6：LCT
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getRelayPowerStatus(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 配置本板电源状态
    * @description 配置本板电源状态的接口
    * @method
    * @url void setRelayPowerStatus(const char *data, ViplexCallback callBack);
    * @json_param {"sn":"123456","taskInfo":{"relayStatus":[{"type":"本板电源","powerIndex":1,"status":1}]}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 ObjectArray 设置信息
    * @param relayStatus 必选 objectArray 本板电源状态信息
    * @param type 必选 string 本板电源
    * @param powerIndex 必选 int 继电器编号
    * @param status 必选 int 开关：1表示开，0表示关
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setRelayPowerStatus(const char *data, ExportViplexCallback callBack);
#pragma endregion PowerController 终端电源控制 待开发

#pragma region VideoSourceController
   /**
   * @brief获取当前视频源
   * @param const char * data
   * {
   *     "sn":""
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getVideoControlInfo(const char *data, ExportViplexCallback callBack);
   /**
   * @brief设置视频源配置
   * @param const char * data
   * {
    *     "sn":""
    *     "videdSourceInfo":{
    *     "type":"VIDEO_SOURCE_SWITCH",
    *     "source":{
    *         "type":1,
    *         "platform":1
    *     },
    *     "videoMode":1,
    *     "videoSource":0,
    *     "isScale":false,
    *     "offsetX":0,
    *     "offsetY":0,
    *     "conditions":[
    *         {
    *             "cron":"0 0 12 ? * *",
    *             "source":0,
    *             "enable":true
    *         },
    *         {
    *             "cron":"0 0 12 ? * *",
    *             "source":1,
    *             "enable":true
    *         }
    *     ]
    * }
    * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setVideoControlInfo(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/视频源控制/EDID控制
    * @title 设置EDID
    * @description 设置EDID的接口
    * @method
    * @url void setVideoEDID(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"width":1920,"height":1080}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 设置信息
    * @param width 必选 int 显示屏宽度
    * @param height 必选 int 显示屏高度
    * @param fieldRate 必选 int 场频，即刷新频率
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setVideoEDID(const char *data, ExportViplexCallback callBack);
   /**
    * showdoc
    * @catalog 接口示例/视频源控制/EDID控制
    * @title 获取EDID
    * @description 获取EDID的接口
    * @method
    * @url void nvGetVideoEDID(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"fieldRate":60,"height":900,"width":1600}
    * @return_param code int 错误码：`0`获取成功
    * @return_param fieldRate int 场频，即刷新频率
    * @return_param height int 显示屏高度
    * @return_param height int 显示屏宽度
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getVideoEDID(const char *data, ExportViplexCallback callBack);

   /**
   * showdoc
   * @catalog 接口示例/视频源控制/获取视频源状态(0x99)
   * @title 获取视频源状态(0x99)
   * @description 获取视频源状态接口
   * @method
   * @url void nvGetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback callBack);
   * @json_param {"sn":"BZSA79353N1310006847"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"code":0,data:{"enable":true,"isScale":false,"offsetX":0,"offsetY":0,"orderId":-1,"videoMode":0,"videoSource":0}}
   * @return_param code int 错误码：`0`获取成功
   * @return_param enable bool 使能开关
   * @return_param isScale bool 是否缩放，true为全屏缩放，false为不缩放
   * @return_param offsetX int 偏移X
   * @return_param offsetY int 偏移Y
   * @return_param orderId int 命令的唯一标识
   * @return_param videoMode int 模式，HDMI优先 0，手动 1， 定时 2
   * @return_param videoSource int 视频源 SOURCE_INSIDE 内部 0， SOURCE_HDMI HDMI 1
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void nvGetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback callBack);

   /**
   * showdoc
   * @catalog 接口示例/视频源控制/设置视频源状态(0x99)
   * @title 设置视频源状态(0x99)
   * @description 设置视频源状态接口
   * @method
   * @url void nvSetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback callBack);
   * @json_param{"sn":"BZVA28407N3X20008006","data":{"videoSource":0}}
   * @param sn 必选 string 产品唯一序列号
   * @param videoSource 必选 int 视频源 SOURCE_INSIDE 内部 0， SOURCE_HDMI HDMI 1
   * @return {"code":0}
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void nvSetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback callBack);

   /**
   * showdoc
   * @catalog 接口示例/视频源控制/获取视频源状态(0x99)
   * @title 获取视频源状态(0x99)
   * @description 获取视频源状态(0x99)接口
   * @method
   * @url void nvGetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback callBack);
   * @json_param {"sn":"BZSA79353N1310006847"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"code":0,data:{"conditions":[{"cron":"0 0 12 ? * *","enable":true,"source":0},{"cron":"0 0 12 ? * *","enable":true,"source":1}],"enable":true,"isScale":false,"offsetX":0,"offsetY":0,"orderId":-1,"videoMode":0,"videoSource":0}}
   * @return_param code int 错误码：`0`获取成功
   * @return_param conditions objectArray 按照条件执行的任务集合，支持多任务
   * @return_param enable bool 使能开关
   * @return_param source int 视频源 SOURCE_INSIDE 内部 0， SOURCE_HDMI HDMI 1
   * @return_param enable bool 使能开关
   * @return_param isScale bool 是否缩放，true为全屏缩放，false为不缩放
   * @return_param offsetX int 偏移X
   * @return_param offsetY int 偏移Y
   * @return_param orderId int 命令的唯一标识
   * @return_param videoMode int 模式，HDMI优先 0，手动 1， 定时 2
   * @return_param videoSource int 视频源 SOURCE_INSIDE 内部 0， SOURCE_HDMI HDMI 1
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void nvGetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback callBack);

   /**
   * showdoc
   * @catalog 接口示例/视频源控制/设置定时视频源状态(0x99)
   * @title 设置定时视频源状态(0x99)
   * @description 设置定时视频源状态接口
   * @method
   * @url void nvSetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback callBack);
   * @json_param {"sn":"BZVA28407N3X20008006","data":{"enable":true,"conditions":[{"cron":"0 0 12 ? * *","source":0,"enable":true},{"cron":"0 0 12 ? * *","source":1,"enable":true }]}}
   * @param sn 必选 string 产品唯一序列号
   * @param conditions 必选 objectArray 按照条件执行的任务集合，支持多任务
   * @param enable 必选 bool 使能开关
   * @param source 必选 int 视频源 SOURCE_INSIDE 内部 0， SOURCE_HDMI HDMI 1
   * @return {"code":0}
   * @return_param code int 错误码：`0`获取成功
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void nvSetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback callBack);
   
#pragma endregion VideoSourceController 视频源控制

#pragma region userInfo

   /**
   * @brief
   * @param const char * data
   * {
   * "sn":"",
   * "userInfo":{
   *     "aliasName":"easy-pluto",
   *     "registerAddress":{
   *         "country":"中国",
   *         "province":"山西省",
   *         "city":"西安市",
   *         "county":"雁塔区",
   *         "address":"科技二路，西安软件园"
   *     }
   *  }
   * }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setUserInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief
   * @param const char * data
   * {
   *     "sn":""
   * }
   * @param ExportViplexCallback
   * @param callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getUserInfo(const char *data, ExportViplexCallback(callBack));
#pragma endregion userInfo 显示屏用户信息

#pragma region Login
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 搜索屏体
   * @description 此接口应该避免从 UI 线程发起调用，调用一次后， SDK 会在 4s 内依次返回搜索到的终端，且返回错误码 0，代表成功。若4s内未能搜索到任何终端，此接口返回 65535 错误码，代表搜索超时。
   * @url void nvSearchTerminal(ExportViplexCallback callback)
   * @return {"sn":"20393844393033","productName":"AX200","width":400,"height":800,"rotation":0,"aliasName":"XianYataScreen","logined":true,"username":["admin"],"tcpPort":16603,"ftpPort":16602,"syssetFtpPort":16604,"syssetTcpPort":16605,"key":"novaStar","platform":"rk3368","privacy":true,"terminalState":0,"ignoreTime":100029432434,"hasPassword":true,"password":"12345678"}
   * @return_param code int 错误码：<br>`0`搜索成功，result即为搜索返回内容。<br>`65535`搜索超时，代表在4s时间内未能搜索到任何终端
   * @return_param sn string 产品序列号
   * @return_param productName string 产品名称
   * @return_param width int 显示屏宽度, 单位为像素
   * @return_param height int 显示屏高度, 单位为像素
   * @return_param rotation int 旋转角度：0，90，180，270
   * @return_param aliasName string 显示屏别名
   * @return_param logined boolean 是否有人已经登陆
   * @return_param username string_array 若已经有人登陆，代表已经登陆的用户名列表
   * @return_param tcpPort int tcp连接端口
   * @return_param ftpPort int ftp连接端口
   * @return_param syssetFtpPort int 系统设置ftp端口
   * @return_param syssetTcpPort int 系统设置tcp端口
   * @return_param key string 终端返回的key,参与ftp的密码生产规则
   * @return_param platform string 系统平台信息（暂时会出现rk3368, rk312x）
   * @return_param privacy boolean True表示终端支持加密模式，当然如果是新的终端一定是True
   * @return_param password string 密码
   * @return_param terminalState int 当前屏体状态，terminalState共有6个值,分别代表：<br>`0`：未连接任何终端，当前处于未连接状态<br>`1`：连接成功但是未登录状态<br>`2`：被他人登录状态<br>`3`：登录成功状态<br>`4`：密码错误状态<br>`5`：离线状态，处于搜索不到的状态，但是曾经被搜索到过
   * @return_param ignoreTime long 记录点击忽略密码的时间戳
   * @return_param hasPassword boolean 是否记住密码，true表示记住，false，表示没有
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void serchTerminal(ExportViplexCallback resultCallBack);
   VIPLEX_EXPORT void serchTerminalW(ExportViplexCallbackUnicode resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 从数据库获取所有终端
   * @description 查询所有曾经搜索到的终端信息
   * @url void nvFindAllTerminals(ExportViplexCallback resultCallBack);
   * @return [{"aliasName":"Taurus-49999787","ftpPort":16602,"hasPassWord":false,"height":1080,"ignoreTime":0,"ip":"172.16.9.205","key":"novaStar","logined":false,"loginedUsernames":[""],"password":"","platform":"rk312x","privacy":true,"productName":"TC300","sn":"BZSA07194A0049999787","syssetFtpPort":16604,"syssetTcpPort":16605,"tcpPort":16603,"terminalState":5,"username":[],"width":1920}]
   * @return_param code int 错误码：<br>`0`获取成功
   * @return_param sn string 产品序列号
   * @return_param productName string 产品名称
   * @return_param width int 显示屏宽度, 单位为像素
   * @return_param height int 显示屏高度, 单位为像素
   * @return_param rotation int 旋转角度：0，90，180，270
   * @return_param aliasName string 显示屏别名
   * @return_param logined boolean 是否有人已经登陆
   * @return_param username string_array 若已经有人登陆，代表已经登陆的用户名列表
   * @return_param tcpPort int tcp连接端口
   * @return_param ftpPort int ftp连接端口
   * @return_param syssetFtpPort int 系统设置ftp端口
   * @return_param syssetTcpPort int 系统设置tcp端口
   * @return_param key string 终端返回的key,参与ftp的密码生产规则
   * @return_param platform string 系统平台信息（暂时会出现rk3368, rk312x）
   * @return_param privacy boolean True表示终端支持加密模式，当然如果是新的终端一定是True
   * @return_param password string 密码
   * @return_param terminalState int 当前屏体状态（数据库中搜索到的一直为5）
   * @return_param ignoreTime long 记录点击忽略密码的时间戳
   * @return_param hasPassword boolean 是否记住密码，true表示记住，false，表示没有
   * @return_param configInfo object 支持模块
   * @return_param installedPackageVersions object 已安装版本信息
   * @return_param productInfo object 设备信息
   * @return_param firmwareInfo object 固件版本信息
   * @return_param screenMosaicInfo object 多屏拼接信息
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void findAllTerminals(ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 登录
   * @description 登陆接口和tcp连接是合并在一起的。<br>由于登录包含了tcp连接，因此可能耗时稍微能长点，同时也保持了长连接，假如某个时间tcp突然断开了，错误信息会从这个接口返回。
   * @url void nvLogin(const char *data,ExportViplexCallback resultCallBack);
   * @json_param {"sn":"BZSA17332J0A20002272","username":"admin","password":"password","loginType":0,"rememberPwd":0}
   * @param sn 必选 string 产品唯一序列号
   * @param username 必选 string 用户名
   * @param password 必选 string 密码
   * @param loginType 必选 int `0`：登陆到屏体管理<br>`1`：登陆到系统设置（暗门登录）<br>`2`：登陆到诊断模块<br>`3`：LCT登录
   * @param rememberPwd 必选 int 是否记住密码<br>`0`表示No<br>`1`表示Yes
   * @return {"logined":true,"password":"123456","sn":"BZSA17332J0A20002272","username":"admin","validation":true,"validition":true,"loginedUsernames":["admin"],"encrypt":""}
   * @return_param code int 错误码：<br>`0`不代表登录成功，具体看备注<br>`65313`请求参数中SN无效<br>`65300`长连接过程中socket断开，可能是网络原因，也可能是终端断开了socket连接<br>**注意：当错误码code=65300时，data为sn，目的是告诉上位机哪个终端断开了**<br>`65304`执行登录动作时tcp连接失败，一般是因为网络问题（或者ip为空，端口占用等原因）<br>`65353`已经登录过了，请不要再进行二次登录<br>`65351`记住密码登录时，用户名或密码错误，有可能密码被其他人修改了，上位机可根据此错误码让用户重新手动输入密码<br>`16`密码连续错误3次，进入防暴力机制，1min内不允许登录，data返回：<br>{"errorDiscription":"Continuein33seconds.","mRemainTime":33}，mRemainTime代表33s后才可以继续登录
   * @return_param sn string 产品序列号
   * @return_param username string 用户名
   * @return_param password string 密码
   * @return_param validition boolean 用户名和密码是否有效（旧版本遗留字段）
   * @return_param validation boolean 用户名和密码是否有效（新版本增加的字段）
   * @return_param logined boolean 是否成功登陆
   * @return_param loginedUsernames string_array 已经登陆的账户名称,当logined为false，validation为true时，此字段有效
   * @return_param encrypt string 密码的暗码，用于找回密码,当logined为false，validation为falsee时，此字段有效
   * @remark 判断是否登录成功说明：<br>当返回 code == 0时：<br>`1、`当 logined 为 true,且 validition 也为 true 时，代表登录成功<br>`2、`当 logined 为 false，但 validition 为 true 时，代表终端被其他人登录<br>`3、`当 logined 为 false，且 validition 也为 false 时，代表密码错误<br><br>请重点关注错误码
   * @number 99
   */
   VIPLEX_EXPORT void loginTerminal(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 修改密码
   * @description 修改屏体的登录密码
   * @url void nvChangePassWord(const char *data,ExportViplexCallback resultCallBack);
   * @json_param {"sn":"12345787454544","reSetInfo":{"username":"admin","password":"123456","newPassword":"12345678"}}
   * @param sn 必选 string 产品唯一序列号
   * @param username 必选 string 用户名
   * @param password 必选 string 旧密码
   * @param newPassword 必选 string 新密码
   * @return changepassword success
   * @return_param code int 错误码：<br>`0`修改成功
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void changePassWord(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 屏体信息存储（数据继承）
   * @description 此接口是旧版本屏体数据继承
   * @url void nvSetScreenInfo(const char *data, ExportViplexCallback resultCallBack);
   * @json_param [{"aliasName":"Taurus-10006848","screenMosaicInfo":{"order":456,"videoSource":127},"ftpPort":16602,"hasPassWord":false,"height":400,"ignoreTime":0,"ip":"192.168.1.113","key":"novaStar","logined":false,"password":"","productName":"T6","sn":"BZSA79353N1310006848","syssetFtpPort":16604,"syssetTcpPort":16605,"tcpPort":16603,"terminalState":0,"width":400}]
   * @param sn 必选 string 产品唯一序列号
   * @param productName 可选 string 产品名称
   * @param width 可选 int 显示屏宽度, 单位为像素
   * @param height 可选 int 显示屏高度, 单位为像素
   * @param rotation 可选 int 旋转角度：0，90，180，270
   * @param aliasName 可选 string 显示屏别名
   * @param logined 可选 boolean 是否有人已经登陆
   * @param username 可选 string_array 若已经有人登陆，代表已经登陆的用户名列表
   * @param tcpPort 可选 int tcp连接端口
   * @param ftpPort 可选 int ftp连接端口
   * @param syssetFtpPort 可选 int 系统设置ftp端口
   * @param syssetTcpPort 可选 int 系统设置tcp端口
   * @param key 可选 string 终端返回的key,参与ftp的密码生产规则
   * @param screenMosaicInfo 可选 object 拼接屏信息
   * @param order 可选 int 拼接屏顺序
   * @param videoSource 可选 int 视频源个数
   * @return Success
   * @return_param code int 错误码：<br>`0`存储成功<br>`65347`存储失败
   * @return_param data string 错误码描述，不用关注
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void setScreenInfo(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 清除密码
   * @description 清除屏体密码
   * @url void nvDelTerminalInfo(const char *data, ExportViplexCallback resultCallBack);
   * @json_param {"sn":"BZSA17332J0A20002272","type":"clearPassWord"}
   * @param sn 必选 string 产品唯一序列号
   * @param type 必选 string "clearPassWord"代表此次操作是"清除密码"
   * @return Success
   * @return_param code int 错误码：<br>`0`清除成功<br>`65348`删除失败<br>`12`参数type错误，未实现的接口
   * @return_param data string 错误码描述，不用关注
   * @remark
   * @number 99
   */
   /**
    * showdoc
    * @catalog 接口示例/搜索连接登录
    * @title 删除屏体
    * @description 删除某个屏体
    * @url void nvDelTerminalInfo(const char *data,ExportViplexCallback resultCallBack);
    * @json_param {"sn":"BZSA17332J0A20002272","type":"deleteTerminal"}
    * @param sn 必选 string 产品唯一序列号
    * @param type 必选 string "deleteTerminal"代表此次操作是"删除屏体（终端）"
    * @return Success
    * @return_param code int 错误码：<br>`0`删除成功<br>`65348`删除失败<br>`12`参数type错误，未实现的接口
    * @return_param data string 错误码描述，不用关注
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void delTerminalInfo(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 获取拼接屏信息
   * @description 获取拼接屏信息
   * @url void nvGetTerminalInfo(const char *data, ExportViplexCallback resultCallBack);
   * @json_param {"sn":"BZSA17332J0A20002272","type":"getSystemInfo"}
   * @param sn 必选 string 产品唯一序列号
   * @param type 必选 string "getSystemInfo"代表此次操作是"获取系统信息"
   * @return {"mosaicWidth":400,"mosaicHeight":400,"mosaicNum":10}
   * @return_param code int 错误码：<br>`0`获取成功<br>`12`参数type错误，未实现的接口
   * @return_param mosaicWidth int 拼接宽度
   * @return_param mosaicHeight int 拼接高度
   * @return_param mosaicNum int 拼接总数
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void getTerminalInfo(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 设置弱密码忽略时间
   * @description 设置“点击忽略弱密码选项”的时间戳后，调用“搜索屏体”时返回设置的字段，否则调用“搜索屏体”时返回空字符串。<br>设置此时间戳的目的是在未来某段时间内不再弹出“是否忽略弱密码模态框”。
   * @url void nvSetTerminalInfo(const char *data, ExportViplexCallback resultCallBack);
   * @json_param {"sn":"BZSA17332J0A20002272","type":"setIgnoreTime","value": 123456789012345}
   * @param sn 必选 string 产品唯一序列号
   * @param type 必选 string "getSystemInfo"代表此次操作是"设置弱密码忽略时间"
   * @param value 必选 int 要设置的时间戳（毫秒）,比如：1113259324242
   * @return Success
   * @return_param code int 错误码：<br>`0`设置成功<br>`65347`设置失败<br>`12`参数type错误，未实现的接口
   * @return_param data string 错误码描述，不用关注
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void setTerminalInfo(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 设置系统信息
   * @description 设置“系统信息”。设置一些无关sn的配置信息，详见下面参数
   * @url void nvSetSystemInfo(const char *data, ExportViplexCallback resultCallBack);
   * @json_param {"mosaicWidth":400,"mosaicHeight":400,"lang":"cn","demo":true,"userType":"user"}
   * @param mosaicWidth 必选 int 拼接宽度
   * @param mosaicHeight 必选 int 拼接高度
   * @param lang 必选 string 多语言
   * @param demo 必选 bool 是否是demo
   * @param userType 必选 string 用户模式
   * @return Success
   * @return_param code int 错误码：<br>`0`设置成功<br>`65347`设置失败
   * @return_param data string 错误码描述，不用关注
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void setSystemInfo(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/搜索连接登录
   * @title 退出登录
   * @description 注意：退出登录后，返回成功或失败，login接口的长连接自动失效，不会再返回数据
   * @url void nvLogOut(const char *data, ExportViplexCallback resultCallBack);
   * @json_param {"sn":"BZSA17332J0A20002272","loginType":0}
   * @param sn 必选 string 产品唯一序列号
   * @param loginType 必选 int `0：`断开屏体管理<br>`1：`断开系统设置（暗门）<br>`2：`断开诊断模块<br>`3：`断开LCT登录
   * @return disconnetSuccess
   * @return_param code int 错误码：<br>`0`退出成功
   * @return_param data string 错误码描述，不用关注
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void disconnectFromTerminal(const char *data, ExportViplexCallback resultCallBack);
   /**
 * showdoc
 * @catalog 接口示例/屏体其他项
 * @title 固件版本信息
 * @description 获取固件版本信息接口，所有版本的终端均有此接口，返回终端的版本信息。<br>**1.2.2 版本碰到缺少 mac 字段**
 * @url void nvGetFirmwareInfos(const char *data, ExportViplexCallback resultCallBack);
 * @json_param {"sn":"BZSA17332J0A20002272"}
 * @param sn 必选 string 产品唯一序列号
 * @return {"fpga":"1.0.0.1","model":"AX100V010002CN0501","mainVersion":"1.0.1","productName":"T3","aliasName":"easy-PHOJ05447J0330015353","registerAddress":"西安软件园","mac":"30:5A:3A:04:62:C3"}
 * @return_param code int 错误码：<br>`0`获取成功<br>`65535`接口超时
 * @return_param fpga string FPGA版本
 * @return_param model string 系统版本
 * @return_param mainVersion string 终端软件主版本
 * @return_param productName string 产品名称
 * @return_param aliasName string 屏体别名
 * @return_param registerAddress string 屏体地址
 * @return_param mac string 屏体mac地址
 * @remark
 * @number 99
 */
   VIPLEX_EXPORT void getFirmwareInfos(const char *data, ExportViplexCallback resultCallBack);
   /**
 * showdoc
 * @catalog 接口示例/屏体其他项
 * @title 已安装的软件版本信息
 * @description 获取终端已经安装的软件版本信息
 * @url void nvGetInstalledPackageInfo(const char *data, ExportViplexCallback resultCallBack);
 * @json_param {"sn":"BZSA17332J0A20002272","packageInfo":{"packageName":["nova.priv.terminal.syssetting","nova.priv.terminal.easypluto"]}}
 * @param sn 必选 string 产品唯一序列号
 * @param packageInfo 必选 object
 * @param packageName 必选 string_array 软件包名数组
 * @return {"result":[{"packageName":"nova.priv.terminal.syssetting","versionName":"1.0.2.0501","versionCode":102},{"packageName":"nova.priv.terminal.easypluto","versionName":"1.0.2.0502","versionCode":102}]}
 * @return_param code int 错误码：<br>`0`获取成功<br>`65535`接口超时
 * @return_param packageName string 包名
 * @return_param versionName string 版本名称
 * @return_param int string 版本号
 * @remark
 * @number 99
 */
   VIPLEX_EXPORT void getInstalledPackageVersions(const char *data, ExportViplexCallback resultCallBack);
   /**
   * showdoc
   * @catalog 接口示例/屏体其他项
   * @title 设备信息
   * @description 获取终端设备信息
   * @url void nvGetProductInfo (const char *data, ExportViplexCallback resultCallBack);
   * @json_param {"sn":"BZSA17332J0A20002272"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"productInfo":{"productName":"","modelId":10043},"configInfo":{"videoSwitch":false,"displayDevice":"LED","portConfig":[{"portNO":1,"isMainPort":true,"belongMainPort":0},{"portNO":2,"isMainPort":true,"belongMainPort":0}]}}
   * @return_param code int 错误码：<br>`0`获取成功<br>`65535`接口超时
   * @return_param productInfo object 产品信息
   * @return_param productName string 产品名称，例如T3,T6
   * @return_param modelId int 产品编号
   * @return_param configInfo object 配置信息
   * @return_param videoSwitch bool 是否支持视频切换，true表示支持，false表示不支持
   * @return_param displayDevice string 显示设备，有两种LED、LCD
   * @return_param portConfig object_array 网口配置Rotation
   * @return_param portNO int 网口编号，例如 1,2,3,4
   * @return_param isMainPort bool 是否为主网口
   * @return_param belongMainPort int 对应的主网口，如果该网口是主网口，该字段无效
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void getProductInfo(const char *data, ExportViplexCallback resultCallBack);
   /*
    *  @brief 由于json字段太多，showdoc手动填写此处不写showdoc格式注释
    *  @param  
    */
   VIPLEX_EXPORT void getconfiguration(const char *data, ExportViplexCallback resultCallBack);
#pragma endregion Login 搜索连接登录
    
#pragma region ScreenBrightness
   /**
    * @brief 设置亮度调节参数
    * @param const char * data 格式如:
    {
        "sn":"BZWA17422J1X20000093",
        "brightnessAdjustModeInfo":{
            "mode":"MANUALLY"
        }
    }
    * @param ExportViplexCallback callback，返回空
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void setBrightnessAdjustMode(const char *data, ExportViplexCallback callback);
   /**
   * @brief 获取亮度调节模式
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093"
   }
   * @param ExportViplexCallback callback，返回值如：
   {
       "mode":"",
       "source":{
           "platform":1,
           "type":1
       },
       "type":"SCREEN_BRIGHTNESS"
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getBrightnessAdjustMode(const char *data, ExportViplexCallback callback);
   /**
   * @brief 设置亮度
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "screenBrightnessInfo":{
           "ratio":0.5
       }
   }
   * @param ExportViplexCallback callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenBrightness(const char *data, ExportViplexCallback callback);
   /**
   * @brief 获取亮度
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093"
   }
   * @param ExportViplexCallback callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getScreenBrightness(const char *data, ExportViplexCallback callback);
   /**
   * @brief 获取亮度调整策略
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "brightnessPolicyInfo":{
           "isSupportCompleteCron":false
       }
   }
   * @param ExportViplexCallback callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getBrightnessPolicy(const char *data, ExportViplexCallback callback);
   /**
   * @brief 设置定时亮度策略
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "taskInfo":{
       }
   }
   其中taskInfo具体内容参考getBrightnessPolicy接口返回值
   * @param ExportViplexCallback callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setBrightnessPolicy(const char *data, ExportViplexCallback callback);
   /**
 * @brief 获取环境亮度
 * @param const char * data
 {
     "sn":"";
 }
 * @param ExportViplexCallback callBack
 {
     "value":1000
 }
 * @returnVIPLEX_EXPORT void
 */
   VIPLEX_EXPORT void getEnvironmentBrightness(const char *data, ExportViplexCallback callBack);
#pragma endregion LightController 显示屏亮度&环境亮度
   /**
 * @brief 手动设置亮度
 * @param const char * data
 {
	 "sn":"BZSA07194A0049999716";
	 "ratio":60.0;
 }
 * @returnVIPLEX_EXPORT void
 */
   VIPLEX_EXPORT void setManualBrightnessFor0x99(const string &data, ExportViplexCallback callback);
   /**
 * @brief 设置亮度调节方案
 * @param const char * data
 {
       "sn":"BZWA17422J1X20000093",
       "taskInfo":
	   {
			"source": {
				"type": 1,
				"platform": 1
			},
			"taskArray": [{
				"type": "POLICY_BRIGHTNESS",
				"orderId": 12356,
				"action": 4,
				"data": {
					"enable": true,
					"conditions": [{
							"type": 2,
							"cron": ["0 15 10 ? * *"],
							"args": [12000, 20, 80, 40, 10],
							"segments": [{
									"environmentBrightness": 12000,
									"screenBrightness": 80
								},
								{
									"environmentBrightness": 10000,
									"screenBrightness": 60
								}
							],
							"opticalFailureInfo": {
								"enable": true,
								"screenBrightness": 30
							},
							"startTime": "2017-09-01 00:00:00",
							"endTime": "4016-06-06 23:59:59",
							"enable": true
						},
						{
							"type": 1,
							"cron": ["0 15 10 ? * *"],
							"args": [30],
							"enable": true,
							"startTime": "2017-09-01 00:00:00",
							"endTime": "4016-06-06 23:59:59"
						}
					],
					"segmentConfig": {
						"args": [12000, 20, 80, 40, 10],
						"segments": [{
								"environmentBrightness": 12000,
								"screenBrightness": 80
							},
							{
								"environmentBrightness": 10000,
								"screenBrightness": 60
							}
						],
						"opticalFailureInfo": {
							"enable": true,
							"screenBrightness": 30
						}
					},
					"timeStamp": "2018-07-19 11:27:15"
				}
			}]
       }
 }
 * @returnVIPLEX_EXPORT void
 */
   VIPLEX_EXPORT void setPolicyBrightnessFor0x99(const string &data, ExportViplexCallback callback);
#pragma region TemperatureController
   /**
  * @brief 获取色温
  * @param const char * data 格式如：
  {
      "sn":"BZSA07194A0049999716"
  }
  * @param ExportViplexCallback callback
  {
      "colorTemperature":6500
  }
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void getColorTemperature(const char *data, ExportViplexCallback callback);
   /**
   * @brief 设置色温
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "colorTemperatureInfo":{
           "colorTemperature":12
       }
   }
   * @param ExportViplexCallback callback，返回空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setColorTemperature(const char *data, ExportViplexCallback callback);
#pragma endregion TemperatureController 温度&色温 待补充 （获取箱体温度）

#pragma region SwitchController
   /**
   * @brief 设置屏体电源模式
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "taskInfo":{
           "mode":"MANUALLY"
       }
   }
   * @param ExportViplexCallback callback 返回空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenPowerMode(const char *data, ExportViplexCallback callback);
   /**
   * @brief 获取屏体电源模式
   * @param const char * data 格式如：
   {
      "sn":"BZSA79353N1310006847"
   }
   * @param ExportViplexCallback callback，格式如;
   {
       "mode":"MANUALLY",
       "source":{
           "platform":1,
           "type":1
       },
       "type":"SCREENPOWER"
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getScreenPowerMode(const char *data, ExportViplexCallback callback);
   /**
   * @brief 打开或者关闭屏体电源
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "taskInfo":{
           "state":"open"
       }
   }
   * @param ExportViplexCallback callback,返回空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenPowerState(const char *data, ExportViplexCallback callback);
   /**
   * @brief 获取电源状态
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093"
   }
   * @param ExportViplexCallback callback，返回格式如：
   {
       "state":"UNKNOW"
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getScreenPowerState(const char *data, ExportViplexCallback callback);
   /**
   * @brief  获取屏体电源定时策略
   * @param const char * data 格式如：
   {
        "sn":"BZWA17422J1X20000093"
   }
   * @param ExportViplexCallback callback，返回格式如：
   {
       "conditions":[

       ],
       "enable":false,
       "source":{
           "platform":1,
           "type":1
       },
       "type":"SCREENPOWER"
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getScreenPowerPolicy(const char *data, ExportViplexCallback callback);
   /**
   * @brief 屏体电源定时调节
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "taskInfo":{
           "type":"SCREENPOWER",
           "source":{
               "type":0,
               "platform":1
           },
           "enable":true,
           "conditions":[
               {
                   "cron":[
                       "0 15 10 ? * *",
                       "0 0 12 * * ?"
                   ],
                   "action":"OPEN",
                   "enable":true
               },
               {
                   "cron":[
                       "0 15 10 ? * *",
                       "0 0 12 * * ?"
                   ],
                   "action":"CLOSE",
                   "enable":true
               }
           ]
       }
   }
   * @param ExportViplexCallback callback，返回值为空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenPowerPolicy(const char *data, ExportViplexCallback callback);
#pragma endregion SwitchController 开关屏管理
   /**
   * @brief 立即开关屏
   * @param const char * data 格式如：
   {
	   "sn":"BZWA17422J1X20000093",
	   "taskInfo":{
		   {
			"source": {
				"type": 1,
				"platform": 1
			},
			"taskArray": [{
				"type": "SCREEN_POWER_MANUAL",
				"orderId": 12356,
				"action": 4,
				"data": {
					"state": "OPEN"
				}
			}]
			}
	   }
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenPowerManual0x99(const char *data, ExportViplexCallback callback);
   /**
   * @brief 定时开关屏状态
   * @param const char * data 格式如：
   {
	   "sn":"BZWA17422J1X20000093",
	   "taskInfo":{
				"source": {
					"type": 1,
					"platform": 1
				},
				"taskArray": [{
					"type": "SCREEN_POWER_POLICY",
					"orderId": 12356,
					"action": 4,
					"data": {
						"enable": true,
						"conditions": [{
							"cron": ["0 15 10 ? * *", "0 0 12 * * ?"],
							"action": "OPEN",
							"enable": true
						}, {
							"cron": ["0 0 18 ? * *", "0 0 12 * * ?"],
							"action": "CLOSE",
							"enable": true
						}
						]
					}
				}
				]
			}
	   }
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenPowerPolicy0x99(const char *data, ExportViplexCallback callback);
   /**
   * @brief 获取开关屏状态
   * @param const char * data 格式如：
   {
	   "sn":"BZWA17422J1X20000093",
	   "taskInfo":{
				"source":{
					"type":1,
					"platform":1
				},
				"taskArray":[
					{
						"type":"SCREEN_POWER_MANUAL",
						"orderId":12356,
						"action":5,
						"data":null
					}
				]
			}
	   }
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void GetScreenPowerManual0x99(const char *data, ExportViplexCallback callback);
   /**
   * @brief 获取定时开关屏命令
   * @param const char * data 格式如：
   {
	   "sn":"BZWA17422J1X20000093",
	   "taskInfo":{
				"source":{
					"type":1,
					"platform":1
				},
				"taskArray":[
					{
						"type":"SCREEN_POWER_POLICY",
						"orderId":12356,
						"action":5,
						"data":null
					}
				]
			}
	   }
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void GetScreenPowerPolicyFor0x99(const char *data, ExportViplexCallback callback);
   
	  
	   
	   

#pragma region FileManager
#pragma endregion FileManager 系统文件管理 待开发

#pragma region ListManager
#pragma endregion ListManager 清单管理 待补充（党巾涛）

#pragma region AdvancedFeatures
   /**
  * @brief 设置同步播放开关
  * @param const char * data
  * {
  *    "sn":"",
  *    "enable":true
  * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void setSyncPlay(const char *data, ExportViplexCallback callBack);

   /**
  * @brief 获取同步播放配置
  * @param const char * data
   *{
   *    "sn":""
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void getSyncPlay(const char *data, ExportViplexCallback callBack);


   /**
  * @brief 恢复出厂设置
  * @param const char * data
  *"sn":"",
    *    "setInfo":{
    *        "reason":"terminal connect failed"
    *    }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void setReBootWipeUserData(const char *data, ExportViplexCallback callBack);

   /**
  * @brief 清除所有媒体
  * @param const char * data
   *{
   *    "sn":"",
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void clearAllMedias(const char *data, ExportViplexCallback callBack);

   /**
  * @brief OTG USB 状态获取
  * @param const char * data
      * {
      *    "sn":"",
      * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void getOTGUSBMode(const char *data, ExportViplexCallback callBack);

   /**
  * @brief OTG USB 切换  获取
   * {
    *    "sn":"",
    *    "modeInfo":{
    *        "value":1.0    //value  double  USB是否可用，1表示USB不可用，2表示USB可用，adb可调式
    *    }
  * @param const char * data
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void setOTGUSBMode(const char *data, ExportViplexCallback callBack);

   /**
  * @brief 设置当前分辨率
  * @param const char * data
   * @param options
    * {
    *    "sn":"",
    *    "resolutionInfo":{
    *        "displayMode":1,   //displayMode    int 显示模式，默认 DISPLAY_INTERFACE_TV
    *        "resolutionValue":"1280X720p-60"
    *    }
    * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void setCurrentResolutio(const char *data, ExportViplexCallback callBack);

   /**
  * @brief 获取当前分辨率
  * @param const char * data
    * {
    *    "sn":"",
    *    "requestInfo":{
    *        "displayMode":1    //displayMode    int 显示模式，默认 DISPLAY_INTERFACE_TV
    *    }
    *
    *
    * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void getCurrentResolution(const char *data, ExportViplexCallback callBack);

   /**
  * @brief 获取终端所支持的分辨率
  * @param const char * data
  * {
   *    "sn":"",
   *    "requestInfo":{
   *        "displayMode":1    //displayMode    int 显示模式，默认 DISPLAY_INTERFACE_TV
   *    }
   *
   *
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
  * @returnVIPLEX_EXPORT void
  */
   VIPLEX_EXPORT void getSupportedResolution(const char *data, ExportViplexCallback callBack);

   /**
	* @brief HDMI切换-获取终端的输出状态
	* @param const string & data
	{
		"sn":""
	}
	* @param ViplexCallback callBack
	* @return void
	*/
   VIPLEX_EXPORT void getHdmiOutputStatus(const char *data, ExportViplexCallback callBack);

   /**
   * @brief HDMI切换-获取终端的输出状态
   * @param const string & data
   {
	   "value":1
   }
   * @param ViplexCallback callBack
   * @return void
   */
   VIPLEX_EXPORT void setHdmiOutputStatus(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 设置自定义分辨率
   * @param const string & data
   {
	   "displayMode":1
	   "width":1920，
	   "height":1080
   }
   * @param ViplexCallback callBack
   * @return void
   */
   VIPLEX_EXPORT void setCustomResolution(const char *data, ExportViplexCallback callBack);
#pragma endregion AdvancedFeatures 高级特性 

#pragma region AcquisitionReceiver
   /**
    * showdoc
    * @catalog 接口示例/采集器接收器
    * @title 获取采集接收器配置
    * @description 获取采集接收器配置的接口
    * @method
    * @url void nvGetPickerReceiver(const char *data, ExportViplexCallback callback)
    * @json_param {"sn":"BZWA17422J1X20000093"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"pickers":[{"period":1000,"pickType":"PERIOD","receivers":[{"outputDestination":"TCP_NET_WORK","persistent":false}],"type":"CPU_USAGE"}]}
    * @return_param code int 错误码：`0`获取成功
    * @return_param pickers objectArray 采集器列表
    * @return_param period long 采集周期，单位为毫秒，当为周期性采集时才有效
    * @return_param pickType string PERIOD：表示的是周期性采集，AUTO：表示的是自动的，根据这种类型的具体实现。
    * @return_param receivers object 关联的接收器
    * @return_param outputDestination string FILE：表示采集到文件，TCP_NET_WORK：表示的是自动的，根据这种类型的具体实现，CONSOLE：控制台，如终端的控制台，一般用户调试
    * @return_param persistent bool true：表示持久的，即当断电，上电依然有效，false：表示只添加到内存的
    * @return_param type string CPU_USAGE：cpu使用率，CPU_TERMPATURE：cpu温度，MEMORY_USAGE：内存使用率，WIFI_STATE_CHANGED：wifi状态变化
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getPickerReceiver(const char *data, ExportViplexCallback callBack);
#pragma endregion AcquisitionReceiver 采集器接收器 待开发

#pragma region USBVPlay
#pragma endregion USBVPlay U盘相关协议 待开发

#pragma region UpgradeManager
   /**
    * showdoc
    * @catalog 接口示例/升级管理/搜索可用升级包
    * @title 搜索本地指定文件目录下的升级包
    * @description 搜索本地指定文件目录下的升级包的接口
    * @method
    * @url void nvQueryUpdateFileByType(const char *data, ExportViplexCallback callback)
    * @json_param "{"paths":["C:/Users/Public/viplexcore/fileundertest/test2"],"types":["*.nuzip"],"pageIndex" : 0,"pageSize" : 100}"
    * @param paths 必选 指定搜索的文件夹路径
    * @param types 必选 指定搜索的文件后缀名
    * @param pageIndex 必选 当前页数
    * @param pageSize 必选 最大页数
    * @return "{"error_code":0, "data":{"files":["C:/Users/Public/viplexcore/fileundertest/test2/ViPlex Express V1.10.0.0302 Setup.nuzip","C:/Users/Public/viplexcore/fileundertest/test2/ViPlex Express V1.10.0.0601.nuzip"]}}"
    * @return_param code int 错误码：0
    * @return_param files 搜索到的文件的绝对路径
    * @remark
    * @number 99
    */
   void queryUpdateFileByType(const char *data, ExportViplexCallback callBack);

    /**
    * showdoc
    * @catalog 接口示例/升级管理/搜索线上升级包
    * @title 获取线上可用的升级包
    * @description 获取线上可用的升级包的接口
    * @method
    * @url void nvGetOnlineUpgradeFile(const char *data, ExportViplexCallback callback)
    * @json_param "{"productName":"T2"}"
    * @param productName 必选 产品类型
    * @return "{"code": 0, "data": {"onlineUpdatePackageInfos":[{"url":"http://static.vnnox.com/cn/vnnox_system/product_upgrade/accessory/UPDATE_OS_T1T2_TAURUSV020101CN0601.nuzip","type":"NEWEST","version":"TAURUSV020101CN0601","size":300213139,"md5":"7673ec78e817e7b19963738d9b6f6d2b"},{"url":"http://static.vnnox.com/cn/vnnox_system/product_upgrade/accessory/UPDATE_OS_T3T4_TAURUSV020101CN0601.nuzip","type":"STABLE","version":"TAURUSV020501CN0501","size":3012146482,"md5":"7673ec78e817e7b19963738d9b6f6d2b"}]}}"
    * @return_param code int 错误码：0
    * @return_param onlineUpdatePackageInfos Object JSON对象
    * @return_param url 线上升级包下载链接
    * @return_param type 升级版版本类型 稳定版 "STABLE"  最新版 "NEWEST"
    * @return_param version 升级包版本号
    * @return_param size 升级包大小（字节）
    * @return_param md5 升级包md5码
    * @remark `code int 错误码：0 获取成功; 65370 获取线上升级包失败; 65376 网络连接异常` result string 返回信息，返回值示例和字段描述详见**返回示例**和**返回参数说明**
    * @number 99
    */
   void getOnlineUpgradeFile(const char *data, ExportViplexCallback callBack);
   /**
    *  下载升级包
    * @param options
    *{
    *    "url":"/",
    *    "targetAddress":""
    *
    *
    *
    * }
    * @param jsCallback
    *
    */
   void downloadUpgradeFile(const char *data, ExportViplexCallback callBack);
   /**
    *  停止升级包下载
    * @param options
    *{
    *
    *
    *
    *
    *
    * }
    * @param jsCallback
    *
    */
   void stopDownloadUpgradeFile(const char *data, ExportViplexCallback callBack);
   /**
    * 从zip 中读取
    * @param options
    *{
    *    "zipFilePath":"/",
    *    "dFileName":"package_description.json"
    *
    *
    *
    * }
    * @param jsCallback
    *
    */
   void readFileContentFromZipFile(const char *data, ExportViplexCallback callBack);
   /**
   * 升级 OS
   * @param options
   * {
   *    "sn":"",
   *    "filePath":"/mnt/sdcard/viplex_terminal/",
   * }
   * @param Callback（result，error，progress）
   */
   void updateApp(const char *data, ExportViplexCallback callBack);
   /**
   * 升级 OS
   * @param options
   * {
   *    "sn":"",
   *    "filePath":"/mnt/sdcard/viplex_terminal/",
   * }
   * @param Callback（）
   */
   void updateOS(const char *data, ExportViplexCallback callBack);
   /**
    * 停止当前正在执行的升级接口
    * {
    *    "sn":""
    *
    * }
    * @param Callback （result，error）
    */
   void stopCurrentUpdateTask(const char *data, ExportViplexCallback callBack);
   /**
    * 升级可行性判断参数
    * @param options
    * {
    *    "sn":"",
    *    "verifyInfo":{
    *   "version": "TAURUSV010300CN1701",
    *   "totalSize": 279077363,
    *   "description": "TAURUSV010300CN1701",
    *   "packetType": "SINGLE",
    *   "excutionType": "UPDATE",
    *   "createdDate": "2018-08-10T21:04:23Z+08:00",
    *   "packages": [
    *     {
    *       "type": "OS",
    *       "version": "TAURUSV010300CN1701",
    *       "name": "TAURUSV010300CN1701.zip",
    *       "identifier": "VEFVUlVTVjAxMDMwMENOMTcwMS56aXA=",
    *       "size": 279077363,
    *       "startupAfterInstalled": true,
    *       "isUpgradeAppAfterOS":true,
    *       "supportedProducts": ["T1","T2"],
    *       "supportedPlatforms":["rk3368","rk312x"]
    *     }
    *   ]
    * }
    *
    *
    * }
    * @param jsCallback
    */
   VIPLEX_EXPORT void updateVerify(const char *data, ExportViplexCallback callBack);
#pragma endregion UpgradeManager 升级 待修改类名（张鹏程）

#pragma region 网络配置
   /**
* @brief 扫描wifi列表
* @param const char * data 格式如：
* {
*   "sn":"BZSA07194A0049999716"
* }
* @param ExportViplexCallback callback,成功返回json格式的wifi列表
* @returnVIPLEX_EXPORT void
*/
   VIPLEX_EXPORT void getWifiList(const char *data, ExportViplexCallback callback);

   /**
	* @brief 连接指定wifi
	* @param const char * data 格式如：
	*{
	*    "sn":"BZSA07194A0049999716",
	*    "taskInfo":{
	*        "ssid":"AP10006847",
	*        "password":"12345678"
	*    }
	*}
	* @param ExportViplexCallback callback 成功时，返回为空
	* @returnVIPLEX_EXPORT void
	*/
   VIPLEX_EXPORT void connectWifiNetwork(const char *data, ExportViplexCallback callback);

   /**
   * @brief 获取当前WIFI状态 AP/Station
   * @param const char * data 格式如：
   *{
   *   "sn":"BZSA07194A0049999716"
   *}
   * @param ExportViplexCallback callback，成功返回的json格式如：
   {
       "taskArray":[
           {
               "action":5,
               "data":{
                   "state":0
               },
               "errorCode":0,
               "status":1,
               "type":"WIFI_AP_STATION_SWITCH"
           }
       ]
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getWifiCurrentStatus(const char *data, ExportViplexCallback callback);

   /**
   * @brief 断开wifi连接
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "taskInfo":{
           "ssid":"AP10006847"
       }
   }
   * @param ExportViplexCallback callback，成功返回空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void disconnectWifiNetwork(const char *data, ExportViplexCallback callback);

   /**
   * @brief 检测wifi是否开启
   * @param const char * data 格式如：
   {
       "sn":"BZSA07194A0049999716"
   }
   * @param ExportViplexCallback callback，格式如：
   {
       "state":1
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getWifiEnabled(const char *data, ExportViplexCallback callback);

   /**
   * @brief 打开或关闭wifi
   * @param const char * data 格式如：
   {
       "sn":"BZSA07194A0049999716",
       "taskInfo":{
           "state":1
       }
   }
   * @param ExportViplexCallback callback，返回空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setWifiEnabled(const char *data, ExportViplexCallback callback);

   /**
   * @brief Wifi -忘记密码
   * @param const char * data 格式如：
   {
   "sn":"BZSA07194A0049999716",
   "taskInfo":{
       "ssid":"AP10006847"
   }
}
    * @param ExportViplexCallback callback，返回空
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void sendForgetWifiCommand(const char *data, ExportViplexCallback callback);

   /**
   * @brief 获取移动网络配置
   * @param const char * data 格式如：
   {
       "sn":"BZSA07194A0049999716",
       "taskInfo":{
           "ssid":"AP10006847"
       }
   }
   * @param ExportViplexCallback callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getMobileNetwork(const char *data, ExportViplexCallback callback);

   /**
   * @brief 配置移动网络参数
   * @param const char * data 格式如：
   {
       "sn":"BZSA07194A0049999716",
       "mobileData":{
           "basicConfigs":{
               "mobileData":true,
               "dataRoaming":true,
               "enable4G":true
           },
           "advanced":{
               "networkType":"AUTO",
               "APN":{
                   "providerName":"中国移动"
               }
           }
       }
   }
   * @param ExportViplexCallback callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setMobileNetwork(const char *data, ExportViplexCallback callback);

   /**
   * @brief 检测4G模块是否存在
   * @param const char * data 格式如：
   {
       "sn":"BZSA07194A0049999716"
   }
   * @param ExportViplexCallback callback，
   {
       "existed":false
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void isMobileModuleExisted(const char *data, ExportViplexCallback callback);

   /**
   * @brief 获取有线网络配置
   * @param const char * data 格式如：
   {
       "sn":"BZSA07194A0049999716"
   }
   * @param ExportViplexCallback callback
   {
       "ethernets":[
           {
               "dhcp":true,
               "dns":[
                   "172.16.0.201",
                   "172.16.0.202"
               ],
               "gateWay":"172.16.9.254",
               "ip":"172.16.9.192",
               "mask":"255.255.255.0",
               "name":"eth0",
               "scopeId":-1
           }
       ]
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getEthernetInfo(const char *data, ExportViplexCallback callback);

   /**
   * @brief 设置有线网络配置
   * @param const char * data 设置时确保ip地址正确，参考getEthernetInfo接口，并且格式如：
   {
       "sn":"BZSA07194A0049999716",
       "taskInfo":{
           "ethernets":[
               {
                   "scopeId":-1,
                   "name":"eth0",
                   "dhcp":true,
                   "ip":"172.16.9.192",
                   "mask":"255.255.255.0",
                   "gateWay":"172.16.9.254",
                   "dns":[
                       "172.16.0.201",
                       "172.16.0.202"
                   ]
               }
           ]
       }
   }
   * @param ExportViplexCallback callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setEthernetInfo(const char *data, ExportViplexCallback callback);

   /**
   * @brief 获取wifi 热点信息
   * @param const char * data 格式如：
   {
       "sn":"BZSA07194A0049999716"
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getAPNetwork(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 设置WIFI-AP配置信息
   * @param const char * data 格式如：
       {
       "sn":"BZSA07194A0049999716",
       "aliasName":"AP",
       "suffix":"0016",
       "password":"12345678",
       "channelId":10
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setAPNetwork(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取AP的开启状态
   * @param const string & data 格式如：
       {
           "sn":""
       }
   * @param ViplexCallback callBack
   * @return void
   */
   VIPLEX_EXPORT void getAPNetworkOpenStatus(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 设置AP开启状态
   * @param const char * data 格式如：
       {
            "sn":"",
           "enable":true
       }
   * @param ViplexCallback callBack
   * @return void
   */
   VIPLEX_EXPORT void setAPNetworkOpenStatus(const char * data, ExportViplexCallback callBack);

   /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 获取APN信息
    * @description 获取APN信息
    * @method
    * @url void nvGetAPNInfoAsync(const char *data, ExportViplexCallback callBack)
    * @json_param {"sn":"BZSA07194A0049999716"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"APNs":[{"carrier":"Orange FR-MMS","mcc":"208","mnc":"01","apn":"orange.acte","user":"orange","password":"orange","server":"*","port":"80","mmsc":"http://mms.orange.fr","mmsproxy":"192.168.010.200","mmsport":"8080","type":"mms","isUserDefined":false,"isUsed":true},{"carrier":"中国移动彩信 (China Mobile)","mcc":"460","mnc":"00","apn":"cmwap","server":"*","proxy":"10.0.0.172","mmsc":"http://mmsc.monternet.com","mmsproxy":"10.0.0.172","mmsport":"80","type":"mms","protocol":"IPV4V6","isUserDefined":false,"isUsed":true}]}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param APNs Object APN列表
    * @return_param carrier string APN名称，可为空，只用来显示apn列表中此apn的显示名字
    * @return_param mcc string 由三位数组成。 用于识别移动用户的所在国家
    * @return_param mnc string 由两位或三位组成。 用于识别移动用户的归属PLMN
    * @return_param apn string APN网络标识（接入点名称），是APN参数中的必选组成部分。此标识由运营商分配
    * @return_param user string 用户名称
    * @return_param password string 密码
    * @return_param server string 服务器地址
    * @return_param proxy string 代理服务器的地址
    * @return_param port string 代理服务器的端口
    * @return_param mmsc string MMS中继服务器/多媒体消息业务中心，是彩信的交换服务器
    * @return_param mmsproxy string 彩信代理服务器的地址
    * @return_param mmsport string 彩信代理服务器的端口号
    * @return_param type string apn的接入点类型
    * @return_param protocol string 支持的协议，不配置默认为IPV4
    * @return_param authtype string apn的认证协议
    * @return_param roamingProtocol string Apn漫游协议
    * @return_param isUserDefined boolean 是否用户自定义
    * @return_param isUsed boolean 是否正在使用
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getAPNInfo(const char *data, ExportViplexCallback callBack);

   /**
   * showdoc
   * @catalog 接口示例/网络配置/WIFI-AP
   * @title 设置APN信息
   * @description 设置APN信息
   * @method
   * @url void nvSetAPNInfoAsync(const char *data, ExportViplexCallback callBack)
   * @json_param {"sn":"BZSA17313J0820001562","APNs":[{"carrier":"Orange FR-MMS","mcc":"208","mnc":"01","apn":"orange.acte","user":"orange","password":"orange","server":"*","port":"80","mmsc":"http://mms.orange.fr","mmsproxy":"192.168.010.200","mmsport":"8080","type":"mms","isUserDefined":false,"isUsed":true},{"carrier":"中国移动彩信 (China Mobile)","mcc":"460","mnc":"00","apn":"cmwap","server":"*","proxy":"10.0.0.172","mmsc":"http://mmsc.monternet.com","mmsproxy":"10.0.0.172","mmsport":"80","type":"mms","protocol":"IPV4V6","isUserDefined":false,"isUsed":true}]}
   * @param sn string 产品唯一序列号
   * @param APNs object Apn信息列表
   * @param carrier tring APN名称，可为空，只用来显示apn列表中此apn的显示名字
   * @param mcc string 由三位数组成。用于识别移动用户的所在国家
   * @param mnc string 由两位或三位组成。用于识别移动用户的归属PLMN
   * @param apn string APN网络标识（接入点名称），是APN参数中的必选组成部分。此标识由运营商分配
   * @param user string 用户名称
   * @param password string 密码
   * @param server string 服务器地址
   * @param proxy string 代理服务器的地址
   * @param port string 代理服务器的端口
   * @param mmsc string MMS中继服务器/多媒体消息业务中心，是彩信的交换服务器
   * @param mmsproxy string 彩信代理服务器的地址
   * @param mmsport string 彩信代理服务器的端口号
   * @param type string apn的接入点类型
   * @param protocol string 支持的协议，不配置默认为IPV4
   * @param authtype string apn的认证协议
   * @param roamingProtocol string Apn漫游协议
   * @param isUserDefined boolean 是否用户自定义
   * @param isUsed boolean 是否正在使用
   * @return {"basicConfigs":{"mobileData":true,"dataRoaming":true, "enable4G":true,"level":1}, "advanced":{"networkType":"AUTO", "APN":{ "providerName":"中国移动"}}}
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @return_param data object 返回成功参数
   * @remark
   * @number 99
   */
   VIPLEX_EXPORT void setAPNInfo(const char *data, ExportViplexCallback callBack);

   /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 设置飞行模式开关状态
    * @description 设置飞行模式开关状态
    * @method
    * @url void setFlightMode(const char *data, ViplexCallback callback)
    * @json_param {"sn":"BZSA07194A0049999716","enable":true}
    * @param sn 必选 string 产品唯一序列号
    * @param enable 必选 bool 设置飞行模式开关状态
    * @return {"errorDiscription":"the description that describe the error in detail."}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data object 返回失败的data参数
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void setFlightMode(const char *data, ExportViplexCallback callback);

   /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 获取飞行模式开关状态
    * @description 获取飞行模式开关状态
    * @method
    * @url void getFlightMode(const char *data, ViplexCallback callback)
    * @json_param {"sn":"BZSA07194A0049999716"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"enable":true}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param enable bool 飞行模式开关状态
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void getFlightMode(const char *data, ExportViplexCallback callback);

   /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 获取4G网络状态
    * @description 获取4G网络状态
    * @method
    * @url get4GNetworkStatus(const string &data, ViplexCallback callback)
    * @json_param {"sn":"BZSA07194A0049999716"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"mobileNetState":0,"netType":1}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param mobileNetState int 4G网络状态,1正常2异常0未知（当前连接有线网或WIFI）
    * @return_param netType int 网络类型,0：无网络，1：有线网，2：wifi，3：2G，4：3G,5:4G,6:未知
    * @remark
    * @number 99
    */
   VIPLEX_EXPORT void get4GNetworkStatus(const char *data, ExportViplexCallback callback);
#pragma endregion 网络配置 NetworkConfigurator

#pragma region ScreenConfiguration

   /**
   * @brief 获取配屏信息
   * @param const char * data
   {
       "sn":"";
   }
   * @param ExportViplexCallback callBack
   {
       "screenAttributes":[
       {"id":0,"orders":[0],
           "portNumber":1,
           "scanInfos":[
               {"connectIndex":0,
               "height":256,
               "portIndex":0,
               "width":256,
               "x":0,
               "xInPort":0,
               "y":0,
               "yInPort":0}],
           "screenSource":1,
           "xCount":1,
           "xOffset":0,
           "yCount":1,
           "yOffset":0}
           ]
           }
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getScreenAttribute(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 设置配屏信息
   * @param const char * data

   {
       "sn":"",
       "screenAttributes":[
           {"id":0,
           "orders":[0],
           "portNumber":1,
           "scanInfos":[
               {"connectIndex":0,
               "height":256,
               "portIndex":0,
               "width":256,
               "x":0,
               "xInPort":0,
               "y":0,
               "yInPort":0}],
           "screenSource":1,
           "xCount":1,
           "xOffset":0,
           "yCount":1,
           "yOffset":0}
           ]
           }
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenAttribute(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 接收卡文件配屏（函数内部分别调用getUri，putFile，SetRecvCardFileSetScreen三个接口）
   * @param const char * data
   {
       "sn":"",
       "filePath":"",
       "fileName":""
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void SetRecvCardFile(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取接收卡文件上传路径(SDK内部封装，不对外暴露)
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getUri(const char *data, ExportViplexCallback callBack);
#pragma endregion ScreenConfiguration 配屏 待补充（党巾涛）

#pragma region ICareConfigurator
   /**
* @brief 获取icare配置信息
* @param const char * options
{
    "sn":"",
    "requestInfo":
        {
        "language":"en""        //中文"zh-cn", 英文"en"
        }
}

* @returnVIPLEX_EXPORT void
*/
   VIPLEX_EXPORT void getIcareConfigInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 设置icare配置信息
   * @param const char * options
   {
       "sn":"",
       "requestInfo":
           {
           "state":true,
           "url":"care.novaicare.com",
           "username":"XXX"
            }
   }
   * @param const char * callback
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setIcareConfigInfo(const char *data, ExportViplexCallback callBack);
#pragma endregion ICareConfigurator icare配置

#pragma region CloudConfigurator
#pragma endregion CloudConfigurator 终端cloud配置 待补充

#pragma region MonitorConfigurator
   /**
	 * @brief 获取存储信息
	 * @param const char * data
	 {
		 "sn":"";
	 }
	 * @param ExportViplexCallback callBack
	 {
	 "diskAvailableSize":,
	 "diskTotalSize":,
	 "storageInfos":[
		 {
			 "diskAvailableSize":X ,
			 "diskCriticalSize": X,
			 "diskReserveSize":X ,
			 "diskTotalSize":X ,
			 "type":"LOCAL"
		 }
	 ]
	}
	* @returnVIPLEX_EXPORT void
	*/
   VIPLEX_EXPORT void getAvailableStorageData(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取CPU信息
   * @param const char * data
   {
	   "sn":"";
   }
   * @param ExportViplexCallback callBack
   {
	   "value":10
   }
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getCPUUsage(const char *data, ExportViplexCallback callBack);

   /**
	* @brief 获取CPU温度
	* @param const char * data
	{
		"sn":"";
	}
	* @param ExportViplexCallback callBack
	{
		"value":38.8
	}
	* @returnVIPLEX_EXPORT void
	*/
   VIPLEX_EXPORT void getCPUTemp(const char *data, ExportViplexCallback callBack);

   /**
	* @brief 获取可用内存
	* @param const char * data
	{
		"sn":"";
	}
	* @param ExportViplexCallback callBack
	{
		"value":10
	}
	* @returnVIPLEX_EXPORT void
	*/
   VIPLEX_EXPORT void getAvailableMemory(const char *data, ExportViplexCallback callBack);

   /**
	* @brief 添加采集器
	* @param const char * data 格式如：
	{
		"sn":123,
		 "info":
		 {
			"pickers":[
				{
					"type":"CPU_USAGE",
					"pickType":"PERIOD",
					"period":1000,
					"receivers":[
						{
							"outputDestination":"TCP_NET_WORK",
							"persistent":false
						}
					]
				}
			]
		}
	}
	* @param ViplexCallback callBack
	* @return void
	*/
   VIPLEX_EXPORT void addCollector(const char *data, ExportViplexCallback callBack);

   /**
	* @brief 删除采集器
	* @param const char * data 格式如：
		{
		"sn":123,
		"info":
		 {
			"type":["CPU_USAGE"]
		 }

	}
	* @param ViplexCallback callBack
	* @return void
	*/
   VIPLEX_EXPORT void deleteCollector(const char *data, ExportViplexCallback callBack);

   /**
	 * @brief 获取发送卡监控信息
	 * @param const string & data 格式如：
		 {
			 "sn":""
		 }
	 * @param ViplexCallback callBack
	 * @return void
	 */
   VIPLEX_EXPORT void getSendCardMonitorInfo(const char *data, ExportViplexCallback callBack);

   /**
	 * @brief 获取接收卡数量及信息
	 * @param const string & data 格式如：
		 {
			 "sn":""
		 }
	 * @param ViplexCallback callBack
	 * @return void
	 */
   VIPLEX_EXPORT void getReceiverCountAndInfo(const char *data, ExportViplexCallback callBack);

   /**
	 * @brief 根据接收卡索引获取监控信息
	 * @param const string & data 格式如：
		 {
			 "sn":""
			 "info":
			 {
					"receiveCardRegionInfo": [
						{
							portIndex:0,
							connectedIndex:0
						},
						{
							portIndex:0,
							connectedIndex:1
						}
					]
				}
		 }
	 * @param ViplexCallback callBack
	 * @return void
	 */
   VIPLEX_EXPORT void getMonitorInfoByReceiverIndex(const char *data, ExportViplexCallback callBack);
#pragma endregion MonitorConfigurator 监控 待补充

#pragma region ScreenManager
   /**
* @brief 回读时间
* 获取卡时间
* @param const char * data 格式如：
{
    "sn":"BZSA07194A0049999716"
}
* @param ExportViplexCallback callback，返回格式如：
{
    "currentTime":"2020-02-26 12:31:22",
    "isTimeOffsetEnable":false,
    "timeOffsetValue":0,
    "timeZone":"Europe/London",
    "utcTimeMillis":1582720282873
}
* @returnVIPLEX_EXPORT void
*/
   VIPLEX_EXPORT void getCurrentTimeAndZone(const char *data, ExportViplexCallback callback);

   /**
   * @brief  时间同步
   *  设置卡上的时间
   * @param const char * data 格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "timeZoneInfo":{
           "utcTimeMillis":1234455433,
           "timeZone":"Asia/Shanghai",
           "currentTime":"10-23",
           "gmt":"GMT+08:00",
           "isTimeOffsetEnable":true,
           "beginTime":"5-23",
           "endTime":"12-23",
           "timeOffsetValue":6000
       }
   }
   * @param ExportViplexCallback callback，返回空
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void calibrateTime(const char *data, ExportViplexCallback callback);

   /**
       * @brief 读取网络校时配置
       * @param const char * data 格式如：
       {
           "sn":"BZSA07194A0049999716"
       }
       * @param ExportViplexCallback callBack，返回json格式字符串
       * @returnVIPLEX_EXPORT void
       */
   VIPLEX_EXPORT void getNetTimingInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 设置网络校时
   * @param const char * data 请确保lora不为空，格式如：
   {
       "sn":"BZWA17422J1X20000093",
       "TimingInfo":{
           "enable":true,
           "ntp":{
               "enable":true,
               "server":"http://ntpsss.net"
           },
           "lora":{
               "address":1,
               "channel":23,
               "enable":false,
               "mode":"MASTER",
               "groupId":"novad101"
           },
           "gps":{
               "enable":false
           },
           "compatibility":{
               "supportLoraInfo":true
           }
       }
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setNetTimingInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取时间服务器列表
   * @param const char * data 格式如：""
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getNetTimingListInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 增加对时服务器
   * @param const char * data 格式如：
   {
       "label":"zhangsan",
       "node":"123.123.123"
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void addNetTimingInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 删除对时服务器
   * @param const char * data 格式如：
   {
       "label":"zhangsan",
       "node":"123.123.123"
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void deleteNetTimingInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 修改对时服务器
   * @param const char * data 格式如：
   {
       "oldServer":{
           "label":"zhangsan",
           "node":"123.123.123"
       },
       "newServer":{
           "label":"111",
           "node":"111.111.111"
       }
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void updateNetTimingInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 增加对时服务器
   * @param const string & data 格式如：
   {
       "serverInfo":[
           {
               "label":"zhangsan",
               "node":"123.123.123"
           },
           {
               "label":"zhangsan",
               "node":"123.123.123"
           }
       ]
   }
   * @param ViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void addNetTimingInfoList(const char *data, ExportViplexCallback callBack);

   /**
    * @brief 回读时间
    * 获取卡时间
    * @param const char * data 格式如：
    {
        "sn":"BZSA07194A0049999716"
    }
    * @param ExportViplexCallback callback，返回格式如：
    {
        "currentTime":"2020-02-26 12:31:22",
        "isTimeOffsetEnable":false,
        "timeOffsetValue":0,
        "timeZone":"Europe/London",
        "utcTimeMillis":1582720282873
    }
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void getCurrentTimeAndZone(const char *data, ExportViplexCallback callback);

   /**
    * @brief  时间同步
    *  设置卡上的时间
    * @param const char * data 格式如：
    {
        "sn":"BZWA17422J1X20000093",
        "timeZoneInfo":{
            "utcTimeMillis":1234455433,
            "timeZone":"Asia/Shanghai",
            "currentTime":"10-23",
            "gmt":"GMT+08:00",
            "isTimeOffsetEnable":true,
            "beginTime":"5-23",
            "endTime":"12-23",
            "timeOffsetValue":6000
        }
    }
    * @param ExportViplexCallback callback，返回空
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void calibrateTime(const char *data, ExportViplexCallback callback);
   
   /**
    * @brief  获取是否夏令时
    *  获取是否夏令时
    * @param const char * data 格式如：
    {
		"sn":"BZSA07194A0049999716",
		"isUseDayLightTimeData":
		{
			"timeZone":"Asia/Shanghai",
			"gmt" : "GMT+08:00"
		}
	}

    * @param ExportViplexCallback callback，返回空
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void getIsUseDayLightTime(const char *data, ExportViplexCallback callback);
   
#pragma region ScreenShot 
   /**
	* @brief获取终端截图
	* @param const string & data
	* {
	*     "sn":"",
	*     "width":11,
	*     "height":22,
	*     "downLoadDirectoryPath":"",
	*     "pictureName":"",
	*     "pictureType":0
	* }
	* @param ViplexCallback callback只有如下三种情况会进行回调：
	1.参数不正确，无法解析
	2.请求成功
	3.请求失败
	* @return void
	*/
   VIPLEX_EXPORT void downLoadScreenshot(const char *data, ExportViplexCallback callBack);
#pragma endregion ScreenShot 截屏

#pragma endregion ScreenManager 屏体其他项
   /**
   * @brief 屏幕旋转设置
   * @param const char * data 格式如：
   {
		"sn": "BZSA79353N1310006847",
		"source": {
			"type": 1,
			"platform": 1
		},
		"taskArray": [{
			"type": "ROTATION",
			"action": 4,
			"data": {
				"rotationValue": 1
			}
		}]
	}
   * @param ExportViplexCallback callback，格式如;
   {
		"source": {
			"type": 1,
			"platform": 1
		},
		"taskArray": [{
			"type": "ROTATION",
			"action": 4,
			"status": 1,
			"errorCode": 0
		}]
	}
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setRotation(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 回读旋转设置
   * @param const char * data 格式如：
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"ROTATION",
				"action":5
			}
		]
	}
   * @param ExportViplexCallback callback，格式如;
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"ROTATION",
				"action":5,
				"status":1,
				"data":{
					"rotationValue":1,
				}
			}
		]
	}
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getRotation(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 屏幕尺寸获取
   * @param const char * data 格式如：
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"DISPLAY_INFO",
				"action":5
			}
		]
	}
   * @param ExportViplexCallback callback，格式如;
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"DISPLAY_INFO",
				"action":5,
				"status":1,
				"data":{
					"width":400,
					"height":400,
					"rotation":0,
				}
			}
		]
	}
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getDisplayInfo(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 清理媒体
   * @param const char * data 格式如：
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"TIME_AND_ZONE",
				"orderId":12356,
				"action":1,
				"data":{
					"utcTimeMillis":1234455433,
					"timeZone":"Asia/Shanghai",
					"gmt":"GMT+08:00",
					"isTimeOffsetEnable":true,
					"beginTime":"5-23",
					"endTime":"12-23",
					"timeOffsetValue":+6000
					}
			}
		]
	}
   * @param ExportViplexCallback callback，格式如;
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"TIME_AND_ZONE",
				"orderId":12356,
				"action":1,
				"status":1,
				"errorCode":0
			}
		]
	}
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setTimeAndZone(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 截图（此接口为vnnox使用，使用时，TCP要下发"width":256,"height":256,"type":"PNG"）
   * @param const char * data 格式如：
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"SCREEN_SHOT",
				"orderId":12356,
				"action":4,
				"data":{
				 "uploadOssInfo"{
				   "accessid":"eMYWoIbIam9NsYRC",
				   "host":"https://novacloud-test.oss-cn-hangzhou.aliyuncs.com",
				   "policy":"eyJleHBpcmF0aW9uIjoiMjAxOS0xMS0yMVQwOTo0OTowMFoiLCJjb5nZSIsMCwxMDQ4NTc2=",
				   "signature":"xt/XaiwvkNe3q2KlIRGN63iQSoI=",
				   "expire":1574300940,
				   "callback":"eyJjYWxsYmFja1VybCI6Imh0dHA6XC9cL3Rlc3QtcmVzdC52bm5veC5m9ybV",
				   "dir":"CheckPlatform/"
				},
				"sessionID":"h0dHA6XC9cL3Rlc3QtcmVzdC52bm5veC5m9.jpg"
			   }
			}
		]
	}
   * @param ExportViplexCallback callback，格式如;
   {
		"source":{
			"type":1,
			"platform":1
		},
		"taskArray":[
			{
				"type":"SCREEN_SHOT",
				"orderId":12356,
				"action":4,
				"status":1,
				"errorCode":0
			}
		]
	}
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setScreenShot(const char *data, ExportViplexCallback callBack);

#pragma region 其他

   /**
   * @brief 获取接收卡温度信息
   * @param const char * data
   {
       "sn":"";
   }
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getScreenUnitTemp(const char *data, ExportViplexCallback callBack);

#pragma region DataBaseMigration
   /**
* @brief 数据迁移
* @param const char * data
* {
* "data":
* [{
*	"ID":"",
*	 "PLAYSOLUTION":"",
*	 "PLAYSOLUTIONRELATION":"",
*	"SCHEDULECONSTRAINT"："",
*	"PLAYLIST"："",
*	"PLAN":"",
*	"Width":"",
*	"Height":""
* }]
* }
* @param ExportViplexCallback
* @param callBack
* @returnVIPLEX_EXPORT void
*/
   void dataBaseMigration(const char *data, ExportViplexCallback(callBack));
#pragma endregion DataBaseMigration 数据迁移

#pragma region PlayManager

   /**
   * @brief 获取节目清单
   * @param const char * data
   *{
   *	"sn":""
   *}
   * @param ExportViplexCallback callBack
   *{
   *"programInfos" : [
   *	{
   *		"identifier":"62932662fb727f42d695201aa91e32c8",
   *		"name": "PlayLists1",
   *		"thumbnailUrl": "program_868679025220684_1/program_thumb.png",
   *		"statusCode": 1,
   *		"source": 0
   *	},
   *	{
   *		"identifier":"62932662fb727f42d695201aa91e32c8",
   *		"name": "PlayLists2",
   *		"thumbnailUrl": "program_868679025220684_2/program_thumb.png",
   *		"statusCode": 1,
   *		"source": 1
   *	}
   *]
   *}
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getProgramInfo(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 删除节目清单
   * @param const char * data
   *{"sn":"",
   *"taskInfo":
   *		{"solutions":
   *				[{
   *				"name":"dangjintao",
   *				"identifier":"ccdc78e192d8d97bfd01c82881038a39"}
   *				]}
   *		}
   *}
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void deletePlayList(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 开始播放
   * @param const char * data
   *{
   *	"sn":"",
   *	"identifier":""
   *}
   * @param ExportViplexCallback callBack
   *无返回数据局，当返回失败时，存放失败错误码，详情请参考错误码定义
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void startPlay(const char *data, ExportViplexCallback callBack);


   /**
   * @brief 暂停播放
   * @param const char * data
   *	{
   *	"sn":"",
   *	"identifier":""
   *}
   * @param ExportViplexCallback callBack
   *无返回数据局，当返回失败时，存放失败错误码，详情请参考错误码定义
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void pausePlay(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 恢复播放
   * @param const char * data
       {
       "sn":"",
       "identifier":""
       }
   * @param ExportViplexCallback callBack
   *无返回数据局，当返回失败时，存放失败错误码，详情请参考错误码定义
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void resumePlay(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取缩略图文件，下载到本地指定目录中
   *{
   *    "sn":"",
   *    "remotePathsAndFileNames":{"":"","":""},
   *    "downLoadDirectoryPath":"",
   *    "fileType":".png"
   *}
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void downLoadFiles(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 通过指定类型所搜文件//文件搜索
   *{
   *  “paths”:[""],可以指定多个路径
   *  "types":[".txt"],//支持多条件搜索 结果按照类型区分
   *  "pageIndex":0,
   *  "pageSize":100,
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void queryFileByType(const char *data, ExportViplexCallback callBack);
#pragma endregion PlayManager  节目播放

#pragma region EditProgram
   /**
   * @brief 创建节目
   * {
   *    "name":"",
   *    "width":400,
   *    "height":400
   * }
   * @return
   */
   VIPLEX_EXPORT void createProgram(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 设置page信息
   * {
   *   "programID":""
   *   "pageID":11,
   *   "pageInfo":{}
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setPageParam(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 生成节目
   * {
   *    "outPutPath":""
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void makeProgram(const char *data, ExportViplexCallback callBack);
   /**
   *@brief 配置默认系统模板
   * {
   *  "data":[
   *       {
   *         width: 0.5,
   *         height: 0.5,
   *         left: 0.5,
   *         top:: 0.5,
   *         zindex: 0,
   *         },
   *       {
   *         width: 0.5,
   *         height: 0.5,
   *         left: 0.5,
   *         top:: 0.5,
   *         zindex: 0,
   *       }
   *  ]
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void setSystemTplInfo(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 添加模板
   *{
   *     data:[
   *        {
   *         width: 0.5,
   *         height: 0.5,
   *         left: 0.5,
   *         top:: 0.5,
   *         zindex: 0,
   *        }
   *    ]
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @return
   */
   VIPLEX_EXPORT void addTpl(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 编辑模板
    * {
    *       tplID: 1,
    *       data:[
    *        {
    *         width: 0.5,
    *         height: 0.5,
    *         left: 0.5,
    *         top:: 0.5,
    *         zindex: 0,
    *        }
    *      ]
    * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @return
   */
   VIPLEX_EXPORT void editTpl(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 删除模板
   * {
   *    tplID: 1,
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @return
   */
   VIPLEX_EXPORT void deleteTpl(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取本地节目
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void getProgram(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 删除节目列表
   * {
   *   "programID":""
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void deleteProgram(const char *data, ExportViplexCallback callBack);
   /**
   * @brief 发布节目
   * @param options
   * {
   *  "sn":"",
   *  "sendProgramFilePath":"",
   *  "programName":"",
   *  "deviceIdentifier":"",
   *  "startPlayAfterTransferred":true
   * “insertPlay”：true
   * }
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void startTransferProgram(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 结束节目传输
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void stopProgramTransfer(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取模板列表
   * @param ViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   void getCustomerTpl(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 获取文件MD5码
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @returnVIPLEX_EXPORT void
   */
   void getFileMD5(const char *data, ExportViplexCallback callBack);

   /**
   * @brief 音频媒体
   * @param const char * data
   * @param ExportViplexCallback callBack
   * @return void
   */
   void setAudioMedioProgram(const char *data, ExportViplexCallback callBack);
#pragma endregion EditProgram 节目编辑

#pragma region feedback
   /**
    * 用户反馈
    *  {
    *      "sn":"",
    *      "contact":"minyf@novastar.tech",
    *      "description":"我的意见反馈描述双卡双待的",
    *      "attacheds":[
    *          {
    *              "dir":"feedback/handy/20200301/abc.jpg"
    *          },
    *          {
    *              "dir":"feedback/handy/20200301/abc.zip"
    *          }
    *      ]
    *  }
    * @param Callback （result，error）
    */
   VIPLEX_EXPORT void uploadFeedbackInfo(const char *data, ExportViplexCallback callBack);

   VIPLEX_EXPORT void uploadFeedBackFileState(const char *data, ExportViplexCallback callBack);
#pragma endregion feedback 用户反馈

#pragma region StatusCollector
   /**
   * @brief获取内存信息
   * @param const char * data
   * {
   *     "sn":"",
   *     "period":XXX
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void startGetAvailableMemoryData(const char *data, ExportViplexCallback callBack);
   /**
   * @brief结束信息采集
   * @param const char * data
   * {
   *     "sn":"",
   *     "type":""
   * }
   * @param ExportViplexCallback callback只有如下三种情况会进行回调：
   1.参数不正确，无法解析
   2.请求成功
   3.请求失败
   * @returnVIPLEX_EXPORT void
   */
   VIPLEX_EXPORT void finishData(const char *data, ExportViplexCallback callBack);
#pragma endregion StatusCollector

#pragma endregion 其他  待补充

#pragma region Remotemanager


    /**
    * @brief 获取绑定信息
    * @param const char * options
    {
        "sn":""
    }
    * @param const char * callback
    {"baseUrl":"",
     "data":
        {
            "playerList":[{"identifier":"",
                        "isUsed":true,
                        "name":"",
                        "playerIdentifier":""}],
            "token":""
        },
    "isBind":true,
    "password":"",
    "username":""
    }
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void getBindPlayer(const char *data, ExportViplexCallback callBack);

    /**
    * @brief 设置绑定消息
    * @param const char * data
    {"sn":"",
    "playerInfo":
            {"baseUrl":"",
     "data":
        {
            "playerList":[{"identifier":"",
                        "isUsed":true,
                        "name":"",
                        "playerIdentifier":""}],
            "token":""
        },
    "isBind":true,
    "password":"",
    "username":""
        }
    }
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void setBindPlayer(const char *data, ExportViplexCallback callBack);

    /**
    * @brief 获取播放器列表
    * @param const char * data
    {
        "host":"",
        "data":
            {
                "username":"",
                "password":"",
                "playerType":2
            }
    }
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void getCloudPlayerList(const char *data, ExportViplexCallback callBack);


    /**
    * @brief 获取节点服务器列表
    * @param const char * data
    {
        "sn":""
    }
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void getNodeServerList(const char *data, ExportViplexCallback callBack);

    /**
    * @brief 新增节点
    * @param const char * data
    {
        "serverName":"",
        "serverAddress":""
    }
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void addNodeServerList(const char *data, ExportViplexCallback callBack);

    /**
    * @brief 删除节点
    * @param const char * data
    {
        "serverName":"",
        "serverAddress":""
    }
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void deleteNodeServerList(const char *data, ExportViplexCallback callBack);

    /**
    * @brief 修改节点信息
    * @param const char * data

    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void changeNodeServerList(const char *data, ExportViplexCallback callBack);

    /**
      * @brief 添加节点服务器
      * @param const string & data 格式如：
      {
          "serverInfo":[
              {
                  "label":"zhangsan",
                  "node":"123.123.123"
              },
              {
                  "label":"zhangsan",
                  "node":"123.123.123"
              }
          ]
      }
      * @param ViplexCallback callBack
      * @returnVIPLEX_EXPORT void
      */
   VIPLEX_EXPORT void addNodeServerInfoList(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void isCommonCloud(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void getPlayerIdentifer(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void isExistPlayerName(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void newSetBindPlayer(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void getToken(const char *data, ExportViplexCallback callBack);
#pragma endregion Remotemanager

#pragma region ScreenSetting

    /**
    * @brief 获取重启任务
    * @param const char * data
    {
        "sn":""
    }
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void GetReBootTask(const char *data, ExportViplexCallback callBack);

    /**
    * @brief 设置重启任务
    * @param const char * data
    {
        "sn":"",
        "taskInfo":
                {
                    "type":"REBOOT",
                     "source":{
                                "type":0,
                                "platform":1
                               },
                    "executionType":"IMMEDIATELY",
                    "reason":"Just to test"
                },
        "conditions":[ {"cron":["0 15 10 ? * *", "0 0 12 * * ?"], "enable":true}]}
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void SetReBootTask(const char *data, ExportViplexCallback callBack);


    /**
    * @brief 配屏(SDK内部封装，不对外暴露)
    * @param const char * data
    * @param ExportViplexCallback callBack
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void SetRecvCardFileSetScreen(const char *data, ExportViplexCallback callBack);

    /**
    * @brief 上传文件，通过FTP(SDK内部封装，不对外暴露)
    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void putFile(ns::RecvCardFileData recvCardFileData, const char *data, ExportViplexCallback callBack);


    /**
    * @brief 获取时区列表
    * @param ExportViplexCallback callBack

    * @returnVIPLEX_EXPORT void
    */
   VIPLEX_EXPORT void getTimeZone(const char *data, ExportViplexCallback callBack);
   /**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 指定IP搜索
	* @description 搜索指定IP的屏体
	* @url void nvSearchAppointIpAsync(const char * data, ExportViplexCallback resultCallBack)
	* @json_param {"ip":"172.18.179.243"}
	* @param ip 必选 string 输入指定的IP
	* @return {"sn":"20393844393033","productName":"AX200","width":400,"height":800,"rotation":0,"aliasName":"XianYataScreen","logined":true,"username":["admin"],"tcpPort":16603,"ftpPort":16602,"syssetFtpPort":16604,"syssetTcpPort":16605,"key":"novaStar","platform":"rk3368","privacy":true,"terminalState":0,"ignoreTime":100029432434,"hasPassword":true,"password":"12345678"}
	* @return_param code int 错误码：<br>`0`搜索成功，result即为指定IP搜索返回内容。<br>`65535`搜索超时，代表在4s时间内未能搜索到任何终端
	* @return_param sn string 产品序列号
	* @return_param productName string 产品名称
	* @return_param width int 显示屏宽度, 单位为像素
	* @return_param height int 显示屏高度, 单位为像素
	* @return_param rotation int 旋转角度：0，90，180，270
	* @return_param aliasName string 显示屏别名
	* @return_param logined boolean 是否有人已经登陆
	* @return_param username string_array 若已经有人登陆，代表已经登陆的用户名列表
	* @return_param tcpPort int tcp连接端口
	* @return_param ftpPort int ftp连接端口
	* @return_param syssetFtpPort int 系统设置ftp端口
	* @return_param syssetTcpPort int 系统设置tcp端口
	* @return_param key string 终端返回的key,参与ftp的密码生产规则
	* @return_param platform string 系统平台信息（暂时会出现rk3368, rk312x）
	* @return_param privacy boolean True表示终端支持加密模式，当然如果是新的终端一定是True
	* @return_param password string 密码
	* @return_param terminalState int 当前屏体状态，terminalState共有6个值,分别代表：<br>`0`：未连接任何终端，当前处于未连接状态<br>`1`：连接成功但是未登录状态<br>`2`：被他人登录状态<br>`3`：登录成功状态<br>`4`：密码错误状态<br>`5`：离线状态，处于搜索不到的状态，但是曾经被搜索到过
	* @return_param ignoreTime long 记录点击忽略密码的时间戳
	* @return_param hasPassword boolean 是否记住密码，true表示记住，false，表示没有
	* @remark
	* @number 99
	*/
   VIPLEX_EXPORT void SerchAppointIp(const char * data, ExportViplexCallback resultCallBack);
   /**
	 * showdoc
	 * @catalog 接口示例/搜索连接登录
	 * @title 指定范围IP搜索
	 * @description 搜索指定范围IP的屏体
	 * @url void SerchRangeIp(const char *data, ExportViplexCallback resultCallBack)
	 * @json_param {"ipStart":"172.18.179.1","ipEnd":"172.18.179.255"}
	 * @param data 必选 object 包含ipStart及ipEnd
	 * @param ipStart 必选 string 输入指定的起始ip
	 * @param ipEnd 必选 string 输入指定的终止ip
	 * @return {"sn":"20393844393033","productName":"AX200","width":400,"height":800,"rotation":0,"aliasName":"XianYataScreen","logined":true,"username":["admin"],"tcpPort":16603,"ftpPort":16602,"syssetFtpPort":16604,"syssetTcpPort":16605,"key":"novaStar","platform":"rk3368","privacy":true,"terminalState":0,"ignoreTime":100029432434,"hasPassword":true,"password":"12345678"}
	 * @return_param code int 错误码：<br>`0`搜索成功，result即为指定IP搜索返回内容。<br>`65535`搜索超时，代表在4s时间内未能搜索到任何终端
	 * @return_param sn string 产品序列号
	 * @return_param productName string 产品名称
	 * @return_param width int 显示屏宽度,单位为像素
	 * @return_param height int 显示屏高度,单位为像素
	 * @return_param rotation int 旋转角度：0，90，180，270
	 * @return_param aliasName string 显示屏别名
	 * @return_param logined boolean 是否有人已经登陆
	 * @return_param username string_array 若已经有人登陆，代表已经登陆的用户名列表
	 * @return_param tcpPort int tcp连接端口
	 * @return_param ftpPort int ftp连接端口
	 * @return_param syssetFtpPort int 系统设置ftp端口
	 * @return_param syssetTcpPort int 系统设置tcp端口
	 * @return_param key string 终端返回的key,参与ftp的密码生产规则
	 * @return_param platform string 系统平台信息（暂时会出现rk3368,rk312x）
	 * @return_param privacy boolean True表示终端支持加密模式，当然如果是新的终端一定是True
	 * @return_param password string 密码
	 * @return_param terminalState int 当前屏体状态，terminalState共有6个值,分别代表：<br>`0`：未连接任何终端，当前处于未连接状态<br>`1`：连接成功但是未登录状态<br>`2`：被他人登录状态<br>`3`：登录成功状态<br>`4`：密码错误状态<br>`5`：离线状态，处于搜索不到的状态，但是曾经被搜索到过
	 * @return_param ignoreTime long 记录点击忽略密码的时间戳
	 * @return_param hasPassword boolean 是否记住密码，true表示记住，false，表示没有
	 * @remark
	 * @number 99
	 */
   VIPLEX_EXPORT void SerchRangeIp(const char *data, ExportViplexCallback resultCallBack);
#pragma endregion ScreenSetting

   VIPLEX_EXPORT void downloadTerminalLog(const char *data, ExportViplexCallback callBack);

   VIPLEX_EXPORT void uploadTerminalLog(const char *data, ExportViplexCallback callBack);

   VIPLEX_EXPORT void checkNetwork(const char *data, ExportViplexCallback callBack);

   VIPLEX_EXPORT void cancelFunction(const char *data, ExportViplexCallback callBack);
   VIPLEX_EXPORT void getScreenLogInfo(const char *data, ExportViplexCallback callBack);

   VIPLEX_EXPORT void getScreenDeviceInfo(const char *data, ExportViplexCallback callBack);
   
   VIPLEX_EXPORT void loginVnnox(const char *data, ViplexCallback callback);
   VIPLEX_EXPORT void getVerifyCode(const char *data, ViplexCallback callback);
   VIPLEX_EXPORT void registerVnnox(const char *data, ViplexCallback callback);
}


#pragma once 
#include "exportdefine.h"

#ifdef __cplusplus
extern "C"
{ 
#endif
    /**
     * showdoc
     * @catalog 接口示例/初始化
     * @title （IOS）设置移动端平台类型
     * @description 如果调用方是 ios 系统，则需要调用接口，其他平台忽略此接口
     * @url void nvSetPlatform(const char *platform);
     * @param platform 必选 string 由于ios系统锁屏/后台的特殊机制，因此在udp搜索时需要一些特殊处理<br>填写`ios`即可
     * @return ""
     * @remark
     * @number 99
     */
    VIPLEX_EXPORT void nvSetPlatform(const char *platform);
    /**
    * showdoc
    * @catalog 接口示例/初始化
    * @title SDK初始化
    * @description SDK初始化接口,调用SDK接口前必须调用此接口完成SDK初始化
    * @url int nvInit(const char *sdkRootDir, const char *credentials);
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
    VIPLEX_EXPORT int nvInit(const char *sdkRootDir, const char *credentials);
    VIPLEX_EXPORT void nvSetDevLang(const char *devLang);
	VIPLEX_EXPORT int nvInitExpress(const char *sdkRootDir, const char *credentials);

	VIPLEX_EXPORT void nvPingAsync(ExportViplexCallback  callback);
#pragma region Diagnosis 诊断模块 
#pragma endregion 诊断模块 待开发

#pragma region publicnet 公网配置
    /**
    * showdoc
    * @catalog 接口示例/公网配置
    * @title 公网初始化
    * @description SDK公网初始化接口,调用SDK公网模式接口前必须调用此接口完成公网初始化,设备上线会触发connectCallback回调，设备掉线会触发disconnectCallback回调
    * @url  void nvInitPublicNetAsync(const char* data, ExportViplexCallback connectCallback, ExportViplexCallback disconnectCallback);
    * @json_param {\"publicModule\":true,\"encrypt\":true,\"certificatePath\":\"E:/bin/cert\",\"port\":16603,\"httpserverUrl\":\"http://192.168.1.103:8080\",\"httpserverLocalPath\":\"E:/httpserverpath\"}";
    * @param publicModule 必选 是否使用公网
    * @param encrypt 必选 通道是否加密
    * @param port 必选 tcpserver监听端口号
    * @param certificatePath 可选 选择通道加密时需要指定SSL证书路径,证书在SDKbin/cert路径下
    * @param httpserverUrl 必选 http文件服务器url
    * @param httpserverLocalPath 必选 文件服务器本地地址
    * @return connectCallback 返回json和搜索接口nvSearchTerminalAsync返回信息一致 {"sn":"20393844393033","productName":"AX200","width":400,"height":800,"rotation":0,"aliasName":"XianYataScreen","logined":true,"username":["admin"],"tcpPort":16603,"ftpPort":16602,"syssetFtpPort":16604,"syssetTcpPort":16605,"key":"novaStar","platform":"rk3368","privacy":true,"terminalState":0,"ignoreTime":100029432434,"hasPassword":true,"password":"12345678"}
    * @return_param code int 错误码：<br>`0` 与终端设备建立TCP连接后时返回终端信息，返回结果与nvSearchterminalAsync相同
    * @return_param sn string 产品序列号
    * @return_param productName string 产品名称
    * @return_param width int 显示屏宽度, 单位为像素
    * @return_param height int 显示屏高度, 单位为像素
    * @return_param rotation int 旋转角度 : 0，90，180，270
    * @return_param aliasName string 显示屏别名
    * @return_param logined boolean 是否有人已经登陆
    * @return_param username string_array 若已经有人登陆，代表已经登陆的用户名列表
    * @return_param tcpPort int tcp连接端口
    * @return_param ftpPort int ftp连接端口
    * @return_param syssetFtpPort int 系统设置ftp端口
    * @return_param syssetTcpPort int 系统设置tcp端口
    * @return_param key string 终端返回的key, 参与ftp的密码生产规则
    * @return_param platform string 系统平台信息（暂时会出现rk3368, rk312x）
    * @return_param privacy boolean True表示终端支持加密模式，当然如果是新的终端一定是True
    * @return_param password string 密码
    * @return_param terminalState int 当前屏体状态，terminalState共有6个值, 分别代表：<br>`0`：未连接任何终端，当前处于未连接状态<br>`1`：连接成功但是未登录状态<br>`2`：被他人登录状态<br>`3`：登录成功状态<br>`4`：密码错误状态<br>`5`：离线状态，处于搜索不到的状态，但是曾经被搜索到过
    * @return_param ignoreTime long 记录点击忽略密码的时间戳
    * @return_param hasPassword boolean 是否记住密码，true表示记住，false，表示没有
	* @return disconnectCallback 返回掉线设备的SN和其登陆类型{"loginType":5,"sn":"BZSA58502N0140004965"}
	* @return_param loginType int 登录类型,公网模式下固定为5
	* @return_param sn string 掉线设备的SN号
    * @remark
    * @number 99
    */
	VIPLEX_EXPORT void nvInitPublicNetAsync(const char* data, ExportViplexCallback connectCallback, ExportViplexCallback disconnectCallback);

    /**
    * showdoc
    * @catalog 接口示例/公网配置
    * @title SDK停止公网服务
    * @description 停止公网服务，在使用公网模式时，退出应用前必须调用此接口
    * @method
    * @url void nvStopPublicNetAsync(ViplexCallback callback);
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 失败返回错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvStopPublicNetAsync(ExportViplexCallback callback);

    /**
    * showdoc
    * @catalog 接口示例/公网配置
    * @title 配置终端公网参数
    * @description 配置终端公网参数
    * @method
    * @url void nvSetPublicNetConfigParamAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {"sn":"BZSA07313J0350000975","data":{"host":"192.168.1.100","port":16603,"timeout":10000,"isEncrypt":false}}
    * @param sn 必选 string 产品唯一序列号
    * @param host 必选 string 公网服务器IP
    * @param port 必选 int 公网服务器端口号
    * @param timeout 可选 int 超时时间
    * @param isEncrypt 必选 是否选择加密通道
    * @return
    * @return_param code int 错误码：`0`配置成功
    * @return_param data string ,失败返回错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetPublicNetConfigParamAsync(const char *data, ExportViplexCallback callback);

    /**
    * showdoc
    * @catalog 接口示例/公网配置
    * @title 终端断开公网连接
    * @description 终端断开公网连接
    * @method
    * @url void nvDisconnectPublicNetAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {\"sn\":\"123456\"}
    * @param sn 必选 string 产品唯一序列号
    * @return 
    * @return_param code int 错误码：`0`配置成功
    * @return_param data string ,失败返回错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvDisconnectPublicNetAsync(const char *data, ExportViplexCallback callback);

    /**
    * showdoc
    * @catalog 接口示例/公网配置
    * @title 获取终端公网连接配置
    * @description获取终端公网连接配置
    * @method
    * @url void nvGetPublicNetParamAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {\"sn\":\"123456\"}
    * @param sn 必选 string 产品唯一序列号
    * @return  {\"isBound\":true,\"host\":\"192.168.1.1\",\"port\":80,\"isEncrypt\":true}
     *@return_param code int 错误码：`0`获取成功
    * @return_param isBound bool 终端是否连接服务器
    * @return_param host string 服务器IP
    * @return_param port int 服务器端口
    * @return_param isEncrypt bool 是否加密
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetPublicNetParamAsync(const char *data, ExportViplexCallback callback);

	/**
	* showdoc
	* @catalog 接口示例/公网配置
	* @title 公网模式下获取SDK设备在线列表
	* @description公网模式下获取SDK设备在线列表
	* @method
	* @url void nvGetOnlineDevicesAsync(ExportViplexCallback  callback);
	* @return  ["sn1","sn2"] 返回在线设备sn列表
	 *@return_param code int 错误码：`0`获取成功
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetOnlineDevicesAsync(ExportViplexCallback callback);

#pragma endregion 公网配置

#pragma region PowerManager 多功能卡电源管理 

		/**
	* showdoc
	* @catalog 接口示例/多功能卡电源管理/定时开关电源
	* @title 设置定时电源开关状态
	* @description 设置定时电源开关状态的接口
	* @method
	* @url void nvSetTimingPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"123456","taskInfo":{"type":"FUNCTIONPOWER","source":{"type":1,"platform":1},"data":[{"commands":[{"conditions":[{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"action":0,"type":"power","startTime":"2018-06-06","endTime":"2018-06-07","enable":false,"powerIndex":0,"flag":"abc"},{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"action":1,"type":"power","startTime":"2018-06-06","endTime":"2018-06-07","enable":false,"powerIndex":1,"flag":"abc"}]}],"enable":false,"portIndex":0,"connectIndex":1}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string FUNCTIONPOWER(固定值)
	* @param source 必选 Object 表示任务的发布来源.如:VNNOX,CS,LCT等
	* @param platform 必选 int 表示任务发布来源,1:手机,2;CS,3:平板,4:VNNOX,5;Care,6:LCT
	* @param data 必选 ObjectArray 按照条件执行的多功能卡任务集合
	* @param enable 必选 bool 按条件执行的使能开关.如果为true,则执行conditions中的定时任务,如果为false,则不执行
	* @param portIndex 必选 int 多功能卡的网口地址
	* @param powerIndex 必选 int 多功能卡网口连接的设备编号
	* @param commands 必选 ObjectArray 按照条件执行的任务集合,支持多任务
	* @param conditions 必选 ObjectArray 按照条件执行的任务集合,支持多任务
	* @param cron 必选 StringArray 每个控制方案使用cron表达式数组表示,当有多个cron表达式时,cron表达式之间使用或的关系
	* @param action 必选 int 具体电源控制:0开,1关
	* @param type 必选 string 开关的类型,以字符串的形式表征
	* @param startTime 必选 string 有效时间的开始日期
	* @param endTime 必选 string 有效时间的结束日期
	* @param enable 必选 boolean 按条件执行的使能开关.如果为true,那么此条cron表达式生效,如果为false,则不生效
	* @param powerIndex 必选 int 多功能卡电源的下标(目前支持0-7)
	* @param flag 必选 string 此字段属于VNNOX,手机,CS专用字段
	* @return {"data":"12d4sa654d564ddauioaj4163"}
	* @return_param code int 错误码：`0`获取成功
	* @return_param data string 成功返回md5码,失败返回错误码对应的说明
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetTimingPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
		/**
	* showdoc
	* @catalog 接口示例/多功能卡电源管理/定时开关电源
	* @title 获取定时开关电源状态
	* @description 获取定时开关电源状态的接口
	* @method
	* @url void nvGetTimingPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"123456"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"data":[{"commands":[{"conditions":[{"action":0,"cron":["0 15 10 ? * *","0 0 12 * * ?"],"enable":false,"endTime":"2018-06-07","flag":"abc","powerIndex":0,"startTime":"2018-06-06","type":"power"},{"action":1,"cron":["0 15 10 ? * *","0 0 12 * * ?"],"enable":false,"endTime":"2018-06-07","flag":"abc","powerIndex":1,"startTime":"2018-06-06","type":"power"}]}],"connectIndex":1,"enable":false,"portIndex":0}],"source":{"platform":1,"type":1},"type":"FUNCTIONPOWER"}
	* @return_param code int 错误码：`0`获取成功
	* @return_param data string 成功返回md5码,失败返回错误码对应的说明
	* @return_param type string FUNCTIONPOWER(固定值)
	* @return_param source Object 表示任务的发布来源.如:VNNOX,CS,LCT等
	* @return_param platform int 表示任务发布来源,1:手机,2;CS,3:平板,4:VNNOX,5;Care,6:LCT
	* @return_param data ObjectArray 按照条件执行的多功能卡任务集合
	* @return_param enable bool 按条件执行的使能开关.如果为true,则执行conditions中的定时任务,如果为false,则不执行
	* @return_param portIndex int 多功能卡的网口地址
	* @return_param powerIndex int 多功能卡网口连接的设备编号
	* @return_param commands ObjectArray 按照条件执行的任务集合,支持多任务
	* @return_param conditions ObjectArray 按照条件执行的任务集合,支持多任务
	* @return_param cron StringArray 每个控制方案使用cron表达式数组表示,当有多个cron表达式时,cron表达式之间使用或的关系
	* @return_param action int 具体电源控制:0开,1关
	* @return_param type string 开关的类型,以字符串的形式表征
	* @return_param startTime string 有效时间的开始日期
	* @return_param endTime string 有效时间的结束日期
	* @return_param enable boolean 按条件执行的使能开关.如果为true,那么此条cron表达式生效,如果为false,则不生效
	* @return_param powerIndex int 多功能卡电源的下标(目前支持0-7)
	* @return_param flag string 此字段属于VNNOX,手机,CS专用字段
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetTimingPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
	/**
    * showdoc
    * @catalog 接口示例/多功能卡电源管理/电源实时状态获取
    * @title 获取电源实时状态获取
    * @description 获取电源实时状态的接口
    * @method
    * @url void nvGetRealtimePowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {"sn":"123456"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"source":{"type":1,"platform":1},"current_status_info":[{"portIndex":0,"connectIndex":1,"updatePowerIndexStates":[{"type":"屏体电源","powerIndex:":0,"status":0},{"type":"屏体电源","powerIndex:":1,"status":0},{"type":"屏体电源","powerIndex:":2,"status":0},{"type":"屏体电源","powerIndex:":3,"status":0},{"type":"屏体电源","powerIndex:":4,"status":0},{"type":"屏体电源","powerIndex:":5,"status":0},{"type":"屏体电源","powerIndex:":6,"status":0},{"type":"屏体电源","powerIndex:":7,"status":0}]}]}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 成功返回md5码,失败返回错误码对应的说明
    * @return_param source Object 表示任务的发布来源.如:VNNOX,CS,LCT等
    * @return_param type Object 表示任务的发布来源.如:VNNOX,CS,LCT等
    * @return_param platform int 表示任务发布来源,1:手机,2;CS,3:平板,4:VNNOX,5;Care,6:LCT
    * @return_param current_status_info ObjectArray 多功能卡的各路电源状态
    * @return_param portIndex int 多功能卡的网口地址
    * @return_param connectIndex int 多多功能卡网口连接的设备编号
    * @return_param updatePowerIndexStates ObjectArray 每张多功能卡中各路电源的状态
    * @return_param type string 开关的类型,以字符串的形式表征
    * @return_param powerIndex int 多功能卡电源的下标(目前支持0-7)
    * @return_param status int 0:开,1:关
    * @remark
    * @number 99
    */
	VIPLEX_EXPORT void nvGetRealtimePowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
    /**
     * showdoc
     * @catalog 接口示例/多功能卡电源管理/手动开关电源
     * @title 设置手动电源开关状态
     * @description 设置手动电源开关状态的接口
     * @method
     * @url void nvSetManualPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback)
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
     * @return {"data":"12d4sa654d564ddauioaj4163"}
     * @return_param code int 错误码：`0`获取成功
     * @return_param data string 成功返回md5码,失败返回错误码对应的说明
     * @remark
     * @number 99
     */
    VIPLEX_EXPORT void nvSetManualPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
    /**
     * showdoc
     * @catalog 接口示例/多功能卡电源管理/手动开关电源
     * @title 获取手动电源开关状态
     * @description 获取手动电源开关状态的接口
     * @method
     * @url void nvGetManualPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback)
     * @json_param {"sn":"123456"}
     * @param sn 必选 string 产品唯一序列号
     * @return {"data":[{"conditions":[{"action":1,"powerIndex":0,"type":"屏体电源"},{"action":1,"powerIndex":1,"type":"风扇电源"}],"connectIndex":1,"portIndex":0}],"source":{"platform":1,"type":1},"type":"FUNCTIONPOWER"}
     * @return_param code int 错误码：`0`获取成功
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
    VIPLEX_EXPORT void nvGetManualPowerSwitchStatusAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion 多功能卡电源管理

#pragma region VolumeController 音量调节
    /**
    * showdoc
    * @catalog 接口示例/音量调节
    * @title 获取音量
    * @description 获取音量的接口
    * @method
    * @url void nvGetVolumeAsync(const char * data, ExportViplexCallback  callback)
    * @json_param {"sn": "BZSA17332J0A20002272"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"ratio":75.0}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回data详情
    * @return_param ratio float 音量百分比
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetVolumeAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/音量调节
    * @title 设置音量
    * @description 设置音量的接口
    * @method
    * @url void nvSetVolumeAsync(const char * data, ExportViplexCallback  callback)
    * @json_param {"sn": "BZSA17332J0A20002272","volumeInfo": {"ratio": 10}}
    * @param sn 必选 string 产品唯一序列号
    * @param volumeInfo 必选 Object 请求信息对象
    * @param ratio 必选 float 音量百分比
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data string 返回data详情
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetVolumeAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/音量调节/设置定时音量的方案
	* @title 设置定时音量的方案
	* @description 定时设置音量的的接口
	* @method
	* @url void nvSetTimingVolumeAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA79353N1310006847","data":{"type":"VOLUME","source":{"type":0,"platform":1},"enable":true,"conditions":[{"cron":["0 15 10 ? * *"],"value":50.0,"enable":true,"startTime":"2020-09-01 00:00:00","endTime":"4016-06-06 24:00:00"},{"cron":["0 15 10 ? * *"],"value":0,"enable":true,"startTime":"2020-09-01 00:00:00","endTime":"4016-06-06 24:00:00"}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 固定为"VOLUME"
	* @param type 必选 int `1`nova自己的平台,`0`第三方平台
	* @param platform 必选 int `1`移动终端发来的,`2`表示传统电脑,`3`表示平板,`4`表示web端发来的
	* @param enable 必选 bool 按条件执行的使能开关
	* @param cron 必选 stringarray 重复次数，每条条件使用cron表达式数组表示
	* @param value 必选 float 音量值,0-100
	* @param enable 必选 bool 该条件执行的使能开关
	* @param startTime 必选 string 有效期起始时间yyyy-MM-dd HH:mm:ss
	* @param endTime 必选 string 有效期截止时间yyyy-MM-dd HH:mm:ss
	* @return ""
	* @return_param code int 错误码：`0`获取成功
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetTimingVolumeAsync(const char *data, ExportViplexCallback  callback);
		/**
	* showdoc
	* @catalog 接口示例/音量调节/获取定时音量的方案
	* @title 获取定时音量的方案
	* @description 定时获取音量的的接口
	* @method
	* @url void nvGetTimingVolumeAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA79353N1310006847"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"conditions":[{"value":50.0,"cron":["0 15 10 ? * *"],"enable":true,"endTime":"4016-06-06 24:00:00","startTime":"2020-09-01 00:00:00"},{"value":0.0,"cron":["0 15 10 ? * *"],"enable":true,"endTime":"4016-06-06 24:00:00","startTime":"2020-09-01 00:00:00"}],"enable":true,"source":{"platform":1,"type":1},"type":"VOLUME"}
	* @return_param code int 错误码：`0`获取成功
	* @return_param type string 固定为"VOLUME"
	* @return_param type int `1`nova自己的平台,`0`第三方平台
	* @return_param platform int `1`移动终端发来的,`2`表示传统电脑,`3`表示平板,`4`表示web端发来的
	* @return_param enable bool 按条件执行的使能开关
	* @return_param cron stringarray 重复次数，每条条件使用cron表达式数组表示
	* @return_param value float 音量值,0-100
	* @return_param enable bool 该条件执行的使能开关
	* @return_param startTime string 有效期起始时间yyyy-MM-dd HH:mm:ss
	* @return_param endTime string 有效期截止时间yyyy-MM-dd HH:mm:ss
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetTimingVolumeAsync(const char *data, ExportViplexCallback  callback);

		/**

	* @catalog 接口示例/音量调节/获取定时音量的方案(0x99)
	* @title 获取定时音量的方案(0x99)
	* @description 定时获取音量的接口
	* @method
	* @url void nvGetVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA79353N1310006847"}
	* @param sn 必选 string 产品唯一序列号
	* @return "data":{"ratio":60.0,"orderId":-1}
	* @return_param code int 错误码：`0`获取成功
	* @return_param type float 音量值,0-100
	* @return_param type int 请求ID号
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/音量调节/设置定时音量的方案(0x99)
	* @title 设置定时音量的方案(0x99)
	* @description 定时设置音量的的接口
	* @method
	* @url void nvSetVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"12345678900000","data":{"ratio":60.0}}
	* @param sn 必选 string 产品唯一序列号
	* @param value 必选 float 音量值,0-100
	* @return ""
	* @return_param code int 错误码：`0`获取成功
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/音量调节/设置定时音量的方案(0x99)
	* @title 设置定时音量的方案(0x99)
	* @description 定时设置音量的的接口
	* @method
	* @url void nvSetTimingVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"123456","data":{"enable":true,"conditions":[{"cron":["0 15 10 ? * *"],"value":50.0,"enable":true,"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 24:00:00"},{"cron":["0 15 10 ? * *"],"value":0,"enable":true,"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 24:00:00"}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param enable 必选 bool 按条件执行的使能开关
	* @param cron 必选 stringarray 重复次数，每条条件使用cron表达式数组表示
	* @param value 必选 float 音量值,0-100
	* @param enable 必选 bool 该条件执行的使能开关
	* @param startTime 必选 string 有效期起始时间yyyy-MM-dd HH:mm:ss
	* @param endTime 必选 string 有效期起始时间yyyy-MM-dd HH:mm:ss
	* @return ""
	* @return_param code int 错误码：`0`获取成功
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetTimingVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/音量调节/获取定时音量的方案(0x99)
	* @title 获取定时音量的方案(ox99)
	* @description 定时获取音量的的接口
	* @method
	* @url void nvGetTimingVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA79353N1310006847"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"conditions":[{"cron":["0 15 10 ? * *"],"enable":true,"endTime":"4016-06-06 24:00:00","startTime":"2020-09-01 00:00:00","value":50.0},{"cron":["0 15 10 ? * *"],"enable":true,"endTime":"4016-06-06 24:00:00","startTime":"2020-09-01 00:00:00","value":0.0}],"enable":true,"orderId":-1,"source":{"platform":1,"type":1}}
	* @return_param code int 错误码：`0`获取成功
	* @return_param type int `1`nova自己的平台,`0`第三方平台
	* @return_param platform int `1`移动终端发来的,`2`表示传统电脑,`3`表示平板,`4`表示web端发来的
	* @return_param enable bool 按条件执行的使能开关
	* @return_param value float 音量值,0-100
	* @return_param enable bool 该条件执行的使能开关
	* @return_param startTime string 有效期起始时间yyyy-MM-dd HH:mm:ss
	* @return_param endTime string 有效期起始时间yyyy-MM-dd HH:mm:ss
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetTimingVolumeFor0x99Async(const char *data, ExportViplexCallback  callback);




#pragma endregion VolumeController 音量调节

#pragma region VPNConnection VPN连接管理
    /**
    * showdoc
    * @catalog 接口示例/VPN连接管理
    * @title 获取VPN连接信息
    * @description 获取VPN连接信息的接口
    * @method
    * @url void nvGetVPNConnectInfoAsync(const char *data, ExportViplexCallback  callback)
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
    * @return_param source object 资源信息
    * @return_param type int 类型信息：1：nova，2：第三方平台
    * @return_param platform int 1：vnnox，2：cs软件
    * @return_param vpnInfo object vpn信息
    * @return_param address string vpn地址
    * @return_param isReconnect boolean 是否断线重连
    * @return_param name string vpn名称
    * @return_param password string 密码
    * @return_param protocolType string vpn协议类型
    * @return_param redialInterval int 重拨间隔
    * @return_param redialNumber int 重拨次数
    * @return_param sessionTimeout int 会话时长
    * @return_param sharedSecretKey string 共享秘钥
    * @return_param username string 用户名
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetVPNConnectInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/VPN连接管理
    * @title 设置VPN连接信息
    * @description 设置VPN连接信息的接口
    * @method
    * @url void nvSetVPNConnectInfoAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvSetVPNConnectInfoAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion VPN连接管理 待开发

#pragma region AppManager
    /**
     * showdoc
     * @catalog 接口示例/App管理
     * @title 获取已安装的APP信息
     * @description 获取已安装的APP信息
     * @method
     * @url void nvGetInstalledPackageInfoAsync(const char *data, ExportViplexCallback  callback);
     * @json_param {"sn":"BZSA17332J0A20002272"}
     * @param sn 必选 string 产品唯一序列号
     * @return {"appInfos":[{"packageName":"nova.priv.terminal.syssetting","versionName":"1.0.2.0501","versionCode":102,"label":"systemSetting","isNetWorkPermission":true},{"packageName":"nova.priv.terminal.easypluto","versionName":"1.0.2.0502","versionCode":102,"label":"easypluto","isNetWorkPermission":true}]}
     * @return_param code int 错误码：`0`获取成功`65535`请求超时
     * @return_param packageName string 包名
     * @return_param versionName tring 版本名称
     * @return_param versionCode int	版本编号
     * @return_param label string APP名称
     * @return_param isNetWorkPermission boolean 是否允许访问网络
     * @remark
     * @number 99
     */
    VIPLEX_EXPORT void nvGetInstalledPackageInfoAsync(const char *data, ExportViplexCallback  callback);

    /**
     * showdoc
     * @catalog 接口示例/App管理
     * @title 获取正在运行的APP版本信息
     * @description 获取正在运行的APP版本信息
     * @method
     * @url void nvGetRunningPackageInfoAsync(const char *data, ExportViplexCallback  callback);
     * @json_param {"sn":"BZSA17332J0A20002272"}
     * @param sn 必选 string 产品唯一序列号
     * @return {"appInfos":[{"packageName":"nova.priv.terminal.syssetting","versionName":"1.0.2.0501","versionCode":102,"label":"systemSetting","isNetWorkPermission":true},{"packageName":"nova.priv.terminal.easypluto","versionName":"1.0.2.0502","versionCode":102,"label":"easypluto","isNetWorkPermission":true}]}
     * @return_param code int 错误码：`0`获取成功`65535`请求超时
     * @return_param packageName string 包名
     * @return_param versionName tring 版本名称
     * @return_param versionCode int	版本编号
     * @return_param label string APP名称
     * @return_param isNetWorkPermission boolean 是否允许访问网络
     * @remark
     * @number 99
     */
    VIPLEX_EXPORT void nvGetRunningPackageInfoAsync(const char *data, ExportViplexCallback  callback);

    /**
     * showdoc
     * @catalog 接口示例/App管理
     * @title 停止运行APP
     * @description 停止运行APP
     * @method
     * @url void nvForceStopAppAsync(const char *data, ExportViplexCallback  callback);
     * @json_param {"sn":"BZSA17332J0A20002272","packageName":"nova.priv.terminal.screenService"}
     * @param sn 必选 string 产品唯一序列号
     * @param packageName 必选 string 要停止app的包名称
	 * @return {"data":"success"}
     * @return_param code int 错误码：`0`获取成功`65535`请求超时
     * @remark
     * @number 99
     */
    VIPLEX_EXPORT void nvForceStopAppAsync(const char *data, ExportViplexCallback  callback);

    /**
     * showdoc
     * @catalog 接口示例/App管理
     * @title 卸载安卓程序
     * @description 卸载安卓程序
     * @method
     * @url void nvUninstallPackageAsync(const char *data, ExportViplexCallback  callback);
     * @json_param {"sn":"BZSA17332J0A20002272","packageName":"nova.priv.terminal.screenService"}
     * @param sn 必选 string 产品唯一序列号
     * @param packageName 必选 string 要卸载app的包名称
	 * @return {"data":"success"}
     * @return_param code int 错误码：`0`获取成功`65535`请求超时
     * @remark
     * @number 99
     */
    VIPLEX_EXPORT void nvUninstallPackageAsync(const char *data, ExportViplexCallback  callback);


    /**
    * showdoc
    * @catalog 接口示例/App管理
    * @title 安装APP
    * @description 安装APP
    * @method
    * @url void nvStartUploadApkCoreAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {"sn":"BZSA58503N1X30005257","taskInfo":{"isLocal":false,"source":{"platform":2,"type":0},"tasks":[{"checkFeasibility":false,"executionType":"IMMEDIATELY","packageType":"AUTO","source":"/sdcard/Download/nova.priv.hand.easypluto_3.2.1.0401_412.apk","startupAfterBoot":false,"startupAfterInstalled":false,"updateType":"UPDATE","version":""}],"type":"UPDATE"}}
    * @param sn 必选 string 产品唯一标识号
    * @param taskInfo 必选 Object 升级详细信息
    * @param type 必选 string 固定为"UPDATE" 字段
    * @param tasks 必选 objectArray 升级任务
    * @param packageType 必选 string APP:表示可执行的应用程序,如apk或exe;OS:非差分包的操作系统包类型;OS_DIF:操作系统差分包类型;FPGA:FPGA固件应用程序;NUZIP:nova压缩包的类型;AUTO:自动类型
    * @param version 非必选 string 对于FPGA和操作系统只有当升级的版本大于等于当前版本时，则升级，否则不会升级。
    * @param executionType 必选 string IMMEDIATELY:立即，BY_CONDITIONS:定时，按照条件升级。
    * @param size 非必选 long 文件的大小，单位为字节
    * @param md5 非必选 string 表示要传输文件的md5码
    * @param updateType 必选 string UPDATE:升级，REPLACE:替换。
    * @param startupAfterInstalled 必选 bool 安装完是否立即启动，true：安装完成后立即启动，false：安装完成后不启动
    * @param startupAfterBoot 必选 bool 开机是否启动，true：开机完成后立即启动，false：开机完成后不启动
    * @param conditions object 非必选 立即升级的此项为空
    * @param start 非必选 string 有效范围，起始时间
    * @param cron 非必选 stringArray 触发条件，cron表达式数组，可以有多个，当为多个时，则使用或的关系。
    * @param end 非必选 string 有效范围，结束时间
    * @param source 非必选 string 对于局域网为存放的路径，对于公网为下载地址
    * @param checkFeasibility 非必选 bool 是否检查升级可行性，目前仅用于nuzip升级包检测
	* @return {"data":"success"}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @remark
    * @number 10
    */
    VIPLEX_EXPORT void nvStartUploadApkCoreAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion AppManager APP管理

#pragma region PlayLogger 播放日志
    /**
    * showdoc
    * @catalog 接口示例/播放日志/播放日志路径获取
    * @title 播放日志路径获取
    * @description 播放日志路径获取的接口
    * @method
    * @url void nvGetPlaylogPathAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"123456"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"logList":["2020-07-13.json"],"url":"/sdcard/nova/viplex_terminal/play_log"}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param logList stringArray 播放日志文件名集合
    * @return_param url string 播放日志目录路径
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetPlaylogPathAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion 播放日志 待开发

#pragma region PlayFont 字体
    /**
     * showdoc
     * @catalog 接口示例/字体
     * @title 获取终端支持的字体
     * @description 获取终端支持的字体的接口
     * @method
     * @url void nvGetTerminalFontAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvGetTerminalFontAsync(const char *data, ExportViplexCallback  callback);
    /**
     * showdoc
     * @catalog 接口示例/字体
     * @title 删除字体
     * @description 删除字体的接口
     * @method
     * @url void nvDeleteFontAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvDeleteFontAsync(const char *data, ExportViplexCallback  callback);
    /**
     * showdoc
     * @catalog 接口示例/字体
     * @title 更新字体
     * @description 更新字体的接口
     * @method
     * @url void nvUpdateFontAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvUpdateFontAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion 字体 待开发

#pragma region 生产功能测试
#pragma endregion 生产功能测试 待开发

#pragma region LEDSplicer 多屏拼接
	/**
	 * showdoc
	 * @catalog 接口示例/多屏拼接
	 * @title 获取拼接参数
	 * @description 获取多屏拼接参数的接口
	 * @method
	 * @url void nvGetSpliceInfoAsync(const char *data, ExportViplexCallback  callback)
	 * @json_param {"sn":"BZSA17332J0A20002272"}
	 * @param sn 必选 string 产品唯一序列号
	 * @return {"height":0,"isScale":false,"offsetX":0,"offsetY":0,"order":0,"orderNum":0,"videoSource":0,"width":0}
	 * @return_param order int 拼接屏的顺序
	 * @return_param width int 播放窗口宽度
	 * @return_param height int 播放窗口高度
	 * @return_param offsetX int 视频源x偏移量
	 * @return_param offsetY int 视频源y偏移量
	 * @return_param videoSource int 视频源:内部0,HDMI1
	 * @return_param orderNum int 拼接数量
	 * @return_param isScale bool 是否缩放,true为全屏缩放,false为不缩放
	 * @return_param code int 错误码：`0`获取成功`65535`请求超时
	 * @remark
	 * @number 99
	 */
	VIPLEX_EXPORT void nvGetSpliceInfoAsync(const char *data, ExportViplexCallback  callback);
	/**
   * showdoc
   * @catalog 接口示例/多屏拼接
   * @title 设置拼接参数
   * @description 设置多屏拼接参数的接口
   * @method
   * @url void void nvSetSpliceInfoAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"","SpliceInfo":{"height":400,"isScale":false,"offsetX":0,"offsetY":0,"order":0,"orderNum":0,"videoSource":0,"width":400}}
   * @param sn 必选 string 产品唯一序列号
   * @param order 必选 int 拼接屏的顺序
   * @param width 必选 int 播放窗口宽度
   * @param height 必选 int 播放窗口高度
   * @param offsetX 必选 int 视频源x偏移量
   * @param offsetY 必选 int 视频源y偏移量
   * @param videoSource 必选 int 视频源:内部0,HDMI1
   * @param orderNum int 必选 拼接数量
   * @param isScale bool 必选 是否缩放,true为全屏缩放,false为不缩放
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvSetSpliceInfoAsync(const char *data, ExportViplexCallback  callback);

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
	* @url void nvGetSupportSensorInfoAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZWA17422J1X20000093"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"sensorInfos":[{"baudRate":115200,"connected":false,"functionId":10,"previewUnit":100,"previewValue":"-1000.0","sensorId":85,"vendor":1,"vendorAliasName":"NovaStar"},{"baudRate":115200,"connected":false,"functionId":6,"previewUnit":60,"previewValue":"-1000.0","sensorId":86,"vendor":1,"vendorAliasName":"NovaStar"}]}
	* @return_param code int 错误码：`0`获取成功
	* @return_param sensorInfos objectArray 传感器信息
	* @return_param functionId int 功能ID
	* @return_param vendor int 厂商
	* @return_param sensorId int 传感器ID
	* @return_param baudRate int 传感器波特率
	* @return_param connected boolean 是否连接
	* @return_param vendorAliasName String 厂商别名字,NovaStar,Nenghui,JXCT
	* @return_param previewValue String 检测到的传感器的值,默认无效值:-1000.0
	* @return_param previewUnit int 检测时传入的数值单位,0:默认单位,1:用户自定义其他单位
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetSupportSensorInfoAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/传感器子板
	* @title 配置传感器的连接选项
	* @description 配置传感器的连接选项的接口
	* @method
	* @url void nvSetSupportSensorInfoAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"isUpgradeSensorProgram":true,"sensorInfos":[{"functionId":10,"vendor":1,"sensorId":85,"baudRate":115200,"vendorAliasName":"NovaStar","previewValue":"-1000.0","previewUnit":100,"connected":true},{"functionId":6,"vendor":1,"sensorId":86,"baudRate":115200,"vendorAliasName":"NovaStar","previewValue":"-1000.0","previewUnit":60,"connected":true}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param taskInfo 必选 Object 设置信息
	* @param isUpgradeSensorProgram 非必选 bool true,上位机支持传感器预览数据回读,false不支持
	* @param sensorInfos 必选 ObjectArray 传感器信息
	* @param functionId 必选 int 功能ID
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
	VIPLEX_EXPORT void nvSetSupportSensorInfoAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion Sensor 传感器子板 待开发

#pragma region ExternalDelivery
#pragma endregion ExternalDelivery 外投调节 待开发

#pragma region RadioFrequency
	/**
		* showdoc
		* @catalog 接口示例/射频管理
		* @title 获取Lora信息
		* @description 获取Lora信息
		* @method
		* @url void nvGetLoraInfoAsync(const char *data, ExportViplexCallback  callback)
		* @json_param {"sn":"BZSA17332J0A20002272"}
		* @param sn 必选 string 产品唯一序列号
		* @return {"exist":true,"frequency":433,"power":1,"version":1,"channel":23,"baudRate":9600,"transSpeed":2.4,"workState":0,"modelNum":1}
		* @return_param code int 错误码：0 获取成功，65535 请求超时
		* @return_param exist boolean 模块是否存在
		* @return_param frequency float 频率(单位：mhz)
		* @return_param power float 功率(单位：w)
		* @return_param version int 版本
		* @return_param channel float 信道
		* @return_param baudRate int 波特率
		* @return_param transSpeed float 空中速率(k/bps)
		* @return_param workState String 工作模式
		* @return_param modelNum int 模块型号
		* @remark
		* @number 99
		*/
	VIPLEX_EXPORT void nvGetLoraInfoAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion RadioFrequency 射频管理  待补充

#pragma region PowerController
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置手动多功能卡电源控制任务
    * @description 设置手动多功能卡电源控制任务的接口
    * @method
    * @url void nvSetPowerInfoManualAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvSetPowerInfoManualAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置定时多功能电源控制任务
    * @description 设置定时多功能电源控制任务的接口
    * @method
    * @url void nvSetPowerInfoPolicyAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":[{"conditions":[{"action":0,"cron":["00 33 14 * * ? *"],"enable":true,"endTime":"4016-06-06","flag":"a2fa3a07-e0da-94b107ff","powerIndex":0,"startTime":"2020-08-28","type":"屏体电源"},{"action":1,"cron":["30 33 14 * * ? *"],"enable":true,"endTime":"4016-06-06","flag":"a2fa3a07-e0da-94b107ff","powerIndex":0,"startTime":"2020-08-28","type":"屏体电源"}],"enable":true,"portIndex":0,"connectIndex":0}]}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 设置信息
    * @param conditions 必选 ObjectArray 按照条件执行的任务集合，支持多任务
    * @param action 必选 int 具体电源控制。0：开、1：关
    * @param cron 必选 StringArray 每个控制方案使用cron表达式数组表示，当有多个cron表达式时，cron表达式之间使用或的关系
    * @param type 必选 string 开关的类型，以字符串的形式表征
    * @param startTime 必选 string 有效时间的开始日期
    * @param endTime 必选 string 有效时间的结束日期
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
    VIPLEX_EXPORT void nvSetPowerInfoPolicyAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取定时多功能电源控制任务
    * @description 获取定时多功能电源控制任务的接口
    * @method
    * @url void nvGetPowerInfoPolicyAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvGetPowerInfoPolicyAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取多功能卡电源状态
    * @description  获取多功能卡电源状态的接口
    * @method
    * @url void nvGetPowerInfoStatusAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvGetPowerInfoStatusAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制模式
    * @title 设置终端电源模式
    * @description 设置终端电源模式的接口
    * @method
    * @url void nvSetPowerModeAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"mode":"1"}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 设置信息
    * @param mode 必选 string 电源的模式。1：定时，0：手动
    * @return ""
    * @return_param code int 错误码：`0`获取成功
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetPowerModeAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制模式
    * @title 获取终端电源模式
    * @description 获取终端电源模式的接口
    * @method
    * @url void nvGetPowerModeAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvGetPowerModeAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置本板电源手动控制任务
    * @description 设置本板电源手动控制任务的接口
    * @method
    * @url void nvSetRelayPowerManualAsync(const char *data, ExportViplexCallback  callback);
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
    VIPLEX_EXPORT void nvSetRelayPowerManualAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 设置本板电源定时控制任务
    * @description 设置本板电源定时控制任务的接口
    * @method
    * @url void nvSetRelayPowerPolicyAsync(const char *data, ExportViplexCallback  callback);
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
    VIPLEX_EXPORT void nvSetRelayPowerPolicyAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取本板电源定时控制任务
    * @description 获取本板电源定时控制任务的接口
    * @method
    * @url void nvGetRelayPowerPolicyAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvGetRelayPowerPolicyAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 获取本板电源状态
    * @description 获取本板电源状态的接口
    * @method
    * @url void nvGetRelayPowerStatusAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvGetRelayPowerStatusAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/终端电源控制/终端电源控制
    * @title 配置本板电源状态
    * @description 配置本板电源状态的接口
    * @method
    * @url void nvSetRelayPowerStatusAsync(const char *data, ExportViplexCallback  callback);
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
    VIPLEX_EXPORT void nvSetRelayPowerStatusAsync(const char *data, ExportViplexCallback  callback);

#pragma endregion PowerController 终端电源控制 待开发

#pragma region VideoSourceController
	/**
	 * showdoc
	 * @catalog 接口示例/视频源控制
	 * @title 获取当前视频源
	 * @description 获取当前视频源
	 * @method
	 * @url void nvGetVideoControlInfoAsync(const char *data, ExportViplexCallback  callback);
	 * @json_param {"sn":"BZSA17332J0A20002272"}
	 * @param sn 必选 string 产品唯一序列号
	 * @return {"type":"VIDEO_SOURCE_SWITCH","source":{"type":1,"platform":1},"videoMode":1,"videoSource":0,"isScale":false,"offsetX":0,"offsetY":0,"conditions":[{"cron":"0 0 12 ? * *","source":0,"enable":true},{"cron":"0 0 12 ? * *","source":1,"enable":true}]}
	 * @return_param code int 错误码：`0`获取成功`65535`请求超时
	 * @return_param type String 固定值："VIDEO_SOURCE_SWITCH"
	 * @return_param source object 下发命令的来源
	 * @return_param type int 1：nova自己的平台，0：第三方平台
	 * @return_param platform int 0：未知，1：移动终端发来的（如手机），2：表示传统电脑，3：表示平板，4：表示web端发来的，5：终端本身
	 * @return_param videoMode int 模式，HDMI优先 0，手动 1， 定时 2
	 * @return_param videoSource int 视频源 SOURCE_INSIDE:内部,0;SOURCE_HDMI:HDMI,1,该字段只对手动模式下有用
	 * @return_param isScale boolean 是否缩放，true为全屏缩放，false为不缩放
	 * @return_param offsetX int 偏移X
	 * @return_param offsetY int 偏移Y
	 * @return_param conditions object 任务列表
	 * @return_param cron String cron表达式,表示开始时间和重复
	 * @return_param source int 视频源,SOURCE_INSIDE:内部,0;SOURCE_HDMI:HDMI,1
	 * @return_param enable boolean	该条定时任务是否生效
	 * @remark
	 * @number 99
	 */

	VIPLEX_EXPORT void nvGetVideoControlInfoAsync(const char *data, ExportViplexCallback  callback);
	/**
	 * showdoc
	 * @catalog 接口示例/视频源控制
	 * @title 设置当前视频源
	 * @description 设置当前视频源
	 * @method
	 * @url void nvSetVideoControlInfoAsync(const char *data, ExportViplexCallback  callback);
	 * @json_param {"sn":"BZSA17332J0A20002272", "videdSourceInfo":{"type":"VIDEO_SOURCE_SWITCH","source":{"type":1,"platform":1},"videoMode":1,"videoSource":0,"isScale":false,"offsetX":0,"offsetY":0,"conditions":[{"cron":"0 0 12 ? * *","source":0,"enable":true},{"cron":"0 0 12 ? * *","source":1,"enable":true}]}}
	 * @param sn 必选 string 产品唯一序列号
	 * @param type 必选 string 固定值："VIDEO_SOURCE_SWITCH"
	 * @param source 必选 object 下发命令的来源
	 * @param type 必选 int 1：nova自己的平台,0：第三方平台
	 * @param platform 必选 int 0：未知，1：移动终端发来的(如手机)，2：表示传统电脑，3：表示平板，4：表示web端发来的，5：终端本身
	 * @param videoMode 必选 int 模式，HDMI优先:0,手动:1,定时:2
	 * @param videoSource 必选 int 视频源,SOURCE_INSIDE:内部,0;SOURCE_HDMI:HDMI,1,该字段只对手动模式下有用
	 * @param isScale 必选 boolean	是否缩放，true为全屏缩放，false为不缩放
	 * @param offsetX 必选 int 偏移X
	 * @param offsetY 必选 int 偏移Y
	 * @param conditions 必选 object 任务列表
	 * @param cron 必选 string cron表达式，用户表示开始时间和重复
	 * @param source 必选 int 视频源,SOURCE_INSIDE:内部,0;SOURCE_HDMI:HDMI,1
	 * @param enable 必选 boolean 该条定时任务是否生效
	 * @return {"data":"success"}
	 * @return_param code int 错误码：`0`获取成功`65535`请求超时
	 * @remark
	 * @number 99
	 */
	VIPLEX_EXPORT void nvSetVideoControlInfoAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/视频源控制/外源分辨率控制
	* @title 设置外源分辨率
	* @description 设置外源分辨率的接口
	* @method
	* @url void nvSetVideoEDIDAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"width":1920,"height":1080,"fieldRate":50}}
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
	VIPLEX_EXPORT void nvSetVideoEDIDAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/视频源控制/外源分辨率控制
	* @title 获取外源分辨率
	* @description 获取外援分辨率的接口
	* @method
	* @url void nvGetVideoEDIDAsync(const char *data, ExportViplexCallback  callback)
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
	VIPLEX_EXPORT void nvGetVideoEDIDAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/视频源控制/获取视频源状态(0x99)
	* @title 获取视频源状态(0x99)
	* @description 获取视频源状态接口
	* @method
	* @url void nvGetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA79353N1310006847"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"enable":true,"isScale":false,"offsetX":0,"offsetY":0,"orderId":-1,"videoMode":0,"videoSource":0}
	* @return_param code int 错误码：`0`获取成功
	* @return_param enable bool 使能开关
	* @return_param isScale bool 是否缩放，true为全屏缩放，false为不缩放
	* @return_param offsetX int 偏移X
	* @return_param offsetY int 偏移Y
	* @return_param orderId int 命令的唯一标识
	* @return_param videoMode int 模式，HDMI优先:0,手动:1,定时:2
	* @return_param videoSource int 视频源,SOURCE_INSIDE:内部,0;SOURCE_HDMI:HDMI,1
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/视频源控制/设置视频源状态(0x99)
	* @title 设置视频源状态(0x99)
	* @description 设置视频源状态接口
	* @method
	* @url void nvSetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param{"sn":"BZVA28407N3X20008006","data":{"videoSource":0}}
	* @param sn 必选 string 产品唯一序列号
	* @param videoSource 必选 int 视频源,SOURCE_INSIDE:内部,0;SOURCE_HDMI:HDMI,1
	* @return {"code":0}
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetVideoSourceManualFor0x99Async(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/视频源控制/获取视频源状态(0x99)
	* @title 获取视频源状态(0x99)
	* @description 获取视频源状态(0x99)接口
	* @method
	* @url void nvGetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA79353N1310006847"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"conditions":[{"cron":"0 0 12 ? * *","enable":true,"source":0},{"cron":"0 0 12 ? * *","enable":true,"source":1}],"enable":true,"isScale":false,"offsetX":0,"offsetY":0,"orderId":-1,"videoMode":0,"videoSource":0}
	* @return_param code int 错误码：`0`获取成功
	* @return_param conditions objectArray 按照条件执行的任务集合,支持多任务
	* @return_param enable bool 使能开关
	* @return_param source int 视频源,SOURCE_INSIDE:内部,0,SOURCE_HDMI:HDMI,1
	* @return_param enable bool 使能开关
	* @return_param isScale bool 是否缩放,true为全屏缩放,false为不缩放
	* @return_param offsetX int 偏移X
	* @return_param offsetY int 偏移Y
	* @return_param orderId int 命令的唯一标识
	* @return_param videoMode int 模式，HDMI优先:0;手动:1;定时:2
	* @return_param videoSource int 视频源,SOURCE_INSIDE:内部,0;SOURCE_HDMI:HDMI,1
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/视频源控制/设置定时视频源状态(0x99)
	* @title 设置定时视频源状态(0x99)
	* @description 设置定时视频源状态接口
	* @method
	* @url void nvSetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZVA28407N3X20008006","data":{"enable":true,"conditions":[{"cron":"0 0 12 ? * *","source":0,"enable":true},{"cron":"0 0 12 ? * *","source":1,"enable":true }]}}
	* @param sn 必选 string 产品唯一序列号
	* @param conditions 必选 objectArray 按照条件执行的任务集合，支持多任务
	* @param enable 必选 bool 使能开关
	* @param source 必选 int 视频源,SOURCE_INSIDE:内部,0,SOURCE_HDMI:HDMI,1
	* @return {"code":0}
	* @return_param code int 错误码：`0`获取成功
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetVideoSourcePolicyFor0x99Async(const char *data, ExportViplexCallback  callback);


#pragma endregion VideoSourceController 视频源控制

#pragma region userInfo

	/**
	* showdoc
	* @catalog 接口示例/显示屏用户信息
	* @title 修改配显示屏用户信息
	* @description 修改配显示屏用户信息的接口
	* @method
	* @url void nvSetUserInfoAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"","userInfo":{"aliasName":"easy-pluto","registerAddress":{"country":"中国","province":"山西省","city":"西安市","county":"雁塔区","address":"科技二路，西安软件园"}}}
	* @param sn 必选 string 产品唯一序列号
	* @param userInfo 必选 Object 详情
	* @param aliasName 必选 string 显示屏别名
	* @param registerAddress 必选 object 注册地址
	* @param country 必选 string 国家
	* @param province 必选 string 省份
	* @param city 必选 string 城市
	* @param county 必选 string 县，区
	* @param address 必选 string 详细地址
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetUserInfoAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/显示屏用户信息
	* @title 获取显示屏用户信息
	* @description 获取显示屏用户信息的接口
	* @method
	* @url void nvGetUserInfoAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"aliasName":"easy-pluto","registerAddress":{"country":"中国","province":"山西省","city":"西安市","county":"雁塔区","address":"科技二路，西安软件园"}}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回值具体描述
	* @return_param aliasName string 显示屏别名
	* @return_param registerAddress object 注册地址
	* @return_param country string 国家
	* @return_param province string 省份
	* @return_param city string 城市
	* @return_param county string 县，区
	* @return_param address string 详细地址
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetUserInfoAsync(const char *data, ExportViplexCallback(callBack));
#pragma endregion userInfo 显示屏用户信息

#pragma region Login
	/**
	 * showdoc
	 * @catalog 接口示例/搜索连接登录
	 * @title 搜索屏体
	 * @description 搜索当前wifi网络下的所有屏体
	 * @url void nvSearchTerminalAsync(ExportViplexCallback  callback)
	 * @return {"sn":"20393844393033","productName":"AX200","width":400,"height":800,"rotation":0,"aliasName":"XianYataScreen","logined":true,"username":["admin"],"tcpPort":16603,"ftpPort":16602,"syssetFtpPort":16604,"syssetTcpPort":16605,"key":"novaStar","platform":"rk3368","privacy":true,"terminalState":0,"ignoreTime":100029432434,"hasPassword":true,"password":"12345678"}
	 * @return_param code int 错误码：<br>`0`搜索成功，result即为搜索返回内容。<br>`65302`UDP监听端口(16600)被占用，可能会导致无数据返回。若没有数据返回，请释放端口后重新启动SDK。注：因为机器可能会存在多个网卡，某些电脑比如笔记本会存在单网卡多IP的情况，因此会可能出现某个IP下的端口被占用，某些没有被占用因此上述用到了“可能会导致无数据返回”。<br>`65535`搜索超时，代表在4s时间内未能搜索到任何终端
	 * @return_param sn string 产品序列号
	 * @return_param productName string 产品名称
	 * @return_param width int 显示屏宽度,单位为像素
	 * @return_param height int 显示屏高度,单位为像素
	 * @return_param rotation int 旋转角度:0，90，180，270
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
	VIPLEX_EXPORT void nvSearchTerminalAsync(ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 指定IP搜索
	* @description 搜索指定IP的屏体
	* @url void nvSearchAppointIpAsync(const char * appointIp, ExportViplexCallback callback)
	* @json_param {"ip":"172.18.179.243"}
	* @param appointIp 必选 string 输入指定的ip
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
	VIPLEX_EXPORT void nvSearchAppointIpAsync(const char * appointIp, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 指定范围IP搜索
	* @description 搜索指定范围IP的屏体
	* @url void nvSearchRangeIpAsync(const char * data, ExportViplexCallback callback);
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
	VIPLEX_EXPORT void nvSearchRangeIpAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 从数据库获取所有终端
	* @description 查询所有曾经搜索到的终端信息
	* @url void nvFindAllTerminalsAsync(ExportViplexCallback callback);
	* @return [{"aliasName":"Taurus-49999787","ftpPort":16602,"hasPassWord":false,"height":1080,"ignoreTime":0,"ip":"172.16.9.205","key":"novaStar","logined":false,"loginedUsernames":[""],"password":"","platform":"rk312x","privacy":true,"productName":"TC300","sn":"BZSA07194A0049999787","syssetFtpPort":16604,"syssetTcpPort":16605,"tcpPort":16603,"terminalState":5,"username":[],"width":1920}]
	* @return_param code int 错误码：<br>`0`获取成功
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
	VIPLEX_EXPORT void nvFindAllTerminalsAsync(ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 登录
	* @description 登陆接口和tcp连接是合并在一起的。假如某个时间tcp突然断开了，错误信息会从这个接口返回。
	* @url void nvLoginAsync(const char *data,ExportViplexCallback callback);
	* @json_param {"sn":"BZSA17332J0A20002272","ip":"","username":"admin","password":"123456","loginType":0,"rememberPwd":0}
	* @param sn 必选 string 产品唯一序列号
	* @param ip 可选 string 要登陆设备的IP地址
	* @param username 必选 string 用户名
	* @param password 必选 string 密码
	* @param loginType 必选 int `0`：登陆到屏体管理<br>`1`：登陆到系统设置（暗门登录）<br>`2`：登陆到诊断模块<br>`3`：LCT登录<br>`5`：公网SDK登录
	* @param rememberPwd 可选 int 是否记住密码<br>`0`表示No<br>`1`表示Yes
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
	VIPLEX_EXPORT void nvLoginAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 修改密码
	* @description 修改屏体的登录密码
	* @url void nvChangePassWordAsync(const char *data,ExportViplexCallback callback);
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
	VIPLEX_EXPORT void nvChangePassWordAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 删除屏体
	* @description 删除某个屏体
	* @url void nvDelTerminalInfoAsync(const char *data,ExportViplexCallback callback);
	* @json_param {"sn":"BZSA17332J0A20002272","type":"deleteTerminal"}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string "deleteTerminal"代表此次操作是"删除屏体（终端）"
	* @return Success
	* @return_param code int 错误码：<br>`0`删除成功<br>`65348`删除失败<br>`12`参数type错误，未实现的接口
	* @return_param data string 错误码描述，不用关注
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvDelTerminalInfoAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 屏体信息存储（数据继承）
	* @description 此接口是旧版本屏体数据继承
	* @url void nvSetScreenInfoAsync(const char *data, ExportViplexCallback callback);
	* @json_param [{"aliasName":"Taurus-10006848","screenMosaicInfo":{"order":456,"videoSource":127},"ftpPort":16602,"hasPassWord":false,"height":400,"ignoreTime":0,"ip":"192.168.1.113","key":"novaStar","logined":false,"password":"","productName":"T6","sn":"BZSA79353N1310006848","syssetFtpPort":16604,"syssetTcpPort":16605,"tcpPort":16603,"terminalState":0,"width":400}]
	* @param sn 必选 string 产品唯一序列号
	* @param productName 可选 string 产品名称
	* @param width 可选 int 显示屏宽度,单位为像素
	* @param height 可选 int 显示屏高度,单位为像素
	* @param rotation 可选 int 旋转角度:0，90，180，270
	* @param aliasName 可选 string 显示屏别名
	* @param logined 可选 boolean 是否有人已经登陆
	* @param username 可选 string_array 若已经有人登陆,代表已经登陆的用户名列表
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
	VIPLEX_EXPORT void nvSetScreenInfoAsync(const char *data, ExportViplexCallback callback);

	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 清除密码
	* @description 清除屏体密码
	* @url void nvDelTerminalInfoAsync(const char *data, ExportViplexCallback callback);
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
	* @title 获取拼接屏信息
	* @description 获取拼接屏信息
	* @url void nvGetTerminalInfoAsync(const char *data, ExportViplexCallback callback);
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
	VIPLEX_EXPORT void nvGetTerminalInfoAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 设置弱密码忽略时间
	* @description 设置“点击忽略弱密码选项”的时间戳后，调用“搜索屏体”时返回设置的字段，否则调用“搜索屏体”时返回空字符串。<br>设置此时间戳的目的是在未来某段时间内不再弹出“是否忽略弱密码模态框”。
	* @url void nvSetTerminalInfoAsync(const char *data, ExportViplexCallback callback);
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
	VIPLEX_EXPORT void nvSetTerminalInfoAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 设置系统信息
	* @description 设置“系统信息”。设置一些无关sn的配置信息，详见下面参数
	* @url void nvSetSystemInfoAsync(const char *data, ExportViplexCallback callback);
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
	VIPLEX_EXPORT void nvSetSystemInfoAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/搜索连接登录
	* @title 退出登录
	* @description 注意：退出登录后，返回成功或失败，login接口的长连接自动失效，不会再返回数据
	* @url void nvLogoutAsync(const char *data, ExportViplexCallback callback);
	* @json_param {"sn":"BZSA17332J0A20002272","loginType":0}
	* @param sn 必选 string 产品唯一序列号
	* @param loginType 必选 int `0：`断开屏体管理<br>`1：`断开系统设置（暗门）<br>`2：`断开诊断模块<br>`3：`断开LCT登录
	* @return disconnetSuccess
	* @return_param code int 错误码：<br>`0`退出成功
	* @return_param data string 错误码描述，不用关注
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvLogoutAsync(const char *data, ExportViplexCallback callback);
	/**
   * showdoc
   * @catalog 接口示例/屏体其他项
   * @title 固件版本信息
   * @description 获取固件版本信息接口，所有版本的终端均有此接口，返回终端的版本信息。<br>**1.2.2 版本碰到缺少 mac 字段**
   * @url void nvGetFirmwareInfosAsync(const char *data, ExportViplexCallback callback);
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
	VIPLEX_EXPORT void nvGetFirmwareInfosAsync(const char *data, ExportViplexCallback callback);
	/**
  * showdoc
  * @catalog 接口示例/屏体其他项
  * @title 已安装的软件版本信息
  * @description 获取终端已经安装的软件版本信息
  * @url void nvGetInstalledPackageVersionsAsync(const char *data, ExportViplexCallback callback);
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
	VIPLEX_EXPORT void nvGetInstalledPackageVersionsAsync(const char *data, ExportViplexCallback callback);
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项
	* @title 设备信息
	* @description 获取终端设备信息
	* @url void nvGetProductInfoAsync(const char *data, ExportViplexCallback callback);
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
	* @return_param portConfig object_array 网口配置
	* @return_param portNO int 网口编号，例如:1,2,3,4
	* @return_param isMainPort bool 是否为主网口
	* @return_param belongMainPort int 对应的主网口，如果该网口是主网口，该字段无效
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetProductInfoAsync(const char *data, ExportViplexCallback callback);
    /* 
    *  @brief  由于涉及json字段太多，在showdoc手动写这个方法的注释，不在这儿写避免被充掉
    *  @param  
    */
	VIPLEX_EXPORT void nvGetconfigurationAsync(const char *data, ExportViplexCallback callback);
#pragma endregion Login 搜索连接登录

#pragma region ScreenBrightness
	/**
	 * showdoc
	 * @catalog 接口示例/显示屏亮度和环境亮度/模式切换
	 * @title 设置模式
	 * @description 设置模式的接口
	 * @method
	 * @url void nvSetBrightnessAdjustModeAsync(const char *data, ExportViplexCallback  callback)
	 * @json_param {"sn":"","brightnessAdjustModeInfo":{"mode":"MANUALLY"}}
	 * @param sn 必选 string 产品唯一序列号
	 * @param brightnessAdjustModeInfo 必选 Object 请求信息对象
	 * @param mode 必选 string MANUALLY表示手动设置,AUTO表示自动
	 * @return ""
	 * @return_param code int 错误码：`0`获取成功`65535`请求超时
	 * @return_param data string 错误码对应的具体描述
	 * @remark
	 * @number 99
	 */
	VIPLEX_EXPORT void nvSetBrightnessAdjustModeAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/模式切换
	* @title 获取模式
	* @description 获取模式的接口
	* @method
	* @url void nvGetBrightnessAdjustModeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"mode":"MANUALLY ","source":{"platform":1,"type":1},"type":"SCREEN_BRIGHTNESS"}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @return_param type String 表示类型，当为开关屏时为SCREENPOWER, 当为亮度模块时为 SCREEN_BRIGHTNESS
	* @return_param source object 表示任务的发布来源,我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等
	* @return_param type number 1：nova自己的平台,0：第三方平台
	* @return_param platform number 表示任务的发布来源，我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等
	* @return_param mode String MANUALLY表示手动设置,AUTO:表示自动
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetBrightnessAdjustModeAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/手动控制亮度
	* @title 手动设置亮度
	* @description 手动设置亮度的接口
	* @method
	* @url void nvSetScreenBrightnessAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZWA17422J1X20000093","screenBrightnessInfo":{"ratio":45.0}}
	* @param sn 必选 string 产品唯一序列号
	* @param screenBrightnessInfo 必选 Object 请求信息对象
	* @param ratio 必选 float 显示屏亮度的值 百分比(0到100)
	* @return ""
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data string 错误码对应的具体描述
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetScreenBrightnessAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/手动控制亮度
	* @title 手动获取亮度
	* @description 手动获取亮度的接口
	* @method
	* @url void nvGetScreenBrightnessAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"ratio":45.0,"source":{"type":1,"platform":1}}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回data详情
	* @return_param ratio float 显示屏亮度的值百分比(0到100)
	* @return_param source Object 表示任务的发布来源,我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等。
	* @return_param type int 1：nova自己的平台, 0：第三方平台。
	* @return_param platform int 1：移动终端发来的(如手机)，2:表示传统电脑，3:表示平板，4:表示vnnox端发来的。5:来自iCare
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetScreenBrightnessAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/定时或自动亮度调节
	* @title 获取亮度调节方案
	* @description 获取亮度调节方案的接口
	* @method
	* @url void nvGetBrightnessPolicyAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"","brightnessPolicyInfo":{"isSupportCompleteCron":false}}
	* @param sn 必选 string 产品唯一序列号
	* @param brightnessPolicyInfo 必选 Object 请求信息对象
	* @param isSupportCompleteCron 非必选 bool 是否支持完整cron表达式调节及有效期，不传此参数，默认为false
	* @return {"enable":true,"source":{"platform":1,"type":1},"conditions":[{"opticalFailureInfo":{"enable":true,"screenBrightness":30},"enable":true,"crons":["0 15 10 ? ** *"],"startTime":"2017-09-01 00:00 : 00","endTime":"4016-06-06 23:59:59","segments":[{"screenBrightness":80,"environmentBrightness":12000},{"screenBrightness":60,"environmentBrightness":10000}],"type":2,"args":[12000,20,80,40,10]},{"opticalFailureInfo":{"enable":true,"screenBrightness":30},"enable":true,"crons":["0 15 10 ? **"],"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 23:59:59","segments":[],"type":1,"args":[30]}],"type":"BRIGHTNESS","segmentConfig":{"opticalFailureInfo":{"enable":true,"screenBrightness":30},"segments":[{"screenBrightness":80,"environmentBrightness":12000},{"screenBrightness":60,"environmentBrightness":10000}],"args":[12000,20,80,40,10]},"timeStamp":"2018-07-19 11:27:15"}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回参数
	* @return_param type string 固定为"BRIGHTNESS"
	* @return_param source object 表示任务的发布来源,我们现在终端的节目可以来自不同的来源,如PC、移动终端、云服务等
	* @return_param type number 1：nova自己的平台,0：第三方平台
	* @return_param platform number 1：移动终端发来的(如手机)，2:表示传统电脑，3：表示平板，4：表示web端发来的。
	* @return_param enable boolean 使能开关， 当为true表示所有有效
	* @return_param conditions object 按照条件执行的条件集合，我们支持多个条件触发。
	* @return_param type number 调节类型，1：定时调节，2：自动调节
	* @return_param cron array 重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
	* @return_param startTime string 策略有效期开始时间yyyy-MM-dd HH:mm:ss
	* @return_param endTime string 策略有效期结束时间yyyy-MM-dd HH:mm:ss,永久有效的时间为4016-06-06 23:59:59
	* @return_param args object 亮度调节参数，定时调试时args只有一个值为亮度百分比,自动调节时args含有5个值,分别为最大环境亮度,最小环境亮度,最大屏体亮度,最小屏体亮度, 分段数
	* @return_param segments object 亮度调节参数的分段详细设置
	* @return_param environmentBrightness number 环境亮度值
	* @return_param screenBrightness number 对应环境亮度所要调节的屏体亮度值
	* @return_param opticalFailureInfo object 自动亮度调节时，获取环境亮度失败,是否调到固定值的选项，该字段只对自动亮度调节有效。
	* @return_param enable boolean 自动亮度调节时，获取环境亮度失败，是否调到固定值
	* @return_param screenBrightness number 需要调节到的固定亮度值
	* @return_param enable boolean 该条方案的使能开关
	* @return_param segmentConfig object 根据环境亮度配置的分段表数据segmentsConfig字段，内部字段参见自动亮度调节的参数说明
	* @return_param timeStamp string 当前数据的时间戳，为后期可能使用
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetBrightnessPolicyAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/定时或自动亮度调节
	* @title 设置亮度调节方案
	* @description 1.终端版本大于等于1.3.1 ：支持starttime，endtime，args中最大屏体亮度，最小屏体亮度支持浮点型。screenBrightness支持浮点型。终端版本小于1.3.1 不支持starttime、endtime以及屏体亮度支持浮点型。当下发定时任务时，args仅有一个参数，代表亮度 大于等于1.3.1 时类型为浮点型，小于1.3.1时为整型 。2.是否支持浮点型根据支持的模块判断是否是浮点型,支持：args中最大屏体亮度，最小屏体亮度支持浮点型。screenBrightness支持浮点型。不支持 :args中最大屏体亮度，最小屏体亮度，screenBrightness只能为int类型。
	* @method
	* @url void nvSetBrightnessPolicyAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"","taskInfo":{"type":"BRIGHTNESS","source":{"type":0,"platform":1},"enable":true,"conditions":[{"type":2,"cron":["0 15 10 ? ** *"],"args":[12000,20,80,40,10],"startTime":"2017-09-01 00:00 : 00","endTime":"4016-06-06 23:59:59","enable":true},{"type":1,"cron":["0 15 10 ? **"],"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 23:59:59","args":[30],"enable":true}],"segmentConfig":{"args":[12000,20,80,40,10],"segments":[{"environmentBrightness":12000,"screenBrightness":80},{"environmentBrightness":10000,"screenBrightness":60}],"opticalFailureInfo":{"enable":true,"screenBrightness":30}},"timeStamp":"2018-07-19 11:27:15"}}
	* @param sn 必选 string 产品唯一序列号
	* @param taskInfo 必选 Object 请求信息对象
	* @param type 必选 string 固定为"BRIGHTNESS"
	* @param source 必选 object 表示任务的发布来源，我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等
	* @param type 必选 number 1：nova自己的平台, 0：第三方平台
	* @param platform 必选 number 1：移动终端发来的(如手机)，2：表示传统电脑，3：表示平板，4：表示web端发来的
	* @param enable 必选 boolean 使能开关
	* @param conditions 必选 object 按照条件执行的条件集合，我们支持多个条件触发
	* @param type 必选 number 调节类型，1：定时调节，2：自动调节
	* @param cron 必选 array 重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系(cron详细格式见附件)
	* @param args 必选 array 亮度调节参数，定时调试时args只有一个值为亮度百分比,自动调节时args含有5个值,分别为最大环境亮度,最小环境亮度,最大屏体亮度,最小屏体亮度，分段数
	* @param startTime 必选 string 策略有效期开始时间yyyy-MM-dd HH:mm:ss(1.3.1以下没有此字段)
	* @param endTime 必选 string 策略有效期结束时间yyyy-MM-dd HH:mm:ss,永久有效的时间为4016-06-0623:59:59(1.3.1以下没有此字段)
	* @param segments 非必选 object 亮度调节参数的分段详细设置,(1.3.1以下在每条定时任务里面,>=1.3.1和定时列表平级)
	* @param environmentBrightness 非必选 int 环境亮度值
	* @param screenBrightness 非必选 number 对应环境亮度所要调节的屏体亮度值
	* @param opticalFailureInfo 非必选 object 自动亮度调节时,获取环境亮度失败,是否调到固定值的选项,该字段只对自动亮度调节有效
	* @param enable 必选 boolean 自动亮度调节时,获取环境亮度失败,是否调到固定值
	* @param screenBrightness 非必选 number 需要调节到的固定亮度值
	* @param enable 必选 boolean 该条方案的使能开关
	* @param segmentConfig 非必选 object 根据环境亮度配置的分段表数据,内部字段参见自动亮度调节的参数说明
	* @param timeStamp 必选 string 当前数据的时间戳,为后期可能使用
	* @return ""
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data string 错误码对应的具体描述
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetBrightnessPolicyAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/环境亮度
	* @title 获取环境亮度
	* @description 获取终端当前的环境亮度，只能获取不能设置环境亮度
	* @method
	* @url void nvGetEnvironmentBrightnessAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"value":1000}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @return_param value int 环境亮度的值,单位LUX
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetEnvironmentBrightnessAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/手动亮度调节（0x99）
	* @title 手动设置亮度
	* @description 获取环境亮度的接口
	* @method
	* @url void nvsetManualBrightnessFor0x99Async(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"MANUAL_BRIGHTNESS","orderId":12356,"action":4,"data":{"ratio":60.0}}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："MANUAL_BRIGHTNESS"
	* @param data 必选 object 亮度命令
	* @param ratio 必选 float 亮度百分比
	* @return {"taskArray":[{"type":"MANUAL_BRIGHTNESS","orderId":12356,"action":4,"status":1,"errorCode":0}]}
	* @return_param errorCode 必选 short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvsetManualBrightnessFor0x99Async(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/定时或自动亮度调节（0x99）
	* @title 设置亮度调节方案
	* @description 设置亮度调节方案的接口
	* @method
	* @url void nvsetPolicyBrightnessFor0x99Async(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"POLICY_BRIGHTNESS","orderId":12356,"action":4,"data":{"enable":true,"conditions":[{"type":2,"cron":["0 15 10 ? * *"],"args":[12000,20,80,40,10],"segments":[{"environmentBrightness":12000,"screenBrightness":80},{"environmentBrightness":10000,"screenBrightness":60}],"opticalFailureInfo":{"enable":true,"screenBrightness":30},"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 23:59:59","enable":true},{"type":1,"cron":["0 15 10 ? * *"],"args":[30],"enable":true,"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 23:59:59"}],"segmentConfig":{"args":[12000,20,80,40,10],"segments":[{"environmentBrightness":12000,"screenBrightness":80},{"environmentBrightness":10000,"screenBrightness":60}],"opticalFailureInfo":{"enable":true,"screenBrightness":30}},"timeStamp":"2018-07-19 11:27:15"}}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param taskInfo 必选 object 请求信息对象
	* @param source 必选 object 表示任务的发布来源，我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等。
	* @param platform 必选 number 1：移动终端发来的（如手机），2：表示传统电脑，3：表示平板，4：表示web端发来的。
	* @param enable 必选 boolean 使能开关
	* @param conditions 必选 object 按照条件执行的条件集合，我们支持多个条件触发。
	* @param type 必选 number 调节类型，1：定时调节，2：自动调节
	* @param cron 必选 string array 重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
	* @param args 必选 object 亮度调节参数，定时调试时args为亮度百分比，自动调节时args为自动调节参数
	* @param startTime 必选 string 策略有效期开始时间yyyy-MM-dd HH:mm:ss
	* @param endTime 必选 string 策略有效期结束时间yyyy-MM-dd HH:mm:ss,永久有效的时间为4016-06-06 23:59:59
	* @param segments 必选 object 亮度调节参数的分段详细设置。
	* @param environmentBrightness 必选 number 环境亮度值
	* @param screenBrightness 必选 number 对应环境亮度所要调节的屏体亮度值
	* @param opticalFailureInfo 必选 object 自动亮度调节时，获取环境亮度失败，是否调到固定值的选项，该字段只对自动亮度调节有效。
	* @param enable 必选 boolean 自动亮度调节时，获取环境亮度失败，是否调到固定值
	* @param screenBrightness 必选 number 需要调节到的固定亮度值
	* @param enable 必选 boolean 该条方案的使能开关
	* @param segmentConfig 必选 object 根据环境亮度配置的分段表数据，内部字段参见自动亮度调节的参数说明
	* @param timeStamp 必选 string 当前数据的时间戳，为后期可能使用
	* @return {"taskArray":[{"type":"POLICY_BRIGHTNESS","orderId":12356,"action":4,"status":1,"errorCode":1,"data":null}]}
	* @param status 必选 int 此任务执行是否成功:1-成功，2-失败，3-未知
	* @param errorCode 必选 int 当返回成功时无意义，当返回失败时，返回失败原因
	* @param data 必选 null 具体返回的数据
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvsetPolicyBrightnessFor0x99Async(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/显示屏亮度和环境亮度/定时或自动亮度调节（0x99）
	* @title 获取亮度调节方案
	* @description 获取亮度调节方案的接口
	* @url ""
	* @json_param void nvgetPolicyBrightnessFor0x99Async(const char *data, ExportViplexCallback  callback)
	* @return {"taskInfo":{"source":{"type":0,"platform":1},"enable":true,"conditions":[{"type":2,"cron":["0 15 10 ? * * *"],"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 23:59:59","args":[12000,20,80,40,10],"segments":[{"environmentBrightness":12000,"screenBrightness":80},{"environmentBrightness":10000,"screenBrightness":60}],"opticalFailureInfo":{"enable":true,"screenBrightness":30},"enable":true},{"type":1,"cron":["0 15 10 ? * *"],"startTime":"2017-09-01 00:00:00","endTime":"4016-06-06 23:59:59","args":[30],"enable":true}],"segmentConfig":{"args":[12000,20,80,40,10],"segments":[{"environmentBrightness":12000,"screenBrightness":80},{"environmentBrightness":10000,"screenBrightness":60}],"opticalFailureInfo":{"enable":true,"screenBrightness":30}},"timeStamp":"2018-07-19 11:27:15"}}
	* @return_param taskInfo 必选 object 返回的数据
	* @return_param source 必选 object 表示任务的发布来源，我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等。
	* @return_param platform 必选 number 1：移动终端发来的（如手机），2：表示传统电脑，3：表示平板，4：表示web端发来的。
	* @return_param enable 必选 boolean 使能开关
	* @return_param conditions 必选 object 按照条件执行的条件集合，我们支持多个条件触发。
	* @return_param type 必选 number 调节类型，1：定时调节，2：自动调节
	* @return_param cron 必选 string array 重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
	* @return_param args 必选 object 亮度调节参数，定时调试时args为亮度百分比，自动调节时args为自动调节参数
	* @return_param startTime 必选 string 策略有效期开始时间yyyy-MM-dd HH:mm:ss
	* @return_param endTime 必选 string 策略有效期结束时间yyyy-MM-dd HH:mm:ss,永久有效的时间为4016-06-06 23:59:59
	* @return_param segments 必选 object 亮度调节参数的分段详细设置。
	* @return_param environmentBrightness 必选 number 环境亮度值
	* @return_param screenBrightness 必选 number 对应环境亮度所要调节的屏体亮度值
	* @return_param opticalFailureInfo 必选 object 自动亮度调节时，获取环境亮度失败，是否调到固定值的选项，该字段只对自动亮度调节有效。
	* @return_param enable 必选 boolean 自动亮度调节时，获取环境亮度失败，是否调到固定值
	* @return_param screenBrightness 必选 number 需要调节到的固定亮度值
	* @return_param enable 必选 boolean 该条方案的使能开关
	* @return_param segmentConfig 必选 object 根据环境亮度配置的分段表数据，内部字段参见自动亮度调节的参数说明
	* @return_param timeStamp 必选 string 当前数据的时间戳，为后期可能使用
	* @return_param errorCode 必选 int 当返回成功时无意义，当返回失败时，返回失败原因
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvgetPolicyBrightnessFor0x99Async(const char *data, ExportViplexCallback  callback);

#pragma endregion LightController 显示屏亮度和环境亮度

#pragma region TemperatureController
	/**
	* showdoc
	* @catalog 接口示例/温度和色温/色温
	* @title 获取色温
	* @description 获取色温的接口
	* @method
	* @url void nvGetColorTemperatureAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"colorTemperature":9300}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回值具体描述
	* @return_param colorTemperature int 色温值
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetColorTemperatureAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/温度和色温/色温
	* @title 设置色温
	* @description 当前终端无法做较为准确的色温设置，所以选定了3种色温，分别为9300、6500、4700，故回读亦是如此
	* @method
	* @url void nvSetColorTemperatureAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","colorTemperatureInfo":{"colorTemperature":6500}}
	* @param sn 必选 string 产品唯一序列号
	* @param colorTemperatureInfo 必选 Object 色温详情
	* @param colorTemperature 必选 int 色温值
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetColorTemperatureAsync(const char *data, ExportViplexCallback  callback);

#pragma region SwitchController
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/模式切换
	* @title 设置模式
	* @description 设置模式的接口
	* @method
	* @url void nvSetScreenPowerModeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"","taskInfo":{"mode":"MANUALLY"}}
	* @param sn 必选 string 产品唯一序列号
	* @param taskInfo 必选 Object 详情
	* @param mode 必选 string MANUALLY:表示手动设置,AUTO：表示自动
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetScreenPowerModeAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/模式切换
	* @title 获取模式
	* @description 获取模式的接口
	* @method
	* @url void nvGetScreenPowerModeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"mode":"MANUALLY","source":{"platform":1,"type":1},"type":"SCREENPOWER"}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回值具体描述
	* @return_param type String 表示类型，当为开关屏时为SCREENPOWER,当为亮度模块时为 SCREEN_BRIGHTNESS
	* @return_param source object 详情参照附录定义
	* @return_param type number 1：nova自己的平台,0：第三方平台。
	* @return_param platform number 1：移动终端发来的(如手机)，2：表示传统电脑，3：表示平板，4:表示web端发来的。
	* @return_param mode String MANUALLY表示手动设置,AUTO：表示自动
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetScreenPowerModeAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/手动开关屏
	* @title 设置手动开关屏状态
	* @description 设置手动开关屏状态的接口
	* @method
	* @url void nvSetScreenPowerStateAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"","taskInfo":{"state":"OPEN"}}
	* @param sn 必选 string 产品唯一序列号
	* @param taskInfo 必选 Object 详情
	* @param state 必选 string 显示屏开关状态,"OPEN":开,"CLOSE":关
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetScreenPowerStateAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/手动开关屏
	* @title 获取手动开关屏状态
	* @description 获取手动开关屏状态的接口
	* @method
	* @url void nvGetScreenPowerStateAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"state":"UNKNOW"}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回值具体描述
	* @return_param state string 显示屏开关状态，"OPEN":开，"CLOSE":关
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetScreenPowerStateAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/定时开关屏
	* @title 获取定时开关屏
	* @description 获取定时开关屏的接口
	* @method
	* @url void nvGetScreenPowerPolicyAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"type":"SCREENPOWER","source":{"type":0,"platform":1},"enable":true,"conditions":[{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"action":"OPEN","enable":true},{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"action":"CLOSE","enable":true}]}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回值具体描述
	* @return_param type string 固定为"SCREENPOWER"
	* @return_param source object 表示任务的发布来源，我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等。
	* @return_param type number 1：nova自己的平台,0：第三方平台。
	* @return_param platform number 1：移动终端发来的（如手机），2：表示传统电脑，3：表示平板，4：表示web端发来的。
	* @return_param enable boolean 按条件执行的使能开关
	* @return_param conditions object 按照条件执行的任务集合，我们支持多个任务。
	* @return_param cron (string)array 重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
	* @return_param action String "OPEN":开， "CLOSE":关
	* @return_param enable boolean 该条件执行的使能开关
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetScreenPowerPolicyAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/定时开关屏
	* @title 设置开关屏状态
	* @description 设置开关屏状态的接口
	* @method
	* @url void nvSetScreenPowerPolicyAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZWA17422J1X20000093","taskInfo":{"type":"SCREENPOWER","source":{"type":0,"platform":1},"enable":true,"conditions":[{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"action":"OPEN","enable":true}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param taskInfo 必选 Object 详情
	* @param type 必选 string 固定为"SCREENPOWER"
	* @param source 非必选 object 表示任务的发布来源，我们现在终端的节目可以来自不同的来源。如PC、移动终端、云服务等。
	* @param type 非必选 number 1：nova自己的平台,0：第三方平台。
	* @param platform 非必选 number 1：移动终端发来的(如手机)，2：表示传统电脑，3：表示平板，4：表示web端发来的。
	* @param enable 必选 boolean 按条件执行的使能开关
	* @param conditions 必选 object 按照条件执行的任务集合，我们支持多个任务。
	* @param cron 必选 (string)array 重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
	* @param action 必选 String "OPEN":开,"CLOSE":关
	* @param enable 必选 boolean 该条件执行的使能开关
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetScreenPowerPolicyAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/开关屏（新协议0x99）
	* @title 立即开关屏
	* @description 此模块为终端开关屏与vnnox的交互协议，包括立即开关屏和定时开关屏，vnnox端没有模式的概念，立即和定时都会执行
	* @method
	* @url void nvsetScreenPowerManual0x99Async(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_MANUAL","orderId":12356,"action":4,"data":{"state":"OPEN"}}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："SCREEN_POWER_MANUAL"
	* @param data 必选 object 开关屏操作
	* @param state 必选 String 显示屏开关状态，"OPEN":开，"CLOSE":关
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_MANUAL","orderId":12356,"action":4,"status":1,"errorCode":0}]}
	* @return_param errorCode short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvsetScreenPowerManual0x99Async(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/开关屏（新协议0x99）
	* @title 定时开关屏状态
	* @description 此模块为终端开关屏与vnnox的交互协议，包括立即开关屏和定时开关屏，vnnox端没有模式的概念，立即和定时都会执行
	* @method
	* @url void nvsetScreenPowerPolicy0x99Async(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_POLICY","orderId":12356,"action":4,"data":{"enable":true,"conditions":[{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"action":"OPEN","enable":true},{"cron":["0 0 18 ? * *","0 0 12 * * ?"],"action":"CLOSE","enable":true}]}}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："SCREEN_POWER_POLICY"
	* @param data 必选 object 开关屏操作
	* @param enable 必选 boolean 使能开关，当为true表示所有有效，当为false表示所有不生效，定时任务不执行
	* @param conditions 必选 object 按照条件执行的任务集合，我们支持多个任务。
	* @param cron 必选 string array重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
	* @param action 必选 enum "OPEN":开,"CLOSE":关
	* @param enable 必选 boolean 该条件执行的使能开关
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_POLICY","orderId":12356,"action":4,"status":1,"errorCode":0}]}
	* @return_param errorCode short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvsetScreenPowerPolicy0x99Async(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/开关屏（新协议0x99）
	* @title 获取开关屏状态
	* @description 此模块为终端开关屏与vnnox的交互协议，包括立即开关屏和定时开关屏，vnnox端没有模式的概念，立即和定时都会执行
	* @method
	* @url void nvGetScreenPowerManual0x99Async(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_MANUAL","orderId":12356,"action":5,"data":null}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："SCREEN_POWER_MANUAL"
	* @param data 必选 object null
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_MANUAL","orderId":12356,"action":5,"status":1,"errorCode":0,"data":{"state":"OPEN"}}]}
	* @return_param errorCode short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @return_param data object 开关屏操作
	* @return_param state String 显示屏开关状态，"OPEN":开，"CLOSE":关
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetScreenPowerManual0x99Async(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/开关屏管理/开关屏（新协议0x99）
	* @title 获取定时开关屏命令
	* @description 此模块为终端开关屏与vnnox的交互协议，包括立即开关屏和定时开关屏，vnnox端没有模式的概念，立即和定时都会执行
	* @method
	* @url void nvsetScreenPowerManual0x99Async(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_POLICY","orderId":12356,"action":5,"data":null}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："SCREEN_POWER_POLICY"
	* @param data 必选 object null
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"SCREEN_POWER_POLICY","orderId":12356,"action":5,"status":1,"errorCode":0,"data":{"source":{"type":1,"platform":1},"enable":true,"conditions":[{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"action":"OPEN","enable":true},{"cron":["0 0 18 ? * *","0 0 12 * * ?"],"action":"CLOSE","enable":true}]}}]}
	* @return_param errorCode short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @return_param data object 开关屏操作
	* @return_param enable boolean 使能开关,当为true表示所有有效，当为false表示所有不生效，定时任务不执行
	* @return_param conditions object 按照条件执行的任务集合，我们支持多个任务。
	* @return_param cron string array重复次数，每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
	* @return_param action enum "OPEN":开,"CLOSE":关
	* @return_param enable boolean 该条件执行的使能开关
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetScreenPowerPolicyFor0x99Async(const char *data, ExportViplexCallback  callback);
#pragma endregion SwitchController 开关屏管理


#pragma region FileManager
#pragma endregion FileManager 系统文件管理 待开发

#pragma region ListManager
	/**
	* showdoc
	* @catalog 接口示例/清单管理
	* @title 清单回读
	* @description 获取节目清单的接口
	* @method
	* @url void nvGetProgramInfoAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA17332J0A20002272"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"programInfos":[{"identifier":"62932662fb727f42d695201aa91e32c8","name":"PlayLists1","thumbnailUrl":"program_868679025220684_1/program_thumb.png","statusCode":1,"source":0},{"identifier":"62932662fb727f42d695201aa91e32c8","name":"PlayLists2","thumbnailUrl":"program_868679025220684_2/program_thumb.png","statusCode":1,"source":1}]}
	* @return_param name string 播放清单的名称
	* @return_param thumbnailUrl string 播放清单缩略图绝对路径
	* @return_param statusCode int 	清单播放状态(`0`表示停止播放;`1`表示正在播放;`2`表示暂停播放)
	* @return_param identifier string 播放方案的唯一标识，这里指的是内容上的，内容相同，则播放方案标识一样，目前存放planList的md5码
	* @return_param source int 清单的来源(`0`表示局域网发送的节目；`1`表示Vnnox发送的节目;)
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetProgramInfoAsync(const char *data, ExportViplexCallback  callback);
	/**
   * showdoc
   * @catalog 接口示例/清单管理
   * @title 清单删除
   * @description 删除节目清单的接口
   * @method
   * @url void nvDeletePlayListAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272","taskInfo":{"solutions":[{"name":"program1","identifier":"ccdc78e192d8d97bfd01c82881038a39"}]}}
   * @param sn 必选 string 产品唯一序列号
   * @param identifier 必选 string 播放方案的唯一标识
   * @param name 必选 string 播放清单的名称
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvDeletePlayListAsync(const char *data, ExportViplexCallback  callback);
	/**
   * showdoc
   * @catalog 接口示例/清单管理
   * @title 清单播放
   * @description 获取节目清单的接口
   * @method
   * @url void nvStartPlayAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272","identifier":"62932662fb727f42d695201aa91e32c8"}
   * @param sn 必选 string 产品唯一序列号
   * @param identifier 必选 string 播放方案的唯一标识
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvStartPlayAsync(const char *data, ExportViplexCallback  callback);
	/**
   * showdoc
   * @catalog 接口示例/清单管理
   * @title 清单暂停播放
   * @description 暂停节目播放的接口
   * @method
   * @url void nvPausePlayAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272","identifier":"62932662fb727f42d695201aa91e32c8"}
   * @param sn 必选 string 产品唯一序列号
   * @param identifier 必选 string 播放方案的唯一标识
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvPausePlayAsync(const char *data, ExportViplexCallback  callback);
	/**
   * showdoc
   * @catalog 接口示例/清单管理
   * @title 清单恢复播放
   * @description 恢复节目播放的接口
   * @method
   * @url void nvResumePlayAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272","identifier":"62932662fb727f42d695201aa91e32c8"}
   * @param sn 必选 string 产品唯一序列号
   * @param identifier 必选 string 播放方案的唯一标识
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvResumePlayAsync(const char *data, ExportViplexCallback  callback);
	/**
* showdoc
* @catalog 接口示例/清单管理
* @title 清单停止播放
* @description 清单停止播放的接口
* @method
* @url void nvStopPlayAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"sn":"BZSA17332J0A20002272","identifier":"62932662fb727f42d695201aa91e32c8"}
* @param sn 必选 string 产品唯一序列号
* @param identifier 必选 string 播放方案的唯一标识
* @return ""
* @return_param code int 错误码：`0`获取成功`65535`请求超时
* @remark
* @number 99
*/
	VIPLEX_EXPORT void nvStopPlayAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion ListManager 清单管理 

#pragma region AdvancedFeatures
	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title 设置同步播放开关
	* @description 设置同步播放开关的接口
	* @method
	* @url void nvSetSyncPlayAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","enable":true}
	* @param sn 必选 string 产品唯一序列号
	* @param enable 必选 bool 开启关闭同步播放
	* @return "success"
	* @return_param code int 错误码:`0`获取成功`65535`请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetSyncPlayAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title 获取同步播放配置
	* @description 获取同步播放配置
	* @method
	* @url void nvGetSyncPlayAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"data":{"enable":false}}
	* @return_param code int 错误码：0 获取成功，65535 请求超时
	* @return_param enable bool 终端是否开启同步播放
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetSyncPlayAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title 恢复出厂设置
	* @description 恢复出厂设置
	* @method
	* @url void nvSetReBootWipeUserDataAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","setInfo":{"reason":"terminal connect failed"}}
	* @param sn 必选 string 产品唯一序列号
	* @param reason 必选 string 恢复出厂设置的原因
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetReBootWipeUserDataAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title 清除所有媒体
	* @description 清除所有媒体
	* @method
	* @url void nvClearAllMediasAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272"}
	* @param sn 必选 string 产品唯一序列号
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvClearAllMediasAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title OTG USB 状态获取
	* @description OTG USB 状态获取
	* @method
	* @url void nvGetOTGUSBModeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"value":1.0}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param value double USB是否可用，1表示USB不可用，2表示USB可用，adb可调式
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetOTGUSBModeAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title OTG USB 状态设置
	* @description OTG USB 状态设置
	* @method
	* @url void nvSetOTGUSBModeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","modeInfo":{"value":2.0}}
	* @param sn 必选 string 产品唯一序列号
	* @param value 必选 double USB是否可用，1表示USB不可用，2表示USB可用，adb可调式
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetOTGUSBModeAsync(const char *data, ExportViplexCallback  callback);

	/**
   * showdoc
   * @catalog 接口示例/高级特性
   * @title 设置当前分辨率
   * @description 设置当前分辨率
   * @method
   * @url void nvSetCurrentResolutioAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"sn":"BZSA17332J0A20002272","resolutionInfo":{"displayMode":1,"resolutionValue":"1280X720p-60"}}
   * @param sn 必选 string 产品唯一序列号
   * @param displayMode 必选 int 显示模式，默认 DISPLAY_INTERFACE_TV(1)
   * @param resolutionValue 必选 string 分辨率的值
   * @return "success"
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvSetCurrentResolutioAsync(const char *data, ExportViplexCallback  callback);

	/**
   * showdoc
   * @catalog 接口示例/高级特性
   * @title 获取当前分辨率
   * @description 获取当前分辨率
   * @method
   * @url void getCurrentResolutionAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"sn":"BZSA17332J0A20002272","requestInfo":{"displayMode":1}}
   * @param sn 必选 string 产品唯一序列号
   * @param displayMode 必选 int 显示模式，1:TV,2:YPbPr,3:VGA,4:HDMI,5:LCD，默认为1
   * @return {"value":"960x2048p-60"}
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @return_param value string 分辨率的值
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvGetCurrentResolutionAsync(const char *data, ExportViplexCallback  callback);

	/**
	  * showdoc
	  * @catalog 接口示例/高级特性
	  * @title 获取终端所支持的分辨率
	  * @description 获取终端所支持的分辨率
	  * @method
	  * @url void getSupportedResolutionAsync(const char *data, ExportViplexCallback  callback)
	  * @json_param {"sn":"BZSA17332J0A20002272"，"requestInfo":{"displayMode":1}}
	  * @param sn 必选 string 产品唯一序列号
	  * @param displayMode 必选 int 显示模式
	  * @return {"result":[{"value":"2048x256p-60"},{"value":"4096x512p-60"}]}
	  * @return_param code int 错误码：`0`获取成功`65535`请求超时
	  * @return_param value string 分辨率的值
	  * @remark
	  * @number 99
	  */
	VIPLEX_EXPORT void nvGetSupportedResolutionAsync(const char *data, ExportViplexCallback  callback);

	/**
   * showdoc
   * @catalog 接口示例/高级特性/重启
   * @title 获取重启任务
   * @description 获取已经设置的重启任务的接口
   * @method
   * @url void nvGetReBootTaskAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"conditions":[{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"enable":true}],"executionType":"BY_CONDITIONS","reason":"Just to test","source":{"platform":1,"type":0},"type":"REBOOT"}
   * @return_param cron stringarray 每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
   * @return_param enable bool 该条件是否启用
   * @return_param executionType string `IMMEDIATELY`立即执行;`BY_CONDITIONS`按照条件执行
   * @return_param reason string 重启的原因
   * @return_param platform int `1`移动终端发来的(如手机),`2`表示传统电脑，`3`表示平板，`4`表示web端发来的
   * @return_param type int `1`nova自己的平台,`0`第三方平台
   * @return_param type string 固定为"REBOOT"
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvGetReBootTaskAsync(const char *data, ExportViplexCallback  callback);
	/**
   * showdoc
   * @catalog 接口示例/高级特性/重启
   * @title 设置重启任务
   * @description 设置重启的接口(设置立即重启，必须要先登录到系统设置)
   * @method
   * @url void void nvSetReBootTaskAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"type":"REBOOT","source":{"type":0,"platform":1},"executionType":"IMMEDIATELY","reason":"Just to test","conditions":[{"cron":["0 15 10 ? * *","0 0 12 * * ?"],"enable":true}]}}
   * @param sn 必选 string 产品唯一序列号
   * @param cron 必选 stringarray 每条条件使用cron表达式数组表示，当为数组时，cron表达式之间使用或的关系
   * @param enable 必选 bool 该条件是否启用
   * @param executionType 必选 string `IMMEDIATELY`立即执行;`BY_CONDITIONS`按照条件执行
   * @param reason 必选 string 重启的原因
   * @param platform 必选 int `1`移动终端发来的(如手机),`2`表示传统电脑，`3`表示平板，`4`表示web端发来的
   * @param type 必选 int `1`nova自己的平台,`0`第三方平台
   * @param type 必选 string 固定为"REBOOT"
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvSetReBootTaskAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title 获取终端的输出状态
	* @description 获取终端的输出状态
	* @method
	* @url void nvGetHdmiOutputStatusAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"value":1}
	* @return_param code int 错误码：0 获取成功，65535 请求超时
	* @return_param value int 1表示当前是HDMI，0表示RGB
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetHdmiOutputStatusAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title 设置终端的输出状态
	* @description 设置终端的输出状态
	* @method
	* @url void setHdmiOutputStatusAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","info":{"value":1}}
	* @param sn 必选 string 产品唯一序列号
	* @param value 必选 int 1表示当前是HDMI，0表示RGB
	* @return "sccuss"
	* @return_param code int 错误码：0 获取成功，65535 请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetHdmiOutputStatusAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/高级特性
	* @title 设置自定义分辨率
	* @description 设置自定义分辨率
	* @method
	* @url void nvSetCustomResolutionAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","info":{"displayMode":1,"width":1920,"height":1080}}
	* @param sn 必选 string 产品唯一序列号
	* @param displayMode 必选 int 显示模式
	* @param width 必选 int 显示宽度
	* @param height 必选 int 显示高度
	* @return "sccuss"
	* @return_param code int 错误码：0 获取成功，65535 请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetCustomResolutionAsync(const char *data, ExportViplexCallback  callback);

#pragma endregion AdvancedFeatures 高级特性 

#pragma region AcquisitionReceiver
	/**
	 * showdoc
	 * @catalog 接口示例/采集器接收器
	 * @title 获取采集接收器配置
	 * @description 获取采集接收器配置的接口
	 * @method
	 * @url void nvGetPickerReceiverAsync(const char *data, ExportViplexCallback  callback)
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
	 * @return_param type string CPU_USAGE:cpu使用率，CPU_TERMPATURE：cpu温度，MEMORY_USAGE：内存使用率，WIFI_STATE_CHANGED：wifi状态变化
	 * @remark
	 * @number 99
	 */
	VIPLEX_EXPORT void nvGetPickerReceiverAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/采集器接收器
	* @title 添加采集接收器
	* @description 添加采集接收器
	* @method
	* @url void nvAddCollectorAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA07194A0049999716","info":{"pickers":[{"type":"CPU_USAGE", "pickType":"PERIOD","period":1000,"receivers":[{"outputDestination":"TCP_NET_WORK","persistent":false}]}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param info 必选 object 采集器数据实体
	* @param pickers 必选 object 采集器数据列表
	* @param type 必选 string 采集器类型
	* @param pickType 必选 string PERIOD或AUTO
	* @param period 必选 long 采集周期
	* @param receivers 必选 object 关联的接收器
	* @param outputDestination 必选 enum 采集输出路径包括文件、网络和控制台
	* @param persistent 必选 bool 表示是否持久
	* @return "sccuss"
	* @return_param code int 错误码:`0`获取成功`65535`请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvAddCollectorAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/采集器接收器
	* @title 删除采集接收器
	* @description 删除采集接收器
	* @method
	* @url void nvDeleteCollectorAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA07194A0049999716","info":{"type":["CPU_USAGE"]}}
	* @param sn 必选 string 产品唯一序列号
	* @param info 必选 object 删除的采集器类型
	* @param type 必选 list 删除的采集器类型列表
	* @return "sccuss"
	* @return_param code int 错误码:`0`获取成功`65535`请求超时
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvDeleteCollectorAsync(const char *data, ExportViplexCallback  callback);

#pragma endregion AcquisitionReceiver 采集器接收器

#pragma region USBVPlay
#pragma endregion USBVPlay U盘相关协议 待开发

#pragma region UpgradeManager
	/**
	* showdoc
	* @catalog 接口示例/升级管理
	* @title 搜索可用升级包
	* @description 搜索本地指定文件目录下的升级包的接口
	* @method
	* @url void nvQueryUpdateFileByTypeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"paths":["C:/Users/Public/viplexcore/fileundertest/test2"],"types":["*.nuzip"],"pageIndex" : 0,"pageSize" : 100}
	* @param paths 必选 string 指定搜索的文件夹路径
	* @param types 必选 string 指定搜索的文件后缀名
	* @param pageIndex 必选 int 当前页数
	* @param pageSize 必选 int 最大页数
	* @return {"files":["C:/Users/Public/viplexcore/fileundertest/test2/ViPlex Express V1.10.0.0302 Setup.nuzip","C:/Users/Public/viplexcore/fileundertest/test2/ViPlex Express V1.10.0.0601.nuzip"]}
	* @return_param code int 错误码：0
	* @return_param files stringArray 搜索到的文件的绝对路径
	* @remark
	* @number 99
	*/
    VIPLEX_EXPORT void nvQueryUpdateFileByTypeAsync(const char *data, ExportViplexCallback  callback);
	/**
	 * showdoc
	 * @catalog 接口示例/升级管理
	 * @title 搜索线上升级包
	 * @description 获取线上可用的升级包的接口
	 * @method
	 * @url void nvGetOnlineUpgradeFileAsync(const char *data, ExportViplexCallback  callback)
	 * @json_param {"productName":"T2"}
	 * @param productName 必选 产品类型
	 * @return {"onlineUpdatePackageInfos":[{"url":"http://static.vnnox.com/cn/vnnox_system/product_upgrade/accessory/UPDATE_OS_T1T2_TAURUSV020101CN0601.nuzip","type":"NEWEST","version":"TAURUSV020101CN0601","size":300213139,"md5":"7673ec78e817e7b19963738d9b6f6d2b"},{"url":"http://static.vnnox.com/cn/vnnox_system/product_upgrade/accessory/UPDATE_OS_T3T4_TAURUSV020101CN0601.nuzip","type":"STABLE","version":"TAURUSV020501CN0501","size":3012146482,"md5":"7673ec78e817e7b19963738d9b6f6d2b"}]}
	 * @return_param code int 错误码：0
	 * @return_param onlineUpdatePackageInfos Object JSON对象
	 * @return_param url string 线上升级包下载链接
	 * @return_param type string 升级版版本类型 稳定版 "STABLE"  最新版 "NEWEST"
	 * @return_param version string 升级包版本号
	 * @return_param size long 升级包大小（字节）
	 * @return_param md5 string 升级包md5码
	 * @remark `code int 错误码：0 获取成功; 65370 获取线上升级包失败; 65376 网络连接异常` result string 返回信息，返回值示例和字段描述详见**返回示例**和**返回参数说明**
	 * @number 99
	 */
    VIPLEX_EXPORT void nvGetOnlineUpgradeFileAsync(const char *data, ExportViplexCallback  callback);

    VIPLEX_EXPORT void nvDownloadUpgradeFileAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/升级管理
	* @title 停止下载
	* @description 停止线上升级包下载的接口
	* @method
	* @url void nvStopDownloadUpgradeFileAsync(const string &data,  ExportViplexCallback  callback)
	* @header data 必选 string 请求的JSON参数，参数示例和字段描述详见`请求参数示例`和`参数`
	* @header  callback 必选 ExportViplexCallback 接收返回值的回调函数
	* @json_param ""
	* @return ""
	* @return_param code int 错误码：0
	* @remark `code int 错误码：0 获取成功` result string 返回信息，返回值示例和字段描述详见**返回示例**和**返回参数说明**
	* @number 99
	*/
    VIPLEX_EXPORT void nvStopDownloadUpgradeFileAsync(const char *data, ExportViplexCallback  callback);
	/**
	 * showdoc
	 * @catalog 接口示例/升级管理
	 * @title 获取升级描述文件内容
	 * @description 获取压缩包中的升级文件描述信息
	 * @method
	 * @url void nvReadFileContentFromZipFileAsync(const string &data,  ExportViplexCallback  callback)
	 * @header data 必选 string 请求的JSON参数，参数示例和字段描述详见`请求参数示例`和`参数`
	 * @header  callback 必选 ExportViplexCallback 接收返回值的回调函数
	 * @json_param {"zipFilePaths":["/sdcard/Android/data/UPDATE_OS_TAURUSV010501CN0301.nuzip"], "dFileNames":["package_description.json"]}
	 * @param zipFilePaths 必选 压缩包的路径
	 * @param dFileNames 必选 json的文件名，与压缩包路径一一对应
	 * @return {"zipFileContents":[{"commonSupportedProducts": ["T1", "T2", "T3", "T4", "T6", "T8", "T1-4G", "T2-4G", "TC300"], "description": "fgfgg", "totalSize": 34537490, "excutionType": "UPDATE", "version": "2.0.0.0602", "createdDate": "2020-03-13T11:32:51Z+08:00", "packetType": "BUNDLE", "packages": [{"version": "2.0.0.0602", "supportedPlatforms": ["rk3368", "rk312x"], "name": "Daemon-Terminal-release_2.0.0.0601-signed-aligned.apk", "supportedProducts": ["T1", "T2", "T3", "T4", "T6", "T8", "T1-4G", "T2-4G", "TC300"], "identifier": "RGFlbW9uLVRlcm1pbmFsLXJlbGVhc2VfMi4wLjAuMDYwMS1zaWduZWQtYWxpZ25lZC5hcGs=", "type": "APP", "startupAfterInstalled": "true", "size": 6674478}, {"version": "2.0.0.0602", "supportedPlatforms": ["rk3368", "rk312x"], "name": "Router-Terminal-release_2.0.0.0601-signed-aligned.apk", "supportedProducts": ["T1", "T2", "T3", "T4", "T6", "T8", "T1-4G", "T2-4G", "TC300"], "identifier": "Um91dGVyLVRlcm1pbmFsLXJlbGVhc2VfMi4wLjAuMDYwMS1zaWduZWQtYWxpZ25lZC5hcGs=", "type": "APP", "startupAfterInstalled": "true", "size": 6442643}, {"version": "2.0.0.0602", "supportedPlatforms": ["rk3368", "rk312x"], "name": "ScreenService-Terminal-release_2.0.0.0601-signed-aligned.apk", "supportedProducts": ["T1", "T2", "T3", "T4", "T6", "T8", "T1-4G", "T2-4G", "TC300"], "identifier": "U2NyZWVuU2VydmljZS1UZXJtaW5hbC1yZWxlYXNlXzIuMC4wLjA2MDEtc2lnbmVkLWFsaWduZWQuYXBr", "type": "APP", "startupAfterInstalled": "true", "size": 18543383}, {"version": "2.0.0.11", "supportedPlatforms": ["rk312x"], "name": "FPGA_T1-4G_T2-4G_2.0.0.11.bit.bin", "supportedProducts": ["T1-4G", "T2-4G"], "identifier": "RlBHQV9UMS00R19UMi00R18yLjAuMC4xMS5iaXQuYmlu", "type": "FPGA", "startupAfterInstalled": "true", "size": 465883}, {"version": "2.0.0.13", "supportedPlatforms": ["rk3368"], "name": "FPGA_T1_T2_2.0.0.13.bit.bin", "supportedProducts": ["T1", "T2"], "identifier": "RlBHQV9UMV9UMl8yLjAuMC4xMy5iaXQuYmlu", "type": "FPGA", "startupAfterInstalled": "true", "size": 803425}, {"version": "2.0.0.11", "supportedPlatforms": ["rk3368"], "name": "FPGA_T3_JT100_2.0.0.11.bit.bin", "supportedProducts": ["T3", "JT100"], "identifier": "RlBHQV9UM19KVDEwMF8yLjAuMC4xMS5iaXQuYmlu", "type": "FPGA", "startupAfterInstalled": "true", "size": 803701}, {"version": "2.0.0.18", "supportedPlatforms": ["rk3368"], "name": "FPGA_T4_T6_T8_2.0.0.18.bit.bin", "supportedProducts": ["T4", "T6", "T8"], "identifier": "RlBHQV9UNF9UNl9UOF8yLjAuMC4xOC5iaXQuYmlu", "type": "FPGA", "startupAfterInstalled": "true", "size": 803977}]}],"zipFilePaths":["data/data/com.example.myapp/app_flutter/log/UPDATE_APP_2.0.0.0602.nuzip"]}
	 * @return_param code int 错误码：0, 获取成功; 65314, 文件路径错误; 65315, 压缩包解压失败; 65316, json文件内容为空
	 * @return_param zipFileContents string json的内容
	 * @return_param zipFilePaths string 文件路径
	 * @remark `code int 错误码：0 获取成功; 65314, 文件路径错误; 65315, 压缩包解压失败; 65316, json文件内容为空` result string 返回信息，返回值示例和字段描述详见**返回示例**和**返回参数说明**
	 * @number 99
	 */
    VIPLEX_EXPORT void nvReadFileContentFromZipFileAsync(const char *data, ExportViplexCallback  callback);

    /**
    * showdoc
    * @catalog 接口示例/升级模块
    * @title 升级系统版本
    * @description 升级系统版本
    * @method
    * @url void nvUpdateOSAsync(const string &data,  ViplexCallback callback)
    * @header data 必选 string 请求的JSON参数，参数示例和字段描述详见`请求参数示例`和`参数`
    * @header callback 必选 ExportViplexCallback 接收返回值的回调函数
    * @json_param "{\"sn\":\"BZSA07313J0350001034\",\"filePath\":\"data/data/com.example.myapp/app_flutter/log/UPDATE_APP_2.1.0.0301.CTM1.0.2.nuzip\"}"
    * @param filePath 必选 升级包的路径
    * @param sn 必选 终端sn号
    * @return
    * @return_param  code int 错误码：0, 安装成功  {"bytesSent":75841536,"bytesTotal":81391147,"status":1};
    * @return_param  code int 错误码： 65320, 下载进度  {"bytesSent":75841536,"bytesTotal":81391147,"status":1};
    * @return_param  code int 错误码： 65321, 下载成功，准备升级 {"packageName":"UPDATE_APP_2.1.0.0301.CTM1.0.2.nuzip","packageType":"APP","status":0,"time":"2020-04-24 10:36:02:068","version":""}
    * @remark `
    * @number 99
    */
    VIPLEX_EXPORT void nvUpdateAppAsync(const char *data, ExportViplexCallback  callback);

    /**
    * showdoc
    * @catalog 接口示例/升级模块
    * @title 升级系统版本
    * @description 升级系统版本
    * @method
    * @url void nvUpdateOSAsync(const string &data,  ViplexCallback callback)
    * @header data 必选 string 请求的JSON参数，参数示例和字段描述详见`请求参数示例`和`参数`
    * @header callback 必选 ExportViplexCallback 接收返回值的回调函数
    * @json_param "{\"sn\":\"BZSA07313J0350001034\",\"filePath\":\"data/data/com.example.myapp/app_flutter/log/UPDATE_APP_2.1.0.0301.CTM1.0.2.nuzip\"}"
    * @param filePath 必选 升级包的路径
    * @param sn 必选 终端sn号
    * @return 
    * @return_param  code int 错误码： 65320, 下载进度  {"bytesSent":75841536,"bytesTotal":81391147,"status":1};
    * @return_param  code int 错误码： 65321, 下载成功，准备升级 {"packageName":"UPDATE_APP_2.1.0.0301.CTM1.0.2.nuzip","packageType":"APP","status":0,"time":"2020-04-24 10:36:02:068","version":""}
    * @remark `
    * @number 99
    */
    VIPLEX_EXPORT void nvUpdateOSAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/升级管理
	* @title 停止升级
	* @description 中断升级包传输的接口
	* @method
	* @url void nvStopCurrentUpdateTaskAsync(const string &data,  ExportViplexCallback  callback)
	* @header data 必选 string 请求的JSON参数，参数示例和字段描述详见`请求参数示例`和`参数`
	* @header  callback 必选 ExportViplexCallback 接收返回值的回调函数
	* @json_param {"sn":"BZSA07313J0350001034"}
	* @param sn 必选 string 产品唯一序列号
	* @return ""
	* @return_param code int 错误码：0, 获取成功;
	* @remark `code int 错误码：0 获取成功;` result string 返回信息，返回值示例和字段描述详见**返回示例**和**返回参数说明**
	* @number 99
	*/
    VIPLEX_EXPORT void nvStopCurrentUpdateTaskAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/升级管理
	* @title 包是否可升级判断接口
	* @description 包是否可升级判断接口
	* @method
	* @url void nvUpdateVerifyAsync(const string &data,  ExportViplexCallback  callback)
	* @header data 必选 string 请求的JSON参数，参数示例和字段描述详见`请求参数示例`和`参数`
	* @header  callback 必选 ExportViplexCallback 接收返回值的回调函数
	* @json_param {"sn":"BZSA07313J0350001034","verifyInfo":{"version": "TAURUSV010300CN1701","totalSize": 279077363,"description": "TAURUSV010300CN1701","packetType": "SINGLE","excutionType": "UPDATE","createdDate": "2018-08-10T21:04:23Z+08:00","packages": [{"type": "OS","version": "TAURUSV010300CN1701","name": "TAURUSV010300CN1701.zip"identifier": "VEFVUlVTVjAxMDMwMENOMTcwMS56aXA=","size": 279077363,"startupAfterInstalled": true,"isUpgradeAppAfterOS":true,"supportedProducts": ["T1","T2"],"supportedPlatforms":["rk3368","rk312x"]}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param verifyInfo 必选 Object JSON对象
	* @return ""
	* @return_param code int 错误码：0, 获取成功;
	* @remark `code int 错误码：0 获取成功; 11 权限不够; 20 没有空间的异常; 24 校验失败; 25 升级包不合法或错误; 26 签名不匹配; 51 升级时，通过产品和平台验证的FPGA的个数不是一个; 52升级校验时，终端产品不支持; 53 待升级软件版本低于当前终端已安装版本; 54 升级校验时，终端平台不支持; 65364 高版本回退低版本，不做校验，返回版本回退错误; 65365 当前终端版本不支持升级校验; 65350 终端已断开连接` result string 返回信息，返回值示例和字段描述详见**返回示例**和**返回参数说明**
	* @number 99
	*/
	VIPLEX_EXPORT void nvUpdateVerifyAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion UpgradeManager 升级 待修改类名（张鹏程）

#pragma region 网络配置
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI
    * @title 获取WIFI列表
    * @description 获取WIFI列表的接口
    * @method
    * @url void nvGetWifiListAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":""}
    * @param sn 必选 string 产品唯一序列号
    * @return {"result":[{"ssid":"AirStation","bssid":"00:24:a5:bc:f4:56","level":4,"security":"PSK:WPA2","state":5},{"ssid":"ESAY_PLUTO","bssid":"c8:3a:35:47:ee:08","level":3,"security":"WPA","state":0}]}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param result jsonarray wifi列表，json数组
    * @return_param ssid String wifi的ssid
    * @return_param bssid String wifi的bssid
    * @return_param level int wifi信号等级
    * @return_param security String 密码加密方式，PSK:WPA，PSK:WPA2，PSK:WPA_WPA2，EAP，WEP，NONE
    * @return_param state int wifi状态，0:闲置状态，即尚未连接过,1:已经配置过，即已经保存了密码,2:正在连接,3:正在授权,4:正在获取IP地址,5:已连接,6:密码错误,7:其他错误,8:已断开连接,9:正在断开连接
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetWifiListAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI
    * @title 连接wifi
    * @description 连接wifi的接口
    * @method
    * @url void nvConnectWifiNetworkAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"","taskInfo":{"ssid":"AP10006847","password":"12345678"}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 详情
    * @param ssid 必选 String wifi的ssid
    * @param password 必选 String 密码
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 错误码对应的具体描述
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvConnectWifiNetworkAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI
    * @title 断开连接
    * @description 断开连接的接口
    * @method
    * @url void nvDisconnectWifiNetworkAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"","taskInfo":{"ssid":"AP10006847"}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 详情
    * @param ssid 必选 String wifi的ssid
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 错误码对应的具体描述
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvDisconnectWifiNetworkAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI
    * @title 获取wifi的开启状态
    * @description 获取wifi的开启状态的接口
    * @method
    * @url void nvGetWifiEnabledAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":""}
    * @param sn 必选 string 产品唯一序列号
    * @return {"state":1}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param state int 1表示开启，0表示关闭
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetWifiEnabledAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI
    * @title 设置WIFI开启状态
    * @description 设置WIFI开启状态的接口
    * @method
    * @url void nvSetWifiEnabledAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"state":1}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 详情
    * @param state 必选 int 1表示开启，0表示关闭
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 错误码对应的具体描述
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetWifiEnabledAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI
    * @title 忘记密码
    * @description 忘记密码的接口
    * @method
    * @url void nvSendForgetWifiCommandAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"","taskInfo":{"ssid":"AP10006847"}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 详情
    * @param ssid 必选 String wifi的ssid
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时`19`不存在的异常
    * @return_param data Object 错误码对应的具体描述
    * @remark 如果忘记的wifi的密码为空时返回ErrorCode为： ERR_NOT_EXISTED
    * @number 99
    */
    VIPLEX_EXPORT void nvSendForgetWifiCommandAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/4G网络
    * @title 获取移动网络配置信息
    * @description 获取移动网络配置信息的接口
    * @method
    * @url void nvGetMobileNetworkAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":""}
    * @param sn 必选 string 产品唯一序列号
    * @return {"basicConfigs":{"mobileData":true,"dataRoaming":true,"enable4G":true,"level":1},"advanced":{"networkType":"AUTO","APN":{"providerName":"中国移动"}}}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param basicConfigs object 基础配置
    * @return_param mobileData boolean 移动数据开关是否打开
    * @return_param dataRoaming boolean 漫游是否打开
    * @return_param enable4G boolean 是否使能4G网络
    * @return_param level int 4G网络的信号强度0~5
    * @return_param advanced object 高级特性
    * @return_param networkType enum 网络类型，详细见说明部分(目前只支持AUTO)
    * @return_param APN object 	APN设置，预留
    * @return_param providerName string sim卡的运行商名称
    * @remark AUTO:模块内部自动选择
    * @number 99
    */
    VIPLEX_EXPORT void nvGetMobileNetworkAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/4G网络
    * @title 设置移动网络配置信息
    * @description 设置移动网络配置信息的接口
    * @method
    * @url void nvSetMobileNetworkAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"","mobileData":{"basicConfigs":{"mobileData":true,"dataRoaming":true,"enable4G":true},"advanced":{"networkType":"AUTO","APN":{"providerName":"中国移动"}}}}
    * @param sn 必选 string 产品唯一序列号
    * @param mobileData 必选 Object 请求对象信息
    * @param basicConfigs 必选 object 基础配置
    * @param mobileData 必选 boolean 移动数据开关是否打开
    * @param dataRoaming 必选 boolean 漫游是否打开
    * @param enable4G 必选 boolean 是否使能4G网络
    * @param advanced 必选 object 高级特性
    * @param networkType 必选 enum 网络类型，目前只支持 AUTO(自动)
    * @param APN 必选 object APN设置，预留
    * @param providerName string sim卡的运行商名称
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @remark AUTO:模块内部自动选择
    * @number 99
    */
    VIPLEX_EXPORT void nvSetMobileNetworkAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/4G网络
    * @title 获取移动上网模块是否存在
    * @description 获取移动上网模块是否存在的接口
    * @method
    * @url void nvIsMobileModuleExistedAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":""}
    * @param sn 必选 string 产品唯一序列号
    * @return {"existed":true}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param existed boolean true存在，false不存在
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvIsMobileModuleExistedAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/有线网络
    * @title 获取有线网络信息
    * @description 获取有线网络信息的接口
    * @method
    * @url void nvGetEthernetInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":""}
    * @param sn 必选 string 产品唯一序列号
    * @return {"ethernets":[{"scopeId":0,"name":"eth0","dhcp":false,"ip":"192.168.1.127","mask":"255.255.255.0","gateWay":"17.16.20.1","dns":["211.20.1.67"]}]}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param ethernets object 有线网络详情
    * @return_param scopeId int scopeId，如果 不知道，或者使用默认的，则填写-1
    * @return_param name string 名称，如 eth0,等等，可以指定的。
    * @return_param dhcp boolean true 的时候，表示使用动态地址分配，后面的字段无效
    * @return_param ip string ip地址
    * @return_param mask string 子网掩码
    * @return_param gateWay string 网关
    * @return_param dns string object DNS
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetEthernetInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/有线网络
    * @title 设置有线网络信息
    * @description 设置仔细核对IP地址等信息，否则会导致搜到不到终端
    * @method
    * @url void nvSetEthernetInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"ethernets":[{"scopeId":-1,"name":"eth0","dhcp":true,"ip":"172.16.9.192","mask":"255.255.255.0","gateWay":"172.16.9.254","dns":["172.16.0.201","172.16.0.202"]}]}}
    * @param sn 必选 string 产品唯一序列号
    * @param taskInfo 必选 Object 详情
    * @param ethernets 必选 Array 无
    * @param scopeId 必选 int scopeId，如果不知道，或者使用默认的，则填写-1
    * @param name 必选 string 名称，如 eth0,等等，可以指定的。
    * @param dhcp 必选 boolean true 的时候，表示使用动态地址分配，后面的字段无效
    * @param ip 必选 string ip地址
    * @param mask 必选 string 子网掩码
    * @param gateWay 必选 string 网关
    * @param dns string object	DNS
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 错误码对应的具体描述
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetEthernetInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 获取WiFi-AP信息
    * @description 获取WiFi-AP信息的接口
    * @method
    * @url void nvgGetAPNetworkAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":""}
    * @param sn 必选 string 产品唯一序列号
    * @return {"aliasName":"AP","password":"12345678","suffix":"20002272"}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param aliasName String AP别名
    * @return_param suffix String AP后缀
    * @return_param password String AP密码
	* @return_param channelId int 信道， 范围为1-11
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetAPNetworkAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 设置wifi-AP信息
    * @description 设置wifi-AP信息的接口
    * @method
    * @url void nvSetAPNetworkAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"BZSA07194A0049999716","aliasName":"AP","suffix":"0016","password":"12345678","channelId":10}
    * @param sn 必选 string 产品唯一序列号
    * @param aliasName 必选 String AP别名
    * @param suffix 必选 String AP后缀
    * @param password 必选 String AP密码,8<=密码长度<=32,数字加大小写字母，不能有特殊字符
    * @param channelId 必选 int 信道， 范围为1-11
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetAPNetworkAsync(const char *data, ExportViplexCallback  callback);

    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 获取APN信息
    * @description 获取APN信息
    * @method
    * @url void nvGetAPNInfoAsyncAsync(const char *data, ExportViplexCallback  callback)
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
    VIPLEX_EXPORT void nvGetAPNInfoAsync(const char *data, ExportViplexCallback  callback);

    /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 设置APN信息
    * @description 设置APN信息接口
    * @method
    * @url void nvSetAPNInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"BZSA17313J0820001562","APNs":[{"carrier":"Orange FR-MMS","mcc":"208","mnc":"01","apn":"orange.acte","user":"orange","password":"orange","server":"*","port":"80","mmsc":"http://mms.orange.fr","mmsproxy":"192.168.010.200","mmsport":"8080","type":"mms","isUserDefined":false,"isUsed":true},{"carrier":"中国移动彩信 (China Mobile)","mcc":"460","mnc":"00","apn":"cmwap","server":"*","proxy":"10.0.0.172","mmsc":"http://mmsc.monternet.com","mmsproxy":"10.0.0.172","mmsport":"80","type":"mms","protocol":"IPV4V6","isUserDefined":false,"isUsed":true}]}
    * @param sn string 产品唯一序列号
    * @param APNs object Apn信息列表
    * @param carrier string APN名称，可为空，只用来显示apn列表中此apn的显示名字
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
    * @return_param basicConfigs object 基础配置
    * @return_param mobileData bool 移动数据
    * @return_param dataRoaming bool 移动数据漫游
    * @return_param enable4G bool 4g数据
    * @return_param level int 数据信号强度值
	* @return_param advanced object 高级配置
	* @return_param networkType string 网络类型
	* @return_param APN object apn信息
	* @return_param providerName string 供应商名称
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetAPNInfoAsync(const char *data, ExportViplexCallback  callback);

   /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 设置飞行模式开关状态
    * @description 设置飞行模式开关状态
    * @method
    * @url void nvSetFlightModeAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"BZSA07194A0049999716","enable":true}
    * @param sn 必选 string 产品唯一序列号
    * @param enable 必选 bool 设置飞行模式开关状态
    * @return {"errorDiscription":"the description that describe the error in detail."}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data object 返回失败的data参数
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetFlightModeAsync(const char *data, ExportViplexCallback  callback);

   /**
    * showdoc
    * @catalog 接口示例/网络配置/WIFI-AP
    * @title 获取飞行模式开关状态
    * @description 获取飞行模式开关状态
    * @method
    * @url void nvGetFlightModeAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":"BZSA07194A0049999716"}
    * @param sn 必选 string 产品唯一序列号
    * @return {"enable":true}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param enable bool 飞行模式开关状态
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetFlightModeAsync(const char *data, ExportViplexCallback  callback);


    /**
     * showdoc
     * @catalog 接口示例/网络配置/WIFI-AP
     * @title 获取4G网络状态
     * @description 获取4G网络状态
     * @method
     * @url nvGet4GNetworkStatusAsync(const string &data, ExportViplexCallback  callback)
     * @json_param {"sn":"BZSA07194A0049999716"}
     * @param sn 必选 string 产品唯一序列号
     * @return {"mobileNetState":0,"netType":1}
     * @return_param code int 错误码：`0`获取成功`65535`请求超时
     * @return_param mobileNetState int 4G网络状态,1正常2异常0未知（当前连接有线网或WIFI）
     * @return_param netType int 网络类型,0：无网络，1：有线网，2：wifi，3：2G，4：3G,5:4G,6:未知
     * @remark
     * @number 99
     */
    VIPLEX_EXPORT void nvGet4GNetworkStatusAsync(const char *data, ExportViplexCallback  callback);

	/**
	 * showdoc
	 * @catalog 接口示例/网络配置/WIFI-AP
	 * @title 获取AP开启状态
	 * @description 获取AP开启状态
	 * @method
	 * @url nvGetAPNetworkOpenStatusAsync(const string &data, ExportViplexCallback  callback)
	 * @json_param {"sn":"BZSA07194A0049999716"}
	 * @param sn 必选 string 产品唯一序列号
	 * @return {"ebable":true}
	 * @return_param code int 错误码：`0`获取成功`65535`请求超时
	 * @return_param enable bool AP的开启状态
	 * @remark
	 * @number 99
	 */
	VIPLEX_EXPORT void nvGetAPNetworkOpenStatusAsync(const char *data, ExportViplexCallback  callback);

	/**
	 * showdoc
	 * @catalog 接口示例/网络配置/WIFI-AP
	 * @title 设置AP开启状态
	 * @description 设置AP开启状态
	 * @method
	 * @url nvSetAPNetworkOpenStatusAsync(const string &data, ExportViplexCallback  callback)
	 * @json_param {"sn":"BZSA07194A0049999716","enable":true}
	 * @param sn 必选 string 产品唯一序列号
	 * @param enable bool AP的开启状态
	 * @return "success"
	 * @return_param code int 错误码：`0`获取成功`65535`请求超时
	 * @remark
	 * @number 99
	 */
	VIPLEX_EXPORT void nvSetAPNetworkOpenStatusAsync(const char *data, ExportViplexCallback  callback);
	/**
	 * showdoc
	 * @catalog 接口示例/网络配置/WiFi-AP/Station切换
	 * @title 切换AP/Station（ap切换只有TC300支持，其他产品不支持）
	 * @description 此模块的功能是设置和回读WiFi-Ap/Station切换。
	 * @method
	 * @url void nvSetWifiApStationSwitchAsync(const char *data, ExportViplexCallback  callback);
	 * @json_param {"sn":"BZSA07201A0010000183","data":{"state":1,"ssid":"novastar","password":"nova123456"}}
	 * @param sn 必选 string 产品唯一序列号
	 * @param data 必选 Object 具体的命令协议
	 * @param state 必选 int 切换WIFI-AP/Station的状态，0 表示切换到wifi-ap，1 表示切换到wifi-station
	 * @param ssid 必选 string 当state为1 （wifi-station）时， 表示连接的wifi的ssid，当state为0 （wifi-ap）时， 表示ap的ssid
	 * @param password 必选 string 当state为1 （wifi-station）时， 表示连接的wifi的密码，当state为0 （wifi-ap）时， 表示ap的密码
	 * @return "data":null
	 * @return_param errorCode int 当返回成功时无意义，当返回失败时，返回失败原因
	 * @remark
	 * @number 99
	 */
	VIPLEX_EXPORT void nvSetWifiApStationSwitchAsync(const char *data, ExportViplexCallback  callback);
	/**
		* showdoc
		* @catalog 接口示例/网络配置/4G模块信息获取
		* @title 获取信息（定制版本，目前通用版本没有data结构体，后续可能会添加）
		* @description 获取4G模块相关信息
		* @method
		* @url void nvGetModuleInfoAsync(const char *data, ExportViplexCallback  callback);
		* @json_param {"sn":"BZSA07201A0010000183"}
		* @param sn 必选 string 产品唯一序列号
		* @param type 必选 String GET_MODULE_INFO
		* @return {"data":{"imei":"123456","model":"ZTE","version":"1.0.0"}}
		* @return_param imei string 模块imei号
		* @return_param model string 模块型号
		* @return_param version string 模块版本号(暂不清楚指红茶软SIM版本还是高新兴模块版本)
		* @return_param errorCode int 当返回成功时无意义，当返回失败时，返回失败原因
		* @remark
		* @number 99
		*/
	VIPLEX_EXPORT void nvGetModuleInfoAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion 网络配置 NetworkConfigurator

#pragma region ScreenConfiguration

    /**
   * showdoc
   * @catalog 接口示例/配屏/配屏
   * @title 获取配屏信息
   * @description 获取配屏信息的接口
   * @method
   * @url void void nvGetScreenAttributeAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"screenAttributes":[{"id":1,"screenSource":0,"xCount":1,"yCount":1,"xOffset":0,"yOffset":0,"portNumber":2,"orders":[0,1],"scanInfos":[{"width":128,"height":128,"x":0,"y":0,"xInPort":0,"yInPort":0,"portIndex":0,"connectIndex":0}]}]}
   * @return_param id int 显示屏id
   * @return_param screenSource int 配屏参数来源（`0`手机配屏,`1`LCT配屏）
   * @return_param xCount int X方向上接收卡个数
   * @return_param yCount int y方向上接收卡个数
   * @return_param xOffset int x方向上显示位置的偏移坐标
   * @return_param yOffset int y方向上显示位置的偏移坐标
   * @return_param portNumber int 所使用的网口数量
   * @return_param orders intArray 总共8种走线，数组内容顺序按照网口大小依次从小到大排列
   * @return_param scanInfos object 接收卡信息集合
   * @return_param width int 接收卡宽度
   * @return_param height int 接收卡高度
   * @return_param x int 接收卡所在显卡x坐标
   * @return_param y int 接收卡所在显卡y坐标
   * @return_param xInPort int 接收卡所在网口带载区域x坐标
   * @return_param yInPort int 接收卡所在网口带载区域y坐标
   * @return_param portIndex int 接收卡所在网口下标
   * @return_param connectIndex int 接收卡所在网口下的连接位置
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvGetScreenAttributeAsync(const char *data, ExportViplexCallback  callback);

    /**
   * showdoc
   * @catalog 接口示例/配屏/配屏
   * @title 设置配屏信息
   * @description 设置配屏信息的接口
   * @method
   * @url void void nvSetScreenAttributeAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272","screenAttribute":{"screenAttributes":[{"id":0,"orders":[0,1],"portNumber":1,"scanInfos":[{"connectIndex":0,"height":256,"portIndex":0,"width":256,"x":0,"xInPort":0,"y":0,"yInPort":0}],"screenSource":1,"xCount":1,"xOffset":0,"yCount":1,"yOffset":0}]}}
   * @param sn 必选 string 产品唯一序列号
   * @param screenAttribute 必选 object 配屏信息
   * @param screenAttributes 必选 objectArray 显示屏属性
   * @param id 必选 int 显示屏id
   * @param screenSource 必选 int 配屏参数来源（`0`手机配屏,`1`LCT配屏）
   * @param xCount 必选 int X方向上接收卡个数
   * @param yCount 必选 int y方向上接收卡个数
   * @param xOffset 必选 int x方向上显示位置的偏移坐标
   * @param yOffset 必选 int y方向上显示位置的偏移坐标
   * @param portNumber 必选 int 所使用的网口数量
   * @param orders 必选 intArray 总共8种走线，数组内容顺序按照网口大小依次从小到大排列
   * @param scanInfos 必选 object 接收卡信息集合
   * @param width 必选 int 接收卡宽度
   * @param height 必选 int 接收卡高度
   * @param x 必选 int 接收卡所在显卡x坐标
   * @param y 必选 int 接收卡所在显卡y坐标
   * @param xInPort 必选 int 接收卡所在网口带载区域x坐标
   * @param yInPort 必选 int 接收卡所在网口带载区域y坐标
   * @param portIndex 必选 int 接收卡所在网口下标
   * @param connectIndex 必选 int 接收卡所在网口下的连接位置
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvSetScreenAttributeAsync(const char *data, ExportViplexCallback  callback);

    /**
   * showdoc
   * @catalog 接口示例/配屏/接收卡文件配屏
   * @title 接收卡文件配屏接口
   * @description 接口的功能是终端可以通过接收卡文件配屏。该接口业务逻辑分为3步：1获取文件上传路径、2将本地文件上传到指定路径、3配屏
   * @method
   * @url void nvSetRecvCardFileAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272","filePath":"C:/test","fileName":"5036.rcfgx"}
   * @param sn 必选 string 产品唯一序列号
   * @param filePath 必选 string 	配屏文件的地址
   * @param fileName 必选 string 配屏文件的名称
   * @return ""
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvSetRecvCardFileAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion ScreenConfiguration 配屏 

#pragma region ICareConfigurator
    /**
   * showdoc
   * @catalog 接口示例/icare配置
   * @title 获取icare配置信息
   * @description 获取icare配置信息的接口
   * @method
   * @url void nvGetIcareConfigInfoAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA17332J0A20002272","requestInfo":{"language":"zh-cn"}}
   * @param sn 必选 string 产品唯一序列号
   * @param language 必选 string `zh-cn`中文,`en`英文
   * @return {"state":true,"serverNodes":[{"label":"测试","node":"t.novaicare.com"},{"label":"美国节点","node":"care-us.novaicare.com"},{"label":"中国节点","node":"care.novaicare.com"}],"url":"t.novaicare.com","username":"XXX","isOnline":true}
   * @return_param state bool 开启状态,true为开启,false为关闭
   * @return_param serverNodes object 所有服务器的地址
   * @return_param label string 服务器名称
   * @return_param node string 服务器地址
   * @return_param url string 当前连接的服务器地址
   * @return_param username string 绑定的用户名
   * @return_param isOnline bool 是否在线,true为在线,false为不在线
   * @return_param code int 错误码：`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvGetIcareConfigInfoAsync(const char *data, ExportViplexCallback  callback);

    /**
   * showdoc
   * @catalog 接口示例/icare配置
   * @title 设置icare配置信息
   * @description 设置icare配置信息的接口
   * @method
   * @url void nvSetIcareConfigInfoAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"sn":"BZSA17332J0A20002272","requestInfo":{"state":true,"url":"care.novaicare.com","username":"XXX"}}
   * @param sn 必选 string 产品唯一序列号
   * @param state 必选 bool 开启状态,true为开启,false为关闭
   * @param url 必选 string 当前连接的服务器地址
   * @param username 必选 string 绑定的用户名
   * @return ""
   * @return_param code int 错误码:`0`获取成功`33`账号不存在`34`未配屏`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvSetIcareConfigInfoAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion ICareConfigurator icare配置

#pragma region CloudConfigurator

    /**
   * showdoc
   * @catalog 接口示例/终端cloud配置
   * @title 绑定Cloud服务器
   * @description 绑定Cloud服务器的接口
   * @method
   * @url void nvSetBindPlayerAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"sn":"BZSA07194A0049999716","playerInfo":{"baseUrl":"https://api-cn.vnnox.com","data":{"playerList":[{"identifier":"84f37cb1a12783654780f47da13b55db##dangjintao","isUsed":true,"name":"dangjintao","playerIdentifier":"BZSA07194A0049999716"}],"token":"f2972f5a403d5e13d1c6103f91bf78a58055bfd5"},"isNewVnnox":true,"password":"123456","username":"gmt"}}
   * @param sn 必选 string 产品唯一序列号
   * @param baseUrl 必选 string 用于更换服务器时,终端访问对应服务器主机地址
   * @param password 必选 string 播放机认证的密码
   * @param username 必选 string 	播放机认证的用户名
   * @param isNewVnnox 必选 bool 绑定的是否为新的vnnox
   * @param token 必选 string 播放机交互TOKEN(播放器与服务器交互,要将此TOKEN加入http协议header中)
   * @param identifier 必选 string 服务端播放机唯一标识(从VNNOX获取的Identifer+"##播放器名称")
   * @param isUsed 必选 bool 服务端播放机是否已绑定
   * @param name 必选 string 服务端播放机名称
   * @param playerIdentifier 必选 string 终端播放器唯一标识
   * @return ""
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvSetBindPlayerAsync(const char *data, ExportViplexCallback  callback);

    /**
   * showdoc
   * @catalog 接口示例/终端cloud配置
   * @title 获取播放器列表
   * @description 获取播放器列表的接口
   * @method
   * @url void nvGetCloudPlayerListAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"host":"http://beta-rest.vnnox.com","data":{"username":"qht1003077897","password":"qht1003077897","playerType":2}}
   * @param host 必选 string 服务器地址
   * @param username 必选 string 播放机认证的用户名
   * @param password 必选 string 播放机认证的密码
   * @param playerType 必选 int `1`同步，`2`异步
   * @return {"status":[10000],"data":{"token":"654ad5s64f65w46f5e456wa4f","playerList":[{"name":"player_1","identifier":"654ad-5s64f6-5w46-f5e45-6wa4f","isUsed":true,"playerIdentifier":"33-22-44-22-44"}]}}
   * @return_param status int 返回结果状态
   * @return_param token string 播放机交互TOKEN(播放器与服务器交互)
   * @return_param name string 服务端播放机名称
   * @return_param identifier string 服务端播放机唯一标识
   * @return_param isUsed bool 服务端播放机是否已绑定
   * @return_param playerIdentifier string 终端播放器唯一标识
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvGetCloudPlayerListAsync(const char *data, ExportViplexCallback  callback);
    /**
   * showdoc
   * @catalog 接口示例/终端cloud配置
   * @title 获取播放器绑定信息
   * @description 获取播放器绑定信息的接口
   * @method
   * @url void nvGetBindPlayerAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"sn":"BZSA07194A0049999716"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"isBind":true,"errorDescription":" ","baseUrl":"http://test.vnnox.com","password":"wxgaly199425","username":"wxgaly","status":[10000],"data":{"token":"9e49437a8bc44ba790389524b74c76acdc7909e6","playerList":[{"identifier":"103190fdfa52c37516aae26a9d00ed7c","isUsed":true,"name":"异步播放机1","playerIdentifier":"30:34:00:00:00:17"}]}}
   * @return_param isBind bool 终端播放器是否被绑定
   * @return_param errorDescription string 播放器未被绑定的错误信息
   * @return_param baseUrl string 用于更换服务器时，终端访问对应服务器主机地址
   * @return_param password string 播放机认证的密码
   * @return_param username string 播放机认证的用户名
   * @return_param status intarray 播放机当前心跳状态(10000表示心跳正常)
   * @return_param token string 播放机交互TOKEN(播放器与服务器交互)
   * @return_param name string 服务端播放机名称
   * @return_param identifier string 服务端播放机唯一标识
   * @return_param isUsed bool 服务端播放机是否已绑定
   * @return_param playerIdentifier string 终端播放器唯一标识
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvGetBindPlayerAsync(const char *data, ExportViplexCallback  callback);

#pragma endregion CloudConfigurator 终端cloud配置

#pragma region MonitorConfigurator
    /**
   * showdoc
   * @catalog 接口示例/监控/获取系统参数
   * @title 获取硬盘存储信息
   * @description 获取硬盘存储信息
   * @method
   * @url void void nvGetAvailableStorageDataAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"sn":"BZSA07194A0049999716"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"diskAvailableSize":3.67,"diskTotalSize":3.96,"storageInfos":[{"diskAvailableSize":3938967552,"diskCriticalSize":524288000,"diskReserveSize":0,"diskTotalSize":4248846336,"type":"LOCAL"}]}
   * @return_param diskTotalSize float 外部存储空间总大小,单位G
   * @return_param diskAvailableSize float 可用空间大小,单位G
   * @return_param storageInfos object 存储空间信息
   * @return_param diskAvailableSize float 磁盘可用空间大小,单位Byte
   * @return_param diskCriticalSize float 磁盘空间不足预警阀值,当剩余存储空间小于该值,部分功能可能无法正常使用,单位Byte
   * @return_param diskReserveSize float 磁盘内部预留空间,单位Byte
   * @return_param diskTotalSize float 磁盘存储空间总大小,单位Byte
   * @return_param type string 磁盘类型,`LOCAL`内部存储（SD卡）`EXTERNAL`外部存储（U盘等）
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvGetAvailableStorageDataAsync(const char *data, ExportViplexCallback  callback);

    /**
   * showdoc
   * @catalog 接口示例/监控/获取系统参数
   * @title 获取CPU使用率
   * @description 获取CPU使用率的接口
   * @method
   * @url void nvGetCPUUsageAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA07194A0049999716"}
   * @param sn 必选 string 产品唯一序列号
   * @return {"value":18}
   * @return_param value float CPU使用率
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvGetCPUUsageAsync(const char *data, ExportViplexCallback  callback);

/**
* showdoc
* @catalog 接口示例/监控/获取系统参数
* @title 获取CPU温度
* @description 获取CPU温度的接口
* @method
* @url void nvGetCPUTempAsyncAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"sn":"BZSA07194A0049999716"}
* @param sn 必选 string 产品唯一序列号
* @return {"value":38.8}
* @return_param value float CPU使用率
* @return_param code int 错误码:`0`获取成功`65535`请求超时
* @remark
* @number 99
*/
	VIPLEX_EXPORT void nvGetCPUTempAsync(const char *data, ExportViplexCallback  callback);

/**
* showdoc
* @catalog 接口示例/监控/获取系统参数
* @title 获取可用内存
* @description 获取可用内存的接口
* @method
* @url void nvGetAvailableMemoryAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"sn":"BZSA07194A0049999716"}
* @param sn 必选 string 产品唯一序列号
* @return {"value":18}
* @return_param value float CPU使用率
* @return_param code int 错误码:`0`获取成功`65535`请求超时
* @remark
* @number 99
*/
	VIPLEX_EXPORT void nvGetAvailableMemoryAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/监控
	* @title 获取发送卡的监控信息
	* @description 获取发送卡的监控信息
	* @method
	* @url void nvGetSendCardMonitorInfoAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA07194A0049999716"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"sendCardMonitorInfo":[{"isDVIConnected": true,"DVIRate": 60,"redundancePortInfo": [{"isRedundant": false,"devMappingList": [{"devIndex": 0,"devType": 1},{"devIndex": 0,"devType": 2},{"devIndex": 0,"devType":3}],"deviceWorkState": 1},	{"isRedundant": true,"devMappingList": [{"devIndex": 0,"devType": 1},{"devIndex": 0,"devType": 2},{"devIndex": 1,"devType": 3}],"deviceWorkState": 0}],"deviceMapList": [{"deviceIndex": 0,"deviceType": 1}, {"deviceIndex": 0,"deviceType": 2}],"deviceWorkState": 0}]}
	* @return_param code int 错误码:`0`获取成功`65535`请求超时
	* @return_param sendCardMonitorInfo	object	发送卡的监控数据
	* @return_param deviceWorkState	int	工作状态， 正常OK=1，异常 Error = 1， 未知 Unknown = 2
	* @return_param deviceMapList	object	设备的位置索引信息
	* @return_param deviceIndex	int	设备所在位置编号，设备串联上的第几个
	* @return_param deviceType	int	设备类型
	* @return_param isDVIConnected	boolean	DVI源是否连接
	* @return_param DVIRate	int	DVI刷新率，仅在DVI连接时才有效
	* @return_param redundancePortInfo	object	网口信息的列表
	* @return_param deviceWorkState	int	工作状态， 正常OK=1，异常 Error = 1， 未知 Unknown = 2
	* @return_param deviceMapList	object	设备的位置索引信息
	* @return_param deviceIndex	int	设备所在位置编号，设备串联上的第几个
	* @return_param deviceType	int	设备类型
	* @return_param isRedundant	boolean	是否是冗余网口
    * @return_param isWorking boolean 工作状态
    * @return_param portIndex int 端口的id
    * @return_param portProperty int 网口数据，0-主口，1-冗余口
    * @return_param sourcesInAndOut string 内外源状态
    * @return_param withScreen boolean 配屏状态
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetSendCardMonitorInfoAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/监控
	* @title 获取接收卡的数量及信息
	* @description 获取接收卡的数量及信息
	* @method
	* @url void nvGetReceiverCountAndInfoAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA07194A0049999716"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"receiveCardRegionInfo":[{"senderIndex": 0,"portIndex": 0,"connectIndex": 0,"X": 0,"Y": 0,"XInPort": 0,"YInPort": 0,"width": 400,"height": 400,"rowIndexInScreen": 0,"colIndexInScreen": 0}]}
	* @return_param code int 错误码:`0`获取成功`65535`请求超时
	* @return_param receiveCardRegionInfo	object	所有接收卡的位置和大小信息
	* @return_param senderIndex byte 所属发送卡序号， 若为-1，表示留空
	* @return_param portIndex	byte	所属输出口序号
	* @return_param connectIndex	int	位于所在输出口的第几个
	* @return_param X	int	X位置(在其所在显卡的X坐标)
	* @return_param Y	int	Y位置(在其所在显卡的Y坐标)
	* @return_param XInPort	int	X位置(在其所在Port带载区域的X坐标)
	* @return_param YInPort	int	Y位置(在其所在Port带载区域的Y坐标)
	* @return_param width	int	带载像素宽度
	* @return_param height	int	带载像素高度
	* @return_param rowIndexInScreen	int	位于屏体第几行
	* @return_param colIndexInScreen	int	位于屏体第几列
    * @return_param distributorIndex int 分线器下标
    * @return_param distributorPortIndex int 分线器网口下标
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetReceiverCountAndInfoAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/监控
	* @title 根据接收卡索引获取监控信息
	* @description 根据接收卡索引获取监控信息接口
	* @method
	* @url void nvGetMonitorInfoByReceiverIndexAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"info":{"receiveCardRegionInfo": [{"portIndex":0,"connectedIndex":0},{"portIndex":0,"connectedIndex":1}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param receiveCardRegionInfo 必选 object 所要获取的接收卡的位置信息
	* @param portIndex 必选 byte 所属输出口序号，网口位置
	* @param connectedIndex 必选 int 位于所在输出口的第几个
	* @return {"receiveCardRegionInfo":[{"portIndex":0,"connectedIndex":0},{"portIndex":0,"connectedIndex":1}]}
	* @return_param code int 错误码:`0`获取成功`65535`请求超时
	* @return_param screenMonitorData	object	监控数据
	* @return_param receiveCardMonitorInfo	object	接收卡的监控数据
	* @return_param deviceWorkState	int	工作状态， 正常OK=1，异常 Error = 1， 未知 Unknown = 2
	* @return_param deviceMapList	object	接受卡的位置索引信息
	* @return_param deviceIndex	int	设备所在位置编号，设备串联上的第几个
	* @return_param deviceType	int	设备类型
	* @return_param temprature	float	接收卡本板温度
	* @return_param voltage	float	接收卡本板电压
	* @return_param monitorCardMonitorInfo	object	监控卡的监控数据
	* @return_param deviceWorkState	int	工作状态， 正常OK=1，异常 Error = 1， 未知 Unknown = 2
	* @return_param deviceMapList	object	设备的位置索引信息
	* @return_param deviceIndex	int	设备所在位置编号，设备串联上的第几个
	* @return_param deviceType	int	设备类型
	* @return_param temperatureUpdateInfo	object	温度状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param temprature	float	温度值, -255表示无效温度
	* @return_param humidityUpdateInfo	object	湿度状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param humidity	float	湿度值
	* @return_param smokeUpdateInfo	object	烟雾状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param smoke	boolean	是否有烟雾
	* @return_param cabinDoorUpdateInfo	object	箱门状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param isDoorOpen	boolean	箱门是否打开
	* @return_param fansUpdateInfo	object	风扇状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param fansMonitorInfoCollection	HashMap	风扇转速，key为第几路风扇，value为风扇转速
	* @return_param powerUpdateInfo	object	电源状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param powerMonitorInfoCollection	HashMap	电压监控，key为第几路电源，value为电源电压, 0路为监控卡的电压，其他1到8是8路电源电压
	* @return_param socketCableUpdateInfo	object	排线状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param socketCableMonitorInfoList	object	排线信息
	* @return_param deviceWorkState	int	工作状态， 正常OK=1，异常 Error = 1， 未知 Unknown = 2
	* @return_param deviceMapList	object	设备的位置索引信息
	* @return_param deviceIndex	int	设备所在位置编号，设备串联上的第几个
	* @return_param deviceType	int	设备类型
	* @return_param socketCableInfoMap	HashMap	ke为int， value为object List
	* @return_param isCableOK	boolean	设备所在位置编号，设备串联上的第几个
	* @return_param cableType	int	排线数据类型
	* @return_param moduleUpdateInfo	object	模组状态信息
	* @return_param isUpdate	boolean	是否更新
	* @return_param moduleMonitorInfoCollection	HashMap	电压监控，keyint，value为Object，ModuleStatus
	* @return_param deviceWorkStatus	int	工作状态
	* @return_param busIndex	int	flash所在总线下标
	* @return_param flashIndex	int	flash下标
	* @return_param rowIndex	int	行坐标
	* @return_param colIndex	int	列坐标
	* @return_param temperature	float	温度
	* @return_param voltage	float	电压
	* @return_param workTime	long	工作时间
    * @return_param fpgaHardwareVersionInfo string fpga版本信息
    * @return_param hardwareDeviceodel int modelID
    * @return_param remarksVersionInfo string 设备备注信息
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetMonitorInfoByReceiverIndexAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion MonitorConfigurator 监控 

#pragma region ScreenManager
	/**
	  * showdoc
	  * @catalog 接口示例/屏体其他项/校时
	  * @title 获取时区
	  * @description 获取时区的接口
	  * @method
	  * @url void nvGetCurrentTimeAndZoneAsync(const char * data, ExportViplexCallback  callback)
	  * @json_param {"sn":""}
	  * @param sn 必选 string 产品唯一序列号
	  * @return {"utcTimeMillis":1585190230828,"timeZone":"Europe/London","currentTime":"2020-03-26 02:37:10","isTimeOffsetEnable":true,"beginTime":"","endTime":"","timeOffsetValue":0,"gmt":"GMT+08:00"}
	  * @return_param code int 错误码：`0`获取成功`65535`请求超时
	  * @return_param data Object 返回值具体描述
	  * @return_param utcTimeMillis long utc时间的毫秒表示
	  * @return_param timeZone string 时区，例如"Asia/Shanghai"
	  * @return_param gmt string 时区gmt，例如"GMT+08:00"
	  * @return_param isTimeOffsetEnable boolean 是否开启时间补偿，开启为true，否则false
	  * @return_param beginTime string 补时开始时间，传递开始的月和天，例如"2020-05-23"
	  * @return_param endTime string 补时结束时间，传递开始的月和天，例如"2020-12-23"
	  * @return_param timeOffsetValue long 时间补偿值，以秒为单位，带符号数。例如:+6000
      * @return_param orderId int 服务端的orderid，命令标识
	  * @remark
	  * @number 99
	  */
	VIPLEX_EXPORT void nvGetCurrentTimeAndZoneAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项/校时
	* @title 设置卡上的时间
	* @description 设置卡上的时间的接口
	* @method
	* @url void nvCalibrateTimeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","currentTime":"2020-03-26 02:37:10","timeZoneInfo":{"utcTimeMillis":1585190230828,"timeZone":"Europe/London","isTimeOffsetEnable":true,"beginTime":"","endTime":"","timeOffsetValue":0,"gmt":"GMT-08:00"}}
	* @param sn 必选 string 产品唯一序列号
	* @param currentTime 必选 string 当前时区对应的时间
	* @param timeZoneInfo 必选 Object 时区详情
	* @param utcTimeMillis 必选 long utc时间的毫秒表示
	* @param timeZone 必选 string 时区，例如"Asia/Shanghai"
	* @param gmt 必选 string 时区gmt，例如"GMT-08:00"
	* @param isTimeOffsetEnable 必选 boolean 是否开启时间补偿，开启为true，否则false
	* @param beginTime 必选 string 补时开始时间，传递开始的月和天，例如"2020-05-23"
	* @param endTime 必选 string 补时结束时间，传递开始的月和天，例如"2020-05-23"
	* @param timeOffsetValue 必选 long 时间补偿值，以秒为单位，带符号数。例如：-6000
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @return_param utcTimeMillis long utc时间的毫秒表示
	* @return_param timeZone string 时区，例如"Asia/Shanghai"
	* @return_param gmt string 时区gmt，例如"GMT-08:00"
	* @return_param isTimeOffsetEnable boolean 是否开启时间补偿，开启为true，否则false
	* @return_param timeOffsetValue long 时间补偿值，以秒为单位，带符号数。例如：-6000
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvCalibrateTimeAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项/NTP校时
	* @title 获取对时配置
	* @description 获取对时配置，通过此接口可获取到ntp对时和Lora对时taskArray数组，不区分版本，低版本通过旧网络对时协议获取到信息后，转换为0x99协议的形式
	* @method
	* @url void nvGetNetTimingInfoAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":""}
	* @param sn 必选 string 产品唯一序列号
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"LORA_SYNC","action":5,"status":1,"data":{"enable":true,"address":1,"channel":23,"mode":"MASTER","groupId":"novad101","regulation":{"timeEnable":false,"brightnessEnable":true,"volumeEnable":true,"environmentalMonitoring":true}}},{"type":"NTP_CONFIG","action":5,"status":1,"data":{"enable":true,"server":"http://ntpsss.net"}}]}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 返回值具体描述
	* @return_param source object 下发命令的来源
	* @return_param type int 1：nova自己的平台,0：第三方平台
	* @return_param platform int 1:手机、2:CS、3:平板、4:VNNOX、5:Care、6:LCT、7:Lora
	* @return_param taskArray object 任务数组
	* @return_param type string 表征业务类型,固定值:"NTP_CONFIG",或者固定值:"LORA_SYNC"
	* @return_param action int 表征此命令的动作，固定值：ACTION_SET(5)
	* @return_param status int 成功或失败,0:未知状态;1:成功;2:失败
	* @return_param data object NTP校时配置项
	* @return_param enable boolean ntp是否使能
	* @return_param server string ntp服务器地址
	* @return_param data object 射频同步配置项
	* @return_param enable boolean 射频同步使能
	* @return_param mode string 主从模式"MASTER"or"SLAVE"
	* @return_param address int 目标地址
	* @return_param channel int 目标信道
	* @return_param groupId string 组id，用户划分设备组,(字符串格式，最大长度为10个字节，由上位机做限制)
	* @return_param regulation object 同步使能规则
	* @return_param timeEnable boolean 时间同步使能
	* @return_param brightnessEnable boolean 亮度同步使能
	* @return_param volumeEnable boolean 音量同步使能
	* @return_param environmentalMonitoring boolean 环境检测数据同步使能
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetNetTimingInfoAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项/NTP校时
	* @title NTP校时配置
	* @description 设置对时配置，包括配置ntp对时和lora对时，以数组的形式下发，也可以单独下发ntp或者lora
	* @method
	* @url void nvSetNetTimingInfoAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA17332J0A20002272","TimingInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"LORA_SYNC","action":4,"data":{"enable":true,"address":1,"channel":23,"mode":"MASTER","groupId":"novad101","regulation":{"timeEnable":false,"brightnessEnable":true,"volumeEnable":true,"environmentalMonitoring":true}}},{"type":"NTP_CONFIG","action":4,"data":{"enable":true,"server":"http://ntpsss.net"}}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param TimingInfo 必选 string 对时配置对象
	* @param source 必选 object 下发命令的来源
	* @param type 必选 int 1：nova自己的平台,0：第三方平台
	* @param platform 必选 int 1：手机、2：CS、3：平板、4：VNNOX、5：Care、6：LCT、7:Lora
	* @param taskArray 必选 object 任务数组
	* @param type 必选 string 表征业务类型,固定值："NTP_CONFIG"，或者固定值："LORA_SYNC"
	* @param action 必选 int 表征此命令的动作，固定值：ACTION_SET
	* @param data 必选 object NTP校时配置项
	* @param enable 必选 boolean ntp是否使能
	* @param server 必选 string ntp服务器地址
	* @param data 必选 object 射频同步配置项
	* @param enable 必选 boolean 射频同步使能
	* @param mode 必选 string 主从模式"MASTER"or"SLAVE"
	* @param address 必选 int 目标地址
	* @param channel 必选 int 目标信道
	* @param groupId 必选 string 组id，用户划分设备组,(字符串格式，最大长度为10个字节，由上位机做限制)
	* @param regulation 必选 object 同步使能规则
	* @param timeEnable 必选 boolean 时间同步使能
	* @param brightnessEnable 必选 boolean 亮度同步使能
	* @param volumeEnable 必选 boolean 音量同步使能
	* @param environmentalMonitoring 必选 boolean 环境检测数据同步使能
	* @return {"taskArray":[{"action":4,"errorCode":0,"status":1,"type":"NTP_CONFIG"},{"action":4,"errorCode":0,"status":1,"type":"LORA_SYNC"}]}
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data Object 错误码对应的具体描述
	* @return_param type string 表征业务类型,固定值："NTP_CONFIG"或"LORA_SYNC"
	* @return_param action int 表征此命令的动作，固定值：ACTION_GET(4)
	* @return_param status int 成功或失败，0:未知状态；1:成功；2:失败
	* @return_param errorCode int 错误码
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetNetTimingInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/其他/对时服务器列表
    * @title 获取时间服务器列表
    * @description 1.获取对时服务器列表，由两部分组成，用户自定义及服务器获取到的列表，服务器获取到的列表会根据语言返回对应的地址，服务器列表地址如：http://download.vnnox.com/vnnox_api_host/timehost.json2.服务器获取到的列表不可修改
    * @method
    * @url void nvGetNetTimingListInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"lang":"en"}
    * @param lang 必选 string 语言，英文：en，中文：zh-cn，日文：jp，韩文：kr，西班牙语：es，法语：fr
    * @return {"serverInfo":[{"islocal":true,"label":"aa","node":"www.baidu.com"}]}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data string 返回值错误码对应的说明
    * @return_param serverInfo array 返回服务器列表数组
    * @return_param islocal bool 是否是用户自定义添加的数据，true：用户自定义，false：服务器获取
    * @return_param label string 节点名称
    * @return_param node string 节点地址
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetNetTimingListInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/其他/对时服务器列表
    * @title 添加对时服务器
    * @description 添加对时服务器的接口
    * @method
    * @url void nvAddNetTimingInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"label":"aa","node":"www.baidu.com"}
    * @param label 必选 string 节点名称
    * @param node 必选 string 节点地址
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvAddNetTimingInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/其他/对时服务器列表
    * @title 删除对时服务器
    * @description 删除对时服务器列表，如果存在两条node和label都完全一致的数据，则删除第一条
    * @method
    * @url void nvDeleteNetTimingInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"label":"aa","node":"www.baidu.com"}
    * @param label 必选 string 节点名称
    * @param node 必选 string 节点地址
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvDeleteNetTimingInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/其他/对时服务器列表
    * @title 修改对时服务器
    * @description 修改对时服务器列表,修改服务器列表,如果存在两条node和label都完全一致的数据,则修改第一条
    * @method
    * @url void nvUpdateNetTimingInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"oldServer":{"label":"zhangsan","node":"123.123.123"},"newServer":{"label":"lisi","node":"111.111.111"}}
    * @param oldServer 必选 Object 被修改的服务器信息
    * @param label 必选 string 节点名称
    * @param node 必选 string 节点地址
    * @param newServer 必选 Object 修改后的服务器信息
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvUpdateNetTimingInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/其他/对时服务器列表
    * @title 添加对时服务器列表
    * @description 添加对时服务器列表的接口
    * @method
    * @url void nvAddNetTimingInfoListAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"serverInfo":[{"label":"aa","node":"www.baidu.com"},{"label":"aa","node":"www.baidu.com"}]}
    * @param serverInfo 必选 array 服务器列表数组
    * @param label 必选 string 节点名称
    * @param node 必选 string 节点地址
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvAddNetTimingInfoListAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/其他/校时
	* @title 获取是否夏令时
	* @description 获取是否夏令时的接口
	* @method
	* @url void nvGetIsUseDayLightTimeAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"isUseDayLightTimeData":{"timeZone":"Asia/Shanghai","gmt":"GMT+08:00"}
	* @param isUseDayLightTimeData 必选 Object 获取是否夏令时信息
	* @param gmt 必选 string 时区gmt
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时
	* @return_param data string 返回值错误码对应的说明
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetIsUseDayLightTimeAsync(const char *data, ExportViplexCallback  callback);
	
	
#pragma region ScreenShot 
    /**
     * showdoc
     * @catalog 接口示例/屏体管理
     * @title 获取终端截图
     * @description 获取终端截图
     * @method
     * @url void nvDownLoadScreenshotAsync(const char *data, ExportViplexCallback  callback);
     * @json_param {"sn":"","width":100,"height":100,"downLoadDirectoryPath":"d://","pictureName":"a.png","pictureType":1}
     * @param sn 必选 string 产品唯一序列号
     * @param width 必选 int 图片宽度
     * @param height 必选 int 图片高度
     * @param pictureType 必选 int 图片格式，0代表png格式，1代表jpg格式
     * @param downLoadDirectoryPath 必选 string 截图下载路径
     * @param pictureName 必选 string 截图文件名字
     * @return {"code":0,"path":"/cache/screenShots/screenshot.png"}
     * @return_param code int 错误码：`0`获取成功`65535`请求超时
     * @return_param path string 截图路径
     * @remark
     * @number 90
     */
    VIPLEX_EXPORT void nvDownLoadScreenshotAsync(const char *data, ExportViplexCallback  callback);

	VIPLEX_EXPORT void nvDownLoadScreenshotNetAsync(const char* data, ExportViplexCallback  callback);
#pragma endregion ScreenShot 截屏

#pragma endregion ScreenManager 屏体其他项
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项/旋转屏幕
	* @title 屏幕旋转设置
	* @description 此功能V1.6.0以后增加，旋转屏幕后，节目的宽高也做了置换。 客户在某种场景需要旋转屏幕，节目也同时达到旋转的效果，因此增加此设置。
	* @method
	* @url void nvSetRotationAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"ROTATION","action":4,"data":{"rotationValue":1}}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："ROTATION"
	* @param data 必选 object 屏幕旋转的数据
	* @param rotationValue 必选 int 旋转的角度值仅仅支持：0：0°，1：90°，2：180°，3：270°
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"ROTATION","action":4,"status":1,"errorCode":0}]}
	* @return_param errorCode short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetRotationAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项/旋转屏幕
	* @title 回读旋转设置
	* @description 此功能V1.6.0以后增加，旋转屏幕后，节目的宽高也做了置换。 客户在某种场景需要旋转屏幕，节目也同时达到旋转的效果，因此增加此设置。
	* @method
	* @url void nvGetRotationAsync(const char *data, ExportViplexCallback  callback)
	* @json_param {"sn":"BZSA07194A0049999716","taskInfo":{"source":{"type":1,"platform":1},"taskArray":[{"type":"ROTATION","action":5}]}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："ROTATION"
	* @param data 必选 object null
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"ROTATION","action":5,"status":1,"data":{"rotationValue":1}}]}
	* @return_param errorCode short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @return_param data object 当返回失败时无意义，当返回成功时，存放旋转参数
	* @return_param rotationValue int 旋转的角度值仅仅支持：0：0°，1：90°，2：180°，3：270°
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetRotationAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项/屏幕尺寸信息
	* @title 屏幕尺寸获取
	* @description 此功能V1.7.0以后增加，因为旋转屏幕后，节目的宽高发生了变化，上位机通过此接口获取宽高及其旋转角度。
	* @method
	* @url void nvGetDisplayInfoAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA07201A0010000183"}
	* @param sn 必选 string 产品唯一序列号
	* @return {"source":{"type":1,"platform":1},"taskArray":[{"type":"DISPLAY_INFO","action":5,"status":1,"data":{"width":400,"height":400,"rotation":0}}]}
	* @return_param code short 错误码
	* @return_param width int 屏幕宽度
	* @return_param height int 	屏幕高度
	* @return_param rotation int 旋转的角度值仅仅支持：0，90，180，270
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvGetDisplayInfoAsync(const char *data, ExportViplexCallback  callback);
	/**
	* showdoc
	* @catalog 接口示例/屏体其他项/校时（新协议0x99）
	* @title 校时（新协议0x99）
	* @description 此模块为终端校时与vnnox的交互协议，目前vnnox只有对时区，协议是支持校时区和时间。
	* @method
	* @url void nvSetTimeAndZoneAsync(const char *data, ExportViplexCallback  callback);
	* @json_param {"sn":"BZSA07201A0010000183","taskInfo":{"data":{"utcTimeMillis":1234455433,"timeZone":"Asia/Shanghai","gmt":"GMT+08:00","isTimeOffsetEnable":true,"beginTime":"5-23","endTime":"12-23","timeOffsetValue":6000}}}
	* @param sn 必选 string 产品唯一序列号
	* @param type 必选 string 表征业务类型,固定值："TIME_AND_ZONE"
	* @param data 必选 object 开关屏操作
	* @param utcTimeMillis 必选 long utc时间的毫秒表示，如果只校时区，该字段为0
	* @param timeZone 必选 string 时区，例如"Asia/Shanghai"
	* @param gmt 必选 string 时区gmt，例如"GMT-08:00"
	* @param isTimeOffsetEnable 必选 boolean 是否开启时间补偿，开启为true，否则false
	* @param beginTime 必选 string 补时开始时间，传递开始的月和天，例如"5-23"
	* @param endTime 必选 string 补时结束时间，传递开始的月和天，例如"12-23"
	* @param timeOffsetValue 必选 long 时间补偿值，以秒为单位，带符号数。例如：-6000
	* @return ""
	* @return_param errorCode short 错误码，详情参考：http://172.16.80.64/index.php?s=/3&page_id=36
	* @remark
	* @number 99
	*/
	VIPLEX_EXPORT void nvSetTimeAndZoneAsync(const char *data, ExportViplexCallback  callback);
#pragma region 其他
    /**
    * showdoc
    * @catalog 接口示例/温度和色温/温度
    * @title 获取箱体温度
    * @description 获取箱体温度的接口
    * @method
    * @url void nvGetScreenUnitTemp(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":""}
    * @param sn 必选 string 产品唯一序列号
    * @return {"temps":[{"bx":0,"by":0,"value":20},{"bx":128,"by":0,"value":25}]}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 错误码对应的具体描述
    * @return_param temps object 数组对象
    * @return_param bx int X坐标
    * @return_param by int y坐标
    * @return_param value float 温度值
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetScreenUnitTempAsync(const char *data, ExportViplexCallback  callback);
    /**
   * showdoc
   * @catalog 接口示例/其他/数据迁移
   * @title 数据迁移
   * @description 数据迁移的接口
   * @method
   * @url void nvDataBaseMigrationAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"templates":[{"data":[{"width":0.4,"height":0.4,"left":0.4,"top":0.4,"zindex":1,"index":0}]}],"size":[{"height":300,"width":300}],"program":[{"ID":"15","programName":"name","PLAYLIST":"","Width":"400","Height":"400"}]}
   * @param ID 必选 string 节目ID
   * @param programName 必选 string 节目名称
   * @param PLAYLIST 必选 string playlist.json文件中的内容
   * @param Width 必选 string 节目分辨率的宽
   * @param Height 必选 string 节目分辨率的高
   * @param templates 必选 object 自定义模版信息
   * @param width 必选 int 模板中窗口宽度
   * @param height 必选 int 模板中窗口高度
   * @param left 必选 float 模板中窗口左边占比
   * @param top 必选 float 模板中窗口上边占比
   * @param zindex 必选 int Z序
   * @param index 必选 int 模板中窗口窗口的ID
   * @param width 必选 int 模板的宽度
   * @param templates 必选 int 自定义模版信息
   * @return ""
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvDataBaseMigrationAsync(const char *data, ExportViplexCallback  callback);
    /**
   * showdoc
   * @catalog 接口示例/其他/下载缩略图
   * @title 下载缩略图
   * @description 下载缩略图的接口
   * @method
   * @url void nvDownLoadFilesAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"sn":"BZSA07194A0049999716","remotePathsAndFileNames":{"sdcard/nova/viplex_terminal/program/program_DANGJT-P1/tu1/35384db4-d10a-4db8-a1fe-54479706376f.png":"1.png","sdcard/nova/viplex_terminal/program/program_DANGJT-P1/tu2/296653e7-814c-4fad-9198-c731c0770d8c.png":"2.png"},"downLoadDirectoryPath":"/data/data/com.example.myhandy_android/app_flutter/log","fileType":".png"}
   * @param sn 必选 string 产品唯一序列号
   * @param remotePathsAndFileNames 必选 map {"需要下载缩略图文件路径":"自定义文件名称"}
   * @param downLoadDirectoryPath 必选 string 指定路径，缩略图下载到这个路径下
   * @param fileType 必选 string 文件类型
   * @return ""
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvDownLoadFilesAsync(const char *data, ExportViplexCallback  callback);

    /**
   * showdoc
   * @catalog 接口示例/其他/获取指定路径下指定类型文件
   * @title 获取指定路径下指定类型文件
   * @description 获取指定路径下指定类型文件的接口
   * @method
   * @url void nvQueryFileByTypeAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"paths":["C:/"],"types":[".txt"],"pageIndex":0,"pageSize":100}
   * @param paths 必选 string 需要查询的路径
   * @param types 必选 string 需要查询的文件类型
   * @param pageIndex 必选 int 每页显示的个数(暂未用到,可设置任意值)
   * @param pageSize 必选 int 查询的最大值(暂未用到,可设置任意值)
   * @return {"files":["C:/1.txt"]}
   * @return_param files stringarray 查询到的指定后缀类型的文件集合
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvQueryFileByTypeAsync(const char *data, ExportViplexCallback  callback);



#pragma region EditProgram
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 创建节目
    * @description 创建节目的接口
    * @method
    * @url  void nvCreateProgramAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"name":"jiemu1","width":400,"height":400}
    * @param name 必选 String 节目名称
    * @param width 必选 int 宽度
    * @param height 必选 int 高度
    * @return {"programID":1}
    * @return_param code int 错误码：`0`获取成功`65340`创建失败
    * @return_param data string 返回值错误码对应的详细信息
    * @return_param programID int 创建成功的节目id
    * @remark
    * @number 
    */
    VIPLEX_EXPORT void nvCreateProgramAsync(const char *data, ExportViplexCallback  callback);

	/**
	* showdoc
	* @catalog 接口示例/节目/编辑节目
	* @title 视频，GIF，图片
	* @description 编辑节目，此接口为视频，GIF，图片简化实例。
	* @url ""
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":5000,"dataSource":"f239518bb2aa5a52806b751cc3100a04.jpg","type":"PICTURE","name":"liuwen1.jpg","originalDataSource":"D:/liuwen1.jpg"}]},"id":1,"name":"widgetContainers1"}]}}
	* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback callBack);
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param contents 必选 object 窗口挂件内容
	* @param name 必选 string widgetContainers的名称
	* @param widgets 必选 objectArray 窗口挂件
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param type 必选 string 类型VIDEO:表示视频类型;GIF:表示是gif动画类型
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param dataSource 必选 string "媒体文件的MD5值"+"媒体文件的后缀"
	* @param originalDataSource 必选 string 数据源，原平台的媒体路径
	* @remark
	* @number 99
	*/


	/**
	* showdoc
	* @catalog 接口示例/节目/编辑复杂节目
	* @title 视频，GIF，图片
	* @description 编辑节目，此接口以图片为例
	* @method
	* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback callBack)
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"audioGroup":"","backgroundColor":"#00000000","backgroundDrawable":"","contents":{"widgets":[{"id":1,"enable":true,"repeatCount":1,"layout":{"y":"0","height":"100%","x":"0","width":"100%"},"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","zOrder":0,"displayRatio":"FULL","outAnimation":{"type":0,"duration":0},"dataSource":"4ab22addfa68f0e1110571a3c4766f2b.jpg","type":"PICTURE","constraints":[{"cron":[],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"border":{"borderThickness":"2px,3px,5%,6","style":0,"backgroundColor":"#ff000000","name":"border","cornerRadius":"2%","effects":{"headTailSpacing":"","isHeadTail":false,"speedByPixelEnable":true,"speed":0,"animation":"CLOCK_WISE"}},"inAnimation":{"type":0,"duration":1000},"duration":3605000,"name":"IMG_20200916_111857.jpg","originalDataSource":"/storage/emulated/0/DCIM/Camera/IMG_20200916_111857.jpg","functionStorage":"","isSupportSpecialEffects":false}]},"enable":true,"id":1,"itemsSource":"","layout":{"height":"1.0","width":"1.0","x":"0.0","y":"0.0"},"name":"widgetContainers1","pickCount":0,"pickPolicy":"ORDER","zOrder":0}]}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
	* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
	* @param backgroundDrawable 必选 string 背景图片资源,默认为空
	* @param contents 必选 object 窗口挂件内容
	* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
	* @param itemsSource 必选 string 媒体列表
	* @param layout 必选 object 布局
	* @param x 必选 string 起始x(例如0.2568)
	* @param y 必选 string 起始y(例如0.2568)
	* @param width 必选 string 宽(例如0.5000)
	* @param height 必选 string 高(例如0.5000)
	* @param name 必选 string widgetContainers的名称
	* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
	* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
	* @param zOrder 必选 int z序列
	* @param widgets 必选 objectArray 窗口挂件
	* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
	* @param mid 必选 int 媒体资源的唯一标识
	* @param name 必选 string 名称
	* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
	* @param layout 必选 object 布局
	* @param x 必选 string 无
	* @param y 必选 string 无
	* @param width 必选 string 无
	* @param height 必选 string 无
	* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
	* @param inAnimation 必选 object 入场动画
	* @param type 必选 int 动画类型
	* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
	* @param outAnimation 必选 object 出场动画
	* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
	* @param originalDataSource 必选 string 数据源，原平台的媒体路径
	* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
	* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
	* @param zOrder 必选 int z序列
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param border 非必选 object 边框
	* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
	* @param style 非必选 int 样式
	* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param name 非必选 string 名称
	* @param cornerRadius 非必选 string 边框的角半径 单位目前支持像素和百分比
	* @param effects 非必选 object 特效动画
	* @param speed 非必选 float 速度表示 像素/秒
	* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
	* @param isHeadTail 非必选 boolean 是否开启首尾相接
	* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
	* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
	* @param functionStorage 必选 string 默认为空
	* @param isSupportSpecialEffects 必选 string 是否支持播放特效
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时`65285`编辑page失败
	* @return_param data string 返回值错误码对应的详细信息
	* @remark
	* @number 99
	*/


    /**
    * showdoc
    * @catalog 接口示例/节目/编辑复杂节目
    * @title 网页媒体
    * @description 编辑节目，此接口为网页详解。metadata为空，类型为:HTML
    * @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"inAnimation":{"duration":1000,"type":1},"dataSource":"https://www.baidu.com/","type":"HTML","name":"网页","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]}}
    * @param programID int 节目id(创建节目返回的id)
    * @param pageID 必选 int pageId(当前版本pageId为1)
    * @param pageInfo 必选 Object page的详细信息
    * @param name 必选 string 名称
    * @param widgetContainers 必选 objectArray 窗口挂件容器
    * @param id 必选 int id标识
    * @param contents 必选 object 窗口挂件内容
    * @param name 必选 string widgetContainers的名称
    * @param widgets 必选 objectArray 窗口挂件
    * @param name 必选 string 名称
    * @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
    * @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
    * @param inAnimation 非必选 object 入场动画
    * @param type 非必选 int 动画类型。0表示没有特效，1表示随机特效
    * @param duration 非必选 long 特效播放时长，单位为毫秒
    * @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
    * @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是数据文件(md5.png)，网址，流媒体路径等
    * @param originalDataSource 必选 string 数据源，原平台的媒体路径
    * @param name 必选 string 媒体名称,图片、视频、gif媒体为媒体文件名称
    * @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
    * @param startTime 必选 string 开始时间
    * @param endTime 必选 string 结束时间
    * @param cron 必选 stringArray cron表达式
    * @param isSupportSpecialEffects 必选 bool 是否支持播放特效。支持特效时true,不支持特效为false
    * @return ""
    * @remark
    * @number 99
    */



	/**
	* showdoc
	* @catalog 接口示例/节目/编辑节目
	* @title 数字时钟
	* @description 编辑节目，数字时钟示例
	* @url ""
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"id":1,"name":"节目05","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":5000,"metadata":{"gmt":"UTC-08:00","suffixTemplates":["上午","下午"],"weekTemplates":["星期日","星期一","星期二","星期三","星期四","星期五","星期六"],"regular":"$MM/$dd/$yyyy\n$E\n$HH:$mm:$ss","solidText":{"text":"","textAttributes":null},"textAttributes":{"backgroundColor":"#00ff00","font":{"isUnderline":false,"size":20,"style":"NORMAL"},"letterSpacing":0,"textColor":"#ffff0000"},"zone":"America/Anchorage"},"name":"数字时钟","type":"DIGITAL_CLOCK"}]}}]}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param contents 必选 object 窗口挂件内容
	* @param name 必选 string widgetContainers的名称
	* @param widgets 必选 objectArray 窗口挂件
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param name 必选 string 名称
	* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param metadata 非必选 object 媒体详情
	* @param zone 必选 string 时区,例如"Asia/Shanghai"
	* @param gmt 必选 string 时区gmt，例如"GMT-08:00"
	* @param regular 必选 string 数字时钟的显示规则，占位符定义如：`1`.$dd：表示日；`2`.$MM：表示月；`3`.$yyyy：表示年，当表示两位年的时候使用$yy；`4`.$E：表示星期的一个占位符；`5`.$HH：时，时的格式为24进制；`6`.$hh：时，时的格式为12进制；`7`.$mm：分；`8`.$ss：秒；`9`.$N：上午下午；`10`.\n：表示换行
	* @param weekTemplates 必选 stringArray 表示星期的模板，七个数据项，分别表示星期一到星期日
	* @param suffixTemplates 必选 stringArray 表示时间后缀，两个数据项，上午or下午
	* @param textAttributes 必选 object 数字时钟样式文本属性
	* @param backgroundColor 必选 string 背景色，默认00FFFFFF
	* @param textColor 必选 string 文字的前景色，默认#FF0000
	* @param font 必选 object 字体描述
	* @param style 必选 string 类型，`1`.BOLD：粗体，`2`.NORMAL：正常类型，`3`.ITALIC：斜体，`4`.BOLD_ITALIC：粗体、斜体
	* @param size 必选 int 大小，目前只支持像素为单位，默认16
	* @param isUnderline 必选 bool 是否有下划线
	* @param solidText 非必选 object 固定文本属性对象
	* @param text 非必选 string 固定文本
	* @param textAttributes 非必选 object 固定文本属性，具体参考时钟属性textAttributes
	* @remark
	* @number 99
	*/

    /**
    * showdoc
    * @catalog 接口示例/节目/编辑复杂节目
    * @title 数字时钟
    * @description 编辑节目，数字时钟示例
    * @url ""
    * @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"audioGroup":"","backgroundColor":"#00000000","backgroundDrawable":"","contents":{"widgets":[{"id":1,"enable":true,"repeatCount":1,"layout":{"y":"0","height":"100%","x":"0","width":"100%"},"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","zOrder":0,"displayRatio":"FULL","outAnimation":{"type":0,"duration":0},"metadata":{"zone":"America/Anchorage","gmt":"UTC-08:00","regular":"$MM/$dd/$yyyy\n$E\n$HH:$mm:$ss","weekTemplates":["星期日","星期一","星期二","星期三","星期四","星期五","星期六"],"solidText":{"text":"","textAttributes":{}},"suffixTemplates":["上午","下午"],"textAttributes":{"ShadowDx":2,"ShadowRadius":10,"backgroundColor":"#00ff00","font":{"family":["Times","Georia","New York"],"isUnderline":false,"size":8,"style":"NORMAL"},"letterSpacing":0,"shadowColor":"#00ff00","shadowDy":0,"shadowEnable":false,"strokeEnable":true,"strokeWidth":115,"textColor":"#ffff0000"}},"dataSource":"4ab22addfa68f0e1110571a3c4766f2b.jpg","type":"PICTURE","constraints":[{"cron":[],"endTime":"4017-12-30T23:59:59Z 8:00","startTime":"1970-01-01T00:00:00Z 8:00"}],"border":{"borderThickness":"2px,3px,5%,6","style":0,"backgroundColor":"#ff000000","name":"border","cornerRadius":"2%","effects":{"headTailSpacing":"","isHeadTail":false,"speedByPixelEnable":true,"speed":0,"animation":"CLOCK_WISE"}},"inAnimation":{"type":0,"duration":1000},"duration":3605000,"name":"IMG_20200916_111857.jpg","originalDataSource":"/storage/emulated/0/DCIM/Camera/IMG_20200916_111857.jpg","functionStorage":"","isSupportSpecialEffects":false}]},"enable":true,"id":1,"itemsSource":"","layout":{"height":"1.0","width":"1.0","x":"0.0","y":"0.0"},"name":"widgetContainers1","pickCount":0,"pickPolicy":"ORDER","zOrder":0}]}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
	* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
	* @param backgroundDrawable 必选 string 背景图片资源,默认为空
	* @param contents 必选 object 窗口挂件内容
	* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
	* @param itemsSource 必选 string 媒体列表
	* @param layout 必选 object 布局
	* @param x 必选 string 起始x(例如0.2568)
	* @param y 必选 string 起始y(例如0.2568)
	* @param width 必选 string 宽(例如0.5000)
	* @param height 必选 string 高(例如0.5000)
	* @param name 必选 string widgetContainers的名称
	* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
	* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
	* @param zOrder 必选 int z序列
	* @param widgets 必选 objectArray 窗口挂件
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
	* @param mid 必选 int 媒体资源的唯一标识
	* @param name 必选 string 名称
	* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
	* @param layout 必选 object 布局
	* @param x 必选 string 无
	* @param y 必选 string 无
	* @param width 必选 string 无
	* @param height 必选 string 无
	* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
	* @param inAnimation 必选 object 入场动画
	* @param type 必选 int 动画类型
	* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
	* @param outAnimation 必选 object 出场动画
	* @param metadata 非必选 object 媒体详情
	* @param zone 必选 string 时区,例如"Asia/Shanghai"
	* @param gmt 必选 string 时区gmt，例如"GMT-08:00"
	* @param regular 必选 string 数字时钟的显示规则，占位符定义如：`1`.$dd：表示日；`2`.$MM：表示月；`3`.$yyyy：表示年，当表示两位年的时候使用$yy；`4`.$E：表示星期的一个占位符；`5`.$HH：时，时的格式为24进制；`6`.$hh：时，时的格式为12进制；`7`.$mm：分；`8`.$ss：秒；`9`.$N：上午下午；`10`.\n：表示换行
	* @param weekTemplates 必选 stringArray 表示星期的模板，七个数据项，分别表示星期一到星期日
	* @param suffixTemplates 必选 stringArray 表示时间后缀，两个数据项，上午or下午
	* @param textAttributes 必选 object 数字时钟样式文本属性
	* @param backgroundColor 必选 string 背景色，默认00FFFFFF
	* @param textColor 必选 string 文字的前景色，默认#FF0000
	* @param font 必选 object 字体描述
	* @param family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
	* @param style 必选 string 类型，`1`.BOLD：粗体，`2`.NORMAL：正常类型，`3`.ITALIC：斜体，`4`.BOLD_ITALIC：粗体、斜体
	* @param size 必选 int 大小，目前只支持像素为单位，默认16
	* @param isUnderline 必选 bool 是否有下划线
	* @param shadowEnable 非必选 bool 阴影是否使能，默认false
	* @param shadowRadius 非必选 int 阴影半径大小像素为单位，默认10
	* @param shadowDx 非必选 int x轴的偏移
	* @param shadowDy 非必选 int y轴的偏移
	* @param shadowColor 非必选 string 阴影颜色，默认#00ff00
	* @param solidText 非必选 object 固定文本属性对象
	* @param text 非必选 string 固定文本
	* @param textAttributes 非必选 object 固定文本属性，具体参考时钟属性textAttributes
	* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
	* @param originalDataSource 必选 string 数据源，原平台的媒体路径
	* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
	* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
	* @param zOrder 必选 int z序列
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param border 非必选 object 边框
	* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
	* @param style 非必选 int 样式
	* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param name 非必选 string 名称
	* @param cornerRadius 非必选 string 边框的角半径 单位目前支持像素和百分比
	* @param effects 非必选 object 特效动画
	* @param speed 非必选 float 速度表示 像素/秒
	* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
	* @param isHeadTail 非必选 boolean 是否开启首尾相接
	* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
	* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
	* @param functionStorage 必选 string 默认为空
	* @param isSupportSpecialEffects 必选 string 是否支持播放特效
    * @remark
    * @number 99
    */

	/**
	* showdoc
	* @catalog 接口示例/节目/编辑节目
	* @title 图片(带特效)
	* @description 编辑节目，此接口为图片(带特效类)widgets详解，类型为PICTURE。
	* @url ""
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"inAnimation":{"duration":1000,"type":1},"metadata":{"scrollAttributes":{"effects":{"animation":"MARQUEE_UP","speed":3.0}}},"duration":5000,"dataSource":"f239518bb2aa5a52806b751cc3100a04.jpg","type":"PICTURE","name":"liuwen1.jpg","originalDataSource":"D:/liuwen1.jpg"}]},"id":1,"name":"widgetContainers1"}]}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param contents 必选 object 窗口挂件内容
	* @param name 必选 string widgetContainers的名称
	* @param widgets 必选 objectArray 窗口挂件
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param name 必选 string 名称
	* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param inAnimation 必选 object 入场动画
	* @param type 必选 int `1`.0x00:无特效;`2`.0x01:随机动画;`3`.0x10:从左侧扩展进入;`4`.0x11:从顶部扩展进入;`5`.0x12:从右侧扩展进入;`6`.0x13:从底部扩展进入;`7`.0x14:从中间向外扩展；`8`.0x15：水平方向扩展；`9`.0x16：垂直方向扩展；`10`.0x20：从左侧移动进入；`11`.0x21：从顶部移动进入；`12`.0x22：从右侧移动进入；`13`.0x23：从底部移动进入；`14`.0x30：从左侧缩进；`15`.0x31：从顶部缩进；`16`.0x32：从右侧缩进；`17`.0x33：从底部缩进；`18`.0x34：从上下向中间缩进；`19`.0x35：从左右向中间缩进；`20`.0x40：从顶部向下滚动铺展；`21`.0x41：从底部向上滚动铺展；`22`.0x50：水平方向关门；`23`.0x51：垂直方向关门；`24`.0x60：下百叶窗；`25`.0x61：右百叶窗；`26`.0x70：变焦全屏；`27`.0x80：中文名称暂时未定；`28`.0x90：雷达；`29`.0xA0：上下齿合；`30`.0xB0：淡入；`31`.0xB1：淡出；`32`.0xC0：从左向右堆积；`33`.0xC1：从上向下堆积；`34`.0xC2：从右向左堆积；`35`.0xC3：从下向上堆积；`36`.0xD0：左镭射；`37`.0xD1：上镭射；`38`.0xD2：右镭射；`39`.0xD3：下镭射；`40`.0xE0：向左滚动；`41`.0xE1：向上滚动；`42`.0xE2：向右滚动；`43`.0xE3：向下滚动；`44`.0xF0：向下展开；`45`.0xF1：向上展开；`46`.0xF2：中间向上下展开；`47`.0xF3：上下向中间展开；
	* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
	* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
	* @param scrollAttributes 非必选 object 滚动属性描述
	* @param effects object 必选 滚动特效描述
	* @param animation 必选 string 特效类型:MARQUEE_LEFT，MARQUEE_RIGHT，MARQUEE_UP，MARQUEE_DOWN，NONE为不支持滚动特效
	* @param speed 必选 float 速度，单位像素每秒	
	* @return ""
	* @remark
	* @number 99
	*/



	/**
	* showdoc
	* @catalog 接口示例/节目/编辑复杂节目
	* @title 图片(带特效)
	* @description 编辑节目，此接口为图片带特效实例
	* @url ""
	* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback callBack)
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"audioGroup":"","backgroundColor":"#00000000","backgroundDrawable":"","contents":{"widgets":[{"id":1,"enable":true,"repeatCount":1,"layout":{"y":"0","height":"100%","x":"0","width":"100%"},"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","zOrder":0,"displayRatio":"FULL","outAnimation":{"type":0,"duration":0},"dataSource":"4ab22addfa68f0e1110571a3c4766f2b.jpg","type":"PICTURE","constraints":[{"cron":[],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"border":{"borderThickness":"2px,3px,5%,6","style":0,"backgroundColor":"#ff000000","name":"border","cornerRadius":"2%","effects":{"headTailSpacing":"","isHeadTail":false,"speedByPixelEnable":true,"speed":0,"animation":"CLOCK_WISE"}},"inAnimation":{"type":0,"duration":1000},"metadata":{"scrollAttributes":{"effects":{"animation":"MARQUEE_UP","speed":3.0}}},"duration":3605000,"name":"IMG_20200916_111857.jpg","originalDataSource":"/storage/emulated/0/DCIM/Camera/IMG_20200916_111857.jpg","functionStorage":"","isSupportSpecialEffects":false}]},"enable":true,"id":1,"itemsSource":"","layout":{"height":"1.0","width":"1.0","x":"0.0","y":"0.0"},"name":"widgetContainers1","pickCount":0,"pickPolicy":"ORDER","zOrder":0}]}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
	* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
	* @param backgroundDrawable 必选 string 背景图片资源,默认为空
	* @param contents 必选 object 窗口挂件内容
	* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
	* @param itemsSource 必选 string 媒体列表
	* @param layout 必选 object 布局
	* @param x 必选 string 起始x(例如0.2568)
	* @param y 必选 string 起始y(例如0.2568)
	* @param width 必选 string 宽(例如0.5000)
	* @param height 必选 string 高(例如0.5000)
	* @param name 必选 string widgetContainers的名称
	* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
	* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
	* @param zOrder 必选 int z序列
	* @param widgets 必选 objectArray 窗口挂件
	* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
	* @param mid 必选 int 媒体资源的唯一标识
	* @param name 必选 string 名称
	* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
	* @param layout 必选 object 布局
	* @param x 必选 string 无
	* @param y 必选 string 无
	* @param width 必选 string 无
	* @param height 必选 string 无
	* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
	* @param inAnimation 必选 object 入场动画
	* @param type 必选 int 动画类型
	* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
	* @param outAnimation 必选 object 出场动画
	* @param scrollAttributes 非必选 object 滚动属性描述
	* @param effects object 必选 滚动特效描述
	* @param animation 必选 string 特效类型:MARQUEE_LEFT，MARQUEE_RIGHT，MARQUEE_UP，MARQUEE_DOWN，NONE为不支持滚动特效
	* @param speed 必选 float 速度，单位像素每秒
	* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
	* @param originalDataSource 必选 string 数据源，原平台的媒体路径
	* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
	* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
	* @param zOrder 必选 int z序列
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param border 非必选 object 边框
	* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
	* @param style 非必选 int 样式
	* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param name 非必选 string 名称
	* @param cornerRadius 非必选 string 边框的角半径 单位目前支持像素和百分比
	* @param effects 非必选 object 特效动画
	* @param speed 非必选 float 速度表示 像素/秒
	* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
	* @param isHeadTail 非必选 boolean 是否开启首尾相接
	* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
	* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
	* @param functionStorage 必选 string 默认为空
	* @param isSupportSpecialEffects 必选 string 是否支持播放特效
	* @return "success"
	* @return_param code int 错误码：`0`获取成功`65535`请求超时`65285`编辑page失败
	* @return_param data string 返回值错误码对应的详细信息
	* @remark
	* @number 99
	*/

	/**
	* showdoc
	* @catalog 接口示例/节目/编辑节目
	* @title 文本节目
	* @description 编辑节目，文本媒体示例
	* @url ""
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"metadata":{"content":{"autoPaging":true,"backgroundMusic":{"duration":0,"isTextSync":false},"displayStyle":{"scrollAttributes":{"effects":{"animation":"MARQUEE_LEFT","speed":3}},"type":"STATIC"},"paragraphs":[{"backgroundColor":"#00000000","horizontalAlignment":"CENTER","letterSpacing":0,"lineSpacing":0,"lines":[{"segs":[{"content":"中国制造，惠及全球！测试测测试是是是是是是是试测"}]}],"verticalAlignment":"CENTER"}],"textAttributes":[{"backgroundColor":"#ff000000","attributes":{"font":{"family":["Helvetica"],"isUnderline":false,"size":60,"style":"NORMAL"},"letterSpacing":0,"textColor":"#ffff0000"}}]}},"name":"文本","type":"ARCH_TEXT"}]},"id":1,"name":"widgetContainers1"}]}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param contents 必选 object 窗口挂件内容
	* @param name 必选 string widgetContainers的名称
	* @param widgets 必选 objectArray 窗口挂件
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param duration 必选 long 播放时长，单位为毫秒
	* @param name 必选 string 名称
	* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param metadata 非必选 object 媒体详情	
	* @param displayStyle 必选 object 显示风格
	* @param scrollAttributes 必选 object 滚动属性描述
	* @param effects 必选 object 滚动特效描述
	* @param animation 必选 string MARQUEE_LEFT或MARQUEE_UP
	* @param speed 必选 float 速度,单位像素/s或者档位（1-10）
	* @param type 必选 string PAGE_SWITCH或SCROLL或STATIC，表示按照页切换、滚动模式、静止模式（若文字内容大于屏幕，仅显示第一屏）
	* @param paragraphs 必选 objectArray 段落描述
	* @param verticalAlignment 必选 string 垂直方向对齐方式，分别为：BOTTOM,CENTER,TOP
	* @param horizontalAlignment 必选 string 水平方向对齐方式，分别为：LEFT,CENTER,RIGHT
	* @param backgroundColor 必选 string 段背景色
	* @param lineSpacing 必选 string 段行间距，单位像素
	* @param letterSpacing 必选 int 段字间距，单位像素
	* @param lines 必选 object 行的描述
	* @param content 必选 string 要显示的内容
	* @param textAttributes 必选 objectArray 文本属性列表
	* @param attributes 必选 object 文本属性说明
	* @param backgroundColor 必选 string 背景色，默认00FFFFFF
	* @param textColor 必选 string 文字的前景色，默认#FF0000
	* @param font 必选 object 字体描述
	* @param family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
	* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
	* @param size 必选 int 大小，目前只支持像素为单位，默认16
	* @param isUnderline 必选 bool 是否有下划线
	* @remark
	* @number 99
	*/

	/**
	* showdoc
	* @catalog 接口示例/节目/编辑复杂节目
	* @title 文本节目
	* @description 编辑节目，文本媒体示例
	* @url ""
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"audioGroup":"","backgroundColor":"#00000000","backgroundDrawable":"","contents":{"widgets":[{"id":1,"enable":true,"repeatCount":1,"layout":{"y":"0","height":"100%","x":"0","width":"100%"},"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","zOrder":0,"displayRatio":"FULL","outAnimation":{"type":0,"duration":0},"metadata":{"content":{"displayStyle":{"pageSwitchAttributes":{"inAnimation":{"duration":1000,"type":224},"remainDuration":5000},"scrollAttributes":{"effects":{"animation":"MARQUEE_LEFT","headTailSpacing":"10","isHeadTail":false,"speed":3.0,"speedByPixelEnable":false}},"singleLine":false,"type":"SCROLL"},"paragraphs":[{"backgroundColor":"#00000000 ","horizontalAlignment":"CENTER","letterSpacing":0,"lineSpacing":0,"lines":[{"segs":[{"attributeKey":1,"content":"Welcome Handy!"}]}],"verticalAlignment":"CENTER"}],"textAttributes":[{"attributes":{"ShadowDx":2,"ShadowRadius":10,"backgroundColor":"#ff000000","font":{"family":["Arial"],"isUnderline":false,"size":20,"style":"NORMAL"},"letterSpacing":0,"shadowColor":"#00ff00","shadowDy":2,"shadowEnable":false,"strokeEnable":false,"strokeWidth":0,"textColor":"#ffff0000"},"key":1}],"autoPaging":true,"backgroundMusic":{"duration":0,"isTextSync":false}}},"type":"ARCH_TEXT","constraints":[{"cron":[],"endTime":"4017-12-30T23:59:59Z 8:00","startTime":"1970-01-01T00:00:00Z 8:00"}],"border":{"borderThickness":"2px,3px,5%,6","style":0,"backgroundColor":"#ff000000","name":"border","cornerRadius":"2%","effects":{"headTailSpacing":"","isHeadTail":false,"speedByPixelEnable":true,"speed":0,"animation":"CLOCK_WISE"}},"inAnimation":{"type":0,"duration":1000},"duration":3605000,"name":"text","functionStorage":"","isSupportSpecialEffects":false}]},"enable":true,"id":1,"itemsSource":"","layout":{"height":"1.0","width":"1.0","x":"0.0","y":"0.0"},"name":"widgetContainers1","pickCount":0,"pickPolicy":"ORDER","zOrder":0}]}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param id 必选 int id标识
	* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
	* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
	* @param backgroundDrawable 必选 string 背景图片资源,默认为空
	* @param contents 必选 object 窗口挂件内容
	* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
	* @param itemsSource 必选 string 媒体列表
	* @param layout 必选 object 布局
	* @param x 必选 string 起始x(例如0.2568)
	* @param y 必选 string 起始y(例如0.2568)
	* @param width 必选 string 宽(例如0.5000)
	* @param height 必选 string 高(例如0.5000)
	* @param name 必选 string widgetContainers的名称
	* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
	* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
	* @param zOrder 必选 int z序列
	* @param widgets 必选 objectArray 窗口挂件
	* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
	* @param mid 必选 int 媒体资源的唯一标识
	* @param name 必选 string 名称
	* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
	* @param layout 必选 object 布局
	* @param x 必选 string 无
	* @param y 必选 string 无
	* @param width 必选 string 无
	* @param height 必选 string 无
	* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
	* @param inAnimation 必选 object 入场动画
	* @param type 必选 int 动画类型
	* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
	* @param outAnimation 必选 object 出场动画
	* @param metadata 非必选 object 媒体详情
	* @param displayStyle 必选 object 显示风格
	* @param pageSwitchAttributes 非必选 object 按照页切换的属性
	* @param inAnimation 必选 object 入场动画
	* @param type 必选 int 入场动画类型，默认无特效
	* @param duration 必选 long 特效时间，单位毫秒
	* @param remianDuration 必选 long 保留时间，单位毫秒
	* @param scrollAttributes 必选 object 滚动属性描述
	* @param effects 必选 object 滚动特效描述
	* @param animation 必选 string MARQUEE_LEFT或MARQUEE_UP
	* @param speed 必选 float 速度,单位像素/s或者档位（1-10）
	* @param speedByPixelEnable 非必选 bool 如果为true则是像素每秒，false为档位，默认为false
	* @param isHeadTail 非必选 bool 是否开启首尾相接，默认不开启(false)
	* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者（屏幕百分比%）
	* @param singleLine 非必选 bool 文字是否单行显示
	* @param type 必选 string PAGE_SWITCH或SCROLL或STATIC，表示按照页切换、滚动模式、静止模式（若文字内容大于屏幕，仅显示第一屏）
	* @param paragraphs 必选 objectArray 段落描述
	* @param verticalAlignment 必选 string 垂直方向对齐方式，分别为：BOTTOM,CENTER,TOP
	* @param horizontalAlignment 必选 string 水平方向对齐方式，分别为：LEFT,CENTER,RIGHT
	* @param backgroundColor 必选 string 段背景色
	* @param lineSpacing 必选 string 段行间距，单位像素
	* @param letterSpacing 必选 int 段字间距，单位像素
	* @param lines 必选 object 行的描述
	* @param attributeKey 非必选 int 对应的文本属性key
	* @param content 必选 string 要显示的内容
	* @param textAttributes 必选 objectArray 文本属性列表
	* @param key 非必选 int 与attributeKey对应，设置相应的段落
	* @param attributes 必选 object 文本属性说明
	* @param backgroundColor 必选 string 背景色，默认00FFFFFF
	* @param textColor 必选 string 文字的前景色，默认#FF0000
	* @param font 必选 object 字体描述
	* @param family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
	* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
	* @param size 必选 int 大小，目前只支持像素为单位，默认16
	* @param isUnderline 必选 bool 是否有下划线
	* @param shadowEnable 非必选 bool 阴影是否使能，默认false
	* @param shadowRadius 非必选 int 阴影半径大小像素为单位，默认10
	* @param shadowDx 非必选 int x轴的偏移
	* @param shadowDy 非必选 int y轴的偏移
	* @param shadowColor 非必选 string 阴影颜色，默认#00ff00
	* @param autoPaging 非必选 bool 是否自动分页显示，false表示只显示能显示下的部分，默认为true
	* @param backgroundMusic 非必选 object 文字背景音乐
	* @param id 非必选 int 音频id
	* @param name 非必选 string 音频名称
	* @param dataSource 非必选 string 音频来源
	* @param duration 非必选 long 音频时长
	* @param isTextSync 非必选 bool 音频与文字是否同步
	* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
	* @param originalDataSource 必选 string 数据源，原平台的媒体路径
	* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
	* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
	* @param zOrder 必选 int z序列
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param cron 必选 stringArray cron表达式
	* @param border 非必选 object 边框
	* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
	* @param style 非必选 int 样式
	* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param name 非必选 string 名称
	* @param cornerRadius 非必选 string 边框的角半径 单位目前支持像素和百分比
	* @param effects 非必选 object 特效动画
	* @param speed 非必选 float 速度表示 像素/秒
	* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
	* @param isHeadTail 非必选 boolean 是否开启首尾相接
	* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
	* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
	* @param functionStorage 必选 string 默认为空
	* @param isSupportSpecialEffects 必选 string 是否支持播放特效
	* @return ""
	* @remark
	* @number 99
	*/

	/**
	* showdoc
	* @catalog 接口示例/节目/编辑复杂节目
	* @title 简单天气预报
	* @description 简单天气预报，对应媒体类型：SIMPLE_WEATHER。支持只显示文字信息的天气预报，文字属性只支持统一修改。
	* @url ""
	* @json_param {"programID":1,"pageID":1,"pageInfo":{"id":1,"name":"节目01","pickPolicy":"ORDER_MODE","sceneItems":[{"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"enable":true,"id":1,"name":"scene1","page":{"id":1,"name":"节目07","widgetContainers":[{"audioGroup":"","backgroundColor":"#00000000","backgroundDrawable":"","contents":{"widgets":[{"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","border":{"backgroundColor":"#FF000000","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","effects":{"animation":"CLOCK_WISE","headTailSpacing":"10","isHeadTail":false,"speed":3,"speedByPixelEnable":false},"name":"border","style":0},"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"dataSource":"","displayRatio":"FULL","duration":5000,"enable":true,"id":1,"inAnimation":{"duration":1000,"type":0},"layout":{"height":"100%","width":"100%","x":"0","y":"0"},"metadata":{"area":{"city":"西安","cityCode":"CN101110101","country":"中国","county":"西安","province":"陕西省"},"cityNewCode":"CN101110101","effects":{"animation":"NONE","headTailSpacing":"100","isHeadTail":true,"speed":3.0,"speedByPixelEnable":false},"isShowInOneLine":false,"isShowUnit":true,"language":"zh-cn","refreshPeriod":300000,"regular":"天气:$w\n温度:$t\n风力:$b级\n当前温度:$c\n湿度:$h","temperatureUnit":"Celsius","textAttributes":{"ShadowDx":2,"ShadowRadius":10,"backgroundColor":"#000","font":{"family":["Times","Georia","New York"],"isUnderline":false,"size":20,"style":"Bold"},"letterSpacing":0,"shadowColor":"#00ff00","shadowDy":0,"shadowEnable":false,"strokeEnable":false,"strokeWidth":-2147483648,"textColor":"#ffff0000"},"weatherSource":1,"windSpeedUnit":"m","windType":"wind_sc"},"name":"天气","originalDataSource":"","outAnimation":{"duration":0,"type":0},"repeatCount":1,"type":"SIMPLE_WEATHER","zOrder":0}]},"enable":true,"id":1,"itemsSource":"","layout":{"height":"100.00%","width":"100.00%","x":"0.00%","y":"0.00%"},"name":"widgetContainers1","pickCount":0,"pickPolicy":"ORDER","zOrder":0}],"widgets":[]},"repeatCount":1,"rules":"TIMES","type":"PAGE"}],"uuid":""}}
	* @param programID int 节目id(创建节目返回的id)
	* @param pageID 必选 int pageId(当前版本pageId为1)
	* @param pageInfo 必选 Object page的详细信息
	* @param id 必选 int id标识
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
	* @param sceneItems 必选 数组 场景列表，对于一个播放列表，如果没有场景，则认为这个播放列表是空的，非法的
	* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
	* @param backgroundDrawable 必选 string 背景图片资源,默认为空
	* @param backgroundMusic 必选 string 背景音乐路径，url 可以来自网络或本地。
	* @param constraints 必选 objectArray 时间约束，有效时间范围。当为按照次数播放时，无此选项，当按照时长播放时，如果没有此项，在时常范围内一直有效
	* @param cron 必选 stringarray cron 表达式，目前按照dayOfWeek 或者dayOfMonth 来约束,当有多个表达式时，按照或的关系处理
	* @param startTime 必选 string 开始时间，根据需求，可以是只包含时间的，也可以是包含日期和时区的时间，根据需求来决定
	* @param endTime 必选 string 结束时间，根据需求，可以是只包含时间的，也可以是包含日期和时区的时间，根据需求来决定
	* @param duration 必选 long 播放时长，当按照时长播放时，才有效。单位为毫秒
	* @param enable 必选 bool 场景是否有效，true表示播放此场景，false表示不播放
	* @param id 必选 number 在整个播放方案需要保持唯一
	* @param name 必选 string 名称
	* @param page 必选 object 页面
	* @param id 必选 number 在整个播放方案需要保持唯一
	* @param name 必选 string 名称
	* @param widgetContainers 必选 objectArray 窗口挂件容器
	* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
	* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
	* @param backgroundDrawable 必选 string 背景图片资源,默认为空
	* @param contents 必选 object 窗口挂件内容
	* @param widgets 必选 object 窗口挂件
	* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
	* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
	* @param border 非必选 object 边框，表示媒体类型为边框
	* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
	* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
	* @param cornerRadius 非必选 string 边框的角半径，单位目前支持像素和百分比
	* @param effects 非必选 object 特效动画
	* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
	* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
	* @param isHeadTail 非必选 boolean 是否开启首尾相接
	* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
	* @param name 必选 string 名称
	* @param style 非必选 int 样式
	* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
	* @param cron 必选 stringArray cron表达式
	* @param startTime 必选 string 开始时间
	* @param endTime 必选 string 结束时间
	* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
	* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
	* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
	* @param enable 必选 bool 媒体是否有效，当为无效时，则不播放此媒体
	* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
	* @param inAnimation 必选 object 入场动画
	* @param duration 必选 long 动画持续时间，单位为毫秒。当type 为无特效时，此自动无意义
	* @param type 必选 string 特效类型
    * @param layout 必选 object 布局
	* @param height 必选 string 高(例如0.5000)
	* @param width 必选 string 宽(例如0.5000)
	* @param x 必选 string 起始x(例如0.2568)
	* @param y 必选 string 起始y(例如0.2568)
	* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
	* @param area 必选 object 区域，要获取的天气信息的区域
	* @param city 必选 string 所属城市
	* @param cityCode 非必选 string 城市编码，当无效时，使用上述字段匹配
	* @param country 必选 string 所属国家
	* @param county 必选 string 所属县
	* @param province 必选 string 所属省份
	* @param cityNewCode 非必选 string 表示城市code的新字段
	* @param effects 必选 object 播放效果，目前只支持滚动的动画
	* @param animation 必选 string 动画类型，NONE，MARQUEE_LEFT，MARQUEE_UP，MARQUEE_RIGHT，MARQUEE_DOWN
	* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者（屏幕百分比%）
	* @param isHeadTail 非必选 bool 是否开启首尾相接
	* @param speed 非必选 float 滚动速度,单位像素/s或者档位（1-10）
	* @param speedByPixelEnable 非必选 bool 如果为true则是像素每秒，false为档位
	* @param isShowInOneLine 必选 bool 是否单行显示
	* @param isShowUnit 非必选 bool 是否显示单位，如果为true，显示单位（℃或℉），如果为false，隐藏单位，只显示单位左上角的圈圈
	* @param language 非必选 string 表示天气数据的显示语言，如zh-cn,en,jp等
	* @param refreshPeriod 必选 long 刷新周期，单位为毫秒
	* @param regular 非必选 string 显示规则，包含占位符和要显示的信息
	* @param temperatureUnit 必选 string Celsius或Fahrenheit 分别表示摄氏度或者华氏度
	* @param textAttributes 必选 object 文字属性，请参考文本属性定义，描述天气预报的文字的属性
	* @param shadowDx 非必选 number x轴的偏移
	* @param shadowRadius 非必选 number 阴影半径大小像素为单位
	* @param backgroundColor 非必选 string 背景色
	* @param font 非必选  object 字体描述
	* @param family 必选 stringArray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的
	* @param isUnderline 非必选 bool 是否有下划线
	* @param size 非必选 number 大小，目前只支持像素为单位
	* @param style 必选 string 类型
	* @param letterSpacing 必选 int 字间距，单位像素，默认0
	* @param shadowColor 非必选 string 阴影颜色
	* @param shadowDy 非必选 number y轴的偏移
	* @param shadowEnable 非必选 bool 阴影是否使能
	* @param strokeEnable 必选 bool 描边是否生效
	* @param strokeWidth 必选 int 描边宽度
	* @param textColor 必选 string 文字的前景色
	* @param weatherSource 非必选 int 表示天气数据来源，1为和风天气网，2为雅虎，不存在字段或为0表示为旧的协议
	* @param windSpeedUnit 非必选 string 风速计量单位：公制:m；英制:i；默认为公制单位
	* @param windType 非必选 string 风力显示类型：风力:wind_sc；风速：wind_spd；默认为风力
	* @param name 非必选 string 名称
	* @param originalDataSource 必选 string 数据源，原平台的媒体路径
	* @param outAnimation 必选 object 出场动画
	* @param duration 必选 long 动画持续时间，单位为毫秒。当type 为无特效时，此自动无意义
	* @param type 必选 int 动画类型
    * @param repeatCount 必选 int 播放次数,如果为-1表示无限次
    * @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
	* @param zOrder 必选 int z序列
	* @param enable 必选 bool 媒体是否有效，当为无效时，则不播放此媒体
	* @param id 必选 number id标识
	* @param itemsSource 必选 string 媒体列表
	* @param layout 必选 object 布局
	* @param height 必选 string 无
	* @param width 必选 string 无
	* @param x 必选 string 无
	* @param y 必选 string 无
	* @param name 必选 string 名称
	* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
	* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
	* @param zOrder 必选 int z序列
	* @param widgets 必选 object 窗口挂件
	* @param repeatCount 必选 int 重复次数，当按照次数播放时，才有效
	* @param rules 必选 string 规则 DURATION：按照时长播放，TIMES:按照次数播放
	* @param type 必选 string PAGE or PLAYLIST
	* @param uuid 必选 string 唯一标识
	* @return ""
	* @remark
	* @number 99
	*/

/**
* showdoc
* @catalog 接口示例/节目/编辑节目
* @title 简单天气预报
* @description 简单天气预报，对应媒体类型：SIMPLE_WEATHER。支持只显示文字信息的天气预报，文字属性只支持统一修改。
* @url ""
* @json_param {"programID":1,"pageID":1,"pageInfo":{"id":1,"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":5000,"metadata":{"area":{"city":"西安","cityCode":"CN101110101","country":"中国","county":"西安","province":"陕西省"},"effects":{"animation":"MARQUEE_LEFT"},"isShowInOneLine":false,"refreshPeriod":300000,"regular":"天气:$w\n温度:$t\n风力:$b级\n当前温度:$c\n湿度:$h","temperatureUnit":"Celsius","textAttributes":{"font":{"family":["Times","Georia","New York"]},"textColor":"#ffff0000"}},"type":"SIMPLE_WEATHER"}]}}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param id 必选 int id标识
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param contents 必选 object 窗口挂件内容
* @param widgets 必选 objectArray 窗口挂件
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param cron 必选 stringArray cron表达式
* @param endTime 必选 string 结束时间
* @param startTime 必选 string 开始时间
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param metadata 必选 object 元数据，即为一个窗口挂件的私有数据成员集合
* @param area 必选 object 区域，要获取的天气信息的区域
* @param city 必选 string 所属城市
* @param cityCode 非必选 string 城市编码，当无效时，使用上述字段匹配
* @param country 必选 string 所属国家
* @param county 必选 string 所属县
* @param province 必选 string 所属省份
* @param effects 必选 object 播放效果，目前只支持滚动的动画
* @param animation 必选 string 动画类型，NONE，MARQUEE_LEFT，MARQUEE_UP，MARQUEE_RIGHT，MARQUEE_DOWN
* @param isShowInOneLine 必选 bool 是否单行显示
* @param refreshPeriod 必选 long 刷新周期，单位为毫秒
* @param regular 非必选 string 显示规则，包含占位符和要显示的信息
* @param temperatureUnit 必选 string Celsius或Fahrenheit 分别表示摄氏度或者华氏度
* @param textAttributes 必选 object 文字属性，请参考文本属性定义，描述天气预报的文字的属性
* @param font 非必选  object 字体描述
* @param family 必选 stringArray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的
* @param textColor 必选 string 文字的前景色
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @return ""
* @remark
* @number 99
*/



/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title 模拟时钟
* @description 模拟时钟，对应媒体类型为：ANALOG_CLOCK。
* @url ""
* @json_param {"programID":1,"pageID":1,"pageInfo":{"id":1,"name":"节目01","pickPolicy":"ORDER_MODE","sceneItems":[{"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"enable":true,"id":1,"name":"scene1","page":{"id":1,"name":"节目06","widgetContainers":[{"audioGroup":"","backgroundColor":"#00000000","backgroundDrawable":"","contents":{"widgets":[{"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","border":{"backgroundColor":"#FF000000","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","effects":{"animation":"CLOCK_WISE","headTailSpacing":"10","isHeadTail":false,"speed":3,"speedByPixelEnable":false},"name":"border","style":0},"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"dataSource":"","displayRatio":"FULL","duration":5000,"enable":true,"id":1,"inAnimation":{"duration":1000,"type":0},"layout":{"height":"100%","width":"100%","x":"0","y":"0"},"metadata":{"background":{"color":"#00000000"},"date":{"enable":true,"regular":"$dd/$MM/$yyyy\n$E","textAttributes":{"ShadowDx":0,"ShadowRadius":0,"backgroundColor":"","font":{"family":[],"isUnderline":false,"size":16,"style":"NORMAL"},"letterSpacing":0,"shadowColor":"","shadowDy":0,"shadowEnable":false,"strokeEnable":false,"strokeWidth":0,"textColor":"#ffffff00"},"weekTemplates":["星期日","星期一","星期二","星期三","星期四","星期五","星期六"]},"gmt":"UTC+08:00","hourHand":{"color":"#ffffff00","enable":true},"hourScale":{"color":"#ff00ff00","enable":true,"height":6,"shape":"RECTANGLE","textAttributes":{"ShadowDx":0,"ShadowRadius":0,"backgroundColor":"","font":{"family":[],"isUnderline":false,"size":3,"style":"NORMAL"},"letterSpacing":0,"shadowColor":"","shadowDy":0,"shadowEnable":false,"strokeEnable":false,"strokeWidth":0,"textColor":""},"width":6},"minuteHand":{"color":"#ff00ff00","enable":true},"minuteScale":{"color":"#ff0000ff","enable":true,"height":4,"shape":"RECTANGLE","textAttributes":{"ShadowDx":0,"ShadowRadius":0,"backgroundColor":"","font":{"family":[],"isUnderline":false,"size":2,"style":"NORMAL"},"letterSpacing":0,"shadowColor":"","shadowDy":0,"shadowEnable":false,"strokeEnable":false,"strokeWidth":0,"textColor":""},"width":4},"secondHand":{"color":"#ffff0000","enable":true},"text":{"enable":false,"text":"","textAttributes":{"ShadowDx":0,"ShadowRadius":0,"backgroundColor":"","font":{"family":[],"isUnderline":false,"size":12,"style":"NORMAL"},"letterSpacing":0,"shadowColor":"","shadowDy":0,"shadowEnable":false,"strokeEnable":false,"strokeWidth":0,"textColor":"#ffff0000"}},"zone":"Asia/Shanghai"},"name":"模拟时钟","originalDataSource":"","outAnimation":{"duration":0,"type":0},"repeatCount":1,"type":"ANALOG_CLOCK","zOrder":0}]},"enable":true,"id":1,"itemsSource":"","layout":{"height":"100.00%","width":"100.00%","x":"0.00%","y":"0.00%"},"name":"widgetContainers1","pickCount":0,"pickPolicy":"ORDER","zOrder":0}],"widgets":[]},"repeatCount":1,"rules":"TIMES","type":"PAGE"}],"uuid":""}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param id 必选 int id标识
* @param name 必选 string 名称
* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
* @param sceneItems 必选 数组 场景列表，对于一个播放列表，如果没有场景，则认为这个播放列表是空的，非法的
* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
* @param backgroundDrawable 必选 string 背景图片资源,默认为空
* @param backgroundMusic 必选 string 背景音乐路径，url 可以来自网络或本地。
* @param constraints 必选 objectArray 时间约束，有效时间范围。当为按照次数播放时，无此选项，当按照时长播放时，如果没有此项，在时常范围内一直有效
* @param cron 必选 stringarray cron 表达式，目前按照dayOfWeek 或者dayOfMonth 来约束,当有多个表达式时，按照或的关系处理
* @param startTime 必选 string 开始时间，根据需求，可以是只包含时间的，也可以是包含日期和时区的时间，根据需求来决定
* @param endTime 必选 string 结束时间，根据需求，可以是只包含时间的，也可以是包含日期和时区的时间，根据需求来决定
* @param duration 必选 long 播放时长，当按照时长播放时，才有效。单位为毫秒
* @param enable 必选 bool 场景是否有效，true表示播放此场景，false表示不播放
* @param id 必选 number 在整个播放方案需要保持唯一
* @param name 必选 string 名称
* @param page 必选 object 页面
* @param id 必选 number 在整个播放方案需要保持唯一
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
* @param backgroundDrawable 必选 string 背景图片资源,默认为空
* @param contents 必选 object 窗口挂件内容
* @param widgets 必选 object 窗口挂件
* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
* @param border 非必选 object 边框，表示媒体类型为边框
* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
* @param cornerRadius 非必选 string 边框的角半径，单位目前支持像素和百分比
* @param effects 非必选 object 特效动画
* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
* @param isHeadTail 非必选 boolean 是否开启首尾相接
* @param speed 非必选 float 速度表示像素/秒
* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
* @param name 必选 string 名称
* @param style 非必选 int 样式
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param cron 必选 stringArray cron表达式
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param enable 必选 bool 媒体是否有效，当为无效时，则不播放此媒体
* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
* @param inAnimation 必选 object 入场动画
* @param duration 必选 long 动画持续时间，单位为毫秒。当type 为无特效时，此自动无意义
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param layout 必选 object 布局
* @param height 必选 string 高(例如0.5000)
* @param width 必选 string 宽(例如0.5000)
* @param x 必选 string 起始x(例如0.2568)
* @param y 必选 string 起始y(例如0.2568)
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param -background 非必选 object 表盘背景色，可以为透明，也可以是可绘制的图片
* @param color 必选 string 无
* @param -date 必选 object 日期对象
* @param enable 非必选 boolean 日期是否显示
* @param regular 非必选 string 日期格式表达式，例如"$dd/$MM/$yyyy$E"最终结果可以是17/02/2017星期五
* @param --textAttributes 必选 object 日期文本属性
* @param shadowDx 非必选 number x轴的偏移
* @param shadowRadius 非必选 number 阴影半径大小像素为单位
* @param backgroundColor 非必选 string 背景色
* @param font 非必选  object 字体描述
* @param family 必选 stringArray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的
* @param isUnderline 非必选 bool 是否有下划线
* @param size 非必选 number 大小，目前只支持像素为单位
* @param style 必选 string 类型
* @param letterSpacing 必选 int 字间距，单位像素，默认0
* @param shadowColor 非必选 string 阴影颜色
* @param shadowDy 非必选 number y轴的偏移
* @param shadowEnable 非必选 bool 阴影是否使能
* @param strokeEnable 必选 bool 描边是否生效
* @param strokeWidth 必选 int 描边宽度
* @param textColor 必选 string 文字的前景色
* @param weekTemplates 必选 stringarray 表示星期的模板，七个数据项，分别表示星期一到星期日
* @param gmt 非必选 string 时区gmt，例如"GMT-08:00"
* @param -hourHand 必选 object 时针对象属性
* @param color 必选 string 表示时针的颜色
* @param enable 非必选 bool 是否显示
* @param -hourScale 非必选 object 时针刻度
* @param color 非必选 string 颜色，当形状为方形或者圆形时，此字段表示形状的颜色，当形状为数字时，此字段无效
* @param enable 非必选 bool 是否显示
* @param height 非必选 int 形状高度
* @param shape 非必选 string 形状，RECTANGLE：方形；OVAL：圆或椭圆；DIGITAL：数字，只有时针拥有此属性
* @param --textAttributes 必选 object 文本属性，当形状为数字时，此字段表示数字的本文属性
* @param shadowDx 非必选 number x轴的偏移
* @param shadowRadius 非必选 number 阴影半径大小像素为单位
* @param backgroundColor 非必选 string 背景色
* @param font 非必选  object 字体描述
* @param family 必选 stringArray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的
* @param isUnderline 非必选 bool 是否有下划线
* @param size 非必选 number 大小，目前只支持像素为单位
* @param style 必选 string 类型
* @param letterSpacing 必选 int 字间距，单位像素，默认0
* @param shadowColor 非必选 string 阴影颜色
* @param shadowDy 非必选 number y轴的偏移
* @param shadowEnable 非必选 bool 阴影是否使能
* @param strokeEnable 必选 bool 描边是否生效
* @param strokeWidth 必选 int 描边宽度
* @param textColor 必选 string 文字的前景色
* @param width 非必选 int 形状的宽度
* @param -minuteHand 必选 object 分针对象属性
* @param color 必选 string 分针刻度颜色
* @param enable 非必选 bool 是否显示
* @param -minuteScale 非必选 object 分针刻度
* @param color 非必选 string 颜色，当形状为方形或者圆形时，此字段表示形状的颜色，当形状为数字时，此字段无效
* @param enable 非必选 bool 是否显示
* @param height 非必选 int 形状高度
* @param shape 非必选 string 形状，RECTANGLE：方形；OVAL：圆或椭圆；DIGITAL：数字，只有时针拥有此属性
* @param --textAttributes 必选 object 文本属性，当形状为数字时，此字段表示数字的本文属性
* @param shadowDx 非必选 number x轴的偏移
* @param shadowRadius 非必选 number 阴影半径大小像素为单位
* @param backgroundColor 非必选 string 背景色
* @param font 非必选  object 字体描述
* @param family 必选 stringArray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的
* @param isUnderline 非必选 bool 是否有下划线
* @param size 非必选 number 大小，目前只支持像素为单位
* @param style 必选 string 类型
* @param letterSpacing 必选 int 字间距，单位像素，默认0
* @param shadowColor 非必选 string 阴影颜色
* @param shadowDy 非必选 number y轴的偏移
* @param shadowEnable 非必选 bool 阴影是否使能
* @param strokeEnable 必选 bool 描边是否生效
* @param strokeWidth 必选 int 描边宽度
* @param textColor 必选 string 文字的前景色
* @param width 非必选 number 形状宽度
* @param -secondHand 必选 object 秒针对象属性
* @param color 必选 string 秒针刻度颜色
* @param enable 非必选 bool 秒针是否存在
* @param -text 必选 object 固定文本属性对象
* @param enable 非必选 boolean 固定文本是否显示
* @param text 必选 string 固定文本
* @param --textAttributes 必选 object 固定文本属性
* @param shadowDx 非必选 number x轴的偏移
* @param shadowRadius 非必选 number 阴影半径大小像素为单位
* @param backgroundColor 非必选 string 背景色
* @param font 非必选  object 字体描述
* @param family 必选 stringArray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的
* @param isUnderline 非必选 bool 是否有下划线
* @param size 非必选 number 大小，目前只支持像素为单位
* @param style 必选 string 类型
* @param letterSpacing 必选 int 字间距，单位像素，默认0
* @param shadowColor 非必选 string 阴影颜色
* @param shadowDy 非必选 number y轴的偏移
* @param shadowEnable 非必选 bool 阴影是否使能
* @param strokeEnable 必选 bool 描边是否生效
* @param strokeWidth 必选 int 描边宽度
* @param textColor 必选 string 文字的前景色
* @param zone 必选 string 时区，如Asia/Shanghai
* @param name 非必选 string 名称
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param outAnimation 必选 object 出场动画
* @param duration 必选 long 动画持续时间，单位为毫秒。当type 为无特效时，此自动无意义
* @param type 必选 int 动画类型
* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param zOrder 必选 int z序列
* @param enable 必选 bool 媒体是否有效，当为无效时，则不播放此媒体
* @param id 必选 number id标识
* @param itemsSource 必选 string 媒体列表
* @param layout 必选 object 布局
* @param height 必选 string 无
* @param width 必选 string 无
* @param x 必选 string 无
* @param y 必选 string 无
* @param name 必选 string 名称
* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
* @param zOrder 必选 int z序列
* @param widgets 必选 object 窗口挂件
* @param repeatCount 必选 int 重复次数，当按照次数播放时，才有效
* @param rules 必选 string 规则 DURATION：按照时长播放，TIMES:按照次数播放
* @param type 必选 string PAGE或PLAYLIST
* @param uuid 必选 string 唯一标识
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑节目
* @title 模拟时钟
* @description 此字段表示模拟时钟媒体中的metadata部分，对应媒体类型为：ANALOG_CLOCK。
* @url ""
* @json_param {"programID":1,"pageID":1,"pageInfo":{"id":1,"name":"节目06","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":5000,"metadata":{"date":{"textAttributes":{"font":{"size":16},"textColor":"#ffffff00"},"weekTemplates":["星期日","星期一","星期二","星期三","星期四","星期五","星期六"]},"hourHand":{"color":"#ffffff00"},"minuteHand":{"color":"#ff00ff00"},"secondHand":{"color":"#ffff0000"},"text":{"text":"","textAttributes":{"font":{"size":12},"textColor":"#ffff0000"}}},"name":"模拟时钟","type":"ANALOG_CLOCK"}]}}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param id 必选 int id标识
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param contents 必选 object 窗口挂件内容
* @param widgets 必选 objectArray 窗口挂件
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param cron 必选 stringArray cron表达式
* @param endTime 必选 string 结束时间
* @param startTime 必选 string 开始时间
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param metadata 必选 object 元数据，即为一个窗口挂件的私有数据成员集合
* @param -date 必选 object 日期对象
* @param --textAttributes 必选 object 日期文本属性
* @param --font 必选 object 日期文本描述
* @param --size 必选 object 日期文本大小
* @param --textColor 必选 object 日期文本的前景色
* @param weekTemplates 必选 stringarray 表示星期的模板，七个数据项，分别表示星期一到星期日
* @param -hourHand 必选 object 时针对象属性
* @param color 必选 string 表示时针的颜色
* @param -minuteHand 必选 object 分针对象属性
* @param color 必选 string 表示分针的颜色
* @param -secondHand 必选 object 分针对象属性
* @param color 必选 string 表示秒针的颜色
* @param -text 必选 object 固定文本属性对象
* @param text 必选 string 固定文本
* @param --textAttributes 必选 object 固定文本属性
* @param --font 必选 object 固定文本描述
* @param --size 必选 object 固定文本大小
* @param --textColor 必选 object 固定文本的前景色
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title RSS媒体
* @description 编辑节目，此接口为RSS媒体详解，媒体类型为：SIMPLE_RSS
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"metadata":{"titleEnable":true,"pubTimeEnable":true,"bodyEnable":true,"bodyImageEnable":false,"displayStyle":{"type":"PAGE_SWITCH","pageSwitchAttributes":{"inAnimation":{"type":17,"duration":1000},"remainDuration":5000},"scrollAttributes":{"effects":{"speed":5,"animation":"MARQUEE_UP","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}}},"textAttributes":{"title":{"textColor":"#FF0000","font":{"family":["Arial"],"style":"NORMAL","size":18,"isUnderline":false}},"pubTime":{"textColor":"#FFFF00","font":{"family":["Arial"],"style":"NORMAL","size":16,"isUnderline":false}},"body":{"textColor":"#00FF00","font":{"family":["Arial"],"style":"NORMAL","size":18,"isUnderline":false}}}},"dataSource":"http://tech.qq.com/web/it/telerss.xml","type":"SIMPLE_RSS","name":"RSS","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param contents 必选 object 窗口挂件内容
* @param name 必选 string widgetContainers的名称
* @param widgets 必选 objectArray 窗口挂件
* @param name 必选 string 名称
* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param inAnimation 非必选 object 入场动画
* @param type 非必选 int 动画类型。0表示没有特效，1表示随机特效
* @param duration 非必选 long 特效播放时长，单位为毫秒
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，网页，gif，视频，图片(无特效)时不需要此字段
* @param updatePeriod 非必选 long 更新周期,单位为毫秒，默认为60000ms
* @param titleEnable 非必选 bool 标题是否显示,默认显示(true)
* @param pubTimeEnable 非必选 bool 发布时间是否显示，默认显示(true)
* @param bodyEnable 非必选 bool 主体部分是否显示,默认显示(true)
* @param bodyImageEnable 非必选 bool 主体部分的图片是否显示，默认显示(true)
* @param displayStyle 必选 object 显示风格
* @param type 必选 string PAGE_SWITCH或SCROLL，表示按照页切换或者滚动模式,PAGE_SWITCH则PageSwitchAttributes有效,SCROLL则ScrollAttributes有效
* @param pageSwitchAttributes 必选 object 按照页切换的属性
* @param inAnimation 必选 object 入场动画
* @param type 非必选 int 入场动画类型，默认无特效
* @param duration 必选 long 特效时间，单位毫秒
* @param remianDuration 必选 long 保留时间，单位毫秒
* @param scrollAttributes 非必选 object 滚动属性描述
* @param effects object 必选 滚动特效描述
* @param animation 必选 string 1.MARQUEE_LEFT：向左移动，默认情况下是单行向左移动，2.MARQUEE_UP：向上移动，整屏幕滚动，3.MARQUEE_DOWN：向下移动，整屏幕滚动4.MARQUEE_RIGHT：向右滚动，默认情况下是单行向左移动，文字要倒过来
* @param speed 必选 float 速度，单位像素每秒
* @param textAttributes 必选 object 文字的属性
* @param title 必选 object 标题字体样式
* @param textColor 非必选 string 文字的前景色，默认#FF0000
* @param font 必选 object 字体描述
* @param family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param pubTime 必选 object 时间字体样式，同title
* @param body 必选 object 正文字体样式，同title
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是数据文件(md5.png)，网址，流媒体路径等
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param name 必选 string 媒体名称,图片、视频、gif媒体为媒体文件名称
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param isSupportSpecialEffects 必选 bool 是否支持播放特效。支持特效时true,不支持特效为false
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑节目
* @title 炫彩字媒体
* @description 编辑节目，此接口为炫彩字metadata示例，媒体类型：COLORFUL_TEXT
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"metadata":{"content":{"content":"请输入文字!","scrollAttributes":{"effects":{"speed":5,"animation":"MARQUEE_LEFT","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"textAttributes":{"effects":{"type":"GRADIENT_HORIZONTAL","colors":["#FF0000","#FF00B050","#FFC00000","#FF007BD4","#FFFFFF00","#FF00FF"],"texture":""},"textColor":"#FF0000","font":{"family":["Arial"],"style":"NORMAL","size":50,"isUnderline":false}}}},"dataSource":"","type":"COLORFUL_TEXT","name":"炫彩字","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param contents 必选 object 窗口挂件内容
* @param name 必选 string widgetContainers的名称
* @param widgets 必选 objectArray 窗口挂件
* @param name 必选 string 名称
* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT，但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param inAnimation 非必选 object 入场动画
* @param type 非必选 int 动画类型。0表示没有特效，1表示随机特效
* @param duration 非必选 long 特效播放时长，单位为毫秒
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，网页，gif，视频，图片(无特效)时不需要此字段
* @param content 必选 object 炫彩字详细设置信息
* @param content 必选 string 显示文本内容
* @param scrollAttributes 必选 object 滚动属性描述
* @param effects 必选 object 滚动特效描述
* @param animation 必选 string MARQUEE_LEFT或MARQUEE_RIGHT
* @param speed 必选 float 速度,单位像素/s或者档位（1-10）
* @param speedByPixelEnable 必选 bool 如果为true则是像素每秒，false为档位，默认为false
* @param isHeadTail 必选 bool 是否开启首尾相接，默认不开启(false)
* @param headTailSpacing 必选 string 首尾相接字间距，单位像素或者（屏幕百分比%）
* @param textAttributes 必选 object 文本属性列表
* @param effects 必选 object 炫彩字播放特效
* @param type 必选 string 特效类型，对于文本属性中的特效有五种，GRADIENT_HORIZONTAL（水平渐变）、GRADIENT_VERTICAL（垂直渐变）、GRADIENT_OBLIQUE（斜角渐变）、FADE_IN_FADE_OUT(淡入淡出)、TEXTURE（纹理）
* @param colors 必选 stringObject 渐变的颜色
* @param texture 非必选 string 当type为TEXTURE时有效，图片名字，如1.jpg
* @param textColor 非必选 string 文字的前景色，默认#FF0000
* @param font 必选 object 字体描述
* @param family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是数据文件(md5.png)，网址，流媒体路径等
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param name 必选 string 媒体名称,图片、视频、gif媒体为媒体文件名称
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param isSupportSpecialEffects 必选 bool 是否支持播放特效。支持特效时true,不支持特效为false
* @return ""
* @remark
* @number 99
*/


/**
* showdoc
* @catalog 接口示例/节目/编辑节目
* @title 环境监测媒体
* @description 编辑节目，环境监测媒体metadata，对应媒体类型为：RT_MEDIA
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"metadata":{"updatePeriod":10000,"temperatureUnit":"Celsius","regular":"噪音:$n\n温度:$t\n气湿:$AH\n气压:$AP\n风速:$WS\n风向:$WD\nPM2.5:$PM2.5\nPM10:$PM10\nCO2:$CO2\n","solidText":{"text":"","textAttributes":{"textColor":"#FFF56E00","font":{"family":["Arial"],"style":"NORMAL","size":12,"isUnderline":false}}},"textAttributes":{"textColor":"#FFF56E00","font":{"family":["楷体"],"style":"NORMAL","size":32,"isUnderline":false}},"valueTextAttributes":{"textColor":"#FFF56E00","font":{"family":["Arial"],"style":"NORMAL","size":16,"isUnderline":false}},"unitTextAttributes":{"textColor":"#FFF56E00","font":{"family":["Arial"],"style":"NORMAL","size":32,"isUnderline":false}},"displayStyle":{"type":"PAGE_SWITCH","pageSwitchAttributes":{"inAnimation":{"type":1,"duration":1000},"remainDuration":3000},"scrollAttributes":{"effects":{"speed":3,"animation":"MARQUEE_UP","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}}},"layoutStyles":[{"type":1,"horizontalAlignment":"RIGHT","proportion":50},{"type":0,"horizontalAlignment":"CENTER","proportion":1},{"type":4,"horizontalAlignment":"CENTER","proportion":49}],"regularContents":[{"key":"$t","type":0,"unit":"℃"},{"key":"$n","type":0,"unit":"dB"},{"key":"$WS","type":0,"unit":"km/h"},{"key":"$WD","type":0,"unit":"","Templates":["北风","东北风","东风","东南风","南风","西南风","西风","西北风"]},{"key":"$AT","type":0,"unit":"℃"},{"key":"$AP","type":0,"unit":"kPa"},{"key":"$AH","type":0,"unit":"%RH"},{"key":"$PM2.5","type":0,"unit":"μg/m3"},{"key":"$PM10","type":0,"unit":"μg/m3"},{"key":"$CO2","type":0,"unit":"ppm"}]},"dataSource":"","type":"RT_MEDIA","name":"环境监测","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param contents 必选 object 窗口挂件内容
* @param name 必选 string widgetContainers的名称
* @param widgets 必选 objectArray 窗口挂件
* @param name 必选 string 名称
* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param inAnimation 非必选 object 入场动画
* @param type 非必选 int 动画类型。0表示没有特效，1表示随机特效
* @param duration 非必选 long 特效播放时长，单位为毫秒
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，网页，gif，视频，图片(无特效)时不需要此字段
* @param updatePeriod 必选 long 更新周期,单位为毫秒(如果为0，则只读取一次)
* @param temperatureUnit 必选 string 温度探头Celsius或Fahrenheit，分别表示摄氏度或者华氏度
* @param regular 必选 string 播放规则`1`.$longitude：经度；`2`.$latitude：表示纬度；`3`.$altitude：表示海拔；`4`.$PM2.`5`：表示PM2.5，单位μg/m3；`5`.$WS：表示风速，单位：Km/H，m/s,级，类型：0：千米每小时，1：米每秒，默认千米每小时，2：级；`6`.$WP：表示风力；`7`.$WD：表示风向；`8`.$h：表示湿度；`9`.$t：表示温度，单位：℃，℉，°，类型为0:摄氏度1:华氏度，默认摄氏度；`10`.$n:表示噪声,单位：dB；`11`.$CO2:表示二氧化碳,单位μg/m3；`12`.$AT：表示气温，单位℃，℉，°，类型0:摄氏度，1:华氏度，默认摄氏度；`13`.$AH:表示气湿,单位RH；`14`.$AP：表示气压,单位KPa，bar，atm，mmHg，Torr，kgf/cm2，类型：0:KPa，1:bar，2:atm，3:mmHg，4:Torr，5:kgfcm2，6：hpa,默认KPa；`15`.$SH:表示土壤湿度（定制）,单位RH；`16`.$ST:表示土壤温度（定制）,单位：℃，℉，°，类型：0:摄氏度，1:华氏度，默认摄氏度；`17`：\n：表示换行；`18`：&#160；(此处的分号是英文分号)：表示空格
* @param solidText 非必选 object 固定文本
* @param text 必选 string 固定文本内容
* @param textAttributes 非必选 object 标题样式
* @param textColor 必选 string 文字的前景色，默认#FF0000
* @param font 必选 object 字体描述
* @param family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param textAttributes 必选 object 标签文本属性，详情同textAttributes
* @param valueTextAttributes 必选 object 数值文本属性，详情同textAttributes
* @param unitTextAttributes 必选 object 单位文本属性，详情同textAttributes
* @param displayStyle 必选 object 显示风格
* @param type 必选 string PAGE_SWITCH、SCROLL、STATIC：表示按照页切换、滚动模式、静止模式（若文字内容大于屏幕，仅显示第一屏）
* @param pageSwitchAttributes	必选 object 按照页切换的属性
* @param inAnimation 必选 object 入场动画
* @param type 非必选 int 入场动画类型，默认无特效
* @param duration 必选 long 特效时间，单位毫秒
* @param remianDuration 必选 long 保留时间，单位毫秒
* @param effects 必选 object 滚动特效描述
* @param animation 必选 string MARQUEE_LEFT或MARQUEE_UP
* @param speed 必选 float 速度,单位像素/s或者档位（1-10）
* @param speedByPixelEnable 必选 bool 如果为true则是像素每秒，false为档位，默认为false
* @param isHeadTail 必选 bool 是否开启首尾相接，默认不开启(false)
* @param headTailSpacing 必选 string 首尾相接字间距，单位像素或者（屏幕百分比%）
* @param layoutStyles 必选 objectarray 布局样式数组
* @param type 必选 int 0：间距，1：自定义标签，2：数值，3：单位，4：数值、单位
* @param horizontalAlignment 必选 string 水平方向对齐方式，分别为：LEFT，CENTER，RIGHT
* @param verticalAlignment 必选 string 垂直方向对齐方式，分别为：BOTTOM，CENTER，TOP（V1.9.0+）
* @param proportion	必选 int 最大范围100
* @param -regularContents 必选 objectarray 媒体内容
* @param key 必选 string 详细见regular的占位符定义及其相关属性
* @param unit 必选 string 对应数值的单位
* @param type 必选 int 对应不同单位的换算类型
* @param templates 必选 stringarray	仅对风向支持，必须按照顺序："北风"，"东北风"，"东风"，"东南风"，"南风"，"西南风"，"西风"，"西北风"
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是数据文件(md5.png)，网址，流媒体路径等
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param name 必选 string 媒体名称,图片、视频、gif媒体为媒体文件名称
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param isSupportSpecialEffects 必选 bool 是否支持播放特效。支持特效时true,不支持特效为false
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑节目
* @title 流媒体
* @description 编辑节目，流媒体metadata，对应媒体类型为：STREAM_MEDIA
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"metadata":{"subType":"STREAM","modelData":{"src":"http://ivi.bupt.edu.cn/hls/cctv1hd.m3u8","volume":100,"stream_media_type":"m3u8","stream_media_protocol_type":"hls"}},"dataSource":"","type":"STREAM_MEDIA","name":"流媒体","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param contents 必选 object 窗口挂件内容
* @param name 必选 string widgetContainers的名称
* @param widgets 必选 objectArray 窗口挂件
* @param name 必选 string 名称
* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param inAnimation 非必选 object 入场动画
* @param type 非必选 int 动画类型。0表示没有特效，1表示随机特效
* @param duration 非必选 特效播放时长，单位为毫秒
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param modelData 必选 object 流媒体参数
* @param src 必选 string 流媒体地址
* @param stream_media_protocol_type 必选 string 流媒体协议类型
* @param stream_media_type 必选 string 流媒体类型
* @param volume 必选 int 流媒体音量
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是数据文件(md5.png)，网址，流媒体路径等
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param name 必选 string 媒体名称,图片、视频、gif媒体为媒体文件名称
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param isSupportSpecialEffects 必选 bool 是否支持播放特效。支持特效时true,不支持特效为false
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑节目
* @title 计时器媒体
* @description 编辑节目，计时器媒体metadata，对应媒体类型为：COUNT_TIMER
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"metadata":{"solidText":{"textAttributes":{"font":{"size":48,"isUnderline":false,"family":["Arial"],"style":"NORMAL"},"textColor":"#FF0000"},"text":""},"textAttributes":{"font":{"size":48,"isUnderline":false,"family":["Arial"],"style":"NORMAL"},"textColor":"#FF0000"},"regularNew":"$d&#160;$Ud&#160;$H&#160;$UH&#160;$m&#160;$Um&#160;$s&#160;$Us","units":[{"zero":"天","name":"$Ud","singular":"天","plural":"天"},{"zero":"时","name":"$UH","singular":"时","plural":"时"},{"zero":"分","name":"$Um","singular":"分","plural":"分"},{"zero":"秒","name":"$Us","singular":"秒","plural":"秒"}],"regular":"$d&#160;天&#160;$H&#160;时&#160;$m&#160;分&#160;$s&#160;秒","targetDateTime":1602864000000,"countType":"COUNT_DOWN"},"dataSource":"","type":"COUNT_TIMER","name":"计时器","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param contents 必选 object 窗口挂件内容
* @param name 必选 string widgetContainers的名称
* @param widgets 必选 objectArray 窗口挂件
* @param name 必选 string 名称
* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param inAnimation 非必选 object 入场动画
* @param type 非必选 int 动画类型。0表示没有特效，1表示随机特效
* @param duration 非必选 特效播放时长，单位为毫秒
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param regular 必选 string 播放规则，1.$T:表示固定文本；2.$d：表示日；3.$H：表示时；4.$m：表示分；5.$s：表示秒；6.$Ud：表示日的单位；7.$UH：表示时的单位；8.$Um：表示分的单位；9.$Us：表示秒的单位；10.\n：表示换行；11.&#160；(此处的分号是英文分号)：表示空格
* @param regularNew 必选 string 规则，1.5.0终端添加计时媒体单位单复数的功能，需要添加新规则
* @param units 必选 object 单位替换数组
* @param name 必选 string 替换名称
* @param singular 必选 string 单数名称
* @param plural 必选 string 复数名称
* @param zero 必选 string 为0时显示的单位
* @param solidText 必选 object 固定文本属性对象
* @param text 非必选 string 固定文本
* @param textAttributes 非必选 object 固定文本显示
* @param textColor 必选 string 文字的前景色，默认#FF0000
* @param font 必选 object 字体描述
* @param family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param targetDateTime 必选 long UTC时间戳(单位是毫秒)
* @param countType 必选 string 计时类型(COUNT_DOWN: 表示倒计时;COUNT_UP：表示正计时;)
* @param textAttributes 必选 object 计时文本属性，参考固定文本textAttributes属性
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是数据文件(md5.png)，网址，流媒体路径等
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param name 必选 string 媒体名称,图片、视频、gif媒体为媒体文件名称
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param isSupportSpecialEffects 必选 bool 是否支持播放特效。支持特效时true,不支持特效为false
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title 网页媒体
* @description 编辑节目，此接口为网页详解。metadata为空，类型为:HTML
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z+8:00","startTime":"1970-01-01T00:00:00Z+8:00"}],"duration":10000,"inAnimation":{"duration":1000,"type":1},"dataSource":"https://www.baidu.com/","type":"HTML","name":"网页","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param contents 必选 object 窗口挂件内容
* @param name 必选 string widgetContainers的名称
* @param widgets 必选 objectArray 窗口挂件
* @param name 必选 string 名称
* @param type 必选 string 类型,COLORFUL_TEXT：炫彩字；PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param inAnimation 非必选 object 入场动画
* @param type 非必选 int 动画类型。0表示没有特效，1表示随机特效
* @param duration 非必选 特效播放时长，单位为毫秒
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是数据文件(md5.png)，网址，流媒体路径等
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param name 必选 string 媒体名称,图片、视频、gif媒体为媒体文件名称
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param isSupportSpecialEffects 必选 bool 是否支持播放特效。支持特效时true,不支持特效为false
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title RSS媒体
* @description 编辑节目，此接口为RSS媒体metadata详解，媒体类型为：SIMPLE_RSS
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"pageNew","widgetContainers":[{"zOrder":1,"layout":{"x":"0","y":"0","width":"1","height":"1"},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"contents":{"widgets":[{"layout":{"x":"0%","y":"0%","width":"100%","height":"100%"},"inAnimation":{"type":0,"duration":1000},"outAnimation":{"type":0,"duration":1000},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"constraints":[{"startTime":"1970-01-01T00:00:00Z+8:00","endTime":"4012-01-01T23:59:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}],"metadata":{"updatePeriod":60000,"titleEnable":true,"pubTimeEnable":true,"bodyEnable":true,"bodyImageEnable":false,"displayStyle":{"type":"PAGE_SWITCH","singleLine":true,"pageSwitchAttributes":{"inAnimation":{"type":17,"duration":1000},"remainDuration":5000},"scrollAttributes":{"effects":{"speed":5,"animation":"MARQUEE_UP","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"offset":{"x":0,"y":0}},"textAttributes":{"title":{"backgroundColor":"#00FFFFFF","textColor":"#FF0000","font":{"family":["Arial"],"style":"NORMAL","size":18,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0},"pubTime":{"backgroundColor":"#00FFFFFF","textColor":"#FFFF00","font":{"family":["Arial"],"style":"NORMAL","size":16,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0},"body":{"backgroundColor":"#00FFFFFF","textColor":"#00FF00","font":{"family":["Arial"],"style":"NORMAL","size":18,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0}}},"displayRatio":"FULL","filesize":1024,"zOrder":1,"dataSource":"http://tech.qq.com/web/it/telerss.xml","backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","name":"RSS","enable":true,"type":"SIMPLE_RSS","duration":10000,"repeatCount":1,"id":100000,"uuid":"099a5635-8250-4392-9ede-964087db8bc6"}],"widgetContainer":[],"enable":false,"zOrder":0,"id":0,"uuid":"5a0e9597-737a-428f-acd8-a0846b480d97"},"PCType":0,"name":"页面1","enable":true,"pickPolicy":"ORDER","id":200000,"uuid":"3ee6e06b-5a05-4cd7-84b8-c8668b4f6d53"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
* @param backgroundDrawable 必选 string 背景图片资源,默认为空
* @param contents 必选 object 窗口挂件内容
* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
* @param itemsSource 必选 string 媒体列表
* @param layout 必选 object 布局
* @param x 必选 string 起始x(例如0.2568)
* @param y 必选 string 起始y(例如0.2568)
* @param width 必选 string 宽(例如0.5000)
* @param height 必选 string 高(例如0.5000)
* @param name 必选 string widgetContainers的名称
* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
* @param zOrder 必选 int z序列
* @param widgets 必选 objectArray 窗口挂件
* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
* @param mid 必选 int 媒体资源的唯一标识
* @param name 必选 string 名称
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param updatePeriod 非必选 long 更新周期,单位为毫秒，默认60000ms
* @param titleEnable 非必选 bool 标题是否显示,默认显示(true)
* @param pubTimeEnable 非必选 bool 发布时间是否显示，默认显示(true)
* @param bodyEnable 非必选 bool 主体部分是否显示,默认显示(true)
* @param bodyImageEnable 非必选 bool 主体部分的图片是否显示，默认显示(true)
* @param -displayStyle 必选 object 显示风格
* @param type 必选 string PAGE_SWITCH或SCROLL，表示按照页切换或者滚动模式,PAGE_SWITCH则PageSwitchAttributes有效,SCROLL则ScrollAttributes有效
* @param --pageSwitchAttributes 必选 object 按照页切换的属性
* @param ---inAnimation 必选 object 入场动画
* @param type 非必选 int 入场动画类型，默认无特效
* @param duration 必选 long 特效时间，单位毫秒
* @param remianDuration 必选 long 保留时间，单位毫秒
* @param --scrollAttributes 非必选 object 滚动属性描述
* @param ---effects object 必选 滚动特效描述
* @param animation 必选 string 1.MARQUEE_LEFT：向左移动，默认情况下是单行向左移动，2.MARQUEE_UP：向上移动，整屏幕滚动，3.MARQUEE_DOWN：向下移动，整屏幕滚动4.MARQUEE_RIGHT：向右滚动，默认情况下是单行向左移动，文字要倒过来
* @param speed 必选 float 速度，单位像素每秒
* @param -textAttributes 必选 object 文字的属性
* @param --title 必选 object 标题字体样式
* @param backgroundColor 非必选 string 背景色，默认00FFFFFF
* @param textColor 非必选 string 文字的前景色，默认#FF0000
* @param ---font 必选 object 字体描述
* @param ----family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param letterSpacing 必选 int 字间距，单位像素，默认0
* @param shadowEnable 必选 bool 阴影是否使能，默认false
* @param shadowRadius 必选 int 阴影半径大小像素为单位，默认10
* @param shadowDx 必选 int x轴的偏移
* @param shadowDy 必选 int y轴的偏移
* @param shadowColor 必选 string 阴影颜色，默认#00ff00
* @param strokeEnable 必选 bool 描边是否生效
* @param strokeWidth 必选 int 描边宽度
* @param strokeColor 必选 string 描边颜色
* @param --pubTime 必选 object 时间字体样式，同title
* @param --body 必选 object 正文字体样式，同title
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
* @param layout 必选 object 布局
* @param x 必选 string 无
* @param y 必选 string 无
* @param width 必选 string 无
* @param height 必选 string 无
* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
* @param inAnimation 必选 object 入场动画
* @param type 必选 int 动画类型
* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
* @param outAnimation 必选 object 出场动画
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
* @param zOrder 必选 int z序列
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param border 非必选 object 边框
* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
* @param style 非必选 int 样式
* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param name 非必选 string 名称
* @param cornerRadius 非必选 string 边框的角半径，单位目前支持像素和百分比
* @param effects 非必选 object 特效动画
* @param speed 非必选 float 速度，像素/秒
* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
* @param isHeadTail 非必选 boolean 是否开启首尾相接
* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
* @param functionStorage 必选 string 默认为空
* @param isSupportSpecialEffects 必选 string 是否支持播放特效
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title 炫彩字媒体
* @description 编辑节目，此接口为炫彩字metadata示例，媒体类型：COLORFUL_TEXT
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"pageNew","widgetContainers":[{"zOrder":1,"layout":{"x":"0","y":"0","width":"1","height":"1"},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"contents":{"widgets":[{"layout":{"x":"0%","y":"0%","width":"100%","height":"100%"},"inAnimation":{"type":0,"duration":1000},"outAnimation":{"type":0,"duration":1000},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"constraints":[{"startTime":"1970-01-01T00:00:00Z 8:00","endTime":"4012-01-01T23:59:59Z 8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}],"metadata":{"content":{"content":"请输入文字!","scrollAttributes":{"effects":{"speed":5,"animation":"MARQUEE_LEFT","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"textAttributes":{"effects":{"type":"GRADIENT_HORIZONTAL","colors":["#FF0000","#FF00B050","#FFC00000","#FF007BD4","#FFFFFF00","#FF00FF"],"texture":""},"backgroundColor":"#00FFFFFF","textColor":"#FF0000","font":{"family":["Arial"],"style":"NORMAL","size":50,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":2,"shadowDy":2,"shadowColor":"#6128bf","strokeEnable":false,"strokeWidth":2,"strokeColor":"#6128bf","letterSpacing":1}}},"displayRatio":"FULL","filesize":1024,"zOrder":1,"backgroundColor":"#FF1F8787","backgroundDrawable":"","backgroundMusic":"","name":"炫彩字","enable":true,"type":"COLORFUL_TEXT","duration":10000,"repeatCount":1,"id":100000,"uuid":"3dc02eef-b736-4817-b107-ea4c696e61f1"}],"widgetContainer":[],"enable":false,"zOrder":0,"id":0,"uuid":"71052088-28d3-48cf-9f03-08e16e189fe8"},"PCType":0,"name":"页面1","enable":true,"pickPolicy":"ORDER","id":200000,"uuid":"9e2a4114-6bec-4cb0-8d3e-93652ff0bb50"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
* @param backgroundDrawable 必选 string 背景图片资源,默认为空
* @param contents 必选 object 窗口挂件内容
* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
* @param itemsSource 必选 string 媒体列表
* @param layout 必选 object 布局
* @param x 必选 string 起始x(例如0.2568)
* @param y 必选 string 起始y(例如0.2568)
* @param width 必选 string 宽(例如0.5000)
* @param height 必选 string 高(例如0.5000)
* @param name 必选 string widgetContainers的名称
* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
* @param zOrder 必选 int z序列
* @param widgets 必选 objectArray 窗口挂件
* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
* @param mid 必选 int 媒体资源的唯一标识
* @param name 必选 string 名称
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param content 必选 object 炫彩字详细设置信息
* @param -content 必选 string 显示文本内容
* @param -scrollAttributes 必选 object 滚动属性描述
* @param --effects 必选 object 滚动特效描述
* @param animation 必选 string MARQUEE_LEFT或MARQUEE_RIGHT
* @param speed 必选 float 速度,单位像素/s或者档位（1-10）
* @param speedByPixelEnable 必选 bool 如果为true则是像素每秒，false为档位，默认为false
* @param isHeadTail 必选 bool 是否开启首尾相接，默认不开启(false)
* @param headTailSpacing 必选 string 首尾相接字间距，单位像素或者（屏幕百分比%）
* @param --textAttributes 必选 object 文本属性列表
* @param ---effects 必选 object 炫彩字播放特效
* @param type 必选 string 特效类型，对于文本属性中的特效有五种，GRADIENT_HORIZONTAL（水平渐变）、GRADIENT_VERTICAL（垂直渐变）、GRADIENT_OBLIQUE（斜角渐变）、FADE_IN_FADE_OUT(淡入淡出)、TEXTURE（纹理）
* @param colors 必选 stringObject 渐变的颜色
* @param texture 非必选 string 当type为TEXTURE时有效，图片名字，如1.jpg
* @param backgroundColor 非必选 string 背景色，默认00FFFFFF
* @param textColor 非必选 string 文字的前景色，默认#FF0000
* @param ---font 必选 object 字体描述
* @param ----family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param letterSpacing 必选 int 字间距，单位像素，默认0
* @param shadowEnable 必选 bool 阴影是否使能，默认false
* @param shadowRadius 必选 int 阴影半径大小像素为单位，默认10
* @param shadowDx 必选 int x轴的偏移
* @param shadowDy 必选 int y轴的偏移
* @param shadowColor 必选 string 阴影颜色，默认#00ff00
* @param strokeEnable 必选 bool 描边是否生效
* @param strokeWidth 必选 int 描边宽度
* @param strokeColor 必选 string 描边颜色
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
* @param layout 必选 object 布局
* @param x 必选 string 无
* @param y 必选 string 无
* @param width 必选 string 无
* @param height 必选 string 无
* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
* @param inAnimation 必选 object 入场动画
* @param type 必选 int 动画类型
* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
* @param outAnimation 必选 object 出场动画
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
* @param zOrder 必选 int z序列
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param border 非必选 object 边框
* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
* @param style 非必选 int 样式
* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param name 非必选 string 名称
* @param cornerRadius 非必选 string 边框的角半径，单位目前支持像素和百分比
* @param effects 非必选 object 特效动画
* @param speed 非必选 float 速度，像素/秒
* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
* @param isHeadTail 非必选 boolean 是否开启首尾相接
* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
* @param functionStorage 必选 string 默认为空
* @param isSupportSpecialEffects 必选 string 是否支持播放特效
* @return ""
* @remark
* @number 99
*/


/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title 环境监测媒体
* @description 编辑节目，环境监测媒体metadata，对应媒体类型为：RT_MEDIA
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"pageNew","widgetContainers":[{"zOrder":1,"layout":{"x":"0","y":"0","width":"1","height":"1"},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"contents":{"widgets":[{"layout":{"x":"0%","y":"0%","width":"100%","height":"100%"},"inAnimation":{"type":0,"duration":1000},"outAnimation":{"type":0,"duration":1000},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"constraints":[{"startTime":"1970-01-01T00:00:00Z+8:00","endTime":"4012-01-01T23:59:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}],"metadata":{"updatePeriod":60000,"temperatureUnit":"Celsius","regular":"噪音:$n\n温度:$t\n气湿:$AH\n气压:$AP\n风速:$WS\n风向:$WD\nPM2.5:$PM2.5\nPM10:$PM10\nCO2:$CO2\n","solidText":{"text":"","textAttributes":{"backgroundColor":"#00FFFFFF","textColor":"#FFF56E00","font":{"family":["Arial"],"style":"NORMAL","size":12,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0}},"textAttributes":{"backgroundColor":"#00FFFFFF","textColor":"#FFF56E00","font":{"family":["楷体"],"style":"NORMAL","size":32,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0},"valueTextAttributes":{"backgroundColor":"#00FFFFFF","textColor":"#FFF56E00","font":{"family":["Arial"],"style":"NORMAL","size":16,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0},"unitTextAttributes":{"backgroundColor":"#00FFFFFF","textColor":"#FFF56E00","font":{"family":["Arial"],"style":"NORMAL","size":32,"isUnderline":false},"shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0},"temperatureCompensation":0,"displayStyle":{"type":"PAGE_SWITCH","singleLine":true,"pageSwitchAttributes":{"inAnimation":{"type":1,"duration":1000},"remainDuration":3000},"scrollAttributes":{"effects":{"speed":3,"animation":"MARQUEE_UP","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"offset":{"x":0,"y":0}},"layoutStyles":[{"type":1,"horizontalAlignment":"RIGHT","proportion":50},{"type":0,"horizontalAlignment":"CENTER","proportion":1},{"type":4,"horizontalAlignment":"CENTER","proportion":49}],"regularContents":[{"key":"$t","type":0,"unit":"℃","compensation":0.0},{"key":"$n","type":0,"unit":"dB","compensation":0.0},{"key":"$WS","type":0,"unit":"km/h","compensation":0.0},{"key":"$WD","type":0,"unit":"","compensation":0.0,"Templates":["北风","东北风","东风","东南风","南风","西南风","西风","西北风"]},{"key":"$AT","type":0,"unit":"℃","compensation":0.0},{"key":"$AP","type":0,"unit":"kPa","compensation":0.0},{"key":"$AH","type":0,"unit":"%RH","compensation":0.0},{"key":"$PM2.5","type":0,"unit":"μg/m³","compensation":0.0},{"key":"$PM10","type":0,"unit":"μg/m³","compensation":0.0},{"key":"$CO2","type":0,"unit":"ppm","compensation":0.0}]},"displayRatio":"FULL","filesize":1024,"zOrder":1,"backgroundColor":"#FF1F8787","backgroundDrawable":"","backgroundMusic":"","name":"环境监测","enable":true,"type":"RT_MEDIA","duration":10000,"repeatCount":1,"id":100000,"uuid":"3dc02eef-b736-4817-b107-ea4c696e61f1"}],"widgetContainer":[],"enable":false,"zOrder":0,"id":0,"uuid":"71052088-28d3-48cf-9f03-08e16e189fe8"},"PCType":0,"name":"页面1","enable":true,"pickPolicy":"ORDER","id":200000,"uuid":"9e2a4114-6bec-4cb0-8d3e-93652ff0bb50"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
* @param backgroundDrawable 必选 string 背景图片资源,默认为空
* @param contents 必选 object 窗口挂件内容
* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
* @param itemsSource 必选 string 媒体列表
* @param layout 必选 object 布局
* @param x 必选 string 起始x(例如0.2568)
* @param y 必选 string 起始y(例如0.2568)
* @param width 必选 string 宽(例如0.5000)
* @param height 必选 string 高(例如0.5000)
* @param name 必选 string widgetContainers的名称
* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
* @param zOrder 必选 int z序列
* @param widgets 必选 objectArray 窗口挂件
* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
* @param mid 必选 int 媒体资源的唯一标识
* @param name 必选 string 名称
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param updatePeriod 必选 long 更新周期,单位为毫秒(如果为0，则只读取一次)
* @param temperatureUnit 必选 string 温度探头Celsius或Fahrenheit，分别表示摄氏度或者华氏度
* @param regular 必选 string 播放规则`1`.$longitude：经度；`2`.$latitude：表示纬度；`3`.$altitude：表示海拔；`4`.$PM2.`5`：表示PM2.5，单位μg/m3；`5`.$WS：表示风速，单位：Km/H，m/s,级，类型：0：千米每小时，1：米每秒，默认千米每小时，2：级；`6`.$WP：表示风力；`7`.$WD：表示风向；`8`.$h：表示湿度；`9`.$t：表示温度，单位：℃，℉，°，类型为0:摄氏度1:华氏度，默认摄氏度；`10`.$n:表示噪声,单位：dB；`11`.$CO2:表示二氧化碳,单位μg/m3；`12`.$AT：表示气温，单位℃，℉，°，类型0:摄氏度，1:华氏度，默认摄氏度；`13`.$AH:表示气湿,单位RH；`14`.$AP：表示气压,单位KPa，bar，atm，mmHg，Torr，kgf/cm2，类型：0:KPa，1:bar，2:atm，3:mmHg，4:Torr，5:kgfcm2，6：hpa,默认KPa；`15`.$SH:表示土壤湿度（定制）,单位RH；`16`.$ST:表示土壤温度（定制）,单位：℃，℉，°，类型：0:摄氏度，1:华氏度，默认摄氏度；`17`：\n：表示换行；`18`：&#160；(此处的分号是英文分号)：表示空格
* @param -solidText 非必选 object 固定文本
* @param text 必选 string 固定文本内容
* @param --textAttributes 非必选 object 标题样式
* @param backgroundColor 必选 string 背景色，默认00FFFFFF
* @param textColor 必选 string 文字的前景色，默认#FF0000
* @param ---font 必选 object 字体描述
* @param ----family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param letterSpacing 必选 int 字间距，单位像素，默认0
* @param shadowEnable 必选 bool 阴影是否使能，默认false
* @param shadowRadius 必选 int 阴影半径大小像素为单位，默认10
* @param shadowDx 必选 int x轴的偏移
* @param shadowDy 必选 int y轴的偏移
* @param shadowColor 必选 string 阴影颜色，默认#00ff00
* @param strokeEnable 必选 bool 描边是否生效
* @param strokeWidth 必选 int 描边宽度
* @param strokeColor 必选 string 描边颜色
* @param -textAttributes 必选 object 标签文本属性，详情同textAttributes
* @param -valueTextAttributes 必选 object 数值文本属性，详情同textAttributes
* @param -unitTextAttributes 必选 object 单位文本属性，详情同textAttributes
* @param temperatureCompensation 必选 object 温度补偿值，范围为-50~50，默认为0
* @param -displayStyle 必选 object 显示风格
* @param type 必选 string PAGE_SWITCH、SCROLL、STATIC：表示按照页切换、滚动模式、静止模式（若文字内容大于屏幕，仅显示第一屏）
* @param --pageSwitchAttributes	必选 object 按照页切换的属性
* @param ---inAnimation 必选 object 入场动画
* @param type 非必选 int 入场动画类型，默认无特效
* @param duration 必选 long 特效时间，单位毫秒
* @param remianDuration 必选 long 保留时间，单位毫秒
* @param --effects 必选 object 滚动特效描述
* @param animation 必选 string MARQUEE_LEFT或MARQUEE_UP
* @param speed 必选 float 速度,单位像素/s或者档位（1-10）
* @param speedByPixelEnable 必选 bool 如果为true则是像素每秒，false为档位，默认为false
* @param isHeadTail 必选 bool 是否开启首尾相接，默认不开启(false)
* @param headTailSpacing 必选 string 首尾相接字间距，单位像素或者（屏幕百分比%）
* @param -layoutStyles 必选 objectarray 布局样式数组
* @param type 必选 int 0：间距，1：自定义标签，2：数值，3：单位，4：数值、单位
* @param horizontalAlignment 必选 string 水平方向对齐方式，分别为：LEFT，CENTER，RIGHT
* @param verticalAlignment 必选 string 垂直方向对齐方式，分别为：BOTTOM，CENTER，TOP（V1.9.0+）
* @param proportion	必选 int 最大范围100
* @param -regularContents 必选 objectarray 媒体内容
* @param key 必选 string 详细见regular的占位符定义及其相关属性
* @param unit 必选 string 对应数值的单位
* @param type 必选 int 对应不同单位的换算类型
* @param compensation 必选 double 补偿值，详见占位符定义及其相关属性
* @param templates 必选 stringarray	仅对风向支持，必须按照顺序："北风"，"东北风"，"东风"，"东南风"，"南风"，"西南风"，"西风"，"西北风"
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
* @param layout 必选 object 布局
* @param x 必选 string 无
* @param y 必选 string 无
* @param width 必选 string 无
* @param height 必选 string 无
* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
* @param inAnimation 必选 object 入场动画
* @param type 必选 int 动画类型
* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
* @param outAnimation 必选 object 出场动画
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
* @param zOrder 必选 int z序列
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param border 非必选 object 边框
* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
* @param style 非必选 int 样式
* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param name 非必选 string 名称
* @param cornerRadius 非必选 string 边框的角半径，单位目前支持像素和百分比
* @param effects 非必选 object 特效动画
* @param speed 非必选 float 速度，像素/秒
* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
* @param isHeadTail 非必选 boolean 是否开启首尾相接
* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
* @param functionStorage 必选 string 默认为空
* @param isSupportSpecialEffects 必选 string 是否支持播放特效
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title 流媒体
* @description 编辑节目，流媒体metadata，对应媒体类型为：STREAM_MEDIA
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"pageNew","widgetContainers":[{"zOrder":1,"layout":{"x":"0","y":"0","width":"1","height":"1"},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"contents":{"widgets":[{"layout":{"x":"0%","y":"0%","width":"100%","height":"100%"},"inAnimation":{"type":0,"duration":1000},"outAnimation":{"type":0,"duration":1000},"border":{"foregroundColor":"#FF008000","width":1,"name":"border","borderThickness":"0px,0px,0px,0px","cornerRadius":"2%","backgroundColor":"#FF000000","style":0,"styleForExpress":0,"effects":{"speed":3,"animation":"CLOCK_WISE","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"constraints":[{"startTime":"1970-01-01T00:00:00Z+8:00","endTime":"4012-01-01T23:59:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}],"metadata":{"subType":"STREAM","modelData":{"src":"http://ivi.bupt.edu.cn/hls/cctv1hd.m3u8","volume":100,"stream_media_type":"m3u8","stream_media_protocol_type":"hls"}},"displayRatio":"FULL","filesize":1024,"zOrder":1,"backgroundColor":"#00000000","backgroundDrawable":"","backgroundMusic":"","name":"流媒体","enable":true,"type":"STREAM_MEDIA","duration":10000,"repeatCount":1,"id":100000,"uuid":"099a5635-8250-4392-9ede-964087db8bc6"}],"widgetContainer":[],"enable":false,"zOrder":0,"id":0,"uuid":"5a0e9597-737a-428f-acd8-a0846b480d97"},"PCType":0,"name":"页面1","enable":true,"pickPolicy":"ORDER","id":200000,"uuid":"3ee6e06b-5a05-4cd7-84b8-c8668b4f6d53"}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
* @param backgroundDrawable 必选 string 背景图片资源,默认为空
* @param contents 必选 object 窗口挂件内容
* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
* @param itemsSource 必选 string 媒体列表
* @param layout 必选 object 布局
* @param x 必选 string 起始x(例如0.2568)
* @param y 必选 string 起始y(例如0.2568)
* @param width 必选 string 宽(例如0.5000)
* @param height 必选 string 高(例如0.5000)
* @param name 必选 string widgetContainers的名称
* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
* @param zOrder 必选 int z序列
* @param widgets 必选 objectArray 窗口挂件
* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
* @param mid 必选 int 媒体资源的唯一标识
* @param name 必选 string 名称
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param modelData 必选 object 流媒体参数
* @param src 必选 string 流媒体地址
* @param stream_media_protocol_type 必选 string 流媒体协议类型
* @param stream_media_type 必选 string 流媒体类型
* @param volume 必选 int 流媒体音量
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
* @param layout 必选 object 布局
* @param x 必选 string 无
* @param y 必选 string 无
* @param width 必选 string 无
* @param height 必选 string 无
* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
* @param inAnimation 必选 object 入场动画
* @param type 必选 int 动画类型
* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
* @param outAnimation 必选 object 出场动画
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
* @param zOrder 必选 int z序列
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param border 非必选 object 边框
* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
* @param style 非必选 int 样式
* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param name 非必选 string 名称
* @param cornerRadius 非必选 string 边框的角半径，单位目前支持像素和百分比
* @param effects 非必选 object 特效动画
* @param speed 非必选 float 速度，像素/秒
* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
* @param isHeadTail 非必选 boolean 是否开启首尾相接
* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
* @param functionStorage 必选 string 默认为空
* @param isSupportSpecialEffects 必选 string 是否支持播放特效
* @return ""
* @remark
* @number 99
*/

/**
* showdoc
* @catalog 接口示例/节目/编辑复杂节目
* @title 计时器媒体
* @description 编辑节目，计时器媒体metadata，对应媒体类型为：COUNT_TIMER
* @url void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"pageID":1,"pageInfo":{"name":"pageNew","widgetContainers":[{"zOrder":1,"contents":{"widgets":[{"constraints":[{"startTime":"1970-01-01T00:00:00Z+8:00","endTime":"4012-01-01T23:59:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}],"metadata":{"regular":"$d天$H时$m分$s秒","regularNew":"$d$Ud$H$UH$m$Um$s$Us","solidText":{"textAttributes":{"font":{"size":48,"isUnderline":false,"family":["Arial"],"style":"NORMAL"},"textColor":"#FF0000","backgroundColor":"#00FFFFFF","shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0},"text":""},"textAttributes":{"font":{"size":48,"isUnderline":false,"family":["Arial"],"style":"NORMAL"},"textColor":"#FF0000","backgroundColor":"#00FFFFFF","shadowEnable":false,"ShadowRadius":0,"ShadowDx":0,"shadowDy":0,"shadowColor":"#00ff00","strokeEnable":false,"strokeWidth":0,"letterSpacing":0},"units":[{"zero":"天","name":"$Ud","singular":"天","plural":"天"},{"zero":"时","name":"$UH","singular":"时","plural":"时"},{"zero":"分","name":"$Um","singular":"分","plural":"分"},{"zero":"秒","name":"$Us","singular":"秒","plural":"秒"}],"targetDateTime":1602864000000,"countType":"COUNT_DOWN"},"filesize":1024,"zOrder":1,"dataSource":"","name":"计时器","enable":true,"type":"COUNT_TIMER","duration":10000,"repeatCount":1,"id":100000}],"zOrder":0,"id":0},"PCType":0,"name":"页面1","enable":true,"pickPolicy":"ORDER","id":200000}]}}
* @param programID 必选 int 节目id(创建节目返回的id)
* @param pageID 必选 int pageId(当前版本pageId为1)
* @param pageInfo 必选 Object page的详细信息
* @param name 必选 string 名称
* @param widgetContainers 必选 objectArray 窗口挂件容器
* @param id 必选 int id标识
* @param audioGroup 必选 string 音频组件，详细见音频组件页面，终端1.3.4版本支持，默认为空
* @param backgroundColor 必选 string 颜色值，标准格式四个字节从高到低以此是"ARGB"，如#00ff0000(红色)
* @param backgroundDrawable 必选 string 背景图片资源,默认为空
* @param contents 必选 object 窗口挂件内容
* @param enable 必选 bool 是否有效，但为无效时，此窗口内部的媒体均不会播放
* @param itemsSource 必选 string 媒体列表
* @param layout 必选 object 布局
* @param x 必选 string 起始x(例如0.2568)
* @param y 必选 string 起始y(例如0.2568)
* @param width 必选 string 宽(例如0.5000)
* @param height 必选 string 高(例如0.5000)
* @param name 必选 string widgetContainers的名称
* @param pickCount 必选 int 当pickPolicy的内容包含‘N’时，则有效，大于0才有意义
* @param pickPolicy 必选 string ORDER:按照原始顺序播放;ORDER_N:按orderIDArray顺序播放;ORDER_ONE_ANOTHER_N:按orderIDArray顺序逐个取n个播放，本次已经取过的，下次不再取,n的具体值从pickCount上取;RANDOM_ORDER:随机排序播放。每次在播放的时候，现在场景进行随机排序，排序后;RANDOM_ORDER_N:随机排序，取n个有效场景播放。n的具体值从pickCount上取;RANDOM:真正的随机取，这个要靠运气了;RANDOM_N:真正的随机播放n个。n的具体值从pickCount上取
* @param zOrder 必选 int z序列
* @param widgets 必选 objectArray 窗口挂件
* @param id 必选 int 唯一标识，在整个播放方案需要保持唯一
* @param mid 必选 int 媒体资源的唯一标识
* @param name 必选 string 名称
* @param type 必选 string 类型,PICTURE:表示是图片类型;VIDEO:表示视频类型;AUDIO:表示音频类型;GIF:表示是gif动画类型;HTML:表示是内嵌网页;PLUGIN_H5:表示html5离线组件类;RICH_TEXT:富文本;ARCH_TEXT:综合文本，这种文本所表现的文字特性非常丰富，属性种类繁多，具体格式定义见综合文本章节，沿用了之前的文本风格，带有历史原因，所以我们命名为ARCH_TEXT。但是其功能确实很强大;ANALOG_CLOCK:模拟时钟;DIGITAL_CLOCK:数字时钟;SIMPLE_RSS:简单RSS媒体;SIMPLE_WEATHER:简单天气预报，只包含当前的天气情况，不支持图片形式，文字只能统一修改属性;BORDER:边框，表示媒体类型为边框;STREAM_MEDIA:表示本地实现的流媒体;PICTURE_GROUP:图片组挂件，主要播放一组图片组
* @param metadata 非必选 object 媒体详情，具体见详细媒体说明，流媒体，网页，gif，视频，图片(无特效)时不需要此字段
* @param regular 必选 string 播放规则，1.$T:表示固定文本；2.$d：表示日；3.$H：表示时；4.$m：表示分；5.$s：表示秒；6.$Ud：表示日的单位；7.$UH：表示时的单位；8.$Um：表示分的单位；9.$Us：表示秒的单位；10.\n：表示换行；11.&#160；(此处的分号是英文分号)：表示空格
* @param regularNew 必选 string 规则，1.5.0终端添加计时媒体单位单复数的功能，需要添加新规则
* @param units 必选 object 单位替换数组
* @param name 必选 string 替换名称
* @param singular 必选 string 单数名称
* @param plural 必选 string 复数名称
* @param zero 必选 string 为0时显示的单位
* @param solidText 必选 object 固定文本属性对象
* @param text 非必选 string 固定文本
* @param textAttributes 非必选 object 固定文本显示
* @param backgroundColor 必选 string 背景色，默认00FFFFFF
* @param textColor 必选 string 文字的前景色，默认#FF0000
* @param ---font 必选 object 字体描述
* @param ----family 必选 stringarray 字体类型数组，当有多个字体时，最前面的优先，如果最前面的无效，则依次取后面的字体，如果均无此字库，则使用系统默认的，默认Arial
* @param style 必选 string 类型，1.BOLD：粗体，2.NORMAL：正常类型，3.ITALIC：斜体，4.BOLD_ITALIC：粗体、斜体
* @param size 必选 int 大小，目前只支持像素为单位，默认16
* @param isUnderline 必选 bool 是否有下划线
* @param letterSpacing 非必选 int 字间距，单位像素，默认0
* @param shadowEnable 非必选 bool 阴影是否使能，默认false
* @param shadowRadius 非必选 int 阴影半径大小像素为单位，默认10
* @param shadowDx 非必选 int x轴的偏移
* @param shadowDy 非必选 int y轴的偏移
* @param shadowColor 非必选 string 阴影颜色，默认#00ff00
* @param strokeEnable 非必选 bool 描边是否生效
* @param strokeWidth 非必选 int 描边宽度
* @param strokeColor 非必选 string 描边颜色
* @param targetDateTime 必选 long UTC时间戳(单位是毫秒)
* @param countType 必选 string 计时类型(COUNT_DOWN: 表示倒计时;COUNT_UP：表示正计时;)
* @param textAttributes 必选 object 计时文本属性，参考固定文本textAttributes属性
* @param duration 必选 long 播放时长，单位为毫秒，播放时长，表示媒体播放一次的时间，当为-1表示按照媒体的实际时间，如走马灯在不同大小的显示屏上，播放一次的时间是不一样的
* @param repeatCount 必选 int 播放次数,如果为-1表示无限次
* @param layout 必选 object 布局
* @param x 必选 string 无
* @param y 必选 string 无
* @param width 必选 string 无
* @param height 必选 string 无
* @param displayRatio 必选 string 显示的比例类型，当layout有效时，则layout优先，否则使用此字段,FULL:铺满全屏;ORIGINAL_SIZE:原始比例尺寸，从左上角开始显示，原始媒体多大，则显示多大;ORIGINAL_RATIO:原始比例,比例显示,与16:9,4:3类似;R16_9：16:9;R4_3：4:3;CUSTOM:自定义，当填写这个时，layout必须有效
* @param inAnimation 必选 object 入场动画
* @param type 必选 int 动画类型
* @param duration 必选 long 动画持续时间，单位为毫秒。当type为无特效时，此自动无意义
* @param outAnimation 必选 object 出场动画
* @param dataSource 必选 string 数据源唯一标识，可以是url，也可以是下载的数据文件(md5.png)
* @param originalDataSource 必选 string 数据源，原平台的媒体路径
* @param backgroundMusic 必选 string 背景音乐，一般描述背景音乐的路径或者url
* @param backgroundColor 必选 String 颜色值，标准格式四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param backgroundDrawable 必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
* @param zOrder 必选 int z序列
* @param constraints 必选 objectArray 媒体上的播放条件约束，对于媒体的播放有效性约束，暂时支持到一个时间有效范围即可
* @param startTime 必选 string 开始时间
* @param endTime 必选 string 结束时间
* @param cron 必选 stringArray cron表达式
* @param border 非必选 object 边框
* @param borderThickness 非必选 string 边框宽度单位与layout类似，目前支持像素和百分比
* @param style 非必选 int 样式
* @param backgroundColor 非必选 string 颜色值，标准格式,四个字节从高到低以此是"ARGB",如#00ff0000(红色)
* @param name 非必选 string 名称
* @param cornerRadius 非必选 string 边框的角半径，单位目前支持像素和百分比
* @param effects 非必选 object 特效动画
* @param speed 非必选 float 速度，像素/秒
* @param animation 非必选 string 动画类型(CLOCK_WISE:顺时针旋转,ANTI_CLOCK_WISE:逆时针旋转)
* @param isHeadTail 非必选 boolean 是否开启首尾相接
* @param headTailSpacing 非必选 string 首尾相接字间距，单位像素或者(屏幕百分比%)
* @param speedByPixelEnable 非必选 boolean 如果为true则是像素每秒，false为档位
* @param functionStorage 必选 string 默认为空
* @param isSupportSpecialEffects 必选 string 是否支持播放特效
* @return ""
* @remark
* @number 99
*/

    VIPLEX_EXPORT void nvSetPageProgramAsync(const char *data, ExportViplexCallback  callback);
    /**
* showdoc
* @catalog 接口示例/节目
* @title 编辑多页面节目
* @description 编辑多页面节目，此接口支持节目多页面，事例节目包含两个页面，第一个页面播放模拟时钟，第二个页面播放炫彩字。
* @url void nvSetPageProgramsAsync(const char *data, ExportViplexCallback  callback);
* @json_param {"programID":1,"sceneItems":[{"id":1,"page":{"id":1,"name":"节目06","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z 8:00","startTime":"1970-01-01T00:00:00Z 8:00"}],"duration":5000,"metadata":{"date":{"textAttributes":{"font":{"size":16},"textColor":"#ffffff00"},"weekTemplates":["星期日","星期一","星期二","星期三","星期四","星期五","星期六"]},"hourHand":{"color":"#ffffff00"},"minuteHand":{"color":"#ff00ff00"},"secondHand":{"color":"#ffff0000"},"text":{"text":"","textAttributes":{"font":{"size":12},"textColor":"#ffff0000"}}},"name":"模拟时钟","type":"ANALOG_CLOCK"}]}}]},"rules":"TIMES","repeatCount":1,"name":"scene1","enable":false,"type":"PLAYLIST","backgroundColor":"#00ff0000","backgroundDrawable":"","backgroundMusic":"","constraints":[{"startTime":"1970-01-01T00:00:00Z+08:00","endTime":"4017-12-30T23:59:59Z 8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}]},{"id":2,"page":{"name":"节目01","widgetContainers":[{"contents":{"widgets":[{"constraints":[{"cron":["0 0 0 ? * 1,2,3,4,5,6,7"],"endTime":"4017-12-30T23:59:59Z 8:00","startTime":"1970-01-01T00:00:00Z 8:00"}],"duration":10000,"metadata":{"content":{"content":"请输入文字!","scrollAttributes":{"effects":{"speed":5,"animation":"MARQUEE_LEFT","isHeadTail":false,"headTailSpacing":"10","speedByPixelEnable":false}},"textAttributes":{"effects":{"type":"GRADIENT_HORIZONTAL","colors":["#FF0000","#FF00B050","#FFC00000","#FF007BD4","#FFFFFF00","#FF00FF"],"texture":""},"textColor":"#FF0000","font":{"family":["Arial"],"style":"NORMAL","size":50,"isUnderline":false}}}},"dataSource":"","type":"COLORFUL_TEXT","name":"炫彩字","originalDataSource":"","isSupportSpecialEffects":true}]},"id":1,"name":"widgetContainers1"}]},"rules":"TIMES","repeatCount":1,"name":"scene2","enable":false,"type":"PLAYLIST","backgroundColor":"#00ff0000","backgroundDrawable":"","backgroundMusic":"","constraints":[{"startTime":"1970-01-01T00:00:00Z+08:00","endTime":"4017-12-30T23:59:59Z 8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}]}]}
* @url void nvSetPageProgramsAsync(const char *data, ExportViplexCallback callBack);
* @param programID 必选 int 节目id(创建节目返回的id)
* @param sceneItems 必选 objectArray 场景列表，一个场景包含一个播放页面，多个场景对应多个播放页面
* @param id 必选 int 唯一识别scene
* @param enable 非必选 bool 场景是否有效，true表示播放此场景，false表示不播放，默认为true
* @param type 非必选 string PAGE或PLAYLIST，默认PLAYLIST
* @param rules 非必选 string 播放规则，TIMES：按照次数播放，默认为TIMES
* @param repeatCount 非必选 int 重复次数，当按照次数播放时，才有效，默认为1
* @param backgroundColor 非必选 string 颜色值，标准格式，四个字节从高到低以此是"ARGB"，如#00ff0000(红色)，默认是#00ff0000
* @param backgroundDrawable 非必选 string url,背景图片的路径。可以来自网络或者本地。背景颜色与背景图片不能同时起效，同时存在时，背景图片优先
* @param backgroundMusic 非必选 string 背景音乐路径，url可以来自网络或本地。
* @param constraints 非必选 object 时间约束，有效时间范围。时长播放有效，当为按照次数播放时，无此选项，默认为永久有效
* @param startTime 非必选 string 开始时间，根据需求，可以是只包含时间的，也可以是包含日期和时区的时间，根据需求来决定
* @param cron 非必选 stringArray cron表达式
* @param endTime 非必选 string 结束时间
* @param page 必选 object 页面，具体页面内容参考编辑节目或者编辑复杂节目中详细媒体说明的pageInfo内容进行编辑简单媒体和复杂媒体
* @remark
* @number 99
*/
    VIPLEX_EXPORT void nvSetPageProgramsAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 生成节目
    * @description 生成节目的接口
    * @method
    * @url void nvMakeProgramAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"programID":1,"outPutPath":"test","mediasPath":[{"oldPath":"test","newPath":"test"}],"complexProgram":{"name":"复杂节目","programRegular":[{"priority":1,"programID":1,"constraints":[{"startTime":"1970-01-01T14:17:00Z+8:00","endTime":"4017-12-30T14:17:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]},{"startTime":"1970-01-01T14:19:00Z+8:00","endTime":"4017-12-30T14:19:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}]},{"priority":2,"programID":2,"constraints":[{"startTime":"1970-01-01T14:18:00Z+8:00","endTime":"4017-12-30T14:18:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]},{"startTime":"1970-01-01T14:20:00Z+8:00","endTime":"4017-12-30T14:20:59Z+8:00","cron":["0 0 0 ? * 1,2,3,4,5,6,7"]}]}]}}
    * @param programID 必选 int 节目id,当complexProgram为空时生效，complexProgram不为空时,programID固定值1
    * @param outPutPath 必选 string 生成节目相关协议的路径
    * @param oldPath 必选 string 原文件路径(针对IOS获取不到原文件时使用)
    * @param newPath 必选 string 文件现路径(针对IOS获取不到原文件时，将源文件复制到某路径下)
    * @param complexProgram 非必选 object 当节目涉及到排期生效
    * @param name 必选 object 名称，当complexProgram生效时，不为空，name相同时覆盖原节目
    * @param programRegular 必选 objectArray 排期规则
    * @param priority 必选 int 优先级，当时间冲突时，值较大的优先播放
    * @param programID 必选 int 节目id，需要排期的节目
    * @param constraints 必选 objectArray 时间约束,相同节目可设置多个不同的时间段
    * @param cron 必选 StringArray 每个控制方案使用cron表达式数组表示，当有多个cron表达式时，cron表达式之间使用或的关系
    * @param startTime 必选 string 有效时间的开始日期
    * @param endTime 必选 string 有效时间的结束日期
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65338`创建Json文件时失败
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvMakeProgramAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 配置默认系统模板
    * @description 配置默认系统模板的接口
    * @method
    * @url void nvSetSystemTplInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"data":[{"data":[{"width":1,"height":1,"left":0,"top":0,"zindex":0,"index":0}]},{"data":[{"width":0.5,"height":1,"left":0,"top":0,"zindex":0,"index":0},{"width":0.5,"height":1,"left":0.5,"top":0,"zindex":1,"index":1}]},{"data":[{"width":1,"height":0.5,"left":0,"top":0,"zindex":0,"index":0},{"width":1,"height":0.5,"left":0,"top":0.5,"zindex":1,"index":1}]},{"data":[{"width":0.3333,"height":1,"left":0,"top":0,"zindex":0,"index":0},{"width":0.3333,"height":1,"left":0.3333,"top":0,"zindex":1,"index":1},{"width":0.3333,"height":1,"left":0.6666,"top":0,"zindex":2,"index":2}]},{"data":[{"width":1,"height":0.3333,"left":0,"top":0,"zindex":0,"index":0},{"width":1,"height":0.3333,"left":0,"top":0.3333,"zindex":1,"index":1},{"width":1,"height":0.3333,"left":0,"top":0.6666,"zindex":2,"index":2}]},{"data":[{"width":0.5,"height":0.5,"left":0,"top":0,"zindex":0,"index":0},{"width":0.5,"height":0.5,"left":0.5,"top":0,"zindex":1,"index":1},{"width":0.5,"height":0.5,"left":0,"top":0.5,"zindex":2,"index":2},{"width":0.5,"height":0.5,"left":0.5,"top":0.5,"zindex":3,"index":3}]}]}
    * @param width 必选 int 高度
    * @param height 必选 int 高度
    * @param left 必选 float 左边占比
    * @param top 必选 float 上边占比
    * @param zindex 必选 int Z序
    * @param index 必选 int 小窗口的ID
    * @return "success"
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetSystemTplInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 添加用户自定义模板
    * @description 添加用户自定义模板的接口
    * @method
    * @url void nvAddTplAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"data":[{"data":[{"width":1,"height":1,"left":0,"top":0,"zindex":0,"index":0}]}],"size":{"width":400,"height":400}}
    * @param width 必选 int 宽度
    * @param height 必选 int 高度
    * @param left 必选 float 左边占比
    * @param top 必选 float 上边占比
    * @param zindex 必选 int Z序
    * @param index 必选 int 小窗口的ID
    * @param width 必选 int 模板的宽度
    * @param height 必选 int 模板的高度
    * @return {"tplID":1}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 返回值错误码对应的说明
    * @return_param tplID int 增家的模板ID
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvAddTplAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 编辑用户自定义模板
    * @description 编辑用户自定义模板的接口
    * @method
    * @url void nvEditTplAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"tplID":1,"data":[{"data":[{"width":1,"height":1,"left":0,"top":0,"zindex":0,"index":0}]}],"size":{"width":400,"height":400},"isSystemTpl":true}
    * @param tplID 必选 int 模板id
    * @param width 必选 int 宽度
    * @param height 必选 int 高度
    * @param left 必选 float 左边占比
    * @param top 必选 float 上边占比
    * @param zindex 必选 int Z序
    * @param index 必选 int 小窗口的ID
    * @param width 必选 int 模板的宽度
    * @param height 必选 int 模板的高度
    * @return {"tplID":1}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvEditTplAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 删除用户自定义模板
    * @description 删除用户自定义模板的接口
    * @method
    * @url void nvDeleteTplAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"tplID":[1,2,3]}
    * @param tplID 必选 intArray 模板id
    * @return {"tplID":1}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvDeleteTplAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 获取本地节目
    * @description 获取本地节目的接口
    * @method
    * @url void nvGetProgramAsync(const char *data, ExportViplexCallback  callback)
    * @json_param ""
    * @param data 必选 string data为任意字符串，“”或“任意string”
    * @return {"name":"jiemu1","programID":1,"height":400,"width":400,"page":{"id":1,"name":"page1","widgetContainers":[{"audioGroup":"","backgroundColor":"#00000000","backgroundDrawable":"","contents":{"widgets":[]},"enable":true,"id":1,"itemsSource":"","layout":{"height":"100%","width":"100%","x":"0%","y":"0%"},"name":"widgetContainers1","pickCount":0,"pickPolicy":"ORDER","zOrder":0}],"widgets":[]}]}}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 返回值错误码对应的说明
    * @return_param name string 节目名称
    * @return_param programID int 节目的ID
    * @return_param height int 节目的高
	* @return_param width int 节目的宽
    * @return_param page int 节目page信息
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvGetProgramAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 删除本地节目
    * @description 删除本地节目的接口
    * @method
    * @url void nvDeleteProgramAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"programID":[1,2,3]}
    * @param programID 必选 intArray 节目的ID数组
    * @return "success"
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvDeleteProgramAsync(const char *data, ExportViplexCallback  callback);

    VIPLEX_EXPORT void nvStartTransferProgramAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 取消节目发布
    * @description 取消节目发布的接口
    * @method
    * @url void nvStopProgramTransferAsync(const char *data, ExportViplexCallback  callback)
    * @json_param ""
    * @param data 必选 string data为任意字符串，""或任意string
    * @return "success"
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 返回值错误码对应的说明
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvStopProgramTransferAsync(const char *data, ExportViplexCallback  callback);

    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 获取模板列表
    * @description 获取模板列表的接口
    * @method
    * @url void nvGetCustomerTplAsync(const char *data, ExportViplexCallback  callback)
    * @json_param "string"
    * @param data 必选 string 参数data可以任意string,但是必须有该参数
    * @return {"templates":[{"data":[{"width":1,"height":1,"left":0,"top":0,"zindex":0,"index":0}]}],"size":{"width":400,"height":400},"isSystemTpl":true}
    * @return_param width int 宽度
    * @return_param height int 高度
    * @return_param left float 左边占比
    * @return_param top float 上边占比
    * @return_param index int 小窗口的ID
    * @return_param width int 模板宽度
    * @return_param height int 模板高度
    * @return_param isSystemTpl bool 是否用户自定义模板
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @remark
    * @number 99
    */
	VIPLEX_EXPORT void nvGetCustomerTplAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 获取媒体文件MD5码
    * @description 获取媒体文件MD5码的接口
    * @method
    * @url void nvGetFileMD5Async(const char *data, ExportViplexCallback  callback)
    * @json_param {"filePath":"C:/test/media"}
    * @param filePath 必选 string 媒体所在路径
    * @return {"data":"12d4sa654d564ddauioaj4163"}
    * @return_param code int 错误码：`0`获取成功
    * @return_param data string 成功返回md5码,失败返回错误码对应的说明
    * @remark
    * @number 99
    */
	VIPLEX_EXPORT void nvGetFileMD5Async(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/节目
    * @title 音频媒体
    * @description 音频组件是窗口挂件容器(WidgetContainer)的一个属性，设计的初衷是为了每一个WidgetContainer上都有自己的背景音乐。通俗的理解为音乐组件不是独立的媒体，是每个窗口的共有属性，调用音频媒体需要保持audioFileName与WidgetContainer中audioGroup相对应，保证给指定WidgetContainer添加背景音乐
    * @method
    * @url void nvSetAudioMedioProgramAsync(const char *data,ExportViplexCallback callback);
    * @json_param {"programID":1,"taskInfo":[{"audioFileName":"audioList1.json","data":{"audioList":[{"enable":true,"originalDataSource":"F:/test/test111.mp3"},{"enable":true,"originalDataSource":"F:/test/test222.mp3"}],"playPolicy":"ORDER"}},{"audioFileName":"audioList2.json","data":{"audioList":[{"enable":true,"originalDataSource":"F:/test/test333.mp3"}],"playPolicy":"ORDER"}}]}
    * @param programID 必选 int 节目ID
    * @param taskInfo 必选 object 升级详细信息
    * @param audioFileName 必选 string 生成的json文件名称，对于相同节目，不能重复，WidgetContainer中audioGroup字段须与此出内容相同
    * @param data 必选 objectArray 音频媒体内容
    * @param audioList 必选 object 音频媒体列表，一个widgetContainer可以添加多个音频媒体
    * @param enable 非必选 bool 表征单独音频是否可用,默认为true
    * @param originalDataSource 必选 string 音频媒体路径
    * @param playPolicy 非必选 string 播放顺序,ORDER:顺序播放,RANDOM:随机播放,默认为"ORDER"
    * @return_param code int 错误码:`0`获取成功`65381`请求超时
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvSetAudioMedioProgramAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion EditProgram 节目

#pragma region NodeServerList 节点服务器列表
    /**
 * showdoc
 * @catalog 接口示例/其他/节点服务器列表
 * @title 获取节点服务器列表
 * @description 获取硬盘存储信息
 * @method
 * @url void nvGetNodeServerListAsync(const char *data, ExportViplexCallback  callback);
 * @json_param {"lang":"en"}
 * @param lang 必选 string 语言,英文:en,中文:zh-cn,日文:jp,韩文:kr,西班牙语:es,法语:fr
 * @return {"serverInfo":[{"islocal":true,"label":"aa","node":"www.baidu.com"}]}
 * @return_param islocal bool 是否是用户自定义添加的数据,true:用户自定义,false:服务器获取
 * @return_param label string 节点名称
 * @return_param node string 节点地址
 * @return_param code int 错误码:`0`获取成功`65535`请求超时
 * @remark
 * @number 99
 */
    VIPLEX_EXPORT void nvGetNodeServerListAsync(const char *data, ExportViplexCallback  callback);
    /**
 * showdoc
 * @catalog 接口示例/其他/节点服务器列表
 * @title 添加节点服务器
 * @description 添加对时服务器的接口
 * @method
 * @url void nvAddNodeServerListAsync(const char *data, ExportViplexCallback  callback)
 * @json_param {"label":"aa","node":"www.baidu.com"}
 * @param label 必选 string 节点名称
 * @param node 必选 string 节点地址
 * @return "success"
 * @return_param code int 错误码：`0`获取成功`65535`请求超时
 * @return_param data string 返回值错误码对应的说明
 * @remark
 * @number 99
 */
    VIPLEX_EXPORT void nvAddNodeServerListAsync(const char *data, ExportViplexCallback  callback);
    /**
 * showdoc
 * @catalog 接口示例/其他/节点服务器列表
 * @title 删除节点服务器
 * @description 删除对时服务器列表，如果存在两条node和label都完全一致的数据，则删除第一条
 * @method
 * @url void nvDeleteNodeServerListAsync(const char *data, ExportViplexCallback  callback)
 * @json_param {"label":"aa","node":"www.baidu.com"}
 * @param label 必选 string 节点名称
 * @param node 必选 string 节点地址
 * @return "success"
 * @return_param code int 错误码：`0`获取成功`65535`请求超时
 * @return_param data string 返回值错误码对应的说明
 * @remark
 * @number 99
 */
    VIPLEX_EXPORT void nvDeleteNodeServerListAsync(const char *data, ExportViplexCallback  callback);
    /**
 * showdoc
 * @catalog 接口示例/其他/节点服务器列表
 * @title 修改节点服务器
 * @description 修改对时服务器列表,修改服务器列表,如果存在两条node和label都完全一致的数据,则修改第一条
 * @method
 * @url void nvUpdateNetTimingInfoAsync(const char *data, ExportViplexCallback  callback)
 * @json_param {"oldServer":{"label":"zhangsan","node":"123.123.123"},"newServer":{"label":"lisi","node":"111.111.111"}}
 * @param oldServer 必选 Object 被修改的服务器信息
 * @param label 必选 string 节点名称
 * @param node 必选 string 节点地址
 * @param newServer 必选 Object 修改后的服务器信息
 * @return "success"
 * @return_param code int 错误码：`0`获取成功`65535`请求超时
 * @return_param data string 返回值错误码对应的说明
 * @remark
 * @number 99
 */
    VIPLEX_EXPORT void nvChangeNodeServerListAsync(const char *data, ExportViplexCallback  callback);
    /**
 * showdoc
 * @catalog 接口示例/其他/节点服务器列表
 * @title 添加服务器列表
 * @description 添加服务器列表的接口
 * @method
 * @url void nvAddNetTimingInfoListAsync(const char *data, ExportViplexCallback  callback)
 * @json_param {"serverInfo":[{"label":"aa","node":"www.baidu.com"},{"label":"aa","node":"www.baidu.com"}]}
 * @param serverInfo 必选 array 服务器列表数组
 * @param label 必选 string 节点名称
 * @param node 必选 string 节点地址
 * @return "success"
 * @return_param code int 错误码：`0`获取成功`65535`请求超时
 * @return_param data string 返回值错误码对应的说明
 * @remark
 * @number 99
 */
    VIPLEX_EXPORT void nvAddNodeServerInfoListAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion NodeServerList 


#pragma region feedback
    /**
    * showdoc
    * @catalog 接口示例/其他/意见反馈
    * @title 上传用户反馈信息
    * @description 上传用户反馈信息的接口
    * @method
    * @url void nvUploadFeedbackInfoAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"sn":","contact":"minyf@novastar.tech","description":"我的意见反馈描述双卡双待的","attacheds":[{"dir":"feedback/handy/20200301/abc.jpg"},{"dir":"feedback/handy/20200301/abc.zip"}]}
    * @param sn 必选 string 产品唯一标识号
    * @param contact 非必选 string 联系方式
    * @param description 必选 string 意见反馈描述
    * @param attacheds 非必选 Object 附件
    * @param dir 非必选 string 上传到阿里云的文件dir目录
    * @return {"logid":"225be01205","status":0,"data":"ok"}
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data Object 返回值具体描述
    * @return_param logid string 请求日志id
    * @return_param status int 结果返回状态，0-成功，非0代表失败，具体参考code码含义
    * @return_param errmsg string 错误时会返回错误描述
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvUploadFeedbackInfoAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/其他/意见反馈
    * @title 取消上传意见反馈
    * @description 取消上传意见反馈的接口
    * @method
    * @url void nvUploadFeedBackFileStateAsync(const char *data, ExportViplexCallback  callback)
    * @json_param {"state":true}
    * @param state 非必选 bool true表示继续下载，false表示停止下载，默认为false
    * @return "success"
    * @return_param code int 错误码：`0`获取成功`65535`请求超时
    * @return_param data string 返回值具体描述
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvUploadFeedBackFileStateAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion feedback 用户反馈

#pragma region StatusCollector
    /**
    * @brief获取内存信息
    * @param const char * data
    * {
    *     "sn":"",
    *     "period":XXX
    * }
    * @param ExportViplexCallback  callback只有如下三种情况会进行回调：
    1.参数不正确，无法解析
    2.请求成功
    3.请求失败
    * @returnVIPLEX_EXPORT void
    */
    VIPLEX_EXPORT void nvStartGetAvailableMemoryDataAsync(const char *data, ExportViplexCallback  callback);
    /**
    * @brief结束信息采集
    * @param const char * data
    * {
    *     "sn":"",
    *     "type":""
    * }
    * @param ExportViplexCallback  callback只有如下三种情况会进行回调：
    1.参数不正确，无法解析
    2.请求成功
    3.请求失败
    * @returnVIPLEX_EXPORT void
    */
    VIPLEX_EXPORT void nvFinishDataAsync(const char *data, ExportViplexCallback  callback);


#pragma endregion StatusCollector

#pragma region BindingManager
    /**
 * showdoc
 * @catalog 接口示例/其他/绑定优化
 * @title 是否公有云
 * @description 是否公有云的接口
 * @method
 * @url void nvIsCommonCloudAsync(const char *data, ExportViplexCallback  callback);
 * @json_param {"baseUrl":"https://api-cn.vnnox.com"}
 * @param baseurl 必选 string 播放器绑定地址
 * @return {"status":[10000],"data":{"isCloud":1}}
 * @return_param status intarray 返回服务端状态码:`10000`成功,`10306`url格式错误
 * @return_param code int 错误码:`0`获取成功`65535`请求超时
 * @remark
 * @number 99
 */
	VIPLEX_EXPORT void nvIsCommonCloudAsync(const char *data, ExportViplexCallback  callback);
    /**
 * showdoc
 * @catalog 接口示例/其他/绑定优化
 * @title 获取播放器唯一识别号
 * @description 获取播放器唯一识别号的接口
 * @method
 * @url void nvGetPlayerIdentiferAsync(const char *data, ExportViplexCallback  callback）
 * @json_param {"baseUrl":"https://test-rest-k8s.vnnox.com","data":{"token":"f2972f5a403d5e13d1c6103f91bf78a58055bfd5","number":1}}
 * @param baseurl 必选 string 播放器绑定地址
 * @param token 必选 string 播放机交互TOKEN(播放器与服务器交互)
 * @param number 必选 int 申请的唯一标识的数量（int最大值为1000，超过1000，按照1000进行计算)
 * @return {"status":[10000],"data":{"identifierList":["b518fd5c1ac9e6c68d20ed97c749b490"]}}
 * @return_param status intarray 返回服务端状态码:`10000`成功,`10201`http[header]中token为空`10202`http[header]中token错误
 * @return_param identifierList stringarray 申请的唯一标识号
 * @return_param code int 错误码:`0`获取成功`65535`请求超时
 * @remark
 * @number 99
 */
	VIPLEX_EXPORT void nvGetPlayerIdentiferAsync(const char *data, ExportViplexCallback  callback);
    /**
   * showdoc
   * @catalog 接口示例/其他/绑定优化
   * @title 播放器名称校验
   * @description 播放器名称校验的接口
   * @method
   * @url void nvIsExistPlayerNameAsync(const char *data, ExportViplexCallback  callback)
   * @json_param {"baseUrl":"https://test-rest-k8s.vnnox.com","data":{"token":"f2972f5a403d5e13d1c6103f91bf78a58055bfd5","playerName":"dangjintao"}}
   * @param baseurl 必选 string 播放器绑定地址
   * @param token 必选 string 播放机交互TOKEN(播放器与服务器交互)
   * @param playerName 必选 string 播放器名称
   * @return {"status":[10000],"data":{"playerName":"dangjintao"}}
   * @return_param status intarray 返回服务端状态码:`10000`成功,`10201`http[header]中token为空`10202`http[header]中token错误`10209`播放器名称格式错误`10210`播放器名称已存在
   * @return_param playerName  string 播放器名称
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
	VIPLEX_EXPORT void nvIsExistPlayerNameAsync(const char *data, ExportViplexCallback  callback);
    /**
    * showdoc
    * @catalog 接口示例/其他/绑定优化
    * @title 获取token值
    * @description 播放器名称校验的接口
    * @method
    * @url void nvGetTokenAsync(const char *data, ExportViplexCallback  callback);
    * @json_param {"baseUrl":"https://test-rest-k8s.vnnox.com","data":{"username":"gmt","password":"123456"}}
    * @param baseurl 必选 string 播放器绑定地址
    * @param username 必选 string 播放器用户名
    * @param password 必选 string 播放器密码
    * @return {"status":[10000],"data":{"token":"654ad5s64f65w46f5e456wa4f","timeout":3600}}
    * @return_param status intarray 返回服务端状态码:`10000`成功,`10001`用户名或密码错误
    * @return_param token string 播放机交互TOKEN（播放器与服务器交互，要将此TOKEN加入http协议header中）
    * @return_param timeout int token的超时时间(单位s)
    * @return_param code int 错误码:`0`获取成功`65535`请求超时
    * @remark
    * @number 99
    */
	VIPLEX_EXPORT void nvGetTokenAsync(const char *data, ExportViplexCallback  callback);
#pragma endregion 
    /**
   * showdoc
   * @catalog 接口示例/其他/获取时区列表
   * @title 获取时区列表
   * @description 获取时区列表的接口。<br/>返回的时间为夏令时时间（无夏令时时间的国家返回标准时间）。
   * @method
   * @url void nvGetTimeZoneAsync(const char *data, ExportViplexCallback  callback);
   * @json_param {"data":"anystring"}
   * @param data 必选 string 参数data必须有,但是可以为任意string
   * @return {"Pacific/Midway":"中途岛 (UTC-11:00)","Pacific/Honolulu":"檀香山 (UTC-10:00)","America/Anchorage":"安克雷奇 (UTC-08:00)","America/Los_Angeles":"洛杉矶/美国太平洋 (UTC-07:00)","America/Tijuana":"提华纳/美国太平洋 (UTC-07:00)","America/Phoenix":"凤凰城美国山区 (UTC-07:00)","America/Chihuahua":"奇瓦瓦 (UTC-06:00)","America/Denver":"丹佛/美国山区 (UTC-06:00)","America/Costa_Rica":"哥斯达黎加/美国中部 (UTC-06:00)","America/Regina":"里贾纳/美国中部 (UTC-06:00)","America/Mexico_City":"墨西哥城/美国中部 (UTC-05:00)","America/Chicago":"芝加哥/美国中部 (UTC-05:00)","America/Bogota":"波哥大/哥伦比亚 (UTC-05:00)","America/New_York":"纽约/美国东部 (UTC-04:00)","America/Caracas":"加拉加斯/委内瑞拉 (UTC-04:30)","America/Barbados":"巴巴多斯/大西洋 (UTC-04:00)","America/Manaus":"马瑙斯/亚马逊 (UTC-04:00)","America/Santiago":"圣地亚哥 (UTC-03:00)","America/Sao_Paulo":"圣保罗 (UTC-03:00)","America/St_Johns":"圣约翰/纽芬兰 (UTC-04:00)","America/Argentina/Buenos_Aires":"布宜诺斯艾利斯 (UTC-03:00)","America/Montevideo":"蒙得维的亚/乌拉圭 (UTC-03:00)","America/Godthab":"戈特霍布 (UTC-02:00)","Atlantic/South_Georgia":"南乔治亚 (UTC-02:00)","Atlantic/Cape_Verde":"佛得角 (UTC-01:00)","Atlantic/Azores":"亚述尔群岛 (UTC+00:00)","Africa/Casablanca":"卡萨布兰卡 (UTC+00:00)","Europe/London":"伦敦/格林尼治 (UTC+00:00)","Africa/Brazzaville":"布拉扎维/西部非洲 (UTC+01:00)","Africa/Windhoek":"温得和克 (UTC+01:00)","Europe/Amsterdam":"阿姆斯特丹/中欧 (UTC+02:00)","Europe/Belgrade":"贝尔格莱德/中欧 (UTC+02:00)","Europe/Brussels":"布鲁塞尔/中欧 (UTC+02:00)","Europe/Sarajevo":"萨拉热窝/中欧 (UTC+02:00)","Africa/Harare":"哈拉雷/中部非洲 (UTC+02:00)","Africa/Cairo":"开罗/东欧 (UTC+02:00)","Asia/Beirut":"贝鲁特/东欧 (UTC+03:00)","Europe/Athens":"雅典/东欧 (UTC+03:00)","Europe/Helsinki":"赫尔辛基/东欧 (UTC+03:00)","Asia/Jerusalem":"耶路撒冷/以色列 (UTC+03:00)","Asia/Amman":"安曼/东欧 (UTC+03:00)","Europe/Minsk":"明斯克 (UTC+03:00)","Asia/Baghdad":"巴格达 (UTC+03:00)","Europe/Moscow":"莫斯科 (UTC+03:00)","Asia/Kuwait":"科威特 (UTC+03:00)","Africa/Nairobi":"内罗毕/东部非洲 (UTC+03:00)","Asia/Baku":"巴库 (UTC+05:00)","Asia/Tbilisi":"第比利斯 (UTC+04:00)","Asia/Yerevan":"埃里温 (UTC+04:00)","Asia/Dubai":"迪拜 (UTC+04:00)","Asia/Tehran":"德黑兰/伊朗 (UTC+04:30)","Asia/Kabul":"喀布尔/阿富汗 (UTC+04:30)","Asia/Karachi":"卡拉奇 (UTC+05:00)","Asia/Oral":"乌拉尔 (UTC+05:00)","Asia/Yekaterinburg":"叶卡捷林堡 (UTC+05:00)","Asia/Calcutta":"加尔各答 (UTC+05:30)","Asia/Colombo":"科伦坡 (UTC+05:30)","Asia/Katmandu":"加德满都/尼泊尔 (UTC+05:45)","Asia/Almaty":"阿拉木图 (UTC+06:00)","Asia/Rangoon":"仰光/缅甸 (UTC+06:30)","Asia/Krasnoyarsk":"克拉斯诺亚尔斯克 (UTC+07:00)","Asia/Bangkok":"曼谷 (UTC+07:00)","Asia/Shanghai":"北京/中国 (UTC+08:00)","Asia/Hong_Kong":"香港/中国 (UTC+08:00)","Asia/Irkutsk":"伊尔库茨克 (UTC+08:00)","Asia/Kuala_Lumpur":"吉隆坡 (UTC+08:00)","Australia/Perth":"佩思 (UTC+08:00)","Asia/Taipei":"台北时间 (UTC+08:00)","Asia/Seoul":"首尔 (UTC+09:00)","Asia/Tokyo":"东京/日本 (UTC+09:00)","Asia/Yakutsk":"雅库茨克 (UTC+09:00)","Australia/Adelaide":"阿德莱德 (UTC+09:30)","Australia/Darwin":"达尔文 (UTC+09:30)","Australia/Brisbane":"布里斯班 (UTC+10:00)","Australia/Hobart":"霍巴特 (UTC+10:00)","Australia/Sydney":"悉尼 (UTC+10:00)","Asia/Vladivostok":"符拉迪沃斯托克/海参崴 (UTC+10:00)","Pacific/Guam":"关岛 (UTC+10:00)","Asia/Magadan":"马加丹 (UTC+10:00)","Pacific/Majuro":"马朱罗 (UTC+12:00)","Pacific/Auckland":"奥克兰 (UTC+12:00)","Pacific/Fiji":"斐济 (UTC+12:00)","Pacific/Tongatapu":"东加塔布 (UTC+13:00)"}
   * @return_param code int 错误码:`0`获取成功`65535`请求超时
   * @remark
   * @number 99
   */
    VIPLEX_EXPORT void nvGetTimeZoneAsync(const char *data, ExportViplexCallback  callback);

#pragma endregion 其他  待补充
    /**
    * showdoc
    * @catalog 接口示例/终端日志
    * @title 获取终端日志
    * @description 获取终端日志，包含运行日志，播放日志
    * @method
    * @url void nvDownloadTerminalPlayLog(const char *data, ExportViplexCallback  callback);
    * @json_param {"sn":"BZSA79353N1310006847","fileName":"test_upload","filePath":"E:/test"}
    * @param sn 必选 string 产品唯一标识号
    * @param fileName 必选 string 日志保存文件名字
    * @param filePath 必选 string 日志保存路径
    * @return "download termianl log finished"
    * @return_param code int 错误码:`0`获取成功`65535`请求超时`65381`下载完成
    * @remark
    * @number 99
    */
	VIPLEX_EXPORT void nvDownloadTerminalLogAsync(const char *data, ExportViplexCallback  callback);

	VIPLEX_EXPORT void nvUploadTerminalLogAsync(const char *data, ExportViplexCallback  callback);

	VIPLEX_EXPORT void nvCheckNetworkAsync(const char *data, ExportViplexCallback  callback);

    VIPLEX_EXPORT void nvDownloadTerminalAllLogAsync(const char *data, ExportViplexCallback callback);

	VIPLEX_EXPORT void nvDownloadTerminalLogNetAsync(const char* data, ExportViplexCallback callback);

	VIPLEX_EXPORT void nvDownloadTerminalPlayLogNetAsync(const char* data, ExportViplexCallback callback);
        /**
    * showdoc
    * @catalog 接口示例/终端日志
    * @title 获取终端播放日志
    * @description 获取播放日志，调用接口会多次回调，返回下载进度，如{"m_curBytes":11896905,"m_totalBytes":19896905,"status":1}
    * @method
    * @url void nvDownloadTerminalPlayLogAsync(const char *data,ExportViplexCallback callback);
    * @json_param {"sn":"BZSA79353N1310006847","fileName":"test_upload","filePath":"E:/test"}
    * @param sn 必选 string 产品唯一标识号
    * @param fileName 必选 string 日志保存文件名字
    * @param filePath 必选 string 日志保存路径
    * @return "E:/test/test_upload/play_log"
    * @return_param code int 错误码:`0`获取成功`65535`请求超时`65381`下载完成
    * @remark
    * @number 99
    */
    VIPLEX_EXPORT void nvDownloadTerminalPlayLogAsync(const char *data,ExportViplexCallback callback);

	VIPLEX_EXPORT void nvCancelFunctionAsync(const char *data, ExportViplexCallback  callback);

	VIPLEX_EXPORT void nvGetScreenDeviceInfoAsync(const char *data, ExportViplexCallback  callback);

#pragma region VNNOX注册登录
	VIPLEX_EXPORT void nvLoginVnnox(const char *data, ExportViplexCallback  callback);
	VIPLEX_EXPORT void nvGetVerifyCode(const char *data, ExportViplexCallback  callback);
	VIPLEX_EXPORT void nvRegisterVnnox(const char *data, ExportViplexCallback  callback);
#pragma endregion	

	VIPLEX_EXPORT void nvSetEnvironmentBrightnessParameterAsync(const char* data, ExportViplexCallback  callback);
	VIPLEX_EXPORT void nvGetEnvironmentBrightnessParameterAsync(const char* data, ExportViplexCallback  callback);
	VIPLEX_EXPORT void nvGetManualBrightnessFor0x99Async(const char* data, ExportViplexCallback  callback);
	VIPLEX_EXPORT void nvRebootAsync(const char* data, ExportViplexCallback  callback);
	VIPLEX_EXPORT void nvStartUploadApkAsync(const char* data, ExportViplexCallback callback);
	VIPLEX_EXPORT void nvGetWifiCurrentStatusAsync(const char* data, ExportViplexCallback callback);
	VIPLEX_EXPORT void nvSetScreenShotAsync(const char* data, ExportViplexCallback callback);
	VIPLEX_EXPORT void nvNewSetBindPlayerAsync(const char* data, ExportViplexCallback callback);
	VIPLEX_EXPORT void nvRsaEncodeAsync(const char* data, ExportViplexCallback callback);
	VIPLEX_EXPORT void nvRsaDecodeAsync(const char* data, ExportViplexCallback callback);
#ifdef __cplusplus
}
#endif




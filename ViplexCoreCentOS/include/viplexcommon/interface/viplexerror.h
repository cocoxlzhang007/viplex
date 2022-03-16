#pragma once
#include <stdint.h>
#include <map>
#include <string>
#include "../viplexcommon_global.h"
enum ViplexError : uint16_t
{
	OK = 0x00,//	成功
	ERR_COMMON = 0x01,//	通用错误
	ERR_NULL = 0x02,//	参数为空
	ERR_INVALID_PARAM = 0x03,//	无效参数
	ERR_TIMEOUT = 0x04,//	超时
	ERR_IO_EXCEPTION = 0x05,//	IO异常
	ERR_INTERRUPTED = 0x06,//	中断异常
	ERR_INCOMPLETED = 0x07,//	未完成
	ERR_INCOMPLETED_SET = 0x08,//	未完成的设置异常
	ERR_ALREADY_DONE = 0x09,//	已经执行异常
	ERR_SECURITY = 0x0A,//	安全问题
	ERR_PERMISSION_DENIED = 0x0B,//		权限不够（授权失败）
	ERR_NOT_IMPLEMENTED = 0x0C,//	未实现的功能
	ERR_REMOTE_EXCEPTION = 0x0D,//	远程过程调用异常，一般用于进程间通信异常
	ERR_UNSUPPORTEDENCODING = 0x0F,//	不支持的编码异常
	ERR_JSON_EXCEPTION = 0x10,//	Json异常
	ERR_FORBIDDEN = 0x11,//	禁止访问
	ERR_NO_SESSION = 0x12,//	无会话连接异常
	ERR_NOT_EXISTED = 0x13,//	不存在的异常
	ERR_NO_SPACE = 0x14,//	没有空间的异常
	ERR_DATABASE_EXCEPTION = 0x15,//	数据库异常
	ERR_TOO_FREQUENTLY = 0x16,//	操作过于频繁
	ERR_ALREADY_EXISTED = 0x17,//	已经存在
	ERR_VERIFY_FAILED = 0x18,//	校验失败（例如文件MD5不一致, 系统升级包校验失败）
	ERR_FILE_ILLEGAL = 0x19,//	升级包不合法或错误
	ERR_SIGNATURE_NO_MATCH = 0x20,//	签名不匹配（升级包）
	ERR_ACCOUNT_NOT_EXIST = 0x21,//	账号不存在
	ERR_SCREEN_NOT_CONFIG = 0x22,//	未配屏
	ERR_NETWORK = 0x23,//	网络异常
	ERR_UNSUPPORTED = 0x24,//	终端不支持
	ERR_LORA_SLAVE_UNSUPPORTED = 0x25,//	射频从设备不支持(例如给从设备设置音量，亮度，时间，时区时返回该错误码)
	ERR_NOT_ONE_FPGA = 0x33,//	升级时，通过产品和平台验证的FPGA的个数不是一个
	ERR_NOT_SUPPORT_PRODUCT = 0x34,//	升级校验时，终端产品不支持
	ERR_VERSION_LOW = 0x35,//	待升级软件版本低于当前终端已安装版本
	ERR_NOT_SUPPORT_PLATFORM = 0x36,//	升级校验时，终端平台不支持

	ERR_LOGIN_LOCKED = 0x43,//登录时，密码已经连续错误3次

	NAME_ALREADY_EXIST = 0xFF04,//ntp对时服务器或者绑定服务器重命名
	CALLBACK_IS_NULL = 0xFF05,
	LOG_INIT_ERR = 0xFF06,
	DB_INIT_ERR = 0xFF07,
	VALUE_RANGE_ERROR = 0xFF08,//值越界

	ConnectionSuccess = 0xFF11,          // TCP 连接成功
	AlreadyConnection = 0xFF12,          // TCP 已经建立了连接
	ConnectionRefusedError = 0xFF13,
	RemoteHostClosedError = 0xFF14,
	HostNotFoundError = 0xFF15,
    ERR_UDP_ADDRINUSE = 0xFF16,      //UDP监听端口被占用
    ERR_UDP_BINDFAIL = 0xFF17,      //UDP监听失败，其他原因
	SocketTimeoutError = 0xFF18,
	NetworkError = 0xFF1a,
	SocketAddressNotAvailableError = 0xFF1c,
	UnknownSocketError = 0xFF1d,
	setBindPlayerError = 0xFF1e,
	UdpSerchGateWayIsNullError = 0xFF1f,      //网关地址为空

	LOGIN_SN_IS_ILLEGAL = 0xFF20,
	SN_IS_ILLEGAL = 0xFF21,

	ERR_PATH_NOT_EXIST = 0xFF22,
	ERR_FILE_NUZIP_FAILED = 0xFF23,
	ERR_DESCRIPTION_JSON_NULL = 0xFF24,
	PARAM_IS_EXCEPTION = 0xFF25,
	NO_MATCH_FILE = 0xFF27,                  //没有匹配的文件
	UPDATE_PACKAGE_UPLOADING = 0xFF28,      //升级包上传中
	START_UPDATE = 0xFF29,                  //升级包上传完毕
	DIR_NOT_EXIST = 0xFF30,                    //路径不存在
	CREATE_JSONFILE_FAILED = 0xFF3a,           //创建JSON文件失败
	UPLOAD_FILE = 0xFF3b,                      //正在上传文件

	CREATEPROGRAM_ERROR = 0xFF3c,              //创建节目错误
	GETPROGRAM_ERROR = 0xFF3d,                 //获取节目错误
	PROGRAMTEMPLATE_DATABASE_EMPTY = 0xFF3e,   //数据库读取节目模板，内容为空
	ERR_CHANGEPWD_OLDPWDERR = 0xFF3f,         //旧密码错误
	ERR_UPDATEPACKAGE_TRANSPORT = 0xFF40,     //安装包发送失败
	TEMPLATEID_IS_ERROR = 0xFF41,
	DisConnectSuccess = 0xFF42,
	ERR_INSERTERROR = 0xFF43,                 //插入数据库失败
	ERR_DELETEERROR = 0xFF44,                 //删除数据库失败
	ERR_TCP_UNCONNECTED = 0Xff45,             //tcp socket未连接

	ERR_NOT_LOGIN = 0Xff46,                   //未登录
	ERR_PWDERROR_CLEARPASSWORD = 0Xff47,      //终端返回用户名和密码错误，但是登录入参是记住密码的，因此帮助handy清除密码，使用特殊的code标识
	OLD_DATABASE_ISEMPTY = 0Xff48,
	ERR_ALREADY_LOGIN = 0Xff49,               //已经登录了，你在进行二次登陆
	ERR_LOGIN_FAIL = 0Xff50,                  //自用,代表登录失败，导出层判断登录是否成功
	ERR_UNGETFIRMWARE_VERSIONISNULL = 0Xff51,          //未先调用获取固件版本信息接口，导致版本号是空，因此无法做旧卡的兼容配置
	MEDIA_UPLOADING = 0Xff52,                     //媒体正在上传标志
	ERR_FTP_SEND_ERROR = 0XFF53,                //ftp发送失败，网络断开
	ERR_VERISON_ROLLBACK = 0xFF54,              //升级版本回退错误
	ERR_NOT_SUPPORT_VERIFY = 0xFF55,            //不支持版本升级验证
    ERR_FEEDBACK_FAILED = 0xff56,                       //意见反馈上传文件失败
    NO_AVAILABLE_SPACE = 0xff57,                        //Tcard存储空间不足
    USB_NO_AVAILABLE_SPACE = 0xff58,                    //U盘空间不足
    UPDATE_PACKAGE_DOWNLOADING= 0xFF59,                 //升级包下载中
    ERR_GET_ONLINE_PACKAGE_FAILED = 0xFF5A,             //获取线上升级包失败
    ERR_STOP_DOWNLOAD_UPDATE_PACKAGE = 0xFF5B,          //终止升级包下载
    ERR_DOWNLOAD_UPDATE_PACKAGE_FAILED = 0xFF5C,        //升级包下载失败
    ERR_LOCAL_FILE = 0xFF5D,                            //本地文件打开失败
    ERR_CURL_INIT = 0xFF5E,                             //curl初始化失败
    ERR_FILE_VERIFY_IFAILED = 0xFF5F,                   //升级包校验失败
    ERR_NETWORKCONNECT = 0xFF60,                        //网络检测异常
	ERR_USERNAME_EMPTY = 0xFF61,                        //绑定时用户名为空
	ERR_PASSWORD_EMPTY = 0xFF62,                        //绑定时密码为空
	ERR_RESPONSEDATA_ERROR,                             //终端返回参数异常
	ERR_CANCEL_PROGRESS,                                //取消压缩过程
	ERR_TERMINALLOG_DOWNLOAD_FINISH,                    //终端日志下载压缩完成
	ERR_GET_TOKEN_ERROR,								//http请求token值错误
	ERR_GET_OSSINFO_ERROR,								//http请求oss认证信息值错误
	ERR_CANCEL_TERMINALLOG_UPLOAD,						//取消日志上传
	ERR_GET_OSSLINK_ERROR,								//http请求下载日志链接错误
	ERR_GET_OSSLINK_SUCCESS,							//http请求下载日志链接成功
	ERR_TERMINAL_UPLOAD_FINISH,							//终端日志上传完成
	ERR_CREATE_DIR_ERROR,								//创建文件夹失败


    ERR_CURLE_UNSUPPORTED_PROTOCOL = 0X07E5, /* 1    --->1+2020 */
    ERR_CURLE_FAILED_INIT, /* 2 */
    ERR_CURLE_URL_MALFORMAT, /* 3 */
    ERR_CURLE_OBSOLETE4, /* 4 - NOT USED */
    ERR_CURLE_COULDNT_RESOLVE_PROXY, /* 5 */
    ERR_CURLE_COULDNT_RESOLVE_HOST, /* 6 */
    ERR_CURLE_COULDNT_CONNECT, /* 7 */
    ERR_CURLE_FTP_WEIRD_SERVER_REPLY, /* 8 */
    ERR_CURLE_REMOTE_ACCESS_DENIED, /* 9 a service was denied by the server
                                        due to lack of access - when login fails
                                        this is not returned. */
    ERR_CURLE_OBSOLETE10, /* 10 - NOT USED */
    ERR_CURLE_FTP_WEIRD_PASS_REPLY, /* 11 */
    ERR_CURLE_OBSOLETE12, /* 12 - NOT USED */
    ERR_CURLE_FTP_WEIRD_PASV_REPLY, /* 13 */
    ERR_CURLE_FTP_WEIRD_227_FORMAT, /* 14 */
ERR_CURLE_FTP_CANT_GET_HOST, /* 15 */
ERR_CURLE_OBSOLETE16, /* 16 - NOT USED */
ERR_CURLE_FTP_COULDNT_SET_TYPE, /* 17 */
ERR_CURLE_PARTIAL_FILE, /* 18 */
ERR_CURLE_FTP_COULDNT_RETR_FILE, /* 19 */
ERR_CURLE_OBSOLETE20, /* 20 - NOT USED */
ERR_CURLE_QUOTE_ERROR, /* 21 - quote command failure */
ERR_CURLE_HTTP_RETURNED_ERROR, /* 22 */
ERR_CURLE_WRITE_ERROR, /* 23 */
ERR_CURLE_OBSOLETE24, /* 24 - NOT USED */
ERR_CURLE_UPLOAD_FAILED, /* 25 - failed upload "command" */
ERR_CURLE_READ_ERROR, /* 26 - couldn't open/read from file */
ERR_CURLE_OUT_OF_MEMORY, /* 27 */
/* Note: ERR_CURLE_OUT_OF_MEMORY may sometimes indicate a conversion error
           instead of a memory allocation error if CURL_DOES_CONVERSIONS
           is defined
  */
    ERR_CURLE_OPERATION_TIMEDOUT, /* 28 - the timeout time was reached */
    ERR_CURLE_OBSOLETE29, /* 29 - NOT USED */
    ERR_CURLE_FTP_PORT_FAILED, /* 30 - FTP PORT operation failed */
    ERR_CURLE_FTP_COULDNT_USE_REST, /* 31 - the REST command failed */
    ERR_CURLE_OBSOLETE32, /* 32 - NOT USED */
    ERR_CURLE_RANGE_ERROR, /* 33 - RANGE "command" didn't work */
    ERR_CURLE_HTTP_POST_ERROR, /* 34 */
    ERR_CURLE_SSL_CONNECT_ERROR, /* 35 - wrong when connecting with SSL */
    ERR_CURLE_BAD_DOWNLOAD_RESUME, /* 36 - couldn't resume download */
    ERR_CURLE_FILE_COULDNT_READ_FILE, /* 37 */
    ERR_CURLE_LDAP_CANNOT_BIND, /* 38 */
    ERR_CURLE_LDAP_SEARCH_FAILED, /* 39 */
    ERR_CURLE_OBSOLETE40, /* 40 - NOT USED */
    ERR_CURLE_FUNCTION_NOT_FOUND, /* 41 */
    ERR_CURLE_ABORTED_BY_CALLBACK, /* 42 */
    ERR_CURLE_BAD_FUNCTION_ARGUMENT, /* 43 */
    ERR_CURLE_OBSOLETE44, /* 44 - NOT USED */
    ERR_CURLE_INTERFACE_FAILED, /* 45 - CURLOPT_INTERFACE failed */
    ERR_CURLE_OBSOLETE46, /* 46 - NOT USED */
    ERR_CURLE_TOO_MANY_REDIRECTS, /* 47 - catch endless re-direct loops */
    ERR_CURLE_UNKNOWN_TELNET_OPTION, /* 48 - User specified an unknown option */
    ERR_CURLE_TELNET_OPTION_SYNTAX, /* 49 - Malformed telnet option */
    ERR_CURLE_OBSOLETE50, /* 50 - NOT USED */
    ERR_CURLE_PEER_FAILED_VERIFICATION, /* 51 - peer's certificate or fingerprint
                                         wasn't verified fine */
    ERR_CURLE_GOT_NOTHING, /* 52 - when this is a specific error */
    ERR_CURLE_SSL_ENGINE_NOTFOUND, /* 53 - SSL crypto engine not found */
    ERR_CURLE_SSL_ENGINE_SETFAILED, /* 54 - can not set SSL crypto engine as
                                        default */
    ERR_CURLE_SEND_ERROR, /* 55 - failed sending network data */
    ERR_CURLE_RECV_ERROR, /* 56 - failure in receiving network data */
    ERR_CURLE_OBSOLETE57, /* 57 - NOT IN USE */
    ERR_CURLE_SSL_CERTPROBLEM, /* 58 - problem with the local certificate */
    ERR_CURLE_SSL_CIPHER, /* 59 - couldn't use specified cipher */
    ERR_CURLE_SSL_CACERT, /* 60 - problem with the CA cert (path?) */
    ERR_CURLE_BAD_CONTENT_ENCODING, /* 61 - Unrecognized transfer encoding */
    ERR_CURLE_LDAP_INVALID_URL, /* 62 - Invalid LDAP URL */
    ERR_CURLE_FILESIZE_EXCEEDED, /* 63 - Maximum file size exceeded */
    ERR_CURLE_USE_SSL_FAILED, /* 64 - Requested FTP SSL level failed */
    ERR_CURLE_SEND_FAIL_REWIND, /* 65 - Sending the data requires a rewind
                                        that failed */
    ERR_CURLE_SSL_ENGINE_INITFAILED, /* 66 - failed to initialise ENGINE */
    ERR_CURLE_LOGIN_DENIED, /* 67 - user, password or similar was not
                                        accepted and we failed to login */
    ERR_CURLE_TFTP_NOTFOUND, /* 68 - file not found on server */
    ERR_CURLE_TFTP_PERM, /* 69 - permission problem on server */
    ERR_CURLE_REMOTE_DISK_FULL, /* 70 - out of disk space on server */
    ERR_CURLE_TFTP_ILLEGAL, /* 71 - Illegal TFTP operation */
    ERR_CURLE_TFTP_UNKNOWNID, /* 72 - Unknown transfer ID */
    ERR_CURLE_REMOTE_FILE_EXISTS, /* 73 - File already exists */
    ERR_CURLE_TFTP_NOSUCHUSER, /* 74 - No such user */
    ERR_CURLE_CONV_FAILED, /* 75 - conversion failed */
    ERR_CURLE_CONV_REQD, /* 76 - caller must register conversion
                                        callbacks using curl_easy_setopt options
                                        CURLOPT_CONV_FROM_NETWORK_FUNCTION,
                                        CURLOPT_CONV_TO_NETWORK_FUNCTION, and
                                        CURLOPT_CONV_FROM_UTF8_FUNCTION */
    ERR_CURLE_SSL_CACERT_BADFILE, /* 77 - could not load CACERT file, missing
                                        or wrong format */
    ERR_CURLE_REMOTE_FILE_NOT_FOUND, /* 78 - remote file not found */
    ERR_CURLE_SSH, /* 79 - error from the SSH layer, somewhat
                                        generic so the error message will be of
                                        interest when this has happened */

    ERR_CURLE_SSL_SHUTDOWN_FAILED, /* 80 - Failed to shut down the SSL
                                        connection */
    ERR_CURLE_AGAIN, /* 81 - socket is not ready for send/recv,
                                        wait till it's ready and try again (Added
                                        in 7.18.2) */
    ERR_CURLE_SSL_CRL_BADFILE, /* 82 - could not load CRL file, missing or
                                        wrong format (Added in 7.19.0) */
    ERR_CURLE_SSL_ISSUER_ERROR, /* 83 - Issuer check failed.  (Added in
                                        7.19.0) */
    ERR_CURL_LAST, /* never use! */

    FTP_LOCAL_FILE_NOT_EXIST,

    ERR_FEEDBACK_STOP, //取消上传意见反馈

    ERR_FEEDBACK_TIMEOUT,//意见反馈http请求超时

    ERR_PARAMETER_ABNORMAL = 0x01F4,//Handy上云退出参数异常

    DOWNCOMPLETE,
	CALLBACK_TIMEOUT = 0xFFFF

};

VIPLEXCOMMON_EXPORT const std::string& descriptionWithError(const ViplexError viplexError);

#pragma once
#include "jsoncommon.h"

using namespace std;
using nlohmann::json;

namespace ns
{
    struct TimeZoneInfo
    {
        int64_t utcTimeMillis;
        string timeZone;
        string gmt;
        string isTimeOffsetEnable;
        string beginTime;
        string endTime;
        int64_t timeOffsetValue;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimeZoneInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimeZoneInfo &data);
    struct TimeAndZone
    {
        string sn;
        string currentTime;
        TimeZoneInfo timeZoneInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimeAndZone &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimeAndZone &data);
}
//网络校时
namespace ns
{
    struct Compatibility
    {
        bool supportLoraInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Compatibility &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Compatibility &data);
    struct TimingInfo
    {
        bool enable = false;
        string type = "NET_TIMING";//固定值NET_TIMING
        Source source;
        Ntp ntp;
        Lora lora;
        Gps gps;
        Compatibility compatibility;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingInfo &data);
    struct VerifyNetTimeInfo
    {
        string sn;
        TimingInfo timingInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VerifyNetTimeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VerifyNetTimeInfo &data);

    struct ServerInfo
    {
        string label;
        string node;
        bool islocal = true;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ServerInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ServerInfo &data);

    struct serverAddressInfo
    {
        ns::ServerInfo oldServer;
        ns::ServerInfo newServer;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const serverAddressInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, serverAddressInfo &data);

    struct serverAddress
    {
        vector<serverAddressInfo> serverInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const serverAddress &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, serverAddress &data);

    struct ServerAddressContent
    {
        vector<ServerInfo> serverInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ServerAddressContent &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ServerAddressContent &data);
    //     struct Ntp 
    //     {
    //         bool enable;
    //         string server;
    //     };
    //     struct Lora 
    //     {
    //         int address;
    //         int channel;
    //         bool enable;
    //         string mode;
    //         string groupId;
    //     };
    struct Regulation
    {
        bool timeEnable;
        bool brightnessEnable;
        bool volumeEnable;
        bool environmentalMonitoring;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Regulation &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Regulation &data);
    struct LoraData
    {
        int address;
        int channel;
        bool enable;
        string groupId;
        string mode;
        Regulation regulation;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LoraData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LoraData &data);
    struct TaskArrays
    {
        string type;
        int action;
        NtpData ntpData;
        LoraData loraData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TaskArrays &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TaskArrays &data);
    struct TimingVertify
    {
        Source source;
        vector<TaskArrays> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVertify &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVertify &data);
    struct  TimingVertifyInfo
    {
        string sn;
        TimingVertify timingInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVertifyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVertifyInfo &data);

    struct GetTaskArray
    {
        string type;
        int action;
        int status = -1;
        int errorcode = -1;
        NtpData ntpData;
        LoraData loraData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTaskArray &data);
    struct GetTimingVertify
    {
        Source source;
        vector<GetTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingVertify &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingVertify &data);
}

namespace ns
{
    //高级功能-恢复出厂设置中setinfo
    struct SetInfo
    {
        string reason;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetInfo &info);

    //高级功能-adb状态设置modeInfo
    struct ModeInfo
    {
        double value;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ModeInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ModeInfo &info);

    //高级功能-获取当前分辨率&&分辨率列表RequestInfo
    struct RequestInfo
    {
        int displayMode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RequestInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RequestInfo &info);

    //高级功能-设置当前分辨率
    struct ResolutionInfo
    {
        int displayMode;
        string resolutionValue;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ResolutionInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ResolutionInfo &info);

    struct SyncPlayInfo
    {
        string type;
        Source source;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SyncPlayInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SyncPlayInfo &info);

    struct RebootInfo
    {
        string type;
        Source source;
        string executionType;
        string reason;
        std::vector<Condition> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RebootInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RebootInfo &info);

    struct RebootData
    {
        string sn;
        RebootInfo rebootinfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RebootData &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RebootData &info);

    struct RebootTaskData
    {
        string sn;
        RebootInfo reboottaskinfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RebootTaskData &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RebootTaskData &info);


    struct OTGUSBInfo
    {
        double value;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OTGUSBInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OTGUSBInfo &info);

    struct VersionInfo
    {
        string packageName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VersionInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VersionInfo &info);

    struct PackageInfo
    {
        std::vector<string> packageName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PackageInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PackageInfo &info);

    struct PackageInfoWithSN
    {
        string sn;
        PackageInfo packageInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PackageInfoWithSN &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PackageInfoWithSN &info);

    struct InsertValueWithSN
    {
        string sn;
        string type;
        string value;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const InsertValueWithSN &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InsertValueWithSN &info);

    struct DelValueWithSN
    {
        string sn;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DelValueWithSN &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DelValueWithSN &info);

    struct GetValueWithSN
    {
        string sn;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetValueWithSN &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetValueWithSN &info);

    struct mosaicInfo
    {
        int mosaicWidth = 256;
        int mosaicHeight = 256;
        int mosaicNum = 0;
        string lang = "";
        string userType = "user";
        bool demo = false;
		string token;
		string node;
		string userName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const mosaicInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, mosaicInfo &info);

    struct WifiAPInfo
    {
        string aliasName;
        string suffix;
        string password;
        int channelId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiAPInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiAPInfo &info);

    struct WifiAPOpenStatus
    {
        bool enable = false;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiAPOpenStatus &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiAPOpenStatus &info);

    //高级功能中的options的并集
    struct AdvancedOption
    {
        string sn;
        bool enable;
        RebootInfo rebootInfo;
        SetInfo setInfo;
        ModeInfo modeInfo;
        RequestInfo requestInfo;
        ResolutionInfo resolutionInfo;
        string aliasName;
        string suffix;
        string password;
        int channelId = -1;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AdvancedOption &option);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AdvancedOption &option);
    struct NetworkStatus4G
    {
        int mobileNetState = -1;
        int netType = -1;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const NetworkStatus4G &option);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, NetworkStatus4G &option);
}
namespace ns
{
	struct LogOutRespond
	{
		int code;
		string data;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const LogOutRespond &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, LogOutRespond &data);
}
namespace ns
{
	//Handy获取个人信息
	struct GetUserInfoData
	{
		string userName;
		string node;
		string token;
		string email;
		string phone;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetUserInfoData &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetUserInfoData &data);
	struct GetUserInfo
	{
		int code;
		GetUserInfoData data;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetUserInfo &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetUserInfo &data);
	//VNNOX获取个人信息
	struct GetVnnoxUserInfoUser
	{
		string uid;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVnnoxUserInfoUser &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVnnoxUserInfoUser &data);
	struct GetVnnoxUserInfoWorkGroup
	{
		string wid;
		string oid;
		string is_system;
		string parentID;
		string workGroupName;
		string remark;
		vector<GetVnnoxUserInfoUser> user;
		bool checked;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVnnoxUserInfoWorkGroup &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVnnoxUserInfoWorkGroup &data);
	struct GetVnnoxUserInfoRole
	{
		string rid;
		string name;
		string uid;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVnnoxUserInfoRole &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVnnoxUserInfoRole &data);
	struct GetVnnoxUserInfoData
	{
		string uid;
		string default_approve;
		string isAdmin;
		string firstName;
		string familyName;
		string mail;
		string phoneCountryCode;
		string phoneNumber;
		string userLang;
		vector<GetVnnoxUserInfoRole> role;
		string uName;
		vector<GetVnnoxUserInfoWorkGroup> workgroup;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVnnoxUserInfoData &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVnnoxUserInfoData &data);
	struct GetVnnoxUserInfo
	{
		int http_code;
		vector<int> status;
		vector<GetVnnoxUserInfoData> data;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVnnoxUserInfo &data);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVnnoxUserInfo &data);
}

namespace ns
{
    struct SetWifiApStationSwitchTaskInfo
    {
        int state;
        string ssid;
        string password;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetWifiApStationSwitchTaskInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetWifiApStationSwitchTaskInfo &data);
    struct SetWifiApStationSwitchTaskArray
    {
        string type;
        int action;
        SetWifiApStationSwitchTaskInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetWifiApStationSwitchTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetWifiApStationSwitchTaskArray &data);
    struct SetWifiApStationSwitchRequest
    {
        Source source;
        vector<SetWifiApStationSwitchTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetWifiApStationSwitchRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetWifiApStationSwitchRequest &data);
    struct SetWifiApStationSwitch
    {
        string sn;
        SetWifiApStationSwitchTaskInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetWifiApStationSwitch &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetWifiApStationSwitch &data);
}
namespace ns
{
    struct GetModuleInfoResponseData
    {
        string imei;
        string model;
        string version;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetModuleInfoResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetModuleInfoResponseData &data);
    struct GetModuleInfoResponseTaskArray
    {
        int action;
        int errorCode;
        long orderId;
        int status;
        string type;
        GetModuleInfoResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetModuleInfoResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetModuleInfoResponseTaskArray &data);
    struct GetModuleInfoResponse
    {
        string currentTime;
        vector<GetModuleInfoResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetModuleInfoResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetModuleInfoResponse &data);
}
namespace ns
{
    struct GetIcareRequestInfo
    {
        string language;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetIcareRequestInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetIcareRequestInfo &data);

    struct GetIcareConfigInfo
    {
        string sn;
        GetIcareRequestInfo getIcareRequestInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetIcareConfigInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetIcareConfigInfo &data);

}

namespace ns {
    struct ServerNodes
    {
        string lable;
        string node;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ServerNodes &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ServerNodes &data);

    struct GetIcareConfigReturnInfo
    {
        bool state;
        vector<ServerNodes> serverNodes;
        string url;
        string username;
        bool isOnline;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetIcareConfigReturnInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetIcareConfigReturnInfo &data);
}

namespace ns
{

    struct SetIcareRequestInfo
    {
        bool state;
        string url;
        string username;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetIcareRequestInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetIcareRequestInfo &data);

    struct SetIcareConfigInfo
    {
        string sn;
        SetIcareRequestInfo setIcareRequestInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetIcareConfigInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetIcareConfigInfo &data);
}

namespace ns
{

    struct BindPlayerPlayerList
    {
        string identifier;
        bool isUsed;
        string name;
        string playerIdentifier;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BindPlayerPlayerList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BindPlayerPlayerList &data);

    struct BindPlayerData
    {
        string token;
        std::vector<BindPlayerPlayerList> bindPlayerPlayerList;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BindPlayerData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BindPlayerData &data);

    struct BindPlayerInfo
    {
        bool isBind;
        string errorDescription;
        string baseUrl;
        string password;
        string username;
        string serverPlayerName;
        std::vector<int> status;
        BindPlayerData bindPlayerData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BindPlayerInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BindPlayerInfo &data);

    struct GetBindPlayer
    {
        string sn;
        BindPlayerInfo bindPlayerInfo;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetBindPlayer &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetBindPlayer &data);

    struct GetBindPlayerSn
    {
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetBindPlayerSn &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetBindPlayerSn &data);

    struct SetBindPlayerInfo
    {
        string baseUrl;
        bool isNewVnnox;
        string password;
        string username;
        BindPlayerData bindPlayerData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetBindPlayerInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetBindPlayerInfo &data);

    struct SetBindPlayer
    {
        string sn;
        SetBindPlayerInfo setBindPlayerInfo;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetBindPlayer &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetBindPlayer &data);


}

namespace ns {

    struct GetCloudPlayerListData
    {
        string url;
        string username;
        string password;
        int playerType;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetCloudPlayerListData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetCloudPlayerListData &data);

    struct PlayerListReturnPlayerList
    {
        string name;
        string identifier;
        bool isUsed;
        string playerIdentifier;
        bool litePlayerRegister;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerListReturnPlayerList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerListReturnPlayerList &data);

    struct PlayerListReturnData
    {
        string token;
        std::vector<PlayerListReturnPlayerList> playerListReturnPlayerList;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerListReturnData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerListReturnData &data);

    struct GetCloudPlayerListReturnData
    {
        std::vector<int> status;
        PlayerListReturnData playerListReturnData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetCloudPlayerListReturnData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetCloudPlayerListReturnData &data);
}
//vnnox服务器地址获取
namespace ns
{
    struct  VnnoxServerInfo
    {
        string label;
        string node;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VnnoxServerInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VnnoxServerInfo &data);

    // VIPLEXCOMMON_EXPORT void to_json(json& j, const map<string, vector<VnnoxServerInfo>> &servers);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, map<string, vector<VnnoxServerInfo>> &servers);

}
namespace ns
{
    struct GetOnlineUpdatePackage
    {
        string productName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetOnlineUpdatePackage &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetOnlineUpdatePackage &data);
    struct DownloadOnlineFileData
    {
        string url;
        string address;
        string md5;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadOnlineFileData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadOnlineFileData &data);
    struct OnlineUpdatePackageInfo
    {
        string type;
        string url;
        string version;
        int64_t size;
        string md5;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OnlineUpdatePackageInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OnlineUpdatePackageInfo &data);

    struct OnlineUpdatePackageData
    {
        vector<OnlineUpdatePackageInfo> onlineUpdatePackageInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OnlineUpdatePackageData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OnlineUpdatePackageData &data);

    struct UpgradeDescription
    {
        string zh;
        string jp;
        string es;
        string kp;
        string fr;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpgradeDescription &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpgradeDescription &data);
    struct OnlinePackage
    {
        vector<string> supportedPlatforms;
        string name;
        vector<string> supportedProducts;
        string isUpgradeAppAfterOS;
        string version;
        string identifier;
        string type;
        bool startupAfterInstalled;
        int64_t size;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OnlinePackage &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OnlinePackage &data);
    struct AnnexesDescription
    {
        vector<string> commonSupportedProducts;
        string description;
        string totalSize;
        string excutionType;
        string version;
        string createdDate;
        string packetType;
        OnlinePackage packages;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AnnexesDescription &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AnnexesDescription &data);
    struct OnlineFileDescription
    {
        string productTypeUnique;
        string productType;
        string productUnique;
        string productModel;
        string productVersion;
        UpgradeDescription upgradeDescription;
        string md5;
        int64_t size;
        string downloadAddress;
        AnnexesDescription annexesDescription;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OnlineFileDescription &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OnlineFileDescription &data);

    struct UnzipJsonContentData
    {
        vector<string> zipFilePaths;
        vector<string> dFileNames;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UnzipJsonContentData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UnzipJsonContentData &data);

    struct ReadZipFileContent
    {
        vector<string> zipFilePaths;
        vector<string> zipFileContents;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ReadZipFileContent &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ReadZipFileContent &data);

    struct FilePath
    {
        vector<string> filePath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FilePath &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FilePath &data);

    struct ViplexUpdateInfo
    {
        string sn;
        string filePath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ViplexUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ViplexUpdateInfo &data);

    struct StopUpdateInfo
    {
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const StopUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, StopUpdateInfo &data);

    struct ViplexPackage
    {
        string type;
        string version;
        string name;
        string identifier;
        int64_t size;
        bool startupAfterInstalled;
        string isUpgradeAppAfterOS;
        list<string> supportedProducts;
        list<string> supportedPlatforms;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ViplexPackage &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ViplexPackage &data);

    struct VerifyInfo
    {
        string version;
        int64_t totalSize;
        string description;
        string packetType;
        string excutionType;
        string createdDate;
        list<ViplexPackage> packages;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VerifyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VerifyInfo &data);

    struct UpdateVerifyData
    {
        string sn;
        ns::VerifyInfo verifyInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateVerifyData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateVerifyData &data);

    struct VPlayerViplexPackage
    {
        string type;
        string version;
        string name;
        string identifier;
        int64_t size;
        bool startupAfterInstalled;
        list<string> supportedProducts;
        list<string> supportedPlatforms;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPlayerViplexPackage &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPlayerViplexPackage &data);

    struct VPlayerVerifyInfo
    {
        string version;
        int64_t totalSize;
        string description;
        string packetType;
        string excutionType;
        string createdDate;
        list<VPlayerViplexPackage> packages;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPlayerVerifyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPlayerVerifyInfo &data);

    struct VPlayerUpdateVerifyData
    {
        string sn;
        ns::VPlayerVerifyInfo verifyInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPlayerUpdateVerifyData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPlayerUpdateVerifyData &data);

    struct UpdatePackageDescription
    {
        string description;
        string version;
        string versionCode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdatePackageDescription &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdatePackageDescription &data);

    enum UpdatePackageUploadStatus
    {
        START = 0,           //开始传输
        UPLOADING = 1,       //传输中
        FINISH = 2           //传输结束
    };
    struct UpdatePackageUploadProgress
    {
        UpdatePackageUploadStatus status;  //状态
        qint64 bytesSent;                  //已传输的字节
        qint64 bytesTotal;                 //文件总字节数
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdatePackageUploadProgress &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdatePackageUploadProgress &data);

    enum UpdateStatusEnum
    {
        STARTUPGRADE = 0,   //开始升级
        UPGRADING = 1       //升级中(暂时不用)
    };
    struct UpdateStatus
    {
        UpdateStatusEnum status;   //升级状态
        string versioin;           //升级包版本号（现在拿不到）
        string packageType;        //包类型（APP：软件升级包 OS：系统升级包）
        string packageName;        //包名
        string time;               //当前系统时间
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateStatus &data);

    enum PackageType
    {
        APP,
        OS,
        OS_DIF,
        FPGA,
        NUZIP,
        AUTO
    };
    enum ExecutionType
    {
        IMMEDIATELY,
        BY_CONDITIONS
    };
    enum UpdateType
    {
        UPDATE,
        REPLACE,
    };



    struct ViplexUpdateConditions
    {
        string start;
        vector<string> corn;
        string end;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ViplexUpdateConditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ViplexUpdateConditions &data);

    struct ViplexUpdateTask
    {
        string packageType;
        string version;
        string executionType;
        qint64 size;
        string md5;
        string updateType;
        bool startupAfterInstalled;
        bool startupAfterBoot;
        vector<ViplexUpdateConditions> conditions;
        string source;
        bool checkFeasibility;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ViplexUpdateTask &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ViplexUpdateTask &data);

    struct ViplexUpdateData
    {
        string type;
        bool isLocal = false;
        Source source;
        vector<ViplexUpdateTask> tasks;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ViplexUpdateData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ViplexUpdateData &data);
    struct ViplexUpdateDataInfo
    {
        std::string sn;
        ViplexUpdateData taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ViplexUpdateDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ViplexUpdateDataInfo &data);
}

namespace ns {

    struct NodeServerListData
    {
        string sn;
        string nodeServerName;
        string nodeServerAddress;
        string nodeServerId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const NodeServerListData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, NodeServerListData &data);

    struct NodeServerList
    {
        std::vector<NodeServerListData> nodeServerListData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const NodeServerList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, NodeServerList &data);

}

namespace ns
{
    struct VolumeInfo
    {
        float ratio;
        Source source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VolumeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VolumeInfo &data);
    struct Volume
    {
        string sn;
        VolumeInfo volumeInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Volume &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Volume &data);

    struct TimingVolumeConditions
    {
        std::vector<string> cron;
        float value = 0;
        bool enable;
        string startTime;
        string endTime;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVolumeConditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVolumeConditions &data);

    struct TimingVolumeInfo
    {

        string type;
        Source source;
        bool enable;
        vector<TimingVolumeConditions> conditions;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVolumeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVolumeInfo &data);

    struct TimingVolume
    {
        string sn;
        ns::TimingVolumeInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVolume &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVolume &data);

}

namespace ns
{
    struct ColorTemperatureInfo
    {
        int colorTemperature;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ColorTemperatureInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ColorTemperatureInfo &data);
    struct ColorTemperature
    {
        string sn;
        ColorTemperatureInfo colorTemperatureInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ColorTemperature &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ColorTemperature &data);
}

namespace ns
{
    struct GetEnvironmentBrightnessInfo
    {
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetEnvironmentBrightnessInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetEnvironmentBrightnessInfo &data);

    struct GetEnvironmentBrightnessReturnData
    {
        int value;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetEnvironmentBrightnessReturnData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetEnvironmentBrightnessReturnData &data);

}

namespace ns
{
    struct Ratio0x99
    {
        float ratio;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Ratio0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Ratio0x99 &data);
    struct LightTaskArrayDataFor0x99
    {
        string type;
        long orderId;
        int action;
        Ratio0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LightTaskArrayDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LightTaskArrayDataFor0x99 &data);
    struct LightRequestDataFor0x99
    {
        Source source;
        std::vector<LightTaskArrayDataFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LightRequestDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LightRequestDataFor0x99 &data);

    struct setScreenBrightness
    {
        string sn;
        ns::Ratio0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const setScreenBrightness &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, setScreenBrightness &data);

    struct RatioResponse0x99
    {
        json::value_type ratio;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(nlohmann::json &j, const RatioResponse0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const nlohmann::json &j, RatioResponse0x99 &data);

    struct ScreenBrightnessResponseTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        short errorCode;
        RatioResponse0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessResponseTaskArray &data);

    struct ScreenBrightnessResponseData
    {
        string currentTime;
        vector<ScreenBrightnessResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessResponseData &data);
}


namespace ns
{
    struct GetScreenUnitTempInfo
    {
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetScreenUnitTempInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetScreenUnitTempInfo &data);
}

namespace ns
{
    struct GetAvailableStorageDataInfo
    {
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetAvailableStorageDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetAvailableStorageDataInfo &data);

}

namespace ns
{
    struct BrightnessAdjustModeInfo
    {
        string type;
        Source source;
        string mode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BrightnessAdjustModeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BrightnessAdjustModeInfo &data);
    struct BrightnessAdjustMode
    {
        string sn;
        BrightnessAdjustModeInfo brightnessAdjustModeInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BrightnessAdjustMode &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BrightnessAdjustMode &data);
}

namespace ns
{
    struct ScreenBrightnessInfo
    {
        float ratio;
        Source source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessInfo &data);
    struct ScreenBrightness
    {
        string sn;
        ScreenBrightnessInfo screenBrightnessInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightness &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightness &data);
}

namespace ns
{
    struct BrightnessPolicyInfo
    {
        bool isSupportCompleteCron;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BrightnessPolicyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BrightnessPolicyInfo &data);
    struct ScreenBrightnessPolicy
    {
        string sn;
        BrightnessPolicyInfo brightnessPolicyInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessPolicy &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessPolicy &data);

}

namespace ns
{
    struct Segments
    {
        int environmentBrightness;
        double screenBrightness;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Segments &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Segments &data);
    struct OpticalFailureInfo
    {
        bool enable;
        double screenBrightness = -1;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OpticalFailureInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OpticalFailureInfo &data);
    struct Conditions
    {
        int type;
        vector<string> crons;
        string startTime;
        string endTime;
        vector<json::value_type> args;
        vector<Segments> segments;
        OpticalFailureInfo opticalFailureInfo;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Conditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Conditions &data);
    struct SegmentConfig
    {
        vector<json::value_type> args;
        vector<Segments> segments;
        OpticalFailureInfo opticalFailureInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SegmentConfig &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SegmentConfig &data);

    struct ScreenBrightnessPolicyTaskInfo
    {
        string type;
        Source source;
        bool enable;
        vector<Conditions> conditions;
        SegmentConfig segmentConfig;
        string timeStamp;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessPolicyTaskInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessPolicyTaskInfo &data);
    struct ScreenBrightnessPolicyDetail
    {
        string sn;
        ScreenBrightnessPolicyTaskInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessPolicyDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessPolicyDetail &data);
}

namespace ns
{
    struct SegmentsInt
    {
        int environmentBrightness;
        int screenBrightness;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SegmentsInt &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SegmentsInt &data);
    struct OpticalFailureInfoInt
    {
        bool enable;
        int screenBrightness = -1;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OpticalFailureInfoInt &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OpticalFailureInfoInt &data);
    struct ConditionsInt
    {
        int type;
        vector<string> crons;
        string startTime;
        string endTime;
        vector<int> args;
        vector<SegmentsInt> segments;
        OpticalFailureInfoInt opticalFailureInfo;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConditionsInt &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConditionsInt &data);
    struct SegmentConfigInt
    {
        vector<int> args;
        vector<SegmentsInt> segments;
        OpticalFailureInfoInt opticalFailureInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SegmentConfigInt &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SegmentConfigInt &data);

    struct ScreenBrightnessPolicyTaskInfoInt
    {
        string type;
        Source source;
        bool enable;
        vector<ConditionsInt> conditions;
        SegmentConfigInt segmentConfig;
        string timeStamp;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessPolicyTaskInfoInt &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessPolicyTaskInfoInt &data);
    struct ScreenBrightnessPolicyDetailInt
    {
        string sn;
        ScreenBrightnessPolicyTaskInfoInt taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenBrightnessPolicyDetailInt &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenBrightnessPolicyDetailInt &data);
}

namespace ns
{
    struct BrightnessAdjustDataDetail
    {
        bool enable;
        vector<Conditions> conditions;
        SegmentConfig segmentConfig;
        string timeStamp;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BrightnessAdjustDataDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BrightnessAdjustDataDetail &data);
    struct SetBrightnessAdjustTaskArray
    {
        string type;
        long orderId;
        int action;
        BrightnessAdjustDataDetail data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetBrightnessAdjustTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetBrightnessAdjustTaskArray &data);
    struct SetBrightnessAdjustRequest
    {
        Source source;
        vector<SetBrightnessAdjustTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetBrightnessAdjustRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetBrightnessAdjustRequest &data);
    struct SetBrightnessAdjustDataInfo
    {
        string sn;
        BrightnessAdjustDataDetail taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetBrightnessAdjustDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetBrightnessAdjustDataInfo &data);
}

namespace ns
{
    struct  CloudPlayerListPlayerInfoData
    {
        string username;
        string password;
        int playerType;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CloudPlayerListPlayerInfoData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CloudPlayerListPlayerInfoData &data);

    struct CloudPlayerListPlayerInfo
    {
        string host;
        CloudPlayerListPlayerInfoData cloudPlayerListPlayerInfoData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CloudPlayerListPlayerInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CloudPlayerListPlayerInfo &data);

    struct CloudPlayerList
    {
        string sn;
        CloudPlayerListPlayerInfo cloudPlayerListPlayerInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CloudPlayerList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CloudPlayerList &data);
}

namespace ns
{
    struct VedioCondition
    {
        string cron;
        int source;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VedioCondition &condition);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VedioCondition &condition);

    struct VideoSourceInfo
    {
        string type;
        ns::Source source;
        int videoMode;
        int videoSource;
        bool isScale;
        int offsetX;
        int offsetY;
        vector<VedioCondition> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoSourceInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoSourceInfo &info);

    struct VideoSourceCtrlInfo
    {
        string sn;

        VideoSourceInfo videdSourceInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoSourceCtrlInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoSourceCtrlInfo &info);

    struct ScreenshotInfo
    {
        string sn;
        int width;
        int height;
        string downLoadDirectoryPath;
        string pictureName;
        int pictureType;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenshotInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenshotInfo &info);

    struct ScreenshotNetResult
    {
        int status;
        std::string path;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenshotNetResult& result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenshotNetResult& result);

    struct PublicNetScreenshotInfo
    {
        string sn;
        int width;
        int height;
        string url;
        string pictureName;
        int pictureType;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetScreenshotInfo& info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetScreenshotInfo& info);

    struct ScreenshotResult
    {
        string path;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenshotResult &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenshotResult &result);

    struct EDIDInfo
    {
        int width;
        int height;
        int fieldRate = 60;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EDIDInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EDIDInfo &result);
    struct EDIDControl
    {
        string sn;
        EDIDInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EDIDControl &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EDIDControl &result);
}
namespace ns
{
    struct ScreenRotationSettingsInfo
    {
        int rotationValue;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenRotationSettingsInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenRotationSettingsInfo &result);
    struct ScreenRotationSettingsTaskArray
    {
        string type;
        int action;
        ScreenRotationSettingsInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenRotationSettingsTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenRotationSettingsTaskArray &data);
    struct ScreenRotationSettingsRequest
    {
        Source source;
        vector<ScreenRotationSettingsTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenRotationSettingsRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenRotationSettingsRequest &data);
    struct ScreenRotationSettings
    {
        string sn;
        ScreenRotationSettingsInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenRotationSettings &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenRotationSettings &result);
    struct GetRotationResponseTaskArray
    {
        int action;
        int errorCode;
        int status;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetRotationResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetRotationResponseTaskArray &data);
    struct GetRotationResponseData
    {
        string currentTime;
        vector<GetRotationResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetRotationResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetRotationResponseData &data);
}
namespace ns
{
    struct GetRotationData
    {
        int rotationValue;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetRotationData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetRotationData &data);
    struct GetRotationTaskArray
    {
        string type;
        int action;
        int status;
        short errorCode;
        GetRotationData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetRotationTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetRotationTaskArray &data);
    struct GetRotationResponse
    {
        string currentTime;
        vector<GetRotationTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetRotationResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetRotationResponse &data);
}
namespace ns
{
    struct GetDisplayInfoResponseData
    {
        int width;
        int height;
        int rotation;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetDisplayInfoResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetDisplayInfoResponseData &data);
    struct GetDisplayInfoResponseTaskArray
    {
        string type;
        int action;
        int status;
        GetDisplayInfoResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetDisplayInfoResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetDisplayInfoResponseTaskArray &data);
    struct GetDisplayInfoResponse
    {
        string currentTime;
        vector<GetDisplayInfoResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetDisplayInfoResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetDisplayInfoResponse &data);
}
namespace ns
{
    struct SetTimeAndZoneData
    {
        long long utcTimeMillis;;
        string timeZone;
        string gmt;
        bool isTimeOffsetEnable;
        string beginTime;
        string endTime;
        long timeOffsetValue;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimeAndZoneData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimeAndZoneData &data);
    struct SetTimeAndZoneTaskArray
    {
        string type;
        long orderId;
        int action;
        SetTimeAndZoneData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimeAndZoneTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimeAndZoneTaskArray &data);
    struct SetTimeAndZoneRequest
    {
        Source source;
        vector<SetTimeAndZoneTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimeAndZoneRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimeAndZoneRequest &data);
    struct SetTimeAndZone
    {
        string sn;
        SetTimeAndZoneData taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimeAndZone &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimeAndZone &data);
}
namespace ns
{
    struct SetScreenShotUploadOssInfo
    {
        string accessid;
        string host;
        string policy;
        string signature;
        string expire;
        string callback;
        string dir;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetScreenShotUploadOssInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetScreenShotUploadOssInfo &data);
    struct SetScreenShotData
    {
        SetScreenShotUploadOssInfo uploadOssInfo;
        string sessionID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetScreenShotData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetScreenShotData &data);
    struct SetScreenShotTaskArray
    {
        string type;
        long orderId;
        int action;
        SetScreenShotData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetScreenShotTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetScreenShotTaskArray &data);
    struct SetScreenShotRequest
    {
        Source source;
        vector<SetScreenShotTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetScreenShotRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetScreenShotRequest &data);
    struct SetScreenShot
    {
        string sn;;
        SetScreenShotData taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetScreenShot &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetScreenShot &data);
}
namespace ns
{
    struct ScreenPowerModeInfo
    {
        string type;
        Source source;
        string mode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenPowerModeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenPowerModeInfo &data);
    struct ScreenPowerMode
    {
        string sn;
        ScreenPowerModeInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenPowerMode &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenPowerMode &data);
    struct SetScreenPowerModeConditions
    {
        string action;
        vector<string> cron;
        bool enable;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetScreenPowerModeConditions &data);
    struct SetScreenPowerModeResponse
    {
        vector<SetScreenPowerModeConditions> conditions;
        bool enable = false;
        Source source;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetScreenPowerModeResponse &data);
}

namespace ns
{
    struct ScreenPowerInfo
    {
        string type;
        Source source;
        string state;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenPowerInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenPowerInfo &data);
    struct ScreenPower
    {
        string sn;
        ScreenPowerInfo  taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenPower &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenPower &data);
}

namespace ns
{
    struct ScreenConditions
    {
        vector<string> cron;
        string action;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenConditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenConditions &data);
    struct ScreenPowerPolicyInfo
    {
        string type;
        Source source;
        bool enable;
        vector<ScreenConditions> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenPowerPolicyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenPowerPolicyInfo &data);
    struct  ScreenPowerPolicy
    {
        string sn;
        ScreenPowerPolicyInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenPowerPolicy &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenPowerPolicy &data);
}
namespace ns
{
    struct SwitchingScreenInfo
    {
        string state;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SwitchingScreenInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SwitchingScreenInfo &data);
    struct TaskArrayData
    {
        string type;
        long orderId;
        int action;
        SwitchingScreenInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TaskArrayData &data);
    struct SwitchingScreenRequest
    {
        Source source;
        vector<TaskArrayData> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SwitchingScreenRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SwitchingScreenRequest &data);
    struct SwitchingScreen
    {
        string sn;
        SwitchingScreenInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SwitchingScreen &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SwitchingScreen &data);
}
namespace ns
{
    struct ConditionsData
    {
        vector<string> cron;
        string action;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConditionsData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConditionsData &data);
    struct SwitchScreenStatusInfo
    {
        bool enable;
        vector<ConditionsData> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SwitchScreenStatusInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SwitchScreenStatusInfo &data);
    struct SwitchScreenStatusTaskArray
    {
        string type;
        long orderId;
        int action;
        SwitchScreenStatusInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SwitchScreenStatusTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SwitchScreenStatusTaskArray &data);
    struct SwitchScreenStatusRequest
    {
        Source source;
        vector<SwitchScreenStatusTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SwitchScreenStatusRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SwitchScreenStatusRequest &data);
    struct SwitchScreenStatus
    {
        string sn;
        SwitchScreenStatusInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SwitchScreenStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SwitchScreenStatus &data);
}

namespace ns
{
    struct GetSwitchScreenStatusData
    {
        string state;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSwitchScreenStatusData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSwitchScreenStatusData &data);
    struct GetSwitchScreenResponseStatusTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        short errorCode;
        GetSwitchScreenStatusData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSwitchScreenResponseStatusTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSwitchScreenResponseStatusTaskArray &data);
    struct GetSwitchScreenResponseStatus
    {
        string currentTime;
        vector<GetSwitchScreenResponseStatusTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSwitchScreenResponseStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSwitchScreenResponseStatus &data);
}

namespace ns
{
    struct GetTimingSwitchScreenResponseCommandConditions
    {
        vector<string> cron;
        string action;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingSwitchScreenResponseCommandConditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingSwitchScreenResponseCommandConditions &data);
    struct GetTimingSwitchScreenResponseCommandData
    {
        Source source;
        bool enable;
        vector<GetTimingSwitchScreenResponseCommandConditions> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingSwitchScreenResponseCommandData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingSwitchScreenResponseCommandData &data);
    struct GetTimingSwitchScreenResponseCommandTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        short errorCode;
        GetTimingSwitchScreenResponseCommandData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingSwitchScreenResponseCommandTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingSwitchScreenResponseCommandTaskArray &data);
    struct GetTimingSwitchScreenResponseCommand
    {
        string currentTime;
        vector<GetTimingSwitchScreenResponseCommandTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingSwitchScreenResponseCommand &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingSwitchScreenResponseCommand &data);
}

namespace ns
{
    struct ScanInfos
    {
        int width;
        int height;
        int x;
        int y;
        int xInPort;
        int yInPort;
        int portIndex;
        int connectIndex;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScanInfos &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScanInfos &result);
    struct ScreenAttributeData
    {
        int id;
        int screenSource;
        int xCount;
        int yCount;
        int xOffset;
        int yOffset;
        int portNumber;
        std::vector<int> orders;
        std::vector<ScanInfos> scanInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenAttributeData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenAttributeData &result);
    struct ScreenAttribute
    {
        std::vector<ScreenAttributeData> screenAttributes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenAttribute &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenAttribute &result);
    struct ScreenAttributeInfo
    {
        string sn;
        ScreenAttribute screenAttribute;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenAttributeInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenAttributeInfo &result);
}

namespace ns
{
    struct FtpFileInfo
    {
        string fileName;
        FtpFileTag tag;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FtpFileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FtpFileInfo &data);

    struct FtpParam
    {
        string hostIp;
        int port;
        string userName;
        string sn;
        string remotePath;
        string localPath;
        FtpFileInfo fileInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FtpParam &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FtpParam &data);
}

namespace ns
{
    struct GetPlayerListResponseplayerList
    {
        string name;
        string identifier;
        bool isUsed;
        string playerIdentifier;
        bool litePlayerRegister;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetPlayerListResponseplayerList &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetPlayerListResponseplayerList &result);

    struct GetPlayerListResponseData
    {
        string token;
        vector<GetPlayerListResponseplayerList> getPlayerListResponseplayerList;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetPlayerListResponseData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetPlayerListResponseData &result);

    struct getPlayerListResponseInfo
    {
        vector<int> status;
        GetPlayerListResponseData getPlayerListResponseData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const getPlayerListResponseInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, getPlayerListResponseInfo &result);

    struct getBindPlayerResponseInfo
    {
        bool isBind;
        string baseUrl;
        string username;
        string password;
        GetPlayerListResponseData getPlayerListResponseData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const getBindPlayerResponseInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, getBindPlayerResponseInfo &result);
}

namespace ns
{
    struct GetMemoryRawRequest
    {
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetMemoryRawRequest &request);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetMemoryRawRequest &request);

    struct Receiver
    {
        string outputDestination;
        bool persistent;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Receiver &receiver);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Receiver &receiver);

    struct Picker
    {
        //CollectorType type;
        //PickType pickType;
        string type;
        string pickType;
        long period;
        std::vector<Receiver> receivers;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Picker &picker);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Picker &picker);

    struct CollectorInfo
    {
        std::vector<Picker> pickers;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CollectorInfo &request);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CollectorInfo &request);

    struct CollectorRequest
    {
        string sn;
        CollectorInfo info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CollectorRequest &request);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CollectorRequest &request);

    struct DeleteCollectorData
    {
        std::vector<string> types;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DeleteCollectorData &request);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DeleteCollectorData &request);

    struct DeleteCollectorRequest
    {
        string sn;
        DeleteCollectorData info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DeleteCollectorRequest &request);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DeleteCollectorRequest &request);

    struct FinishPickRawRequest
    {
        string sn;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FinishPickRawRequest &request);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FinishPickRawRequest &request);

    struct FinishPickRequest
    {
        std::vector<string> type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FinishPickRequest &request);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FinishPickRequest &request);
}

namespace ns
{
    struct SpliceInfo
    {
        int order;
        int width;
        int height;
        int offsetX;
        int offsetY;
        int videoSource;
        bool isScale;
        int orderNum;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const SpliceInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SpliceInfo &result);

    struct SpliceData
    {
        string sn;
        SpliceInfo spliceInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SpliceData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SpliceData &result);
}

namespace ns
{
    struct FileName
    {
        std::string fileName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FileName &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FileName &result);

    struct RecvCardFileInfo
    {
        std::string uri;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RecvCardFileInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RecvCardFileInfo &result);

    struct RecvCardFileData
    {
        std::string sn;
        std::string filePath;
        std::string fileName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RecvCardFileData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RecvCardFileData &result);
}

namespace ns
{
    struct WifiConntctInfo
    {
        string ssid;
        string password;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiConntctInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiConntctInfo &data);
    struct WifiConnect
    {
        string sn;
        WifiConntctInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiConnect &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiConnect &data);
    struct WifiDisconnectInfo
    {
        string ssid;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiDisconnectInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiDisconnectInfo &data);
    struct WifiDisconnect
    {
        string sn;
        WifiDisconnectInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiDisconnect &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiDisconnect &data);
    struct WifiStateInfo
    {
        int state;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiStateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiStateInfo &data);
    struct WifiState
    {
        string sn;
        WifiStateInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiState &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiState &data);
    struct TaskArray
    {
        string type;
        int action;
        string data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TaskArray &data);
    struct WifiApStation
    {
        Source source;
        vector<TaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiApStation &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiApStation &data);
    struct APNetworkInfo
    {
        string aliasName;
        string suffix;
        string password;
        int channelId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const APNetworkInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, APNetworkInfo &data);
    struct APNetwork
    {
        string sn;
        APNetworkInfo taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const APNetwork &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, APNetwork &data);
    struct BasicConfigs
    {
        bool mobileData;
        bool dataRoaming;
        bool enable4G;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BasicConfigs &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BasicConfigs &data);
    struct APN
    {
        string providerName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const APN &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, APN &data);
    struct Advanced
    {
        string networkType;
        APN apn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Advanced &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Advanced &data);
    struct MobileNetworkInfo
    {
        BasicConfigs basicConfigs;
        Advanced advanced;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const MobileNetworkInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, MobileNetworkInfo &data);
    struct MobileNetwork
    {
        string sn;
        MobileNetworkInfo mobileData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const MobileNetwork &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, MobileNetwork &data);
    struct Ethernets
    {
        int scopeId = -1;
        string name;
        bool dhcp;
        string ip;
        string mask;
        string gateWay;
        vector<string> dns;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Ethernets &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Ethernets &data);
    struct EthernetDetail
    {
        vector<Ethernets> ethernets;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EthernetDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EthernetDetail &data);
    struct EthernetInfo
    {
        string sn;
        EthernetDetail taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EthernetInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EthernetInfo &data);
    struct WifiListResult
    {
        string bssid;
        int level;
        string security;
        string ssid;
        int state;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiListResult &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiListResult &data);
    struct WifiListInfo
    {
        vector<WifiListResult> result;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiListInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiListInfo &data);
    struct WifiCurrentStatusResponseData
    {
        int state;
        long orderId = -1;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiCurrentStatusResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiCurrentStatusResponseData &data);
    struct WifiCurrentStatusResponseTaskArray
    {
        int action;
        WifiCurrentStatusResponseData data;
        int errorCode;
        long orderId = -1;
        int status;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiCurrentStatusResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiCurrentStatusResponseTaskArray &data);
    struct WifiCurrentStatusResponse
    {
        string currentTime;
        vector<WifiCurrentStatusResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WifiCurrentStatusResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WifiCurrentStatusResponse &data);
}

namespace ns
{
    struct ForceStopAppRequestInfo
    {
        string packageName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ForceStopAppRequestInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ForceStopAppRequestInfo &info);


    struct ForceStopAppInfo
    {
        string sn;
        ForceStopAppRequestInfo requestInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ForceStopAppInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ForceStopAppInfo &info);

    struct UninstalllAppInfo
    {
        string sn;
        string packageName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UninstalllAppInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UninstalllAppInfo &info);

    struct InstalllAppInfo
    {
        string sn;
        string packageName;
        string apkFile;
        bool startAfterInstal;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const InstalllAppInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InstalllAppInfo &info);
}

namespace ns
{
    struct TimeZoneListData
    {
        string id;
        string name;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimeZoneListData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimeZoneListData &result);

    struct TimeZoneList
    {
        std::vector<TimeZoneListData> timeZoneListData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimeZoneList &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimeZoneList &result);

    struct UpLoadUserInfo
    {
        string platform;
        string title;
        string content;
        string file;
        string emailOrphone;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpLoadUserInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpLoadUserInfo &result);
}

namespace ns
{
    struct ProgramInfoData
    {
        string identifier;
        string name;
        string  thumbnailUrl;
        int statusCode;
        int source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ProgramInfoData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ProgramInfoData &result);

    struct ProgramInfo
    {
        std::vector<ProgramInfoData> programInfoData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ProgramInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ProgramInfo &result);

    struct DeleteProgramListDatas
    {
        string identifier;
        string name;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DeleteProgramListDatas &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DeleteProgramListDatas &result);

    struct DeleteProgramListData
    {
        std::vector<DeleteProgramListDatas> deleteProgramListDatas;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DeleteProgramListData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DeleteProgramListData &result);

    struct DeleteProgramList
    {
        string sn;
        DeleteProgramListData deleteProgramListData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DeleteProgramList &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DeleteProgramList &result);

    struct Identifier
    {
        string identifier;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Identifier &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Identifier &result);	struct PlayIdentifier
    {
        string sn;
        string identifier;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayIdentifier &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayIdentifier &result);

    struct QueryFileByType
    {
        std::vector<string> paths;
        std::vector<string> types;
        int pageIndex;
        int pageSize;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const QueryFileByType &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, QueryFileByType &result);

    struct AllFiles
    {
        std::vector<string> files;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AllFiles &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AllFiles &result);

    struct DownLoadFiles
    {
        string sn;
        //vector<string> remotePaths;
        string downLoadDirectoryPath;
        //vector<string>  fileNames;

        std::map<string, string> remotePathsAndFileNames;
        string fileType;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownLoadFiles &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownLoadFiles &result);


    struct DownLoadFilesResult
    {
        string path;
        bool isDownloadSuccess;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownLoadFilesResult &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownLoadFilesResult &result);

    struct DownLoadFilesResultData
    {
        std::vector<DownLoadFilesResult> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownLoadFilesResultData &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownLoadFilesResultData &result);
}

//plan.json文件中用到的数据结构
namespace ns
{
    //文件头信息，标注方案类型与适应平台
    struct SourceInfo
    {
        int type;
        int platform;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SourceInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SourceInfo &data);

    //方案文件信息
    struct SolutionFileInfo
    {
        string strFileName;
        string strMd5;
        //string strUrl;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SolutionFileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SolutionFileInfo &data);

    //资源文件信息
    struct ResourceFileInfo
    {
        string type;
        int id;
        long size;
        string fileName;
        string md5;
        string url;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ResourceFileInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ResourceFileInfo &result);

    struct ThumbnailInfo
    {
        string id;
        long size;
        string fileName;
        string md5;
        string url;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ThumbnailInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ThumbnailInfo &result);

    struct PlanFileInfo
    {
        SourceInfo sourceInfo;
        int id;
        string name;
        //std::vector<SolutionFileInfo> displaySolutions;
        std::vector<SolutionFileInfo> playRelations;
        std::vector<SolutionFileInfo> playSolutions;
        std::vector<SolutionFileInfo> playlists;
        std::vector<SolutionFileInfo> scheduleConstraints;
        //std::vector<SolutionFileInfo> medialists;
        std::vector<ResourceFileInfo> resources;
        //ThumbnailInfo thumbnail;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlanFileInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlanFileInfo &result);
}

//schedule_constraints.json文件中所用到的数据结构
namespace ns
{
    struct ConstraintInfo
    {
        int id;
        //ConstraintTypeEnum type;
        string name;
        int priority;
        string startTime;
        std::vector<string> crons;
        string endTime;
        bool isNotForever = false;
        //SceneRulesEnum rules;
        //int duration;
        //long repeatCount;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConstraintInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConstraintInfo &data);

    struct ConstraintFileInfo
    {
        int id;
        string name;
        //string uuid;
        std::vector<ConstraintInfo> constraints;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConstraintFileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConstraintFileInfo &data);
}

//play_solution.json文件中所用到的数据结构
namespace ns
{
    struct BackgroundMusicInfo
    {
        bool enable;
        string audioGroup;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BackgroundMusicInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BackgroundMusicInfo &data);
    struct TaskItem
    {
        int id;
        string name;
        DisplayRect layout;
        int zOrder;
        //BackgroundMusicInfo backgroundMusic;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TaskItem &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TaskItem &data);

    struct PlaySolutionFileInfo
    {
        string version;
        SourceInfo source;
        string name;
        string uuid;
        std::vector<int> target;
        string pickType;
        int itemCount;
        std::vector<TaskItem> items;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlaySolutionFileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlaySolutionFileInfo &data);
}

//playSolutionRelation.json文件中所用到的数据结构
namespace ns
{
    struct RelationMedialist
    {
        int pageId;
        int widgetContainerId;
        string source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelationMedialist &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelationMedialist &data);

    struct RelationPlaylist
    {
        int playlistId;
        string playlistSource;
        //std::vector<RelationMedialist> medialists;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelationPlaylist &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelationPlaylist &data);

    struct RelationScheduleConstraint
    {
        int constraintId;
        string constraintSource;
        std::vector<RelationPlaylist> playlists;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelationScheduleConstraint &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelationScheduleConstraint &data);

    struct Relation
    {
        int taskId;
        string playSolutionSource;
        std::vector<RelationScheduleConstraint> scheduleConstraints;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Relation &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Relation &data);

    struct RelationFileInfo
    {
        int id;
        string name;
        string playSolutionSource;
        std::vector<Relation> relations;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelationFileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelationFileInfo &data);

}

namespace ns
{
    struct Constraints
    {
        string startTime;
        vector<string> cron;
        string endTime;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Constraints &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Constraints &data);
    struct WidgetGroupsContents
    {
        vector<Widget> widgets;
        //    vector<WidgetContainers> widgetContainers;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WidgetGroupsContents &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WidgetGroupsContents &data);
    struct WidgetGroups
    {
        int id;
        string name;
        bool enable;
        int64_t duration;
        int repeatCount;
        Layout layout;
        Animation inAnimation;
        Animation outAnimation;
        string backgroundMusic;
        string backgroundColor;
        string backgroundDrawable;
        //Borders border;
        int zOrder;
        WidgetGroupsContents contents;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WidgetGroups &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WidgetGroups &data);
    struct Contents
    {
        vector<Widget> widgets;
        vector<WidgetGroups> widgetGroups;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Contents &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Contents &data);
    struct ContentsForJson
    {
        vector<WidgetForJson> widgets;
        vector<WidgetGroups> widgetGroups;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ContentsForJson &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ContentsForJson &data);
    struct Layouts
    {
        string x = "0";
        string y = "0";
        string width = "1";
        string height = "1";
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Layouts &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Layouts &data);
    struct WidgetContainers
    {
        int id;
        string name;
        bool enable = true;
        string backgroundColor = "#00000000";
        string backgroundDrawable = "";
        string pickPolicy = "ORDER";
        int pickCount = 0;
        Layouts layout;
        Border border;
        int zOrder = 0;
        string itemsSource = "";
        string audioGroup = "";
        // vector<int> orderIDArray;
        Contents contents;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WidgetContainers &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WidgetContainers &data);
    struct WidgetContainersForJson
    {
        int id;
        string name;
        bool enable = true;
        string backgroundColor;
        string backgroundDrawable;
        string pickPolicy;
        int pickCount = 0;
        Layouts layout;
        Border border;
        int zOrder;
        string itemsSource;
        string audioGroup;
        // vector<int> orderIDArray;
        ContentsForJson contents;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WidgetContainersForJson &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WidgetContainersForJson &data);
    struct ScenePage
    {
        int id;
        string name;
        // Animation inAnimation;
        // Animation outAnimation;
        //Border border;
        vector<WidgetGroups> widgetGroups;
        vector<Widget> widgets;
        vector<WidgetContainers> widgetContainers;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScenePage &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScenePage &data);
    struct ScenePageForJson
    {
        int id;
        string name;
        // Animation inAnimation;
        // Animation outAnimation;
       //  Borders border;
        vector<WidgetGroups> widgetGroups;
        vector<Widget> widgets;
        vector<WidgetContainersForJson> widgetContainers;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScenePageForJson &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScenePageForJson &data);
    struct  SceneItems
    {
        int id;
        string name;
        //int mode = 0;
        bool enable = true;
        string type = "PLAYLIST";
        string rules = "TIMES";
        int64_t duration = 10000;
        int repeatCount = 1;
        string backgroundColor = "#00ff0000";
        string backgroundDrawable;
        string backgroundMusic;
        vector<Constraints> constraints;
        ScenePage page;
        //string itemSourceId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SceneItems &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SceneItems &data);

    struct  SceneItemsForJson
    {
        int id;
        string name;
        //int mode = 0;
        bool enable;
        string type;
        string rules;
        int64_t duration;
        int repeatCount = 0;
        string backgroundColor;
        string backgroundDrawable;
        string backgroundMusic;
        vector<Constraints> constraints;
        ScenePageForJson page;
        //string itemSourceId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SceneItemsForJson &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SceneItemsForJson &data);
    struct Playlist
    {
        int64_t id = -1;
        string name;
        string uuid;
        string pickPolicy;
        //std::vector<int> orderIDArray;
        //bool thirdParty;
        std::vector<SceneItems> sceneItems;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Playlist &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Playlist &data);
    struct PlaylistForJson
    {
        int64_t id = -1;
        string name;
        string uuid;
        string pickPolicy;
        //std::vector<int> orderIDArray;
        //bool thirdParty;
        std::vector<SceneItemsForJson> sceneItems;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlaylistForJson &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlaylistForJson &data);
    struct AddPage
    {
        int programID;
        int tplID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AddPage &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AddPage &data);
    struct AddPageBackInfo
    {
        int pageID;
        vector<WidgetContainers> widgetContainers;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AddPageBackInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AddPageBackInfo &data);
    struct AddWidgetList
    {
        string widgetMediaType;
        Widget widget;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AddWidgetList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AddWidgetList &data);
    struct AddWidget
    {
        int programID;
        int pageID;
        int widgetContainerID;
        vector<AddWidgetList> taskinfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AddWidget &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AddWidget &data);
    struct AddWidgetBackInfo
    {
        vector<int> widgetID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AddWidgetBackInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AddWidgetBackInfo &data);
    struct GetPageParam
    {
        int programID;
        int pageID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetPageParam &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetPageParam &data);

    struct GetWidgetParamInfo
    {
        int programID;
        int pageID;
        int widgetContainerID;
        int widgetID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetWidgetParamInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetWidgetParamInfo &data);

    struct DeleteWidgetParamInfo
    {
        int programID;
        int pageID;
        int widgetContainerID;
        vector<int> widgetID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DeleteWidgetParamInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DeleteWidgetParamInfo &data);

    struct MoveWidgetParamInfo
    {
        int programID;
        int pageID;
        int widgetContainerID;
        vector<int> widgetID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const MoveWidgetParamInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, MoveWidgetParamInfo &data);

    struct SetWidgetParamInfo
    {
        int programID;
        int pageID;
        int widgetContainerID;
        int widgetID;
        Widget widget;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetWidgetParamInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetWidgetParamInfo &data);

    struct SetPageParam
    {
        int  programID;
        int pageID;
        ScenePage pageInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetPageParam &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetPageParam &data);

    struct SetPageParams
    {
        int programID;
        std::vector<SceneItems> sceneItems;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetPageParams &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetPageParams &data);

    struct WidgetInfo
    {
        int programID;
        int pageID;
        int widgetContainerID;
        int widgetID;
    };
}

namespace ns
{

    struct WinInfo
    {
        float width=0;
        float height=0;
        float left=0;
        float top=0;
        int zindex=0;
        int index;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WinInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WinInfo &data);

    struct CreateProgram
    {
        string name;
        int width;
        int height;
        int tplID=1;
        ns::WinInfo winInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CreateProgram &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CreateProgram &data);

    struct MediasPath
    {
        string oldPath="";
        string newPath="";
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const MediasPath &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, MediasPath &data);


    struct MakeProgram
    {
        std::vector<ns::MediasPath> mediasPath;
        int64_t programID=0;
        string outPutPath="";
        ns::ComplexProgram complexProgram;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const MakeProgram &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, MakeProgram &data);
}

namespace ns
{
    struct UpdateFontInfo
    {
        string name;
        vector<string> style;
        vector<string> file;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateFontInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateFontInfo &data);

    struct UpdateFontDetail
    {
        vector<UpdateFontInfo> fonts;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateFontDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateFontDetail &data);

    struct TemplateSize
    {
        int height = 400;
        int width = 400;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TemplateSize &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TemplateSize &data);

    struct TemplateData
    {
        double width;
        double height;
        double left;
        double top;
        int zindex;
        int index;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TemplateData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TemplateData &data);

    struct TemplateDataInfo
    {
        std::vector<TemplateData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TemplateDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TemplateDataInfo &data);

    struct TemplateInfo
    {
        std::vector<TemplateDataInfo> data;
        TemplateSize size;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TemplateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TemplateInfo &data);

    struct Template
    {
        int tplID;
        std::vector<TemplateData> data;
        TemplateSize size;
        bool isSystemTpl;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Template &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Template &data);

    struct Templates
    {
        std::vector<Template> templates;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Templates &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Templates &data);

    struct TemplateId
    {
        std::vector<int> tplID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TemplateId &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TemplateId &data);


    struct ResponseTemplateId
    {
        int tplID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ResponseTemplateId &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ResponseTemplateId &data);

    struct LocalProgram
    {
        string name;
        int64_t programID;
        int height;
        int width;
        vector<ScenePage> page;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LocalProgram &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LocalProgram &data);

    struct ProgramList
    {
        vector<LocalProgram> programList;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ProgramList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ProgramList &data);

    struct ProgramID
    {
        std::vector<int64_t> programID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ProgramID &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ProgramID &data);

    struct SendProgramFilePaths
    {
        string programPath="";
        std::map<string, string> mediasPath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SendProgramFilePaths &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SendProgramFilePaths &data);

    struct StartTransferProgram
    {
        string sn;
        string iconPath;
        string iconName;
        SendProgramFilePaths sendProgramFilePaths;
        string programName;
        string deviceIdentifier;
        bool startPlayAfterTransferred;
        bool insertPlay;
        string localFontPath = "";
        vector<UpdateFontInfo> fonts;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const StartTransferProgram &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, StartTransferProgram &data);

    struct Solutions
    {
        string name;
        string identifier;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Solutions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Solutions &data);

    struct TransferProgram
    {
        string deviceIdentifier;
        long totalSize;
        string type;
        int source;
        bool local;
        Solutions solutions;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TransferProgram &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TransferProgram &data);

    struct TransferProgramInfo
    {
        string sn;
        TransferProgram transferProgram;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TransferProgramInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TransferProgramInfo &data);

    struct AppliedInfos
    {
        string name;
        string identifier;
        string uploadUrl;
        int statusCode;
        int source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AppliedInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AppliedInfos &data);


    struct DirectoryInfos
    {
        string type;
        long long  availableSize;
        long long  criticalSize;
        string directoryUrl;
        long long  reserveSize;
        long long  totalSize;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DirectoryInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DirectoryInfos &data);

    struct TransferProgramResponseData
    {
        bool canTranster;
        string uploadMediaUrl;
        AppliedInfos appliedInfos;
        vector<DirectoryInfos> directoryInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TransferProgramResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TransferProgramResponseData &data);

    struct TransferFileInfo
    {
        int64_t bytesSent;
        int64_t bytesTotal;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TransferFileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TransferFileInfo &data);

    struct ConfirmedInfos
    {
        string identifier;
        string name;
        string planListUrl;
        string thumbnailUrl;
        bool isSupportMd5Checkout = false;
        int source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConfirmedInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConfirmedInfos &data);

    struct EndTransferProgramInfo
    {
        bool playImmediately;
        ConfirmedInfos confirmedInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EndTransferProgramInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EndTransferProgramInfo &data);

    struct EndTransferProgram
    {
        string sn;
        EndTransferProgramInfo endTransferProgramInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EndTransferProgram &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EndTransferProgram &data);

    struct StopProgramTransfer
    {
        string sn;
        string programName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const StopProgramTransfer &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, StopProgramTransfer &data);

}

namespace ns
{
    struct CreateProgramOnSuccessData
    {
        int64_t programID;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CreateProgramOnSuccessData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CreateProgramOnSuccessData &data);

    struct CreateProgramOnSuccess
    {
        CreateProgramOnSuccessData onSuccess;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CreateProgramOnSuccess &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CreateProgramOnSuccess &data);
}


namespace ns
{
    struct RegisterAddress
    {
        string country;
        string province;
        string city;
        string county;
        string address;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RegisterAddress &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RegisterAddress &data);
    struct UserInfoDetail
    {
        string aliasName;
        RegisterAddress registerAddress;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UserInfoDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UserInfoDetail &data);
    struct ScreenUserInfo
    {
        std::string sn;
        UserInfoDetail userInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenUserInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenUserInfo &data);
}

namespace ns
{
    struct DBData
    {
        std::vector<std::map<std::string, std::string>> program;
        std::vector<ns::TemplateInfo> templates;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DBData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DBData &data);
}

namespace ns
{
    struct ServerLang
    {
        std::string lang;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ServerLang &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ServerLang &data);
}

namespace ns
{
    struct Progress
    {
        long long  m_curBytes;
        long long  m_totalBytes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Progress &data);

    struct ProgressWithStatus
    {
        long long  m_curBytes;
        long long  m_totalBytes;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ProgressWithStatus &data);
}

namespace ns {
    struct SearchResponseData
    {
        string sn;
        string productName;
        int16_t width = 0;
        int16_t height = 0;
        int32_t rotation = 0;
        string aliasName;
        bool logined = false;
        std::vector<string> userNameVec; ////VPlayer搜索回复
        int16_t tcpPort = 0;
        int16_t ftpPort = 0;
        int16_t syssetTcpPort = 0;
        int16_t syssetFtpPort = 0;
        int16_t encodeType = 0;
        string key;
        string platform;
        bool privacy = false;
        string ip;
        bool hasPassWord = false;
        string password;
        int64_t ignoreTime = 0;
        std::vector<string> loginedUsernames; //T卡搜索回复
        int16_t terminalState = 0;
        Version4CS firmwareInfo;
        InstalledPackageVersions installedPackageVersions;
        ConfigInfo productInfo;
        PlayerFunctions configInfo;
        ScreenMosaicInfo screenMosaicInfo;
        string screenLogUrl;
        string screenLogFileName;
        long long screenLogFileSize;
        long long screenLogTime;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SearchResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SearchResponseData &data);

}
namespace ns
{
    struct SerchAppointIpRequest
    {
        string ip;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SerchAppointIpRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SerchAppointIpRequest &data);
}
namespace ns
{
    struct SerchRangeIpRequest
    {
        string ipStart;
        string ipEnd;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SerchRangeIpRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SerchRangeIpRequest &data);
}
namespace ns
{
    struct Number
    {
        int number;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Number &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Number &data);

    struct Name
    {
        string playerName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Name &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Name &data);


    struct newPlayerBoundingInfo
    {
        PlayerBoundingInfo data;
        string baseUrl;
        string token;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const newPlayerBoundingInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, newPlayerBoundingInfo &data);


    struct PlayerNumberData
    {
        PlayerNumber data;
        string baseUrl;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerNumberData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerNumberData &data);


    struct PlayerNameData
    {
        PlayerName data;
        string baseUrl;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerNameData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerNameData &data);
}

namespace ns
{
    struct Attacheds
    {
        string dir;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Attacheds &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Attacheds &data);
    struct FeedBackInfo
    {
        string sn;
        string contact;
        string description;
        vector<Attacheds> attacheds;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FeedBackInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FeedBackInfo &data);

    struct GetTokenHeader
    {
        string appid;
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTokenHeader &data);
    struct Sign
    {
        string sign;
        string time;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Sign &data);
    struct GetTokenResponseInfo
    {
        string token;
        long expire;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTokenResponseInfo &data);
    struct GetTokenResponse
    {
        string logid;
        int status;
        string errmsg;
        GetTokenResponseInfo data;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTokenResponse &data);

    struct GetOssUploadAuthInfo
    {
        string appid;
        string token;
        string sn;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetOssUploadAuthInfo& data);

    struct GetOssUploadAuthInfoResponseData
    {
        string accessid;
        string host;
        string policy;
        string signature;
        int64_t expire;
        string callback;
        string dir;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetOssUploadAuthInfoResponseData &data);
    struct GetOssUploadAuthInfoResponse
    {
        string logid;
        int status;
        string errmsg;
        GetOssUploadAuthInfoResponseData data;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetOssUploadAuthInfoResponse &data);
    struct AttachedsInfo
    {
        string type;
        string dir;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AttachedsInfo &data);
    struct FeedBackUploadInfo
    {
        string description;
        string contact;
        vector<AttachedsInfo> attacheds;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FeedBackUploadInfo &data);

    struct UploadInfoOSS
    {
        string OSSAccessKeyId;
        string policy;
        string signature;
        string callback;
        string key;
        string file;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UploadInfoOSS &data);
    struct FeedBackResult
    {
        string logid;
        int status;
        string data;
    };
	VIPLEXCOMMON_EXPORT void to_json(json& j, const FeedBackResult &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FeedBackResult &data);

    struct FeedBackState
    {
        bool state;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FeedBackState &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FeedBackState &data);
}

namespace ns
{
    struct SignalFilePath
    {
        string filePath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SignalFilePath &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SignalFilePath &data);


    struct WidgetNameAttribute
    {
        int index;
        float speed;
        int turn;
        int scroll;
        bool random;
        string id;
        int subtabId = 0;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WidgetNameAttribute &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WidgetNameAttribute &data);

}

namespace ns
{
    struct FileInfo
    {
        string name;
        long size;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FileInfo &data);

    struct  FileInfos
    {
        std::vector<FileInfo> fileInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FileInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FileInfos &data);

}
namespace ns
{
    //struct  IdentifierList
    //{
    //	vector<string> identifierList;
    //};
    //VIPLEXCOMMON_EXPORT void to_json(json& j, const IdentifierList &data);
    //VIPLEXCOMMON_EXPORT void from_json(const json& j, IdentifierList &data);

    struct GetIdentifierResponceData
    {
        vector<int> status;
        IdentifierList data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetIdentifierResponceData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetIdentifierResponceData &data);
}

namespace ns
{
    struct APNInfoData
    {
        string carrier;			//	APN名称，可为空，只用来显示apn列表中此apn的显示名字
        string mcc;			//	由三位数组成。 用于识别移动用户的所在国家
        string mnc;			//	由两位或三位组成。 用于识别移动用户的归属PLMN
        string apn;			//	APN网络标识（接入点名称），是APN参数中的必选组成部分。此标识由运营商分配
        string user;			//	用户名称
        string password;		//	密码
        string server;			//	服务器地址
        string proxy;			//	代理服务器的地址
        string port;			//	代理服务器的端口
        string mmsc;			//	MMS中继服务器 / 多媒体消息业务中心，是彩信的交换服务器
        string mmsproxy;		//	彩信代理服务器的地址
        string mmsport;		//	彩信代理服务器的端口号
        string type;			//	apn的接入点类型
        string protocol;		//	支持的协议，不配置默认为IPV4
        string authtype;		//	apn的认证协议
        string roamingProtocol;	//	Apn漫游协议
        bool isUserDefined;		//	是否用户自定义
        bool isUsed;			//	是否正在使用
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const APNInfoData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, APNInfoData &data);
}

namespace ns
{
    struct APNSDatas
    {
        vector<APNInfoData>APNs;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const APNSDatas &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, APNSDatas &data);
}

namespace ns
{
    struct APNInfo
    {
        string sn;
        vector<APNInfoData> APNs;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const APNInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, APNInfo &data);
}


namespace ns
{
    struct PolicyCondition
    {
        vector<string> cron;
        int action;
        string type;
        string startTime;
        string endTime;
        bool enable;
        int powerIndex;
        string flag;
        int status = -1;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyCondition &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyCondition &data);
    struct FunctionCardCommand
    {
        vector<PolicyCondition> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FunctionCardCommand &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FunctionCardCommand &data);
    struct FunctionCardPolicy
    {
        bool enable;
        int portIndex;
        int connectIndex;
        vector<FunctionCardCommand> commands;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FunctionCardPolicy &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FunctionCardPolicy &data);
    struct FunctionPowerPolicyDetail
    {
        string type;
        Source source;
        vector<FunctionCardPolicy> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FunctionPowerPolicyDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FunctionPowerPolicyDetail &data);
    struct FunctionPowerPolicy
    {
        string sn;
        FunctionPowerPolicyDetail taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FunctionPowerPolicy &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FunctionPowerPolicy &data);
}
namespace ns
{
    struct FlightModeInfo
    {
        string sn;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FlightModeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FlightModeInfo &data);
}


namespace ns
{
    struct FunctionCardManual
    {
        int	action;
        string type;
        int powerIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FunctionCardManual &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FunctionCardManual &data);


    struct ManualPowerSwitchStatusData
    {
        vector<FunctionCardManual> conditions;
        int portIndex;
        int connectIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ManualPowerSwitchStatusData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ManualPowerSwitchStatusData &data);


    struct ManualPowerSwitchStatus
    {
        string type;
        Source source;
        vector<ManualPowerSwitchStatusData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ManualPowerSwitchStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ManualPowerSwitchStatus &data);

    struct ManualPowerSwitchStatusInfo
    {
        string sn;
        ManualPowerSwitchStatus data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ManualPowerSwitchStatusInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ManualPowerSwitchStatusInfo &data);
}

namespace ns
{
    struct IsUseDayLightTimeData
    {
        string timeZone;
        string gmt;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IsUseDayLightTimeData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IsUseDayLightTimeData &data);

    struct IsUseDayLightTimeInfo
    {
        string sn;
        IsUseDayLightTimeData isUseDayLightTimeData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IsUseDayLightTimeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IsUseDayLightTimeInfo &data);
}
//vpn管理
namespace ns
{
    struct NetWorkInfo
    {
        string ipAddress;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const NetWorkInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, NetWorkInfo &data);
    struct ConnectInfo
    {
        string connectStatus;
        string failReasonCode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConnectInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConnectInfo &data);
    struct VpnInfoResponse
    {
        string guid;
        string platform;
        string taskAction;
        string softwareVersion;
        int playerType;
        string time;
        string vpnName;
        string vpnAddress;
        string vpnType;
        string username;
        string password;
        string sharedSecretKey;
        string redialNumber;
        string redialInterval;
        string sessionTime;
        string isBolTredial;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VpnInfoResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VpnInfoResponse &data);
    struct VPNInfoDetailResponse
    {
        string guid;
        string taskAction;
        Source source;
        string timestamp;
        VpnInfoResponse vpnInfo;
        ConnectInfo connectInfo;
        NetWorkInfo netWorkInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPNInfoDetailResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPNInfoDetailResponse &data);

    struct VpnInfo
    {
        string name;
        string address;
        int protocolType;
        string username;
        string password;
        string sharedSecretKey;
        int redialNumber;
        int redialInterval;
        int sessionTimeout;
        bool isReconnect;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VpnInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VpnInfo &data);
    struct VPNInfoDetail
    {
        string guid;
        string taskAction;
        Source source;
        VpnInfo vpnInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPNInfoDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPNInfoDetail &data);
    struct VPN
    {
        string sn;
        VPNInfoDetail taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPN &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPN &data);


    struct ServiceName
    {
        string serviceName;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ServiceName &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ServiceName &data);

    struct SerciveData
    {
        string sn;
        ServiceName taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SerciveData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SerciveData &data);

}

namespace ns
{
    struct RelayPowerSwitchData
    {
        int powerIndex;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerSwitchData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerSwitchData &data);

    struct RelayPowerSwitchInfo
    {
        ns::Source source;
        std::vector<ns::RelayPowerSwitchData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerSwitchInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerSwitchInfo &data);

    struct RelayPowerSwitchRequest
    {
        std::string sn;
        RelayPowerSwitchInfo info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerSwitchRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerSwitchRequest &data);
}

namespace ns
{
    struct RelayPowerPolicySwitchData
    {
        vector<string> cron;
        int powerIndex;
        int status;
        string startTime;
        string endTime;
        string type;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicySwitchData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicySwitchData &data);

    struct RelayPowerPolicySwitchInfo
    {
        ns::Source source;
        std::vector<ns::RelayPowerPolicySwitchData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicySwitchInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicySwitchInfo &data);

    struct RelayPowerPolicySwitchRequest
    {
        std::string sn;
        RelayPowerPolicySwitchInfo info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicySwitchRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicySwitchRequest &data);
}

namespace ns
{
    struct FontInfo
    {
        string name;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FontInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FontInfo &data);
    struct FontDetail
    {
        vector<FontInfo> fonts;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FontDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FontDetail &data);
    struct TerminalFont
    {
        string sn;
        FontDetail taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TerminalFont &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TerminalFont &data);

    struct UpdateFont
    {
        string sn;
        string localFontPath;
        UpdateFontDetail taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateFont &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateFont &data);
    struct FontPath
    {
        string fontPath;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FontPath &data);
    struct  SupportFonts
    {
        string name;
        string src;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SupportFonts &data);
    struct TerminalFontResponse
    {
        vector<SupportFonts> supportFonts;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TerminalFontResponse &data);
}

namespace ns
{
    struct receiveCardRegionData
    {
        int connectedIndex;
        int portIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const receiveCardRegionData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, receiveCardRegionData &data);

    struct receiveCardRegionWrapper
    {
        vector<receiveCardRegionData> receiveCardRegionInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const receiveCardRegionWrapper &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, receiveCardRegionWrapper &data);

    struct receiveCardRegionRequest
    {
        string sn;
        receiveCardRegionWrapper info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const receiveCardRegionRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, receiveCardRegionRequest &data);


    struct FileManagerData
    {
        string sn;
        HostData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FileManagerData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FileManagerData &data);

    struct Enable
    {
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Enable &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Enable &data);

    struct USBAuthenticData
    {
        string sn;
        Enable taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const USBAuthenticData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, USBAuthenticData &data);

}

namespace ns
{
    struct SetTerminalStatusValue
    {
        int value;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTerminalStatusValue &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTerminalStatusValue &data);

    struct SetTerminalStatus
    {
        string sn;
        SetTerminalStatusValue info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTerminalStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTerminalStatus &data);


}

namespace ns
{
    struct ResolutionData
    {
        int displayMode;
        int	width;
        int	height;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ResolutionData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ResolutionData &data);

    struct SetCustomResolutionRequest
    {
        string sn;
        ResolutionData info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetCustomResolutionRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetCustomResolutionRequest &data);


}

namespace ns
{

    struct  IsUseDayLightTimeResponse
    {
        bool isUseDayLightTime;
        long timeOffsetValue;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IsUseDayLightTimeResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IsUseDayLightTimeResponse &data);


    struct  RunningLogInfo
    {
        std::string  generalUrl;
        std::string zipUrl;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RunningLogInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RunningLogInfo &data);

    struct  USBAuthenticInfo
    {
        bool enable;
        int orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const USBAuthenticInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, USBAuthenticInfo &data);
}

namespace ns
{
    struct IpAudioMediaList
    {
        int id;
        int mid;
        string name;
        string type;
        string md5;
        long size;
        string content;
        string gender;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioMediaList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioMediaList &data);

    struct IpAudioPolicy
    {
        string endType;
        string endValue;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioPolicy &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioPolicy &data);
    struct IpAudioData
    {
        string operate;
        float volume;
        vector<IpAudioMediaList> mediaList;
        IpAudioPolicy policy;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioData &data);

    struct IpAudioTaskArray
    {
        string type;
        int orderId;
        int action;
        IpAudioData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioTaskArray &data);
    struct IpAudioRequestInfo
    {
        Source source;
        vector<IpAudioTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioRequestInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioRequestInfo &data);

    struct IpAudioDataInfo
    {
        string sn;
        IpAudioData taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioDataInfo &data);
    struct IpAudioDataConditions
    {
        string operate;
        string priority;
        vector<IpAudioMediaList> mediaList;
        IpAudioPolicy policy;
        vector<string> cron;
        bool enable;
        float volume;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioDataConditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioDataConditions &data);
    struct IpAudioDataPolicy
    {
        string callback;
        vector<IpAudioDataConditions> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioDataPolicy &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioDataPolicy &data);

    struct IpAudioDataPolicyTaskArray
    {
        string type;
        int orderId;
        int action;
        IpAudioDataPolicy data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioDataPolicyTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioDataPolicyTaskArray &data);
    struct IpAudioDataPolicyRequestInfo
    {
        Source source;
        vector<IpAudioDataPolicyTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioDataPolicyRequestInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioDataPolicyRequestInfo &data);
    struct  IpAudioDataPolicyInfo
    {
        string sn;
        IpAudioDataPolicy taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IpAudioDataPolicyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IpAudioDataPolicyInfo &data);
}




namespace ns
{
    struct SensorData
    {
        int functionId;
        int vendor;
        int sensorId;
        int baudRate;
        bool connected;
        string vendorAliasName;
        string previewValue;
        int previewUnit;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorData &data);
    struct SensorDataDetail
    {
        vector<SensorData> sensorInfos;
        bool isUpgradeSensorProgram;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorDataDetail &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorDataDetail &data);
    struct SetSensorTaskArray
    {
        string type;
        long orderId;
        int action;
        SensorDataDetail data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSensorTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSensorTaskArray &data);
    struct SetSensorRequest
    {
        Source source;
        vector<SetSensorTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSensorRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSensorRequest &data);
    struct SetSensorDataInfo
    {
        string sn;
        SensorDataDetail taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSensorDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSensorDataInfo &data);



    struct SensorRequestData
    {
        bool isUpgradeSensorProgram;
        string sensorInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorRequestData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorRequestData &data);
    struct SensorTaskArray
    {
        string type;
        int action;
        SensorRequestData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorTaskArray &data);
    struct SensorRequest
    {
        Source source;
        vector<SensorTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorRequest &data);
    struct SensorDataInfo
    {
        string sn;
        SensorRequestData taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorDataInfo &data);

    struct SensorResponseData
    {
        vector<SensorData> sensorInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorResponseData &data);
    struct SensorResponseArray
    {
        int action;
        int errorCode;
        int status;
        string type;
        SensorResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorResponseArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorResponseArray &data);
    struct SensorResponse
    {
        vector<SensorResponseArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorResponse &data);
}
namespace ns
{

    struct Type
    {
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Type &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Type &data);




    struct SetTimingVolumeCondition
    {
        vector<string> cron;
        float value;
        bool enable;
        string startTime;
        string endTime;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingVolumeCondition &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingVolumeCondition &data);

    struct SetTimingVolumeTaskArrayData
    {
        bool enable;
        vector<SetTimingVolumeCondition> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingVolumeTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingVolumeTaskArrayData &data);


    struct GetFuncDataFor0x99
    {
        Source source;
        vector<TaskArrayFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetFuncDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetFuncDataFor0x99 &data);
    struct Ratio
    {
        float ratio;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Ratio &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Ratio &data);

    struct VolumeTaskArrayDataFor0x99 :TaskArrayFor0x99
    {
        Ratio data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VolumeTaskArrayDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VolumeTaskArrayDataFor0x99 &data);


    struct VolumeRequestDataFor0x99
    {
        Source source;
        std::vector<VolumeTaskArrayDataFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VolumeRequestDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VolumeRequestDataFor0x99 &data);

    struct SetVolumeRequest
    {
        string sn;
        ns::Ratio data;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetVolumeRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetVolumeRequest &data);


    struct GetVolumeDataFor0x99
    {
        Source source;
        std::vector<TaskArrayFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVolumeDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVolumeDataFor0x99 &data);

    struct GetVolumeRequestDataFor0x99
    {
        string sn;
        GetVolumeDataFor0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVolumeRequestDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVolumeRequestDataFor0x99 &data);


    struct SetVolumeRequestTaskArray : TaskArrayFor0x99
    {
        Ratio data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetVolumeRequestTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetVolumeRequestTaskArray &data);

    struct SetVolumeRequestData
    {
        Source source;
        std::vector<SetVolumeRequestTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetVolumeRequestData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetVolumeRequestData &data);

    struct SetVolumeRequestDataFor0x99
    {
        string sn;
        SetVolumeRequestData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetVolumeRequestDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetVolumeRequestDataFor0x99 &data);




    struct SetTimingVolumeTaskArrayFor0x99 :TaskArrayFor0x99
    {
        SetTimingVolumeTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingVolumeTaskArrayFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingVolumeTaskArrayFor0x99 &data);

    struct SetTimingVolumeDataFor0x99
    {
        Source source;
        vector<SetTimingVolumeTaskArrayFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingVolumeDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingVolumeDataFor0x99 &data);

    struct SetTimingVolumeRequestData
    {
        string sn;
        SetTimingVolumeTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingVolumeRequestData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingVolumeRequestData &data);

    struct GetResponseTaskArray
    {
        int action;
        int errorCode;
        long orderId;
        int status;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetResponseTaskArray &data);
    struct GetResponseData
    {
        string currentTime;
        vector<GetResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetResponseData &data);

    struct RatioResponse
    {
        float ratio;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RatioResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RatioResponse &data);

    struct VolumeResponseTaskArray :GetResponseTaskArray
    {
        RatioResponse data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VolumeResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VolumeResponseTaskArray &data);

    struct VolumeResponseData
    {
        string currentTime;
        vector<VolumeResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VolumeResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VolumeResponseData &data);


    struct TimingVolumeResponseTAData
    {
        vector<TimingVolumeConditions> conditions;
        bool enable;
        Source source;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVolumeResponseTAData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVolumeResponseTAData &data);

    struct TimingVolumeResponseTaskArray :GetResponseTaskArray
    {
        TimingVolumeResponseTAData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVolumeResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVolumeResponseTaskArray &data);


    struct TimingVolumeResponseData
    {
        string currentTime;
        vector<TimingVolumeResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingVolumeResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingVolumeResponseData &data);
}

namespace ns
{
    struct InfraredBehavior
    {
        string type;
        int action;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const InfraredBehavior &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InfraredBehavior &data);

    struct InfraredData
    {
        bool enable;
        int trigger;
        int condition;
        vector<InfraredBehavior> behaviors;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const InfraredData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InfraredData &data);

    struct InfraredInfo
    {
        string sn;
        InfraredData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const InfraredInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InfraredInfo &data);
}



namespace ns
{
    struct VPNTaskArrayDataFor0x99
    {
        string guid;
        string taskAction;
        Source source;
        VpnInfo vpnInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPNTaskArrayDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPNTaskArrayDataFor0x99 &data);

    struct VPNTaskArrayFor0x99 :TaskArrayFor0x99
    {
        VPNTaskArrayDataFor0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPNTaskArrayFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPNTaskArrayFor0x99 &data);

    struct VPNRequestDataFor0x99
    {
        Source source;
        vector<VPNTaskArrayFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPNRequestDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPNRequestDataFor0x99 &data);


    struct VPNRequestFor0x99
    {
        string sn;
        int action;
        VPNTaskArrayDataFor0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VPNRequestFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VPNRequestFor0x99 &data);
}

namespace ns
{
    struct SolidPowerRequestTaskArrayData
    {
        string type;
        int powerIndex;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SolidPowerRequestTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SolidPowerRequestTaskArrayData &data);

    struct SetManualSolidPowerRequestData
    {
        string sn;
        vector<SolidPowerRequestTaskArrayData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetManualSolidPowerRequestData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetManualSolidPowerRequestData &data);

    struct SolidPowerRequestTaskArray :TaskArrayFor0x99
    {
        vector<SolidPowerRequestTaskArrayData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SolidPowerRequestTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SolidPowerRequestTaskArray &data);

    struct SetManualSolidPowerRequestInfo
    {
        Source source;
        vector<SolidPowerRequestTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetManualSolidPowerRequestInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetManualSolidPowerRequestInfo &data);
}

namespace ns
{
    struct PowerControllerManualCondiotions
    {
        int action;
        string type;
        int powerIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerManualCondiotions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerManualCondiotions &data);
    struct PowerControllerManualData
    {
        vector<PowerControllerManualCondiotions> condiotions;
        int portIndex;
        int connectIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerManualData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerManualData &data);
    struct PowerControllerManualTaskArray
    {
        string type;
        long orderId;
        int action;
        vector<PowerControllerManualData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerManualTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerManualTaskArray &data);
    struct PowerControllerManualRequest
    {
        Source source;
        vector<PowerControllerManualTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerManualRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerManualRequest &data);
    struct PowerControllerManualInfo
    {
        string sn;
        vector<PowerControllerManualData> taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerManualInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerManualInfo &data);
    struct PowerControllerPolicyData
    {
        vector<PolicyCondition> conditions;
        bool enable;
        int portIndex;
        int connectIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerPolicyData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerPolicyData &data);
    struct PowerControllerPolicyTaskArray
    {
        string type;
        long orderId;
        int action;
        vector<PowerControllerPolicyData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerPolicyTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerPolicyTaskArray &data);
    struct PowerControllerPolicyRequest
    {
        Source source;
        vector<PowerControllerPolicyTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerPolicyRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerPolicyRequest &data);
    struct PowerControllerPolicyInfo
    {
        string sn;
        vector<PowerControllerPolicyData> taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerControllerPolicyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerControllerPolicyInfo &data);
    struct PowerPolicyResponseDataInfo
    {
        vector<PolicyCondition> conditions;
        int connectIndex;
        bool enable;
        int portIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerPolicyResponseDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerPolicyResponseDataInfo &data);
    struct PowerPolicyResponseData
    {
        Source source;
        vector<PowerPolicyResponseDataInfo> data;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerPolicyResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerPolicyResponseData &data);
    struct PowerPolicyResponseTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        int errorCode;
        PowerPolicyResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerPolicyResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerPolicyResponseTaskArray &data);
    struct PowerPolicyResponse
    {
        vector<PowerPolicyResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerPolicyResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerPolicyResponse &data);
    struct PowerStatusResponseUpdateStates
    {
        int action;
        string type;
        int powerIndex;
        int state;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerStatusResponseUpdateStates &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerStatusResponseUpdateStates &data);
    struct PowerStatusResponseCurrentInfo
    {
        int portIndex;
        int connectIndex;
        vector<PowerStatusResponseUpdateStates> updatePowerIndexStates;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerStatusResponseCurrentInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerStatusResponseCurrentInfo &data);
    struct PowerStatusResponseData
    {
        Source source;
        vector<PowerStatusResponseCurrentInfo> current_status_info;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerStatusResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerStatusResponseData &data);
    struct PowerStatusResponseTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        int errorCode;
        PowerStatusResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerStatusResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerStatusResponseTaskArray &data);
    struct PowerStatusResponse
    {
        vector<PowerStatusResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerStatusResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerStatusResponse &data);
    struct PowerModeData
    {
        string mode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeData &data);
    struct PowerModeTaskArray
    {
        string type;
        int action;
        long orderId;
        int errorCode;
        PowerModeData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeTaskArray &data);
    struct PowerModeRequest
    {
        Source source;
        vector<PowerModeTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeRequest &data);
    struct  PowerModeInfo
    {
        string sn;
        PowerModeData taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeInfo &data);
    struct PowerModeSource 
    {
        int type = -1;
        int platform = -1;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeSource &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeSource &data);
    struct PowerModeResponseData
    {
        PowerModeSource source;
        int mode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeResponseData &data);
    struct PowerModeResponseTaskArray
    {
        string type;
        int action;
        int status;
        int errorCode;
        PowerModeResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeResponseTaskArray &data);
    struct PowerModeResponse
    {
        vector<PowerModeResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerModeResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerModeResponse &data);


    struct TimingSolidPowerTaskArrayData
    {
        vector<string> cron;
        int powerIndex;
        string type;
        int status;
        string startTime;
        string endTime;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingSolidPowerTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingSolidPowerTaskArrayData &data);


    struct TimingSolidPowerRequestData
    {
        string sn;
        vector<TimingSolidPowerTaskArrayData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingSolidPowerRequestData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingSolidPowerRequestData &data);

    struct TimingSolidPowerTaskarray :TaskArrayFor0x99
    {
        vector<TimingSolidPowerTaskArrayData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingSolidPowerTaskarray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingSolidPowerTaskarray &data);

    struct TimingSolidPowerRequestInfo
    {
        Source source;
        vector<TimingSolidPowerTaskarray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingSolidPowerRequestInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingSolidPowerRequestInfo &data);

    struct SetSolidPowerStatusRelayStatusInfo
    {
        string type;
        int powerIndex;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSolidPowerStatusRelayStatusInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSolidPowerStatusRelayStatusInfo &data);

    struct SetSolidPowerStatusRelayStatus
    {
        vector<SetSolidPowerStatusRelayStatusInfo> relayStatus;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSolidPowerStatusRelayStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSolidPowerStatusRelayStatus &data);


    struct SetSolidPowerStatusTaskArray :TaskArrayFor0x99
    {
        SetSolidPowerStatusRelayStatus data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSolidPowerStatusTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSolidPowerStatusTaskArray &data);


    struct SetSolidPowerRequestDataInfo
    {
        Source source;
        vector<SetSolidPowerStatusTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSolidPowerRequestDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSolidPowerRequestDataInfo &data);

    struct SetSolidPowerRequestData
    {
        string sn;
        SetSolidPowerStatusRelayStatus data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetSolidPowerRequestData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetSolidPowerRequestData &data);


    struct ResponseTaskArrayFor0x99
    {
        string type;
        long orderId;
        int action;
        int errorCode;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ResponseTaskArrayFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ResponseTaskArrayFor0x99 &data);


    struct TimingSolidPowerResponseTaskArrayData
    {
        bool enable;
        vector<TimingSolidPowerTaskArrayData> relayPolicyTask;
        Source source;
        int orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingSolidPowerResponseTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingSolidPowerResponseTaskArrayData &data);

    struct TimingSolidPowerResponseTaskArray :ResponseTaskArrayFor0x99
    {

        TimingSolidPowerResponseTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingSolidPowerResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingSolidPowerResponseTaskArray &data);

    struct TimingSolidPowerResponseInfo
    {
        string currentTime;
        vector<TimingSolidPowerResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimingSolidPowerResponseInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimingSolidPowerResponseInfo &data);


    struct GetSolidPowerStatusTADataRelayStatus
    {
        string type;
        int powerIndex;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSolidPowerStatusTADataRelayStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSolidPowerStatusTADataRelayStatus &data);

    struct GetSolidPowerStatusTAData
    {
        vector<GetSolidPowerStatusTADataRelayStatus> relayStatus;
        Source source;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSolidPowerStatusTAData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSolidPowerStatusTAData &data);

    struct GetSolidPowerStatusTaskArray :ResponseTaskArrayFor0x99
    {
        GetSolidPowerStatusTAData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSolidPowerStatusTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSolidPowerStatusTaskArray &data);

    struct GetSolidPowerStatusResponseInfo
    {
        string currentTime;
        vector<GetSolidPowerStatusTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSolidPowerStatusResponseInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSolidPowerStatusResponseInfo &data);

    struct IsExistSolidPowerTaskArrayData
    {
        bool isExist;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IsExistSolidPowerTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IsExistSolidPowerTaskArrayData &data);

    struct IsExistSolidPowerTaskArray :ResponseTaskArrayFor0x99
    {
        IsExistSolidPowerTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IsExistSolidPowerTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IsExistSolidPowerTaskArray &data);

    struct IsExistSolidPowerResponseInfo
    {
        string currentTime;
        vector<IsExistSolidPowerTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const IsExistSolidPowerResponseInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IsExistSolidPowerResponseInfo &data);

    struct RelayPowerManualData
    {
        string type;
        int powerIndex;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerManualData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerManualData &data);
    struct  RelayPowerManualTaskArray
    {
        string type;
        long orderId;
        int action;
        vector<RelayPowerManualData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerManualTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerManualTaskArray &data);
    struct RelayPowerManualRequest
    {
        Source source;
        vector<RelayPowerManualTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerManualRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerManualRequest &data);
    struct RelayPowerManualInfo
    {
        string sn;
        vector<RelayPowerManualData> taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerManualInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerManualInfo &data);
    struct RelayPowerPolicyData
    {
        vector<string> cron;
        int powerIndex;
        string type;
        int status;
        string startTime;
        string endTime;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicyData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicyData &data);
    struct RelayPowerPolicyTaskArray
    {
        string type;
        long orderId;
        int action;
        vector<RelayPowerPolicyData> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicyTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicyTaskArray &data);
    struct RelayPowerPolicyRequest
    {
        Source source;
        vector<RelayPowerPolicyTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicyRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicyRequest &data);
    struct RelayPowerPolicyInfo
    {
        string sn;
        vector<RelayPowerPolicyData> taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicyInfo &data);
    struct RelayStatus
    {
        string type;
        int powerIndex;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayStatus &data);
    struct RelayPowerStatusData
    {
        vector<RelayStatus> relayStatus;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerStatusData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerStatusData &data);
    struct RelayPowerStatusTaskArray
    {
        string type;
        long orderId;
        int action;
        RelayPowerStatusData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerStatusTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerStatusTaskArray &data);
    struct RelayPowerStatusRequest
    {
        Source source;
        vector<RelayPowerStatusTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerStatusRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerStatusRequest &data);
    struct RelayPowerStatusInfo
    {
        string sn;
        RelayPowerStatusData taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerStatusInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerStatusInfo &data);
    struct RelayPowerStatusResponseData
    {
        Source source;
        vector<RelayStatus> relayStatus;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerStatusResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerStatusResponseData &data);
    struct RelayPowerStatusResponseTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        int errorCode;
        RelayPowerStatusResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerStatusResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerStatusResponseTaskArray &data);
    struct RelayPowerStatusResponse
    {
        vector<RelayPowerStatusResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerStatusResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerStatusResponse &data);
    struct RelayPowerPolicyResponseData
    {
        Source source;
        vector<RelayPowerPolicyData> relayPolicyTask;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicyResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicyResponseData &data);
    struct RelayPowerPolicyResponseTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        int errorCode;
        RelayPowerPolicyResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicyResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicyResponseTaskArray &data);
    struct RelayPowerPolicyResponse
    {
        vector<RelayPowerPolicyResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RelayPowerPolicyResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RelayPowerPolicyResponse &data);
}

namespace ns
{
    struct VideoStatusResponseData
    {
        bool enable;
        bool isScale;
        int offsetX;
        int offsetY;
        int videoMode;
        int videoSource;
        int orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoStatusResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoStatusResponseData &data);

    struct VideoStatusResponseTask :GetResponseTaskArray
    {
        VideoStatusResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoStatusResponseTask &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoStatusResponseTask &data);

    struct VideoStatusResponseInfo
    {
        string currentTime;
        vector<VideoStatusResponseTask> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoStatusResponseInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoStatusResponseInfo &data);

    struct VideoSetData
    {
        int videoSource;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoSetData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoSetData &data);

    struct VideoSetRequset
    {
        string sn;
        VideoSetData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoSetRequset &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoSetRequset &data);

    struct VideoSetTaskFor0x99 :TaskArrayFor0x99
    {
        VideoSetData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoSetTaskFor0x99 &data);

    struct VideoSetRequestFor0x99
    {
        Source source;

        vector<VideoSetTaskFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoSetRequestFor0x99 &data);

    struct PolicyVideoSetCondition
    {
        string cron;
        int source;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoSetCondition &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyVideoSetCondition &data);

    struct PolicyVideoSetData
    {
        bool enable;
        vector <PolicyVideoSetCondition> conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoSetData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyVideoSetData &data);

    struct PolicyVideoSetRequset
    {
        string sn;
        PolicyVideoSetData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoSetRequset &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyVideoSetRequset &data);

    struct PolicyVideoSetTaskFor0x99 :TaskArrayFor0x99
    {
        PolicyVideoSetData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoSetTaskFor0x99 &data);

    struct PolicyVideoSetRequestFor0x99
    {
        Source source;

        vector<PolicyVideoSetTaskFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoSetRequestFor0x99 &data);

    struct PolicyVideoStatusResponseData
    {
        vector <PolicyVideoSetCondition> conditions;
        bool enable;
        bool isScale;
        int offsetX;
        int offsetY;
        int videoMode;
        int videoSource;
        int orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoStatusResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyVideoStatusResponseData &data);

    struct PolicyVideoStatusResponseTask :GetResponseTaskArray
    {
        PolicyVideoStatusResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoStatusResponseTask &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyVideoStatusResponseTask &data);

    struct PolicyVideoStatusResponseInfo
    {
        string currentTime;
        vector<PolicyVideoStatusResponseTask> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyVideoStatusResponseInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyVideoStatusResponseInfo &data);
}

namespace ns
{
    struct ImmediatelyRebootTaskArrayData
    {
        string reason;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ImmediatelyRebootTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ImmediatelyRebootTaskArrayData &data);


    struct SetImmediatelyRebootTaskArray :TaskArrayFor0x99
    {
        ImmediatelyRebootTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetImmediatelyRebootTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetImmediatelyRebootTaskArray &data);

    struct SetImmediatelyRebootInfo
    {
        Source source;
        vector<SetImmediatelyRebootTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetImmediatelyRebootInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetImmediatelyRebootInfo &data);


    struct SetImmediatelyRebootData
    {
        string sn;
        ImmediatelyRebootTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetImmediatelyRebootData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetImmediatelyRebootData &data);




    struct SetTimingRebootTaskArrayDataInfo
    {
        vector<string>  cron;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingRebootTaskArrayDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingRebootTaskArrayDataInfo &data);

    struct SetTimingRebootTaskArrayDataConditions
    {
        vector<SetTimingRebootTaskArrayDataInfo>  conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingRebootTaskArrayDataConditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingRebootTaskArrayDataConditions &data);

    struct SetTimingRebootTaskArray :TaskArrayFor0x99
    {
        SetTimingRebootTaskArrayDataConditions data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingRebootTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingRebootTaskArray &data);

    struct SetTimingRebootInfo
    {
        Source source;
        vector<SetTimingRebootTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingRebootInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingRebootInfo &data);


    struct SetTimingRebootData
    {
        string sn;
        SetTimingRebootTaskArrayDataConditions data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetTimingRebootData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetTimingRebootData &data);


    struct GetTimingRebootResponseTaskArrayData
    {
        Source source;
        vector<SetTimingRebootTaskArrayDataInfo>  conditions;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingRebootResponseTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingRebootResponseTaskArrayData &data);


    struct GetTimingRebootResponseTaskArray :ResponseTaskArrayFor0x99
    {
        GetTimingRebootResponseTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingRebootResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingRebootResponseTaskArray &data);

    struct GetTimingRebootResponseData
    {
        Source source;
        vector<GetTimingRebootResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetTimingRebootResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetTimingRebootResponseData &data);


    struct ClearMediaTaskArrayData
    {
        int scope;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ClearMediaTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ClearMediaTaskArrayData &data);

    struct ClearMediaTaskArray :TaskArrayFor0x99
    {
        ClearMediaTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ClearMediaTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ClearMediaTaskArray &data);

    struct ClearMediaDataFor0x99
    {
        Source source;
        vector<ClearMediaTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ClearMediaDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ClearMediaDataFor0x99 &data);

    struct ClearMediaFor0x99
    {
        string sn;
        ClearMediaTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ClearMediaFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ClearMediaFor0x99 &data);


    struct SyncPlayTaskArrayDataFor0x99
    {
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SyncPlayTaskArrayDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SyncPlayTaskArrayDataFor0x99 &data);


    struct SyncPlayTaskArrayFor0x99 :TaskArrayFor0x99
    {
        SyncPlayTaskArrayDataFor0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SyncPlayTaskArrayFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SyncPlayTaskArrayFor0x99 &data);

    struct SyncPlayDataFor0x99
    {
        Source source;
        vector<SyncPlayTaskArrayFor0x99> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SyncPlayDataFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SyncPlayDataFor0x99 &data);

    struct SyncPlayFor0x99
    {
        string sn;
        SyncPlayTaskArrayDataFor0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SyncPlayFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SyncPlayFor0x99 &data);


    struct SyncPlayResponseData
    {
        bool enable;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SyncPlayResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SyncPlayResponseData &data);





    struct PolicySourceOutModeTaskArrayData
    {
        string currentSourceOutMode;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicySourceOutModeTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicySourceOutModeTaskArrayData &data);

    struct PolicySourceOutModeTaskArray :ResponseTaskArrayFor0x99
    {
        PolicySourceOutModeTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicySourceOutModeTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicySourceOutModeTaskArray &data);

    struct PolicySourceOutModeInfo
    {
        string currentTime;
        vector<PolicySourceOutModeTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicySourceOutModeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicySourceOutModeInfo &data);



    struct SetPolicySourceOutModeTaskArrayData
    {
        Source source;
        string currentSourceOutMode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetPolicySourceOutModeTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetPolicySourceOutModeTaskArrayData &data);


    struct SetPolicySourceOutModeTaskArray :TaskArrayFor0x99
    {
        SetPolicySourceOutModeTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetPolicySourceOutModeTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetPolicySourceOutModeTaskArray &data);


    struct SetPolicySourceOutModeInfo
    {
        Source source;
        vector<SetPolicySourceOutModeTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetPolicySourceOutModeInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetPolicySourceOutModeInfo &data);

    struct SetPolicySourceOutModeData
    {
        string sn;
        string currentSourceOutMode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetPolicySourceOutModeData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetPolicySourceOutModeData &data);


    struct GetNetworkCheckConfigs
    {
        string address;
        bool enable;
        int type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetNetworkCheckConfigs &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetNetworkCheckConfigs &data);

    struct GetNetworkCheckTaskArrayData
    {
        vector<GetNetworkCheckConfigs> networkConfigs;
        bool enable;
        long orderId;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetNetworkCheckTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetNetworkCheckTaskArrayData &data);

    struct GetNetworkCheckTaskArray :ResponseTaskArrayFor0x99
    {
        GetNetworkCheckTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetNetworkCheckTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetNetworkCheckTaskArray &data);

    struct GetNetworkCheckInfo
    {
        string currentTime;
        vector<GetNetworkCheckTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetNetworkCheckInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetNetworkCheckInfo &data);


    //struct SetNetworkCheckTaskArrayData
    //{
    //
    //};
    struct BatchLoginResponse
    {
        string sn;
        int errorCode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BatchLoginResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BatchLoginResponse &data);

    struct BatchLoginResponseInfo
    {
        vector<BatchLoginResponse> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BatchLoginResponseInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BatchLoginResponseInfo &data);



    struct ScreenAttributeInfos
    {
        string sn;
        int width;
        int height;
        int xCount;
        int yCount;
        vector<int> orders;
        int portNumber;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenAttributeInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenAttributeInfos &data);



    struct ProgramInfos
    {
        int statusCode;
        bool isSupportMd5Checkout = false;
        string thumbnailUrl;
        string identifier;
        string name;
        int source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ProgramInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ProgramInfos &data);


    struct GetProgramInfos
    {
        vector<ProgramInfos> programInfos;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetProgramInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetProgramInfos &data);

    struct SetNetWorkTaskArrayData
    {

        bool enable = true;
        vector<GetNetworkCheckConfigs> networkConfigs;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetNetWorkTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetNetWorkTaskArrayData &data);

    struct SetNetWorkTaskArray :TaskArrayFor0x99
    {
        SetNetWorkTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetNetWorkTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetNetWorkTaskArray &data);

    struct SetNetWorkInfo
    {
        Source source;
        vector<SetNetWorkTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetNetWorkInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetNetWorkInfo &data);

    struct SetNetWorkData
    {
        string sn;
        vector<GetNetworkCheckConfigs> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SetNetWorkData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SetNetWorkData &data);


    struct DownloadTerminalLogData
    {
        string sn;
        string fileName;
        string filePath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadTerminalLogData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadTerminalLogData &data);
    struct Sn
    {
        string sn;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Sn &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Sn &data);

    struct GetPlaylogPathResponse
    {
        vector<string> logList;
        string url;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetPlaylogPathResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetPlaylogPathResponse &data);


    struct DownloadFileInfo
    {
        string path;
        string fileName;
        long size;
        string localPath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadFileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadFileInfo &data);

    struct DownloadFileInfos
    {
        std::vector<ns::DownloadFileInfo> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadFileInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadFileInfos &data);

    struct FileProgress
    {
        int errorCode;
        long currentSize;
        long totleSize;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FileProgress &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FileProgress &data);

    struct UploadTerminalLogData
    {
        string sn;
        string fileName;
        string filePath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UploadTerminalLogData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UploadTerminalLogData &data);

    struct DownloadTerminalLogDataWithPublicNetResult
    {
        int status;
        std::string path;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadTerminalLogDataWithPublicNetResult& result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadTerminalLogDataWithPublicNetResult& result);

    struct DownloadTerminalLogDataWithPublicNetInfo
    {
        string url;
        string startDate;
        string endDate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadTerminalLogDataWithPublicNetInfo& data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadTerminalLogDataWithPublicNetInfo& data);

    struct DownloadTerminalLogDataWithPublicNet
    {
        string sn;
        DownloadTerminalLogDataWithPublicNetInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadTerminalLogDataWithPublicNet& data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadTerminalLogDataWithPublicNet& data);

    struct GetOssLinkInfoData
    {
        string ossKey;
        int expireTime;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetOssLinkInfoData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetOssLinkInfoData &data);

    struct StopFunctionData
    {
        string sn;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const StopFunctionData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, StopFunctionData &data);

    struct LogLinkData
    {
        string url;
        int status;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LogLinkData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LogLinkData &data);

}
namespace ns
{
    struct Segments;
    struct OpticalFailureInfo;
    struct PolicyBrightnessResponseConditions
    {
        int type;
        vector<string> cron;
        string startTime;
        string endTime;
        vector<int> args;
        vector<Segments> segments;
        OpticalFailureInfo opticalFailureInfo;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(nlohmann::json &j, const PolicyBrightnessResponseConditions &data);
    VIPLEXCOMMON_EXPORT void from_json(const nlohmann::json &j, PolicyBrightnessResponseConditions &data);

    struct SegmentsInt;
    struct PolicyBrightnessResponseSegmentConfig
    {
        vector<int> args;
        vector<SegmentsInt> segments;
        OpticalFailureInfoInt opticalFailureInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(nlohmann::json &j, const PolicyBrightnessResponseSegmentConfig &data);
    VIPLEXCOMMON_EXPORT void from_json(const nlohmann::json &j, PolicyBrightnessResponseSegmentConfig &data);

    struct DataResponse0x99
    {
        Source source;
        bool enable;
        vector<PolicyBrightnessResponseConditions> conditions;
        PolicyBrightnessResponseSegmentConfig segmentConfig;
        string timeStamp;
    };
    VIPLEXCOMMON_EXPORT void to_json(nlohmann::json &j, const DataResponse0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const nlohmann::json &j, DataResponse0x99 &data);

    struct PolicyBrightnessResponseTaskArray
    {
        string type;
        long orderId;
        int action;
        int status;
        short errorCode;
        DataResponse0x99 data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyBrightnessResponseTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyBrightnessResponseTaskArray &data);

    struct PolicyBrightnessResponseData
    {
        string currentTime;
        vector<PolicyBrightnessResponseTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PolicyBrightnessResponseData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PolicyBrightnessResponseData &data);



    struct EnvironmentBrightnessParameterTaskArrayData
    {
        int period;
        int count;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EnvironmentBrightnessParameterTaskArrayData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EnvironmentBrightnessParameterTaskArrayData &data);

    struct EnvironmentBrightnessParameterTaskArray
    {
        std::string type;
        long orderId;
        int action;
        ns::EnvironmentBrightnessParameterTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EnvironmentBrightnessParameterTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EnvironmentBrightnessParameterTaskArray &data);



    struct EnvironmentBrightnessParameter 
    {
        Source source;
        vector<EnvironmentBrightnessParameterTaskArray> taskArray;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EnvironmentBrightnessParameter &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EnvironmentBrightnessParameter &data);




    struct EnvironmentBrightnessParameterResData
    {
        string sn;
        EnvironmentBrightnessParameterTaskArrayData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EnvironmentBrightnessParameterResData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EnvironmentBrightnessParameterResData &data);














}
namespace ns
{
    struct CompanyInfo
    {
        string company = "NovaStar";
        string phone = "029-68216000";
        string email = "hr@novastar.tech";
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CompanyInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CompanyInfo &data);
}

namespace ns
{
    struct APIContent
    {
        std::string devLang;
        std::string sdkVersion;
        std::string sn;
        std::string terminalInfo;
        std::string productType;
        std::string productVersion;
        std::string credentials;
        std::string apiName;
        std::string data;
        std::string result;
        int64_t callTime = 0;
        int64_t responseTime = 0;
        uint16_t code = 0;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const APIContent &apiContent);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, APIContent &apiContent);

    struct ScreenLogInfo
    {
        string screenLogUrl;
        string screenLogFileName;
        long long screenLogTime;
        long long screenLogFileSize;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenLogInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenLogInfo &data);
}

namespace ns
{

    struct ReceiveCardRegionInfoData
    {
        int senderIndex;
        int portIndex;
        int connectIndex;
        int X;
        int Y;
        int XInPort;
        int YInPort;
        int width;
        int height;
        int rowIndexInScreen;
        int colIndexInScreen;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ReceiveCardRegionInfoData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ReceiveCardRegionInfoData &data);


    struct ReceiveCardRegionInfo
    {
        vector<ReceiveCardRegionInfoData> receiveCardRegionInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ReceiveCardRegionInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ReceiveCardRegionInfo &data);


    struct DeviceInfo
    {
        int deviceIndex;
        int deviceType;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DeviceInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DeviceInfo &data);

    struct ReceiveCardMonitorInfo
    {
        float temprature;
        float voltage;
        vector<DeviceInfo> deviceMapList;
        int deviceWorkState;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ReceiveCardMonitorInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ReceiveCardMonitorInfo &data);

    struct CabinDoorUpdateInfo
    {
        bool isDoorOpen;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CabinDoorUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CabinDoorUpdateInfo &data);


    struct FansUpdateInfoData
    {
        std::map<int, float> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FansUpdateInfoData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FansUpdateInfoData &data);




    struct FansUpdateInfo
    {
        FansUpdateInfoData fansMonitorInfoCollection;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const FansUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, FansUpdateInfo &data);


    struct HumidityUpdateInfo
    {
        int humidity;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const HumidityUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, HumidityUpdateInfo &data);


    struct ModuleStatus
    {
        int deviceWorkStatus;
        int busIndex;
        int flashIndex;
        int rowIndex;
        int colIndex;
        float temperature;
        float voltage;
        long workTime;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ModuleStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ModuleStatus &data);

    struct ModuleUpdateInfoData
    {
        std::map<int, ModuleStatus> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ModuleUpdateInfoData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ModuleUpdateInfoData &data);


    struct ModuleUpdateInfo
    {
        ModuleUpdateInfoData moduleMonitorInfoCollection;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ModuleUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ModuleUpdateInfo &data);


    struct PowerUpdateInfoData
    {
        std::map<int, int> data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerUpdateInfoData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerUpdateInfoData &data);

    struct PowerUpdateInfo
    {
        PowerUpdateInfoData powerMonitorInfoCollection;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PowerUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PowerUpdateInfo &data);

    struct SmokeUpdateInfo
    {
        bool smoke;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SmokeUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SmokeUpdateInfo &data);

    struct SocketCableStatus
    {
        bool isCableOK;
        bool cableType;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SocketCableStatus &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SocketCableStatus &data);



    struct SocketCableUpdateInfo
    {
        std::map<int, vector<SocketCableStatus>> socketCableMonitorInfoList;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SocketCableUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SocketCableUpdateInfo &data);

    struct TemperatureUpdateInfo
    {
        int temprature;
        bool isUpdate;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TemperatureUpdateInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TemperatureUpdateInfo &data);


    struct MonitorCardMonitorInfo
    {
        CabinDoorUpdateInfo cabinDoorUpdateInfo;
        FansUpdateInfo fansUpdateInfo;
        HumidityUpdateInfo humidityUpdateInfo;
        ModuleUpdateInfo moduleUpdateInfo;
        PowerUpdateInfo powerUpdateInfo;
        SmokeUpdateInfo smokeUpdateInfo;
        SocketCableUpdateInfo socketCableUpdateInfo;
        TemperatureUpdateInfo temperatureUpdateInfo;
        vector<DeviceInfo> deviceMapList;
        int deviceWorkState;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const MonitorCardMonitorInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, MonitorCardMonitorInfo &data);


    struct ScreenMonitorDataInfo
    {
        ReceiveCardMonitorInfo receiveCardMonitorInfo;
        MonitorCardMonitorInfo monitorCardMonitorInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenMonitorDataInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenMonitorDataInfo &data);

    struct ScreenMonitorData
    {
        vector<ScreenMonitorDataInfo> screenMonitorData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenMonitorData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenMonitorData &data);




    struct GetLoraInfos
    {
        bool exist;
        float frequency;
        float power;
        int version;
        float channel;
        int baudRate;
        float transSpeed;
        int workState;
        int modelNum;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetLoraInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetLoraInfos &data);

    struct Existed
    {
        bool existed;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Existed &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Existed &data);


    struct ReceiveCardInfo
    {
        int status;
        ReceiveCardRegionInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ReceiveCardInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ReceiveCardInfo &data);

    struct ReceiveCardMonitorInfos
    {
        int status;
        ScreenMonitorData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ReceiveCardMonitorInfos &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ReceiveCardMonitorInfos &data);

    struct GetLoraInfo
    {
        int status;
        GetLoraInfos data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetLoraInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetLoraInfo &data);

    struct GetSensorInfo
    {
        int status;
        SensorResponseData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetSensorInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetSensorInfo &data);


    struct GetMobileInfo
    {
        int status;
        Existed data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetMobileInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetMobileInfo &data);


    struct GetScreenDeviceInfo
    {
        ReceiveCardInfo receiveCardinfo;
        ReceiveCardMonitorInfos receiveCardMonitorInfo;
        GetLoraInfo getLoraInfo;
        GetSensorInfo getSensorInfo;
        GetMobileInfo getMobileInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const GetScreenDeviceInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, GetScreenDeviceInfo &data);
}

namespace ns 
{
    struct BurtPointossAuthorizationData
    {
        string accessId;
        string signature;
        string expire;
        string host;
        string dir;
        string policy;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BurtPointossAuthorizationData &data);
    struct BurtPointossAuthorization
    {
        vector<int> status;
        BurtPointossAuthorizationData data;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BurtPointossAuthorization &data);
}

namespace ns
{
    struct AudioListArray
    {
        int id;
        int mid = 0;
        std::string name;
        std::string dataSource;
        std::string originalDataSource;
        int64_t duration = -1;
        bool enable = true;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AudioListArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AudioListArray &data);
    struct AudioListInfo
    {
        std::string playPolicy = "ORDER";
        vector<AudioListArray> audioList;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AudioListInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AudioListInfo &data);
    struct AudioListSingelMedia
    {
        std::string audioFileName;
        AudioListInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AudioListSingelMedia &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AudioListSingelMedia &data);
    struct AudioList 
    {
        int programID;
        vector<AudioListSingelMedia> taskInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AudioList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AudioList &data);
}



namespace ns
{
    struct DownloadTerminalLogWithPublicNetInfo
    {
        std::string url;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadTerminalLogWithPublicNetInfo& data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadTerminalLogWithPublicNetInfo& data);
    struct DownloadTerminalLogWithPublicNet
    {
        string sn;
        DownloadTerminalLogWithPublicNetInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadTerminalLogWithPublicNet& data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadTerminalLogWithPublicNet& data);

    struct DownloadTerminalLogWithPublicNetInfoResult
    {
        int status = -1;
        std::string path;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DownloadTerminalLogWithPublicNetInfoResult& data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DownloadTerminalLogWithPublicNetInfoResult& data);


    struct TransferProgramData
    {
        string sn;
        string name;
        int width;
        int height;
        ns::ScenePage pageInfo;
        ns::SendProgramFilePaths sendProgramFilePaths;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TransferProgramData& data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TransferProgramData& data);

    struct TransferProgramPagesData
    {
        string sn;
        string name;
        int width;
        int height;
        std::vector<SceneItems> sceneItems;
        ns::SendProgramFilePaths sendProgramFilePaths;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TransferProgramPagesData& data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TransferProgramPagesData& data);



    
}


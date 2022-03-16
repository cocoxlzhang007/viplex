
#include <iostream>

using namespace std;

#include "viplexcoreasync.h"
#include <thread>
#include <list>

bool g_bAPIReturn = false;
uint16_t g_loginCode = 0;
std::string g_sn = "BZSA58502N0140004965"; //BZSA79353N1310006847
std::string g_port = "16603";
void callBack(const uint16_t code, const char *data)
{
    g_loginCode = code;
    cout << "ViplexCore Demo code:" << code << endl;
    cout << "ViplexCore Demo data:" << data << endl;
    g_bAPIReturn = true;
}

void waitAPIReturn() 
{
    while (!g_bAPIReturn)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    g_bAPIReturn = false;
}
std::string appendParam(const string &src, const string &key, const string &content)
{
    auto target = src;
    target.insert(src.find(key) + key.length(), content);
    return target;
}
std::string appendSN(const string &src)
{
    return appendParam(src, "\"sn\":\"", g_sn);
}
int main(int argc, char* argv[])
{

		if (argc == 2)
		{
			g_port = argv[1];
			cout << "input device g_port: " << g_port << endl;
		}

		string sdkRootDir = __FILE__;
		while (sdkRootDir.find("\\") != std::string::npos)
		{
			sdkRootDir[sdkRootDir.find("\\")] = '/';
		}
		sdkRootDir = sdkRootDir.substr(0, sdkRootDir.rfind("/") + 1) + "temp";

		std::cout << "nvInit(sdk 初始化)" << endl;
		int ret = -1;

		string credentials = "{\"company\":\"NovaStar\",\"phone\":\"029-68216000\",\"email\":\"hr@novastar.tech\"}";
		ret = ViplexCoreAsync::nvInit(sdkRootDir.c_str(), credentials.c_str());
		string initdata = "{\"publicModule\":true,\"encrypt\":false,\"certificatePath\":\"E:/vplayergit/vplayer301/viplexcore_pubtmp/viplexcore/build/RelWithDebInfo/bin/cert\",\"port\":16603,\"httpserverUrl\":\"http://192.168.1.100:8080\",\"httpserverLocalPath\":\"E:/httpserverpath\"}";
		initdata = initdata.replace(initdata.find("16603"), 5, g_port);
		cout << "replace init data: " << initdata << endl;
		ViplexCoreAsync::nvInitPublicNetAsync(initdata.c_str(), [=](const uint16_t code, const char* data) {
			std::cout << "\n connect device: " << data << endl;
			}, [=](const uint16_t code, const char* data) {
				std::cout << "\n disconnect device: " << data << endl;
			});

		bool flag = false;
		while (!flag)
		{

			ViplexCoreAsync::nvGetOnlineDevicesAsync([&](const uint16_t code, const char* data) {
				std::cout << "\n nvGetOnlineDevicesAsync device: " << data << endl;
				string strDe4vices = data;
				if (strDe4vices.find(g_sn) != string::npos)
				{
					std::cout << "nvGetOnlineDevicesAsync device: " << g_sn << "   is online" << endl;
					flag = true;
					return;
				}
				});
			this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
		
		std::cout << "\n ViplexCore Demo nvLoginAsync(登录) begin... ";
		std::string loginParam = "{\"sn\":\"\",\"username\":\"admin\",\"rememberPwd\":1,\"password\":\"123456\",\"loginType\":5}";
		ViplexCoreAsync::nvLoginAsync(appendSN(loginParam).c_str(), callBack);
		waitAPIReturn();
		if (g_loginCode != 0)
		{
			std::cout << "ViplexCore Demo nvLoginAsync(登录) 失败";
			return 0;
		}

		std::cout << "\n ViplexCore Demo nvGetVolumeAsync(获取音量) begin... " << endl;
		ViplexCoreAsync::nvGetVolumeAsync(appendSN("{\"sn\":\"\"}").c_str(), callBack);
		waitAPIReturn();

		std::cout << "ViplexCore Demo nvStopPublicNetAsync(停止公网服务) begin... " << endl;
		ViplexCoreAsync::nvStopPublicNetAsync(callBack);
		waitAPIReturn();
		return 0;
}


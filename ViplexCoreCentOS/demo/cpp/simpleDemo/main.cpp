
#include <iostream>

using namespace std;

#include "exportviplexcoreasync.h"
#include <thread>

bool g_bAPIReturn = false;
uint16_t g_loginCode = 0;
std::string g_sn = "BZSA79353N1310006847"; //BZSA07313J0350000997
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
    string sdkRootDir = __FILE__;
    while (sdkRootDir.find("\\") != std::string::npos)
    {
        sdkRootDir[sdkRootDir.find("\\")] = '/';
    }
    sdkRootDir = sdkRootDir.substr(0, sdkRootDir.rfind("/") + 1) + "temp";

    string createProgram = "{\"name\":\"Demo\",\"width\":500,\"height\":500,\"tplID\":1,\"winInfo\":{\"height\":100,\"width\":100,\"left\":0,\"top\":0,\"zindex\":0,\"index\":0}}";
    string editProgram = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目\",\"widgetContainers\":[{\"audioGroup\":\"\",\"backgroundColor\":\"#00000000\",\"backgroundDrawable\":\"\",\"contents\":{\"widgetGroups\":[],\"widgets\":[{\"id\":1,\"enable\":true,\"repeatCount\":1,\"layout\":{\"y\":\"0\",\"height\":\"100%\",\"x\":\"0\",\"width\":\"100%\"},\"backgroundColor\":\"#00000000\",\"backgroundDrawable\":\"\",\"backgroundMusic\":\"\",\"zOrder\":0,\"displayRatio\":\"FULL\",\"outAnimation\":{\"type\":0,\"duration\":0},\"dataSource\":\"ad4e2c49d8f6d37c90a99db6bc174052.png\",\"type\":\"PICTURE\",\"constraints\":[{\"cron\":[],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"border\":{\"borderThickness\":\"2px,3px,5%,6\",\"style\":0,\"backgroundColor\":\"#ff000000\",\"name\":\"border\",\"cornerRadius\":\"2%\",\"effects\":{\"headTailSpacing\":\"\",\"isHeadTail\":false,\"speedByPixelEnable\":true,\"speed\":0,\"animation\":\"CLOCK_WISE\"}},\"inAnimation\":{\"type\":0,\"duration\":1000},\"duration\":3605000,\"name\":\"test.png\",\"originalDataSource\":\"./test.png\",\"functionStorage\":\"\",\"isSupportSpecialEffects\":false}]},\"enable\":true,\"id\":1,\"itemsSource\":\"\",\"layout\":{\"height\":\"1.0\",\"width\":\"1.0\",\"x\":\"0.0\",\"y\":\"0.0\"},\"name\":\"widgetContainers1\",\"pickCount\":0,\"pickPolicy\":\"ORDER\",\"zOrder\":0}]}}";
    string genrateProgram = "{\"programID\":1,\"outPutPath\":\"/\",\"mediasPath\":[{\"oldPath\":\"test\",\"newPath\":\"test\"}]}";
    genrateProgram = appendParam(genrateProgram, "\"outPutPath\":\"", sdkRootDir);
    string trasfromProgram = "{\"sn\":\"\",\"iconPath\": \"\",\"iconName\": \"\",\"sendProgramFilePaths\": {\"programPath\": \"/program1\",\"mediasPath\": {\"./test.png\": \"test.png\"}},\"programName\": \"program1\",\"deviceIdentifier\": \"Demo\",\"startPlayAfterTransferred\": true,\"insertPlay\": true}";
    trasfromProgram = appendSN(trasfromProgram);
    trasfromProgram = appendParam(trasfromProgram, "\"programPath\": \"", sdkRootDir);
	
	bool bTestVideo = false;
    if (true)
    {
        editProgram = "{ \"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"Demo\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z 8:00\",\"startTime\":\"1970-01-01T00:00:00Z 8:00\"}],\"duration\":5000,\"dataSource\":\"219c7dd3260d6bf98ebf61b6da440ffd.avi\",\"type\":\"VIDEO\",\"name\":\"test.vai\",\"originalDataSource\":\"./test.avi\"}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
        genrateProgram = "{\"programID\":1,\"outPutPath\":\"/\",\"mediasPath\":[{\"oldPath\":\"test\",\"newPath\":\"test\"}]}";
        genrateProgram = appendParam(genrateProgram, "\"outPutPath\":\"", sdkRootDir);
        trasfromProgram = "{\"sn\":\"\",\"iconPath\": \"\",\"iconName\": \"\",\"sendProgramFilePaths\": {\"programPath\": \"/program1\",\"mediasPath\": {\"./test.avi\": \"test.avi\"}},\"programName\": \"program1\",\"deviceIdentifier\": \"Demo\",\"startPlayAfterTransferred\": true,\"insertPlay\": true}";
        trasfromProgram = appendSN(trasfromProgram);
        trasfromProgram = appendParam(trasfromProgram, "\"programPath\": \"", sdkRootDir);
    }
    
    bool bTestText = false;
    if (bTestText)
    {
        editProgram = "{\"programID\":1,\"pageID\":1,\"pageInfo\":{\"name\":\"节目\",\"widgetContainers\":[{\"contents\":{\"widgets\":[{\"constraints\":[{\"cron\":[\"0 0 0 ? * 1,2,3,4,5,6,7\"],\"endTime\":\"4017-12-30T23:59:59Z+8:00\",\"startTime\":\"1970-01-01T00:00:00Z+8:00\"}],\"duration\":5000,\"metadata\":{\"content\":{\"autoPaging\":true,\"backgroundMusic\":{\"duration\":0,\"isTextSync\":false},\"displayStyle\":{\"scrollAttributes\":{\"effects\":{\"animation\":\"MARQUEE_LEFT\",\"speed\":3}},\"type\":\"SCROLL\"},\"paragraphs\":[{\"backgroundColor\":\"#00000000\",\"horizontalAlignment\":\"CENTER\",\"letterSpacing\":0,\"lineSpacing\":0,\"lines\":[{\"segs\":[{\"content\":\"简体繁體日本語한국어.English123\"}]}],\"verticalAlignment\":\"CENTER\"}],\"textAttributes\":[{\"backgroundColor\":\"#ff000000\",\"attributes\":{\"font\":{\"family\":[\"Arial\"],\"isUnderline\":false,\"size\":20,\"style\":\"NORMAL\"},\"letterSpacing\":0,\"textColor\":\"#ffff0000\"}}]}},\"name\":\"text\",\"type\":\"ARCH_TEXT\"}]},\"id\":1,\"name\":\"widgetContainers1\"}]}}";
        trasfromProgram =
            "{\"sn\": \"\",\"iconPath\": \"\",\"iconName\": \"\",\"sendProgramFilePaths\": {\"programPath\": \"/program1\",\"mediasPath\": {}},\"programName\": \"program1\",\"deviceIdentifier\": \"Demo\",\"startPlayAfterTransferred\": true,\"insertPlay\": true}";
        trasfromProgram = appendSN(trasfromProgram);
        trasfromProgram = appendParam(trasfromProgram, "\"programPath\": \"", sdkRootDir);
    }

    std::cout << "nvInit(sdk 初始化)" << endl;
    int ret = -1;

    string credentials = "{\"company\":\"NovaStar\",\"phone\":\"029-68216000\",\"email\":\"hr@novastar.tech\"}";
    ret = nvInit(sdkRootDir.c_str(), credentials.c_str());


    std::cout << "\n ViplexCore Demo nvSearchTerminalAsync(搜索) begin..." << endl;
    nvSearchTerminalAsync(callBack);
    this_thread::sleep_for(std::chrono::milliseconds(3000));
    g_bAPIReturn = false;

    std::cout << "\n ViplexCore Demo nvLoginAsync(登录) begin... ";
    std::string loginParam = "{\"sn\":\"\",\"username\":\"admin\",\"rememberPwd\":1,\"password\":\"123456\",\"loginType\":0}";
    nvLoginAsync(appendSN(loginParam).c_str(), callBack);
    waitAPIReturn();
    if (g_loginCode != 0)
    {
        std::cout << "\n ViplexCore Demo nvLoginAsync(登录) 失败！";
        return 0;
    }

    std::cout << "\n ViplexCore Demo nvCreateProgramAsync(创建节目) begin... " << endl;
    nvCreateProgramAsync(createProgram.c_str(), callBack);
    waitAPIReturn();


    string requestDatapath = "{\"filePath\":\"./test.png\"}";
    std::cout << "\n ViplexCore Demo nvGetFileMD5Async(获取MD5) begin... " << endl;
    nvGetFileMD5Async(requestDatapath.c_str(), callBack);
    waitAPIReturn();

    std::cout << "\n ViplexCore Demo nvSetPageProgramAsync(编辑节目) begin... " << endl;
    nvSetPageProgramAsync(editProgram.c_str(), callBack);
    waitAPIReturn();

    std::cout << "\n ViplexCore Demo nvMakeProgramAsync(生成节目) begin... " << endl;
    nvMakeProgramAsync(genrateProgram.c_str(), callBack);
    waitAPIReturn();

    std::cout << "\n ViplexCore Demo nvStartTransferProgramAsync(发送节目) begin... " << endl;
    nvStartTransferProgramAsync(trasfromProgram.c_str(), callBack);
    this_thread::sleep_for(std::chrono::milliseconds(10000));
    g_bAPIReturn = false;

    std::cout << "\n ViplexCore Demo nvGetProgramInfoAsync(获取节目信息) begin... " << endl;
    nvGetProgramInfoAsync(appendSN("{\"sn\":\"\"}").c_str(), callBack);
    waitAPIReturn();

    std::cout << "\n ViplexCore Demo nvSetVolumeAsync(设置音量) begin... " << endl;
    nvSetVolumeAsync(appendSN("{\"sn\":\"\",\"volumeInfo\":{\"ratio\":60.0}}").c_str(), callBack);
    waitAPIReturn();

    std::cout << "\n ViplexCore Demo nvGetVolumeAsync(获取音量) begin... "<< endl;
    nvGetVolumeAsync(appendSN("{\"sn\":\"\"}").c_str(), callBack);
    waitAPIReturn();

}


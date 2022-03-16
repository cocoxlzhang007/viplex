#pragma once
#include "viplexcommon/interface/viplexerror.h"
#include <iostream>
#include <string>
#include <functional>
#include "viplexcommon/jsonserializer/protocoljson.h"

using namespace std;

struct ViplexRequestData
{
    uint16_t what= 0;
    uint16_t type= 0;
    uint8_t action= 0;
    uint16_t param= 0;
    string data;
    string sn;
	string ip;
    int loginType = 0;//0：登陆屏体管理 1：登陆到系统设置 2：登陆到诊断模块 3：LCT登录
    ViplexRequestData(): what(), type(){}
	ViplexRequestData(uint16_t what, uint8_t action, string sn, string data = "")
		: what(what)
		, action(action)
		, sn(sn)
		, data(data)
	{}
	ViplexRequestData(uint16_t what, string sn, string data = "")
		: what(what)
		, sn(sn)
		, data(data)
	{}
};

//using ViplexCallback = std::function<void(const uint16_t, const std::string &)>;
using ViplexCallback = std::function<void(const uint16_t, const char *)>;
using ViplexRequest = std::function<void(const string &data, ViplexCallback)>;

class IViplexRequester
{
public:
    virtual ~IViplexRequester(){}
    virtual void request(const ViplexRequestData &reqData, ViplexCallback callback) = 0;
};

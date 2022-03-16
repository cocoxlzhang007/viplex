#pragma once
#include <string>
#include "singleheader/json.hpp"
#include "protocoljson.h"
#include <QtCore/QMetaType>
#include <QtCore/QVariant>
#include "viplexcommon/viplexcommon_global.h"


using namespace std;
using nlohmann::json;


namespace ns {
    VIPLEXCOMMON_EXPORT void to_json(json& j, const std::string &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, std::string &data);

    struct TaskArrayFor0x99
    {
        string type;
        long orderId;
        int action;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TaskArrayFor0x99 &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TaskArrayFor0x99 &data);
}

namespace ns {
    //服务器地址请求信息
    struct HostData
    {
        string url;       //访问的服务器地址
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const HostData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, HostData &data);
}
Q_DECLARE_METATYPE(ns::HostData);

namespace ns {

    //矩形区域信息
    struct Layout
    {
        int x;
        int y;
        int width;
        int height;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Layout &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Layout &data);

    //播放显示区域（协议传输的是字符串，因此这里用字符串对象进行接收）
    struct DisplayRect
    {
        string x = "0";
        string y = "0";
        string width = "400";
        string height = "400";
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const DisplayRect &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DisplayRect &data);
}
Q_DECLARE_METATYPE(ns::DisplayRect*);


namespace ns
{
    struct OffSetInfo
    {
        int x;
        int y;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const OffSetInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, OffSetInfo &data);
}
//文本媒体
namespace ns {
    ///播放媒体挂件

        //图片特效
    struct  Animation
    {
        int type = 0;
        long duration = 0;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const Animation &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Animation &data);

    //时间约束
    struct Constraint
    {
        string startTime = "1970-01-01T00:00:00Z+8:00";     //开始时间（只含时分秒）
        std::vector<string> cron = { "0 0 0 ? * 1,2,3,4,5,6,7" };//时间约束的CRON表达式
        string endTime = "4017-12-30T23:59:59Z+8:00";     //结束时间（只含时分秒）
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Constraint &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Constraint &data);

    struct  WidgetLayout
    {
        string x = "0";
        string y = "0";
        string width = "100%";
        string height = "100%";
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const WidgetLayout &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WidgetLayout &data);

};
Q_DECLARE_METATYPE(ns::Animation);
//Q_DECLARE_METATYPE(ns::Widget);


namespace ns {

    //字体
    struct  CustomFont
    {
        std::vector<string> family = { "Arial" };
        string style = "NORMAL";
        int size = 16;
        bool isUnderline = false;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CustomFont &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CustomFont &data);

    struct ColorfulTextEffect
    {
        string type;
        std::vector<std::string> colors;
        string texture;
        string tempTexturePath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ColorfulTextEffect &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ColorfulTextEffect &data);
    //文字属性
    struct TextProperty
    {
        string backgroundColor = "#00FFFFFF";
        string textColor = "#FF0000";
        CustomFont font;
        bool shadowEnable = false;
        int shadowRadius = 10;
        int shadowDx = 2;
        int shadowDy = 0;
        string shadowColor = "#00ff00";
        bool strokeEnable = false;
        int strokeWidth = 0;
        int letterSpacing = 0;
        ColorfulTextEffect effects;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TextProperty &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TextProperty &data);

    struct RssTextAttribute
    {
        TextProperty title;
        TextProperty pubTime;
        TextProperty body;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RssTextAttribute &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RssTextAttribute &data);

    //文本属性
    struct TextAttribute
    {
        int key = 1;
        TextProperty textInfo;
        //TextProperty body;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TextAttribute &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TextAttribute &data);


    //文本片段
    struct Seg
    {
        int attributeKey = 1; //对应的文本属性key
        string  content = ""; //要显示的内容
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Seg &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Seg &data);

    //文本行
    struct Line
    {
        std::vector<Seg> segs;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Line &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Line &data);
    //文本段落
    struct  Paragraph
    {
        string  verticalAlignment;
        string horizontalAlignment;
        string backgroundColor = "#000000FF";
        int lineSpacing = 0;
        int letterSpacing = 0;
        std::vector<Line> lines;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Paragraph &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Paragraph &data);


    //页面切换效果描述
    struct PageSwitchAttributes
    {
        Animation inAnimation;
        int remainDuration = 10000;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PageSwitchAttributes &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PageSwitchAttributes &data);

    struct ScrollEffect
    {
        float speed = 1;
        //MoveType moveType = MoveType::MARQUEE_LEFT;
        string animation = "MARQUEE_LEFT ";
        string headTailSpacing = "0";
        bool isHeadTail = true;
        bool speedByPixelEnable = false;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScrollEffect &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScrollEffect &data);

    struct ScrollAttributes
    {
        ScrollEffect effecs;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScrollAttributes &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScrollAttributes &data);

    struct ScrollAttribute
    {
        ScrollAttributes scrollAttributes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScrollAttribute &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScrollAttribute &data);

    struct TextOffset
    {
        int x = 0;
        int y = 0;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TextOffset &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TextOffset &data);

    //图片组播放方式
    struct DisplayStyle
    {
        //SwitchingType type = SwitchingType::SCROLL;
        string type = "PAGE_SWITCH";
        bool singleLine = false;
        PageSwitchAttributes pageSwitchAttributes;
        ScrollAttributes scrollAttributes;
        //TextOffset offset;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DisplayStyle &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DisplayStyle &data);

    struct BackgroundMusic
    {
        bool isTextSync = false;
        int duration = 0;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BackgroundMusic &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BackgroundMusic &data);

    struct RichTextContent
    {
        DisplayStyle displayStyle;
        std::vector<TextAttribute> textAttributes;
        bool autoPaging = true;
        std::vector<Paragraph> paragraphs;
        BackgroundMusic baskgroundMusic;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const RichTextContent &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RichTextContent &data);
    //富文本
    struct RichTextInfo
    {
        string itemSource = "";
        RichTextContent content;
        string VerTextAlignment = "CENTER";
        string HorTextAlignment = "CENTER";
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RichTextInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RichTextInfo &data);
}


namespace ns {

    //RSS媒体
    struct  RSSMetaData
    {
        long updatePeriod = 60000;
        bool titleEnable = true;
        bool pubTimeEnable = true;
        bool bodyEnable = true;
        bool bodyImageEnable = true;
        RssTextAttribute textAttributes;
        DisplayStyle displayStyle;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RSSMetaData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RSSMetaData &data);
}


namespace ns {

    //流媒体
    struct  StreamMediaData
    {
        string source;
        string protocolType;
        string videoType;
        int volume = 10000;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const StreamMediaData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, StreamMediaData &data);
    struct StreamMetadata
    {
        string subType = "STREAM";//流媒体
        StreamMediaData modelData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const StreamMetadata &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, StreamMetadata &data);
}

namespace ns {

    struct NtpData
    {
        bool enable;
        string server;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const NtpData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, NtpData &data);
}

namespace ns
{
    struct SolidText
    {
        std::string text;
        TextProperty textAttributes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SolidText &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SolidText &data);
}

namespace ns
{
    //数字时钟
    struct DigitalClock
    {
        std::string zone;
        std::string gmt;
        std::string regular;
        std::vector<string> weekTemplates;
        std::vector<string> suffixTemplates;
        SolidText solidText;
        //bool isDisplayMilliseconds = false;
        TextProperty textAttributes;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DigitalClock &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DigitalClock &data);
}

namespace ns
{
    struct Units
    {
        std::string timerName;
        std::string zero;
        std::string singular;
        std::string plural;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Units &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Units &data);

    //计时媒体
    struct CountTimer
    {
        std::string regular;

        std::string regularNew;//判断单位单复数

        std::vector<Units> units;

        SolidText solidText;
        int64_t  targetDateTime;
        std::string countType = "COUNT_DOWN";
        bool isDisplayMilliseconds = false;//是否显示秒
        TextProperty textAttributes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CountTimer &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CountTimer &data);
}

namespace ns
{
    //简单天气:区域
    struct Area
    {
        std::string country = "中国";
        std::string province = "陕西省";
        std::string city = "西安";
        std::string county = "西安";
        std::string cityCode = "CN101110101";
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Area &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Area &data);
}
namespace ns
{
    //简单天气:播放效果
    struct Effects
    {
        string animation = "MARQUEE_LEFT";
        float speed = 3.0;
        bool speedByPixelEnable = false;
        bool isHeadTail = true;
        std::string headTailSpacing = "100";
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Effects &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Effects &data);
}


namespace ns
{
    //简单天气
    struct SimpleWeather
    {
        Area area;
        int weatherSource = 1;
        std::string language = "zh-cn";
        std::string cityNewCode;
        std::string windSpeedUnit = "m";
        std::string windType = "wind_sc";
        string temperatureUnit = "Celsius";
        bool isShowUnit = true;
        std::string regular = "天气:$w\n温度:$t\n风力:$b级\n当前温度:$c\n湿度:$h";
        bool isShowInOneLine = false;
        long refreshPeriod = 300000;
        Effects effects;
        TextProperty textAttributes;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SimpleWeather &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SimpleWeather &data);
}

namespace ns
{
    //实时媒体布局样式
    struct LayoutStyles
    {
        int type;//布局样式类型，0：间距 1:自定义标签，2：数值，3：单位，4：数值+单位
        std::string horizontalAlignment; //对齐方式
        std::string verticalAlignment = "VCENTER";//垂直对齐方式
        int proportion; //范围
    };
    VIPLEXCOMMON_EXPORT void to_json(json &j, const LayoutStyles &data);
    VIPLEXCOMMON_EXPORT void from_json(const json&j, LayoutStyles &data);
    //媒体内容
    struct RegularContents
    {
        std::string key; //占位符
        std::string unit;//对应数值的单位
        int type;//对应不同单位的换算类型
        int compension;//补偿值
        std::vector<string> mediaTemplates; //风向
    };
    VIPLEXCOMMON_EXPORT void to_json(json &j, const RegularContents &data);
    VIPLEXCOMMON_EXPORT void from_json(const json&j, RegularContents &data);
    //实时媒体：温度
    struct RtMedia
    {
        long updatePeriod = 10000;
        std::string regular;
        std::string temperatureUnit = "Celsius";//默认摄氏度
        int temperatureCompensation = 0;
        SolidText solidText;
        TextProperty textAttributes; //固定文本属性，标签文本属性
        TextProperty valueTextAttributes;//数值文本属性
        TextProperty unitTextAttributes;//单位文本属性
        //2019-03-19添加
        DisplayStyle displayStyle;   //图片特效
        std::vector<LayoutStyles> layoutStyles;     //布局样式
        std::vector<RegularContents> regularContents; //媒体内容
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RtMedia &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RtMedia &data);
}

namespace ns {
    struct  ScreenShot
    {
        int width = -1;
        int height = -1;
        string type;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenShot &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenShot &data);
}

namespace ns {
    struct Scale
    {
        bool enable = true;
        string shape = "RECTANGLE";
        int width = 6;
        int height = 6;
        string color = "#ff00ff00";
        TextProperty textAttributes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Scale &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Scale &data);

    struct Hand
    {
        bool enable = true;
        string color;
        //string drawable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Hand &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Hand &data);

    struct  Background
    {
        string color = "#000000";
        //string drawable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Background &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Background &data);
}

namespace ns {
    struct HourScale
    {
        string enable;
        string shape;
        int width = 0;
        int height = 0;
        string color;
    };

    struct  Date
    {
        bool enable = true;
        string regular = "$dd/$MM/$yyyy\n$E";
        std::vector<string> weekTemplates = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
        TextProperty textAttributes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Date &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Date &data);

    struct Text
    {
        bool enable = true;
        string text;
        TextProperty textAttributes;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Text &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Text &data);

    struct AnalogClock
    {
        string zone;
        string gmt = "UTC+08:00";
        Scale hourScale;
        Scale  minuteScale;
        Hand  hourHand;
        Hand  minuteHand;
        Hand secondHand;
        Background  background;
        Date  date;
        Text text;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const AnalogClock &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AnalogClock &data);
}


namespace ns {
    struct ColorfulContent
    {
        string content = "请输入文字";
        ScrollAttributes scrollAttributes;
        TextProperty textAttributes;
        OffSetInfo offSetInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ColorfulContent &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ColorfulContent &data);
    struct ColorfulText
    {
        ColorfulContent content;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ColorfulText &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ColorfulText &data);



    struct EffectsofBorder
    {
        string animation = "CLOCK_WISE";
        bool isHeadTail = false;
        int speed = 0;
        string headTailSpacing = "";
        bool speedByPixelEnable = true;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const EffectsofBorder &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, EffectsofBorder &data);

    struct SDKBorder
    {
        string name = "border";
        string borderThickness = "2px,3px,5%,6";
        string cornerRadius = "2%";
        string backgroundColor = "#ff000000";
        int style = 0;
        EffectsofBorder effects;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SDKBorder &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SDKBorder &data);

    struct  Widget
    {
        int id = 1;//挂件编号
        //int mid;//媒体唯一编号
        string name = "";//挂件名称
        bool enable = true;//是否启用，默认为TRUE
        string type = "";//
        long duration = 5000;
        int repeatCount = 1;
        WidgetLayout layout;
        string displayRatio = "FULL";
        Animation inAnimation;
        Animation outAnimation;
        string dataSource = "";
        string originalDataSource = "";
        string backgroundMusic = "";
        string backgroundColor = "#00000000";
        string backgroundDrawable = "";
        string originalMD5 = "";
        int64_t mStartTimeMillis = 0;
        int64_t mEndTimeMillis = 0;
        int zOrder = 0;

        std::vector<Constraint> constraints;
        Constraint constraintsForHandy;

        DigitalClock digitClockMetadata;
        AnalogClock analogClockMetadata;
        SimpleWeather simpleWeather;
        RichTextInfo richTextInfo;
        ScrollAttribute picture;
        //Fold fold;
        SDKBorder border;

        ColorfulText colorfulText;
        CountTimer countTimer;
        RSSMetaData rssMetaData;

        RtMedia rtMedia;

        StreamMetadata stramMetaData;
        string functionStorage = "";
        bool isSupportSpecialEffects = false;

    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const Widget &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Widget &data);

    struct  WidgetForJson
    {
        int id;//挂件编号
        //int mid;//媒体唯一编号
        string name;//挂件名称
        bool enable = true;//是否启用，默认为TRUE
        string type;//
        long duration = 10000;
        int repeatCount = 1;
        WidgetLayout layout;
        string displayRatio;
        Animation inAnimation;
        Animation outAnimation;
        string dataSource;
        string originalDataSource;
        string backgroundMusic = "";
        string backgroundColor = "#00000000";
        string backgroundDrawable = "";
        string originalMD5 = "";
        int64_t mStartTimeMillis = 0;
        int64_t mEndTimeMillis = 0;
        int zOrder;
        std::vector<Constraint> constraints;
        //Constraint constraints;
        DigitalClock digitClockMetadata;
        AnalogClock analogClockMetadata;
        SimpleWeather simpleWeather;
        RichTextInfo richTextInfo;
        ScrollAttribute picture;
        //Fold fold;
        SDKBorder border;

        ColorfulText colorfulText;
        CountTimer countTimer;
        RSSMetaData rssMetaData;

        RtMedia rtMedia;
        StreamMetadata stramMetaData;
        string functionStorage;
        bool isSupportSpecialEffects;

    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const WidgetForJson &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, WidgetForJson &data);

}

namespace ns {
    struct  MediaInfo
    {
        int playerId;
        int taskId;
        int layerId = 0;
        int pageId;
        int containerId;
        ns::Widget widget;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const MediaInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, MediaInfo &data);
}
namespace ns {

    struct  TrafficData
    {
        string type;
        long size;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TrafficData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TrafficData &data);
    struct TrafficInfo
    {
        string date;
        std::vector<TrafficData>traffics;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TrafficInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TrafficInfo &data);
}

namespace ns {
    VIPLEXCOMMON_EXPORT std::string getStringFromKey(const json &j);

    VIPLEXCOMMON_EXPORT std::vector<std::string> getStringsFromKey(const json &j);

    VIPLEXCOMMON_EXPORT std::vector<std::string> getStringsFromKey(const json &j, const std::string &key);

    std::map<std::string, std::string> getMapsFromKey(const json &j);
}

namespace ns {
    struct PlaylistUrl
    {
        std::string planUrl;
        std::string confUrl;
        std::string jobUrl;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlaylistUrl &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlaylistUrl &data);

}

#pragma region Region Token
namespace ns {
    struct TokenBody
    {
        string username;
        string password;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const TokenBody &body);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TokenBody &body);
}

namespace ns {
    struct TokenHeader
    {
        string baseUrl;
        TokenBody data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TokenHeader &header);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TokenHeader &header);
}
#pragma endregion
#pragma region Websocket Part	

#pragma region  Window

namespace ns {
    struct Window
    {
        int id;
        int height;
        int width;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const Window &window);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Window &window);
}
#pragma endregion

#pragma region MyRegion
namespace ns
{
    struct Source
    {
        int type;
        int platform;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Source &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Source &data);
}
#pragma endregion

namespace ns
{
    struct Condition
    {
        std::vector<string> cron;
        //std::string action;
        bool enable;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Condition &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Condition &data);
}
#pragma endregion

#pragma region update
//协议文档 http://172.16.80.64/index.php?s=/3&page_id=429
namespace ns
{
    struct UpDateSource
    {
        int type;
        int platform;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpDateSource &source);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpDateSource &source);
}

namespace ns
{
    struct UpdateCondition
    {
        string start;
        std::vector<string> cron;
        string end;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateCondition &condition);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateCondition &condition);
}

namespace ns
{
    struct UpdateTask
    {
        string packageType;
        string version;
        string executionType;
        string source;
        std::vector<UpdateCondition>conditions;
        long size = 0;
        string md5;
        string updateType;
        bool startupAfterInstalled = false;
        bool startupAfterBoot = false;
        bool checkFeasibility = false;
        int platformType = 0;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateTask &task);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateTask &task);
}
namespace ns
{
    struct UpdateTasks
    {
        std::vector<UpdateTask> tasks;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateTasks &task);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateTasks &task);

    struct UpdateTaskArray
    {
        string type;
        int orderId = 0;
        int action = 0;
        UpdateTasks data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateTaskArray &task);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateTaskArray &task);


    struct PublicNetUpdateTask
    {
        Source source;
        vector<UpdateTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetUpdateTask &task);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetUpdateTask &task);
    
}
namespace ns
{
    struct CSUpdate
    {
        string type;
        bool isLocal;
        Source source;
        std::vector<UpdateTask> tasks;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const CSUpdate &update);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, CSUpdate &update);
}

namespace ns {
    struct UpdateInfo
    {
        string upgradeFilePath;  // 升级文件 路径/*.exe     
        string workingDirectory;  //proto.exe工作目录  
        string version;       //升级文件版本号  2.0.0  不带v
        bool isUpdate = false;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateInfo &info);
}
#pragma endregion

#pragma region Version4CS
namespace ns {
    struct Version4CSResult
    {
        string packageName;
        string versionName;
        int versionCode;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const Version4CSResult &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Version4CSResult &result);
}

namespace ns {
    struct InstalledPackageVersions
    {
        std::vector<Version4CSResult> result;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const InstalledPackageVersions &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InstalledPackageVersions &result);
}

namespace ns {
    struct Version4CS
    {
        string fpga;
        string model;
        string mainVersion;
        string productName;
        string aliasName;
        string mac;
        string registerAddress;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const Version4CS &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Version4CS &info);
}

namespace ns {
    struct ConfigInfo_productInfo
    {
        string productName;
        int modelId = 0;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConfigInfo_productInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConfigInfo_productInfo &info);
}
namespace ns {
    struct ConfigInfo_portConfig
    {
        bool isMainPort = false;
        int portNO = 0;
        int belongMainPort = 0;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConfigInfo_portConfig &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConfigInfo_portConfig &info);
}
namespace ns {
    struct ConfigInfo_configInfo
    {
        bool videoSwitch = false;
        string displayDevice;
        std::vector<ns::ConfigInfo_portConfig> portConfigs;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConfigInfo_configInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConfigInfo_configInfo &info);
}

namespace ns {
    struct ConfigInfo
    {
        ns::ConfigInfo_productInfo productinfo;
        ns::ConfigInfo_configInfo configinfo;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const ConfigInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ConfigInfo &info);
}
namespace ns {
    struct ScreenMosaicInfo
    {
        int order = 0;
        int videoSource = 0;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenMosaicInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenMosaicInfo &info);
}

#pragma endregion

#pragma region Playlist4CS
namespace ns {
    struct Solution
    {
        string name;
        string identifier;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const Solution &solution);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Solution &solution);
}

namespace ns {
    struct SolutionStart
    {
        string deviceIdentifier;
        long totalSize;
        string type;
        int source;
        bool local;
        Solution solutions;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const SolutionStart &solution);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SolutionStart &solution);
}

namespace ns {
    //struct ConfirmedInfos
    //{
    //	string identifier;
    //	string name;
    //	string planListUrl;
    //	string thumbnailUrl;
    //	bool isSupportMd5Checkout;
    //};

    //VIPLEXCOMMON_EXPORT void to_json(json& j, const ConfirmedInfos &info);
    //VIPLEXCOMMON_EXPORT void from_json(const json& j, ConfirmedInfos &info);
}

//namespace ns {
//	struct SolutionEnd
//	{
//		bool playImmediately;
//		ConfirmedInfos confirmedInfos;
//	};
//
//	VIPLEXCOMMON_EXPORT void to_json(json& j, const SolutionEnd &solution);
//	VIPLEXCOMMON_EXPORT void from_json(const json& j, SolutionEnd &solution);
//}

namespace ns {
    struct AppliedInfo
    {
        string name;
        string identifier;
        string uploadUrl;
        int fileSource;
        int statusCode;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const AppliedInfo &info);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, AppliedInfo &info);
}

namespace ns {
    struct SolutionStartResponse
    {
        bool canTranster;
        string uploadMediaUrl;
        int errorCode;
        AppliedInfo appliedInfos;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const SolutionStartResponse &response);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SolutionStartResponse &response);
}
#pragma endregion


#pragma region LoginData
namespace ns
{
    struct DissConnectData
    {
        string sn;
        int loginType = 0;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const DissConnectData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, DissConnectData &data);

    struct LoginData
    {
		string ip;
        string sn;
        string username;
        string password;
        int loginType = 0;
        int rememberPwd = 0;
        Source source;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginData &data);


    struct LoginReplySuccessData
    {
        string sn;
        string username;
        string password;
        bool validation;
        bool validition;
        bool logined;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginReplySuccessData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginReplySuccessData &data);

    struct LoginReplyData
    {
        string sn;
        string username;
        string password;
        bool validation;
        bool validition;
        bool logined;
        std::vector<std::string> loginedUsernames;
        string encrypt;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginReplyData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginReplyData &data);

    struct LoginErrorData
    {
        string errorDiscription;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginErrorData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginErrorData &data);

    struct ContinuousLoginErrorData
    {
        string errorDiscription;
        int mRemainTime;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ContinuousLoginErrorData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ContinuousLoginErrorData &data);

    struct ChangePassword
    {
        string username;
        string password;
        string newPassword;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ChangePassword &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ChangePassword &data);

    struct ChangePasswordWithSN
    {
        string sn;
        ChangePassword cp;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ChangePasswordWithSN &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ChangePasswordWithSN &data);


    struct RegisterAddressData
    {
        string country;
        string province;
        string city;
        string county;
        string address;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RegisterAddressData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RegisterAddressData &data);


    struct ChangeVPlayerName
    {
        string aliasName;
        RegisterAddressData registerAddressData;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ChangeVPlayerName &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ChangeVPlayerName &data);
}
#pragma endregion

#pragma region DeviceInfo

namespace ns {
    //亮度模块支持的功能
    struct Brightness
    {
        bool Validity = false;
        bool CompleteCron = false;
        bool FloatValue = false;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Brightness &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Brightness &data);
}
namespace ns {
    //网络模块支持的功能
    struct NetWork
    {
        bool IsSupport = false;			//是否支持网络功能
        bool Wifi = false;		//是否支持WiFi(此字段为T卡1.3.3版本判断wifi支持的字段，上边WIFI字段废弃不用，但继续保留为了兼容)
        bool Wired = false;		//是否支持有线网络
        bool AP = false;		//是否支持AP网络
        bool Mobile = false;		//是否支持移动网络
        bool IsSupportNetWorkCheck = false;		//是否支持切换网络检测
        bool IsSupportMultiDns = false;		//是否支持多个DNS地址
        bool WiFiApSwitch = false;		//是否支持wifi-ap/station切换
        bool Apn = false;
        bool AirPlane = false;
        bool NetStateFor4G = false;
        bool Restart4GModule = false;
        bool WorkStateFor4G = false;
        bool Log4G = false;
        bool IsSupportSimModeSwitch = false;
        bool IsSupportGetModuleInfo = false;
        bool IsSupportModuleVersionUpdate = false;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const NetWork &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, NetWork &data);
}
namespace ns {
    //支持功能信息
    struct Input
    {
        bool IsSupport = false;			//是否支持输入源
        bool Hdmi = false;		//是否支持hdmi输入源
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Input &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Input &data);
}
namespace ns {
    //支持功能信息
    struct Output
    {
        bool IsSupport = false;			//是否支持输出源
        bool HdmiToLvds = false;		//是否支持hdmi与lvds输出源
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Output &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Output &data);
}
namespace ns {
    //视频源模块支持的功能(VIDEO_SOURCE_SWITCH字段不能满足express，故加此字段)
    struct VideoSource
    {
        bool IsSupport = false;			//是否支持视频源模块
        bool Hdmi = false;		//是否支持Hdmi视频源
        Input input;
        Output output;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const VideoSource &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, VideoSource &data);
}
namespace ns {
    //射频管理模块支持的功能
    struct RadioFrequencyManage
    {
        bool IsSupport = false;			//是否支持射频管理
        bool IsSupportLoraInfo = false;		//是否支持Lora信息检测功能
        bool IsSupportProduct = false;		//产品是否支持，主要指硬件是否支持该功能
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const RadioFrequencyManage &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, RadioFrequencyManage &data);
}
namespace ns {
    //升级模块
    struct Upgrade
    {
        bool IsSupportCheckValid = false;			//是否支持升级可行性检查
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Upgrade &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Upgrade &data);
}
namespace ns {
    //输出源模式
    struct SourceOutMode
    {
        bool IsSupportChangeSourceOutMode = false;			//是否支持输出源HDMI/DVI切换
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SourceOutMode &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SourceOutMode &data);
}
namespace ns {
    //运行时文件路径获取
    struct ZipRunningLog
    {
        bool IsSupportZipRunningLogInfo = false;			//是否支持输出源HDMI/DVI切换
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ZipRunningLog &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ZipRunningLog &data);
}
namespace ns {
    //接收卡相关功能
    struct ReceiveCard
    {
        bool IsSupport = false;			//是否支持多功能卡
        bool Config = false;			//是否支持多功能卡配置
        bool Temperature = false;			//是否支持多功能卡温度
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ReceiveCard &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ReceiveCard &data);
}
namespace ns {
    //配屏相关功能
    struct ScreenConfig
    {
        bool IsSupport = false;			//是否支持配屏相关功能
        bool Config = false;			//是否支持配置
        bool ScreenJoint = false;			//是否支持多屏拼接
        bool IsSupportProduct = false;			//产品是否支持，主要指硬件是否支持该功能
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ScreenConfig &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ScreenConfig &data);
}
namespace ns {
    //监控相关功能
    struct Monitoring
    {
        bool IsSupport = false;			//是否支持监控相关功能
        bool ClearMedia = false;			//是否支持清除媒体
        bool Memory = false;			//是否支持内存监控
        bool CPU = false;			//是否支持CPU监控
        bool AmbientBrightness = false;			//是否支持环境亮度监控
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Monitoring &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Monitoring &data);
}
namespace ns {
    //对时相关功能
    struct TimeControl
    {
        bool IsSupport = false;			//是否支持对时功能
        bool Manual = false;			//是否支持手动对时
        bool NTP = false;			//是否支持NTP对时
        bool Lora = false;			//是否支持lora对时
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const TimeControl &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, TimeControl &data);
}
namespace ns {
    //分辨率相关功能
    struct Resolution
    {
        bool IsSupport = false;			//是否支持切换分辨率
        bool CustomResolution = false;			//是否支持自定义分辨率，上边CustomResolution字段废弃不用，但继续保留为了兼容
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Resolution &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Resolution &data);
}
namespace ns {
    //传感器子板相关功能
    struct SensorBoard
    {
        bool IsSupport = false;			//是否支持传感器子板
        bool SensorInfo = false;			//是否支持获取及设置传感器的信息(保留)
        bool IsSupportProduct = false;		//产品是否支持，主要指硬件是否支持该功能
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const SensorBoard &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, SensorBoard &data);
}
namespace ns {
    //旋转功能
    struct Rotation
    {
        bool IsSupport = false;			//是否支持旋转
        bool IsSupportProduct = false;		//产品是否支持，主要指硬件是否支持该功能
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Rotation &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Rotation &data);

    struct PlayManager
    {
        bool IsSupport = false;			//是否支持查看终端信息
        bool ProgramListManager = false;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayManager &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayManager &data);
}
namespace ns {
    //开关量外部设备调节功能， 红外感应设备（高低电平）
    struct InfraredDetector
    {
        bool IsSupport = false;			//是否支持外部设备调节
        bool IsSupportProduct = false;		//产品是否支持，主要指硬件是否支持该功能
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const InfraredDetector &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InfraredDetector &data);
}
namespace ns {
    //支持功能信息
    struct config_info
    {
        bool REBOOT = false;		//是否支持重启
        bool SCREENPOWER = false;		//是否支持开关屏
        bool SYNC_PLAY = false;		//是否支持同步播放
        bool SPOTS = false;         //是否支持插播
        bool VIDEO_SOURCE_SWITCH = false;		//是否支持视频源切换
        bool UPDATE = false;		//是否支持升级功能
        bool SCREENSHOT = false;		//是否支持截屏功能
        bool TIMEZONE = false;		//是否支持设置/获取时区功能
        bool POWER = false;		//是否支持控制电源功能
        bool VOICE = false;		//是否支持控制音量功能
        bool LIGHT = false;		//是否支持控制亮度功能
        bool UPDATEOS = false;		//是否支持系统升级
        bool WIFI = false;		//是否支持wifi station
        bool CARE = false;		//是否支持Care
        bool VNNOX = false;		//是否支持vnnox
        bool PLAYLOG = false;		//是否支持播放日志
        bool COLORTEMPERATURE = false;		//是否支持色温
        bool INDICATORLIGHT = false;		//是否支持指示灯
        bool NEXUSFONT = false;		//是否支持字体管理
        bool NEWPROTOCOL = false;		//是否支持新协议
        bool RELAYPOWER = false;		//是否支持本板电源
        bool RELAYPOWERCONFIG = false;		//是否支持本板电源配置
        bool RESET = false;		//是否支持恢复出厂设置
        bool FIXEDPOINT = false;		//是否支持定点投放
        bool TERMINALINFO = false;		//是否支持终端信息
        bool CustomResolution = false;		//是否支持自定义分辨率
        Brightness brightness;		//亮度模块支持的功能
        NetWork netWork; 		//网络模块支持的功能
        VideoSource videoSource;  		//视频源模块支持的功能(VIDEO_SOURCE_SWITCH字段不能满足express，故加此字段)
        RadioFrequencyManage radioFrequencyManage; 		//射频管理模块支持的功能
        Upgrade upgrade; 		//升级模块
        SourceOutMode sourceOutMode; 		//输出源模式
        ZipRunningLog zipRunningLog; 		//运行时文件路径获取
        ReceiveCard receiveCard; 		//接收卡相关功能
        ScreenConfig screenConfig; 		//配屏相关功能
        Monitoring monitoring; 		//监控相关功能
        TimeControl timeControl; 		//对时相关功能
        Resolution resolution; 		//分辨率相关功能
        SensorBoard sensorBoard; 		//传感器子板相关功能
        Rotation  rotation; 		//旋转功能
        PlayManager playManager;
        InfraredDetector infraredDetector;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const config_info &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, config_info &data);
    const json &getDefaultConfigJson();
}

namespace ns {
    //终端支持功能列表信息
    struct PlayerFunctions
    {
        string version;	//"V1.3.0",
        config_info configInfo;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerFunctions &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerFunctions &data);
}
#pragma endregion

#pragma region UpdateDescription

namespace ns
{
    struct Package
    {
        string identifier;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Package &data);
}

namespace ns
{
    struct Description
    {
        std::vector<Package>packages;
    };
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Description &data);
}
#pragma endregion

namespace ns {
    //播放绑定请求
    struct ServerType
    {
        bool value = true;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const ServerType &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ServerType &data);


}

namespace ns {
    //请求g_jIdentifierList的个数request
    struct PlayerNumber
    {
        int number = 0;
        string token;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerNumber &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerNumber &data);

    //请求g_jIdentifierList的response
    struct IdentifierList
    {
        vector<string> identifierList;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const IdentifierList &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, IdentifierList &data);

    //判断播放器名称是否正确request
    struct PlayerName
    {
        string playerName;
        string token;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerName &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerName &data);

    //播放器名称是否有效response
    struct ValidPlayerName
    {
        int value = 0;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const ValidPlayerName &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ValidPlayerName &data);

    struct BaseUrl
    {
        string baseurl;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const BaseUrl &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, BaseUrl &data);
}
Q_DECLARE_METATYPE(ns::PlayerNumber);
Q_DECLARE_METATYPE(ns::PlayerName);
Q_DECLARE_METATYPE(ns::ValidPlayerName);
Q_DECLARE_METATYPE(ns::IdentifierList);

namespace ns {
    struct UserInfo
    {
        string userName;   //认证用户名
        string passWord;    //认证用户密码
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UserInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UserInfo &data);
}
Q_DECLARE_METATYPE(ns::UserInfo);

namespace ns {
    //播放绑定请求
    struct PlayerBoundingInfo
    {
        string productName;
        string platform;
        string platformSystem;
        string hostName;
        string hostIp;
        string softwareName;
        string softwareVersion;
        int playerType;
        string playerIdentifier;
        string identifier;
        vector<Window> windows;
    };

    VIPLEXCOMMON_EXPORT void to_json(json& j, const PlayerBoundingInfo &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PlayerBoundingInfo &data);
}

namespace ns
{
    struct Border
    {
        string foregroundColor = "#FF008000";
        string backgroundColor = "#FF000000";
        int width = 0;
        string borderSource;
        string originalBorderSource;
        string TempBorderBackgroud;
        int style = 0;
        int styleForExpress = 0;
        EffectsofBorder effects;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Border &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Border &data);
}
#pragma region Region Task

namespace ns {
    struct Ntp
    {
        bool enable;
        string server;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Ntp &job);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Ntp &job);

    struct Lora
    {
        int address;
        int channel;
        bool enable;
        string groupId;
        string mode;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Lora &job);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Lora &job);

    struct Gps
    {
        bool enable;

    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const Gps &job);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, Gps &job);
}

#pragma endregion

namespace ns 
{

	struct LoginVnnox 
	{
		std::string type;
		std::string userName;
		std::string password;
		std::string node;
		std::string verifyCode;
		std::string countryCode;	
	};

	VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginVnnox &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginVnnox &job);

	struct LoginVnnoxForPassword
	{
		std::string type;
		std::string username;
		std::string password;
	};

	VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginVnnoxForPassword &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginVnnoxForPassword &job);

	struct LoginVnnoxForCode
	{
		std::string type;
		std::string username;
		std::string code;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginVnnoxForCode &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginVnnoxForCode &job);

	struct LoginVnnoxResponseData
	{
		std::string token;
		string isAdministrator;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginVnnoxResponseData &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginVnnoxResponseData &job);

	struct LoginVnnoxResponse
	{
		int http_code;
		std::vector<int> status;
		ns::LoginVnnoxResponseData data;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const LoginVnnoxResponse &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, LoginVnnoxResponse &job);

	struct GetVerifyCode
	{
		std::string type;
		std::string lang;
		std::string userName;
		std::string node;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVerifyCode &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVerifyCode &job);

	struct GetVerifyCodeRequestData
	{
		int sendType;
		std::string sendTarget;
		int language;
		int sendTempType;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const GetVerifyCodeRequestData &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, GetVerifyCodeRequestData &job);

	struct RegisterVnnox
	{
		std::string type;
		std::string userName;
		std::string countryCode;
		std::string verifyCode;
		std::string password;
		std::string node;
		std::string name;
		std::string lang;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const RegisterVnnox &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, RegisterVnnox &job);

	struct RegisterVnnoxRequestData
	{
		std::string registerType;
		std::string username;
		std::string email;
		std::string emailCode;
		std::string countryCode;
		std::string phone;
		std::string phoneCode;
		std::string password;
		std::string language;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const RegisterVnnoxRequestData &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, RegisterVnnoxRequestData &job);



	struct RegisterVnnoxResponse
	{
		int http_code;
		std::vector<int> status;
		ns::RegisterVnnoxRequestData data;
	};
	VIPLEXCOMMON_EXPORT void to_json(json& j, const RegisterVnnoxResponse &job);
	VIPLEXCOMMON_EXPORT void from_json(const json& j, RegisterVnnoxResponse &job);



}

namespace ns 
{
    struct ProgramRegular
    {
        int id;
        int priority;//优先级，节目播放的优先级
        int programID = -1;//需要播放节目的programID
        vector<ns::Constraint> constraints;
//         std::string startTime;//开始时间
//         std::string endTime;//结束时间
//         vector<std::string> cron;
        std::string rules;//规则，DURATION：按照时长播放,TIMES:按照次数播放
        int64_t duration;//播放时长，预留字段
        int repeatCount;//重复次数
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ProgramRegular &job);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ProgramRegular &job);
    struct ComplexProgram 
    {
        std::string name;//复杂节目名称
        bool isUpdate = false;//是否修改节目，true表示修改复杂节目，name可重复，false:新增复杂节目，name不可重复
        vector<ns::ProgramRegular> programRegular;//复杂节目规则
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const ComplexProgram &job);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, ComplexProgram &job);

}

namespace ns
{

#pragma region Region 连接公网SDK服务器
    struct InitPublicNet
    {
        int port;
        bool publicModule = false; //是否是公网模式
        bool isEncrypt = false;// 是否加密
        string SSLCertPath;
        string httpserverUrl;
        string httpserverLocalPath;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const InitPublicNet &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, InitPublicNet &result);

    //request
    struct PublicNetConfigInfo
    {
        int port;
        int timeout = 0;
        bool isEncrypt = true;
        string host;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetConfigInfo &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetConfigInfo &result);

    struct PublicNetConfig
    {
        string sn;
        PublicNetConfigInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetConfig &result);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetConfig &result);


    struct PublicNetConfigInfoTaskArray: TaskArrayFor0x99
    {
        PublicNetConfigInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetConfigInfoTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetConfigInfoTaskArray &data);

    struct PublicNetConfigRequest
    {
        Source source;
        vector<PublicNetConfigInfoTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetConfigRequest &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetConfigRequest &data);

    //response
#pragma endregion 

#pragma region Region 断开公网SDK服务器
    //request  TaskArrayFor0x99

    //response
    //同PublicNetConfigResponseArray

#pragma endregion

#pragma region Region 回读公网SDK服务器地址信息
    //request  同PublicNetDisconnectTaskArray

    //response
    struct PublicNetConfigParamResponse
    {
        string type;
        int action;
        int status;
        int errorCode;
        PublicNetConfigInfo data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetConfigParamResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetConfigParamResponse &data);


    struct PublicNetConfigParamResponseArray
    {
        vector<PublicNetConfigParamResponse> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const PublicNetConfigParamResponseArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, PublicNetConfigParamResponseArray &data);
#pragma endregion

#pragma region Region 更新节目
    struct UpdateProgramPlanData
    {
        long size = 0;
        string fileName;
        string url;
        string md5;
        string programName;
        bool isSupportMd5Checkout = false;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateProgramPlanData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateProgramPlanData &data);


    struct UpdateProgramThumbnailData
    {
        long size = 0;
        string fileName;
        string md5;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateProgramThumbnailData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateProgramThumbnailData &data);

    struct UpdateProgramData
    {
        string identifier;
        UpdateProgramPlanData plan;
        UpdateProgramThumbnailData thumbnail;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateProgramData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateProgramData &data);


    struct UpdateProgramDataTaskArray : TaskArrayFor0x99
    {
        UpdateProgramData data;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateProgramDataTaskArray &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateProgramDataTaskArray &data);


    struct UpdateProgramRequestData
    {
        Source source;
        vector<UpdateProgramDataTaskArray> taskArray;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateProgramRequestData &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateProgramRequestData &data);

    struct UpdateProgramResponse
    {
        string fileInfo;
        int downloadStatus = 0;
        int errorInfo = 0;
        int progress = 0;
        long updateTime = 0;
    };
    VIPLEXCOMMON_EXPORT void to_json(json& j, const UpdateProgramResponse &data);
    VIPLEXCOMMON_EXPORT void from_json(const json& j, UpdateProgramResponse &data);




    



#pragma endregion
}

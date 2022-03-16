#pragma once
#include <vector>
#include <utility>
#include <string>
#include <set>
#include "QTextCodec"

string readFile(const string &filePath)
{
    if (!QFile::exists(QString::fromStdString(filePath)))
    {
        return "";
    }
    QFile file(QString::fromStdString(filePath));
    QTextCodec *textCode = QTextCodec::codecForName("GBK");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return "";
    }
    return file.readAll().toStdString();
}

bool writeFile(const QString & filePath, const QString & content)
{
    QFile f(filePath);
    if (!f.open(QIODevice::WriteOnly))
    {
        return false;
    }
    QTextStream t(&f);
    t << content;
    f.close();
    return true;
}

class ExportGenerator
{
public:
    using FuncNamePair = std::pair<std::string, std::string>;
    using FuncNamePairs = std::vector<std::pair<std::string, std::string>>;
    ExportGenerator(const std::string &exportCPPPath, const std::string &targetLangPath)
        : m_exportCPPPath(exportCPPPath)
        , m_targetLanPath(targetLangPath){}
    void generateAPI() const
    {
        FuncNamePairs funcNames = getFuncNames(readFile(m_exportCPPPath));
        writeFile(m_targetLanPath.c_str(), getAPIContents(funcNames, m_targetLanPath).c_str());
    }
protected:
    std::string getAPIContents(const FuncNamePairs &funcNames, const std::string &exportAPIPath) const;

    bool needTranslateFunc(set<std::string> exceptionFuncNames, std::string &funcName) const
    {
        for (const auto & exceptionName : exceptionFuncNames)
        {
            if (funcName.find(exceptionName) != std::string::npos)
            {
                return false;
            }
        }
        return true;
    }

    size_t calculateInsertPos(const std::string &csContents, size_t pos) const
    {
        size_t tmpPos = pos;
        while (' ' == csContents[tmpPos - 1])
        {
            tmpPos -= 1;
        }
        return tmpPos;
    }

    vector<std::pair<std::string, std::string>> getFuncNames(const std::string &content) const;
    virtual std::string generateMethod(const FuncNamePair &funcNamePair) const = 0;
    std::string m_exportCPPPath;
    std::string m_targetLanPath;
};


std::string ExportGenerator::getAPIContents(const FuncNamePairs &funcNames, const std::string &exportAPIPath) const
{
    std::string csContents = readFile(exportAPIPath);
    std::string insertPoint = "//insert here";
    auto pos = csContents.find(insertPoint);
    csContents.replace(pos, insertPoint.size(), "");
    pos = calculateInsertPos(csContents, pos);
    set<std::string> exceptionFuncNames = { "exportFuncAPIAsync", "nvSetPlatform", "nvInit", "nvSearchTerminalAsync", 
        "nvSetDevLang", "nvPingAsync", "nvStopPublicNetAsync", "nvFindAllTerminalsAsync", "nvGetOnlineDevicesAsync", "nvInitPublicNetAsync" };
    for (const auto & element : funcNames)
    {
        std::string funcName = element.first;
        if (!needTranslateFunc(exceptionFuncNames, funcName))
        {
            continue;
        }
        csContents.insert(pos, generateMethod(element));
    }
    return csContents;
}

vector<std::pair<std::string, std::string>> ExportGenerator::getFuncNames(const std::string &content) const
{
    vector<std::pair<std::string, std::string>> funcNames;
    std::string funcNamePrefix = "VIPLEX_EXPORT void ";
    std::string funcNamePostfix = "(";
    size_t prefix = content.find(funcNamePrefix, 0);
    while (std::string::npos != prefix)
    {
        prefix = prefix + funcNamePrefix.size();
        size_t postfix = content.find(funcNamePostfix, prefix);
        if (std::string::npos != postfix)
        {
            auto funcName1 = content.substr(prefix, postfix - prefix);
            //                 if (funcName1.substr(0, 2) != "nv")
            //                 {
            //                     OutputDebugStringA("Viplex error: 导出的函数名不是以nv开头");
            //                     break;
            //                 }
            auto funcName2 = funcName1;
            funcName2[0] -= 32;
            funcNames.emplace_back(std::pair<std::string, std::string>{ funcName1, funcName2 });
        }
        prefix = content.find(funcNamePrefix, prefix);
    }
    return funcNames;
}

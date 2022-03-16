#pragma once
#pragma execution_character_set("utf-8")


#include "QFile"
#include "jsonserializer/jsonserializer.h"

namespace ns {
    template<class T>
    void to_string(const T &data, std::string &content)
    {
        json j;
        to_json(j, data);
        content = j.dump();

    }


    template<class T>
    void  from_string(const std::string &content, T &data)
    {
        try
        {
            json j = json::parse(content);
            from_json(j, data);
        }
        catch (exception* e)
        {

        }

    }
}
namespace ns
{
    template<class T>
    bool readJsonFromFile(QString filePath, T &data)
    {
        try
        {
            QFile fileLoader(filePath);

            if (!fileLoader.open(QIODevice::ReadOnly))
            {
                return false;
            }
            QByteArray allData = fileLoader.readAll();
            fileLoader.close();

            QString content = QString(allData).toUtf8();
            from_string(content.toStdString(), data);
            return true;
        }
        catch (exception& e)
        {
            return false;
        }
    }
}
namespace ns 
{
    template<class T>
    void to_arraysString(T &t,const std::vector<std::string> &data, std::string &content)
    {
        json j;
        for (auto& element : data)
        {
            j.push_back(element);
        }
        content = j.dump();
    }
    template<class T>
    void from_arraysString(T &t, const std::string &content, std::vector<std::string> &data)
    {
        if (content.empty())
        {
            return;
        }
        json j=json::parse(content);
        data = getStringsFromKey(j);
    }

    template<class T>
    void to_vectorOfTString(std::vector<T> &data, std::string &content)
    {
        json j = json(data);
        content = j.dump();
    }

    template<class T>
    void from_vectorOfTString(std::string &content,std::vector<T> &data)
    {
        json j = json::parse(content);
        for (auto t: j)
        {
            data.push_back(t);
        }
    }
}
namespace ns
{
    template<class T>
    bool findKey(T &t, std::string &jsonContent, std::string key)
    {
        if (jsonContent.empty())return false;
        json j = json::parse(jsonContent);
        if (j.find(key) != j.end()) {
            return true;
        }
        return false;
    }

    template<class T>
    std::string findValueOfKey(T &t, std::string &jsonContent, std::string key)
    {
        std::string value = "";
        if (jsonContent.empty())
        {
            return value;
        }
        json j = json::parse(jsonContent);
        if (j.find(key) != j.end()) {
            value = j[key].dump();
        }
        return value;
    }
}

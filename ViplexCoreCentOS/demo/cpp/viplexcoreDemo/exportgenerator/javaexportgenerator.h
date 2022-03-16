#pragma once
#include "exportgenerator.h"

class JavaExportGenerator : public ExportGenerator
{
public:
    JavaExportGenerator(const std::string &exportCPPPath, const std::string &targetLangPath)
        :ExportGenerator(exportCPPPath, targetLangPath) {}
    virtual std::string generateMethod(const FuncNamePair &funcNamePair) const override;
};

std::string JavaExportGenerator::generateMethod(const FuncNamePair &funcNamePair) const
{
    QString line = "    void %1(String data, CallBack callBack);\n";
    line = line.arg(funcNamePair.first.c_str());
    return line.toStdString();
}

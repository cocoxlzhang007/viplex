#pragma once
#include "exportgenerator.h"

class OCHExportGenerator : public ExportGenerator
{
public:
    OCHExportGenerator(const std::string &exportCPPPath, const std::string &targetLangPath)
        :ExportGenerator(exportCPPPath, targetLangPath) {}
    virtual std::string generateMethod(const FuncNamePair &funcNamePair) const override;
};

std::string OCHExportGenerator::generateMethod(const FuncNamePair &funcNamePair) const
{
    QString line = "- (void)%1:(NSString*)nsdata:(viplexcoreblock)block;\n";
    line = line.arg(funcNamePair.first.c_str());
    return line.toStdString();
}

#pragma once
#include "exportgenerator.h"

class OCMExportGenerator : public ExportGenerator
{
public:
    OCMExportGenerator(const std::string &exportCPPPath, const std::string &targetLangPath)
        :ExportGenerator(exportCPPPath, targetLangPath) {}
    virtual std::string generateMethod(const FuncNamePair &funcNamePair) const override;
};

std::string OCMExportGenerator::generateMethod(const FuncNamePair &funcNamePair) const
{
    QString line = 
        "- (void)%1:(NSString*)nsdata:(viplexcoreblock)block {\n"\
        "    const char* data = [nsdata UTF8String];\n"\
        "    ViplexCoreAsync::%1(data, [block](uint16_t code,const char * data) {\n"\
        "        NSString *nsData = [[NSString alloc] initWithCString:(const char*)data encoding:NSASCIIStringEncoding];\n"\
        "        block(code ,nsData);\n"\
        "    });\n"\
        "}\n\n";
    line = line.arg(funcNamePair.first.c_str());
    return line.toStdString();
}

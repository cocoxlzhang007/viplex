#pragma once
#include "exportgenerator.h"

class CSharpExportGenerator : public ExportGenerator
{
public:
    CSharpExportGenerator(const std::string &exportCPPPath, const std::string &targetLangPath)
        :ExportGenerator(exportCPPPath, targetLangPath) {}
    virtual std::string generateMethod(const FuncNamePair &funcNamePair) const override;
};

std::string CSharpExportGenerator::generateMethod(const FuncNamePair &funcNamePair) const
{
    QString line1 = "        [DllImport(\"viplexcore.dll\", EntryPoint = \"%1\", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]\n";
    QString line2 = "        public static extern void %1(byte[] data, exportViplexCallback resultCallback);\n\n";
    line1 = line1.arg(funcNamePair.first.c_str());
    line2 = line2.arg(funcNamePair.second.c_str());
    line1 += line2;
    return line1.toStdString();
}

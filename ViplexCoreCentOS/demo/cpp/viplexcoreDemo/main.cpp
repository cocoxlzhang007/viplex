#include <QtWidgets/QApplication>
#include "QObject"
#include "demoGUI.h"
#include"QDebug"
#include <string>
#include <utility>
#include "exportgenerator/exportgenerator.h"
#include "exportgenerator/csharpexportgenerator.h"
#include "exportgenerator/javaexportgenerator.h"
#include "exportgenerator/ochexportgenerator.h"
#include "exportgenerator/ocmexportgenerator.h"
#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString ss = QString("%1df%1").arg("111");
    
    if (argc == 3
            && 0 == strcmp(argv[1], "-export"))
     {
        std::string dirForZip = argv[2];
        std::string includeDir = dirForZip + "/../src/libs/viplexcore/";
        std::string pathForJava = includeDir + "exportviplexcoreasync.h";
        vector<shared_ptr<ExportGenerator>> generators = {
            (shared_ptr<ExportGenerator>)make_shared<JavaExportGenerator>(JavaExportGenerator(pathForJava, dirForZip + "/demo/java/src/viplexcore.java")),
            (shared_ptr<ExportGenerator>)make_shared<OCHExportGenerator>(OCHExportGenerator(pathForJava, dirForZip + "/demo/oc/viplexcoreoc.h")),
            (shared_ptr<ExportGenerator>)make_shared<OCMExportGenerator>(OCMExportGenerator(pathForJava, dirForZip + "/demo/oc/viplexcoreoc.mm"))
        };
#ifdef WIN32
        std::string pathForCS = includeDir + "exportviplexcoreasyncunicode.h";
        generators.emplace_back(
            (shared_ptr<ExportGenerator>)make_shared<CSharpExportGenerator>(CSharpExportGenerator(pathForCS, dirForZip + "/demo/c#/viplexcoresample/viplexcore.cs")));
#endif
        for (auto element : generators)
        {
            element->generateAPI();
        }
        return 0;
    }
    DemoGUI w;
    w.show();
    return a.exec();

}


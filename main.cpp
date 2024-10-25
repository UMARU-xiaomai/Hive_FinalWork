#include "mainwindow.h"
#include "scenemanager.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QResource>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QResource::registerResource("./Resources.rcc");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Hive_FinalWork_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    //加载场景管理器


    MainWindow w;
    SceneManager sm ;

    w.show();
    return a.exec();
}

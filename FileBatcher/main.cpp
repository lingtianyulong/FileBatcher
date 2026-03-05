#include "helper/theme_helper.h"
#include "logger/logger.h"
#include "ui/mainwindow.h"

#include <QApplication>
#include <QFile>

using namespace file_batcher::logger;
using namespace file_batcher::helper;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    Logger::LoadConfig("config/log.json");
    if (!Logger::init()) {
        return 0;
    }
    Logger::Info("FileBatcher started");

    ThemeHelper::loadTheme({":/styles/buttons.qss"});

    MainWindow w;
    w.show();
    return a.exec();
}

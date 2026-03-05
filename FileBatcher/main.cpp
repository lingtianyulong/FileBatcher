#include "helper/theme_helper.h"
#include "ui/mainwindow.h"

#include <QApplication>
#include <QFile>

using namespace file_batcher::helper;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    ThemeHelper::loadTheme({":/styles/buttons.qss"});

    MainWindow w;
    w.show();
    return a.exec();
}

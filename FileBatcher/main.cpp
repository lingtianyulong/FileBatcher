#include "ui/mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    // 加载 qss
    QStringList qssFiles = {
        // ":/theme/advanceddock.qss",
        ":/styles/buttons.qss",
    };
    QString qss = "";
    for (auto& file : qssFiles) {
        QFile f(file);
        if (f.open(QFile::ReadOnly)) {
            qss += f.readAll();
            qss += "\n";
        } else {
            // Logger::Error("Failed to load qss file: " + file.toStdString());
        }
    }
    qApp->setStyleSheet(qss);

    MainWindow w;
    w.show();
    return a.exec();
}

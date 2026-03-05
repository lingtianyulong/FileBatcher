#pragma once

#include <QApplication>
#include <QFile>

namespace file_batcher::helper {
class ThemeHelper {
public:
    static void loadTheme(const QStringList& themes) {
        QString qss = "";
        for (const auto& theme : themes) {
            if (theme.isEmpty()) {
                continue;
            }
            if (!theme.endsWith(".qss", Qt::CaseInsensitive)) {
                continue;
            }
            QFile file(theme);
            if (!file.open(QFile::ReadOnly)) {
                continue;
            }
            qss += file.readAll();
            qss += "\n";
        }
        qApp->setStyleSheet(qss);
    }
};
}  // namespace file_batcher::helper
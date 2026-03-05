#pragma once

#include <QPushButton>
namespace file_batcher::controls {
class InfoButton : public QPushButton {
    Q_OBJECT
public:
    explicit InfoButton(QWidget* parent = nullptr) : QPushButton(parent) {
        this->setProperty("btnType", "info");
    }
    explicit InfoButton(const QString& text, QWidget* parent = nullptr)
        : QPushButton(text, parent) {
        this->setProperty("btnType", "info");
    }
    InfoButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr)
        : QPushButton(icon, text, parent) {
        this->setProperty("btnType", "info");
    }
    ~InfoButton() = default;
};
}  // namespace file_batcher::controls
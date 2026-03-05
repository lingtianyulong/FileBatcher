#pragma once

#include <QPushButton>
namespace file_batcher::controls {
class WarningButton : public QPushButton {
    Q_OBJECT
public:
    explicit WarningButton(QWidget* parent = nullptr) : QPushButton(parent) {
        this->setProperty("btnType", "warning");
    }
    explicit WarningButton(const QString& text, QWidget* parent = nullptr)
        : QPushButton(text, parent) {
        this->setProperty("btnType", "warning");
    }
    WarningButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr)
        : QPushButton(icon, text, parent) {
        this->setProperty("btnType", "warning");
    }
    ~WarningButton() = default;
};
}  // namespace file_batcher::controls
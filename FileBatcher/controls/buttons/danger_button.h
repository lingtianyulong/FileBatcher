#pragma once

#include <QPushButton>
namespace file_batcher::controls {
class DangerButton : public QPushButton {
    Q_OBJECT
public:
    explicit DangerButton(QWidget* parent = nullptr) : QPushButton(parent) {
        this->setProperty("btnType", "danger");
    }
    explicit DangerButton(const QString& text, QWidget* parent = nullptr)
        : QPushButton(text, parent) {
        this->setProperty("btnType", "danger");
    }
    DangerButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr)
        : QPushButton(icon, text, parent) {
        this->setProperty("btnType", "danger");
    }
    ~DangerButton() = default;
};
}  // namespace file_batcher::controls
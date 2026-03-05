#pragma once

#include <QPushButton>
namespace file_batcher::controls {
class PrimaryButton : public QPushButton {
    Q_OBJECT
public:
    explicit PrimaryButton(QWidget* parent = nullptr) : QPushButton(parent) {
        this->setProperty("btnType", "primary");
    }
    explicit PrimaryButton(const QString& text, QWidget* parent = nullptr)
        : QPushButton(text, parent) {
        this->setProperty("btnType", "primary");
    }
    PrimaryButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr)
        : QPushButton(icon, text, parent) {
        this->setProperty("btnType", "primary");
    }
    ~PrimaryButton() = default;
};
}  // namespace file_batcher::controls
#pragma once

#include <QPushButton>
namespace file_batcher::controls {
class SuccessButton : public QPushButton {
    Q_OBJECT
public:
    explicit SuccessButton(QWidget* parent = nullptr) : QPushButton(parent) {
        this->setProperty("btnType", "success");
    }
    explicit SuccessButton(const QString& text, QWidget* parent = nullptr)
        : QPushButton(text, parent) {
        this->setProperty("btnType", "success");
    }
    SuccessButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr)
        : QPushButton(icon, text, parent) {
        this->setProperty("btnType", "success");
    }
    ~SuccessButton() = default;
};
}  // namespace file_batcher::controls
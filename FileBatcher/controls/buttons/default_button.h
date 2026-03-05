#pragma once

#include <QPushButton>

namespace file_batcher::controls {
class DefaultButton : public QPushButton {
    Q_OBJECT

public:
    explicit DefaultButton(QWidget* parent = nullptr) : QPushButton(parent) {
        this->setProperty("btnType", "default");
    }
    explicit DefaultButton(const QString& text, QWidget* parent = nullptr)
        : QPushButton(text, parent) {
        this->setProperty("btnType", "default");
    }
    DefaultButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr)
        : QPushButton(icon, text, parent) {
        this->setProperty("btnType", "default");
    }
    ~DefaultButton() = default;
};

}  // namespace file_batcher::controls
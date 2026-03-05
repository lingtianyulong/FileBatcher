#pragma once

#include <QPushButton>

namespace file_batcher::controls {
class DefaultButton : public QPushButton {
    Q_OBJECT

public:
    explicit DefaultButton(QWidget* parent = nullptr);
    explicit DefaultButton(const QString& text, QWidget* parent = nullptr);
    DefaultButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr);
    ~DefaultButton();
};

}  // namespace file_batcher::controls
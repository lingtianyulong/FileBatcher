#include "default_button.h"

namespace file_batcher::controls {

DefaultButton::DefaultButton(QWidget* parent) : QPushButton(parent) {
    this->setProperty("btnType", "default");
}

DefaultButton::DefaultButton(const QString& text, QWidget* parent) : QPushButton(text, parent) {
    this->setProperty("btnType", "default");
}

DefaultButton::DefaultButton(const QIcon& icon, const QString& text, QWidget* parent)
    : QPushButton(icon, text, parent) {
    this->setProperty("btnType", "default");
}

DefaultButton::~DefaultButton() {

};
}  // namespace file_batcher::controls
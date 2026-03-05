#include "mainwidget.h"

#include "../controls/buttons/primary_button.h"

#include <QVBoxLayout>

using namespace file_batcher::controls;

namespace file_batcher::ui {

MainWidget::MainWidget(QWidget* parent) : QWidget(parent) {
    PrimaryButton* primaryButton = new PrimaryButton("Test", this);
    primaryButton->setFixedSize(QSize(100, 40));
    this->setLayout(new QVBoxLayout(this));
    this->layout()->addWidget(primaryButton);
}

MainWidget::~MainWidget() = default;

}  // namespace file_batcher::ui
#include "mainwindow.h"

// #include "../controls/buttons/base_button.h"
#include "../controls/buttons/danger_button.h"
#include "../controls/buttons/default_button.h"
#include "../controls/buttons/info_button.h"
#include "../controls/buttons/primary_button.h"
#include "../controls/buttons/success_button.h"
#include "../controls/buttons/warning_button.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>


using namespace file_batcher::controls;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // BaseButton* baseButton = new BaseButton("Test", this);
    DefaultButton* button = new DefaultButton("Test", this);
    PrimaryButton* primaryButton = new PrimaryButton("Test", this);
    SuccessButton* successButton = new SuccessButton("Test", this);
    InfoButton* infoButton = new InfoButton("Test", this);
    WarningButton* warningButton = new WarningButton("Test", this);
    DangerButton* dangerButton = new DangerButton("Test", this);
    button->setFixedSize(QSize(100, 40));
    primaryButton->setFixedSize(QSize(100, 40));
    successButton->setFixedSize(QSize(100, 40));
    infoButton->setFixedSize(QSize(100, 40));
    warningButton->setFixedSize(QSize(100, 40));
    dangerButton->setFixedSize(QSize(100, 40));

    this->setCentralWidget(new QWidget(this));
    QVBoxLayout* layout = new QVBoxLayout(this->centralWidget());
    layout->addWidget(button);
    layout->addWidget(primaryButton);
    layout->addWidget(successButton);
    layout->addWidget(infoButton);
    layout->addWidget(warningButton);
    layout->addWidget(dangerButton);
    this->centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow() {
    delete ui;
}

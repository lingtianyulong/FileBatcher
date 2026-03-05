#include "mainwindow.h"

// #include "../controls/buttons/base_button.h"
#include "../controls/buttons/default_button.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

using namespace file_batcher::controls;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // BaseButton* baseButton = new BaseButton("Test", this);
    DefaultButton* button = new DefaultButton("Test", this);
    button->setFixedSize(QSize(100, 40));

    this->setCentralWidget(new QWidget(this));
    QVBoxLayout* layout = new QVBoxLayout(this->centralWidget());
    layout->addWidget(button);
    this->centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow() {
    delete ui;
}

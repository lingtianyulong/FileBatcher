#include "mainwindow.h"

#include "mainwidget.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

using namespace file_batcher::ui;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setMinimumSize(QSize(800, 600));
    this->resize(QSize(1280, 800));
    this->setWindowTitle("File Batcher");
    this->setWindowIcon(QIcon(":/icons/filebatcher.png"));

    MainWidget* mainWidget = new MainWidget(this);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

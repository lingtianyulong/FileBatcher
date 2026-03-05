#pragma once

#include <QWidget>

namespace file_batcher::ui {

class MainWidget : public QWidget {
    Q_OBJECT
public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget();
};

}  // namespace file_batcher::ui

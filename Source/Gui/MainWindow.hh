#pragma once

#include "GLWidget.hh"

#include <QMainWindow>

class MainWindow final
    : public QMainWindow
{
public:

    MainWindow();
    ~MainWindow() override;

private:

    GLWidget* m_GLWidget;
};

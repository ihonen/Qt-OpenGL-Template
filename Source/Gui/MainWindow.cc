#include "MainWindow.hh"

#include <QStatusBar>

MainWindow::MainWindow()
    : QMainWindow(nullptr)
    , m_GLWidget(new GLWidget(this))
{
    setCentralWidget(m_GLWidget);
}

MainWindow::~MainWindow() = default;

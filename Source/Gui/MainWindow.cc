#include "MainWindow.hh"

#include <QStatusBar>

MainWindow::MainWindow()
    : QMainWindow(nullptr)
    , m_GLWidget(new GLWidget)
{
    setCentralWidget(m_GLWidget);

    setStatusBar(new QStatusBar(this));
}

MainWindow::~MainWindow() = default;

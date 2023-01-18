extern "C" {
#include "Engine/Engine.h"
}

#include "Gui/MainWindow.hh"

#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    MainWindow window;
    window.show();

    return app.exec();
}

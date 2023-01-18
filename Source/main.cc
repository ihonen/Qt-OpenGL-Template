extern "C" {
#include "Engine/Engine.h"
}

#include <QApplication>
#include <QSurfaceFormat>

#include "Gui/glwidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    GLWidget window;
    window.show();

    Engine_init();

    return app.exec();
}

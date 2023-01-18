#include "GLWidget.hh"

extern "C" {
#include "../Engine/Engine.h"
}

GLWidget::~GLWidget()
{
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

void GLWidget::initializeGL()
{
    Engine_init();
}

void GLWidget::paintGL()
{
    Engine_render();
}

void GLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);

    Engine_setViewPort(
        (width  - side) / 2,
        (height - side) / 2,
        side,
        side
    );
}

void GLWidget::mousePressEvent(QMouseEvent* /*event*/)
{
}

void GLWidget::mouseMoveEvent(QMouseEvent* /*event*/)
{
}

void GLWidget::mouseReleaseEvent(QMouseEvent* /*event*/)
{
}

#include "GLWidget.hh"

extern "C" {
#include "../Renderer/Renderer.h"
}

GLWidget::~GLWidget()
{
    free(m_renderer);
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
    m_renderer = Renderer_init();
}

void GLWidget::paintGL()
{
    Renderer_doRender(m_renderer);
}

void GLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);

    Renderer_setViewPort(
        m_renderer,
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

#include "GLWidget.hh"

extern "C" {
#include "../Renderer/Renderer.h"
}

GLWidget::GLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
    m_renderer = Renderer_new();
}

GLWidget::~GLWidget()
{
    free(m_renderer);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

void GLWidget::initializeGL()
{
    Renderer_init(m_renderer);
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

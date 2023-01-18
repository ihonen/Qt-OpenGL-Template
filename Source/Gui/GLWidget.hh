#pragma once

#include <QOpenGLWidget>

class GLWidget final
    : public QOpenGLWidget
{
    Q_OBJECT

public:

    using QOpenGLWidget::QOpenGLWidget;
    ~GLWidget();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

protected:

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
};

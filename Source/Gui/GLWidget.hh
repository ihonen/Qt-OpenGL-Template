#pragma once

#include <QOpenGLWidget>

struct Renderer;

class GLWidget final
    : public QOpenGLWidget
{
    Q_OBJECT

public:

    GLWidget(QWidget* parent);
    ~GLWidget() override;

    QSize sizeHint() const override;

protected:

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:

    struct Renderer* m_renderer;
};

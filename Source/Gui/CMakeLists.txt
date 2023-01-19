find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)

set(CMAKE_AUTOMOC ON)

add_library(Example-Gui STATIC
    GLWidget.cc
    MainWindow.cc
)
target_link_libraries(Example-Gui
    PUBLIC Qt::Core
    PUBLIC Qt::Gui
    PUBLIC Qt::OpenGL
    PUBLIC Qt::OpenGLWidgets
)
target_link_libraries(Example-Gui
    PUBLIC Example-Renderer
    PUBLIC gl3w-static
)

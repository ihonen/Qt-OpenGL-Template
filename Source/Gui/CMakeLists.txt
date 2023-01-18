find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)

set(CMAKE_AUTOMOC ON)

add_library(Qt-OpenGL-Example-Gui STATIC
    GLWidget.cc
)
target_link_libraries(Qt-OpenGL-Example-Gui
    PUBLIC Qt::Core
    PUBLIC Qt::Gui
    PUBLIC Qt::OpenGL
    PUBLIC Qt::OpenGLWidgets
)
target_link_libraries(Qt-OpenGL-Example-Gui
    PUBLIC gl3w-static
    PUBLIC Qt-OpenGL-Example-Engine
)

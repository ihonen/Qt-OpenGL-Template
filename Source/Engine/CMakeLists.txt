find_package(OpenGL)

################################################################################

add_library(Qt-OpenGL-Example-Engine STATIC
    Engine.c
)
target_link_libraries(Qt-OpenGL-Example-Engine
    PUBLIC ${OPENGL_LIBRARIES}
    PUBLIC gl3w-static
)

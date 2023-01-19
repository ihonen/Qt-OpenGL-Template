add_library(Example-Renderer STATIC
    Renderer.c
)
target_link_libraries(Example-Renderer
    PUBLIC ${OPENGL_LIBRARIES}
    PUBLIC gl3w-static
)

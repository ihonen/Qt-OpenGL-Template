include(ExternalProject)

################################################################################
# OpenGL
################################################################################

find_package(OpenGL REQUIRED)

################################################################################
# gl3w
################################################################################

add_library(gl3w-static STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/gl3w/gen/src/gl3w.c
)
target_include_directories(gl3w-static
    PUBLIC gl3w/gen/include
)
target_link_libraries(gl3w-static
    PUBLIC ${OPENGL_LIBRARIES}
)

add_subdirectory(Engine)
add_subdirectory(Gui)

################################################################################

add_executable(Qt-OpenGL-Example
    main.cc
)
target_include_directories(Qt-OpenGL-Example
    PUBLIC Extern/gl3w/include
)
target_link_libraries(Qt-OpenGL-Example
    PUBLIC Qt-OpenGL-Example-Engine
    PUBLIC Qt-OpenGL-Example-Gui
)

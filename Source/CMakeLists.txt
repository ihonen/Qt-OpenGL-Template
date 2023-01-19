add_subdirectory(Gui)
add_subdirectory(Renderer)

################################################################################

add_executable(Example-App
    main.cc
)
target_include_directories(Example-App
    PUBLIC Extern/gl3w/include
)
target_link_libraries(Example-App
    PUBLIC Example-Gui
    PUBLIC Example-Renderer
)

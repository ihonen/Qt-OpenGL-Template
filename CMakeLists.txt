cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(Qt-OpenGL-Template)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_POLICY_DEFAULT_CMP0072 NEW)
cmake_policy(SET CMP0072 NEW)

################################################################################

add_subdirectory(Extern)
add_subdirectory(Source)

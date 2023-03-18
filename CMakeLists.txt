cmake_minimum_required(VERSION 3.24)
project(opengl_c C)

set(CMAKE_C_STANDARD 11)

add_executable(opengl_c main.c src/test/test.c)

target_include_directories(opengl_c PRIVATE src/)

add_library(src_lib STATIC src/test/test.c)
target_include_directories(src_lib PUBLIC src/)
target_link_libraries(opengl_c PRIVATE src_lib)

add_library(glad_lib STATIC libraries/glad.c)
target_include_directories(glad_lib PUBLIC include/glad/)
target_link_libraries(opengl_c PRIVATE glad_lib)

target_link_libraries(opengl_c PUBLIC GL dl glfw)
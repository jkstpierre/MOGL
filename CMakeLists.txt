# Modern OpenGL Project #

cmake_minimum_required(VERSION 3.18)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/examples)

# MOGL Library

project(MOGL)

file(GLOB_RECURSE mogl_c_src ${CMAKE_SOURCE_DIR}/src/mogl/*.c)
file(GLOB_RECURSE mogl_cpp_src ${CMAKE_SOURCE_DIR}/src/mogl/*.cpp)
add_library(MOGL ${mogl_c_src} ${mogl_cpp_src})

target_include_directories(MOGL PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(MOGL PUBLIC cxx_std_20)
target_compile_options(MOGL PUBLIC "$<$<CONFIG:DEBUG>:-Wall -Wextra -Werror -g -pg>")
target_compile_options(MOGL PUBLIC "$<$<CONFIG:RELEASE>:-Wall -Wextra -Werror -O3>")

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)

target_link_libraries(MOGL ${OPENGL_LIBRARIES} ${X11_LIBRARIES} ${CMAKE_DL_LIBS})

# Examples

project(Ex1)

file(GLOB_RECURSE ex1_cpp_src ${CMAKE_SOURCE_DIR}/examples/src/ex1/*.cpp)
add_executable(Ex1 ${ex1_cpp_src})

target_include_directories(Ex1 PRIVATE ${CMAKE_SOURCE_DIR}/examples/include)

target_compile_features(Ex1 PRIVATE cxx_std_20)
target_compile_options(Ex1 PRIVATE "$<$<CONFIG:DEBUG>:-Wall -Wextra -Werror -g -pg>")
target_compile_options(Ex1 PRIVATE "$<$<CONFIG:RELEASE>:-Wall -Wextra -Werror -O3>")

target_link_libraries(Ex1 MOGL)
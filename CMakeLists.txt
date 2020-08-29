# Modern OpenGL Project #

cmake_minimum_required(VERSION 3.17)

# Set flags for compilation

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/examples)

if (GNU)
set (DEBUG_COMPILER_OPTIONS "-Wall -Wextra -Werror -g -pg")
set (RELEASE_COMPILER_OPTIONS "-Wall -Wextra -Werror -O3")
endif(GNU)

if (MSVC)
set (DEBUG_COMPILER_OPTIONS "/MDd /Zi /Ob0 /Od /RTC1")
set (RELEASE_COMPILER_OPTIONS "/MD /O2 /Ob2 /DNDEBUG")
endif (MSVC)

# mogl Library

project(mogl)

file(GLOB_RECURSE mogl_c_src ${CMAKE_SOURCE_DIR}/src/mogl/*.c)
file(GLOB_RECURSE mogl_cpp_src ${CMAKE_SOURCE_DIR}/src/mogl/*.cpp)
add_library(mogl ${mogl_c_src} ${mogl_cpp_src})

target_include_directories(mogl PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(mogl PUBLIC cxx_std_20)
target_compile_options(mogl PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_COMPILER_OPTIONS}>")
target_compile_options(mogl PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_COMPILER_OPTIONS}>")

find_package(OpenGL REQUIRED)

if (UNIX)
find_package(X11 REQUIRED)
target_link_libraries(mogl ${OPENGL_LIBRARIES} ${X11_LIBRARIES} ${CMAKE_DL_LIBS})
else()
target_link_libraries(mogl ${OPENGL_LIBRARIES})
endif()

# Examples

project(Ex1)

file(GLOB_RECURSE ex1_cpp_src ${CMAKE_SOURCE_DIR}/examples/src/ex1/*.cpp)
if (WIN32)
add_executable(Ex1 WIN32 ${ex1_cpp_src})
else()
add_executable(Ex1 ${ex1_cpp_src})
endif()

target_include_directories(Ex1 PRIVATE ${CMAKE_SOURCE_DIR}/examples/include)

target_compile_features(Ex1 PRIVATE cxx_std_20)
target_compile_options(Ex1 PRIVATE "$<$<CONFIG:DEBUG>:${DEBUG_COMPILER_OPTIONS}>")
target_compile_options(Ex1 PRIVATE "$<$<CONFIG:RELEASE>:${RELEASE_COMPILER_OPTIONS}>")

target_link_libraries(Ex1 mogl)
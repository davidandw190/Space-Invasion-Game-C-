cmake_minimum_required(VERSION 3.25)
project(PP_SPACE_INVASION)

set(CMAKE_CXX_STANDARD 17)

add_executable(PP_SPACE_INVASION Source/main.cpp)

#include_directories(Source/Headers c:/SFML/include)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)

target_link_libraries(PP_SPACE_INVASION sfml-system sfml-window sfml-graphics sfml-audio)
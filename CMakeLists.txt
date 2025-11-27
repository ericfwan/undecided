cmake_minimum_required(VERSION 3.16)
project(Undecided)

set(CMAKE_CXX_STANDARD 17)

# Add source and include directories
include_directories(include)
file(GLOB_RECURSE SOURCES src/*.cpp)

# Find SFML
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

add_executable(Undecided ${SOURCES})

target_link_libraries(Undecided sfml-system sfml-window sfml-graphics sfml-audio)

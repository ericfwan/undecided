cmake_minimum_required(VERSION 3.18)
project(Undecided LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)

include_directories(include)

file(GLOB SRC "src/*.cpp")
add_executable(Undecided ${SRC})

target_link_libraries(Undecided PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

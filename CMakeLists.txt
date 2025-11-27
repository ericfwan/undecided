cmake_minimum_required(VERSION 3.16)
project(Undecided)

set(CMAKE_CXX_STANDARD 17)

# Absolute path to the actual SFML 2.6.2 config directory
set(SFML_DIR "/opt/homebrew/Cellar/sfml@2/2.6.2_1/lib/cmake/SFML")

# Add this so CMake searches the folder
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/sfml@2/2.6.2_1")

# Add source and include directories
include_directories(include)
file(GLOB_RECURSE SOURCES src/*.cpp)

# Find SFML 2.6 components
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

add_executable(Undecided ${SOURCES})

target_link_libraries(Undecided sfml-system sfml-window sfml-graphics sfml-audio)

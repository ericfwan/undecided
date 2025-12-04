cmake_minimum_required(VERSION 3.16)
project(Undecided)

set(CMAKE_CXX_STANDARD 17)

# SFML (Homebrew path on Mac)
set(SFML_DIR "/opt/homebrew/Cellar/sfml@2/2.6.2_1/lib/cmake/SFML")
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/sfml@2/2.6.2_1")

include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/ui/*.cpp
    src/scenes/*.cpp
)

# Copy assets into build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# SFML
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

# Executable
add_executable(Undecided ${SOURCES})

# Link libraries
target_link_libraries(Undecided
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

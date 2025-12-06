cmake_minimum_required(VERSION 3.11)
project(Undecided)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------------
# SFML (Homebrew installation)
# -------------------------------------------------------------
set(SFML_DIR "/opt/homebrew/Cellar/sfml@2/2.6.2_1/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

# -------------------------------------------------------------
# Source files
# -------------------------------------------------------------
file(GLOB_RECURSE SRC_FILES
    "src/*.cpp"
)

# -------------------------------------------------------------
# Executable
# -------------------------------------------------------------
add_executable(undecided ${SRC_FILES})

target_include_directories(undecided PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(undecided
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

# -------------------------------------------------------------
# Copy assets folder to build directory after build
# -------------------------------------------------------------
add_custom_command(TARGET undecided POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_CURRENT_BINARY_DIR}/assets
)

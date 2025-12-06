cmake_minimum_required(VERSION 3.11)
project(Undecided)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------------
# SFML
# Try normal discovery first, then fallback to Homebrew stable path.
# -------------------------------------------------------------
find_package(SFML 2.6 COMPONENTS system window graphics audio QUIET)

if(NOT SFML_FOUND)
    # Homebrew stable alias path (less version-fragile)
    set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")
    find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)
endif()

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
# Copy assets next to the executable after build
# This makes running from build/ reliable.
# -------------------------------------------------------------
add_custom_command(TARGET undecided POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:undecided>/assets
)

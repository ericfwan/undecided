cmake_minimum_required(VERSION 3.11)
project(undecided)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

add_subdirectory("lib/SFML")
set(SFML_INCS "lib/SFML/include")
set(INCLUDE "include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

# Use GLOB_RECURSE to find all .cpp files in subfolders too!
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE INCLUDES "include/*.hpp")

add_executable(undecided
        ${SOURCES}
        ${INCLUDES}
        src/physics/RigidBody.cpp
        include/scenes/Renderer.hpp
        src/scenes/Renderer.cpp
        include/physics/Controller.hpp
        src/physics/Controller.cpp
        include/physics/Entities.hpp
        src/physics/Entities.cpp
)


target_include_directories(undecided PRIVATE
        ${SFML_INCS}
        ${INCLUDE}
)
target_link_libraries(undecided
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)

add_custom_command(TARGET undecided POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets/
        ${CMAKE_CURRENT_BINARY_DIR}/bin
)


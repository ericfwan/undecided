cmake_minimum_required(VERSION 3.11)
project(setup)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Setup Directories
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

#Output all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#Add External Dependencies
add_subdirectory("lib/SFML")
set(SFML_INC "lib/SFML/include")
set(MY_INCLUDE "include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")


file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE INCLUDE "include/*.hpp")
add_executable(undecided ${SOURCES} ${INCLUDE}
        src/scenes/SceneMAnager.cpp)
target_include_directories(undecided PRIVATE
        ${SFML_INC}
        ${MY_INCLUDE})
target_link_libraries(undecided sfml-graphics)
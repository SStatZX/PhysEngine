cmake_minimum_required(VERSION 3.0.0)
project(alteon VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(dependencies) # Dependencies contains its own CMakeLists.txt that uses FetchContent to get the dependencies ImGUI and SFML

file(GLOB_RECURSE SOURCES src/*.cpp ) # Add all sources in src that end in .cpp
add_executable(alteon ${SOURCES}) # Add them to the executable
target_include_directories(alteon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # Add /include as a include directory

target_link_libraries(alteon # Link the libraries to the main project
    PUBLIC
        ImGui-SFML::ImGui-SFML
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

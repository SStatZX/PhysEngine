cmake_minimum_required(VERSION 3.0.0)
project(alteon VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# add_subdirectory(include)
file(GLOB_RECURSE SOURCES src/*.cpp )
add_executable(alteon ${SOURCES})
target_include_directories(alteon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

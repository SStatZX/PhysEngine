cmake_minimum_required(VERSION 3.0.0)
project(alteon VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(dependencies)

# find_package(OpenGL REQUIRED)
# find_package(GLUT REQUIRED)
# find_package(GLEW REQUIRED)
# find_package(glfw3 REQUIRED)
# set(ImGUI-SFML_DIR /usr/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake)
# find_package(imgui REQUIRED)
# find_package(ImGui-SFML REQUIRED)
# find_package(EnTT REQUIRED)



file(GLOB_RECURSE SOURCES src/*.cpp )
add_executable(alteon ${SOURCES})
target_include_directories(alteon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS}  )
target_link_libraries(alteon 
    PUBLIC
        ImGui-SFML::ImGui-SFML
        # EnTT::EnTT
)
# OpenGL::OpenGL GLUT::GLUT GLEW::GLEW glfw
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


# find_package(OpenGL REQUIRED)
# find_package(GLUT REQUIRED)
# include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

# target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

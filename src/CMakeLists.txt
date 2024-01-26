file(GLOB_RECURSE SOURCES *.cpp *.h *.hpp)

add_executable(alteon ${SOURCES})
target_include_directories(alteon PRIVATE .)
target_link_libraries(alteon PRIVATE

    )
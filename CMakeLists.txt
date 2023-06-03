cmake_minimum_required(VERSION 3.21)

project(raygame LANGUAGES C VERSION 0.0.1)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/raylib)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/rayengine)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib rayengine)
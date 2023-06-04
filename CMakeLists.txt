cmake_minimum_required(VERSION 3.21)

project(raygame LANGUAGES C VERSION 0.0.1)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)

set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(ASSETS_DEST_DIR "${CMAKE_BINARY_DIR}/assets")

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/raylib)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/rayengine)

add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_command(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory
        ${ASSETS_DEST_DIR}
        COMMENT "Removing previous assets directory"
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${ASSETS_DIR}
        ${ASSETS_DEST_DIR}
        COMMENT "Copying assets to output directory"
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib rayengine)
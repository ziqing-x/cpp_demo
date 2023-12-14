project(app)
file(
    GLOB_RECURSE OBJ_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx
)
add_library(
    ${PROJECT_NAME}
    STATIC
    ${OBJ_SRCS}
    )
add_library(
    local::${PROJECT_NAME}
    ALIAS
    ${PROJECT_NAME}
    )
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/manager
    ${CMAKE_CURRENT_SOURCE_DIR}/network

    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/updater
)
find_package(Threads REQUIRED)
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    Threads::Threads

    PUBLIC
    third::spdlog
    third::json
)
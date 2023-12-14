project(json)

add_library(
    ${PROJECT_NAME} INTERFACE
)
add_library(
    third::${PROJECT_NAME} ALIAS
    ${PROJECT_NAME}
)
target_include_directories(
    ${PROJECT_NAME} INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

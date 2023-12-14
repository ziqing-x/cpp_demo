add_executable(
    ${APP_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
target_link_libraries(
    ${APP_NAME} PRIVATE
    local::app
)
set_target_properties(
    ${APP_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_subdirectory(app)
add_subdirectory(3party/json)
add_subdirectory(3party/spdlog)
if (ENABLE_TEST)
    add_subdirectory(3party/doctest)
    add_subdirectory(test)
endif()
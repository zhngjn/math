cmake_minimum_required(VERSION 3.16)

add_library(model SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/fake_map/*.cpp
)

target_include_directories(model
PUBLIC
    ${PROJECT_SOURCE_DIR}/third_party/include
    ${PROJECT_SOURCE_DIR}/include/model
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(model
    geometry
)
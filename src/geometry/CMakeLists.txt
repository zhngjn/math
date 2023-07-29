cmake_minimum_required(VERSION 3.16)

file(GLOB ELEMENTS_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/elements/*.cpp")
file(GLOB CALCULATION_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/calculation/*.cpp")
file(GLOB DUMP_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/dump/*.cpp")

add_library(geometry SHARED
    ${ELEMENTS_SRCS}
    ${CALCULATION_SRCS}
    ${DUMP_SRCS}
)

target_include_directories(geometry
PUBLIC
    ${PROJECT_SOURCE_DIR}/include/geometry
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(geometry
PUBLIC
    util
)
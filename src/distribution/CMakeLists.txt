cmake_minimum_required(VERSION 3.16)

file(GLOB DISTRIBUTION_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(distribution SHARED
    ${DISTRIBUTION_SRCS}
)

target_include_directories(distribution
PUBLIC
    ${PROJECT_SOURCE_DIR}/include/distribution
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(distribution
PUBLIC
    util
)
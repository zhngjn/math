cmake_minimum_required(VERSION 3.16)

find_package(GTest REQUIRED)
set(GTEST_LIBS GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(GLOB TEST_GEOMETRY_SRCS 
    "${CMAKE_CURRENT_SOURCE_DIR}/geometry/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/geometry/elements/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/geometry/util/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/geometry/calculation/*.cpp"
)

add_executable(test_geometry
    ${TEST_GEOMETRY_SRCS}
)

target_link_libraries(test_geometry
    geometry
    ${GTEST_LIBS}
)

file(GLOB TEST_UTIL_SRCS 
    "${CMAKE_CURRENT_SOURCE_DIR}/util/*.cpp"
)

add_executable(test_util
    ${TEST_UTIL_SRCS}
)

target_link_libraries(test_util
    util
    ${GTEST_LIBS}
)

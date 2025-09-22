add_executable(${CMAKE_PROJECT_NAME}_tests
    read_input_test.cpp
    checksum_test.cpp
    bit_pattern_test.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}_tests
    PRIVATE
    ${CMAKE_PROJECT_NAME}_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_tests)
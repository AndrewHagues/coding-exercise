add_executable(${CMAKE_PROJECT_NAME}_tests
    read_input_test.cpp
    checksum_test.cpp
    bit_pattern_test.cpp
    write_png_images_test.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}_tests
    PRIVATE
    ${CMAKE_PROJECT_NAME}_lib
    GTest::gtest_main
)

# Provide absolute path to tests directory for locating test data assets
target_compile_definitions(${CMAKE_PROJECT_NAME}_tests
    PRIVATE TEST_DATA_DIR="${CMAKE_SOURCE_DIR}/tests/data")

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_tests)
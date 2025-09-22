include(FetchContent)

FetchContent_Declare(
    lodepng
    GIT_REPOSITORY https://github.com/lvandeve/lodepng.git
    GIT_TAG master 
)
FetchContent_MakeAvailable(lodepng)

# Make a CMake target for lodepng
add_library(lodepng STATIC ${lodepng_SOURCE_DIR}/lodepng.cpp)
target_include_directories(lodepng PUBLIC ${lodepng_SOURCE_DIR})

# Build the main coding exercise library
add_library(CodingExercise_lib
    read_input.cpp
    checksum.cpp
    bit_pattern.cpp
    write_png_images.cpp
)
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)

# Link in lodepng
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC 
    lodepng
)

# Bulild the main executable (solution)
add_executable(solution
    main.cpp
)
target_link_libraries(solution PRIVATE 
    ${CMAKE_PROJECT_NAME}_lib
)
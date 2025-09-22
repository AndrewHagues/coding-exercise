find_program(CPPCHECK cppcheck)

if (CPPCHECK)
    message(STATUS "Found cppcheck: ${CPPCHECK}")

    set (INCLUDES 
        -I${CMAKE_SOURCE_DIR}/include
        -I${CMAKE_SOURCE_DIR}/build/_deps/lodepng-src
    )

    add_test(
        NAME cppcheck
        COMMAND ${CPPCHECK} 
            --enable=warning,performance,portability 
            --std=c++20 
            --language=c++ 
            --quiet
            --suppress=missingIncludeSystem
            --suppress=toomanyconfigs
            --error-exitcode=1 
            ${INCLUDES}
            ${CMAKE_SOURCE_DIR}/src
    )
    set_tests_properties(cppcheck PROPERTIES LABELS "static_analysis")
else()
    message(WARNING "cppcheck not found")
endif()
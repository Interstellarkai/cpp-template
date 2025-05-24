cmake_minimum_required(VERSION 3.31)

#
# Project details
#

project(
  ${CMAKE_PROJECT_NAME}Tests
  LANGUAGES CXX
)

# Set C++20 as the standard for tests
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

verbose_message("Adding tests under ${CMAKE_PROJECT_NAME}Tests...")

# Enable testing
enable_testing()

# Add test executable for each day
foreach(YEAR ${ADVENT_YEARS})
    foreach(DAY ${ADVENT_DAYS})
        set(DAY_NAME "day${DAY}")
        set(DAY_TEST "advent_of_code/${YEAR}/${DAY_NAME}_test.cpp")
        
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${DAY_TEST}")
            add_executable(${YEAR}_${DAY_NAME}_test ${DAY_TEST})
            set_target_properties(${YEAR}_${DAY_NAME}_test PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
            )
            target_link_libraries(${YEAR}_${DAY_NAME}_test
                PRIVATE
                ${YEAR}_${DAY_NAME}_lib
                GTest::gtest_main
                GTest::gmock_main
            )
            target_include_directories(${YEAR}_${DAY_NAME}_test
                PRIVATE
                ${CMAKE_SOURCE_DIR}/include
                ${CMAKE_SOURCE_DIR}/src
            )
            add_test(NAME ${YEAR}_${DAY_NAME}_test COMMAND ${YEAR}_${DAY_NAME}_test)
        endif()
    endforeach()
endforeach()

verbose_message("Finished adding unit tests for ${CMAKE_PROJECT_NAME}.")

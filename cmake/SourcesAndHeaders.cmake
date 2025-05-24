# Find all Advent of Code source files
file(GLOB_RECURSE advent_sources 
    "src/advent_of_code/*/*.cpp"
)

# Find all Advent of Code headers
file(GLOB_RECURSE advent_headers 
    "src/advent_of_code/*/*.hpp"
)

# Find all test sources
file(GLOB_RECURSE test_sources 
    "test/advent_of_code/*/*.cpp"
)

# Filter out main.cpp files from advent_sources
file(GLOB_RECURSE main_sources
    "src/advent_of_code/*/main.cpp"
)
list(REMOVE_ITEM advent_sources ${main_sources})

set(sources
    ${advent_sources}
)

# We don't need exe_sources anymore since each day is its own executable
set(exe_sources "")

set(headers
    ${advent_headers}
)

set(test_sources
    ${test_sources}
)

# Add include directories for all targets
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

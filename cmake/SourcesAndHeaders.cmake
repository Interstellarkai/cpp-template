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

set(sources
    ${advent_sources}
)

set(exe_sources
    ${advent_sources}
)

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

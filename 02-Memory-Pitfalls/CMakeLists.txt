cmake_minimum_required(VERSION 3.10)
project(MEMORY_OPS LANGUAGES C CXX)

add_executable(MEMORY_OPS main.cpp)

target_include_directories(MEMORY_OPS PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

set_target_properties(MEMORY_OPS PROPERTIES
    CXX_STANDARD            17
    CXX_STANDARD_REQUIRED   YES
    OUTPUT_NAME             memory_operations
    RUN_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR})

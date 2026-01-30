cmake_minimum_required(VERSION 3.10)
project(PERFTRC LANGUAGES C CXX)

add_library(TracerLib src/Tracer.cpp)

target_compile_features(TracerLib PUBLIC cxx_std_17)

target_include_directories(TracerLib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:inc>)

add_executable(PERFTRC main.cpp)

target_link_libraries(PERFTRC PRIVATE TracerLib)

set_target_properties(PERFTRC PROPERTIES
    CXX_STANDARD            17
    CXX_STANDARD_REQUIRED   YES
    OUTPUT_NAME             performance_tracker
    RUN_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR})

install(TARGETS TracerLib DESTINATION lib)
install(FILES include/Tracer.h DESTINATION include)

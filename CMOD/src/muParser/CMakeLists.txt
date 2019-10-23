file(GLOB_RECURSE muParser_sources "*.cpp")

add_library(muparser STATIC ${muParser_sources})
target_include_directories(muparser PUBLIC "./")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
        OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(muparser PRIVATE
            -Wall
            -Wextra
            -Wswitch
            -Wconversion
            -Wparentheses
            -Wfloat-equal
            -Wzero-as-null-pointer-constant
            -Wpedantic
            -pedantic
            -pedantic-errors)
endif ()

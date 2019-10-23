add_library(parser STATIC lex.yy.c)
target_include_directories(parser PUBLIC "./")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
        OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(parser PRIVATE
            -Wall
            -Wextra
            -Wswitch
            -Wconversion
            -Wparentheses
            -Wfloat-equal
            -Wpedantic
            -pedantic
            -pedantic-errors)
endif ()

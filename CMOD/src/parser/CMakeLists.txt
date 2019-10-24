add_library(parser STATIC lex.yy.c Parser.cpp)
target_include_directories(parser PUBLIC "./")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
        OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(parser PRIVATE
            -Wall
            -Wextra
            -Wswitch
            -Wparentheses
            -Wfloat-equal
            -Wpedantic
            -Wno-unused-function
            -Wno-write-strings
            -pedantic
            -pedantic-errors)
endif ()

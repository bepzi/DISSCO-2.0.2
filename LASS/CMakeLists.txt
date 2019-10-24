file(GLOB lass_sources "src/*.cpp")

add_library(lass STATIC ${lass_sources})
target_include_directories(lass PUBLIC "src/")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
        OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(lass PRIVATE
            -Wall
            -Wextra
            -Wswitch
            -Wconversion
            -Wparentheses
            -Wfloat-equal
            -Wzero-as-null-pointer-constant
            -Wno-deprecated
            -Wpedantic
            -pedantic
            -pedantic-errors)
endif ()

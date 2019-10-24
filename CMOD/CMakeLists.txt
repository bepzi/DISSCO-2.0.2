add_subdirectory(src/muParser)
add_subdirectory(src/parser)

file(GLOB lcmod_sources "src/*.cpp")
list(FILTER lcmod_sources EXCLUDE REGEX "src/Main.*")

add_library(lcmod STATIC ${lcmod_sources})
target_include_directories(lcmod PUBLIC "src/")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
        OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(lcmod PRIVATE
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

add_executable(cmod "src/Main.cpp")
target_link_libraries(cmod PRIVATE lcmod lass parser muparser Threads::Threads ${SNDFILE_LIBRARIES} ${XERCESC_LIBRARIES})
target_include_directories(cmod PRIVATE ${SNDFILE_INCLUDE_DIRS} ${XERCESC_INCLUDE_DIRS})

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
        OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(cmod PRIVATE
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

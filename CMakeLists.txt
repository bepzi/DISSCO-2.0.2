cmake_minimum_required(VERSION 3.1...3.15)
if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project(DISSCO
        VERSION 2.0.2
        LANGUAGES C CXX)

# add_subdirectory(LASSIE)
# add_subdirectory(LASS)
add_subdirectory(CMOD)

# add_executable(lassie main.cpp)
# target_include_directories(naivebayes PRIVATE ./)

# add_subdirectory(libbayes/)
# target_link_libraries(naivebayes libbayes)

set_target_properties(parser muparser PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)

# if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
#         OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
#     target_compile_options(naivebayes PRIVATE
#             -Wall
#             -Wextra
#             -Wswitch
#             -Wconversion
#             -Wparentheses
#             -Wfloat-equal
#             -Wzero-as-null-pointer-constant
#             -Wpedantic
#             -pedantic
#             -pedantic-errors)
# elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
#     target_compile_options(naivebayes PRIVATE
#             /W3)
# endif ()

cmake_minimum_required(VERSION 3.1...3.16)
if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project(DISSCO
        VERSION 2.0.2
        LANGUAGES C CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)
pkg_check_modules(SNDFILE sndfile)
pkg_check_modules(XERCESC xerces-c)

# TODO: Delete all occurences of -Wno-deprecated and fix those warnings

# TODO: This is only because LASSIE directly calls the CMOD executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

add_subdirectory(LASSIE)
add_subdirectory(LASS)
add_subdirectory(CMOD)

set_target_properties(parser muparser lcmod cmod lass lassie PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS ON
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)

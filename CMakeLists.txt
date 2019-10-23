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

set_target_properties(parser muparser PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS ON  # TODO: Don't rely on GNU extensions
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)

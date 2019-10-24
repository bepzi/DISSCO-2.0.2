file(GLOB lassie_sources "src/*.cpp")
list(FILTER lassie_sources EXCLUDE REGEX "UpgradeProjectFormat.*")

add_executable(lassie ${lassie_sources})
target_link_libraries(lassie PRIVATE lcmod lass parser muparser Threads::Threads ${GTKMM_LIBRARIES} ${SNDFILE_LIBRARIES} ${XERCESC_LIBRARIES})
target_include_directories(lassie PRIVATE ${GTKMM_INCLUDE_DIRS} ${SNDFILE_INCLUDE_DIRS} ${XERCESC_INCLUDE_DIRS})

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
        OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(lassie PRIVATE
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

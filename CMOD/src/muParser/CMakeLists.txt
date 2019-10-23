file(GLOB_RECURSE muParser_sources "*.cpp")

add_library(muparser STATIC ${muParser_sources})
target_include_directories(muparser PUBLIC "./")

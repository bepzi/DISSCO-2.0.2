add_library(parser STATIC lex.yy.c)
target_include_directories(parser PUBLIC "./")

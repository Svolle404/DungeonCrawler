add_executable(main main.c)
add_library(library library.c)
target_link_libraries(main library)
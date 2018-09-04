cmake_minimum_required(VERSION 3.9)

add_subdirectory(libft)

aux_source_directory(src SRC)
set(HEADERS includes/filler.h)
add_executable(vzomber_filler ${SRC} ${HEADERS})
target_link_libraries(vzomber_filler ft)
target_include_directories(vzomber_filler PUBLIC libft/libftsrc libft/includes includes)
cmake_minimum_required(VERSION 3.13.2)
project(Fractol C)

set(CMAKE_C_STANDARD 99)

# Directories where compiler will search for includes files
include_directories(includes)
include_directories(lib/libft/includes)

# Linux
include_directories(lib/minilibx)

# OSX
#include_directories(lib/minilibx_macos)

add_executable(Fractol
        src/main.c
        includes/fractol.h
        includes/events.h
        includes/colors.h
        src/meta.c
        src/colors.c
        src/image.c
        src/drawer.c
        src/events/keyboard.c
        src/events/mouse.c
        src/fractal.c
        src/fractals/mandelbrot.c
        src/fractals/julia.c
        src/zoom.c
        src/helper.c
        src/fractals/burningship.c
        src/fractals/unknown.c
        src/palette.c
        src/palette2.c
        src/fractals/spider.c
        src/fractals/thorn.c
        src/fractals/frothy.c
        src/fractals/biomorph.c)

add_definitions(-Wall -Wextra -Werror -g)
add_definitions(-O3)

#add_subdirectory(lib/libft)

# OSX
#target_link_libraries(Fractol "-framework AppKit")
#target_link_libraries(Fractol "-framework OpenGL")
#target_link_libraries(Fractol mlx)
#target_link_libraries(Fractol ${CMAKE_SOURCE_DIR}/lib/minilibx_macos/libmlx.a)

# Linux
target_link_libraries(Fractol Xext)
target_link_libraries(Fractol X11)
target_link_libraries(Fractol pthread)
target_link_libraries(Fractol ${CMAKE_SOURCE_DIR}/lib/minilibx/libmlx.a)
target_link_libraries(Fractol ${CMAKE_SOURCE_DIR}/lib/libft/libft.a)

target_link_libraries(Fractol m)
#target_link_libraries(Fractol libft)

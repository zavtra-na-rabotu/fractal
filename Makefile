TARGET		= fractol
OS			= $(shell uname)


# Directories
SRCS_DIR	= ./src
OBJS_DIR	= ./obj
FT_DIR		= ./lib/libft
MLX_DIR		= ./lib/minilibx


# Sources
SRC_FILES	= colors.c \
			  drawer.c \
			  fractal.c \
			  helper.c \
			  image.c \
			  main.c \
			  meta.c \
			  palette.c \
			  palette2.c \
			  zoom.c \
			  events/keyboard.c \
			  events/mouse.c \
			  fractals/burningship.c \
			  fractals/julia.c \
			  fractals/mandelbrot.c \
			  fractals/unknown.c \
			  fractals/spider.c \
			  fractals/biomorph.c \
			  fractals/thorn.c \
			  fractals/frothy.c

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:c=o))


# Includes
INCL		= -I ./includes
FT_INCL		= -I ./lib/libft/includes
MLX_INCL	= -I ./lib/minilibx


# Libraries
FT_LIB		= $(FT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/mlx.a
LIBS_LINK	= -L $(FT_DIR) -lm -lft -lpthread
ifeq ($(OS), Linux)
	MLX_LINK = -L $(MLX_DIR) -lmlx_x86_64 -lXext -lX11
else
	MLX_LINK = -lmlx -framework OpenGL -framework AppKit
endif


# Compilation
COMPILER	= gcc
BUILD_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = $(BUILD_FLAGS) -g
O_FLAGS		= -Ofast


.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(FT_LIB) $(MLX_LIB) $(OBJS)
	@$(COMPILER) $(OBJS) $(MLX_LINK) $(LIBS_LINK) -o $(TARGET)
	@echo Relinking

$(FT_LIB):
	@make -C $(FT_DIR) > /dev/null

$(MLX_LIB):
	@make -C $(MLX_DIR) > /dev/null 2>&1

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/fractals
	@mkdir -p $(OBJS_DIR)/events
	@$(COMPILER) $(BUILD_FLAGS) $(O_FLAGS) $(MLX_INCL) $(FT_INCL) $(INCL) -o $@ -c $<
	@echo Recompiling $<

clean:
	@rm -rf $(OBJS_DIR) > /dev/null
	@make -C $(FT_DIR) clean > /dev/null
	@make -C $(MLX_DIR) clean > /dev/null

fclean: clean
	@rm -rf $(TARGET) > /dev/null
	@make -C $(FT_DIR) fclean > /dev/null

re: fclean all

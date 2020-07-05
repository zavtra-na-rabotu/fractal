TARGET		= libft.a


# Directories
SRCS_DIR	= ./src
OBJS_DIR	= ./obj


# Sources
SRC_FILES	= ft_atoi.c \
			  ft_bzero.c \
			  ft_ftoa.c \
			  ft_get_digits.c \
			  ft_handle_min.c \
			  ft_isalnum.c  \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_itoa.c \
			  ft_lstadd.c \
			  ft_lstcount.c \
			  ft_lstdel.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstreverse.c \
			  ft_memalloc.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memdel.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_power.c \
			  ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_putendl.c \
			  ft_putendl_fd.c \
			  ft_putnbr.c \
			  ft_putnbr_fd.c \
			  ft_putstr.c \
			  ft_putstr_fd.c \
			  ft_putwchar.c \
			  ft_round.c \
			  ft_strcat.c \
			  ft_strchr.c \
			  ft_strchrnul.c \
			  ft_strclr.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_strcut.c \
			  ft_strdel.c \
			  ft_strdup.c \
			  ft_strequ.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlen.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strncat.c \
			  ft_strncmp.c \
			  ft_strncpy.c \
			  ft_strndup.c \
			  ft_strnequ.c \
			  ft_strnew.c \
			  ft_strnstr.c \
			  ft_strpushfront.c \
			  ft_strrchr.c \
			  ft_strrev.c \
			  ft_strsplit.c \
			  ft_strstartswith.c \
			  ft_strstr.c \
			  ft_strsub.c \
			  ft_strtrim.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  get_next_line.c

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:c=o))


# Includes
INCL		= -I ./includes


# Compilation
COMPILER	= gcc
BUILD_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = $(BUILD_FLAGS) -g
O_FLAGS		= -O3


.PHONY: create_obj_directories all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	@ar rc $(TARGET) $(OBJS)
	@ranlib $(TARGET)
	@echo Relinking

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(COMPILER) $(BUILD_FLAGS) $(O_FLAGS) $(INCL) -o $@ -c $<
	@echo Recompiling $<

clean:
	@rm -rf $(OBJS_DIR) > /dev/null

fclean: clean
	@rm -rf $(TARGET) > /dev/null

re: fclean all

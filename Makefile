NAME = fdf

H_DIR = includes
C_DIR = src
O_DIR = obj
DIR_LIST = $(H_DIR) $(C_DIR) $(O_DIR)

H_FILES = $(NAME).h
C_FILES = main.c matrix_values.c rotate.c utils.c draw_line.c read_map.c \
			key_hook.c put_string.c mouse_hook.c
H_PATH = $(addprefix $(H_DIR)/, $(H_FILES))
C_PATHS = $(addprefix $(C_DIR)/, $(C_FILES))
OBJ_PATHS = $(addprefix $(O_DIR)/, $(patsubst %.c, %.o, $(C_FILES)))

LIBFT = libft/libft.a
LINKS = -lmlx -framework OpenGl -framework AppKit
CC = gcc
FLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): pre_requisites $(OBJ_PATHS)
	@touch pre_requisites
	@make -C libft
	$(CC) $(FLAGS) -I $(H_DIR) -o $@ $(OBJ_PATHS) $(LIBFT) $(LINKS)

$(OBJ_PATHS): $(O_DIR)/%.o:$(C_DIR)/%.c $(H_PATH)
	$(CC) $(C_FLAGS) -I $(H_DIR) -c $< -o $@

pre_requisites: $(DIR_LIST) $(H_PATHS) $(C_PATHS)

$(DIR_LIST):
	mkdir $@

$(H_PATH):
	touch $@

$(C_PATHS):
	touch $@

.PHONY: print_files
print_files:
	@echo "H paths:   $(H_PATHS)"
	@echo "C paths:   $(C_PATHS)"
	@echo "OBJ paths: $(OBJ_PATHS)"
	@echo "C flags:   $(C_FLAGS)"
	@echo ""

.PHONY: clean
clean:
	-@rm -f $(OBJ_PATHS)
	@make clean -C libft
	@echo "All object files are removed!"

.PHONY: fclean
fclean: clean
	-@rm -f $(NAME)
	@make fclean -C libft
	@echo "$(NAME) file is removed!"

.PHONY: re
re: fclean all
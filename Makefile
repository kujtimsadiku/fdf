# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 15:22:49 by ksadiku           #+#    #+#              #
#    Updated: 2022/05/16 14:16:17 by ksadiku          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

H_FOLDER		=	includes
C_FOLDER		=	src
OBJ_FOLDER		=	obj
FOLDER_LIST		=	$(H_FOLDER) $(C_FOLDER) $(OBJ_FOLDER)

H_FILES			=	$(NAME).h
C_FILES			=	matrix_values.c projection.c utils.c draw_line.c read_map.c \
					key_hook.c put_string.c mouse_hook.c main.c draw_map.c
H_PATHS			=	$(addprefix $(H_FOLDER)/, $(H_FILES))
C_PATHS			=	$(addprefix $(C_FOLDER)/, $(C_FILES))
OBJ_PATHS		=	$(addprefix $(OBJ_FOLDER)/, $(patsubst %.c, %.o, $(C_FILES)))

LINKS			=	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
C_FLAGS			=	-Wall -Wextra -Werror
FT_INC			=	-I libft/includes
FT_LIB			=	libft/libft.a
#C_FLAGS		+=	-g

.PHONY: all
all: $(NAME)

$(NAME): pre_requisites $(OBJ_PATHS)
	@touch pre_requisites
	@make -C libft
	cc $(C_FLAGS) -I $(H_FOLDER) $(FT_LIB) $(LINKS) -o $@ $(OBJ_PATHS)

$(OBJ_PATHS): $(OBJ_FOLDER)/%.o:$(C_FOLDER)/%.c $(H_PATHS)
	cc $(C_FLAGS) $(FT_INC) -I $(H_FOLDER) -c $< -o $@

pre_requisites: $(FOLDER_LIST) $(H_PATHS) $(C_PATHS)

$(FOLDER_LIST):
	@mkdir $@

$(H_PATHS):
	@touch $@

$(C_PATHS):
	@touch $@

.PHONY: print_files
print_files:
	@echo "H paths:   $(H_PATHS)"
	@echo "C paths:   $(C_PATHS)"
	@echo "OBJ paths: $(OBJ_PATHS)"
	@echo "C flags:   $(C_FLAGS)"
	@echo ""

.PHONY: clean
clean:
	-@rm -fd $(OBJ_PATHS)
	-@make clean -C libft
	@echo "All object files are removed!"

.PHONY: fclean
fclean: clean
	-@rm -f $(NAME)
	-@rm -fd $(OBJ_FOLDER)
	-@rm -f pre_requisites
	@make fclean -C libft
	@echo "$(NAME) file is removed!"

.PHONY: re
re: fclean all


NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = so_long.h
LIB_D = lib
MINI_LX_D = minilibx-linux
SRC = \
		check_errors.c \
		check_errors2.c \
		check_map.c	\
		get_next_line_utils.c \
		get_next_line.c \
		main.c 			\
		utils.c			\
		images.c		\
		key_hooks.c		\
		create_map.c
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o)) 


all: $(MLX_LIB)/libmlx_Linux.a lib/libft.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)  -L$(MINI_LX_D) -lmlx -L$(LIB_D) -lft -lXext -lX11 -Iget_next_line.h

$(OBJ_DIR)/%.o : %.c  
	$(CC) $(CFLAGS) -c -o $@ $< 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ): | $(OBJ_DIR)

lib/libft.a:
	make -C $(LIB_D)

$(MLX_LIB)/libmlx_Linux.a:
	@make -C $(MINI_LX_D)


clean: 
	@make -C $(LIB_D) clean
	@make -C $(MINI_LX_D) clean
	@rm -rf $(addprefix $(OBJ_DIR)/, *.o)

fclean: clean
	@make -C $(LIB_D) fclean
	@rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re



NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = so_long.h
LIB_D = lib
MINI_LX_D = minilibx-linux

OBJ = obj/check_errors.o \
		obj/check_errors2.o \
		obj/check_map.o	\
		obj/get_next_line_utils.o \
		obj/get_next_line.o \
		obj/main.o 			\
		obj/utils.o			\
		obj/images.o		\
		obj/key_hooks.o		\
		obj/create_map.o
 

all: $(MLX_LIB)/libmlx_Linux.a lib/libft.a $(NAME)

obj/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(MINI_LX_D) -lmlx -L$(LIB_D) -lft -lXext -lX11 -Iget_next_line.h

lib/libft.a:
	make -C $(LIB_D)

$(MLX_LIB)/libmlx_Linux.a:
	@make -C $(MINI_LX_D)


clean: 
	@make -C $(LIB_D) clean
	@make -C $(MINI_LX_D) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LIB_D) fclean
	@rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re


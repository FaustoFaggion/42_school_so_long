NAME			=	so_long

PATH_LIBFT		= 	./libraries/libft
LIBFT			= 	$(PATH_LIBFT)/libft.a

MLX_PATH		= 	./libraries/minilibx
MLX				= 	$(MLX_PATH)/libmlx.a

#lx11- controla video lm- matemática

CC				= 	clang
CFLAGS			= 	-Wall -Werror -Wextra
MLX_FLAGS		= 	-L. -lXext -L. -lX11 -L. -lm


#SRC_DIR			= 	sources
SRC		=	so_long.c \
					map_built.c \
					map_validation.c \
					map_to_win.c \
					img_setup.c \
					key_events.c \
					game_setup.c \
					#game_exit.c

#SRC				= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

#OBJ_DIR			= 	objects
OBJ				= 	$(SRC:.c=.o)

HEADER			= 	so_long.h

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)

$(MLX):
	make -C $(MLX_PATH)



	
clean:
	rm -rf $(OBJ)
	make -C $(PATH_LIBFT) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

#run:
#	gcc $(FLAGS) main_solong.c $(NAME) && ./a.out

#run_bonus:
#	gcc $(FLAGS) main_printf_bonus.c $(NAME) && ./a.out

#sanitize:
#	gcc $(CFLAGS) -fsanitize=address -g3 *.c && ./a.out

#valgrind:
#	gcc *.c
#	valgrind ./a.out

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

PATH_LIBFT		= 	./libraries/libft
LIBFT			= 	$(PATH_LIBFT)/libft.a

MLX_PATH		= 	./libraries/minilibx
MLX				= 	$(MLX_PATH)/libmlx.a

#lx11- controla video lm- matemática

CC				= 	clang
CFLAGS			= 	-Wall -Werror -Wextra
MLX_FLAGS		= 	-L. -lXext -L. -lX11 -L. -lm


SRC_DIR			= 	sources
SRC_FILES		=	so_long.c \
					map_built.c \
					map_validation.c \
					map_to_win.c \
					img_setup.c \
					key_events.c \
					game_setup.c \
					game_exit.c
SRC				= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_DIR_BONUS	=	sources_bonus
SRC_FILES_BONUS	=	so_long.c \
					map_built.c \
					map_validation.c \
					map_to_win.c \
					img_setup.c \
					key_events.c \
					game_setup.c \
					game_exit.c
SRC_BONUS				= 	$(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))

OBJ_DIR			= 	objects
OBJ				= 	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

OBJ_DIR_BONUS	= 	objects_bonus
OBJ_BONUS		= 	$(SRC:$(SRC_DIR_BONUS)%.c=$(OBJ_DIR_BONUS)/%.o)

HEADER			= 	$(SRC_DIR)/so_long.h
NEADER			=	$(SRC_DIR_BONUS)/so_long_bonus.h

FS				=   -fsanitize=address -g3 

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
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

sanitize:	$(LIBFT) $(MLX) $(OBJ) $(HEADER)
	$(CC) $(FS) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

valgrind: $(NAME)
	valgrind ./so_long ./basic.ber

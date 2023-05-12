NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGL -framework Appkit

RM = rm -f

SRC =	src/checkers.c \
		src/gameplay.c \
		src/handlers.c \
		src/so_long.c \
		src/movements.c \

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
MLX = ./minilibx_opengl_20191021/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C ft_printf
	@make -C minilibx_opengl_20191021
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	@make clean -C ./ft_printf
	@make clean -C ./minilibx_opengl_20191021
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	@make clean -C ./minilibx_opengl_20191021
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
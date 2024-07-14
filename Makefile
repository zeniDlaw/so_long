NAME = so_long

SRC = exec_src/so_long.c utils_src/utils_src.c utils_src/utils_src2.c map_src/map_engine.c map_src/map_engine2.c map_src/map_engine3.c map_src/map_engine4.c map_src/map_engine5.c dis_src/display_engine.c dis_src/display_engine2.c dis_src/display_engine3.c ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux

MLX_FLAGS = -L$(MLX_DIR) -L /usr/lib/x86_64-linux-gnu/ -lmlx -lXext -lX11 -lm -lbsd 


MLX = ./minilibx-linux/libmlx.a

LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf

all: $(NAME) 

$(NAME): $(OBJ)  $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTPRINTF) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -I$(LIBFTPRINTF_DIR) -c $< -o $@

$(MLX): 
	make -C ./minilibx-linux

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPRINTF_DIR) fclean

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus

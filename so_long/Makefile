CC = cc

SRC = main.c \
      load_map.c \
	  window_managment.c \
	  validate_map.c \
	  utils1.c \
	  utils2.c \
	  movement.c \
	  validate_utils.c\
      ./get_next_line/get_next_line.c \
      ./get_next_line/get_next_line_utils.c\

OBJS = $(SRC:.c=.o)

INCLUDES = -I/usr/include -Imlx_linux -I./libft -I./get_next_line

NAME = so_long

FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

MLX_FLAGS =  -Lmlx_linux -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

# Kompilierregel für .o-Dateien
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) ./libft/libft.a
	+$(MAKE) -Clibft
	+$(MAKE) -Cmlx_linux
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L./libft -lft

clean:
	+$(MAKE) -Clibft clean
	+$(MAKE) -Cmlx_linux clean
	rm -rf $(OBJS)

fclean:
	+$(MAKE) -Clibft fclean
	+$(MAKE) -Cmlx_linux fclean
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

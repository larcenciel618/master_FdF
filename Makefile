NAME		= fdf

SRCS		= fdf.c get_next_line_bonus.c get_next_line_utils_bonus.c \
			line_list.c fdf_split.c free.c hex_atoi.c get_vectors.c \
			effects.c get_vec_utils.c get_file_map.c change_color.c \
			draw.c fdf_utils.c key_hooks.c cross_hook.c convert_color.c

OBJS		= $(SRCS:%.c=%.o)

LIBFT		= libft.a

MLX			= minilibx-linux/libmlx.a

CC			= gcc

CFLAGS		= -lm -Wall -Wextra -Werror

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C ./minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

PHONY: fclean clean all re test retest

NAME		= fdf

BONUS_NAME	= fdf_bonus

VPATH		= srcs:get_next_line_bonus:bonus_srcs

MDTR_SRCS		=  fdf.c\
			line_list.c fdf_split.c free.c hex_atoi.c get_vectors.c \
			effects.c get_vec_utils.c get_file_map.c change_color.c \
			draw.c fdf_utils.c key_hooks.c cross_hook.c convert_color.c

BONUS_SRCS	= bns_fdf.c bns_change_color.c bns_convert_color.c bns_cross_hook.c \
		  bns_draw.c bns_effects.c bns_fdf_split.c bns_fdf_utils.c bns_free.c \
		  bns_get_file_map.c bns_get_vectors.c bns_hex_atoi.c bns_key_hooks.c bns_line_list.c bns_get_vec_utils.c

GNL_SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c

GNL_MDTR_SRCS	= $(MDTR_SRCS) $(GNL_SRCS)

GNL_BONUS_SRCS	= $(BONUS_SRCS) $(GNL_SRCS)

OBJS		= $(GNL_MDTR_SRCS:%.c=%.o)

BONUS_OBJS	= $(GNL_BONUS_SRCS:%.c=%.o)

LIBFT		= libft.a

MLX			= minilibx-linux/libmlx.a

CC			= gcc

CFLAGS		= -lm -Wall -Wextra -Werror

RM			= rm -f

INCDIR		= -I./includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) $(INCDIR) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm

bonus: $(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS)
	make -C ./libft
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) $(INCDIR) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C ./minilibx-linux
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME) $(LIBFT) $(MLX)

re: fclean all

PHONY: fclean clean all re test retest

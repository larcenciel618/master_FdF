/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:42:00 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/18 01:18:07 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	"minilibx-linux/mlx.h"
# include	"get_next_line_bonus.h"
# include	"libft/libft.h"
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<limits.h>

# define SHIFT_MOVE 60
# define STDERR 2

typedef struct s_mlx_info
{
	int	win_width;
	int	win_height;
	int	angle;
}	t_mlx_info;

typedef struct s_llist
{
	char			*content;
	struct s_llist	*next;
}	t_llist;

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
	long			color;
}	t_vector;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fdf {
	t_data		*img;
	t_vector	**vecs;
	void		*mlx;
	void		*win;
	int			map_row;
	int			map_col;
	int			shift_x;
	int			shift_y;
	int			shift_color;
	double		scope;
	double		xradian;
	double		yradian;
}	t_fdf;

typedef struct s_get_vec_info
{
	t_llist		*llist_top;
	t_llist		*file_map;
	t_vector	**vec;
	t_fdf		*fdf;
	int			row_i;
	int			col_i;
}	t_get_vec_info;

enum {
	ON_KEYDOWN = 65364,
	ON_KEYUP = 65362,
	ON_KEYRIGHT = 65363,
	ON_KEYLEFT = 65361,
	ON_KEY_L = 108,
	ON_KEY_K = 107,
	ON_KEY_J = 106,
	ON_KEY_H = 104,
	ON_KEY_A = 97,
	ON_KEY_S = 115,
	ON_KEY_U = 117,
	ON_KEY_I = 105,
	ON_KEY_O = 111,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 65307,
};

void		init_mlx_and_img(t_fdf *fdf, t_data *img, t_llist *file_map);
void		init_fdf(t_fdf *fdf);
void		init_iso(t_fdf *fdf);
void		get_map_size(t_fdf *fdf, t_llist *file_map);
t_llist		*get_file_map(int fd, t_fdf *fdf);
t_llist		*line_listnew(char *content);
void		line_lstadd_back(t_llist **lst, t_llist *new);
t_llist		*line_lstlast(t_llist *lst);
void		line_lstclear(t_llist **lst);
int			line_lstsize(t_llist *lst);
char		**fdf_split(char *s, char c, int *column);
void		free_2d_arr(void	**arr, int	map_col);
void		free_fdf(t_fdf *fdf, t_llist *file_map, bool is_error);
long		hex_atol(const char *str);
t_vector	**get_vectors(t_llist **file_map, t_fdf *fdf);
void		free_get_vectors(t_get_vec_info *gvi, char **line, char **pixel);
int			fdf_isdigit(int c);
bool		digit_check(char *file_z);
t_vector	**init_vecs(t_get_vec_info *gvi);
char		**init_line_elem(t_get_vec_info *gvi, int *column);
void		draw_map(t_fdf *fdf);
int			change_color(int s_color, int e_color, double ratio);
int			key_hook(int keycode, t_fdf *fdf);
int			cross_hook(t_fdf *fdf);
void		rotate_xaxis(t_fdf *fdf, int sign);
void		rotate_yaxis(t_fdf *fdf, int sign);
void		rotate_zaxis(t_fdf *fdf, int sign);
void		convert_color(t_fdf *fdf);
int			error_handler(void);
void		draw_line(t_data *img, t_vector start, t_vector end, t_fdf *fdf);

#endif

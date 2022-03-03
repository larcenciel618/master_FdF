/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:06:51 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 16:07:20 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector	**make_vecs_zc(t_get_vec_info *gvi, char **one_line_elem)
{
	char	**one_pixel_elem;
	int		ele_num;

	one_pixel_elem = fdf_split(one_line_elem[gvi->col_i], ',', &ele_num);
	if (one_pixel_elem == NULL || !digit_check(one_pixel_elem[0]))
		free_get_vectors(gvi, one_line_elem, one_pixel_elem);
	gvi->vec[gvi->row_i][gvi->col_i].z = ft_atoi(one_pixel_elem[0]);
	gvi->vec[gvi->row_i][gvi->col_i].z *= 0.1;
	gvi->vec[gvi->row_i][gvi->col_i].color = 0xffffff;
	if (ele_num >= 2)
		gvi->vec[gvi->row_i][gvi->col_i].color = hex_atol(one_pixel_elem[1]);
	if (gvi->vec[gvi->row_i][gvi->col_i].color == -1)
		gvi->vec[gvi->row_i][gvi->col_i].color = 0xffffff;
	free_2d_arr((void **)one_pixel_elem, -1);
	return (gvi->vec);
}

static t_vector	**make_vecs_xy(t_get_vec_info *gvi)
{
	t_vector	**vector;
	int			row_center;
	int			col_center;

	vector = gvi->vec;
	col_center = gvi->fdf->map_col / 2;
	row_center = gvi->fdf->map_row / 2;
	vector[gvi->row_i][gvi->col_i].x = gvi->col_i - col_center;
	vector[gvi->row_i][gvi->col_i].y = gvi->row_i - row_center;
	return (vector);
}

static t_vector	**pre_make_vecs(t_get_vec_info *gvi, int col)
{
	char	**one_line_elem;

	gvi->row_i = 0;
	while (gvi->file_map != NULL)
	{
		one_line_elem = init_line_elem(gvi, &col);
		gvi->vec[gvi->row_i] = (t_vector *)malloc \
								(sizeof(t_vector) * (col + 1));
		if (gvi->vec == NULL)
			free_get_vectors(gvi, one_line_elem, NULL);
		gvi->col_i = 0;
		while (gvi->col_i < col)
		{
			gvi->vec = make_vecs_xy(gvi);
			gvi->vec = make_vecs_zc(gvi, one_line_elem);
			gvi->col_i++;
		}
		free_2d_arr((void **)one_line_elem, -1);
		gvi->file_map = gvi->file_map->next;
		gvi->row_i++;
	}
	return (gvi->vec);
}

t_vector	**get_vectors(t_llist **file_map, t_fdf *fdf)
{
	t_get_vec_info	gvi;
	int				col;

	col = 0;
	gvi.fdf = fdf;
	gvi.llist_top = *file_map;
	gvi.file_map = *file_map;
	gvi.vec = init_vecs(&gvi);
	gvi.vec = pre_make_vecs(&gvi, col);
	*file_map = gvi.llist_top;
	return (gvi.vec);
}

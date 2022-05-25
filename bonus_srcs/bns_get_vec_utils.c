/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:36:02 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/16 16:36:31 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_get_vectors(t_get_vec_info *gvi, char **line, char **pixel)
{
	free_2d_arr((void **)pixel, -1);
	free_2d_arr((void **)line, -1);
	free_2d_arr((void **)gvi->vec, -1);
	mlx_destroy_image(gvi->fdf->mlx, gvi->fdf->img->img);
	free_fdf(gvi->fdf, gvi->llist_top, true);
}

int	fdf_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == '-' || c == '+')
		return (1);
	return (0);
}

bool	digit_check(char *file_z)
{
	int	idx;

	idx = 0;
	while (file_z[idx] != '\0' && file_z[idx] != '\n')
	{
		if (!fdf_isdigit(file_z[idx]))
			return (false);
		idx++;
	}
	return (true);
}

t_vector	**init_vecs(t_get_vec_info *gvi)
{
	int			i;

	gvi->vec = (t_vector **)malloc \
				(sizeof(t_vector *) * (gvi->fdf->map_row + 1));
	if (!gvi->vec)
		free_fdf(gvi->fdf, gvi->llist_top, true);
	i = 0;
	while (i <= gvi->fdf->map_row)
		gvi->vec[i++] = NULL;
	return (gvi->vec);
}

char	**init_line_elem(t_get_vec_info *gvi, int *column)
{
	char	**one_line_elem;

	one_line_elem = fdf_split(gvi->file_map->content, ' ', column);
	if (!one_line_elem || gvi->fdf->map_col != *column)
		free_get_vectors(gvi, one_line_elem, NULL);
	return (one_line_elem);
}

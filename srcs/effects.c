/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:03:37 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 12:10:50 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_yaxis(t_fdf *fdf, int sign)
{
	int			row_i;
	int			col_i;
	t_vector	save;

	row_i = 0;
	while (row_i < fdf->map_row)
	{
		col_i = 0;
		while (col_i < fdf->map_col)
		{
			save = fdf->vecs[row_i][col_i];
			fdf->vecs[row_i][col_i].x = (save.x * cos(sign * M_PI / 6)) \
										+ (save.z * sin(sign * M_PI / 6));
			fdf->vecs[row_i][col_i].z = -(save.x * (sin(sign * M_PI / 6))) \
											+ (save.z * cos(sign * M_PI / 6));
			col_i++;
		}
		row_i++;
	}
}

void	rotate_xaxis(t_fdf *fdf, int sign)
{
	int			row_i;
	int			col_i;
	t_vector	save;

	row_i = 0;
	while (row_i < fdf->map_row)
	{
		col_i = 0;
		while (col_i < fdf->map_col)
		{
			save = fdf->vecs[row_i][col_i];
			fdf->vecs[row_i][col_i].y = save.y * cos(sign * M_PI / 6) \
										+ save.z * (-1 * sin(sign * M_PI / 6));
			fdf->vecs[row_i][col_i].z = (save.y * sin(sign * M_PI / 6) \
											+ save.z * cos(sign * M_PI / 6));
			col_i++;
		}
		row_i++;
	}
}

void	rotate_zaxis(t_fdf *fdf, int sign)
{
	int			row_i;
	int			col_i;
	t_vector	save;

	row_i = 0;
	while (row_i < fdf->map_row)
	{
		col_i = 0;
		while (col_i < fdf->map_col)
		{
			save = fdf->vecs[row_i][col_i];
			fdf->vecs[row_i][col_i].x = save.x * cos(sign * M_PI / 4) \
										+ save.y * (-1 * sin(sign * M_PI / 4));
			fdf->vecs[row_i][col_i].y = (save.x * sin(sign * M_PI / 4) \
										+ save.y * cos(sign * M_PI / 4));
			col_i++;
		}
		row_i++;
	}
}

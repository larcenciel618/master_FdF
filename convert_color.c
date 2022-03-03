/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:20:33 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/18 01:12:12 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned char	change_color_ele(int color, int color_ele)
{
	int				shift;
	unsigned char	ele;

	shift = 8 * color_ele;
	ele = (color >> shift) & 0xFF;
	return (ele);
}

static int	color_ele_set(int color, int shift_color)
{
	int				fir;
	int				sec;
	int				thi;
	unsigned char	trgb[4];

	if (shift_color == INT_MAX)
		shift_color = 1;
	fir = (2 + shift_color) % 3;
	sec = (1 + shift_color) % 3;
	thi = (0 + shift_color) % 3;
	trgb[3] = change_color_ele(color, 3);
	trgb[fir] = change_color_ele(color, 0);
	trgb[sec] = change_color_ele(color, 1);
	trgb[thi] = change_color_ele(color, 2);
	return (*(int *)&trgb);
}

void	convert_color(t_fdf *fdf)
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
			fdf->vecs[row_i][col_i].color = \
						color_ele_set(save.color, fdf->shift_color);
			col_i++;
		}
		row_i++;
	}
}

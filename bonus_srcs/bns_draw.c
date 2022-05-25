/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:24:10 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 16:43:32 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static bool	draw_dot(t_vector vec, t_data *img)
{
	if (vec.x <= 0 || 1000 <= vec.x)
		return (false);
	if (vec.y <= 0 || 1000 <= vec.y)
		return (false);
	my_mlx_pixel_put(img, vec.x, vec.y, vec.color);
	return (true);
}

static t_vector	get_internal_vector(t_vector start, t_vector end, \
										double ratio, t_fdf *fdf)
{
	t_vector	target;

	target.x = ((start.x + (end.x - start.x) * ratio) * 30 \
							+ fdf->shift_x) * fdf->scope + 500;
	target.y = ((start.y + (end.y - start.y) * ratio) * 30 \
							+ (fdf->shift_y)) * fdf->scope + 500;
	target.z = (start.z + (end.z - start.z) * ratio) \
							* fdf->scope;
	target.color = change_color(start.color, end.color, ratio);
	return (target);
}

void	draw_line(t_data *img, t_vector start, t_vector end, t_fdf *fdf)
{
	double		ratio;
	t_vector	target;
	t_vector	target2;
	double		z_diff;
	double		p_space;

	ratio = 0;
	target = get_internal_vector(start, start, 0, fdf);
	target2 = get_internal_vector(end, end, 0, fdf);
	if (!draw_dot(target, img) && !draw_dot(target2, img))
		return ;
	z_diff = start.z - end.z;
	if (z_diff < 0)
		z_diff *= -1;
	p_space = 0.01 / ((z_diff + 1) * fdf->scope);
	while (ratio <= 1)
	{
		target = get_internal_vector(start, end, ratio, fdf);
		draw_dot(target, img);
		ratio += p_space;
	}
}

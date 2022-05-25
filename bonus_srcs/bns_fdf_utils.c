/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:46:28 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 16:48:48 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_iso(t_fdf *fdf)
{
	rotate_zaxis(fdf, 1);
	rotate_xaxis(fdf, 1);
	rotate_xaxis(fdf, 1);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->vecs = NULL;
	fdf->xradian = 0;
	fdf->yradian = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->shift_color = 1;
	fdf->scope = 1;
}

void	init_mlx_and_img(t_fdf *fdf, t_data *img, t_llist *file_map)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		exit (1);
	fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, " FDF ");
	if (fdf->win == NULL)
		free_fdf(fdf, file_map, true);
	img->img = mlx_new_image(fdf->mlx, 1000, 1000);
	if (img->img == NULL)
		free_fdf(fdf, file_map, true);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_length, &img->endian);
	if (img->addr == NULL)
		free_fdf(fdf, file_map, true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:41:50 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/18 01:16:06 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pass_to_draw_line(t_fdf *fdf, t_data *img)
{
	int	row_i;
	int	col_i;

	row_i = 0;
	while (row_i < fdf->map_row)
	{
		col_i = 0;
		while (col_i < fdf->map_col)
		{
			if (row_i < fdf->map_row - 1)
				draw_line(img, fdf->vecs[row_i][col_i], \
								fdf->vecs[row_i + 1][col_i], fdf);
			if (col_i < fdf->map_col - 1)
				draw_line(img, fdf->vecs[row_i][col_i], \
								fdf->vecs[row_i][col_i + 1], fdf);
			col_i++;
		}
		row_i++;
	}
}

void	draw_map(t_fdf *fdf)
{
	t_data		img;

	img.img = mlx_new_image(fdf->mlx, 1000, 1000);
	if (img.img == NULL)
		free_fdf(fdf, NULL, true); 
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
				&img.line_length, &img.endian);
	if (img.addr == NULL)
		free_fdf(fdf, NULL, true); 
	pass_to_draw_line(fdf, &img);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.img, 0, 0);
	mlx_destroy_image(fdf->mlx, img.img);
	mlx_hook(fdf->win, 17, 1 << 17, cross_hook, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int	argc, char **argv)
{
	int		fd;
	t_llist	*file_map;
	t_fdf	fdf;
	t_data	img;

	fd = open(argv[1], R_OK);
	if (argc != 2 || fd == -1)
		return (error_handler());
	file_map = NULL;
	init_mlx_and_img(&fdf, &img, file_map);
	file_map = get_file_map(fd, &fdf);
	if (file_map == NULL)
		free_fdf(&fdf, file_map, true); 
	init_fdf(&fdf);
	fdf.img = &img;
	get_map_size(&fdf, file_map);
	fdf.vecs = get_vectors(&file_map, &fdf);
	line_lstclear(&file_map);
	init_iso(&fdf);
	mlx_destroy_image(fdf.mlx, img.img);
	draw_map(&fdf);
}

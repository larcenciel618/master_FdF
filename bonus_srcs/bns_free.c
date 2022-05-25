/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:08:25 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/16 16:33:09 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_2d_arr(void **arr, int map_col)
{
	int	i;

	if (!arr)
		return ;
	if (map_col == -1)
		map_col = INT_MAX;
	i = 0;
	while (arr[i] && i < map_col)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_fdf(t_fdf *fdf, t_llist *file_map, bool is_error)
{
	line_lstclear(&file_map);
	free_2d_arr((void **)fdf->vecs, fdf->map_row);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	fdf->mlx = NULL;
	if (is_error)
		exit(error_handler());
	exit(0);
}

int	error_handler(void)
{
	ft_putstr_fd("Error\n", STDERR);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:52:33 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 16:52:52 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_any_axis(int keycode, t_fdf *fdf)
{
	if (keycode == ON_KEYRIGHT)
		rotate_yaxis(fdf, 1);
	else if (keycode == ON_KEYLEFT)
		rotate_yaxis(fdf, -1);
	else if (keycode == ON_KEYUP)
		rotate_xaxis(fdf, 1);
	else if (keycode == ON_KEYDOWN)
		rotate_xaxis(fdf, -1);
	else if (keycode == ON_KEY_A)
		rotate_zaxis(fdf, 1);
	else
		rotate_zaxis(fdf, -1);
	draw_map(fdf);
}

static void	shift_move(int keycode, t_fdf *fdf)
{
	if (keycode == ON_KEY_K)
		fdf->shift_y -= SHIFT_MOVE;
	else if (keycode == ON_KEY_J)
		fdf->shift_y += SHIFT_MOVE;
	else if (keycode == ON_KEY_L)
		fdf->shift_x += SHIFT_MOVE;
	else
		fdf->shift_x -= SHIFT_MOVE;
	draw_map(fdf);
}

static void	other_effects(int keycode, t_fdf *fdf)
{
	if (keycode == ON_KEY_U)
	{
		fdf->shift_color++;
		convert_color(fdf);
	}
	else if (keycode == ON_KEY_I)
		fdf->scope *= 2;
	else
		fdf->scope *= 0.5;
	draw_map(fdf);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ON_KEY_K || keycode == ON_KEY_J || \
			keycode == ON_KEY_L || keycode == ON_KEY_H)
		shift_move(keycode, fdf);
	else if (keycode == ON_KEYRIGHT || keycode == ON_KEYLEFT || \
			keycode == ON_KEYUP || keycode == ON_KEYDOWN || \
			keycode == ON_KEY_A || keycode == ON_KEY_S)
		rotate_any_axis(keycode, fdf);
	else if (keycode == ON_KEY_U || \
			keycode == ON_KEY_O || keycode == ON_KEY_I)
		other_effects (keycode, fdf);
	else if (keycode == ON_DESTROY)
		free_fdf(fdf, NULL, false);
	return (0);
}

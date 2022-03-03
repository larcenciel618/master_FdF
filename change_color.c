/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:28:19 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 16:33:14 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	change_color_ele(int s_color, int e_color, \
								double ratio, int color_ele)
{
	int	shift;
	int	s_ele;
	int	e_ele;

	shift = 8 * color_ele;
	s_ele = (s_color >> shift) & 0xFF;
	e_ele = (e_color >> shift) & 0xFF;
	return (s_ele + (e_ele - s_ele) * ratio);
}

int	change_color(int s_color, int e_color, double ratio)
{
	unsigned char	trgb[4];

	trgb[3] = change_color_ele(s_color, e_color, ratio, 3);
	trgb[2] = change_color_ele(s_color, e_color, ratio, 2);
	trgb[1] = change_color_ele(s_color, e_color, ratio, 1);
	trgb[0] = change_color_ele(s_color, e_color, ratio, 0);
	return (*(int *)&trgb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:50:15 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/12 23:18:45 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	is_space(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

static int	is_hexnum(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	c = ft_toupper(c);
	if ('A' <= c && c <= 'F')
		return (true);
	return (false);
}

static int	convert_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	c = ft_toupper(c);
	return (10 + (c - 'A'));
}

long	hex_atol(const char *str)
{
	long	ret;
	int		idx;

	ret = 0;
	while (is_space(*str))
		str++;
	if (ft_strncmp(str, "0x", 2) != 0)
		return (-1);
	str += 2;
	idx = 0;
	while (is_hexnum(str[idx]))
	{
		ret = ret * 16 + convert_to_int(str[idx++]);
		if (ret > UINT_MAX)
			return (-1);
	}
	if (idx == 0)
		return (-1);
	return (ret);
}

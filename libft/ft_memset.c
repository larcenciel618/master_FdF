/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:11:58 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/07 04:21:45 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*c;
	unsigned char	set;

	c = (unsigned char *)buf;
	set = (unsigned char)ch;
	while (n -- > 0)
		*(c++) = set;
	return (buf);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char buf[] = "abcdefghijk";

// 	ft_memset (NULL,50,3);

// 	printf("buf文字列→%s\n", buf);
// 	return (0);
// }

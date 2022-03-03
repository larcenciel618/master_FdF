/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/07 04:35:37 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char s1[] = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
// 	char s2[] = "\xff\0\0\xaa\0\xde\x00MBS";
// 	size_t n = 9;
// 	printf("[%d:%d]\n", ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
// 	printf("%d\n", ft_memcmp(NULL, NULL, 3));
// 	return (0);
// }

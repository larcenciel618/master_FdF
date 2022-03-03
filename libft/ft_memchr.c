/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:16:18 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/05 02:19:42 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	asc;

	str = (unsigned char *)s;
	asc = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (*str != asc && n-- > 1)
		str++;
	if (*str == asc)
		return (str);
	return (NULL);
}

// int	main(void)
// {
// 	char s[256] = "1234567890abcdefghijklmnopqrstuvwxy
// z1234567890abcdefghijklmnopqrstuvwxyz";
// 	int c, n, count, all;

// 	c = 0;
// 	count = 0;
// 	while (c <= 256)
// 	{
// 		n = 0;
// 		while (n <= 256)
// 		{
// 			if (ft_memchr(s, c, n) != memchr(s, c, n))
// 			{
// 				printf("[%d,%d]",  c, n);
// 				printf("[(%c),%s,%s]\n", (char)c, (char*)ft_memchr(s, c, n),
				//  (char*)memchr(s, c, n));
// 				count++;
// 			}
// 			n++;
// 			all++;
// 		}
// 		c++;
// 	}
// 	printf("NG:%d/%d\n", count,all);
// 	return (0);
// }

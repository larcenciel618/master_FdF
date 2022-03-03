/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 08:54:06 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/07 09:35:11 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	char	*dst;
// 	char	*src;
// 	int		a;
// 	int		b;

// 	dst = (char *)haystack;
// 	src = (char *)needle;
// 	if (src == NULL)
// 	{
// 		printf ("ranning?");
// 		return (dst);
// 	}
// 	a = 0;
// 	while (dst[a] && a < len)
// 	{
// 		b = 0;
// 		while (dst[a + b] == src[b] && src[b] && (a + b) < len)
// 		{
// 			b++;
// 			if (src[b] == '\0')
// 				return (&dst[a]);
// 		}
// 		a++;
// 	}
// 	return (NULL);
// }
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	haystack[50] = "hello,clangworld";
// 	char	needle[20] = "aiuo";
// 	int		len = 0;

// 	printf("%s\n\n", ft_strnstr(haystack,
// 		NULL, len));
// 	return (0);
// }
// int main(void)
// {
// 	char str1[] = "hello,world";
// 	char str2[] = "world";
// 	printf("%s\n", ft_strnstr(str1, str2, 0));
// 	return (0);
// }

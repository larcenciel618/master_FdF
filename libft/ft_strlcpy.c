/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:11:46 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/08 06:47:50 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dstsize-- > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// int main() {
// 	int ng = 0;
// 	int all = 0;
// 	for (int i = 0; i < 15; i++) {
// 		all++;
// 		char d1[256] = "123456789";
// 		char s1[256] = "abcde";
// 		char d2[256] = "123456789";
// 		char s2[256] = "abcde";
// 		size_t ret1 = strlcpy(d1, s1, i);
// 		size_t ret2 = ft_strlcpy(d2, s2, i);
// 		if (ret1 != ret2 || strcmp(d1, d2) != 0)
// 			ng++;
// 	}
// 	for (int i = 0; i < 15; i++) {
// 		all++;
// 		char s1[256] = "123456789";
// 		char d1[256] = "abcde";
// 		char s2[256] = "123456789";
// 		char d2[256] = "abcde";
// 		size_t ret1 = strlcpy(d1, s1, i);
// 		size_t ret2 = ft_strlcpy(d2, s2, i);
// 		if (ret1 != ret2 || strcmp(d1, d2) != 0)
// 			ng++;
// 	}
// 	printf("NG:%d/%d\n", ng, all);
// }

// int main(void)
// {
// 	char	*str = "BBBB";//unittestの最後のテスト
// 	char	buff1[0xF00];
// 	char	buff2[0xF00];

// 	memset(buff1, 'A', 20);
// 	memset(buff2, 'A', 20);
// 	printf("%zu\n", ft_strlcpy(buff1, str, 0));
// 	printf("%zu\n", strlcpy(buff2, str, 0));
// 	// if (strlcpy(buff1, str, 0) != ft_strlcpy(buff2, str, 0))
// 	// 	printf("miss");
// 	if (!memcmp(buff1, buff2, 20))
// 		printf("ok");
// 	return (0);
// }

// int main(void)
// {
// 	char dst[] = "hello";
// 	ft_strlcpy(dst, dst, 4);
// 	strlcpy(dst, dst, 4);
// 	return (0);
// }

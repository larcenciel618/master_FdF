/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:59:29 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/07 10:37:12 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		dlen;
	size_t		slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	j = dlen;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (dstsize - dlen - 1 > 0 && src[i] != '\0')
	{
		dst[j++] = src[i++];
		dstsize--;
	}
	dst[j] = '\0';
	return (dlen + slen);
}

// int	main(void)
// {
// 	char	dst[] = "hirose";
// 	char	src[] = "kaito";

// 	printf("%zu\n", ft_strlcat(dst, src, 10));
// 	printf("%s\n", dst);
// 	return (0);
// }
// int main() {
// 	int ng = 0;
// 	int all = 0;
// 	for (int i = 0; i < 20; i++) {
// 		all++;
// 		char d1[256] = "123456789";
// 		char s1[256] = "abcde";
// 		char d2[256] = "123456789";
// 		char s2[256] = "abcde";
// 		size_t ret1 = strlcat(d1, s1, i);
// 		size_t ret2 = ft_strlcat(d2, s2, i);
// 		if (ret1 != ret2 || strcmp(d1, d2) != 0)
// 			ng++;
// 	}
// 	for (int i = 0; i < 20; i++) {
// 		all++;
// 		char s1[256] = "123456789";
// 		char d1[256] = "abcde";
// 		char s2[256] = "123456789";
// 		char d2[256] = "abcde";
// 		size_t ret1 = strlcat(d1, s1, i);
// 		size_t ret2 = ft_strlcat(d2, s2, i);
// 		if (ret1 != ret2 || strcmp(d1, d2) != 0)
// 			ng++;
// 	}
// 	printf("NG:%d/%d\n", ng, all);
// }

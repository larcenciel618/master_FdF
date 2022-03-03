/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:55:55 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/03 01:46:24 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (p_dst > p_src)
	{
		while (len-- > 0)
			p_dst[len] = p_src[len];
	}
	else
	{
		while (len-- > 0)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}

// int main(void)
// {
// 	char src[] = "hello,world I am a cat";
// 	char *dst;

// 	dst = ft_memmove(src + 3, src, 5);
// 	printf ("%s\n", (char *)(dst - 3));

// 	char src2[] = "welcome to 42tokyo";
// 	char *dst2;

// 	dst2 = ft_memmove(src - 3, src, 5);
// 	printf("%s\n", (char *)(src));

// 	char tsrc[] = "hello,world I am a cat";
// 	char *tdst;

// 	tdst = memmove(tsrc + 3, tsrc, 5);
// 	printf("%s\n", (char *)(tdst - 3));

// 	//この下以降消すとできる
// 	// char tsrc2[] = "welcome to 42tokyo";
// 	// char *tdst2;

// 	// tdst2 = memmove((tsrc2) - 3, tsrc2, 5);
// 	// printf("%s\n", (char *)(tdst2 - 3));
// 	return 0;
// }

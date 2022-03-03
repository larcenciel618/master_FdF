/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:37:37 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/05 02:21:16 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n-- > 0)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char src[] = "abcdefghijklmnopqrstuvwxyz";

// 	printf ("%s\n", (char *)ft_memcpy(NULL, NULL, 10));
// 	printf ("%s\n", (char *)memcpy(NULL, NULL, 10));

// 	//printf ("%s\n", memcpy(src + 10, src, 10));
// 	return (0);
// }

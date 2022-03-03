/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 07:35:03 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/06 03:08:35 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			len;

	i = 0;
	if (count == 0 || size == 0)
	{
		ptr = (unsigned char *)malloc(sizeof(char) * 1);
		if (ptr == NULL)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	len = size * count;
	ptr = (unsigned char *)malloc(len);
	if (ptr == NULL)
		return (NULL);
	while (len-- > 0)
		ptr[i++] = '\0';
	return ((void *)ptr);
}

// int	main(void)
// {
// 	//len--はsize * countで1バイトずつにしてある　int の場合 4xcount
// 	int	size = 8539;
// 	void	*str;
// 	void	*str2;

// 	str = ft_calloc(size, sizeof(int));
// 	str2 = calloc(size, sizeof(int));
// 	return(0);
// }

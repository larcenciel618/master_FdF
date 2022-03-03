/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:57:35 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/03 02:54:22 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;

	c = (unsigned char *)s;
	while (n -- > 0)
		*(c++) = '\0';
}

/*int	main(void)
{
	char buf[] = "abcdefghijk";

	ft_bzero (buf+2,3);

	printf("buf文字列→%s\n", buf);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:37:40 by kahirose          #+#    #+#             */
/*   Updated: 2021/10/25 11:42:35 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	n;

	if (s == NULL)
		return ;
	n = '\n';
	while (*s)
		write(fd, s++, 1);
	write (fd, &n, 1);
}

// int main(void)
// {
// 	// char s[] = "kaito";
// 	char	*s = NULL;
// 	int  fd = 1;
// 	ft_putendl_fd(s, fd);
// 	return (0);
// }

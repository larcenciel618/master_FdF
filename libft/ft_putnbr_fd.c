/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:51:20 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/30 11:55:26 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	nbr;

	c = '-';
	if (n == -2147483648)
	{
		nbr = -1 * (n / 1000000000) + '0';
		write (fd, &c, 1);
		write (fd, &nbr, 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, &c, 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	nbr = (n % 10) + '0';
	write (fd, &nbr, 1);
}

// int main()
// {
//     ft_putnbr_fd(-2147483648, 1);
//     return (0);
// }

// int main(void)
// {
// 	int i = -859724;
// 	ft_putnbr_fd(i, 1);
// 	return (0);
// }

//#include <stdio.h>
//int main(void)
//{
//	int i = -4;
//
//	printf("%d\n", i % 10);
//	return (0);
//}

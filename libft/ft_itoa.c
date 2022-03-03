/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 08:06:17 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/26 02:54:14 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_digit(int num)
{
	int	digit;

	digit = 0;
	if (num < 0)
		num = -(num / 10 * 10);
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	if (digit == 0)
		digit++;
	return (digit);
}

static void	makestr(char *str, int n, int digit, int cnt)
{
	cnt++;
	if (n >= 10 || n <= -10)
	{
		makestr(str, n / 10, digit, cnt);
	}
	if (n < 0)
	{
		if (digit - cnt == 0)
		{
			str[0] = '-';
			str[1] = (char)('0' + (-n % 10));
		}
		else
			str[digit - cnt + 1] = (char)('0' + (n % 10 * -1));
	}
	else
		str[digit - cnt] = (char)('0' + (n % 10));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	int		cnt;

	digit = 0;
	digit = cnt_digit(n);
	if (n < 0)
		str = (char *)ft_calloc((digit + 2), sizeof(char));
	else
		str = (char *)ft_calloc((digit + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	cnt = 0;
	makestr (str, n, digit, cnt);
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int normal = 123435;
// 	int min = -2147483648;
// 	int max = 2147483647;
// 	int zero = 0;
// 	char	*str;
// 	// 2147483647
// 	str = ft_itoa(normal);
// 	printf("%s\n", str);
// 	printf("%d\n", normal);
// 	str = ft_itoa(min);
// 	printf("%s\n", str);
// 	printf("%d\n", min);
// 	str = ft_itoa(max);
// 	printf("%s\n", str);
// 	printf("%d\n", max);
// 	str = ft_itoa(zero);
// 	printf("%s\n", str);
// 	printf("%d\n", zero);
// }
// 	min = -2147483648;
// 	printf("%d\n", -min);
// 	return (0);
// }
// int main(int argc, char const *argv[])
// {
// 	int min = -2147483648;
// 	char *str;

// 	str = ft_itoa(min);
// 	printf("%s\n", str);

// 	return 0;
// }

// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
// 	int i = INT_MIN;
// 	char *s;

// 	while (i < INT_MAX)
// 	{
// 		s = ft_itoa(i);
// 		// if (atoi(s) != i)
// 		printf("[%d:%s]\n", i, s);
// 		i++;
// 		if (i % 500000000 == 0)
// 			printf("5億経過\n");
// 		free(s);
// 	}
// 	return (0);
// }

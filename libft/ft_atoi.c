/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:45:38 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/07 17:07:22 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_int(char *med, int minflag)
{
	long		ans;
	size_t		i;

	ans = 0;
	i = 0;
	while (med[i])
	{
		ans = (ans * 10) + (med[i++] - '0');
		if (med[i] != '\0' && (ans * 10 + (med[i] - '0')) / 10 != ans)
		{
			if (minflag == 1)
				return (0);
			else
				return (-1);
		}
	}
	if (minflag == 1)
		ans *= -1;
	return ((int)ans);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	a;
	int		minflag;
	char	med[21];

	i = 0;
	a = 0;
	minflag = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		 	i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minflag = 1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9' && a <= 19)
	{
		med[a++] = str[i++];
	}
	med[a] = '\0';
	return (return_int(med, minflag));
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	// long longmax = -9223372036854775808;
// // med[21]の21要素はヌルと一つ超過分
// // while の条件分a <= 18でlong intの最大桁数（19桁）である
// // 19桁目までlong int 以内であったとしてもwhileで20要素目までみることでそれ以降に桁があれば次でlong int以上と判定できる
// 	printf("%d\n", ft_atoi("9223372036854775807"));//最大値
//  printf("%d\n", atoi("9223372036854775807"));//最大値
// 	printf("%d\n", ft_atoi("9223372036854775808"));//最大値＋1
// 	printf("%d\n", atoi("9223372036854775808"));//最大値＋1
// 	printf("%d\n", ft_atoi("-9223372036854775808"));//最小値
// 	printf("%d\n", atoi("-9223372036854775808"));//最小値
// 	printf("%d\n", ft_atoi("-9223372036854775809"));//最小値-1
// 	printf("%d\n", atoi("-9223372036854775809"));//最小値-1
// 	printf("%d\n", ft_atoi("4772185884"));
// 	printf("%d\n", atoi("4772185884"));

// 	// printf("%d\n", (int)longmax);
// 	return (0);
// }
// #include <stdio.h>
// #include <assert.h>
// void	my_test(const char *input)
// {
// 	int a = ft_atoi(input);
// 	int b = atoi(input);

// 	printf("%s\n", input);
// 	printf("  %d：ft_atoi\n", a);
// 	printf("  %d：atoi\n", b);
// 	assert(a == b);
// }
// int	main(void)
// {
// 	my_test("0");
// 	my_test("1");
// 	my_test("-1");
// 	my_test("8");
// 	my_test("127");
// 	my_test("128");
// 	my_test("129");
// 	my_test("254");
// 	my_test("255");
// 	my_test("256");
// 	my_test("2147483646");
// 	my_test("2147483647");//INT_MAX
// 	my_test("2147483648");
// 	my_test("4294967294");
// 	my_test("4294967295");//UNSIGNED INT_MAX
// 	my_test("4294967296");
// 	my_test("9223372036854775806");
// 	my_test("9223372036854775807");//LONG MAX
// 	my_test("9223372036854775808");
// 	my_test("18446744073709551614");
// 	my_test("18446744073709551615");//UNSIGNED LONG MAX
// 	my_test("18446744073709551616");
// 	my_test(" -2147483649");
// 	my_test(" -2147483648");//INT_MIN
// 	my_test(" -2147483647");
// 	my_test(" -9223372036854775809");
// 	my_test(" -9223372036854775808");//LONG NIN
// 	my_test(" -9223372036854775807");
// 	my_test(" -922337203685477580009");
// 	my_test(" -922337203685477580008");//LONG NIN
// 	my_test(" -922337203685477580007");
// 	my_test(" 634106827633765826700");
// 	my_test(" 63410682763376582680");
// 	my_test(" 63410682763376582678");
// 	my_test(" 922337203685477580008");
// 	my_test(" 922337203685477580007");
// 	my_test(" -634106827633765826700");
// 	my_test(" -63410682763376582679");
// 	my_test(" -63410682763376582680");
// 	my_test(" -63410682763376582678");
// 	my_test(" -922337203685477580008");
// 	my_test(" -922337203685477580007");
// 	my_test("9223372036854775812");
// 	my_test("922337203685477570");
// 	my_test("922337203685477577");
// 	my_test("-9223372036854775807");
// 	my_test("-9223372036854775807");
// 	my_test("9223372036854775806");
// 	my_test("9223372036854775806");
// 	my_test("-2147483649");
// 	my_test("-2147483649");
// 	my_test("2147483648");
// 	my_test("2147483648");
//     my_test("-2147483658");
//     my_test("-2147483658");
//     my_test("2147483657");
//     my_test("2147483657");
// 	my_test("9223372036854775808");
// 	my_test("9223372036854775808");
// 	my_test("92233720368547758000");
// 	my_test("92233720368547758000");
// 	my_test("-9223372036854775809");
// 	my_test("-9223372036854775809");
// 	my_test("-92233720368547758000");
// 	my_test("-92233720368547758000");
// }

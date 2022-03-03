/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 05:02:12 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/06 04:20:51 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f((unsigned int)i, &s[i]);
		i++;
	}
}

// void	sample_f2(unsigned int i, char *s)
// {
// 	if (s[i] >= 'a' && s[i] < 'z')
// 		s[i] -= 32;
// }
// int main(void)
// {
// 	char	str[] = "kaito";
// 	void (*f)(unsigned int, char *);

// 	f = sample_f2;
// 	ft_striteri(str, f);
// 	printf("%s\n", str);
// 	return (0);
// }

// #include <stdio.h>
// int main(void)
// {

// 	size_t j = 4700000000;
// 	printf("%d\n", (unsigned int)j);
// 	printf("%zu\n", j);
// 	return (0);
// }

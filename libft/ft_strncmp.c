/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:48:06 by kahirose          #+#    #+#             */
/*   Updated: 2021/12/07 04:24:05 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
		return (0);
	count = 0;
	while (s1[count] != '\0' && s1[count] == s2[count] && count < (n - 1))
		count ++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char s[] = "\200";
// 	char s2[] = "\0";
// 	int	i;

// 	i = ft_strncmp(s, s2, 1);
// 	printf("%d\n", i);
// 	i = strncmp(s, s2, 1);
// 	printf("%d\n", i);
// 	return (0);
// }
// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	unsigned char	*str1;
// 	unsigned char	*str2;
// 	size_t			i;

// 	str1 = (unsigned char *)s1;
// 	str2 = (unsigned char *)s2;
// 	if (n == 0)
// 		return (0);
// 	i = 0;
// 	while (n > 1 && str1[i] == str2[i] && str1[i] != '\0')
// 	{
// 		n--;
// 		i++;
// 	}
// 	return ((int)(str1[i] - str2[i]));
// }

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char c[] = "aa\200";
// 	char ch = '\200';
// 	printf("me%d:original%d\n", ft_strncmp(c, "\0", 6),
// 	strncmp(c, "\0", 6));
// 	printf("%d\n", (int)ch);
// 	return (0);
// }
// int main() {
// 	char c1[][256] = {"a","az","aaa","ba","bba","a", "" ,""};
// 	char c2[][256] = {"a","ab","aa" ,"aa","aaa","" , "z",""};

// 	int ng = 0;
// 	int all = 0;
// 	for (size_t i = 0; i < sizeof(c1)/sizeof(c1[0]); i++) {
// 		for (size_t j = 0; j < 5; j++) {
// 			all++;
// 			int a = strncmp(c1[i], c2[i], j);
// 			a = a > 0 ? 1 : (a < 0 ? -1 : 0);
// 			int b = ft_strncmp(c1[i], c2[i], j);
// 			b = b > 0 ? 1 : (b < 0 ? -1 : 0);
// 			if (a != b) {
// 				ng++;
// 				printf("[%ld,%ld]", i, j);
// 			}
// 		}
// 	}
// 	printf("NG:%d/%d\n", ng, all);
// }

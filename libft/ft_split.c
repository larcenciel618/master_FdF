/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:11:24 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/12 23:58:10 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **all, size_t x)
{
	while (x > 0)
	{
		if (all[x] != NULL)
			free(all[x]);
		x--;
	}
	free(all[0]);
	free(all);
}

static size_t	exe_split(char **all, char *str, char c)
{
	size_t	i;
	size_t	start;
	size_t	x;

	x = 0;
	i = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	start = i;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i - 1] != c)
				all[x++] = ft_substr(str, start, (i - start));
			start = i + 1;
		}
		i++;
		if (str[i] == '\0' && str[i - 1] != c)
			all[x++] = ft_substr(str, start, (i - start));
	}
	all[x] = NULL;
	return (x);
}

static char	**set_all(char *s, char c)
{
	size_t	i;
	size_t	count;
	char	**all;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	all = (char **)malloc(sizeof(char *) * (count + 1));
	return (all);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**all;
	size_t	i;
	size_t	x;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	all = set_all(str, c);
	if (all == NULL)
		return (NULL);
	x = exe_split(all, str, c);
	i = 0;
	while (all[i] != NULL)
		i++;
	if (x != i)
	{
		free_all(all, x);
		return (NULL);
	}
	return (all);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
// #include <stdio.h>
// int	main(void)
// {
// 	char	*s = "  I am    a cat I h a  v e n o name   ";
// 	char	**result;
// 	int		i = 0;
// 	int		x = 0;

// 	result = ft_split(s, ' ');
// 	if (result == NULL)
// 		printf("NULL\n");
// 	else
// 	{
// 		while (result[x] != NULL)
// 			printf("[%s]", result[x++]);
// 	}

// 	printf("\n");
// 	i = 0;
// 	if (result != NULL)
// 	{
// 		while (result[i] != NULL)
// 			free(result[i++]);
// 		free(result);
// 	}
// 	return (0);
// 	// ---以下のif文を42行目のif文ブロック内に入れると
// 	// freeチェックができます----------------------
// 	// if (x == 3)
// 	// {
// 	// 	free(all[x - 1]);
// 	// 	all[x - 1] = NULL;
// 	// }
// }

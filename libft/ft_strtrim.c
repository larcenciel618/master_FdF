/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:15 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/08 11:01:33 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	headtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	i;

	i = 0;
	first = 0;
	while (s1[first] && set[i] != '\0')
	{
		while (set[i] && s1[first] != set[i])
			i++;
		if (s1[first] == set[i])
		{
			first++;
			i = 0;
		}
	}
	return (first);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	first;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	first = headtrim(s1, set);
	if (first == len)
		return (ft_strdup(""));
	i = 0;
	while (len > 1 && set[i] != '\0')
	{
		while (set[i] && s1[len - 1] != set[i])
			i++;
		if (s1[len - 1] == set[i])
		{
			len--;
			i = 0;
		}
	}
	return (ft_substr(s1, first, len - (size_t)first));
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*s;
// 	char	str[] = " jafeiBB    BB";
// 	char	set[] = "ABC";

// 	s = ft_strtrim(str, NULL);
// 	printf("%s", s);
// 	return (0);
// }

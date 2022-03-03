/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:59:51 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 15:21:31 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_all(char **all, size_t world_count)
{
	while (world_count > 0)
	{
		if (all[world_count] != NULL)
			free(all[world_count]);
		world_count--;
	}
	free(all[0]);
	free(all);
}

static size_t	exe_split(char **all, char *str, char c)
{
	size_t	i;
	size_t	start;
	size_t	world_count;

	world_count = 0;
	i = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	start = i;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i - 1] != c)
				all[world_count++] = ft_substr(str, start, (i - start));
			start = i + 1;
		}
		i++;
		if (str[i] == '\0' && str[i - 1] != c)
			all[world_count++] = ft_substr(str, start, (i - start));
	}
	all[world_count] = NULL;
	return (world_count);
}

static char	**set_all(char *s, char c, int *column)
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
	*column = count;
	all = (char **)malloc(sizeof(char *) * (count + 1));
	return (all);
}

char	**fdf_split(char *s, char c, int *column)
{
	char	**all;
	size_t	i;
	size_t	x;

	if (s == NULL)
		return (NULL);
	all = set_all(s, c, column);
	if (all == NULL)
		return (NULL);
	x = exe_split(all, s, c);
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

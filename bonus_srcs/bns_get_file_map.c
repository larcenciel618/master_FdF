/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:08:50 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 16:33:44 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static size_t	word_count(char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
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
	return (count);
}

void	get_map_size(t_fdf *fdf, t_llist *file_map)
{
	fdf->map_row = line_lstsize(file_map);
	fdf->map_col = word_count(file_map->content, ' ');
}

t_llist	*get_file_map(int fd, t_fdf *fdf)
{
	char	*map_one_line;
	t_llist	*file_map;
	t_llist	*new;
	bool	is_success;

	is_success = true;
	map_one_line = get_next_line(fd, &is_success);
	file_map = NULL;
	if (!map_one_line && !is_success)
		free_fdf(fdf, file_map, true);
	while (map_one_line != NULL)
	{
		new = line_listnew(map_one_line);
		if (new == NULL)
		{
			free(map_one_line);
			free_fdf(fdf, file_map, true);
		}
		line_lstadd_back(&file_map, new);
		map_one_line = get_next_line(fd, &is_success);
		if (!map_one_line && !is_success)
			free_fdf(fdf, file_map, true);
	}
	return (file_map);
}

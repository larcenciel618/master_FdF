/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:07:08 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 14:50:57 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*make_result(char **all)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = gnl_strlen(*all, 1);
	i = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (**all != '\0' && **all != '\n')
	{
		result[i] = **all;
		*all = *all + 1;
		i++;
	}
	if (**all == '\n')
	{
		*all = *all + 1;
		result[i++] = '\n';
	}
	result[i] = '\0';
	return (result);
}

static char	*tail_trim(char *all, char **save, bool *is_success)
{
	char	*result;
	size_t	i;
	size_t	len;
	char	*keep_all;

	keep_all = all;
	result = make_result(&all);
	if (result == NULL)
		return (error_clean(keep_all, NULL, is_success));
	len = gnl_strlen(all, 0);
	*save = (char *)malloc(sizeof(char) * (len + 1));
	if (*save == NULL)
		return (error_clean(keep_all, result, is_success));
	i = 0;
	while (all[i] != '\0')
	{
		(*save)[i] = all[i];
		i++;
	}
	(*save)[i] = '\0';
	free(keep_all);
	return (result);
}

static bool	read_checker(int rd, char *buf, char *new, bool *is_success)
{
	if (rd == -1)
	{
		return (error_clean(new, buf, is_success));
		return (false);
	}
	if ((rd == 0 && gnl_strlen(new, 0) == 0))
	{
		error_clean(new, buf, is_success);
		*is_success = true;
		return (false);
	}
	return (true);
}

static char	*take_next_line(char *save, int fd, bool *is_success)
{
	char		*buf;
	char		*new;
	ssize_t		rd;

	rd = 1;
	if (eol_sensor(save) == 1)
		return (save);
	new = save;
	while (rd != 0)
	{
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (buf == NULL)
			return (error_clean(new, NULL, is_success));
		rd = read(fd, buf, BUFFER_SIZE);
		if (!read_checker(rd, buf, new, is_success))
			return (NULL);
		buf[rd] = '\0';
		new = gnl_strjoin(new, buf, is_success);
		if (new == NULL)
			return (NULL);
		if (eol_sensor(new) == 1)
			return (new);
	}
	return (new);
}

char	*get_next_line(int fd, bool *is_success)
{
	static char	*save[256];
	char		*result;

	if (fd >= 256 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save[fd] == NULL)
	{
		save[fd] = (char *)malloc(sizeof(char) * 1);
		if (save[fd] == NULL)
			return (NULL);
		*save[fd] = '\0';
	}
	result = take_next_line(save[fd], fd, is_success);
	if (result == NULL)
	{
		save[fd] = NULL;
		return (NULL);
	}
	result = tail_trim(result, &save[fd], is_success);
	if (result == NULL)
		save[fd] = NULL;
	return (result);
}

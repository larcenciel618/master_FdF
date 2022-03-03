/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:57:50 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 14:41:06 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	eol_sensor(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	gnl_strlen(const char *str, int mode)
{
	size_t	i;

	i = 0;
	if (mode == 0)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
		return (i);
	}
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_strjoin(char *s1, char *s2, bool *is_success)
{
	char	*new;
	size_t	len;

	len = gnl_strlen(s1, 0) + gnl_strlen(s2, 0);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (error_clean(s1, s2, is_success));
	*new = '\0';
	new = ft_strcat(new, s1);
	new = ft_strcat(new, s2);
	free(s1);
	free(s2);
	return (new);
}

void	*error_clean(char *s1, char *s2, bool *is_success)
{
	free(s1);
	free(s2);
	*is_success = false;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:58:31 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/02 16:24:25 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*new;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	len = ft_strlen(str1) + ft_strlen(str2);
	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	new = ft_strcat(new, str1);
	new = ft_strcat(new, str2);
	return (new);
}

// int	main(void)
// {
// 	char s1[] = "aiudalfijs";
// 	char s2[] = "eofadsijf";
// 	char *new;
// 	new = ft_strjoin(s1, s2);
// 	printf("%s\n", new);
// 	return (0);
// }

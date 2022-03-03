/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:37:07 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/02 02:14:41 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len == 0 || start >= slen)
		return (ft_strdup(""));
	if (slen < len)
		s2 = (char *)malloc(sizeof(char) * (slen - start + 1));
	else
		s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}

// int main(void)
// {
// 	char 	s[] = "helloworld";
// 	unsigned int start = 2;
// 	size_t len = 5;
// 	printf("%s\n", ft_substr(s, start, len));
// 	return (0);
// }
// int main(void)
// {
// 	char 			s[] = "hello,world";
// 	 char			*result;
// 	unsigned int	start = 2;
// 	size_t			len = 5;
// 	result = ft_substr(s, 5, 3);
// 	//printf("[%zu],[%s]", ft_strlen(result), result);
// 	printf("%s\n", result);
// 	// result = ft_substr("tripouille", 0, 42000);
// 	// printf("[%s],[%zu]\n", result, ft_strlen(result));
// 	// free(result);
// 	// printf("[%s],[%zu]\n", result, ft_strlen(result));
// 	// result = ft_substr("tripouille", 100, 1);
// 	// printf("[%s],[%zu]\n", result, ft_strlen(result));
// 	// free(result);
// 	// result = ft_substr("tripouille", 1, 1);
// 	// printf("%s\n", result);
// 	// printf("%zu\n", ft_strlen(result));

// 	return 0;
// }

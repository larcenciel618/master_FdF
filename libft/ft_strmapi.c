/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 04:05:04 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/07 03:59:23 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	sample_f(unsigned int i, char c)
// {
// 	char	result;

// 	result = c;
// 	if (result >= 'A' && result <= 'Z')
// 		result += i;
// 	else if (result >= 'a' && result <= 'z')
// 		result -= i;
// 	return (result);
// }
// int	main(void)
// {
// 	char	s[] = "HiRsE KaItO";
// 	char (*f)(unsigned int, char);

// 	f = sample_f;
// 	printf("%s\n", ft_strmapi(s, f));
// 	return (0);
// }

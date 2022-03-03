/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:34:30 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/05 02:48:58 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	tage;
	size_t	i;

	i = 0;
	str = (char *)s;
	tage = (char)c;
	while (str[i] != tage && str[i] != '\0')
		i++;
	if (str[i] == tage)
		return (&str[i]);
	return (NULL);
}

// int main() {
// 	int ng = 0;
// 	int all = 0;
// 	char s[256] = "123456789abcdef123456789abcdef";
// 	for (int i = 0; i < 256; i++) {
// 		all++;
// 		if (strchr(s, i) != ft_strchr(s, i))
// 			ng++;
// 	}
// 	printf("NG:%d/%d\n", ng, all);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:15:45 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/03 18:33:56 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = (char *)s;
	if ((char)c == 0)
		return (&str[len]);
	while (len > 0 && str[len] != (char)c)
		len --;
	if (str[len] == (char)c)
		return (&str[len]);
	return (NULL);
}

// int main() {
// 	int ng = 0;
// 	int all = 0;
// 	char c[256] = "123456789abcdef123456789abcdef";
// 	for (int i = 0; i < 256; i++) {
// 		all++;
// 		if (strrchr(c, i) != ft_strrchr(c, i))
// 			ng++;
// 	}
// 	printf("NG:%d/%d\n", ng, all);
// }

// int main(void)
// {
// 	printf("%s\n", strrchr(NULL, '\0'));
// 	return (0);
// }

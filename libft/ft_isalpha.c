/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 06:07:40 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/02 17:02:43 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

// #include <ctype.h>
// int main() {
// 	int count = 0;
// 	for (int i = 0; i < 256; i++) {
// 		if (isalpha(i) != ft_isalpha(i))
// 			count++;
// 	}
// 	printf("NG:%d/256\n", count);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 08:10:11 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/04 21:07:40 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
// #include <ctype.h>
// int main() {
// 	int count = 0;
// 	for (int i = 0; i < 256; i++) {
// 		if (isalnum(i) != ft_isalnum(i))
// 			count++;
// 	}
// 	printf("NG:%d/256\n", count);
// }

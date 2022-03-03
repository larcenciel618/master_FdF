/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 07:56:19 by kahirose          #+#    #+#             */
/*   Updated: 2021/10/14 19:42:45 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// #include <ctype.h>
// int main() {
// 	int count = 0;
// 	for (int i = 0; i < 256; i++) {
// 		if (isdigit(i) != ft_isdigit(i))
// 			count++;
// 	}
// 	printf("NG:%d/256\n", count);
// }

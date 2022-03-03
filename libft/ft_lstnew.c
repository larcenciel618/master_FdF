/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:18:51 by kahirose          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ndPtr;

	ndPtr = malloc(sizeof(t_list));
	if (ndPtr == NULL)
		return (NULL);
	else
	{
		ndPtr->content = content;
		ndPtr->next = NULL;
		return (ndPtr);
	}
}

// int main(void)
// {
// 	t_list *ndPtr;
// 	char	content[] = "hello";

// 	ndPtr = ft_lstnew(content);
// 	printf("%zu\n", sizeof(ndPtr));
// 	printf("%s\n", (char *)ndPtr->content);
// 	return (0);
// }

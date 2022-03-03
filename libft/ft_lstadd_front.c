/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:23:39 by kahirose          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	t_list *lst;
// 	t_list *new;
// 	char	content1[] = "hello,world";
// 	char	content2[] = "goodbye,world";

// 	lst = ft_lstnew(content1);
// 	printf("%s\n", (char *)lst->content);
// 	new = ft_lstnew(content2);
// 	ft_lstadd_front(&lst, new);
// 	printf("%s\n", (char *)(lst->content));
// 	return (0);
// }

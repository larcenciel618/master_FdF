/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:00:46 by kahirose          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ndPtr;

	if (new == NULL)
		return ;
	if (lst == NULL)
		*lst = new;
	ndPtr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (ndPtr->next != NULL)
			ndPtr = ndPtr->next;
		ndPtr->next = new;
	}
}

// void	ft_printlst(t_list *lst)
// {
// 	while (lst->next != NULL)
// 	{
// 		printf("%s\n", (char *)(lst->content));
// 		lst = lst->next;
// 	}
// 	printf("%s\n", (char *)(lst->content));
// }
// int	main(void)
// {
// 	// 例外でリストの値を変えるからダブルポインタを渡してる。
// 	t_list *nd1, *nd2, *nd3, *lst;
// 	char	content1[] = "I am cat";
// 	char	content2[] = "as yet";
// 	char	content3[] = "I have no name";

// 	nd1 = ft_lstnew (content1);
// 	lst = nd1;
// 	nd2 = ft_lstnew (content2);
// 	ft_lstadd_back (&lst, nd2);
// 	nd3 = ft_lstnew(content3);
// 	ft_lstadd_back (&lst, nd3);
// 	ft_printlst (lst);
// 	return (0);
// }

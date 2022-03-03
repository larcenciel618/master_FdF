/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:34:23 by kahirose          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;

	if (del == NULL || lst == NULL)
		return ;
	while (*lst != NULL)
	{
		nxt = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = nxt;
	}
	*lst = NULL;
}

// void	delete(void *content)
// {
// 	//free(content);
// 	// ft_bzero ();
// 	free(content);
// 	return ;
// }
// #include <stdio.h>
// void	ft_printlst(t_list *lst)
// {
// 	if (lst == NULL)
// 	{
// 		printf("null\n");
// 		return ;
// 	}
// 	while (lst->next != NULL)
// 	{
// 		printf("%s\n", (char *)(lst->content));
// 		lst = lst->next;
// 	}
// 	printf("%s\n", (char *)(lst->content));
// }

// int	main(void)
// {
// 	t_list *nd1, *nd2, *nd3, *lst;
// 	char	content1[] = "I am a cat";
// 	char	content2[] = "as yet";
// 	char	content3[] = "I have no name";
// 	void (*f)(void *);

// 	f = delete;
// 	nd1 = ft_lstnew (content1);
// 	lst = nd1;
// 	nd2 = ft_lstnew (content2);
// 	ft_lstadd_back (&lst, nd2);
// 	nd3 = ft_lstnew(content3);
// 	ft_lstadd_back (&lst, nd3);
// 	ft_printlst (lst);
// 	printf("%p\n", lst);
// 	ft_lstclear(&lst, f);
// 	ft_printlst (lst);
// 	return (0);
// }

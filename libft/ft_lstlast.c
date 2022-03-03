/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:53:23 by kahirose          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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
// 	printf("%p\n", nd1);
// 	printf("%p\n", nd2);
// 	printf("%p\n", nd3);
// 		printf("%p\n",ft_lstlast (lst));
// 	return (0);
// }

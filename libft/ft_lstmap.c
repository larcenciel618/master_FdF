/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:15:35 by kahirose          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*list;

	if (lst == NULL || f == NULL)
		return (NULL);
	lst2 = malloc(sizeof(t_list));
	if (lst2 == NULL)
		return (NULL);
	list = lst2;
	while (lst->next != NULL)
	{
		lst2->content = f(lst->content);
		lst2->next = malloc(sizeof(t_list));
		if (lst2->next == NULL)
		{
			ft_lstclear(&list, del);
			return (list);
		}
		lst = lst->next;
		lst2 = lst2->next;
	}
	lst2->content = f(lst->content);
	lst2->next = NULL;
	return (list);
}

//del==NULL 弾かないようにunittestでなってる
// void	*aiu(void *content)
// {
// 	char	*str;
// 	int i = 0;

// 	str = (char	*)content;
// 	while(str[i])
// 	{
// 		if (str[i] >= 97 && str[i] <= 122)
// 			str[i] -= 32;
// 		i++;
// 	}
// 	return (str);
// }

// void del(void *content)
// {
// 	return ;
// }
// #include <stdio.h>
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
// 	t_list *nd1, *nd2, *nd3, *lst, *lst2;
// 	char	content1[] = "I am cat";
// 	char	content2[] = "as yet";
// 	char	content3[] = "I have no name";
// 	void *(*f)(void *);
// 	void (*f2)(void *);

// 	f = aiu;
// 	f2 = del;
// 	nd1 = ft_lstnew (content1);
// 	lst = nd1;
// 	nd2 = ft_lstnew (content2);
// 	ft_lstadd_back (&lst, nd2);
// 	nd3 = ft_lstnew(content3);
// 	ft_lstadd_back (&lst, nd3);
// 	printf("%p\n", lst);
// 	ft_printlst (lst);
// 	ft_printlst (lst);
// 	printf("%p\n", lst);
// 	lst2 = ft_lstmap(lst, f, f2);
// 	printf("%p\n", lst2);
// 	ft_printlst (lst2);
// 	return (0);
// }

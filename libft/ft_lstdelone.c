/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:43:16 by kahirose          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// void	delete(void *content)
// {
// 	int i = 0;
// 	char	*str;

// 	str = (char *)content;
// 	//free(content);
// 	while (str[i] != '\0')
// 		str[i++] = 0;
// }
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
// 	ft_printlst (lst);//contentを表示していく関数
// 	// printf("%p\n", lst);
// 	ft_lstdelone(nd2, f);
// 	ft_printlst (lst);//contentを表示していく関数
// 	return (0);
// }

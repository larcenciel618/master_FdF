/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:55:20 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/12 23:55:28 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_llist	*line_listnew(char *content)
{
	t_llist	*ndPtr;

	ndPtr = malloc(sizeof(t_llist));
	if (ndPtr == NULL)
		return (NULL);
	else
	{
		ndPtr->content = content;
		ndPtr->next = NULL;
		return (ndPtr);
	}
}

void	line_lstadd_back(t_llist **lst, t_llist *new)
{
	t_llist	*t_last;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		t_last = line_lstlast(*lst);
		t_last->next = new;
	}
}

t_llist	*line_lstlast(t_llist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	line_lstclear(t_llist **lst)
{
	t_llist	*nxt;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		nxt = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = nxt;
	}
	*lst = NULL;
}

int	line_lstsize(t_llist *lst)
{
	int	count;

	count = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

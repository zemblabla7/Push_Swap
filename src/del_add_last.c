/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_add_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:42:15 by carolina          #+#    #+#             */
/*   Updated: 2023/04/17 13:27:42 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstdel_all(t_element **lst)
{
	t_element	*temp;

	if (*lst != NULL)
	{
		while (*lst != NULL)
		{
			temp = *lst;
			*lst = (*lst)->next;
			free(temp);
		}
	}
}

void	lstadd_back(t_element **lst, t_element *new)
{
	t_element	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = lstlast(*lst);
		temp -> next = new;
	}
}

t_element	*lstlast(t_element *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_element	*lst_prevlast(t_element *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_element	*lst_prevprevlast(t_element *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

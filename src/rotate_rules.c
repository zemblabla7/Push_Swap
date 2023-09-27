/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:52:57 by casomarr          #+#    #+#             */
/*   Updated: 2023/04/17 14:06:51 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_element **lst, char c)
{
	t_element	*last;
	t_element	*first;

	if (list_length(*lst) < 2)
		return ;
	last = lstlast(*lst);
	first = *lst;
	*lst = (*lst)->next;
	last->next = first;
	first->next = NULL;
	if (c == 'A')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_element **lst1, t_element **lst2)
{
	t_element	*last;
	t_element	*first;

	if (list_length(*lst1) > 1)
	{
		last = lstlast(*lst1);
		first = *lst1;
		*lst1 = (*lst1)->next;
		last->next = first;
		first->next = NULL;
	}
	if (list_length(*lst2) > 1)
	{
		last = lstlast(*lst2);
		first = *lst2;
		*lst2 = (*lst2)->next;
		last->next = first;
		first->next = NULL;
	}
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_element **lst, char c)
{
	t_element	*last;
	t_element	*new_last;
	t_element	*first;

	if (list_length(*lst) < 2)
		return ;
	first = *lst;
	new_last = *lst;
	last = *lst;
	while (last->next != NULL)
	{
		new_last = last;
		last = last->next;
	}
	(*lst) = last;
	last->next = first;
	new_last->next = NULL;
	if (c == 'A')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_element **lst1, t_element **lst2)
{
	t_element	*last;
	t_element	*new_last;
	t_element	*first;

	if (list_length(*lst1) > 1)
	{
		first = *lst1;
		new_last = *lst1;
		last = *lst1;
		while (last->next != NULL)
		{
			new_last = last;
			last = last->next;
		}
		(*lst1) = last;
		last->next = first;
		new_last->next = NULL;
	}
	if (list_length(*lst2) > 1)
		reverse_rotate_both1(lst2);
	ft_putstr_fd("rrr\n", 1);
}

void	reverse_rotate_both1(t_element **lst2)
{
	t_element	*last;
	t_element	*new_last;
	t_element	*first;

	first = *lst2;
	new_last = *lst2;
	last = *lst2;
	while (last->next != NULL)
	{
		new_last = last;
		last = last->next;
	}
	(*lst2) = last;
	last->next = first;
	new_last->next = NULL;
}

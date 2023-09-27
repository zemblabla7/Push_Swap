/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:38 by casomarr          #+#    #+#             */
/*   Updated: 2023/04/20 12:55:39 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_two(t_element **lst)
{
	if (check_sorted_list(lst) == false)
		rotate(lst, 'A');
}

void	algo_three(t_element **lst)
{
	while (check_sorted_list(lst) == false)
	{
		if ((*lst)->value > (*lst)->next->value && \
		(*lst)->next->value < (*lst)->next->next->value && \
		(*lst)->value < (*lst)->next->next->value)
			swap(*lst, 'A');
		if ((*lst)->value > (*lst)->next->value && \
		(*lst)->next->value > (*lst)->next->next->value && \
		(*lst)->value > (*lst)->next->next->value)
		{
			swap(*lst, 'A');
			reverse_rotate(lst, 'A');
		}
		algo_three_bis(lst);
	}
}

void	algo_three_bis(t_element **lst)
{
	if ((*lst)->value > (*lst)->next->value && \
	(*lst)->next->value < (*lst)->next->next->value && \
	(*lst)->value > (*lst)->next->next->value)
		rotate(lst, 'A');
	if ((*lst)->value < (*lst)->next->value && \
	(*lst)->next->value > (*lst)->next->next->value && \
	(*lst)->value < (*lst)->next->next->value)
	{
		swap(*lst, 'A');
		rotate(lst, 'A');
	}
	if ((*lst)->value < (*lst)->next->value && \
	(*lst)->next->value > (*lst)->next->next->value && \
	(*lst)->value > (*lst)->next->next->value)
		reverse_rotate(lst, 'A');
}

void	algo(t_element **lsta, t_element **lstb, t_element **sorted_list)
{
	t_element	*sorted_copy;

	while (is_empty(*lstb) == false)
	{
		sorted_copy = *sorted_list;
		while (sorted_copy->next->value != (*lsta)->value)
			sorted_copy = sorted_copy->next;
		if (upper_half(lstb, sorted_copy->value) == true)
		{
			while ((*lstb)->value != sorted_copy->value)
				rotate(lstb, 'B');
		}
		else
		{
			while ((*lstb)->value != sorted_copy->value)
				reverse_rotate(lstb, 'B');
		}
		if ((*lstb) != NULL)
			push(lstb, lsta, 'A');
	}
}

bool	upper_half(t_element **lst, long nb)
{
	t_element	*copy;
	int			half;
	int			i;

	i = 0;
	half = list_length(*lst) / 2;
	copy = *lst;
	while (copy != NULL)
	{
		if (copy->value == nb)
			break ;
		i++;
		copy = copy->next;
	}
	if (i <= half)
		return (true);
	else
		return (false);
}

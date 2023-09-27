/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:43:19 by casomarr          #+#    #+#             */
/*   Updated: 2023/04/21 18:20:21 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_element *list, char c)
{
	t_element	*temp_list;
	long		temp_nb;

	if (list_length(list) < 2)
		return ;
	temp_nb = 0;
	temp_list = list;
	temp_list = temp_list->next;
	temp_nb = temp_list->value;
	temp_list->value = list->value;
	list->value = temp_nb;
	if (c == 'A')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'B')
		ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_element *lista, t_element *listb)
{
	if (list_length(lista) > 1)
		swap(lista, '0');
	if (list_length(listb) > 1)
		swap(listb, '0');
	ft_putstr_fd("ss\n", 1);
}

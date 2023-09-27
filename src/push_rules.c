/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:57 by casomarr          #+#    #+#             */
/*   Updated: 2023/04/21 13:01:46 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_element **src, t_element **dest, char c)
{
	t_element	*tmp;
	t_element	*copy;

	if (is_empty(*src) == true)
		return ;
	copy = (*src)->next;
	tmp = lstnew((*src)->value);
	free(*src);
	*src = copy;
	tmp->next = *dest;
	*dest = tmp;
	if (c == 'A')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

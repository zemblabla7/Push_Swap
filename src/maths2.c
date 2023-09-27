/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:45:55 by casomarr          #+#    #+#             */
/*   Updated: 2023/04/21 18:23:43 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_element **lst)
{
	t_element	*copy1;
	t_element	*copy2;
	long		tmp;

	if (list_length(*lst) < 2)
		return ;
	copy1 = *lst;
	while (copy1->next != NULL)
	{
		copy2 = copy1->next;
		while (copy2 != NULL)
		{
			if (copy1->value > copy2->value)
			{
				tmp = copy1->value;
				copy1->value = copy2->value;
				copy2->value = tmp;
			}
			copy2 = copy2->next;
		}
		copy1 = copy1->next;
	}
}

long	long_atoi(const char *nptr)
{
	long			nb;
	unsigned long	i;
	unsigned long	negative;

	i = 0;
	nb = 0;
	negative = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = 1;
		if (nptr[i + 1] == '+' || nptr[i + 1] == '-')
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (negative == 1)
		nb = nb * (-1);
	return (nb);
}

long	q_value_9(int nb, long length)
{
	long	q;

	if (nb == 1)
		q = length / 9;
	else if (nb == 2)
		q = (length / 9) * 2;
	else if (nb == 3)
		q = (length / 9) * 3;
	else if (nb == 4)
		q = (length / 9) * 4;
	else if (nb == 5)
		q = length / 2;
	else if (nb == 6)
		q = length - ((length / 9) * 4);
	else if (nb == 7)
		q = length - ((length / 9) * 3);
	else if (nb == 8)
		q = length - ((length / 9) * 2);
	else
		q = length - (length / 9);
	return (q);
}

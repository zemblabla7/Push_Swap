/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:19:35 by carolina          #+#    #+#             */
/*   Updated: 2023/04/24 18:42:05 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	quartile(t_element **lst, int nb)
{
	long		q;
	long		length;
	int			i;
	t_element	*sorted_copy;
	t_element	*tmp;

	sorted_copy = NULL;
	sorted_copy = list_copy(*lst);
	sort(&sorted_copy);
	length = list_length(sorted_copy);
	if (length % 2 != 0)
		length = list_length(sorted_copy) + 1;
	q = q_value_9(nb, length);
	if (length <= 100)
		q = q_value(nb, length);
	i = 0;
	tmp = sorted_copy;
	while (i < q - 1)
	{
		tmp = tmp->next;
		i++;
	}
	q = tmp->value;
	lstdel_all(&sorted_copy);
	return (q);
}

long	q_value(int nb, long length)
{
	long	q;

	if (nb == 1)
		q = length / 7;
	else if (nb == 2)
		q = (length / 7) * 2;
	else if (nb == 3)
		q = (length / 7) * 3;
	else if (nb == 4)
		q = length / 2;
	else if (nb == 5)
		q = length - (length / 7) * 3;
	else if (nb == 6)
		q = length - ((length / 7) * 2);
	else
		q = length - (length / 7);
	return (q);
}

void	sort_in_quartiles(t_element **lsta, t_element **lstb)
{
	t_element	*sorted_copy;
	int			n;

	sorted_copy = list_copy(*lsta);
	sort(&sorted_copy);
	if (list_length(*lsta) <= 100)
		n = 7;
	else
		n = 9;
	sort_in_quartiles1(lsta, lstb, n);
	sort_in_quartiles2(lsta, lstb);
	lstdel_all(&sorted_copy);
}

void	sort_in_quartiles1(t_element **lsta, t_element **lstb, int n)
{
	int			q;
	int			i;
	t_element	*sorted_copy;

	sorted_copy = list_copy(*lsta);
	sort(&sorted_copy);
	q = 1;
	while (q <= n)
	{
		i = 0;
		while (i < list_length(*lsta))
		{
			if ((*lsta)->value <= quartile(&sorted_copy, q) && \
			(*lsta)->value != lstlast(sorted_copy)->value && \
			(*lsta)->value != lst_prevlast(sorted_copy)->value && \
			(*lsta)->value != lst_prevprevlast(sorted_copy)->value)
				push(lsta, lstb, 'B');
			else
				rotate(lsta, 'A');
			i++;
		}
		q++;
	}
	lstdel_all(&sorted_copy);
}

void	sort_in_quartiles2(t_element **lsta, t_element **lstb)
{
	t_element	*sorted_copy;
	int			length;

	sorted_copy = list_copy(*lsta);
	sort(&sorted_copy);
	length = list_length(*lsta);
	if (length > 3)
	{
		while (length > 3)
		{
			if ((*lsta)->value != lstlast(sorted_copy)->value && \
			(*lsta)->value != lst_prevlast(sorted_copy)->value && \
			(*lsta)->value != lst_prevprevlast(sorted_copy)->value)
				push(lsta, lstb, 'B');
			else
				rotate(lsta, 'A');
			length = list_length(*lsta);
		}
	}
	lstdel_all(&sorted_copy);
}

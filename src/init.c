/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:07:54 by carolina          #+#    #+#             */
/*   Updated: 2023/04/28 13:22:33 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*init_lista(t_element *lista, char **argv)
{
	int			i;
	t_element	*tmp;

	i = 1;
	while (argv[i] != NULL)
	{
		tmp = lstnew(long_atoi(argv[i]));
		lstadd_back(&lista, tmp);
		i++;
	}
	return (lista);
}

bool	is_empty(t_element *list)
{
	if (list == NULL)
		return (true);
	return (false);
}

int	list_length(t_element *list)
{
	int	size;

	size = 0;
	if (is_empty(list) == false)
	{
		while (list != NULL)
		{
			size++;
			list = list->next;
		}
	}
	return (size);
}

t_element	*lstnew(long content)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new -> value = content;
	new -> next = NULL;
	return (new);
}

t_element	*list_copy(t_element *lst)
{
	t_element	*copy;
	t_element	*prev;
	t_element	*curr;
	t_element	*new;

	copy = NULL;
	prev = NULL;
	curr = lst;
	while (curr != NULL)
	{
		new = lstnew(curr->value);
		if (prev == NULL)
			copy = new;
		else
			prev->next = new;
		prev = new;
		curr = curr->next;
	}
	return (copy);
}

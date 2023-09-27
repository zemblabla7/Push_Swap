/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:30:42 by carolina          #+#    #+#             */
/*   Updated: 2023/04/24 18:42:26 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	isdigit2(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	check_valid_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (isdigit2(*argv[i]) == 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_no_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (long_atoi(argv[i]) == long_atoi(argv[j]))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	check_max_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (long_atoi(argv[i]) > INT_MAX || long_atoi(argv[i]) < INT_MIN \
		|| ft_strlen(argv[i]) > 11) // j'aurais du compter ft_strlen a partir dapres les espaces et les 0 (de la meme facon que atoi les supprime). Par exemple en faisant un itoa du retour de atoi et le comparer a ce que je lui ai passe.
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	check_sorted_list(t_element **lst)
{
	t_element	*copy;

	copy = *lst;
	while (copy != NULL)
	{
		if ((copy)->next != NULL)
		{
			if ((copy)->value > (copy)->next->value)
				return (false);
			(copy) = (copy)->next;
		}
		else
			break ;
	}
	return (true);
}

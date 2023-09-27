/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:07:49 by carolina          #+#    #+#             */
/*   Updated: 2023/04/28 13:54:39 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_element	*lista;
	t_element	*listb;
	t_element	*sorted_copy;

	check_list(argc, argv);
	lista = NULL;
	lista = init_lista(lista, argv);
	listb = NULL;
	if (list_length(lista) == 2)
		algo_two(&lista);
	else if (list_length(lista) == 3)
		algo_three(&lista);
	else
	{
		sorted_copy = list_copy(lista);
		sort(&sorted_copy);
		if (list_length(lista) <= 10)
			algo_less_than_10(&lista, &listb, &sorted_copy);
		else
			algo_more_than_10(&lista, &listb, &sorted_copy);
		lstdel_all(&listb);
		lstdel_all(&sorted_copy);
	}
	lstdel_all(&lista);
	return (0);
}

void	check_list(int argc, char **argv)
{
	if (check_valid_arguments(argv) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error :\n Incorrect element type in list\n", 2);
		exit(1);
	}
	if (check_no_duplicates(argv) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error :\n Elements in double in list\n", 2);
		exit(1);
	}
	if (check_max_int(argv) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error :\n Element bigger than integer\n", 2);
		exit(1);
	}
	if (argc <= 2)
		exit(1);
	if (check_sorted_arguments(argv) == true)
		exit(1);
}

void	algo_less_than_10(t_element **lista, t_element **listb, \
t_element **sorted_list)
{
	while (list_length(*lista) > 3)
	{
		if ((*lista)->value != lstlast(*sorted_list)->value && \
		(*lista)->value != lst_prevlast(*sorted_list)->value && \
		(*lista)->value != lst_prevprevlast(*sorted_list)->value)
			push(lista, listb, 'B');
		else
			rotate(lista, 'A');
	}
	algo_three(lista);
	algo(lista, listb, sorted_list);
}

void	algo_more_than_10(t_element **lista, t_element **listb, \
t_element **sorted_list)
{
	sort_in_quartiles(lista, listb);
	algo_three(lista);
	algo(lista, listb, sorted_list);
}

bool	check_sorted_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i + 1])
	{
		if (long_atoi(argv[i]) > long_atoi(argv[i + 1]))
			return (false);
		i++;
	}
	return (true);
}

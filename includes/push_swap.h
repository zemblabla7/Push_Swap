/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:08:40 by carolina          #+#    #+#             */
/*   Updated: 2023/04/28 13:55:24 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_element
{
	long				value;
	struct s_element	*next;
}	t_element;

/*INIT */
bool		is_empty(t_element *list);
int			list_length(t_element *list);
t_element	*lstnew(long content);
t_element	*init_lista(t_element *lista, char **argv);
t_element	*list_copy(t_element *lst);

/*DEL_ADD_LAST*/
void		lstdel_all(t_element **lst);
void		lstadd_back(t_element **lst, t_element *new);
t_element	*lstlast(t_element *lst);
t_element	*lst_prevlast(t_element *lst);
t_element	*lst_prevprevlast(t_element *lst);

/*CHECK_VALID_LIST*/
int			isdigit2(int c);
int			check_valid_arguments(char **argv);
int			check_no_duplicates(char **argv);
bool		check_max_int(char **argv);
bool		check_sorted_list(t_element **lst);

/*SWAP_RULES*/
void		swap(t_element *list, char c);
void		swap_both(t_element *lista, t_element *listB);

/*PUSH_RULES*/
void		push(t_element **src, t_element **dest, char c);

/*ROTATE_RULES*/
void		rotate(t_element **lst, char c);
void		rotate_both(t_element **lst1, t_element **lst2);
void		reverse_rotate(t_element **lst, char c);
void		reverse_rotate_both(t_element **lst1, t_element **lst2);
void		reverse_rotate_both1(t_element **lst2);

/*MATHS*/
long		quartile(t_element **lst, int nb);
void		sort_in_quartiles(t_element **lsta, t_element **lstb);
void		sort_in_quartiles1(t_element **lsta, t_element **lstb, int n);
void		sort_in_quartiles2(t_element **lsta, t_element **lstb);
long		q_value(int nb, long length);

/*MATHS2*/
void		sort(t_element **lst);
long		long_atoi(const char *nptr);
long		q_value_9(int nb, long length);

/*ALGORITHMS*/
void		algo_two(t_element **lst);
void		algo_three(t_element **lst);
void		algo_three_bis(t_element **lst);
void		algo(t_element **lsta, t_element **lstb, t_element **sorted_list);
bool		upper_half(t_element **lst, long nb);

/*MAIN*/
void		algo_less_than_10(t_element **lista, t_element **listb, \
t_element **sorted_list);
void		algo_more_than_10(t_element **lista, t_element **listb, \
t_element **sorted_list);
void		check_list(int argc, char **argv);
bool		check_sorted_arguments(char **argv);

#endif
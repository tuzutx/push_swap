/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:57:09 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/03 13:30:04 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../printf/include/ft_printf.h"

typedef struct s_push_swap
{
	int		i;
	t_list	**a;
	t_list	**b;
}			t_push_swap;

//operators.c
void	swap(t_list **lst);
void	push(t_list **extractnode, t_list **putnode);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
//errors.c
int		errorint(char *argc);
int		errornum(char **argc, t_push_swap *data);
int		errordup(t_push_swap *data);
int		errorargv(int argv, char **argc);
//clean.c
void	free_stack(t_list **stack);
void	clean_all(t_push_swap *data);
//algo.c
void	order_first_two(t_push_swap *data, t_list *b);
void	first_step(t_push_swap *data);
void	turkish_algo(t_push_swap *data);
//algorithm_motor.c
void	cost_a(t_list *a, t_push_swap *data);
void	cost_b(t_list *a, int target, int indexmax);
t_list	*if_target_not_found(t_list *b);
t_list	*target_b(t_list *a, t_list *b);
void	motor(t_push_swap *data);
//algorithm_ejecution.c
t_list	*cheapestfunc(t_list *a);
void	in_the_same_median(t_push_swap *data, t_list *a, t_list *b);
void	move_a(t_push_swap *data, t_list *a);
void	move_b(t_push_swap *data, t_list *b);
void	ejecution(t_push_swap *data);
//algorithm_sort2.c
t_list	*lowestfunc(t_list *a);
int		higherfunc(t_list *a);
void	sort_three(t_push_swap *data);
void	ejecution_2(t_push_swap *data);
//algorithm_aux.c
void	set_index(t_list *stack);
void	count_i(t_list *a, t_push_swap *data);

#endif

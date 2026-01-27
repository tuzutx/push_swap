/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaguirr <egaguirr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:57:09 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/27 19:22:21 by egaguirr         ###   ########.fr       */
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
void	set_index(t_list *stack);
void	turkish_algo(t_push_swap *data);
//algorithm_motor.c
void	cost_a(t_list *a, t_push_swap *data);
void	cost_b(t_list *a,int target, int indexmax);
int		target_b(t_list *a, t_list *b);

#endif

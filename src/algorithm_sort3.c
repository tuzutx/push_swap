/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:36:13 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/03 15:26:43 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*lowestfunc(t_list *a)
{
	t_list	*lowest;

	lowest = a;
	a = a->next;
	while (a)
	{
		if (lowest->content > a->content)
			lowest = a;
		a = a->next;
	}
	return (lowest);
}

int	higherfunc(t_list *a)
{
	int	higher;
	int	indx;

	set_index(a);
	higher = a->content;
	indx = a->index;
	a = a->next;
	while (a)
	{
		if (higher < a->content)
		{
			indx = a->index;
			higher = a->content;
		}
		a = a->next;
	}
	return (indx);
}

void	sort_three(t_push_swap *data, t_list *a)
{
	int	higher;

	higher = higherfunc(*data->a);
	if (higher == 1)
	{
		rotate(data->a);
		ft_printf("ra\n");
	}
	else if (higher == 2)
	{
		reverse_rotate(data->a);
		ft_printf("ra\n");
	}
	if (a->content > (a->next)->content)
	{
		swap(data->a);
		ft_printf("sa\n");
	}
}

void	ejecution_2(t_push_swap *data)
{
	t_list	*target;
	t_list	*lowest;

	while (*data->b)
	{
		target = target_b(*data->b, *data->a);
		move_a(data, target);
		push(data->b, data->a);
		ft_printf("pa");
	}
	lowest = lowestfunc(*data->a);
	move_a(data, lowest);
	return ;
}

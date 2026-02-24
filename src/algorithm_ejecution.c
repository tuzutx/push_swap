/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_ejecution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:12:36 by egaguirr          #+#    #+#             */
/*   Updated: 2026/02/24 16:09:20 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*cheapestfunc(t_list *a)
{
	t_list	*cheapestnode;
	int		comp;

	comp = 2147483647;
	while (a)
	{
		if (comp > a->push_cost)
		{
			cheapestnode = a;
			comp = a->push_cost;
		}
		a = a->next;
	}
	return (cheapestnode);
}

void	in_the_same_median(t_push_swap *data, t_list *a, t_list *b)
{
	while ((*data->a != a && *data->b != b))
	{
		if (a->median == 1 && b->median == 1)
		{
			rotate(data->a);
			rotate(data->b);
			ft_printf("rr\n");
		}
		else if (a->median == 0 && b->median == 0)
		{
			reverse_rotate(data->a);
			reverse_rotate(data->b);
			ft_printf("rrr\n");
		}
		else
			break ;
		set_index(a);
		set_index(b);
	}
}

void	move_a(t_push_swap *data, t_list *a)
{
	while (*data->a != a)
	{
		if (a->median == 1)
		{
			rotate(data->a);
			ft_printf("ra\n");
		}
		else
		{
			reverse_rotate(data->a);
			ft_printf("rra\n");
		}
		set_index(a);
	}
	return ;
}

void	move_b(t_push_swap *data, t_list *b)
{
	while (*data->b != b)
	{
		if (b->median == 1)
		{
			rotate(data->b);
			ft_printf("rb\n");
		}
		else
		{
			reverse_rotate(data->b);
			ft_printf("rrb\n");
		}
		set_index(b);
	}
	return ;
}

void	ejecution(t_push_swap *data)
{
	t_list	*cheapest;
	t_list	*target;

	cheapest = cheapestfunc(*data->a);
	ft_printf("--- DEBUG: El motor dice que costará: %d ---\n", cheapest->push_cost);
	target = cheapest->target;
	in_the_same_median(data, cheapest, target);
	move_a(data, cheapest);
	move_b(data, target);
	push(data->a, data->b);
	ft_printf("pb\n");
	return ;
}

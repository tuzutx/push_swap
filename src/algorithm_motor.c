/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_motor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:15:01 by egaguirr          #+#    #+#             */
/*   Updated: 2026/02/24 15:38:57 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

 void	cost(t_list *a, t_list *b, int maxa, int maxb)
{
	if (a->median == 1)
		a->push_cost = a->index;
	else
		a->push_cost = maxa - a->index;
	if (b->median == 1)
		a->push_cost += b->index;
	else
		a->push_cost += maxb - b->index;
	return ;
}
/*
void	cost_b(t_list *a, t_list *target, int indexmax)
{
	if (a->median == target->median && a->median == 1)
	{
		if ((a->index >= target->index))
			return;
		else
		{
			a->push_cost += target->index - a->index;
			return;
		}
	}
	else if (a->median == target->median && a->median == 0)
	{
		if ((a->index <= target->index))
			return;
		else
		{
			a->push_cost += a->index - target->index;
			return;
		}
	}
	if (target->median == 1)
		a->push_cost += target->index;
	else
		a->push_cost += (indexmax - target->index);
	return ;
} */

t_list	*if_target_not_found(t_list *b)
{
	t_list	*target;
	long	targetcont;

	target = NULL;
	targetcont = -2147483649;
	while (b)
	{
		if (targetcont < b->content)
		{
			targetcont = b->content;
			target = b;
		}
		b = b->next;
	}
	return (target);
}

t_list	*target_b(t_list *a, t_list *b)
{
	t_list	*target;
	t_list	*c;
	long	targetcont;

	target = NULL;
	c = b;
	targetcont = -2147483649;
	while (b)
	{
		if ((b->content < a->content) && (targetcont < b->content))
		{
			targetcont = b->content;
			target = b;
		}
		b = b->next;
	}
	if (target == NULL)
		target = if_target_not_found(c);
	return (target);
}

void	push_cost(t_list *target, t_list *a, t_push_swap *data)
{
	int	mv_a;
	int	mv_b;

	a->push_cost = 0;
	if (a->median == target->median && a->median == 1)
	{
		if (a->index <= target->index)
			a->push_cost = target->index;
		else
			a->push_cost = a->index;
	}
	else if (a->median == target->median && a->median == 0)
	{
		mv_a = data->i - a->index;
		mv_b = data->indx_b - target->index;
		if (mv_a <= mv_b)
			a->push_cost = mv_b;
		else
			a->push_cost = mv_a;
	}
	else
		cost(a, target, data->i, data->indx_b);
	return ;

}

void	motor(t_push_swap *data)
{
	t_list	*target;
	t_list	*a;

	target = NULL;
	a = *data->a;
	set_index(*data->a);
	set_index(*data->b);
	count_indx_b(*data->b, data);
	while (a)
	{
		//cost_a(a, data);
		target = target_b(a, *data->b);
		a->target = target;
		//cost_b(a, target, data->indx_b);
		push_cost(target, a, data);
		a = a->next;
	}
	return ;
}

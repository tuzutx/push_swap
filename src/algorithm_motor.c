/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_motor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:15:01 by egaguirr          #+#    #+#             */
/*   Updated: 2026/01/28 17:47:55 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cost_a(t_list *a, t_push_swap *data)
{
	if (a->median == 1)
		a->push_cost = a->index;
	else
		a->push_cost = data->i - a->index;
}

void	cost_b(t_list *a, t_list *target, int indexmax)
{
	if (target->index <= indexmax / 2)
		a->push_cost += target->index;
	else
		a->push_cost += (indexmax - target->index);
	a->push_cost++;
}

t_list	*target_b(t_list *a, t_list *b)
{
	t_list	*c;
	t_list	*target;
	long	targetcont;

	c = b;
	target = NULL;
	targetcont = -2147483649;
	while (c)
	{
		if (c->content < a->content && targetcont < c->content)
		{
			targetcont = c->content;
			target = c;
		}
		c = c->next;
	}
	if (target == NULL)
	{
		c = b;
		while (c)
		{
			if (targetcont < c->content)
			{
				targetcont = c->content;
				target = c;
			}
			c = c->next;
		}
	}
	return (target);
}

void	motor(t_push_swap *data)
{
	t_list	*target;

	set_index(*data->a);
	set_index(*data->b);
	count_i(*data->a, data);
	cost_a(*data->a, data);
	target = target_b(*data->a, *data->b);
	cost_b(*data->a, target, data->i);
	return ;
}

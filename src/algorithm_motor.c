/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_motor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaguirr <egaguirr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:15:01 by egaguirr          #+#    #+#             */
/*   Updated: 2026/01/27 19:16:35 by egaguirr         ###   ########.fr       */
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

void	cost_b(t_list *a,int target, int indexmax)
{
	if (target <= indexmax/2)
		a->push_cost += target;
	else
		a->push_cost += (indexmax - target);
	a->push_cost++;
}

int	target_b(t_list *a, t_list *b)
{
	t_list		*c;
	int			targetindx;
	long int	target;

	c = b;
	target = -2147483649;
	set_index(c);
	while (c)
	{
		if (c->content < a->content && target < c->content)
		{
			target = c->content;
			targetindx = c->index;
		}
		c = c->next;
	}
	if (target == -2147483649;)
	{
		c = b;
		while (c)
		{
			if (target < c->content)
			{
				target = c->content
				targetindx = c->index;
			}
			c = c->next
		}
	}
	return (targetindx);
}

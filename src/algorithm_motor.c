/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_motor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:15:01 by egaguirr          #+#    #+#             */
/*   Updated: 2026/02/13 12:12:29 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cost_a(t_list *a, t_push_swap *data)
{
	if (a->median == 1)
		a->push_cost = a->index;
	else
		a->push_cost = data->i - a->index;
	return ;
}

void	cost_b(t_list *a, t_list *target, int indexmax)
{
	if (target->index <= indexmax / 2)
		a->push_cost += target->index;
	else
		a->push_cost += (indexmax - target->index);
	a->push_cost++;
	return ;
}

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
	ft_printf("Target is : %d\n", target->content);
	return (target);
}

void	motor(t_push_swap *data)
{
	t_list	*target;
	t_list	*a;

	target = NULL;
	a = *data->a;
	set_index(*data->a);
	set_index(*data->b);
	while (a)
	{
		cost_a(a, data);
		target = target_b(a, *data->b);
		a->target = target;
		cost_b(a, target, data->i);
		a = a->next;
	}
	return ;
}

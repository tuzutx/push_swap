/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_ejecution2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:39:33 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/10 14:58:21 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*if_target_not_found_a(t_list *a)
{
	t_list	*target;
	long	targetcont;

	target = NULL;
	targetcont = 2147483649;
	while (a)
	{
		if (targetcont > a->content)
		{
			targetcont = a->content;
			target = a;
			ft_printf("The actual target is: %d\n", target->content);
		}
		a = a->next;
	}
	return (target);
}

t_list	*target_a(t_list *b, t_list *a)
{
	t_list	*target;
	t_list	*c;
	long	targetcont;

	target = NULL;
	c = a;
	targetcont = 2147483649;
	ft_printf("The actual cheapest is: %d\n", b->content);
	while (a)
	{
		if ((a->content < b->content) && (targetcont > a->content))
		{
			targetcont = a->content;
			target = a;
			ft_printf("The actual target is: %d\n", target->content);
		}
		a = a->next;
	}
	if (target == NULL)
		target = if_target_not_found(c);
	return (target);
}

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

void	ejecution_2(t_push_swap *data)
{
	t_list	*target;
	t_list	*lowest;

	while (*data->b)
	{
		target = target_a(*data->b, *data->a);
		move_a(data, target);
		push(data->b, data->a);
		ft_printf("pa\n");
	}
	lowest = lowestfunc(*data->a);
	move_a(data, lowest);
	return ;
}

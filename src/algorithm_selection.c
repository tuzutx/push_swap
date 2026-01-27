/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaguirr <egaguirr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:12:36 by egaguirr          #+#    #+#             */
/*   Updated: 2026/01/27 20:20:25 by egaguirr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cheapest(t_list *a)
{
	t_list	*c;
	int		comp;
	int		moveindx;

	c = a;
	moveindx = 0;
	comp = c->push_cost;
	while (c->next != NULL)
	{
		if (comp > c->push_cost)
		{
			moveindx = c->index;
			comp = c->push_cost;
		}
		c = c->next;
	}
	return (moveindx);
}

void	moveup(t_list *a, t_list *b)
{
	int	indexa;
	int	indexb;
	int	repeat;

	indexa = cheapest(a);
	indexb = target_b(a, b);
	if (index == 0)
		return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:48:12 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/23 13:01:15 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = 1;
		else
			stack->median = 0;
		stack = stack->next;
		i++;
	}
}

void turkish_algo(t_push_swap *data)
{
	//crear copiar de lista a y b
	
	//pasamos los primeros 2 elementos de la lista a a la b
	//ordenamos la pila b
	while (data->a)
	{
		set_index(data->a);
	//Algoritmo que cuente el coste de elección
	//Hacer las operaciones
	//Calcular nuevamente data->i
	}
	
}

void	greedy_1(t_list *a, t_push_swap *data)
{
	if (a->median == 1)
		a->push_cost = a->index;
	else
		a->push_cost = data->i - a->index;
}

/* void	greedy_2(t_list *a, t_list *b)
{
	t_list	*c;

	c = b;
	set_index(c);
	while (c != NULL)
		c = c->next;
	(a->push_cost)++;
	if (a->content > b->content)
		greedy_2(a->next,b);
	else if (a->content > (b->next)->content || a->content < c->content)
	{
		(a->push_cost)++;
		greedy_2(a->next,b);
	}
	else
	{
		greedy_3(a, b, c->index);
		greedy_2(a->next,b);
	}
	
} */

void	greedy_2(t_list *a, t_list *b, int indexmax)
{
	t_list	*c;
	int		target;

	c = b;
	set_index(c);
	while (c->content > a->content)
		c = c->next;
	if (c->index < indexmax/2)
		a->push_cost += c->index;
	else
		a->push_cost += (indexmax - c->index);
}

void	greedy(t_list *a, t_list *b, t_push_swap *data)
{
	t_list	*c;

	c = b;
	set_index(c);
	while (c->next != NULL)
		c = c->next;
	while(a)
	{
		greedy_1(a, data);
		(a->push_cost)++;
		if (a->content > b->content)
			a = a->next;
		else if (a->content > (b->next)->content || a->content < c->content)
			(a->push_cost)++;
		else
			greedy_2(a, b, c->index);
		a = a->next;
	}
}

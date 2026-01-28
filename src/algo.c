/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:48:12 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/28 17:42:18 by nolaeche         ###   ########.fr       */
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

void	count_i(t_list *a, t_push_swap *data)
{
	data->i = 0;
	while (a)
	{
		a = a->next;
		data->i++;
	}
}

void	turkish_algo(t_push_swap *data)
{
	int	target;
	//crear copiar de lista a y b
	
	//pasamos los primeros 2 elementos de la lista a a la b
	//ordenamos la pila b
	while (data->a) //Hasta que en la pila a solo haya 3 números.
	{//Motor
		set_index(*data->a);
		set_index(*data->b);
		count_i(*data->a, data);
		cost_a(*data->a, data);
		target = target_b(*data->a, *data->b);
		cost_b(*data->a, target, data->i);
	//Seleccionar y ejecutar
		ejecution(data);
	}
	//Sort3
	//pa todo
	//Poner el num más pequeño en la posición 0	
}

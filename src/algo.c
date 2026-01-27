/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaguirr <egaguirr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:48:12 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/27 20:11:17 by egaguirr         ###   ########.fr       */
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

void	turkish_algo(t_push_swap *data)
{
	int	target;
	//crear copiar de lista a y b
	
	//pasamos los primeros 2 elementos de la lista a a la b
	//ordenamos la pila b
	while (data->a) //Hasta que en la pila a solo haya 3 números.
	{//Motor
		set_index(data->a);
		cost_a(a, data);
		target = target_b(a, b);
		cost_b(a, target, data->i);
	//Seleccionar y ejecutar
		//Encontrar el numero con menor coste en la pila A
		//Mover la pila A para que ese numero este arriba
		//Mover la pila B para que el target este arriba del todo
		//pb
	}
	//Sort3
	//pa todo
	//Poner el num más pequeño en la posición 0	
}

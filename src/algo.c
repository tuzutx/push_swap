/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:48:12 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/03 18:46:32 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	order_first_two(t_push_swap *data, t_list *b)
{
	if (b->content < (b->next)->content)
	{
		swap(data->b);
		ft_printf("sb");
	}
	return ;
}

void	first_step(t_push_swap *data)
{
	push(data->a, data->b);
	ft_printf("pb\n");
	push(data->a, data->b);
	ft_printf("pb\n");
	order_first_two(data, *data->b);
	return ;
}

void	turkish_algo(t_push_swap *data)
{
	first_step(data);
	while (data->i > 3)
	{
		motor(data);
		ejecution(data);
	}
	sort_three(data, *data->a);
	ejecution_2(data);
	return ;
}

void	push_swap(t_push_swap *data)
{
	if (data->i < 5)
	{
		clean_all(data);
		return ;
	}
	else
		turkish_algo(data);
	clean_all(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:48:12 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/16 11:32:58 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	if_only_two(t_push_swap *data, t_list *a)
{
	if (a->content > (a->next)->content)
	{
		swap(data->a);
		ft_printf("sa\n");
	}
	return ;
}

void	order_first_two(t_push_swap *data, t_list *b)
{
	if (b->content < (b->next)->content)
	{
		swap(data->b);
		ft_printf("sb\n");
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
	count_i(*data->a, data);
	while (data->i > 3)
	{
		motor(data);
		ejecution(data);
		count_i(*data->a, data);
	}
	//ft_printf("Llegamos al sort3\n");
	/*sort_three(data);
	ejecution_2(data); */
	return ;
}

void	push_swap(t_push_swap *data)
{
	count_i(*data->a, data);
	if (data->i == 1)
		;
	else if (data->i == 2)
		if_only_two(data, *data->a);
	else if (data->i == 3)
		sort_three(data);
	else if (data->i == 4)
	{
		push(data->a, data->b);
		ft_printf("pa\n");
		sort_three(data);
		ejecution_2(data);
	}
	else
		turkish_algo(data);
	//print_a(*data->a);
	clean_all(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:26:08 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/24 16:00:22 by nolaeche         ###   ########.fr       */
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

void	count_indx_b(t_list *b, t_push_swap *data)
{
	data->indx_b = 0;
	while (b)
	{
		b = b->next;
		data->indx_b++;
	}
	return ;
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

int	is_valid(char *argc)
{
	int	i;

	i = 0;
	if (argc[i] == '-' || argc[i] == '+')
		i++;
	if (argc[i] == '\0')
		return (1);
	while (argc[i] != '\0')
	{
		if ((argc[i] <= '9' && argc[i] >= '0'))
			i++;
		else
			return (1);
	}
	return (0);
}

void	print_a(t_list *a)
{
	ft_printf("Lista a:\n");
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}

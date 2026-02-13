/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:36:13 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/09 16:39:36 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	higherfunc(t_list *a)
{
	int	higher;
	int	indx;

	set_index(a);
	higher = a->content;
	indx = a->index;
	a = a->next;
	while (a)
	{
		if (higher < a->content)
		{
			indx = a->index;
			higher = a->content;
		}
		a = a->next;
	}
	return (indx);
}

void	sort_three(t_push_swap *data)
{
	int		higher;
	t_list	*a;

	higher = higherfunc(*data->a);
	if (higher == 0)
	{
		rotate(data->a);
		ft_printf("ra\n");
	}
	else if (higher == 1)
	{
		reverse_rotate(data->a);
		ft_printf("rra\n");
	}
	a = *data->a;
	if (a->content > (a->next)->content)
	{
		swap(data->a);
		ft_printf("sa\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:36:13 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/28 18:00:48 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	higher(t_list *a)
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
}

void	sort_three(t_push_swap *data, t_list *a)
{
	int	higher;

	higher = higher(a);
	if (higher == 1)
	{
		rotate(data->a);
		ft_printf("ra\n");
	}
	else if (higher == 2)
	{
		reverser_rotate(data->a);
		ft_printf("ra\n");
	}
	if (a->content > (a->next)->content)
	{
		swap(data->a);
		ft_printf("sa\n");
	}
}

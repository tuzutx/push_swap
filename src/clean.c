/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:15:28 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/21 20:46:00 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
    }
	*stack = NULL;
}

void	clean_all(t_push_swap *data)
{
	if (data->a)
	{
		free_stack(data->a);
		free(data->a);
	}
	if (data->b)
	{
		free_stack(data->b);
		free(data->b);
	}
	free(data);
	write(2, "Error\n", 6);
}
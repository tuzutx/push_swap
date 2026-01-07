/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:38:53 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/07 19:01:52 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
//tengo que pensar como llamar para cuando se pida sa o sb
void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*lst) < 2)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	return ;
}

void	push(t_list **extractnode, t_list **putnode)
{
	t_list	*temp;

	if (!(*extractnode))
		return ;
	temp = *extractnode;
	*extractnode = (*extractnode)->next;
	temp->next = NULL;
	ft_lstadd_front(putnode, temp);
	return ;
}

void	rotate(t_list **lst)
{
	t_list	*temp;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
	return ;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	ft_lstadd_front(lst, last);
	return ;
}

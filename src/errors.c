/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:01:15 by nolaeche          #+#    #+#             */
/*   Updated: 2026/02/03 13:38:26 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Tres errores posibles:
//1.Que pasen argumentos no númericos
//2.Los números exceden los límites de int
//3.Números duplicados

int	errorint(char *argc)
{
	if (atoi(argc) < -2147483648)
		return (1);
	else if (atoi(argc) > 2147483647)
		return (1);
	return (0);
}

int	errornum(char **argc, t_push_swap *data)
{
	t_list	*aux;

	data->i = 0;
	data->a = malloc(sizeof(t_list));
	if (!data->a)
		return (1);
	data->b = malloc(sizeof(t_list));
	if (!data->b)
		return (1);
	while (argc[data->i] != NULL)
	{
		if (errorint(argc[data->i] == 1))
			return (1);
		if (*(data->a) == NULL)
			*(data->a) = ft_lstnew(atoi(argc[data->i]));
		else
		{
			aux = *(data->a);
			while (aux->next != NULL)
				aux = aux->next;
			aux->next = ft_lstnew(atoi(argc[data->i]));
		}
		data->i++;
	}
	return (0);
}

int	errordup(t_push_swap *data)
{
	t_list	*orig;
	t_list	*comp;

	orig = *(data->a);
	comp = *(data->a);
	while (orig != NULL)
	{
		comp = orig->next;
		while (comp != NULL)
		{
			if (comp->content == orig->content)
				return (1);
			comp = comp->next;
		}
		orig = orig->next;
	}
	return (0);
}

int	errorargv(int argv, char **argc)
{
	t_push_swap	*data;

	data = (t_push_swap *)ft_calloc(1, sizeof(t_push_swap));
	if (!data)
		return (1);
	if (argv == 1)
	{
		clean_all(data);
		return (1);
	}
	if (errornum(argc, data) == 1)
	{
		clean_all(data);
		return (1);
	}
	if (errordup(data) == 1)
	{
		clean_all(data);
		return (1);
	}
	return (0);
}

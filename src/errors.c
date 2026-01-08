/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:01:15 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/08 19:58:10 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Tres errores posibles:
//1.Que pasen argumentos no númericos
//2.Los números exceden los límites de int
//3.Números duplicados

void	errornum(char **argc)
{
	int		i;
	t_list	*a;

	i = 0;
	while (argc[i] != NULL)
	{
		a->content = atoi(argc[i]);
		i++;
		a = a->next;
	}
	return ;
}

void	

int	errorargv(int argv, char **argc)
{
	if (argv == 1)
		ft_printf("Error: No se han añadido números");
	errornum(argc);
}


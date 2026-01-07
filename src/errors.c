/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolaeche <nolaeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:01:15 by nolaeche          #+#    #+#             */
/*   Updated: 2026/01/07 19:09:23 by nolaeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Tres errores posibles:
//1.Que pasen argumentos no númericos
//2.Los números exceden los límites de int
//3.Números duplicados

int	errorargv(int argv, char **argc)
{
	if (argv == 1)
		ft_printf("Error: No se han añadido números");
}


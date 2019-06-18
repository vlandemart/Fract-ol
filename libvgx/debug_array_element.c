/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_array_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:48:21 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:48:44 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

void	debug_array_element(int **arr, int i, int j, int debug_lvl)
{
	if (debug_lvl < DEBUG_LEVEL)
		return ;
	ft_putstr("(");
	ft_putnbr(i);
	ft_putstr(":");
	ft_putnbr(j);
	ft_putstr(")");
	ft_putstr(" = ");
	ft_putnbr(arr[i][j]);
	ft_putendl("");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:49:26 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:49:48 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

void	debug_matrix(t_mat4x4 m, int debug_lvl)
{
	int i;
	int j;

	if (debug_lvl < DEBUG_LEVEL)
		return ;
	i = 0;
	while (i < 4)
	{
		ft_putstr("( ");
		j = 0;
		while (j < 4)
		{
			ft_putnbr(m.m[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putendl(")");
		i++;
	}
	ft_putendl("");
}

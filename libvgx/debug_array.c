/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:48:54 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:49:18 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

void	debug_array(int **arr, int h, int w, int debug_lvl)
{
	int i;
	int j;

	if (debug_lvl < DEBUG_LEVEL)
		return ;
	ft_putendl("");
	ft_putendl("Parsed map:");
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			ft_putnbr(arr[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putendl("");
	}
}

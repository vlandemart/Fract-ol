/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_v3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:50:04 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:50:30 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

void	debug_v3(t_vector3 v3, int debug_lvl)
{
	if (debug_lvl < DEBUG_LEVEL)
		return ;
	ft_putstr("(");
	ft_putnbr(v3.x);
	ft_putstr(":");
	ft_putnbr(v3.y);
	ft_putstr(":");
	ft_putnbr(v3.z);
	ft_putstr(") ");
	ft_putnbr(v3.color);
	ft_putstr(".");
}

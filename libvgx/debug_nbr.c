/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:47:49 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:48:11 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

void	debug_nbr(int nbr, int debug_lvl)
{
	if (debug_lvl < DEBUG_LEVEL)
		return ;
	ft_putnbr(nbr);
}

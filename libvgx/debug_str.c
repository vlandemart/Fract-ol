/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:50:52 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:50:54 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

void	debug_str(char *str, int debug_lvl)
{
	if (debug_lvl < DEBUG_LEVEL)
		return ;
	ft_putstr(str);
}

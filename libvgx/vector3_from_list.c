/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_from_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:34:25 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:34:44 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_vector3	vector3_from_list(t_list *lst)
{
	t_vector3 result;

	result.x = ((t_vector3*)lst->content)->x;
	result.y = ((t_vector3*)lst->content)->y;
	result.z = ((t_vector3*)lst->content)->z;
	result.color = ((t_vector3*)lst->content)->color;
	return (result);
}

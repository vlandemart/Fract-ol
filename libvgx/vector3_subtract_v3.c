/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_subtract_v3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:36:06 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:36:24 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_vector3	vector3_subtract_v3(t_vector3 v1, t_vector3 v2)
{
	t_vector3 result;

	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	result = v1;
	return (result);
}

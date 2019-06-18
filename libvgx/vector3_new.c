/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:33:37 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:33:55 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_vector3	vector3_new(float x, float y, float z)
{
	t_vector3 new_vector_3;

	new_vector_3.x = x;
	new_vector_3.y = y;
	new_vector_3.z = z;
	new_vector_3.color = 0xFFFFFF;
	return (new_vector_3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_divide_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:38:41 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:41:46 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_vector3	vector3_divide_f(t_vector3 v1, float num)
{
	v1.x /= num;
	v1.y /= num;
	v1.z /= num;
	return (v1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:40:19 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:42:19 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"
#include <math.h>

float	vector3_length(t_vector3 v1)
{
	return (sqrtf(vector3_dot_product(v1, v1)));
}

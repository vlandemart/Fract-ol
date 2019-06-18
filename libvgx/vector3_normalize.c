/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:40:51 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/07 15:41:35 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_vector3	vector_3_normalize(t_vector3 v1)
{
	float l;

	l = vector3_length(v1);
	return (vector3_divide_f(v1, l));
}

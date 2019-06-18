/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:39:00 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/09 16:39:01 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_mat4x4	matrix_rot_z(float angle_rad)
{
	t_mat4x4 mat_rot;

	ft_bzero(&mat_rot, sizeof(t_mat4x4));
	mat_rot.m[0][0] = cosf(angle_rad);
	mat_rot.m[0][1] = sinf(angle_rad);
	mat_rot.m[1][0] = -sinf(angle_rad);
	mat_rot.m[1][1] = cosf(angle_rad);
	mat_rot.m[2][2] = 1;
	mat_rot.m[3][3] = 1;
	return (mat_rot);
}

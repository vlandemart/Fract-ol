/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:38:45 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/09 16:38:47 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_mat4x4	matrix_rot_x(float angle_rad)
{
	t_mat4x4 mat_rot;

	ft_bzero(&mat_rot, sizeof(t_mat4x4));
	mat_rot.m[0][0] = 1.0f;
	mat_rot.m[1][1] = cosf(angle_rad);
	mat_rot.m[1][2] = sinf(angle_rad);
	mat_rot.m[2][1] = -sinf(angle_rad);
	mat_rot.m[2][2] = cosf(angle_rad);
	mat_rot.m[3][3] = 1.0f;
	return (mat_rot);
}

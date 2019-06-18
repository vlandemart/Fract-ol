/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:40:01 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/09 16:40:02 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_mat4x4	matrix_projection(float fov, float aspect, float near, float far)
{
	float		ffov_rad;
	t_mat4x4	mat;

	ffov_rad = 1.0f / tanf(fov * 0.5f / 180.0f * 3.14159f);
	bzero(&mat, sizeof(mat));
	mat.m[0][0] = aspect * ffov_rad;
	mat.m[1][1] = ffov_rad;
	mat.m[2][2] = far / (far - near);
	mat.m[3][2] = (-far * near) / (far - near);
	mat.m[2][3] = 1.0f;
	return (mat);
}

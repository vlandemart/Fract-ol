/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:40:16 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/09 16:40:17 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvgx.h"

t_mat4x4	matrix_multiplication(t_mat4x4 mat1, t_mat4x4 mat2)
{
	int			i;
	int			j;
	int			k;
	t_mat4x4	res;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.m[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				res.m[i][j] += mat1.m[i][k] * mat2.m[i][k];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:30:29 by njacobso          #+#    #+#             */
/*   Updated: 2019/05/15 15:40:17 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libvgx/libvgx.h"

void	ft_image_put_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	pos;

	if (x < 0 || y < 0 || x > SCREEN_W || y > SCREEN_H)
		return ;
	pos = x + y * SCREEN_W;
	if (pos >= SCREEN_W * SCREEN_H || pos < 0)
		return ;
	*(int *)(fractol->img_data + pos) = color;
}

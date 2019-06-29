/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:06:37 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/25 14:06:39 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			zoom_in(int x, int y, t_fractol *data)
{
	data->max = (x / data->zoom + data->max) - (x / (data->zoom * 1.3));
	data->min = (y / data->zoom + data->min) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	return (1);
}

int			zoom_out(int x, int y, t_fractol *data)
{
	data->max = (x / data->zoom + data->max) - (x / (data->zoom / 1.3));
	data->min = (y / data->zoom + data->min) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	return (1);
}

int			handle_mouse_wheel(t_fractol *data, int wheel_dir, int x, int y)
{
	if (wheel_dir < 0)
		zoom_out(x, y, data);
	else
		zoom_in(x, y, data);
	return (1);
}

/*
int			mouse_movement(int x, int y, t_fractol *data)
{
	if (data->fractal_type != 1 || data->mouse_move == 0)
		return (0);
	data->c_x = x;
	data->c_y = y;
	if (key == 1)
		data->mouse_move = data->mouse_move == 1 ? 0 : 1;
	return (update(data));
}
*/

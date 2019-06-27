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

int			mouse_movement(int x, int y, t_fractol *data)
{
	if (data->fractal_type != 1 || data->mouse_move == 0)
		return (0);
	data->c_x = x;
	data->c_y = y;
	return (update(data));
}

int			handle_mouse(int key, int x, int y, t_fractol *data)
{
	if (key == 1)
		data->mouse_move = data->mouse_move == 1 ? 0 : 1;
	if (key == 4)
		zoom_in(x, y, data);
	else if (key == 5)
		zoom_out(x, y, data);
	return (update(data));
}

int			handle_input(int key, t_fractol *fractol)
{
	if (key == 53)
		close_window(0);
	if (key == 18)
		fractol->color = 0xffffff;
	if (key == 19)
		fractol->color = 0xff0000;
	if (key == 20)
		fractol->color = 0x00ff00;
	if (key == 21)
		fractol->color = 0x0000ff;
	if (key == 69)
		fractol->it_max += 10;
	if (key == 78)
		fractol->it_max -= 10;
	return (update(fractol));
}

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

int			close_window(void *param)
{
	(void)param;
	debug_str("App was closed.\n", 5);
	exit(0);
	return (0);
}

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

int			handle_mouse(int key, int x, int y, t_fractol *data)
{
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
	fractol->it_max += 10;
	return (update(fractol));
}

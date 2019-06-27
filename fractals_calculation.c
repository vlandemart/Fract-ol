/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_calculation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:07:27 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/27 16:07:28 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_calc(t_fractol *data)
{
	long double	tmp;

	data->c_x = data->x / data->zoom + data->max;
	data->c_y = data->y / data->zoom + data->min;
	data->z_x = 0;
	data->z_y = 0;
	data->it = 0;
	while (data->z_x * data->z_x + data->z_y * data->z_y < 4 &&
			data->it < data->it_max)
	{
		tmp = data->z_x;
		data->z_x = data->z_x * data->z_x - data->z_y * data->z_y + data->c_x;
		data->z_y = 2 * data->z_y * tmp + data->c_y;
		data->it++;
	}
	fractal_output(data);
}

void	tricorn_calc(t_fractol *data)
{
	long double	tmp;

	data->c_x = data->x / data->zoom + data->max;
	data->c_y = data->y / data->zoom + data->min;
	data->z_x = 0;
	data->z_y = 0;
	data->it = 0;
	while (data->z_x * data->z_x + data->z_y * data->z_y < 4 &&
			data->it < data->it_max)
	{
		tmp = data->z_x;
		data->z_x = data->z_x * data->z_x - data->z_y * data->z_y + data->c_x;
		data->z_y = -2 * tmp * data->z_y + data->c_y;
		data->it++;
	}
	fractal_output(data);
}

void	burning_calc(t_fractol *data)
{
	long double	tmp;

	data->c_x = data->x / data->zoom + data->max;
	data->c_y = data->y / data->zoom + data->min;
	data->z_x = 0;
	data->z_y = 0;
	data->it = 0;
	while (data->z_x * data->z_x + data->z_y * data->z_y < 4 &&
			data->it < data->it_max)
	{
		tmp = data->z_x;
		data->z_x = data->z_x * data->z_x - data->z_y * data->z_y + data->c_x;
		data->z_y = fabsl(2 * data->z_y * tmp) + data->c_y;
		data->it++;
	}
	fractal_output(data);
}

void	julia_calc(t_fractol *data)
{
	long double	tmp;

	data->z_x = data->x / data->zoom + data->max;
	data->z_y = data->y / data->zoom + data->min;
	data->it = 0;
	while (data->z_x * data->z_x + data->z_y * data->z_y < 4 &&
			data->it < data->it_max)
	{
		tmp = data->z_x;
		data->z_x = data->z_x * data->z_x - data->z_y * data->z_y -
					0.8 + (data->c_x / SCREEN_W);
		data->z_y = 2 * tmp * data->z_y + data->c_y / SCREEN_W;
		data->it++;
	}
	fractal_output(data);
}

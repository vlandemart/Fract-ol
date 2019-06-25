/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:33:50 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/18 14:33:52 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_calc(t_fractol *data)
{
	long double tmp;
	int color;

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
	ft_image_put_pixel(data, data->x, data->y, 0x000000);
	color = 255 * 255 * data->it / data->it_max;
	color = color > 0xffffff ? 0xffffff : color;
	if (data->it != data->it_max)
		ft_image_put_pixel(data, data->x, data->y, color);
}

void	*mandelbrot(void *fract)
{
	t_fractol *data;

	data = (t_fractol *)fract;
	while (data->y < SCREEN_H && data->y < data->y_max)
	{
		data->x = 0;
		while (data->x < SCREEN_W)
		{
			mandelbrot_calc(data);
			data->x++;
		}
		data->y++;
	}
	return (data);
}

void	mandelbrot_pthread(t_fractol *data)
{
	t_fractol	tab[THREADS];
	pthread_t	t[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy(&tab[i], data, sizeof(t_fractol));
		tab[i].y = SCREEN_H / THREADS * i;
		tab[i].y_max = SCREEN_H / THREADS * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img_main, 0, 0);
}

void	mandelbrot_init(t_fractol *data)
{
	int bpp;
	int size;
	int end;

	data->img_data = (int *)mlx_get_data_addr(data->img_main,
											&bpp, &size, &end);
	mandelbrot_pthread(data);
}

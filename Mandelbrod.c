/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:33:50 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/18 14:33:52 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	map(long double x, long double in_min, long double in_max, long double out_min, long double out_max)
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void	mandelbrot_calc(t_fractol *data)
{
	long double a = map(data->x, 0, SCREEN_W, data->min, data->max);
	long double b = map(data->y, 0, SCREEN_H, data->min, data->max);
	long double ai = a;
	long double bi = b;

	data->it = 0;
	while (data->it < data->it_max)
	{
		long double a1 = a * a - b * b;
		long double b1 = 2 * a * b;
		a = a1 + ai;
		b = b1 + bi;
		if ((a + b) > 2)
			break ;
		data->it++;
	}
	
	int bright = map(data->it, 0, data->it_max, 0, 255);
	if (data->it == data->it_max)
		bright = 0;
	ft_image_put_pixel(data, data->x, data->y, 255 * bright + 255 * bright + 82 * bright);
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

	data->img_data = (int *)mlx_get_data_addr(data->img_main, &bpp, &size, &end);
	mandelbrot_pthread(data);
}
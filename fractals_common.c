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

void	fractal_output(t_fractol *data)
{
	int color;

	ft_image_put_pixel(data, data->x, data->y, 0x000000);
	color = data->color * (float)((float)data->it / (float)data->it_max);
	if (data->it != data->it_max)
		ft_image_put_pixel(data, data->x, data->y, color);
}

void	*fractal(void *fract)
{
	t_fractol *data;

	data = (t_fractol *)fract;
	while (data->y < SCREEN_H && data->y < data->y_max)
	{
		data->x = 0;
		while (data->x < SCREEN_W)
		{
			if (data->fractal_type == 0)
				mandelbrot_calc(data);
			else if (data->fractal_type == 1)
				julia_calc(data);
			else if (data->fractal_type == 2)
				burning_calc(data);
			else if (data->fractal_type == 3)
				tricorn_calc(data);
			data->x++;
		}
		data->y++;
	}
	return (data);
}

void	fractal_pthread(t_fractol *data)
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
		pthread_create(&t[i], NULL, fractal, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img_main, 0, 0);
}

void	fractal_init(t_fractol *data)
{
	int bpp;
	int size;
	int end;

	data->img_data = (int *)mlx_get_data_addr(data->img_main,
											&bpp, &size, &end);
	fractal_pthread(data);
}

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

int			set_pixel(t_fractol *data, int x, int y, int color)
{
	data->pixels[SCREEN_W * y + x] = color;
	return (1);
}

void	fractal_output(t_fractol *data)
{
	int color;

	set_pixel(data, data->x, data->y, 0x000000);
	color = data->color * (float)((float)data->it / (float)data->it_max);
	if (data->it != data->it_max)
		set_pixel(data, data->x, data->y, color);
}

int		fractal(void *fract)
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
	return (1);
}

void	fractal_threading(t_fractol *data)
{
	t_fractol	tab[THREADS];
	SDL_Thread	*t[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		memcpy(&tab[i], data, sizeof(t_fractol));
		tab[i].y = SCREEN_H / THREADS * i;
		tab[i].y_max = SCREEN_H / THREADS * (i + 1);
		t[i] = SDL_CreateThread(fractal, "thread", &tab[i]);
		//pthread_create(&t[i], NULL, fractal, &tab[i]);
		i++;
	}
	while (i--)
		SDL_WaitThread(t[i], NULL);
	//pthread_join(t[i], NULL);
}

void	fractal_init(t_fractol *data)
{
	fractal_threading(data);
}

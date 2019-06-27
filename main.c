/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:31:28 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/13 14:36:53 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			close_window(void *param)
{
	(void)param;
	debug_str("App was closed.\n", 5);
	exit(0);
	return (0);
}

void		clear_image(t_fractol *data)
{
	int i;
	int j;

	i = 0;
	while (i < SCREEN_W)
	{
		j = 0;
		while (j < SCREEN_H)
		{
			ft_image_put_pixel(data, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

int			update(t_fractol *fractol)
{
	char *nbr;

	clear_image(fractol);
	fractal_init(fractol);
	nbr = ft_itoa(fractol->it_max);
	mlx_string_put(fractol->mlx, fractol->win, 0, 0, 0xffffff, nbr);
	free(nbr);
	return (1);
}

int			init_fractal(char *str, t_fractol *data)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		data->fractal_type = 0;
	else if (ft_strcmp(str, "Julia") == 0)
		data->fractal_type = 1;
	else if (ft_strcmp(str, "BurningShip") == 0)
		data->fractal_type = 2;
	else if (ft_strcmp(str, "Tricorn") == 0)
		data->fractal_type = 3;
	else
	{
		ft_putendl("Usage: ./fractol <Mandelbrot/Julia/BurningShip/Tricorn");
		return (0);
	}
	data->it_max = 10;
	data->min = -2.05f;
	data->max = -1.3f;
	data->zoom = 300;
	data->color = 0xffffff;
	return (1);
}

int			main(int ac, char **av)
{
	t_fractol *fractol;

	if (ac != 2)
	{
		ft_putendl("Usage: ./fractol <Mandelbrot/Julia/BurningShip/Tricorn>");
		return (0);
	}
	fractol = ft_memalloc(sizeof(t_fractol));
	if (init_fractal(av[1], fractol) == 0)
		return (0);
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, SCREEN_W, SCREEN_H, "Fractol");
	fractol->img_main = mlx_new_image(fractol->mlx, SCREEN_W, SCREEN_H);
	mlx_hook(fractol->win, 17, 0, close_window, (void *)0);
	mlx_hook(fractol->win, 2, 0, handle_input, fractol);
	mlx_hook(fractol->win, 6, 1L < 6, mouse_movement, fractol);
	mlx_mouse_hook(fractol->win, handle_mouse, fractol);
	fractal_init(fractol);
	mlx_loop(fractol->mlx);
	return (1);
}

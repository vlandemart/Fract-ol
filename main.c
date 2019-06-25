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
	mandelbrot_init(fractol);
	nbr = ft_itoa(fractol->it_max);
	mlx_string_put(fractol->mlx, fractol->win, 0, 0, 0xffffff, nbr);
	free(nbr);
	return (1);
}

int			main(int ac, char **av)
{
	t_fractol *fractol;

	if (ac != 2)
	{
		ft_putendl("Usage: ./fractol <map_name>");
		ft_putendl(av[0]);
		return (0);
	}
	fractol = ft_memalloc(sizeof(t_fractol));
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, SCREEN_W, SCREEN_H, "Fractol");
	fractol->img_main = mlx_new_image(fractol->mlx, SCREEN_W, SCREEN_H);
	fractol->fractal_type = 1;
	fractol->it_max = 10;
	fractol->min = -2.05f;
	fractol->max = -1.3f;
	fractol->zoom = 300;
	fractol->color = 255 * 255;
	mlx_hook(fractol->win, 17, 0, close_window, (void *)0);
	mlx_hook(fractol->win, 2, 0, handle_input, fractol);
	mlx_mouse_hook(fractol->win, handle_mouse, fractol);
	mandelbrot_init(fractol);
	mlx_loop(fractol->mlx);
	return (1);
}

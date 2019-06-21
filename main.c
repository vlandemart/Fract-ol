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

int			update(t_fractol *fractol)
{
	char *nbr;

	mandelbrot_init(fractol);
	nbr = ft_itoa(fractol->it_max);
	mlx_string_put(fractol->mlx, fractol->win, 0, 0, 0xffffff, nbr);
	free(nbr);
	return (1);
}

int			close_window(void *param)
{
	(void)param;
	debug_str("App was closed.\n", 5);
	exit(0);
	return (0);
}

int			handle_input(int key, t_fractol *fractol)
{
	if (key == 53)
		close_window(0);
	fractol->factor *= 0.9349;
	fractol->max -= 0.1f * fractol->factor;
	fractol->min += 0.15f * fractol->factor;
	return (update(fractol));
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
	fractol->min = -3.0;
	fractol->max = 1.0;
	fractol->color = 255;
	fractol->factor = 1;
	mlx_hook(fractol->win, 17, 0, close_window, (void *)0);
	mlx_hook(fractol->win, 2, 0, handle_input, fractol);
	mandelbrot_init(fractol);
	mlx_loop(fractol->mlx);
	return (1);
}

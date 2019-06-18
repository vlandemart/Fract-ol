/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:17:44 by njacobso          #+#    #+#             */
/*   Updated: 2019/06/18 14:17:47 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define THREADS 500

# include "libvgx/libvgx.h"
# include "minilibx/mlx.h"
# include "math.h"
# include "pthread.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img_main;
	int			*img_data;
	int			fractal_type;
	int			color;
	int			x;
	int			y;
	double		min;
	double		max;
	int			it_max;
	int			it;
	long double	factor;
	int			y_max;
}				t_fractol;

void	ft_image_put_pixel(t_fractol *fractol, int x, int y, int color);
void	mandelbrot_init(t_fractol *data);

#endif
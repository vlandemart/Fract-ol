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
	int			mouse_move;
	int			color;
	int			x;
	int			y;
	long double	min;
	long double	max;
	int			it_max;
	int			it;
	long double	zoom;
	long double	c_x;
	long double	c_y;
	long double	z_x;
	long double	z_y;
	int			y_max;
}				t_fractol;

int				update(t_fractol *fractol);
void			ft_image_put_pixel(t_fractol *fractol, int x, int y, int color);
void			fractal_init(t_fractol *data);
int				handle_input(int key, t_fractol *fractol);
int				handle_mouse(int key, int x, int y, t_fractol *data);
int				mouse_movement(int x, int y, t_fractol *data);
int				close_window(void *param);
void			fractal_output(t_fractol *data);
void			mandelbrot_calc(t_fractol *data);
void			tricorn_calc(t_fractol *data);
void			burning_calc(t_fractol *data);
void			julia_calc(t_fractol *data);

#endif

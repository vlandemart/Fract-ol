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
# define THREADS 1000
# define FALSE 0
# define TRUE 1
# define SCREEN_W 1000
# define SCREEN_H 1000

# include <SDL2/SDL.h>
# include "math.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_fractol
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*texture;
	int				*pixels;
	int				keys[322];
	int				fractal_type;
	int				mouse_move;
	int				color;
	int				x;
	int				y;
	long double		min;
	long double		max;
	int				it_max;
	int				it;
	long double		zoom;
	long double		c_x;
	long double		c_y;
	long double		z_x;
	long double		z_y;
	int				y_max;
}					t_fractol;

int				update(t_fractol *fractol);
int				set_pixel(t_fractol *fractol, int x, int y, int color);
void			fractal_init(t_fractol *data);
int				handle_mouse_wheel(t_fractol *data, int wheel_dir, int x, int y);
void			fractal_output(t_fractol *data);
void			mandelbrot_calc(t_fractol *data);
void			tricorn_calc(t_fractol *data);
void			burning_calc(t_fractol *data);
void			julia_calc(t_fractol *data);

#endif

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

int			close_app(t_fractol *data, char *die_msg)
{
	SDL_DestroyWindow(data->win);
	SDL_DestroyRenderer(data->rend);
	SDL_Quit();

	printf("%s\n", die_msg);
	exit(1);
}

int			event_handle(void *fract)
{
	SDL_Event	event;
	int			x;
	int			y;
	t_fractol	*data;

	data = (t_fractol *)fract;
	while (SDL_PollEvent(&event))
	{
		SDL_GetMouseState(&x, &y);
		if (event.type == SDL_QUIT)
			close_app(data, "App was closed.");
		if (event.type == SDL_MOUSEWHEEL)
			handle_mouse_wheel(data, event.wheel.y, x, y);
		if (event.type == SDL_KEYDOWN)
			data->keys[event.key.keysym.sym] = TRUE;
		if (event.type == SDL_KEYUP)
			data->keys[event.key.keysym.sym] = FALSE;
	}
	return (1);
}


int			update(t_fractol *data)
{
	void	*pix;
	int		pitch;

	printf("Update started.\n");
	SDL_DetachThread(SDL_CreateThread(event_handle, "input_thread", &data));
	printf("Input moved to another thread.\n");

	memset(data->pixels, 0xffffff, SCREEN_W * SCREEN_H * sizeof(int));
	while (TRUE)
	{
		Uint64 start = SDL_GetPerformanceCounter();
		event_handle(data);
		if (data->keys[SDLK_ESCAPE])
			close_app(data, "App closed.");
		if (data->keys[SDLK_w])
		{
			data->it_max += 10;
			printf("Max iterations: %d\n", data->it_max);
		}
		if (data->keys[SDLK_s])
			data->it_max -= 10;
		fractal_init(data);
		SDL_LockTexture(data->texture, NULL, &pix, &pitch);
		memcpy(pix, data->pixels, SCREEN_H * pitch);
		SDL_UnlockTexture(data->texture);
		//Slower way
		/*
		SDL_UpdateTexture
		(
			data->texture,
			NULL,
			data->pixels,
			SCREEN_W * 4
		);
		*/
		SDL_RenderClear(data->rend);
		SDL_RenderCopy(data->rend, data->texture, NULL, NULL);
		SDL_RenderPresent(data->rend);
		Uint64 end = SDL_GetPerformanceCounter();
		Uint64 freq = SDL_GetPerformanceFrequency();
		double seconds = (end - start) / (double)freq;
		printf("Frametime: %f\n", seconds * 1000);
	}
	return (1);
}

int			init_fractal(char *str, t_fractol *data)
{
	if (strcmp(str, "Mandelbrot") == 0)
		data->fractal_type = 0;
	else if (strcmp(str, "Julia") == 0)
		data->fractal_type = 1;
	else if (strcmp(str, "BurningShip") == 0)
		data->fractal_type = 2;
	else if (strcmp(str, "Tricorn") == 0)
		data->fractal_type = 3;
	else
	{
		printf("Usage: ./fractol <Mandelbrot|Julia|BurningShip|Tricorn>\n");
		return (0);
	}
	data->it_max = 10;
	data->min = -2.05f;
	data->max = -1.3f;
	data->zoom = 300;
	data->color = 0xffffff;
	return (1);
}

int			init(t_fractol *data)
{
	SDL_Init(SDL_INIT_VIDEO);
	data->win = SDL_CreateWindow
	(
		"Fractol",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_W,
		SCREEN_H,
		SDL_WINDOW_OPENGL
	);
	if (!data->win)
		close_app(data, "SDL can't open window.");
	data->rend = SDL_CreateRenderer
	(
		data->win, -1,
		SDL_RENDERER_ACCELERATED
	);
	if (!data->rend)
		close_app(data, "SDL can't create renderer.");
	data->texture = SDL_CreateTexture
	(
		data->rend,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		SCREEN_W, SCREEN_H
	);
	data->pixels = malloc(SCREEN_H * SCREEN_H * sizeof(int));

	return (1);
}

int			main(int ac, char **av)
{
	t_fractol *fractol;

	if (ac != 2)
	{
		printf("Usage: ./fractol <Mandelbrot|Julia|BurningShip|Tricorn>\n");
		return (0);
	}
	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (init_fractal(av[1], fractol) == 0)
		return (0);
	if (!init(fractol))
		close_app(fractol, "Failed to init SDL!");

	update(fractol);
	close_app(fractol, "App closed.");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:50:32 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/31 10:41:35 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "input.h"
#include "ray.h"

#include "SDL.h"
#include <math.h>

t_window	*init_window(void)
{
	t_window	*window;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = (t_window *)malloc(sizeof(t_window)); // return error if allocation fails
	window->width = 800;
	window->height = 600;
	window->x = SDL_WINDOWPOS_CENTERED;
	window->y = SDL_WINDOWPOS_CENTERED;
	window->flags = SDL_WINDOW_SHOWN;
	window->window = SDL_CreateWindow("Window",
		window->x,
		window->y,
		window->width,
		window->height,
		window->flags
	); // return error if window creation fails
	return (window);
}

t_scene		*init_scene(t_window *window)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene)); // return error if allocation fails
	scene->sphere = (t_sphere *)malloc(sizeof(t_sphere)); // return error if allocation fails
	scene->sphere->pos.x = 0;
	scene->sphere->pos.y = 0;
	scene->sphere->pos.z = 10;
	scene->sphere->radius = 1;
	scene->sphere->colour.a = 255;
	scene->sphere->colour.r = 255;
	scene->sphere->colour.g = 0;
	scene->sphere->colour.b = 255;
	scene->sphere->radius2 = scene->sphere->radius * scene->sphere->radius;
	scene->camera = (t_camera *)malloc(sizeof(t_camera)); // return error if allocation fails
	scene->camera->pos.x = 0;
	scene->camera->pos.y = 0;
	scene->camera->pos.z = 0;
	scene->camera->dir.x = 0;
	scene->camera->dir.y = 0;
	scene->camera->dir.z = 1;
	scene->camera->aspect_ratio = window->width / (float)window->height;
	scene->camera->angle = tan(FOV * scene->camera->aspect_ratio * M_PI / 180);
	scene->camera->inverse_width = 1.0 / window->width;
	scene->camera->inverse_height = 1.0 / window->height;
	scene->renderer = SDL_CreateRenderer(window->window, -1, 0);
	return (scene);
}

t_key		*init_input(void)
{
	t_key	*keys;

	keys = (t_key *)malloc(sizeof(t_key)); // return error if allocation fails
	keys->key_w = 0;
	keys->key_s = 0;
	keys->key_a = 0;
	keys->key_d = 0;
	keys->key_up = 0;
	keys->key_down = 0;
	keys->key_left = 0;
	keys->key_right = 0;
	return (keys);
}
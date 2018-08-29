/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:50:32 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/29 18:46:40 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "input.h"

#include "SDL.h"
#include <math.h>

t_scene		*init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->sphere = (t_sphere *)malloc(sizeof(t_sphere));
	scene->sphere->pos.x = 0;
	scene->sphere->pos.y = 0;
	scene->sphere->pos.z = -10;
	scene->sphere->radius = 5;
	scene->sphere->colour.a = 255;
	scene->sphere->colour.r = 255;
	scene->sphere->colour.g = 0;
	scene->sphere->colour.b = 0;
	scene->camera = (t_camera *)malloc(sizeof(t_camera));
	scene->camera->pos.x = 0;
	scene->camera->pos.y = 0;
	scene->camera->pos.z = 0;
	scene->camera->dir.x = 0;
	scene->camera->dir.y = 0;
	scene->camera->dir.z = -1;
	scene->camera->aspect_ratio = tan(90.0 * 0.5 * M_PI / 180);
	return (scene);
}

t_window	*init_window(void)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	window->width = 640;
	window->height = 430;
	window->x = SDL_WINDOWPOS_CENTERED;
	window->y = SDL_WINDOWPOS_CENTERED;
	window->flags = SDL_WINDOW_SHOWN;
	window->window = SDL_CreateWindow("Window",
		window->x,
		window->y,
		window->width,
		window->height,
		window->flags
	);
	return (window);
}

t_key		*init_input(void)
{
	t_key	*keys;

	keys = (t_key *)malloc(sizeof(t_key));
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
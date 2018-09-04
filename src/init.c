/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:50:32 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/04 15:56:58 by ccliffor         ###   ########.fr       */
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

	SDL_Init(SDL_INIT_VIDEO);
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

t_scene		*init_scene(t_window *window, char *path)
{
	int			i;
	t_scene		*scene;
	t_sphere	*sphere;

	scene = (t_scene *)malloc(sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	read_scene(path, scene);
	scene->camera.aspect_ratio = window->width / (float)window->height;
	scene->camera.angle = tan(FOV * scene->camera.aspect_ratio * M_PI / 180);
	scene->camera.inverse_width = 1.0 / window->width;
	scene->camera.inverse_height = 1.0 / window->height;
	i = 0;
	while ((sphere = (t_sphere *)vec_get(&scene->spheres, i++)))
		sphere->radius2 = sphere->radius * sphere->radius;
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
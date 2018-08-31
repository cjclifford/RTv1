/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:37:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/31 10:06:02 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "camera.h"
#include "ray.h"

#define MAX_RAY_DEPTH 1

void	render_scene(t_scene *scene, t_window *window)
{
	int		x;
	int		y;
	int		hit;
	double	collisions[2];
	t_ray	*primary_ray;
	t_ray	*shadow_ray;

	SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
	SDL_RenderClear(scene->renderer);
	primary_ray = (t_ray *)malloc(sizeof(t_ray));
	shadow_ray = (t_ray *)malloc(sizeof(t_ray));
	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			// get primary ray direction
			set_ray(x, y, scene->camera, primary_ray);
			// printf("%f, %f, %f\n", primary_ray->dir.x, primary_ray->dir.y, primary_ray->dir.z);
			hit = 0;
			// while primary ray length is less than max distance
			//	for all objects in scene
			//		if ray intersects object
			if (intersect(scene->camera, primary_ray, scene->sphere, collisions))
			{
				//	if distance to object is smaller than smallest known distance set as smallest
				hit = 1;
			}
			//	if an object was hit
			if (hit)
			{
				//		get shadow ray direction
				//		for all objects in scene
				//			if shadow ray intesects object
				//				color pixel black
				//			else
				//				color pixel object's color
				SDL_SetRenderDrawColor(scene->renderer, scene->sphere->colour.r, scene->sphere->colour.g, scene->sphere->colour.b, scene->sphere->colour.a);
				SDL_RenderDrawPoint(scene->renderer, x, y);
			}
			x++;
		}
		y++;
	}
	SDL_RenderPresent(scene->renderer);
}
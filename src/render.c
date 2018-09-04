/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:37:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/04 17:39:27 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "camera.h"
#include "ray.h"

// TODO:
//	Cones
//	Planes
//	Cylinders
void	render_scene(t_scene *scene, t_window *window)
{
	int			x;
	int			y;
	int			i;
	int			j;
	int			hit;
	double		distance;
	t_ray		*primary_ray;
	t_ray		*shadow_ray;
	t_light		*light;
	t_sphere	*smallest;

	SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
	SDL_RenderClear(scene->renderer);
	primary_ray = (t_ray *)malloc(sizeof(t_ray));
	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			set_ray(x, y, &scene->camera, primary_ray);
			hit = 0;
			// TODO: while primary ray length is less than max distance
			distance = INFINITY;
			i = 0;
			while (i < (int)scene->spheres.length)
			{
				if (intersect(scene, primary_ray, i))
				{
					if (primary_ray->intersect < distance)
					{
						smallest = (t_sphere *)vec_get(&scene->spheres, i);
						distance = primary_ray->intersect;
					}
					hit = 1;
				}
				i++;
			}
			if (hit)
			{
				j = 0;
				while ((light = (t_light *)vec_get(&scene->lights, j++)))
				{
					//		get shadow ray direction
					shadow_ray = (t_ray *)malloc(sizeof(t_ray));
					shadow_ray->dir = vec3_subtract(light->pos, vec3_multiply(primary_ray->dir, primary_ray->intersect));
					//		for all objects in scene
					i = 0;
					// while ((sphere = (t_sphere *)vec_get(&scene->spheres, i++)))
					// {
					// 	if (intersect(vec3_multiply(primary_ray->dir, primary_ray->intersect), shadow_ray, sphere))
					// 		SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
					// 	else
					// 		SDL_SetRenderDrawColor(scene->renderer, smallest->colour.r, smallest->colour.g, smallest->colour.b, 255);
					// }
					SDL_SetRenderDrawColor(scene->renderer, smallest->colour.r, smallest->colour.g, smallest->colour.b, 255);
					SDL_RenderDrawPoint(scene->renderer, x, y);
				}
			}
			x++;
		}
		y++;
	}
	SDL_RenderPresent(scene->renderer);
}
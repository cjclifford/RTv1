/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:37:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/05 12:40:03 by ccliffor         ###   ########.fr       */
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

static void	render_spheres(t_scene *scene, t_ray *primary_ray)
{
	int			i;
	int			j;
	int			hit;
	double		distance;
	double		shading;
	t_ray		*shadow_ray;
	t_light		*light;
	t_sphere	*smallest;

	hit = 0;
	// TODO: while primary ray length is less than max distance
	distance = INFINITY;
	i = 0;
	while (i < (int)scene->spheres.length)
	{
		if (intersect(primary_ray, vec_get(&scene->spheres, i)))
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
			shadow_ray->dir = vec3_subtract(light->pos, vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect)));
			vec3_normalize(&shadow_ray->dir);
			shadow_ray->pos = vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect));
			//		get shading value
			t_vec3	normal = vec3_subtract(smallest->pos, vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect)));
			vec3_normalize(&normal);
			shading = vec3_dot(normal, shadow_ray->dir);
			if (shading < 0)
				shading *= -1;
			//		for all objects in scene
			i = 0;
			SDL_SetRenderDrawColor(scene->renderer, smallest->colour.r * shading, smallest->colour.g * shading, smallest->colour.b * shading, 255);
			while (i < (int)scene->spheres.length)
			{
				if (intersect(shadow_ray, vec_get(&scene->spheres, i)))
						SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
				i++;
			}
		}
	}
}

void		render_scene(t_scene *scene, t_window *window)
{
	int			x;
	int			y;
	t_ray		*primary_ray;

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
			render_spheres(scene, primary_ray);
			SDL_RenderDrawPoint(scene->renderer, x, y);
			x++;
		}
		y++;
	}
	SDL_RenderPresent(scene->renderer);
}
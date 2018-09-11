/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:37:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/10 15:33:31 by ccliffor         ###   ########.fr       */
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

static int	render_spheres(t_scene *scene, t_ray *primary_ray, t_ray *shadow_ray)
{
	int			i;
	int			j;
	double		distance;
	double		shading;
	t_light		*light;
	t_sphere	*nearest;

	distance = INFINITY;
	nearest = NULL;
	i = 0;
	while (i < (int)scene->spheres.length)
	{
		if (sph_intersect(primary_ray, vec_get(&scene->spheres, i)))
		{
			if (primary_ray->intersect < distance)
			{
				nearest = (t_sphere *)vec_get(&scene->spheres, i);
				distance = primary_ray->intersect;
			}
		}
		i++;
	}
	if (nearest)
	{
		j = 0;
		while ((light = (t_light *)vec_get(&scene->lights, j++)))
		{
			//		get shadow ray direction
			shadow_ray->dir = vec3_subtract(light->pos, vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect)));
			vec3_normalize(&shadow_ray->dir);
			shadow_ray->pos = vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect));
			//		get shading value
			vec3_multiply(primary_ray->dir, primary_ray->intersect);
			t_vec3	normal = vec3_subtract(nearest->pos, vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect)));
			vec3_normalize(&normal);
			shading = fabs(vec3_dot(normal, shadow_ray->dir));
			//		for all objects in scene
			SDL_SetRenderDrawColor(scene->renderer, nearest->colour.r * shading, nearest->colour.g * shading, nearest->colour.b * shading, nearest->colour.a);
			i = 0;
			while (i < (int)scene->spheres.length)
			{
				if (sph_intersect(shadow_ray, vec_get(&scene->spheres, i)))
					SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
				i++;
			}
		}
		return (1);
	}
	return (0);
}

static int	render_planes(t_scene *scene, t_ray *primary_ray, t_ray *shadow_ray)
{
	int		i;
	double	distance;
	double	shading;
	t_plane	*nearest;

	(void)shadow_ray;
	distance = INFINITY;
	nearest = NULL;
	i = 0;
	while (i < (int)scene->objects.length)
	{
		if (vec_get(&scene->objects, i))
		if (pln_intersect(primary_ray, vec_get(&scene->planes, i)))
		{
			if (primary_ray->intersect < distance)
			{
				nearest = vec_get(&scene->planes, i);
				distance = primary_ray->intersect;
			}
		}
		i++;
	}
	SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
	if (nearest)
	{
			shading = vec3_dot(nearest->normal, primary_ray->dir);
			SDL_SetRenderDrawColor(scene->renderer, nearest->colour.r * shading, nearest->colour.g * shading, nearest->colour.b * shading, nearest->colour.a);
		return (1);
	}
	return (0);
}

void		render_scene(t_scene *scene, t_window *window)
{
	int		x;
	int		y;
	int		hit;
	t_ray	primary_ray;
	t_ray	shadow_ray;

	SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
	SDL_RenderClear(scene->renderer);
	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			hit = 0;
			set_ray(x, y, &scene->camera, &primary_ray);
			hit = render_planes(scene, &primary_ray, &shadow_ray);
			hit = render_spheres(scene, &primary_ray, &shadow_ray);
			if (hit)
				SDL_RenderDrawPoint(scene->renderer, x, y);
			x++;
		}
		y++;
	}
	SDL_RenderPresent(scene->renderer);
}
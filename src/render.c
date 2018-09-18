/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:37:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/18 14:32:43 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

// TODO:
//	Cones
//	Planes
//	Cylinders

static t_object	*get_nearest(t_scene *scene, t_ray *primary_ray)
{
	int			i;
	double		distance;
	t_object	*nearest;
	t_generic	*generic;

	distance = INFINITY;
	i = 0;
	while (i < (int)scene->objects.length)
	{
		generic = (t_generic *)vec_get(&scene->objects, i);
		if (generic->type != LIGHT)
		{
			if (generic->intersect(primary_ray, (t_object *)vec_get(&scene->objects, i)))
			{
				if (primary_ray->intersect < distance)
				{
					nearest = (t_object *)vec_get(&scene->objects, i);
					distance = primary_ray->intersect;
				}
			}
		}
		i++;
	}
	if (distance < INFINITY)
		return (nearest);
	return (NULL);
}


static void		render_objects(t_scene *scene, t_ray *primary_ray, t_ray *shadow_ray)
{
	int			i;
	int			j;
	double		shading;
	t_generic	*generic;
	t_object	*light;
	t_object	*nearest;
	SDL_Colour	colour;

	i = 0;
	nearest = get_nearest(scene, primary_ray);
	if (nearest)
	{
		i = 0;
		while (i < (int)scene->objects.length)
		{
			generic = (t_generic *)vec_get(&scene->objects, i);
			if (generic->type == LIGHT)
			{
				light = (t_object *)vec_get(&scene->objects, i);
				shadow_ray->dir = vec3_subtract(light->light.generic.pos, vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect)));
				// shadow_ray->dir = vec3_subtract(scene->camera.pos, vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect)));
				vec3_normalize(&shadow_ray->dir);
				shadow_ray->pos = vec3_add(scene->camera.pos, vec3_multiply(primary_ray->dir, primary_ray->intersect * (1 + 1e-6)));
				shading = fabs(vec3_dot(nearest->generic.normal, shadow_ray->dir));
				j = 0;
				colour = (SDL_Colour){nearest->generic.colour.r * shading, nearest->generic.colour.g * shading, nearest->generic.colour.b * shading, 255};
				while (j < (int)scene->objects.length)
				{
					generic = (t_generic *)vec_get(&scene->objects, j);
					if (generic->type != LIGHT)
					{
						if (generic->intersect(shadow_ray, vec_get(&scene->objects, j)))
							colour = (SDL_Colour){0, 0, 0, 255}; 
					}
					j++;
				}
			}
			i++;
		}
	}
	SDL_SetRenderDrawColor(scene->renderer, colour.r, colour.g, colour.b, 255);
}

void			render_scene(t_scene *scene, t_window *window)
{
	int		x;
	int		y;
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
			set_ray(x, y, &scene->camera, &primary_ray);
			render_objects(scene, &primary_ray, &shadow_ray);
			SDL_RenderDrawPoint(scene->renderer, x, y);
			x++;
		}
		y++;
	}
	SDL_RenderPresent(scene->renderer);
}

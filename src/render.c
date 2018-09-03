/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:37:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/03 17:50:42 by ccliffor         ###   ########.fr       */
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
	int			hit;
	double		distance;
	t_ray		*primary_ray;
	t_list		*tmp_list;
	t_sphere	*smallest;
	t_sphere	*tmp_sphere;

	SDL_SetRenderDrawColor(scene->renderer, 0, 0, 0, 255);
	SDL_RenderClear(scene->renderer);
	primary_ray = (t_ray *)malloc(sizeof(t_ray));
	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			set_ray(x, y, scene->camera, primary_ray);
			hit = 0;
			// TODO: while primary ray length is less than max distance
			tmp_list = scene->spheres;
			distance = INFINITY;
			while (tmp_list)
			{
				tmp_sphere = tmp_list->content;
				if (intersect(scene->camera, primary_ray, tmp_sphere))
				{
					if (primary_ray->collision[0] < distance)
					{
						smallest = tmp_sphere;
						distance = primary_ray->collision[0];
					}
					hit = 1;
				}
				tmp_list = tmp_list->next;
			}
			if (hit)
			{
					//		get shadow ray direction
					//		for all objects in scene
					//			if shadow ray intesects object
					//				color pixel black
					//			else
					//				color pixel object's color
				SDL_SetRenderDrawColor(scene->renderer, smallest->colour.r, smallest->colour.g, smallest->colour.b, 255);
				SDL_RenderDrawPoint(scene->renderer, x, y);
			}
			x++;
		}
		y++;
	}
	SDL_RenderPresent(scene->renderer);
}
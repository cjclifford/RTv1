/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:01:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/10 12:34:06 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "camera.h"
#include "object.h"

void	set_ray(int x, int y, t_camera *camera, t_ray *ray)
{
	ray->pos.x = camera->pos.x;
	ray->pos.y = camera->pos.y;
	ray->pos.z = camera->pos.z;
	ray->dir.x = (2 * (x * camera->inverse_width) - 1) * camera->angle * camera->aspect_ratio;
	ray->dir.y = (1 - 2 * (y * camera->inverse_height)) * camera->angle;
	ray->dir.z = camera->dir.z;
	vec3_normalize(&ray->dir);
}

int		sph_intersect(t_ray *ray, t_sphere *sphere)
{
	double		y;
	double		x;
	double		d;
	t_vec3		p;

	d = fabs(vec3_dot(vec3_subtract(sphere->pos, ray->pos), ray->dir));
	p = vec3_add(ray->pos, vec3_multiply(ray->dir, d));
	y = vec3_length(vec3_subtract(sphere->pos, p));
	if (y < sphere->radius)
	{
		x = sqrt(sphere->radius2 - y * y);
		ray->intersect = MIN(d + x, d - x);
		if (ray->intersect < 0)
			ray->intersect = MAX(d + x, d - x);
		return (1);
	}
	return (0);
}

int		pln_intersect(t_ray *ray, t_plane *plane)
{
	double	den;

	den = vec3_dot(plane->normal, ray->dir);
	if (den > 1e-6)
	{
		ray->intersect = vec3_dot(vec3_subtract(plane->pos, ray->pos), plane->normal) / den;
		return (ray->intersect >= 0);
	}
	return (0);
}

// cylinder intersect

// cone intersect
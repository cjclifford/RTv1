/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:45:07 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/18 14:31:25 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

int		sph_intersect(t_ray *ray, t_object *object)
{
	double		y;
	double		x;
	double		d;
	t_vec3		p;
	t_sphere	*sphere;

	sphere = &object->sphere;
	d = fabs(vec3_dot(vec3_subtract(sphere->generic.pos, ray->pos), ray->dir));
	p = vec3_add(ray->pos, vec3_multiply(ray->dir, d));
	y = vec3_length(vec3_subtract(sphere->generic.pos, p));
	if (y < sphere->radius)
	{
		x = sqrt(sphere->radius2 - y * y);
		ray->intersect = MIN(d + x, d - x);
		if (ray->intersect < 0)
			ray->intersect = MAX(d + x, d - x);
		return (1);
	}
	sphere->generic.normal = vec3_subtract(sphere->generic.pos, vec3_add(ray->pos, vec3_multiply(ray->dir, ray->intersect)));
	vec3_normalize(&sphere->generic.normal);
	return (0);

}

int		pln_intersect(t_ray *ray, t_object *object)
{
	double	den;
	t_plane *plane;

	plane = &object->plane;
	den = vec3_dot(plane->generic.normal, ray->dir);
	if (den > 1e-6)
	{
		ray->intersect = vec3_dot(vec3_subtract(plane->generic.pos, ray->pos), plane->generic.normal) / den;
		return (ray->intersect >= 0);
	}
	return (0);
}

// cylinder intersect

// cone intersect
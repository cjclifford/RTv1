/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:45:07 by ccliffor          #+#    #+#             */
/*   Updated: 2018/10/01 07:43:50 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

int		sph_intersect(t_ray *ray, t_object *object)
{
	double		y;
	double		x;
	double		d;
	double		distance;
	t_vec3		p;
	t_sphere	*sphere;

	sphere = &object->sphere;
	d = fabs(vec3_dot(vec3_subtract(sphere->generic.pos, ray->pos), ray->dir));
	p = vec3_add(ray->pos, vec3_multiply(ray->dir, d));
	y = vec3_length(vec3_subtract(sphere->generic.pos, p));
	if (y < sphere->radius)
	{
		x = sqrt(sphere->radius2 - y * y);
		distance = MIN(d + x, d - x);
		if (distance < 0)
			distance = MAX(d + x, d - x);
		if (distance >= ray->intersect)
			return (0);
		ray->intersect = distance;
		sphere->generic.normal = vec3_subtract(sphere->generic.pos, vec3_add(ray->pos, vec3_multiply(ray->dir, ray->intersect)));
		vec3_normalize(&sphere->generic.normal);
		return (1);
	}
	return (0);

}

int		pln_intersect(t_ray *ray, t_object *object)
{
	double	den;
	double	distance;
	t_plane *plane;

	plane = &object->plane;
	den = vec3_dot(plane->generic.normal, ray->dir);
	if (den > 1e-6)
	{
		distance = vec3_dot(vec3_subtract(plane->generic.pos, ray->pos), plane->generic.normal) / den;
		if (distance >= ray->intersect)
			return (0);
		ray->intersect = distance;
		return (ray->intersect >= 0);
	}
	return (0);
}

int		cyl_intersect(t_ray *ray, t_object *object)
{
	t_cylinder	*cylinder;

	cylinder = &object->cylinder;
	t_vec3	oc;
	// double	a;
	// double	b;
	// double	c;
	// double	h;

	oc = vec3_subtract(ray->pos, cylinder->generic.pos);
	// a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z; 
	// b = (ray->dir.x * oc.x + ray->dir.z * oc.z);
	// c = oc.x * oc.x + oc.z * oc.z - cylinder->radius2;
	// h = b * b - a * c;
	// if (h < 0.0001)
	// 	return (0);
	// ray->intersect = (-b - sqrt(h)) / a;
	// if (ray->intersect < 0)
	// 	return (0);
	// cylinder->generic.normal = vec3_subtract(cylinder->generic.pos, vec3_multiply(ray->dir, ray->intersect));
	// vec3_normalize(&cylinder->generic.normal);
	return (1);
}

// cone intersect
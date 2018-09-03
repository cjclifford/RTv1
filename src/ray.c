/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:01:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/03 17:04:36 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "camera.h"
#include "object.h"

void	set_ray(int x, int y, t_camera *camera, t_ray *ray)
{
	ray->dir.x = (2 * (x * camera->inverse_width) - 1) * camera->angle * camera->aspect_ratio;
	ray->dir.y = (1 - 2 * (y * camera->inverse_height)) * camera->angle;
	ray->dir.z = camera->dir.z;
	vec3_normalize(&ray->dir);
}

int		intersect(t_camera *camera, t_ray *ray, t_sphere *sphere)
{
	double		y;
	double		x;
	double		d;
	t_vec3		p;

	d = fabs(vec3_dot(vec3_subtract(sphere->pos, camera->pos), ray->dir));
	p = vec3_add(camera->pos, vec3_multiply(ray->dir, d));
	y = vec3_length(vec3_subtract(sphere->pos, p));
	if (y < sphere->radius)
	{
		x = sqrt(sphere->radius2 - y * y);
		ray->collision[0] = d + x;
		ray->collision[1] = d - x;
		return (1);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:01:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/12 15:45:03 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:56:15 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/03 17:06:51 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "scene.h"

# include "../lib3d/include/vec3.h"

typedef struct	s_ray
{
	t_vec3	dir;
	double	collision[2];
}				t_ray;

void			set_ray(int x, int y, t_camera *camera, t_ray *ray);
int				intersect(t_camera *camera, t_ray *ray, t_sphere *sphere);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:56:15 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/04 17:36:38 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "scene.h"

# include "../lib3d/includes/vec3.h"

typedef struct	s_ray
{
	t_vec3	dir;
	double	intersect;
}				t_ray;

void			set_ray(int x, int y, t_camera *camera, t_ray *ray);
int				intersect(t_scene *scene, t_ray *ray, int i);

#endif

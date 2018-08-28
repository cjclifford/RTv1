/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:48:45 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 18:56:39 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../lib3d/include/vec3.h"

typedef struct	s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
	double	aspect_ratio;
}				t_camera;

#endif

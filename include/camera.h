/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:48:45 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/03 12:49:48 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../lib3d/include/vec3.h"

typedef struct	s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	double	inverse_width;
	double	inverse_height;
	double	aspect_ratio;
	double	angle;
}				t_camera;

#endif

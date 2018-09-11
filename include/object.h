/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:40:07 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/10 15:29:50 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../lib3d/includes/vec3.h"
# include "SDL.h"

typedef struct	s_sphere
{
	t_type		type;
	t_vec3		pos;
	double		radius;
	double		radius2;
	SDL_Colour	colour;
}				t_sphere;

typedef struct	s_plane
{
	t_type		type;
	t_vec3		pos;
	t_vec3		normal;
	SDL_Colour	colour;
}				t_plane;

// TODO:
// cones
// cylinders

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:40:07 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/04 13:35:20 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../lib3d/includes/vec3.h"
# include "SDL.h"

typedef struct	s_sphere
{
	t_vec3		pos;
	double		radius;
	double		radius2;
	SDL_Colour	colour;
}				t_sphere;

#endif

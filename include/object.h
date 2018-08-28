/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:40:07 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 18:56:33 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../lib3d/include/vec3.h"

typedef struct	s_sphere
{
	t_vec3	pos;
	double	radius;
}				t_sphere;

#endif

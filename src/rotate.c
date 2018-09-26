/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:20:56 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/25 12:52:48 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

t_vec3	rotate_x(t_vec3 vec, double theta)
{
	t_vec3	new;

	new.x = vec.x;
	new.y = vec.y * cos(theta) + vec.y * sin(theta);
	new.z = vec.z * -sin(theta) + vec.z * cos(theta);
	return (new);
}

t_vec3	rotate_y(t_vec3 vec, double theta)
{
	t_vec3	new;

	// new.x = vec.x * cos(theta) + vec.x * -sin(theta);
	// new.y = vec.y;
	// new.z = vec.z * sin(theta) + vec.z * cos(theta);
	new.x = vec.x + theta;
	new.y = vec.y;
	new.z = vec.z + theta;
	return (new);
}

t_vec3	rotate_z(t_vec3 vec, double theta)
{
	t_vec3	new;

	new.x = vec.x * cos(theta) + vec.x * sin(theta);
	new.y = vec.y * -sin(theta) + vec.y * cos(theta);
	new.z = vec.z;
	return (new);
}

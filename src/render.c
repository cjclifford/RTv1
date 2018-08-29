/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:37:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/29 18:50:49 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"

void	render_state(t_scene *scene, t_window *window)
{
	int	x;
	int	y;

	// for every pixel
	y = 0;
	while (y < window->y)
	{
		x = 0;
		while (x < window->x)
		{
			// get primary ray direction
			// while primary ray length is less than max distance
			//	for all objects in scene
			//		if ray intersects object
			//			if distance to object is smaller than smallest known distance
			//				set distance as smallest
			//	if an object was hit
			//		get shadow ray direction
			//		for all objects in scene
			//			if shadow ray intesects object
			//				color pixel black
			//			else
			//				color pixel object's color
			x++;
		}
		y++;
	}
}
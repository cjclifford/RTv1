/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:09:26 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/25 12:51:43 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "model.h"

# define SPEED 1
# define ROTSPEED 0.1

void	update_scene(t_scene *scene, t_key *keys)
{
	if (keys->key_w)
		scene->camera.pos.z += SPEED;
	if (keys->key_s)
		scene->camera.pos.z -= SPEED;
	if (keys->key_a)
		scene->camera.dir = rotate_y(scene->camera.dir, 0.1);
	if (keys->key_up)
		scene->camera.pos.y += SPEED;
	if (keys->key_down)
		scene->camera.pos.y -= SPEED;
	if (keys->key_left)
		scene->camera.pos.x -= SPEED;
	if (keys->key_right)
		scene->camera.pos.x += SPEED;
}
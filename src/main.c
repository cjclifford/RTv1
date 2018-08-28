/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:51:52 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 18:57:50 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "../libft/libft.h"
#include "../SDL2/include/SDL2/SDL.h"

int	main(void)
{
	t_camera	camera;
	t_sphere	sphere;
	t_window	window;

	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;
	camera.dir.x = 0;
	camera.dir.y = 0;
	camera.dir.z = -1;

	sphere.pos.x = 0;
	sphere.pos.y = 0;
	sphere.pos.z = -10;
	sphere.radius = 5;

	window.width = 1280;
	window.height = 960;
	window.window = SDL_CreateWindow(
		"Ray Tracer",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		window.width,
		window.height,
		SDL_WINDOW_SHOWN
		);
	SDL_Delay(3000);
	// TODO:
	// initialize scene
	// load scene data
	// while (running)
	// 	handle input
	// 	update state
	// 	render state
	return (0);
}
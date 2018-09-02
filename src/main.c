/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:51:52 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/31 12:10:58 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "init.h"
#include "input.h"

#include "../libft/libft.h"
#include "SDL.h"

int	main(void)
{
	t_scene		*scene;
	t_window	*window;
	t_key		*keys;
	int			quit;

	window = init_window();
	scene = init_scene(window);
	keys = init_input();
	// TODO:
	// load scene from file
	quit = 0;
	while (!quit)
	{
		quit = handle_input(keys);
		update_scene(scene, keys);
		render_scene(scene, window);
	}
	SDL_DestroyWindow(window->window);
	SDL_Quit();
	return (0);
}